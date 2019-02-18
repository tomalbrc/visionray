//
//  IGeometryObject.cpp
//  trace
//
//  Created by Tom Albrecht on 18.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "IGeometryObject.h"

NS_VRAY_BEGIN

IGeometryObject::IGeometryObject()
{
    _material = std::make_shared<CMaterial>();
    _material->diffuseColor(CColor(0.05f, 0.99f, 0.4f, 1.f));
}

std::string IGeometryObject::description()
{
    return "<IGeometryObject>";
}

void IGeometryObject::material(const CMaterial::Ptr &material)
{
    _material = material;
}

const CMaterial::Ptr &IGeometryObject::material() const
{
    return _material;
}

void IGeometryObject::position(const Vec3d &position)
{
    _position = position;
}

const Vec3d& IGeometryObject::position() const
{
    return _position;
}

NS_VRAY_END
