#ifndef R_MATH_QUATERNION_HPP
#define R_MATH_QUATERNION_HPP

#include <r-common.hpp>

struct RMathQuaternion {
    r_f32 x;
    r_f32 y;
    r_f32 z;
    r_f32 w;
};

typedef RMathQuaternion r_q4;

#endif //R_MATH_QUATERNION_HPP