#ifndef R_MATH_MAT3_HPP
#define R_MATH_MAT3_HPP

#include <r-common.hpp>
#include <r-math-vec2.hpp>

struct RMathMat3 {
    union {
        r_f32 m9[9];

        struct {
            r_f32 r0c0;
            r_f32 r0c1;
            r_f32 r0c2;
            r_f32 r1c0;
            r_f32 r1c1;
            r_f32 r1c2;
            r_f32 r2c0;
            r_f32 r2c1;
            r_f32 r2c2;
        };
    };
};

typedef RMathMat3 r_m3;

namespace r_math {

    inline r_void 
    mat3_identity(r_m3& m3) {
        m3.r0c0 = 1.0f;
        m3.r0c1 = 0.0f;
        m3.r0c2 = 0.0f;
        m3.r1c0 = 0.0f;
        m3.r1c1 = 1.0f;
        m3.r1c2 = 0.0f;
        m3.r2c0 = 0.0f;
        m3.r2c1 = 0.0f;
        m3.r2c2 = 1.0f;
    }

    r_external r_void mat3_translation (r_v2* in_v2_translation, r_m3* out_m3_translation, const r_size count);
    r_external r_void mat3_scale       (r_v2* in_v2_scale,       r_m3* out_m3_scale,       const r_size count);
    r_external r_void mat3_rotation    (r_v2* in_v2_rotation,    r_m3* out_m3_rotation,    const r_size count);

    r_external r_void 
    mat3_transform(
              r_v2*  in_v2_translation,
              r_v2*  in_v2_scale,
              r_v2*  in_v2_rotation,
              r_m3*  out_m3_transform,
        const r_size count);
};

#endif //R_MATH_MAT3_HPPP