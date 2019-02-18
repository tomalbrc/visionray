#ifndef MAT4_T_HPP
#define MAT4_T_HPP

#include <ostream>
#include <iomanip>
#include "Vec3_t.hpp"

namespace Void
{
    template <class T>
    class Mat4
    {
    public:
    T   m[16];

    // Ctors
    Mat4()
    {
        memset(m, 0, 16 * sizeof(T));
        m[0] = 1;
        m[5] = 1;
        m[10] = 1;
        m[15] = 1;
    }

    Mat4(Vec3<T> tx, Vec3<T> ty, Vec3<T> tz, Vec3<T> t)
    {
        m[0] = tx.x;
        m[4] = tx.y;
        m[8] = tx.z;
        m[12] = 0;
        m[1] = ty.x;
        m[5] = ty.y;
        m[9] = ty.z;
        m[13] = 0;
        m[2] = tz.x;
        m[6] = tz.y;
        m[10] = tz.z;
        m[14] = 0;
        m[3] = t.x;
        m[7] = t.y;
        m[11] = t.z;
        m[15] = 1;
    }

    Mat4(const Mat4<T>& rhs)
    {
        *this = rhs;
    }

    void        set(Vec3<T> tx, Vec3<T> ty, Vec3<T> tz, Vec3<T> t)
    {
        m[0] = tx.x;
        m[4] = tx.y;
        m[8] = tx.z;
        m[12] = 0;
        m[1] = ty.x;
        m[5] = ty.y;
        m[9] = ty.z;
        m[13] = 0;
        m[2] = tz.x;
        m[6] = tz.y;
        m[10] = tz.z;
        m[14] = 0;
        m[3] = t.x;
        m[7] = t.y;
        m[11] = t.z;
        m[15] = 1;
    }

    Mat4<T>     inverse()
    {
        Mat4<T> inv, invOut;
        float det;
        int i;

        inv[0] = m[5]  * m[10] * m[15] -
                m[5]  * m[11] * m[14] -
                m[9]  * m[6]  * m[15] +
                m[9]  * m[7]  * m[14] +
                m[13] * m[6]  * m[11] -
                m[13] * m[7]  * m[10];

        inv[4] = -m[4]  * m[10] * m[15] +
                m[4]  * m[11] * m[14] +
                m[8]  * m[6]  * m[15] -
                m[8]  * m[7]  * m[14] -
                m[12] * m[6]  * m[11] +
                m[12] * m[7]  * m[10];

        inv[8] = m[4]  * m[9] * m[15] -
                m[4]  * m[11] * m[13] -
                m[8]  * m[5] * m[15] +
                m[8]  * m[7] * m[13] +
                m[12] * m[5] * m[11] -
                m[12] * m[7] * m[9];

        inv[12] = -m[4]  * m[9] * m[14] +
                m[4]  * m[10] * m[13] +
                m[8]  * m[5] * m[14] -
                m[8]  * m[6] * m[13] -
                m[12] * m[5] * m[10] +
                m[12] * m[6] * m[9];

        inv[1] = -m[1]  * m[10] * m[15] +
                m[1]  * m[11] * m[14] +
                m[9]  * m[2] * m[15] -
                m[9]  * m[3] * m[14] -
                m[13] * m[2] * m[11] +
                m[13] * m[3] * m[10];

        inv[5] = m[0]  * m[10] * m[15] -
                m[0]  * m[11] * m[14] -
                m[8]  * m[2] * m[15] +
                m[8]  * m[3] * m[14] +
                m[12] * m[2] * m[11] -
                m[12] * m[3] * m[10];

        inv[9] = -m[0]  * m[9] * m[15] +
                m[0]  * m[11] * m[13] +
                m[8]  * m[1] * m[15] -
                m[8]  * m[3] * m[13] -
                m[12] * m[1] * m[11] +
                m[12] * m[3] * m[9];

        inv[13] = m[0]  * m[9] * m[14] -
                m[0]  * m[10] * m[13] -
                m[8]  * m[1] * m[14] +
                m[8]  * m[2] * m[13] +
                m[12] * m[1] * m[10] -
                m[12] * m[2] * m[9];

        inv[2] = m[1]  * m[6] * m[15] -
                m[1]  * m[7] * m[14] -
                m[5]  * m[2] * m[15] +
                m[5]  * m[3] * m[14] +
                m[13] * m[2] * m[7] -
                m[13] * m[3] * m[6];

        inv[6] = -m[0]  * m[6] * m[15] +
                m[0]  * m[7] * m[14] +
                m[4]  * m[2] * m[15] -
                m[4]  * m[3] * m[14] -
                m[12] * m[2] * m[7] +
                m[12] * m[3] * m[6];

        inv[10] = m[0]  * m[5] * m[15] -
                m[0]  * m[7] * m[13] -
                m[4]  * m[1] * m[15] +
                m[4]  * m[3] * m[13] +
                m[12] * m[1] * m[7] -
                m[12] * m[3] * m[5];

        inv[14] = -m[0]  * m[5] * m[14] +
                m[0]  * m[6] * m[13] +
                m[4]  * m[1] * m[14] -
                m[4]  * m[2] * m[13] -
                m[12] * m[1] * m[6] +
                m[12] * m[2] * m[5];

        inv[3] = -m[1] * m[6] * m[11] +
                m[1] * m[7] * m[10] +
                m[5] * m[2] * m[11] -
                m[5] * m[3] * m[10] -
                m[9] * m[2] * m[7] +
                m[9] * m[3] * m[6];

        inv[7] = m[0] * m[6] * m[11] -
                m[0] * m[7] * m[10] -
                m[4] * m[2] * m[11] +
                m[4] * m[3] * m[10] +
                m[8] * m[2] * m[7] -
                m[8] * m[3] * m[6];

        inv[11] = -m[0] * m[5] * m[11] +
                m[0] * m[7] * m[9] +
                m[4] * m[1] * m[11] -
                m[4] * m[3] * m[9] -
                m[8] * m[1] * m[7] +
                m[8] * m[3] * m[5];

        inv[15] = m[0] * m[5] * m[10] -
                m[0] * m[6] * m[9] -
                m[4] * m[1] * m[10] +
                m[4] * m[2] * m[9] +
                m[8] * m[1] * m[6] -
                m[8] * m[2] * m[5];

        det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
        if (det == 0)
            return invOut;

        det = 1.f / det;
        for (i = 0; i < 16; i++)
            invOut[i] = inv[i] * det;

        return invOut;
    }

