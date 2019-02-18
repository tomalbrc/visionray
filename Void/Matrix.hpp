#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Mat4_t.hpp"
#include "Utils.hpp"

namespace Void
{

    namespace Matrix4
    {
        // Identity matrix
        template <typename T>
        Mat4<T>videntity()
        {
            return Mat4<T>();
        }

        // Translation matrix (vector-defined)
        template <typename T>
        Mat4<T> translation(Vec3<T>& v)
        {
            Mat4<T> m;

            m[3] = v.x;
            m[7] = v.y;
            m[11] = v.z;
            return m;
        }

        // Translation matrix
        template <typename T>
        Mat4<T> translation(T x, T y, T z)
        {
            Mat4<T> m;

            m[3] = x;
            m[7] = y;
            m[11] = z;
            return m;
        }

        // Rotation matrix
        template <typename T>
        Mat4<T> rotation(float angle, enum Axis axis, enum AngleType type = RADIANS)
        {
            Mat4<T> m;
            float   angleRad = (type == RADIANS) ? angle : degToRad(angle);
            float   cosA = cosf(angleRad);
            float   sinA = sinf(angleRad);

            switch (axis)
            {
                case X_AXIS:
                    m[5] = cosA;
                    m[6] = sinA;
                    m[9] = -sinA;
                    m[10] = cosA;
                    break;
                case Y_AXIS:
                    m[0] = cosA;
                    m[2] = -sinA;
                    m[8] = sinA;
                    m[10] = cosA;
                    break;
                case Z_AXIS:
                    m[0] = cosA;
                    m[1] = sinA;
                    m[4] = -sinA;
                    m[5] = cosA;
                    break;
                default:
                    break;
            }
            return m;
        }
    };
};

#endif
