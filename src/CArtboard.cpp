//
//  CArtboard.cpp
//  trace
//
//  Created by Tom Albrecht on 18.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "CArtboard.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

NS_VRAY_BEGIN

CArtboard::CArtboard(unsigned width, unsigned height)
{
    _width = width;
    _height = height;
}

void CArtboard::render(const IScene::Ptr &scene)
{
    std::cout << "Rendering scene: " << scene->description() << std::endl;
    const auto & cam = scene->camera();
    
    Void::Mat4<float> mat;
    mat = mat * Void::Matrix4::rotation<float>(Void::degToRad(cam->orientation().y), Void::Axis::Y_AXIS);
    mat = mat * Void::Matrix4::rotation<float>(Void::degToRad(-cam->orientation().x), Void::Axis::X_AXIS);
    
    
    // used in loops, put here for performance
    auto objs_size = 2*2*2;
    std::vector<IGeometryObject::Ptr> objs(objs_size); // size determines number of reflections
    std::vector<IGeometryObject::Intersection> hits(objs_size);
	const auto& sceneObjects = scene->objects();
	
    // used in loops, put here for performance
    IGeometryObject::Intersection rayInter;
    
    // render code for 1 obj
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            //std::cout << "Pixel " << j << " " << i << std::endl;
            objs.clear();
            hits.clear();
            
            IGeometryObject::Intersection inters;
            
            auto stepsize = 1.0;
			auto stepoffset = Vec3d{static_cast<float>(j*stepsize -(_width/2.0*stepsize)), static_cast<float>(i*stepsize -(_height/2.0*stepsize)), 120};
            
            auto uv = mat*stepoffset;
            uv.normalize();
            
            math::Ray ray{cam->position(), uv, 10000.0};

            double attenuation = 0.0;
            
            for (int currRay = 0; currRay < objs.capacity(); currRay++)
            {
                inters.best_t = ray.length*2.0;
                IGeometryObject::Ptr obj;
                obj = nullptr;
                
                for (const auto& object : sceneObjects)
                {
                    auto hit = object->hit(ray, rayInter);
                    if (hit && rayInter.best_t < inters.best_t)
                    {
                        obj = object;
                        inters = std::move(rayInter);
                    }
                }
                
                if (!obj) break;
                //auto colVal = 1.0-std::clamp(inters.best_t, 0.0, 1.0);
                
                attenuation += inters.best_t;
                
                objs.emplace_back(std::move(obj));
                hits.emplace_back(std::move(inters));
                
                auto bounce = ray.direction - (inters.normal*(ray.direction.dot(inters.normal)*2.0));
                bounce.normalize();
                
                ray.origin = inters.point;
                ray.direction = bounce;
            }
            
            float colVal = static_cast<float>(std::clamp(1.0-attenuation*20.0,0.0,1.0));
            CColor c2{0.5,0.5,0.5,0.5};
            
            for (int idx = 0; idx < objs.size(); idx++)
            {
                const auto &obj = objs[idx];
                const auto &hit = hits[idx];
                if (!obj) break;
                
                c2.red(static_cast<float>((c2.red()+obj->material()->diffuseColor().red()*(1.0-hit.best_t))/2.0));
                c2.green(static_cast<float>((c2.green()+obj->material()->diffuseColor().green()*(1.0-hit.best_t))/2.0));
                c2.blue(static_cast<float>((c2.blue()+obj->material()->diffuseColor().blue()*(1.0-hit.best_t))/2.0));
            }
            
            draw(j, i, CColor(c2.red()*colVal, c2.green()*colVal, c2.blue()*colVal, 1.f));
        }//j
    }//i
}

void CArtboard::draw(const int &x, const int &y, const CColor &color)
{
    _pixelCB(x,y,color);
}

const CArtboard::Callback& CArtboard::pixelCallback() const {
    return _pixelCB;
}

void CArtboard::pixelCallback(const Callback& newCallback) {
    _pixelCB = newCallback;
}

std::string CArtboard::description()
{
    std::stringstream ss;
    ss  << "<CArtboard width=\""
        << std::to_string(_width)
        << "\" height=\""
        << std::to_string(_height)
        << "\">";
    return ss.str();
}

NS_VRAY_END
