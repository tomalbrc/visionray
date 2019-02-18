//
//  CBox.cpp
//  trace
//
//  Created by Tom Albrecht on 31.01.19.
//  Copyright © 2019 Tom Albrecht. All rights reserved.
//

#include "CBox.hpp"

NS_VRAY_BEGIN

CBox::CBox(
    const Vec3d &min,
    const Vec3d &max) :
    _min{std::move(min)}, _max{std::move(max)}
{
    
}

template <typename T> bool isBetweenInclusive(const T& val, const T& min, const T& max)
{
    return (val >= min && val <= max);
}

template <typename T> bool isBetweenExclusive(const T& val, const T& min, const T& max)
{
    return (val > min && val < max);
}




template <typename T>
inline Void::Vec3<T> sgn(const Void::Vec3<T>& val)
{
    T tx = (0.0 < val.x) - (val.x < 0.0);
    T ty = (0.0 < val.y) - (val.y < 0.0);
    T tz = (0.0 < val.z) - (val.z < 0.0);
    return Void::Vec3<T>{tx,ty,tz};
}

template <typename T>
inline Void::Vec3<T> ComputeNormal(const Void::Vec3<T>& inter, const Void::Vec3<T>& aabbCenter)
{
    static Void::Vec3<T> normals[] = { // A cube has 3 possible orientations
        Void::Vec3<T>(1,0,0),
        Void::Vec3<T>(0,1,0),
        Void::Vec3<T>(0,0,1)
    };
    
    const auto interRelative = inter - aabbCenter;
    const auto xyCoef = interRelative.y / interRelative.x;
    const auto zyCoef = interRelative.y / interRelative.z;
    
    const int coef =    (isBetweenInclusive(xyCoef, -1.f, 1.f)? 1 :
                        (isBetweenExclusive(zyCoef, -1.f, 1.f) ? 2 : 0));
    // Here it's exclusive to avoid coef to be 3
    return normals[coef] * sgn(interRelative); // The sign here is used to know direction of the normal
}

bool CBox::hit(const math::Ray& ray, Intersection &inter)
{
    
    auto d = ray.direction;
    auto inv_direction = Vec3d(1.0/d.x, 1.0/d.y, 1.0/d.z);
    Void::Vec3<bool> sign;
    sign.x = (inv_direction.x < 0);
    sign.y = (inv_direction.y < 0);
    sign.z = (inv_direction.z < 0);
    
    auto rt = _min;
    auto lb = _max;
    
    double t;
    double t1 = (lb.x - ray.origin.x)*inv_direction.x;
    double t2 = (rt.x - ray.origin.x)*inv_direction.x;
    double t3 = (lb.y - ray.origin.y)*inv_direction.y;
    double t4 = (rt.y - ray.origin.y)*inv_direction.y;
    double t5 = (lb.z - ray.origin.z)*inv_direction.z;
    double t6 = (rt.z - ray.origin.z)*inv_direction.z;
    
    double tmin = fmax(fmax(fmin(t1, t2), fmin(t3, t4)), fmin(t5, t6));
    double tmax = fmin(fmin(fmax(t1, t2), fmax(t3, t4)), fmax(t5, t6));
    
    // if tmax < 0, ray (line) is intersecting AABB, but the whole AABB is behind us
    if (tmax < 0)
    {
        //t = tmax;
        return false;
    }
    
    // if tmin > tmax, ray doesn't intersect AABB
    if (tmin > tmax)
    {
        //t = tmax;
        return false;
    }
    
    t = tmin;
    
    Intersection &i = inter;
    i.best_t = t/ray.length;
    i.point = ray.direction*i.best_t+ray.origin;
    auto center = (_max-_min);
    auto dis = center.norm();
    i.normal = ComputeNormal(i.point, center*(dis/2.0));
    
    return true;
}

NS_VRAY_END
