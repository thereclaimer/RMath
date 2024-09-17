#ifndef R_MATH_VEC3_HPP
#define R_MATH_VEC3_HPP

#include <r-common.hpp>

struct RMathVec3 {
    r_f32 x;
    r_f32 y;
    r_f32 z;
};

typedef RMathVec3 r_v3;

namespace r_math {

    r_external r_void vec3_add      (r_v3* in_v3_a, r_v3* in_v3_b, r_v3*  out_v3_a_plus_b,  const r_size count);
    r_external r_void vec3_subtract (r_v3* in_v3_a, r_v3* in_v3_b, r_v3*  out_v3_a_sub_b,   const r_size count);
    r_external r_void vec3_dot      (r_v3* in_v3_a, r_v3* in_v3_b, r_f32* out_a_dot_b,      const r_size count);
    r_external r_void vec3_cross    (r_v3* in_v3_a, r_v3* in_v3_b, r_v3*  out_v3_a_cross_b, const r_size count);

    r_external r_void vec3_multiply_scalar (r_v3* in_v3, r_v3* out_v3, const r_f32 scalar, const r_size count);
    r_external r_void vec3_divide_scalar   (r_v3* in_v3, r_v3* out_v3, const r_f32 scalar, const r_size count);
    
    r_external r_void vec3_magnitude (r_v3* in_v3, r_f32* out_magnitude,     const r_size count);
    r_external r_void vec3_normalize (r_v3* in_v3, r_v3*  out_v3_normalized, const r_size count);
};


#endif //R_MATH_VEC3_HPP