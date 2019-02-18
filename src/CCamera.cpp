//
//  CCamera.cpp
//  trace
//
//  Created by Tom Albrecht on 18.12.18.
//  Copyright © 2018 Tom Albrecht. All rights reserved.
//

#include "CCamera.h"

NS_VRAY_BEGIN

CCamera::CCamera(const Vec3d &position, const math::Vec4 &orientation)
{
    _position = position;
    _orientation = _orientation;
}

void CCamera::position(const Vec3d &position)
{
    _position = position;
}

const Vec3d &CCamera::position() const
{
    return _position;
}



void CCamera::orientation(const math::Vec4 &orientation)
{
    _orientation = orientation;
}

const math::Vec4 &CCamera::orientation() const
{
    return _orientation;
}

NS_VRAY_END
