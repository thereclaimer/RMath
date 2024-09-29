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

    r_void vec3_add             (r_v3* in_v3_a, r_v3* in_v3_b, r_v3*  out_v3_a_plus_b,  const r_size count);
    r_void vec3_subtract        (r_v3* in_v3_a, r_v3* in_v3_b, r_v3*  out_v3_a_sub_b,   const r_size count);
    r_void vec3_dot             (r_v3* in_v3_a, r_v3* in_v3_b, r_f32* out_a_dot_b,      const r_size count);
    r_void vec3_cross           (r_v3* in_v3_a, r_v3* in_v3_b, r_v3*  out_v3_a_cross_b, const r_size count);
    r_void vec3_multiply_scalar (r_v3* in_v3, r_v3* out_v3, const r_f32 scalar, const r_size count);
    r_void vec3_divide_scalar   (r_v3* in_v3, r_v3* out_v3, const r_f32 scalar, const r_size count);
    r_void vec3_magnitude       (r_v3* in_v3, r_f32* out_magnitude,     const r_size count);
    r_void vec3_normalize       (r_v3* in_v3, r_v3*  out_v3_normalized, const r_size count);

};

struct RMathVec3Table {
    r_size row_count;
    struct {
        r_f32* x;
        r_f32* y;
        r_f32* z;
    } columns;
};

namespace r_math {

    r_void vec3_table_create(
              RMathVec3Table& table_4_f32_aligned,
        const r_memory        table_4_f32_aligned_memory,
        const r_size          table_4_f32_aligned_row_count);


};

inline r_void
r_math::vec3_add(
          r_v3*  in_v3_a,
          r_v3*  in_v3_b,
          r_v3*  out_v3_a_plus_b,
    const r_size count) {

}

inline r_void
r_math::vec3_subtract(
          r_v3*  in_v3_a,
          r_v3*  in_v3_b,
          r_v3*  out_v3_a_sub_b,
    const r_size count) {

}

inline r_void 
r_math::vec3_dot(
          r_v3*  in_v3_a,
          r_v3*  in_v3_b,
          r_f32* out_a_dot_b,
    const r_size count) {

}

inline r_void
r_math::vec3_cross(
          r_v3*  in_v3_a,
          r_v3*  in_v3_b,
          r_v3*  out_v3_a_cross_b,
    const r_size count) {

}

inline r_void
r_math::vec3_multiply_scalar(
          r_v3*  in_v3,
          r_v3*  out_v3,
    const r_f32  scalar,
    const r_size count) {

}

inline r_void
r_math::vec3_divide_scalar(
          r_v3*  in_v3,
          r_v3*  out_v3,
    const r_f32  scalar,
    const r_size count) {

}

inline r_void
r_math::vec3_magnitude(
          r_v3*  in_v3,
          r_f32* out_magnitude,
    const r_size count) {

}

inline r_void
r_math::vec3_normalize(
          r_v3*  in_v3,
          r_v3*  out_v3_normalized,
    const r_size count) {

}

inline r_void 
r_math::vec3_table_add(
    RMathVec3Table& in_table_a,
    RMathVec3Table& in_table_b,
    RMathVec3Table& out_table_a_plus_b) {

    r_simd_4_f32 xmm_0_vec_a_col_x;
    r_simd_4_f32 xmm_1_vec_a_col_y;
    r_simd_4_f32 xmm_2_vec_a_col_z;
    r_simd_4_f32 xmm_3_vec_b_col_x;
    r_simd_4_f32 xmm_4_vec_b_col_y;
    r_simd_4_f32 xmm_5_vec_b_col_z;

    for (
        r_index row = 0;
        row < out_table_a_plus_b.row_count;
        row += 4) {

        //vector a columns
        xmm_0_vec_a_col_x = r_simd_4_f32_load_aligned(&in_table_a.columns.x[row]);
        xmm_1_vec_a_col_y = r_simd_4_f32_load_aligned(&in_table_a.columns.y[row]);
        xmm_2_vec_a_col_z = r_simd_4_f32_load_aligned(&in_table_a.columns.z[row]);

        //vector b columns
        xmm_3_vec_b_col_x = r_simd_4_f32_load_aligned(&in_table_b.columns.x[row]);
        xmm_4_vec_b_col_y = r_simd_4_f32_load_aligned(&in_table_b.columns.y[row]);
        xmm_5_vec_b_col_z = r_simd_4_f32_load_aligned(&in_table_b.columns.z[row]);

        //columns a + b
        xmm_0_vec_a_col_x = r_simd_4_f32_add(xmm_0_vec_a_col_x,xmm_3_vec_b_col_x);
        xmm_1_vec_a_col_y = r_simd_4_f32_add(xmm_1_vec_a_col_y,xmm_4_vec_b_col_y);
        xmm_2_vec_a_col_z = r_simd_4_f32_add(xmm_2_vec_a_col_z,xmm_5_vec_b_col_z);

        //store result
        r_simd_4_f32_store(&out_table_a_plus_b.columns.x[row],xmm_0_vec_a_col_x);
        r_simd_4_f32_store(&out_table_a_plus_b.columns.y[row],xmm_1_vec_a_col_y);
        r_simd_4_f32_store(&out_table_a_plus_b.columns.z[row],xmm_2_vec_a_col_z);
    }
}

#endif //R_MATH_VEC3_HPP