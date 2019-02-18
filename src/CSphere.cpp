//
//  CSphere.cpp
//  trace
//
//  Created by Tom Albrecht on 23.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "CSphere.h"

NS_VRAY_BEGIN

CSphere::CSphere(float diameter) : IGeometryObject()
{
    _diameter = diameter;
}

bool CSphere::hit(const math::Ray& ray, Intersection &inter)
{
    //https://stackoverflow.com/questions/6533856/ray-sphere-intersection
    
    using namespace math;
    
    auto d = (ray.direction*ray.length);
    auto r = _diameter/2.0;
    auto f = ray.origin-position();
    
    auto a = d.dot(d);
    auto b = f.dot(d)*2.0;
    auto c = f.dot(f) - r*r ;
    
    auto discriminant = b*b-4.0*a*c;
    if( discriminant >= 0.0)
    {
        // ray didn't totally miss sphere,
        // so there is a solution to
        // the equation.
        
        discriminant = sqrt( discriminant );
        
        auto t1 = (-b - discriminant)/(2.0*a);
        auto t2 = (-b + discriminant)/(2.0*a);
        
        if(t1 >= 0.0 && t1 <= 1.0)
        {
            inter.best_t = t1;
            inter.point = ray.origin + ray.direction*t1;
            auto pos = position();
            inter.normal = pos-inter.point;
            inter.normal.normalize();
            return true;
        }
        
        // here t1 didn't intersect so we are either started
        // inside the sphere or completely past it
        if(t2 >= 0 && t2 <= 1)
        {
            inter.best_t = t2;
            inter.point = ray.origin + ray.direction*t2;
            auto pos = position();
            inter.normal = pos-inter.point;
            inter.normal.normalize();
            // ExitWound
            return true;
        }
        
        // no intn: FallShort, Past, CompletelyInside
        return false;
    }
    
    return false;
}

NS_VRAY_END
