//
//  CPlane.cpp
//  trace
//
//  Created by Tom Albrecht on 29.01.19.
//  Copyright © 2019 Tom Albrecht. All rights reserved.
//

#include "CPlane.hpp"

NS_VRAY_BEGIN

CPlane::CPlane(const Vec3d &origin,
               const Vec3d &normal) : _normal{normal}
{
    position(origin);
}

/**
 * detects hit w/ ray+sphere
 * @param[in]   ray ray to test for
 * @param[out]  inter intersection information
 */
bool CPlane::hit(const math::Ray& ray, Intersection &inter)
{
    auto denom = ray.direction.dot(_normal);
    if (std::abs(denom) > 0.0001) // an epsilon
    {
        auto pos = position();
        auto v = pos - ray.origin;
        auto t = v.dot(_normal) / denom;
        
        inter.best_t = t/ray.length;
        inter.point = ray.origin+ray.direction*t;
        inter.normal = _normal;
        
        if (t >= 0.0001 && t <= ray.length)
            return true; // maybe allow an epsilon here too
    }
    return false;
}

NS_VRAY_END
