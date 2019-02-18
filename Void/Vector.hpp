#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Vec3_t.hpp"

namespace Void
{
    namespace Vector3
    {
        // X-axis unit vector
        template <typename T>
        Vec3<T>
        unitX()
        {
            return Vec3<T>(1, 0, 0);
        }
        // Y-axis unit vector
        template <typename T>
        Vec3<T>
        unitY()
        {
            return Vec3<T>(0, 1, 0);
        }
        // Z-axis unit vector
        template <typename T>
        Vec3<T>
        unitZ()
        {
            return Vec3<T>(0, 0, 1);
        }
    };
};

#endif
