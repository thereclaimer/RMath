#ifndef R_MATH_MAT4_HPP
#define R_MATH_MAT4_HPP

#include <r-common.hpp>
#include <r-math-vec3.hpp>

struct RMathMat4 {
    union {
        r_f32 m16[16];

        struct {
            r_f32 r0c0;
            r_f32 r0c1;
            r_f32 r0c2;
            r_f32 r0c3;
            r_f32 r1c0;
            r_f32 r1c1;
            r_f32 r1c2;
            r_f32 r1c3;
            r_f32 r2c0;
            r_f32 r2c1;
            r_f32 r2c2;
            r_f32 r2c3;
            r_f32 r3c0;
            r_f32 r3c1;
            r_f32 r3c2;
            r_f32 r3c3;
        };
    };
};

typedef RMathMat4 r_m4;

namespace r_math {

    inline r_void 
    mat4_identity(r_m4& m4) {
        m4.r0c0 = 1.0f;
        m4.r0c1 = 0.0f;
        m4.r0c2 = 0.0f;
        m4.r0c3 = 0.0f;
        m4.r1c0 = 0.0f;
        m4.r1c1 = 1.0f;
        m4.r1c2 = 0.0f;
        m4.r1c3 = 0.0f;
        m4.r2c0 = 0.0f;
        m4.r2c1 = 0.0f;
        m4.r2c2 = 1.0f;
        m4.r2c3 = 0.0f;
        m4.r3c0 = 0.0f;
        m4.r3c1 = 0.0f;
        m4.r3c2 = 0.0f;
        m4.r3c3 = 1.0f;
    }

    r_external r_void mat4_translation (r_v3* in_v3_translation, r_m4* out_m4_translation, const r_size count);
    r_external r_void mat4_scale       (r_v3* in_v3_scale,       r_m4* out_m4_scale,       const r_size count);
    r_external r_void mat4_rotation    (r_v3* in_v3_rotation,    r_m4* out_m4_rotation,    const r_size count);

    r_external r_void 
    mat4_transform(
              r_v3*  in_v3_translation,
              r_v3*  in_v3_scale,
              r_v3*  in_v3_rotation,
              r_m4*  out_m4_transform,
        const r_size count);
};

#endif //R_MATH_MAT3_HPPP