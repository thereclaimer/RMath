#ifndef R_MATH_TRIG_HPP
#define R_MATH_TRIG_HPP

#include <r-common.hpp>

#define R_MATH_TRIG_PI                  3.14159265
#define R_MATH_TRIG_DEG_TO_RAD_CONSTANT 0.01745329 // (Pi / 180)

namespace r_math {

    inline const r_f32
    trig_degrees_to_radians(
        const r_f32 degrees) {

        const r_f32 radians = degrees * R_MATH_TRIG_DEG_TO_RAD_CONSTANT;

        return(radians);
    }
};

#endif  //R_MATH_TRIG_HPP