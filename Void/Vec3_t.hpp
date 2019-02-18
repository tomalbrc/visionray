#ifndef VEC3_T_HPP
#define VEC3_T_HPP

#include <cmath>
#include <cstring>
#include <ostream>

namespace Void
{
    template <class T>
    class Vec3
    {
    public:
        T       x;
        T       y;
        T       z;

        // Ctors
        Vec3<T>() : x(0), y(0), z(0), _unit(false) {}
        Vec3<T>(T ax, T ay, T az, bool unit = false): x(ax), y(ay), z(az), _unit(unit) {}
        Vec3<T>(const T& rhs) { *this = rhs; }
        Vec3<T>(const T&& rhs) { std::swap(*this, rhs); }

        bool    unit()
        {
            if (_unit)
                return true;
            if (squaredNorm() == 1)
            {
                _unit = true;
                return true;
            }
            return false;
        }

        // Otors
        Vec3<T>&    operator=(const Vec3<T> rhs)
        {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            _unit = rhs._unit;
            return *this;
        }
        // Vector/Vector operations
        Vec3<T>     operator+(const Vec3<T>& rhs) const
        {
            return Vec3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
        }
        Vec3<T>     operator-(const Vec3<T>& rhs) const
        {
            return Vec3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
        }
        Vec3<T>     operator*(const Vec3<T>& rhs) const
        {
            return Vec3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
        }
        Vec3<T>     operator/(const Vec3<T>& rhs) const
        {
            return Vec3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
        }

        // Vector scalar operations
        Vec3<T>     operator+(const T& s) const
        {
            return Vec3<T>(x + s, y + s, z + s);
        }
        Vec3<T>     operator-(const T& s) const
        {
            return Vec3<T>(x - s, y - s, z - s);
        }
        Vec3<T>     operator*(const T& s) const
        {
            return Vec3<T>(x * s, y * s, z * s);
        }
        Vec3<T>     operator/(const T& s) const
        {
            return Vec3<T>(x / s, y / s, z / s);
        }

        // Vector/Vector operations
        Vec3<T>&    operator+=(const Vec3<T>& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            _unit = false;
            return *this;
        }
        Vec3<T>&    operator-=(const Vec3<T>& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            _unit = false;
            return *this;
        }
        Vec3<T>&    operator*=(const Vec3<T>& v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            _unit = false;
            return *this;
        }
        Vec3<T>&    operator/=(const Vec3<T>& v)
        {
            x /= v.x;
            y /= v.y;
            z /= v.z;
            _unit = false;
            return *this;
        }

        // Vector/Scalar operations
        Vec3<T>&    operator+=(const T v)
        {
            x += v;
            y += v;
            z += v;
            _unit = false;
            return *this;
        }
        Vec3<T>&    operator-=(const T v)
        {
            x -= v;
            y -= v;
            z -= v;
            _unit = false;
            return *this;
        }
        Vec3<T>&    operator*=(const T v)
        {
            x *= v;
            y *= v;
            z *= v;
            _unit = false;
            return *this;
        }
        Vec3<T>&    operator/=(const T v)
        {
            x /= v;
            y /= v;
            z /= v;
            _unit = false;
            return *this;
        }

        // Functions
        T       norm()              { return ((_unit) ? 1 : sqrt(x * x + y * y + z * z)); }
        T       squaredNorm()       { return ((_unit) ? 1 : (x * x + y * y + z * z)); }

        void    normalize()
        {
            if (_unit)
                return;
            T norm = this->norm();
            x /= norm;
            y /= norm;
            z /= norm;
            _unit = true;
        }

        T dot(const Vec3<T>& rhs) const
        {
            return (x * rhs.x + y * rhs.y + z * rhs.z);
        }

        Vec3<T> cross(const Vec3<T>& rhs) const
        {
            return Vec3<T>(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
        }

        // Dtor
        ~Vec3<T>() {}

    private:
        bool    _unit;
    };

    template <typename T>
    const std::ostream& operator<<(const std::ostream& os, const Vec3<T>& v)
    {
        os << v.x << " " << v.y << " " << v.z << std::endl;
        return os;
    }
};

#endif
