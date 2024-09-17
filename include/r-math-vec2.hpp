#ifndef R_MATH_VEC2_HPP
#define R_MATH_VEC2_HPP

#include <r-common.hpp>

struct RMathVec2 {
    r_f32 x;
    r_f32 y;    
};

typedef r_v2;

namespace r_math {

    r_external r_void vec2_add             (r_v2* in_v2_a, r_v2* in_v2_b, r_v2* out_v2_c, r_size count);
    r_external r_void vec2_subtract        (r_v2* in_v2_a, r_v2* in_v2_b, r_v2* out_v2_c, r_size count);
    r_external r_void vec2_multiply_scalar (r_v2* in_v2, r_v2* out_v2, r_f32 scalar, r_size count);
    r_external r_void vec2_divide_scalar   (r_v2* in_v2, r_v2* out_v2, r_f32 scalar, r_size count);
    r_external r_void vec2_normalize       (r_v2* in_v2,   r_v2* out_v2_normalized, r_size count);
    r_external r_void vec2_magnitude       (r_v2* in_v2, r_f32* out_magnitude, r_size count);
};


#endif //R_MATH_HPP