#ifndef UTILS_HPP
#define UTILS_HPP

namespace Void
{
    // Defines rotation axis
    enum Axis
    {
        X_AXIS = 0,
        Y_AXIS,
        Z_AXIS
    };

    // Defines angle type (radians/degrees)
    enum AngleType
    {
        RADIANS = 0,
        DEGREES
    };

    // Degrees to radians function
	template <typename T>
    inline T degToRad(const T& degrees)
    {
        return degrees * T(M_PI) / 180.0;
    }

    // Radians to degrees function
	template <typename T>
    inline T radToDeg(const T& radians)
    {
        return radians * 180.0 / T(M_PI);
    }
};

#endif
