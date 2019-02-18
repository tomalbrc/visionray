//
//  ILight.cpp
//  trace
//
//  Created by Tom Albrecht on 28.01.19.
//  Copyright © 2019 Tom Albrecht. All rights reserved.
//

#include "ILight.hpp"

NS_VRAY_BEGIN

const Vec3d& ILight::position() const noexcept
{
    return _pos;
}

void ILight::position(const Vec3d& position) noexcept
{
    _pos = position;
}


const CColor &ILight::color() const noexcept
{
    return _color;
}

void ILight::color(const CColor &color) noexcept
{
    _color = color;
}

const double &ILight::intensity() const noexcept
{
    return _intensity;
}

void ILight::intensity(double intensity) noexcept
{
    _intensity = intensity;
}

NS_VRAY_END
