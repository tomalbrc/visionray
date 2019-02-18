//
//  IScene.cpp
//  trace
//
//  Created by Tom Albrecht on 24.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "IScene.h"

NS_VRAY_BEGIN

const CCamera::Ptr &IScene::camera() const
{
    return _camera;
}

void IScene::camera(const CCamera::Ptr &camera)
{
    _camera = camera;
}

void IScene::addObject(const IGeometryObject::Ptr &object)
{
    _objects.emplace_back(object);
}

const std::vector<IGeometryObject::Ptr>& IScene::objects() const
{
    return _objects;
}


void IScene::addLight(const ILight &lightSrc)
{
    _lights.emplace_back(lightSrc);
}

const std::vector<ILight> & IScene::lights() const
{
    return _lights;
}

NS_VRAY_END