    // Otors
    T           operator[](int i) const    { return m[i]; }
    T&          operator[](int i)          { return m[i]; }

    Mat4<T>&    operator=(const Mat4<T>& rhs)
    {
        memcpy(m, rhs.m, 16 * sizeof(T));
        return *this;
    }

    Mat4<T>&    operator*(const Mat4<T>& m2)
    {
        Mat4<T> m1(*this);

        m[0] = m1[0] * m2[0] + m1[1] * m2[4] + m1[2] * m2[8] + m1[3] * m2[12];
        m[1] = m1[0] * m2[1] + m1[1] * m2[5] + m1[2] * m2[9] + m1[3] * m2[13];
        m[2] = m1[0] * m2[2] + m1[1] * m2[6] + m1[2] * m2[10] + m1[3] * m2[14];
        m[3] = m1[0] * m2[3] + m1[1] * m2[7] + m1[2] * m2[11] + m1[3] * m2[15];
        //
        m[4] = m1[4] * m2[0] + m1[5] * m2[4] + m1[6] * m2[8] + m1[7] * m2[12];
        m[5] = m1[4] * m2[1] + m1[5] * m2[5] + m1[6] * m2[9] + m1[7] * m2[13];
        m[6] = m1[4] * m2[2] + m1[5] * m2[6] + m1[6] * m2[10] + m1[7] * m2[14];
        m[7] = m1[4] * m2[3] + m1[5] * m2[7] + m1[6] * m2[11] + m1[7] * m2[15];
        //
        m[8] = m1[8] * m2[0] + m1[9] * m2[4] + m1[10] * m2[8] + m1[11] * m2[12];
        m[9] = m1[8] * m2[1] + m1[9] * m2[5] + m1[10] * m2[9] + m1[11] * m2[13];
        m[10] = m1[8] * m2[2] + m1[9] * m2[6] + m1[10] * m2[10] + m1[11] * m2[14];
        m[11] = m1[8] * m2[3] + m1[9] * m2[7] + m1[10] * m2[11] + m1[11] * m2[15];
        //
        m[12] = m1[12] * m2[0] + m1[13] * m2[4] + m1[14] * m2[8] + m1[15] * m2[12];
        m[13] = m1[12] * m2[1] + m1[13] * m2[5] + m1[14] * m2[9] + m1[15] * m2[13];
        m[14] = m1[12] * m2[2] + m1[13] * m2[6] + m1[14] * m2[10] + m1[15] * m2[14];
        m[15] = m1[12] * m2[3] + m1[13] * m2[7] + m1[14] * m2[11] + m1[15] * m2[15];

        return *this;
    }

    Vec3<T>& operator*(Vec3<T>& v)
    {
        Vec3<T> v1(v);

        v.x = m[0] * v1.x + m[1] * v1.y + m[2] * v1.z + m[3];
        v.y = m[4] * v1.x + m[5] * v1.y + m[6] * v1.z + m[7];
        v.z = m[8] * v1.x + m[9] * v1.y + m[10] * v1.z + m[11];
        return v;
    }

    // Dtor
    ~Mat4() {}
    };

    inline std::ostream&   operator<<(std::ostream& os, Mat4<float>& m)
    {
        os << std::setw(20) << std::left << m[0] << std::setw(20) << std::left << m[1] << std::setw(20) << std::left << m[2] << std::setw(20) << std::left << m[3] <<std::endl;
        os << std::setw(20) << std::left << m[4] << std::setw(20) << std::left << m[5] << std::setw(20) << std::left << m[6] << std::setw(20) << std::left << m[7] <<std::endl;
        os << std::setw(20) << std::left << m[8] << std::setw(20) << std::left << m[9] << std::setw(20) << std::left << m[10] << std::setw(20) << std::left << m[11] <<std::endl;
        os << std::setw(20) << std::left << m[12] << std::setw(20) << std::left << m[13] << std::setw(20) << std::left << m[14] << std::setw(20) << std::left << m[15] <<std::endl;

        return os;
    }
};

#endif
