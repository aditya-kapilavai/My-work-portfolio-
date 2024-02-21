/* Include files */

#include "blascompat32.h"
#include "Cinematica_JA_reducido_sfun.h"
#include "c2_Cinematica_JA_reducido.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Cinematica_JA_reducido_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[36] = { "q1", "q2", "q3", "q4", "qt",
  "d2", "a2", "a3", "a4", "a5", "a6", "H", "Pxyz", "R", "r21", "r11", "r31",
  "r32", "r33", "al", "ga", "th", "Theta", "Jg", "Tphi", "iTphi", "Ta_phi", "Ja",
  "Ja_b", "J_ainv", "nargin", "nargout", "q", "Ke", "qp", "X_b" };

/* Function Declarations */
static void initialize_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void initialize_params_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void enable_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void disable_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void set_sim_state_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void sf_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void c2_chartstep_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void initSimStructsc2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_X_b, const char_T *c2_identifier, real_T
  c2_y[4]);
static void c2_b_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[36]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[62]);
static real_T c2_atan2(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_y, real_T c2_x);
static void c2_eml_scalar_eg(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);
static real_T c2_mpower(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_a);
static real_T c2_power(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_b);
static void c2_eml_error(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);
static real_T c2_sqrt(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x);
static void c2_b_eml_error(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);
static void c2_inv(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                   real_T c2_x[9], real_T c2_y[9]);
static void c2_inv3x3(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x[9], real_T c2_y[9]);
static real_T c2_norm(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x[9]);
static void c2_eml_warning(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);
static void c2_eps(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void c2_b_eml_warning(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, char_T c2_varargin_2[14]);
static void c2_eye(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                   real_T c2_I[9]);
static void c2_b_eml_scalar_eg(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);
static void c2_b_inv(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                     real_T c2_x[16], real_T c2_y[16]);
static void c2_invNxN(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x[16], real_T c2_y[16]);
static void c2_eml_matlab_zgetrf(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, real_T c2_A[16], real_T c2_b_A[16], int32_T c2_ipiv[4],
  int32_T *c2_info);
static int32_T c2_eml_ixamax(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0);
static int32_T c2_ceval_ixamax(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, int32_T c2_incx);
static void c2_ceval_xswap(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[16]);
static void c2_ceval_xger(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_A[16], int32_T
  c2_ia0, int32_T c2_lda, real_T c2_b_A[16]);
static void c2_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[16], int32_T c2_ib0, int32_T
  c2_ldb, real_T c2_b_B[16]);
static real_T c2_b_norm(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_x[16]);
static void c2_b_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb,
  real_T c2_b_B[4]);
static void c2_c_eml_scalar_eg(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);
static void c2_c_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb,
  real_T c2_b_B[4]);
static void c2_i_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_y[14]);
static void c2_j_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[14]);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_k_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_l_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Cinematica_JA_reducido, const
  char_T *c2_identifier);
static uint8_T c2_m_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T *c2_x);
static void c2_b_eml_matlab_zgetrf(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, real_T c2_A[16], int32_T c2_ipiv[4], int32_T *c2_info);
static void c2_b_ceval_xswap(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy);
static void c2_b_ceval_xger(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_A[16], int32_T
  c2_ia0, int32_T c2_lda);
static void c2_d_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[16], int32_T c2_ib0, int32_T
  c2_ldb);
static void c2_e_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb);
static void c2_f_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb);
static void init_dsm_address_info(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Cinematica_JA_reducido = 0U;
}

static void initialize_params_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static void enable_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[4];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[4];
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T (*c2_qp)[4];
  real_T (*c2_X_b)[4];
  c2_X_b = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3));
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    c2_u[c2_i0] = (*c2_X_b)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_qp)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_Cinematica_JA_reducido;
  c2_c_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[4];
  int32_T c2_i2;
  real_T c2_dv1[4];
  int32_T c2_i3;
  real_T (*c2_X_b)[4];
  real_T (*c2_qp)[4];
  c2_X_b = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "X_b",
                      c2_dv0);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    (*c2_X_b)[c2_i2] = c2_dv0[c2_i2];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "qp",
                      c2_dv1);
  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    (*c2_qp)[c2_i3] = c2_dv1[c2_i3];
  }

  chartInstance->c2_is_active_c2_Cinematica_JA_reducido = c2_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_Cinematica_JA_reducido");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Cinematica_JA_reducido(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static void sf_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  real_T (*c2_Ke)[4];
  real_T (*c2_X_b)[4];
  real_T (*c2_qp)[4];
  real_T (*c2_q)[4];
  c2_Ke = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c2_X_b = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_q)[c2_i4], 0U);
  }

  for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_qp)[c2_i5], 1U);
  }

  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*c2_X_b)[c2_i6], 2U);
  }

  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_Ke)[c2_i7], 3U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Cinematica_JA_reducido(chartInstance);
  sf_debug_check_for_state_inconsistency(_Cinematica_JA_reducidoMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  int32_T c2_i8;
  real_T c2_q[4];
  int32_T c2_i9;
  real_T c2_Ke[4];
  uint32_T c2_debug_family_var_map[36];
  real_T c2_q1;
  real_T c2_q2;
  real_T c2_q3;
  real_T c2_q4;
  real_T c2_qt[4];
  real_T c2_d2;
  real_T c2_a2;
  real_T c2_a3;
  real_T c2_a4;
  real_T c2_a5;
  real_T c2_a6;
  real_T c2_H[16];
  real_T c2_Pxyz[3];
  real_T c2_R[9];
  real_T c2_r21;
  real_T c2_r11;
  real_T c2_r31;
  real_T c2_r32;
  real_T c2_r33;
  real_T c2_al;
  real_T c2_ga;
  real_T c2_th;
  real_T c2_Theta;
  real_T c2_Jg[24];
  real_T c2_Tphi[9];
  real_T c2_iTphi[9];
  real_T c2_Ta_phi[36];
  real_T c2_Ja[24];
  real_T c2_Ja_b[16];
  real_T c2_J_ainv[16];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 2.0;
  real_T c2_qp[4];
  real_T c2_X_b[4];
  real_T c2_b_q1[4];
  int32_T c2_i10;
  int32_T c2_i11;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_c_b;
  real_T c2_d_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_d_b;
  real_T c2_e_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_e_b;
  real_T c2_f_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_f_b;
  real_T c2_g_y;
  real_T c2_c_a;
  real_T c2_g_b;
  real_T c2_h_y;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_h_b;
  real_T c2_i_y;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_i_b;
  real_T c2_j_y;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_j_b;
  real_T c2_k_y;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_k_b;
  real_T c2_l_y;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_d_a;
  real_T c2_l_b;
  real_T c2_m_y;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_e_a;
  real_T c2_m_b;
  real_T c2_n_y;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_n_b;
  real_T c2_o_y;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_f_a;
  real_T c2_o_b;
  real_T c2_p_y;
  real_T c2_g_a;
  real_T c2_q_y;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_h_a;
  real_T c2_p_b;
  real_T c2_r_y;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_i_a;
  real_T c2_q_b;
  real_T c2_s_y;
  real_T c2_j_a;
  real_T c2_t_y;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_k_a;
  real_T c2_r_b;
  real_T c2_u_y;
  real_T c2_ic_x;
  real_T c2_jc_x;
  real_T c2_l_a;
  real_T c2_s_b;
  real_T c2_v_y;
  real_T c2_m_a;
  real_T c2_w_y;
  int32_T c2_i12;
  int32_T c2_i13;
  static real_T c2_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  real_T c2_b_H[3];
  int32_T c2_i14;
  real_T c2_kc_x;
  real_T c2_lc_x;
  real_T c2_mc_x;
  real_T c2_nc_x;
  real_T c2_n_a;
  real_T c2_t_b;
  real_T c2_x_y;
  real_T c2_oc_x;
  real_T c2_pc_x;
  real_T c2_qc_x;
  real_T c2_rc_x;
  real_T c2_o_a;
  real_T c2_u_b;
  real_T c2_y_y;
  real_T c2_sc_x;
  real_T c2_tc_x;
  real_T c2_uc_x;
  real_T c2_vc_x;
  real_T c2_wc_x;
  real_T c2_xc_x;
  real_T c2_yc_x;
  real_T c2_ad_x;
  real_T c2_bd_x;
  real_T c2_cd_x;
  real_T c2_p_a;
  real_T c2_v_b;
  real_T c2_ab_y;
  real_T c2_dd_x;
  real_T c2_ed_x;
  real_T c2_fd_x;
  real_T c2_gd_x;
  real_T c2_q_a;
  real_T c2_w_b;
  real_T c2_bb_y;
  real_T c2_hd_x;
  real_T c2_id_x;
  real_T c2_d0;
  real_T c2_jd_x;
  real_T c2_kd_x;
  real_T c2_ld_x;
  real_T c2_md_x;
  real_T c2_x_b;
  real_T c2_cb_y;
  real_T c2_nd_x;
  real_T c2_od_x;
  real_T c2_y_b;
  real_T c2_db_y;
  real_T c2_pd_x;
  real_T c2_qd_x;
  real_T c2_ab_b;
  real_T c2_eb_y;
  real_T c2_rd_x;
  real_T c2_sd_x;
  real_T c2_bb_b;
  real_T c2_fb_y;
  real_T c2_r_a;
  real_T c2_cb_b;
  real_T c2_gb_y;
  real_T c2_td_x;
  real_T c2_ud_x;
  real_T c2_vd_x;
  real_T c2_wd_x;
  real_T c2_db_b;
  real_T c2_hb_y;
  real_T c2_xd_x;
  real_T c2_yd_x;
  real_T c2_eb_b;
  real_T c2_ib_y;
  real_T c2_ae_x;
  real_T c2_be_x;
  real_T c2_fb_b;
  real_T c2_jb_y;
  real_T c2_ce_x;
  real_T c2_de_x;
  real_T c2_gb_b;
  real_T c2_kb_y;
  real_T c2_s_a;
  real_T c2_hb_b;
  real_T c2_lb_y;
  real_T c2_ee_x;
  real_T c2_fe_x;
  real_T c2_ge_x;
  real_T c2_he_x;
  real_T c2_t_a;
  real_T c2_ib_b;
  real_T c2_mb_y;
  real_T c2_u_a;
  real_T c2_nb_y;
  real_T c2_ie_x;
  real_T c2_je_x;
  real_T c2_jb_b;
  real_T c2_ob_y;
  real_T c2_ke_x;
  real_T c2_le_x;
  real_T c2_kb_b;
  real_T c2_pb_y;
  real_T c2_me_x;
  real_T c2_ne_x;
  real_T c2_lb_b;
  real_T c2_qb_y;
  real_T c2_oe_x;
  real_T c2_pe_x;
  real_T c2_mb_b;
  real_T c2_rb_y;
  real_T c2_qe_x;
  real_T c2_re_x;
  real_T c2_v_a;
  real_T c2_sb_y;
  real_T c2_se_x;
  real_T c2_te_x;
  real_T c2_ue_x;
  real_T c2_ve_x;
  real_T c2_nb_b;
  real_T c2_tb_y;
  real_T c2_we_x;
  real_T c2_xe_x;
  real_T c2_ob_b;
  real_T c2_ub_y;
  real_T c2_ye_x;
  real_T c2_af_x;
  real_T c2_pb_b;
  real_T c2_vb_y;
  real_T c2_bf_x;
  real_T c2_cf_x;
  real_T c2_qb_b;
  real_T c2_wb_y;
  real_T c2_w_a;
  real_T c2_rb_b;
  real_T c2_xb_y;
  real_T c2_df_x;
  real_T c2_ef_x;
  real_T c2_ff_x;
  real_T c2_gf_x;
  real_T c2_sb_b;
  real_T c2_yb_y;
  real_T c2_hf_x;
  real_T c2_if_x;
  real_T c2_tb_b;
  real_T c2_ac_y;
  real_T c2_jf_x;
  real_T c2_kf_x;
  real_T c2_ub_b;
  real_T c2_bc_y;
  real_T c2_lf_x;
  real_T c2_mf_x;
  real_T c2_vb_b;
  real_T c2_cc_y;
  real_T c2_x_a;
  real_T c2_wb_b;
  real_T c2_dc_y;
  real_T c2_nf_x;
  real_T c2_of_x;
  real_T c2_pf_x;
  real_T c2_qf_x;
  real_T c2_y_a;
  real_T c2_xb_b;
  real_T c2_ec_y;
  real_T c2_ab_a;
  real_T c2_fc_y;
  real_T c2_rf_x;
  real_T c2_sf_x;
  real_T c2_tf_x;
  real_T c2_uf_x;
  real_T c2_vf_x;
  real_T c2_wf_x;
  real_T c2_xf_x;
  real_T c2_yf_x;
  int32_T c2_i15;
  int32_T c2_i16;
  static real_T c2_dv3[4] = { 0.0, -1.0, 0.0, 0.0 };

  real_T c2_ag_x;
  real_T c2_bg_x;
  real_T c2_cg_x;
  real_T c2_dg_x;
  real_T c2_bb_a;
  real_T c2_yb_b;
  real_T c2_gc_y;
  real_T c2_eg_x;
  real_T c2_fg_x;
  real_T c2_gg_x;
  real_T c2_hg_x;
  real_T c2_ig_x;
  real_T c2_jg_x;
  real_T c2_cb_a;
  real_T c2_ac_b;
  real_T c2_hc_y;
  real_T c2_kg_x;
  real_T c2_lg_x;
  real_T c2_mg_x;
  real_T c2_ng_x;
  int32_T c2_i17;
  real_T c2_b_Tphi[9];
  real_T c2_dv4[9];
  int32_T c2_i18;
  real_T c2_dv5[9];
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  real_T c2_db_a[36];
  int32_T c2_i34;
  real_T c2_bc_b[24];
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_C[24];
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_b_u[16];
  const mxArray *c2_ic_y = NULL;
  int32_T c2_i51;
  real_T c2_b_Ja_b[16];
  real_T c2_dv6[16];
  int32_T c2_i52;
  int32_T c2_i53;
  real_T c2_c_u[16];
  const mxArray *c2_jc_y = NULL;
  int32_T c2_i54;
  int32_T c2_i55;
  real_T c2_A[16];
  int32_T c2_i56;
  real_T c2_B[4];
  int32_T c2_info;
  int32_T c2_ipiv[4];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_i57;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_ip;
  real_T c2_temp;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  real_T c2_b_A[16];
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  real_T c2_c_A[16];
  int32_T c2_i64;
  int32_T c2_i65;
  real_T (*c2_b_qp)[4];
  real_T (*c2_b_X_b)[4];
  real_T (*c2_b_Ke)[4];
  real_T (*c2_b_q)[4];
  c2_b_Ke = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_X_b = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
    c2_q[c2_i8] = (*c2_b_q)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    c2_Ke[c2_i9] = (*c2_b_Ke)[c2_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 36U, 36U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_q1, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q2, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q3, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_q4, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_qt, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_d2, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_a2, 6U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a3, 7U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a4, 8U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a5, 9U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a6, 10U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_H, 11U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Pxyz, 12U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_R, 13U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r21, 14U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r11, 15U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r31, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r32, 17U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r33, 18U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_al, 19U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_ga, 20U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_th, 21U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Theta, 22U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Jg, 23U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Tphi, 24U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_iTphi, 25U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Ta_phi, 26U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Ja, 27U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Ja_b, 28U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_J_ainv, 29U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 30U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 31U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_q, 32U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_Ke, 33U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_qp, 34U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_X_b, 35U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  c2_q1 = c2_q[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_q2 = c2_q[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_q3 = c2_q[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_q4 = c2_q[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_b_q1[0] = c2_q1;
  c2_b_q1[1] = c2_q2;
  c2_b_q1[2] = c2_q3;
  c2_b_q1[3] = c2_q4;
  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_qt[c2_i10] = c2_b_q1[c2_i10];
  }

  sf_mex_printf("%s =\\n", "qt");
  for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
    c2_u[c2_i11] = c2_qt[c2_i11];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_d2 = 1.20349;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_a5 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_a6 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_x = c2_q3 + c2_q4;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_q2;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_a = -c2_b_x;
  c2_b = c2_d_x;
  c2_b_y = c2_a * c2_b;
  c2_e_x = c2_q3 + c2_q4;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_q2;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_b_a = c2_f_x;
  c2_b_b = c2_h_x;
  c2_c_y = c2_b_a * c2_b_b;
  c2_i_x = c2_q2;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarCos(c2_j_x);
  c2_k_x = c2_q2;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarSin(c2_l_x);
  c2_m_x = c2_q3 + c2_q4;
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarCos(c2_n_x);
  c2_c_b = c2_n_x;
  c2_d_y = 0.8862 * c2_c_b;
  c2_o_x = c2_q3 + c2_q4;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarCos(c2_p_x);
  c2_d_b = c2_p_x;
  c2_e_y = 1.5 * c2_d_b;
  c2_q_x = c2_q3;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarCos(c2_r_x);
  c2_e_b = c2_r_x;
  c2_f_y = 0.8862 * c2_e_b;
  c2_s_x = c2_q3;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_f_b = c2_t_x;
  c2_g_y = 1.5 * c2_f_b;
  c2_c_a = -c2_l_x;
  c2_g_b = (((c2_a2 + c2_d_y) + c2_e_y) + c2_f_y) + c2_g_y;
  c2_h_y = c2_c_a * c2_g_b;
  c2_u_x = c2_q3 + c2_q4;
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarSin(c2_v_x);
  c2_w_x = c2_q3 + c2_q4;
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarCos(c2_x_x);
  c2_y_x = c2_q3 + c2_q4;
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarSin(c2_ab_x);
  c2_h_b = c2_ab_x;
  c2_i_y = 0.8862 * c2_h_b;
  c2_bb_x = c2_q3 + c2_q4;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarSin(c2_cb_x);
  c2_i_b = c2_cb_x;
  c2_j_y = 1.5 * c2_i_b;
  c2_db_x = c2_q3;
  c2_eb_x = c2_db_x;
  c2_eb_x = muDoubleScalarSin(c2_eb_x);
  c2_j_b = c2_eb_x;
  c2_k_y = 0.8862 * c2_j_b;
  c2_fb_x = c2_q3;
  c2_gb_x = c2_fb_x;
  c2_gb_x = muDoubleScalarSin(c2_gb_x);
  c2_k_b = c2_gb_x;
  c2_l_y = 1.5 * c2_k_b;
  c2_hb_x = c2_q3 + c2_q4;
  c2_ib_x = c2_hb_x;
  c2_ib_x = muDoubleScalarCos(c2_ib_x);
  c2_jb_x = c2_q2;
  c2_kb_x = c2_jb_x;
  c2_kb_x = muDoubleScalarCos(c2_kb_x);
  c2_d_a = c2_ib_x;
  c2_l_b = c2_kb_x;
  c2_m_y = c2_d_a * c2_l_b;
  c2_lb_x = c2_q3 + c2_q4;
  c2_mb_x = c2_lb_x;
  c2_mb_x = muDoubleScalarSin(c2_mb_x);
  c2_nb_x = c2_q2;
  c2_ob_x = c2_nb_x;
  c2_ob_x = muDoubleScalarCos(c2_ob_x);
  c2_e_a = -c2_mb_x;
  c2_m_b = c2_ob_x;
  c2_n_y = c2_e_a * c2_m_b;
  c2_pb_x = c2_q2;
  c2_qb_x = c2_pb_x;
  c2_qb_x = muDoubleScalarSin(c2_qb_x);
  c2_rb_x = c2_q2;
  c2_sb_x = c2_rb_x;
  c2_sb_x = muDoubleScalarCos(c2_sb_x);
  c2_n_b = c2_sb_x;
  c2_o_y = 0.9907 * c2_n_b;
  c2_tb_x = c2_q2;
  c2_ub_x = c2_tb_x;
  c2_ub_x = muDoubleScalarCos(c2_ub_x);
  c2_vb_x = c2_q3;
  c2_wb_x = c2_vb_x;
  c2_wb_x = muDoubleScalarCos(c2_wb_x);
  c2_f_a = c2_ub_x;
  c2_o_b = c2_wb_x;
  c2_p_y = c2_f_a * c2_o_b;
  c2_g_a = c2_p_y;
  c2_q_y = c2_g_a * 2.3862;
  c2_xb_x = c2_q2;
  c2_yb_x = c2_xb_x;
  c2_yb_x = muDoubleScalarCos(c2_yb_x);
  c2_ac_x = c2_q3;
  c2_bc_x = c2_ac_x;
  c2_bc_x = muDoubleScalarSin(c2_bc_x);
  c2_h_a = c2_yb_x;
  c2_p_b = c2_bc_x;
  c2_r_y = c2_h_a * c2_p_b;
  c2_cc_x = c2_q4;
  c2_dc_x = c2_cc_x;
  c2_dc_x = muDoubleScalarSin(c2_dc_x);
  c2_i_a = c2_r_y;
  c2_q_b = c2_dc_x;
  c2_s_y = c2_i_a * c2_q_b;
  c2_j_a = c2_s_y;
  c2_t_y = c2_j_a * 2.3862;
  c2_ec_x = c2_q2;
  c2_fc_x = c2_ec_x;
  c2_fc_x = muDoubleScalarCos(c2_fc_x);
  c2_gc_x = c2_q3;
  c2_hc_x = c2_gc_x;
  c2_hc_x = muDoubleScalarCos(c2_hc_x);
  c2_k_a = c2_fc_x;
  c2_r_b = c2_hc_x;
  c2_u_y = c2_k_a * c2_r_b;
  c2_ic_x = c2_q4;
  c2_jc_x = c2_ic_x;
  c2_jc_x = muDoubleScalarCos(c2_jc_x);
  c2_l_a = c2_u_y;
  c2_s_b = c2_jc_x;
  c2_v_y = c2_l_a * c2_s_b;
  c2_m_a = c2_v_y;
  c2_w_y = c2_m_a * 2.3862;
  c2_H[0] = c2_b_y;
  c2_H[4] = c2_c_y;
  c2_H[8] = c2_j_x;
  c2_H[12] = c2_h_y;
  c2_H[1] = -c2_v_x;
  c2_H[5] = -c2_x_x;
  c2_H[9] = 0.0;
  c2_H[13] = (((-c2_d2 - c2_i_y) - c2_j_y) - c2_k_y) - c2_l_y;
  c2_H[2] = c2_m_y;
  c2_H[6] = c2_n_y;
  c2_H[10] = c2_qb_x;
  c2_H[14] = (((c2_q1 + c2_o_y) + c2_q_y) - c2_t_y) + c2_w_y;
  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_H[c2_i12 + 3] = c2_dv2[c2_i13];
    c2_i12 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_b_H[0] = c2_H[12];
  c2_b_H[1] = c2_H[13];
  c2_b_H[2] = c2_H[14];
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    c2_Pxyz[c2_i14] = c2_b_H[c2_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_kc_x = c2_q3 + c2_q4;
  c2_lc_x = c2_kc_x;
  c2_lc_x = muDoubleScalarCos(c2_lc_x);
  c2_mc_x = c2_q2;
  c2_nc_x = c2_mc_x;
  c2_nc_x = muDoubleScalarSin(c2_nc_x);
  c2_n_a = -c2_lc_x;
  c2_t_b = c2_nc_x;
  c2_x_y = c2_n_a * c2_t_b;
  c2_oc_x = c2_q3 + c2_q4;
  c2_pc_x = c2_oc_x;
  c2_pc_x = muDoubleScalarSin(c2_pc_x);
  c2_qc_x = c2_q2;
  c2_rc_x = c2_qc_x;
  c2_rc_x = muDoubleScalarSin(c2_rc_x);
  c2_o_a = c2_pc_x;
  c2_u_b = c2_rc_x;
  c2_y_y = c2_o_a * c2_u_b;
  c2_sc_x = c2_q2;
  c2_tc_x = c2_sc_x;
  c2_tc_x = muDoubleScalarCos(c2_tc_x);
  c2_uc_x = c2_q3 + c2_q4;
  c2_vc_x = c2_uc_x;
  c2_vc_x = muDoubleScalarSin(c2_vc_x);
  c2_wc_x = c2_q3 + c2_q4;
  c2_xc_x = c2_wc_x;
  c2_xc_x = muDoubleScalarCos(c2_xc_x);
  c2_yc_x = c2_q3 + c2_q4;
  c2_ad_x = c2_yc_x;
  c2_ad_x = muDoubleScalarCos(c2_ad_x);
  c2_bd_x = c2_q2;
  c2_cd_x = c2_bd_x;
  c2_cd_x = muDoubleScalarCos(c2_cd_x);
  c2_p_a = c2_ad_x;
  c2_v_b = c2_cd_x;
  c2_ab_y = c2_p_a * c2_v_b;
  c2_dd_x = c2_q3 + c2_q4;
  c2_ed_x = c2_dd_x;
  c2_ed_x = muDoubleScalarSin(c2_ed_x);
  c2_fd_x = c2_q2;
  c2_gd_x = c2_fd_x;
  c2_gd_x = muDoubleScalarCos(c2_gd_x);
  c2_q_a = -c2_ed_x;
  c2_w_b = c2_gd_x;
  c2_bb_y = c2_q_a * c2_w_b;
  c2_hd_x = c2_q2;
  c2_id_x = c2_hd_x;
  c2_id_x = muDoubleScalarSin(c2_id_x);
  c2_R[0] = c2_x_y;
  c2_R[3] = c2_y_y;
  c2_R[6] = c2_tc_x;
  c2_R[1] = -c2_vc_x;
  c2_R[4] = -c2_xc_x;
  c2_R[7] = 0.0;
  c2_R[2] = c2_ab_y;
  c2_R[5] = c2_bb_y;
  c2_R[8] = c2_id_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  c2_r21 = c2_R[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
  c2_r11 = c2_R[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  c2_r31 = c2_R[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
  c2_r32 = c2_R[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
  c2_r33 = c2_R[8];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  c2_al = c2_atan2(chartInstance, c2_r21, c2_r11);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
  c2_d0 = c2_mpower(chartInstance, c2_r32) + c2_mpower(chartInstance, c2_r33);
  c2_b_sqrt(chartInstance, &c2_d0);
  c2_ga = c2_atan2(chartInstance, -c2_r31, c2_d0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
  c2_th = c2_atan2(chartInstance, c2_r32, c2_r33);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
  c2_Theta = c2_th;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
  c2_jd_x = c2_q2;
  c2_kd_x = c2_jd_x;
  c2_kd_x = muDoubleScalarCos(c2_kd_x);
  c2_ld_x = c2_q3 + c2_q4;
  c2_md_x = c2_ld_x;
  c2_md_x = muDoubleScalarCos(c2_md_x);
  c2_x_b = c2_md_x;
  c2_cb_y = 0.8862 * c2_x_b;
  c2_nd_x = c2_q3 + c2_q4;
  c2_od_x = c2_nd_x;
  c2_od_x = muDoubleScalarCos(c2_od_x);
  c2_y_b = c2_od_x;
  c2_db_y = 1.5 * c2_y_b;
  c2_pd_x = c2_q3;
  c2_qd_x = c2_pd_x;
  c2_qd_x = muDoubleScalarCos(c2_qd_x);
  c2_ab_b = c2_qd_x;
  c2_eb_y = 0.8862 * c2_ab_b;
  c2_rd_x = c2_q3;
  c2_sd_x = c2_rd_x;
  c2_sd_x = muDoubleScalarCos(c2_sd_x);
  c2_bb_b = c2_sd_x;
  c2_fb_y = 1.5 * c2_bb_b;
  c2_r_a = -c2_kd_x;
  c2_cb_b = (((c2_a2 + c2_cb_y) + c2_db_y) + c2_eb_y) + c2_fb_y;
  c2_gb_y = c2_r_a * c2_cb_b;
  c2_td_x = c2_q2;
  c2_ud_x = c2_td_x;
  c2_ud_x = muDoubleScalarSin(c2_ud_x);
  c2_vd_x = c2_q3 + c2_q4;
  c2_wd_x = c2_vd_x;
  c2_wd_x = muDoubleScalarSin(c2_wd_x);
  c2_db_b = c2_wd_x;
  c2_hb_y = 0.8862 * c2_db_b;
  c2_xd_x = c2_q3 + c2_q4;
  c2_yd_x = c2_xd_x;
  c2_yd_x = muDoubleScalarSin(c2_yd_x);
  c2_eb_b = c2_yd_x;
  c2_ib_y = 1.5 * c2_eb_b;
  c2_ae_x = c2_q3;
  c2_be_x = c2_ae_x;
  c2_be_x = muDoubleScalarSin(c2_be_x);
  c2_fb_b = c2_be_x;
  c2_jb_y = 0.8862 * c2_fb_b;
  c2_ce_x = c2_q3;
  c2_de_x = c2_ce_x;
  c2_de_x = muDoubleScalarSin(c2_de_x);
  c2_gb_b = c2_de_x;
  c2_kb_y = 1.5 * c2_gb_b;
  c2_s_a = c2_ud_x;
  c2_hb_b = ((c2_hb_y + c2_ib_y) + c2_jb_y) + c2_kb_y;
  c2_lb_y = c2_s_a * c2_hb_b;
  c2_ee_x = c2_q3 + c2_q4;
  c2_fe_x = c2_ee_x;
  c2_fe_x = muDoubleScalarSin(c2_fe_x);
  c2_ge_x = c2_q2;
  c2_he_x = c2_ge_x;
  c2_he_x = muDoubleScalarSin(c2_he_x);
  c2_t_a = c2_fe_x;
  c2_ib_b = c2_he_x;
  c2_mb_y = c2_t_a * c2_ib_b;
  c2_u_a = c2_mb_y;
  c2_nb_y = c2_u_a * 2.3862;
  c2_ie_x = c2_q3 + c2_q4;
  c2_je_x = c2_ie_x;
  c2_je_x = muDoubleScalarCos(c2_je_x);
  c2_jb_b = c2_je_x;
  c2_ob_y = -0.8862 * c2_jb_b;
  c2_ke_x = c2_q3 + c2_q4;
  c2_le_x = c2_ke_x;
  c2_le_x = muDoubleScalarCos(c2_le_x);
  c2_kb_b = c2_le_x;
  c2_pb_y = 1.5 * c2_kb_b;
  c2_me_x = c2_q3;
  c2_ne_x = c2_me_x;
  c2_ne_x = muDoubleScalarCos(c2_ne_x);
  c2_lb_b = c2_ne_x;
  c2_qb_y = 0.8862 * c2_lb_b;
  c2_oe_x = c2_q3;
  c2_pe_x = c2_oe_x;
  c2_pe_x = muDoubleScalarCos(c2_pe_x);
  c2_mb_b = c2_pe_x;
  c2_rb_y = 1.5 * c2_mb_b;
  c2_qe_x = c2_q3 + c2_q4;
  c2_re_x = c2_qe_x;
  c2_re_x = muDoubleScalarCos(c2_re_x);
  c2_v_a = -c2_re_x;
  c2_sb_y = c2_v_a * 2.3862;
  c2_se_x = c2_q2;
  c2_te_x = c2_se_x;
  c2_te_x = muDoubleScalarSin(c2_te_x);
  c2_ue_x = c2_q3 + c2_q4;
  c2_ve_x = c2_ue_x;
  c2_ve_x = muDoubleScalarCos(c2_ve_x);
  c2_nb_b = c2_ve_x;
  c2_tb_y = 0.8862 * c2_nb_b;
  c2_we_x = c2_q3 + c2_q4;
  c2_xe_x = c2_we_x;
  c2_xe_x = muDoubleScalarCos(c2_xe_x);
  c2_ob_b = c2_xe_x;
  c2_ub_y = 1.5 * c2_ob_b;
  c2_ye_x = c2_q3;
  c2_af_x = c2_ye_x;
  c2_af_x = muDoubleScalarCos(c2_af_x);
  c2_pb_b = c2_af_x;
  c2_vb_y = 0.8862 * c2_pb_b;
  c2_bf_x = c2_q3;
  c2_cf_x = c2_bf_x;
  c2_cf_x = muDoubleScalarCos(c2_cf_x);
  c2_qb_b = c2_cf_x;
  c2_wb_y = 1.5 * c2_qb_b;
  c2_w_a = -c2_te_x;
  c2_rb_b = (((c2_a2 + c2_tb_y) + c2_ub_y) + c2_vb_y) + c2_wb_y;
  c2_xb_y = c2_w_a * c2_rb_b;
  c2_df_x = c2_q2;
  c2_ef_x = c2_df_x;
  c2_ef_x = muDoubleScalarCos(c2_ef_x);
  c2_ff_x = c2_q3 + c2_q4;
  c2_gf_x = c2_ff_x;
  c2_gf_x = muDoubleScalarSin(c2_gf_x);
  c2_sb_b = c2_gf_x;
  c2_yb_y = 0.8862 * c2_sb_b;
  c2_hf_x = c2_q3 + c2_q4;
  c2_if_x = c2_hf_x;
  c2_if_x = muDoubleScalarSin(c2_if_x);
  c2_tb_b = c2_if_x;
  c2_ac_y = 1.5 * c2_tb_b;
  c2_jf_x = c2_q3;
  c2_kf_x = c2_jf_x;
  c2_kf_x = muDoubleScalarSin(c2_kf_x);
  c2_ub_b = c2_kf_x;
  c2_bc_y = 0.8862 * c2_ub_b;
  c2_lf_x = c2_q3;
  c2_mf_x = c2_lf_x;
  c2_mf_x = muDoubleScalarSin(c2_mf_x);
  c2_vb_b = c2_mf_x;
  c2_cc_y = 1.5 * c2_vb_b;
  c2_x_a = -c2_ef_x;
  c2_wb_b = ((c2_yb_y + c2_ac_y) + c2_bc_y) + c2_cc_y;
  c2_dc_y = c2_x_a * c2_wb_b;
  c2_nf_x = c2_q3 + c2_q4;
  c2_of_x = c2_nf_x;
  c2_of_x = muDoubleScalarSin(c2_of_x);
  c2_pf_x = c2_q2;
  c2_qf_x = c2_pf_x;
  c2_qf_x = muDoubleScalarCos(c2_qf_x);
  c2_y_a = -c2_of_x;
  c2_xb_b = c2_qf_x;
  c2_ec_y = c2_y_a * c2_xb_b;
  c2_ab_a = c2_ec_y;
  c2_fc_y = c2_ab_a * 2.3862;
  c2_rf_x = c2_q2;
  c2_sf_x = c2_rf_x;
  c2_sf_x = muDoubleScalarCos(c2_sf_x);
  c2_tf_x = c2_q2;
  c2_uf_x = c2_tf_x;
  c2_uf_x = muDoubleScalarCos(c2_uf_x);
  c2_vf_x = c2_q2;
  c2_wf_x = c2_vf_x;
  c2_wf_x = muDoubleScalarSin(c2_wf_x);
  c2_xf_x = c2_q2;
  c2_yf_x = c2_xf_x;
  c2_yf_x = muDoubleScalarSin(c2_yf_x);
  c2_Jg[0] = 0.0;
  c2_Jg[6] = c2_gb_y;
  c2_Jg[12] = c2_lb_y;
  c2_Jg[18] = c2_nb_y;
  c2_Jg[1] = 0.0;
  c2_Jg[7] = 0.0;
  c2_Jg[13] = ((c2_ob_y - c2_pb_y) - c2_qb_y) - c2_rb_y;
  c2_Jg[19] = c2_sb_y;
  c2_Jg[2] = 1.0;
  c2_Jg[8] = c2_xb_y;
  c2_Jg[14] = c2_dc_y;
  c2_Jg[20] = c2_fc_y;
  c2_Jg[3] = 0.0;
  c2_Jg[9] = 0.0;
  c2_Jg[15] = c2_sf_x;
  c2_Jg[21] = c2_uf_x;
  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    c2_Jg[c2_i15 + 4] = c2_dv3[c2_i16];
    c2_i15 += 6;
  }

  c2_Jg[5] = 0.0;
  c2_Jg[11] = 0.0;
  c2_Jg[17] = c2_wf_x;
  c2_Jg[23] = c2_yf_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
  c2_ag_x = c2_ga;
  c2_bg_x = c2_ag_x;
  c2_bg_x = muDoubleScalarCos(c2_bg_x);
  c2_cg_x = c2_th;
  c2_dg_x = c2_cg_x;
  c2_dg_x = muDoubleScalarCos(c2_dg_x);
  c2_bb_a = c2_bg_x;
  c2_yb_b = c2_dg_x;
  c2_gc_y = c2_bb_a * c2_yb_b;
  c2_eg_x = c2_th;
  c2_fg_x = c2_eg_x;
  c2_fg_x = muDoubleScalarSin(c2_fg_x);
  c2_gg_x = c2_ga;
  c2_hg_x = c2_gg_x;
  c2_hg_x = muDoubleScalarCos(c2_hg_x);
  c2_ig_x = c2_th;
  c2_jg_x = c2_ig_x;
  c2_jg_x = muDoubleScalarSin(c2_jg_x);
  c2_cb_a = c2_hg_x;
  c2_ac_b = c2_jg_x;
  c2_hc_y = c2_cb_a * c2_ac_b;
  c2_kg_x = c2_th;
  c2_lg_x = c2_kg_x;
  c2_lg_x = muDoubleScalarCos(c2_lg_x);
  c2_mg_x = c2_ga;
  c2_ng_x = c2_mg_x;
  c2_ng_x = muDoubleScalarSin(c2_ng_x);
  c2_Tphi[0] = c2_gc_y;
  c2_Tphi[3] = -c2_fg_x;
  c2_Tphi[6] = 0.0;
  c2_Tphi[1] = c2_hc_y;
  c2_Tphi[4] = c2_lg_x;
  c2_Tphi[7] = 0.0;
  c2_Tphi[2] = -c2_ng_x;
  c2_Tphi[5] = 0.0;
  c2_Tphi[8] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
  for (c2_i17 = 0; c2_i17 < 9; c2_i17++) {
    c2_b_Tphi[c2_i17] = c2_Tphi[c2_i17];
  }

  c2_inv(chartInstance, c2_b_Tphi, c2_dv4);
  for (c2_i18 = 0; c2_i18 < 9; c2_i18++) {
    c2_iTphi[c2_i18] = c2_dv4[c2_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 89);
  c2_eye(chartInstance, c2_dv5);
  c2_i19 = 0;
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
      c2_Ta_phi[c2_i22 + c2_i19] = c2_dv5[c2_i22 + c2_i20];
    }

    c2_i19 += 6;
    c2_i20 += 3;
  }

  c2_i23 = 0;
  for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
    for (c2_i25 = 0; c2_i25 < 3; c2_i25++) {
      c2_Ta_phi[(c2_i25 + c2_i23) + 18] = 0.0;
    }

    c2_i23 += 6;
  }

  c2_i26 = 0;
  for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
    for (c2_i28 = 0; c2_i28 < 3; c2_i28++) {
      c2_Ta_phi[(c2_i28 + c2_i26) + 3] = 0.0;
    }

    c2_i26 += 6;
  }

  c2_i29 = 0;
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 3; c2_i31++) {
    for (c2_i32 = 0; c2_i32 < 3; c2_i32++) {
      c2_Ta_phi[(c2_i32 + c2_i29) + 21] = c2_iTphi[c2_i32 + c2_i30];
    }

    c2_i29 += 6;
    c2_i30 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 96);
  for (c2_i33 = 0; c2_i33 < 36; c2_i33++) {
    c2_db_a[c2_i33] = c2_Ta_phi[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 24; c2_i34++) {
    c2_bc_b[c2_i34] = c2_Jg[c2_i34];
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  for (c2_i35 = 0; c2_i35 < 24; c2_i35++) {
    c2_Ja[c2_i35] = 0.0;
  }

  for (c2_i36 = 0; c2_i36 < 24; c2_i36++) {
    c2_Ja[c2_i36] = 0.0;
  }

  for (c2_i37 = 0; c2_i37 < 24; c2_i37++) {
    c2_C[c2_i37] = c2_Ja[c2_i37];
  }

  for (c2_i38 = 0; c2_i38 < 24; c2_i38++) {
    c2_Ja[c2_i38] = c2_C[c2_i38];
  }

  for (c2_i39 = 0; c2_i39 < 24; c2_i39++) {
    c2_C[c2_i39] = c2_Ja[c2_i39];
  }

  for (c2_i40 = 0; c2_i40 < 24; c2_i40++) {
    c2_Ja[c2_i40] = c2_C[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 6; c2_i41++) {
    c2_i42 = 0;
    for (c2_i43 = 0; c2_i43 < 4; c2_i43++) {
      c2_Ja[c2_i42 + c2_i41] = 0.0;
      c2_i44 = 0;
      for (c2_i45 = 0; c2_i45 < 6; c2_i45++) {
        c2_Ja[c2_i42 + c2_i41] += c2_db_a[c2_i44 + c2_i41] * c2_bc_b[c2_i45 +
          c2_i42];
        c2_i44 += 6;
      }

      c2_i42 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 98);
  for (c2_i46 = 0; c2_i46 < 3; c2_i46++) {
    c2_Ja_b[c2_i46] = c2_Ja[c2_i46];
  }

  for (c2_i47 = 0; c2_i47 < 3; c2_i47++) {
    c2_Ja_b[c2_i47 + 4] = c2_Ja[c2_i47 + 6];
  }

  for (c2_i48 = 0; c2_i48 < 3; c2_i48++) {
    c2_Ja_b[c2_i48 + 8] = c2_Ja[c2_i48 + 12];
  }

  for (c2_i49 = 0; c2_i49 < 3; c2_i49++) {
    c2_Ja_b[c2_i49 + 12] = c2_Ja[c2_i49 + 18];
  }

  c2_Ja_b[3] = c2_Ja[5];
  c2_Ja_b[7] = c2_Ja[11];
  c2_Ja_b[11] = c2_Ja[17];
  c2_Ja_b[15] = c2_Ja[23];
  sf_mex_printf("%s =\\n", "Ja_b");
  for (c2_i50 = 0; c2_i50 < 16; c2_i50++) {
    c2_b_u[c2_i50] = c2_Ja_b[c2_i50];
  }

  c2_ic_y = NULL;
  sf_mex_assign(&c2_ic_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_ic_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 111);
  for (c2_i51 = 0; c2_i51 < 16; c2_i51++) {
    c2_b_Ja_b[c2_i51] = c2_Ja_b[c2_i51];
  }

  c2_b_inv(chartInstance, c2_b_Ja_b, c2_dv6);
  for (c2_i52 = 0; c2_i52 < 16; c2_i52++) {
    c2_J_ainv[c2_i52] = c2_dv6[c2_i52];
  }

  sf_mex_printf("%s =\\n", "J_ainv");
  for (c2_i53 = 0; c2_i53 < 16; c2_i53++) {
    c2_c_u[c2_i53] = c2_J_ainv[c2_i53];
  }

  c2_jc_y = NULL;
  sf_mex_assign(&c2_jc_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_jc_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 118);
  for (c2_i54 = 0; c2_i54 < 3; c2_i54++) {
    c2_X_b[c2_i54] = c2_Pxyz[c2_i54];
  }

  c2_X_b[3] = c2_Theta;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 121);
  for (c2_i55 = 0; c2_i55 < 16; c2_i55++) {
    c2_A[c2_i55] = c2_J_ainv[c2_i55];
  }

  for (c2_i56 = 0; c2_i56 < 4; c2_i56++) {
    c2_B[c2_i56] = c2_Ke[c2_i56];
  }

  c2_b_eml_matlab_zgetrf(chartInstance, c2_A, c2_ipiv, &c2_info);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if ((real_T)c2_d_info > 0.0) {
    c2_eml_warning(chartInstance);
  }

  for (c2_i57 = 0; c2_i57 < 4; c2_i57++) {
    c2_qp[c2_i57] = c2_B[c2_i57];
  }

  for (c2_i = 1; c2_i < 5; c2_i++) {
    c2_b_i = c2_i;
    if (c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 4, 1, 0) - 1] != c2_b_i) {
      c2_ip = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) - 1];
      c2_temp = c2_qp[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) - 1];
      c2_qp[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_i), 1, 4, 1, 0) - 1] = c2_qp[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ip), 1, 4, 1, 0) - 1];
      c2_qp[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_ip), 1, 4, 1, 0) - 1] = c2_temp;
    }
  }

  for (c2_i58 = 0; c2_i58 < 4; c2_i58++) {
    c2_B[c2_i58] = c2_qp[c2_i58];
  }

  for (c2_i59 = 0; c2_i59 < 4; c2_i59++) {
    c2_qp[c2_i59] = c2_B[c2_i59];
  }

  for (c2_i60 = 0; c2_i60 < 16; c2_i60++) {
    c2_b_A[c2_i60] = c2_A[c2_i60];
  }

  c2_e_eml_blas_xtrsm(chartInstance, 4, 1, 1.0, c2_b_A, 1, 4, c2_qp, 1, 4);
  for (c2_i61 = 0; c2_i61 < 4; c2_i61++) {
    c2_B[c2_i61] = c2_qp[c2_i61];
  }

  for (c2_i62 = 0; c2_i62 < 4; c2_i62++) {
    c2_qp[c2_i62] = c2_B[c2_i62];
  }

  for (c2_i63 = 0; c2_i63 < 16; c2_i63++) {
    c2_c_A[c2_i63] = c2_A[c2_i63];
  }

  c2_f_eml_blas_xtrsm(chartInstance, 4, 1, 1.0, c2_c_A, 1, 4, c2_qp, 1, 4);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -121);
  sf_debug_symbol_scope_pop();
  for (c2_i64 = 0; c2_i64 < 4; c2_i64++) {
    (*c2_b_qp)[c2_i64] = c2_qp[c2_i64];
  }

  for (c2_i65 = 0; c2_i65 < 4; c2_i65++) {
    (*c2_b_X_b)[c2_i65] = c2_X_b[c2_i65];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Cinematica_JA_reducido
  (SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i66;
  real_T c2_b_inData[4];
  int32_T c2_i67;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i66 = 0; c2_i66 < 4; c2_i66++) {
    c2_b_inData[c2_i66] = (*(real_T (*)[4])c2_inData)[c2_i66];
  }

  for (c2_i67 = 0; c2_i67 < 4; c2_i67++) {
    c2_u[c2_i67] = c2_b_inData[c2_i67];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_X_b, const char_T *c2_identifier, real_T
  c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_X_b), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_X_b);
}

static void c2_b_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4])
{
  real_T c2_dv7[4];
  int32_T c2_i68;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv7, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i68 = 0; c2_i68 < 4; c2_i68++) {
    c2_y[c2_i68] = c2_dv7[c2_i68];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_X_b;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i69;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_X_b = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_X_b), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_X_b);
  for (c2_i69 = 0; c2_i69 < 4; c2_i69++) {
    (*(real_T (*)[4])c2_outData)[c2_i69] = c2_y[c2_i69];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  real_T c2_b_inData[16];
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i70 = 0;
  for (c2_i71 = 0; c2_i71 < 4; c2_i71++) {
    for (c2_i72 = 0; c2_i72 < 4; c2_i72++) {
      c2_b_inData[c2_i72 + c2_i70] = (*(real_T (*)[16])c2_inData)[c2_i72 +
        c2_i70];
    }

    c2_i70 += 4;
  }

  c2_i73 = 0;
  for (c2_i74 = 0; c2_i74 < 4; c2_i74++) {
    for (c2_i75 = 0; c2_i75 < 4; c2_i75++) {
      c2_u[c2_i75 + c2_i73] = c2_b_inData[c2_i75 + c2_i73];
    }

    c2_i73 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_dv8[16];
  int32_T c2_i76;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv8, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i76 = 0; c2_i76 < 16; c2_i76++) {
    c2_y[c2_i76] = c2_dv8[c2_i76];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_J_ainv;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_J_ainv = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_J_ainv), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_J_ainv);
  c2_i77 = 0;
  for (c2_i78 = 0; c2_i78 < 4; c2_i78++) {
    for (c2_i79 = 0; c2_i79 < 4; c2_i79++) {
      (*(real_T (*)[16])c2_outData)[c2_i79 + c2_i77] = c2_y[c2_i79 + c2_i77];
    }

    c2_i77 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  real_T c2_b_inData[24];
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  real_T c2_u[24];
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i80 = 0;
  for (c2_i81 = 0; c2_i81 < 4; c2_i81++) {
    for (c2_i82 = 0; c2_i82 < 6; c2_i82++) {
      c2_b_inData[c2_i82 + c2_i80] = (*(real_T (*)[24])c2_inData)[c2_i82 +
        c2_i80];
    }

    c2_i80 += 6;
  }

  c2_i83 = 0;
  for (c2_i84 = 0; c2_i84 < 4; c2_i84++) {
    for (c2_i85 = 0; c2_i85 < 6; c2_i85++) {
      c2_u[c2_i85 + c2_i83] = c2_b_inData[c2_i85 + c2_i83];
    }

    c2_i83 += 6;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24])
{
  real_T c2_dv9[24];
  int32_T c2_i86;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv9, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c2_i86 = 0; c2_i86 < 24; c2_i86++) {
    c2_y[c2_i86] = c2_dv9[c2_i86];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Ja;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[24];
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_Ja = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Ja), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Ja);
  c2_i87 = 0;
  for (c2_i88 = 0; c2_i88 < 4; c2_i88++) {
    for (c2_i89 = 0; c2_i89 < 6; c2_i89++) {
      (*(real_T (*)[24])c2_outData)[c2_i89 + c2_i87] = c2_y[c2_i89 + c2_i87];
    }

    c2_i87 += 6;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  real_T c2_b_inData[36];
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  real_T c2_u[36];
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i90 = 0;
  for (c2_i91 = 0; c2_i91 < 6; c2_i91++) {
    for (c2_i92 = 0; c2_i92 < 6; c2_i92++) {
      c2_b_inData[c2_i92 + c2_i90] = (*(real_T (*)[36])c2_inData)[c2_i92 +
        c2_i90];
    }

    c2_i90 += 6;
  }

  c2_i93 = 0;
  for (c2_i94 = 0; c2_i94 < 6; c2_i94++) {
    for (c2_i95 = 0; c2_i95 < 6; c2_i95++) {
      c2_u[c2_i95 + c2_i93] = c2_b_inData[c2_i95 + c2_i93];
    }

    c2_i93 += 6;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[36])
{
  real_T c2_dv10[36];
  int32_T c2_i96;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv10, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c2_i96 = 0; c2_i96 < 36; c2_i96++) {
    c2_y[c2_i96] = c2_dv10[c2_i96];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Ta_phi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[36];
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_Ta_phi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Ta_phi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Ta_phi);
  c2_i97 = 0;
  for (c2_i98 = 0; c2_i98 < 6; c2_i98++) {
    for (c2_i99 = 0; c2_i99 < 6; c2_i99++) {
      (*(real_T (*)[36])c2_outData)[c2_i99 + c2_i97] = c2_y[c2_i99 + c2_i97];
    }

    c2_i97 += 6;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  real_T c2_b_inData[9];
  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i105;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i100 = 0;
  for (c2_i101 = 0; c2_i101 < 3; c2_i101++) {
    for (c2_i102 = 0; c2_i102 < 3; c2_i102++) {
      c2_b_inData[c2_i102 + c2_i100] = (*(real_T (*)[9])c2_inData)[c2_i102 +
        c2_i100];
    }

    c2_i100 += 3;
  }

  c2_i103 = 0;
  for (c2_i104 = 0; c2_i104 < 3; c2_i104++) {
    for (c2_i105 = 0; c2_i105 < 3; c2_i105++) {
      c2_u[c2_i105 + c2_i103] = c2_b_inData[c2_i105 + c2_i103];
    }

    c2_i103 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9])
{
  real_T c2_dv11[9];
  int32_T c2_i106;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i106 = 0; c2_i106 < 9; c2_i106++) {
    c2_y[c2_i106] = c2_dv11[c2_i106];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_iTphi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_iTphi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_iTphi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_iTphi);
  c2_i107 = 0;
  for (c2_i108 = 0; c2_i108 < 3; c2_i108++) {
    for (c2_i109 = 0; c2_i109 < 3; c2_i109++) {
      (*(real_T (*)[9])c2_outData)[c2_i109 + c2_i107] = c2_y[c2_i109 + c2_i107];
    }

    c2_i107 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i110;
  real_T c2_b_inData[3];
  int32_T c2_i111;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i110 = 0; c2_i110 < 3; c2_i110++) {
    c2_b_inData[c2_i110] = (*(real_T (*)[3])c2_inData)[c2_i110];
  }

  for (c2_i111 = 0; c2_i111 < 3; c2_i111++) {
    c2_u[c2_i111] = c2_b_inData[c2_i111];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv12[3];
  int32_T c2_i112;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv12, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i112 = 0; c2_i112 < 3; c2_i112++) {
    c2_y[c2_i112] = c2_dv12[c2_i112];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Pxyz;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i113;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_Pxyz = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Pxyz), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Pxyz);
  for (c2_i113 = 0; c2_i113 < 3; c2_i113++) {
    (*(real_T (*)[3])c2_outData)[c2_i113] = c2_y[c2_i113];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Cinematica_JA_reducido_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[62];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i114;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 62));
  for (c2_i114 = 0; c2_i114 < 62; c2_i114++) {
    c2_r0 = &c2_info[c2_i114];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i114);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i114);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[62])
{
  c2_info[0].context = "";
  c2_info[0].name = "cos";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[0].fileTimeLo = 3359288576U;
  c2_info[0].fileTimeHi = 30108069U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[1].name = "eml_scalar_cos";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[1].fileTimeLo = 3519288576U;
  c2_info[1].fileTimeHi = 30108069U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "sin";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[2].fileTimeLo = 3799288576U;
  c2_info[2].fileTimeHi = 30108069U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[3].name = "eml_scalar_sin";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[3].fileTimeLo = 3659288576U;
  c2_info[3].fileTimeHi = 30108069U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "mtimes";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].fileTimeLo = 2169964032U;
  c2_info[4].fileTimeHi = 30114358U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "atan2";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[5].fileTimeLo = 3339288576U;
  c2_info[5].fileTimeHi = 30108069U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[6].name = "eml_scalar_eg";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[6].fileTimeLo = 4259288576U;
  c2_info[6].fileTimeHi = 30108069U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[7].name = "eml_scalexp_alloc";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[7].fileTimeLo = 4259288576U;
  c2_info[7].fileTimeHi = 30108069U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[8].name = "eml_scalar_atan2";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c2_info[8].fileTimeLo = 3499288576U;
  c2_info[8].fileTimeHi = 30108069U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "mpower";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[9].fileTimeLo = 424321280U;
  c2_info[9].fileTimeHi = 30108070U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[10].name = "power";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[10].fileTimeLo = 444321280U;
  c2_info[10].fileTimeHi = 30108070U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[11].name = "eml_scalar_floor";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[11].fileTimeLo = 3559288576U;
  c2_info[11].fileTimeHi = 30108069U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[12].name = "eml_error";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[12].fileTimeLo = 3299288576U;
  c2_info[12].fileTimeHi = 30108069U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "sqrt";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[13].fileTimeLo = 3819288576U;
  c2_info[13].fileTimeHi = 30108069U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[14].name = "eml_scalar_sqrt";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[14].fileTimeLo = 3679288576U;
  c2_info[14].fileTimeHi = 30108069U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "";
  c2_info[15].name = "inv";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[15].fileTimeLo = 244321280U;
  c2_info[15].fileTimeHi = 30108070U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[16].name = "eml_index_class";
  c2_info[16].dominantType = "";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[16].fileTimeLo = 4079288576U;
  c2_info[16].fileTimeHi = 30108069U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[17].name = "abs";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[17].fileTimeLo = 3239288576U;
  c2_info[17].fileTimeHi = 30108069U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[18].name = "eml_scalar_abs";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[18].fileTimeLo = 3419288576U;
  c2_info[18].fileTimeHi = 30108069U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[19].name = "eml_div";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[19].fileTimeLo = 3279288576U;
  c2_info[19].fileTimeHi = 30108069U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[20].name = "eml_index_plus";
  c2_info[20].dominantType = "int32";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[20].fileTimeLo = 4079288576U;
  c2_info[20].fileTimeHi = 30108069U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[21].name = "norm";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[21].fileTimeLo = 264321280U;
  c2_info[21].fileTimeHi = 30108070U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c2_info[22].name = "isnan";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[22].fileTimeLo = 3899288576U;
  c2_info[22].fileTimeHi = 30108069U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c2_info[23].name = "eml_guarded_nan";
  c2_info[23].dominantType = "char";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[23].fileTimeLo = 4059288576U;
  c2_info[23].fileTimeHi = 30108069U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[24].name = "eml_is_float_class";
  c2_info[24].dominantType = "char";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[24].fileTimeLo = 4119288576U;
  c2_info[24].fileTimeHi = 30108069U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[25].name = "eml_warning";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[25].fileTimeLo = 24321280U;
  c2_info[25].fileTimeHi = 30108070U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[26].name = "eps";
  c2_info[26].dominantType = "char";
  c2_info[26].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[26].fileTimeLo = 3159288576U;
  c2_info[26].fileTimeHi = 30108069U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[27].name = "eml_flt2str";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c2_info[27].fileTimeLo = 4059288576U;
  c2_info[27].fileTimeHi = 30108069U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context = "";
  c2_info[28].name = "eye";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c2_info[28].fileTimeLo = 3179288576U;
  c2_info[28].fileTimeHi = 30108069U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[29].name = "eml_assert_valid_size_arg";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[29].fileTimeLo = 3239288576U;
  c2_info[29].fileTimeHi = 30108069U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c2_info[30].name = "isinf";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[30].fileTimeLo = 3899288576U;
  c2_info[30].fileTimeHi = 30108069U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[31].name = "intmax";
  c2_info[31].dominantType = "char";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[31].fileTimeLo = 3859288576U;
  c2_info[31].fileTimeHi = 30108069U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[32].name = "min";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[32].fileTimeLo = 3259288576U;
  c2_info[32].fileTimeHi = 30108069U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[33].name = "eml_min_or_max";
  c2_info[33].dominantType = "char";
  c2_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[33].fileTimeLo = 4179288576U;
  c2_info[33].fileTimeHi = 30108069U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[34].name = "eml_xgemm";
  c2_info[34].dominantType = "int32";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[34].fileTimeLo = 3399288576U;
  c2_info[34].fileTimeHi = 30108069U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c2_info[35].name = "length";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[35].fileTimeLo = 3899288576U;
  c2_info[35].fileTimeHi = 30108069U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[36].name = "eml_refblas_xgemm";
  c2_info[36].dominantType = "int32";
  c2_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[36].fileTimeLo = 4119288576U;
  c2_info[36].fileTimeHi = 30108069U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[37].name = "eml_index_minus";
  c2_info[37].dominantType = "int32";
  c2_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[37].fileTimeLo = 4079288576U;
  c2_info[37].fileTimeHi = 30108069U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[38].name = "eml_index_times";
  c2_info[38].dominantType = "int32";
  c2_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[38].fileTimeLo = 4099288576U;
  c2_info[38].fileTimeHi = 30108069U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c2_info[39].name = "eml_xgetrf";
  c2_info[39].dominantType = "int32";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c2_info[39].fileTimeLo = 64321280U;
  c2_info[39].fileTimeHi = 30108070U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c2_info[40].name = "eml_lapack_xgetrf";
  c2_info[40].dominantType = "int32";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c2_info[40].fileTimeLo = 104321280U;
  c2_info[40].fileTimeHi = 30108070U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c2_info[41].name = "eml_matlab_zgetrf";
  c2_info[41].dominantType = "int32";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[41].fileTimeLo = 164321280U;
  c2_info[41].fileTimeHi = 30108070U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[42].name = "realmin";
  c2_info[42].dominantType = "char";
  c2_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[42].fileTimeLo = 3979288576U;
  c2_info[42].fileTimeHi = 30108069U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[43].name = "colon";
  c2_info[43].dominantType = "int32";
  c2_info[43].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[43].fileTimeLo = 384321280U;
  c2_info[43].fileTimeHi = 30108070U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[44].name = "floor";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[44].fileTimeLo = 3719288576U;
  c2_info[44].fileTimeHi = 30108069U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[45].name = "intmin";
  c2_info[45].dominantType = "char";
  c2_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[45].fileTimeLo = 3859288576U;
  c2_info[45].fileTimeHi = 30108069U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c2_info[46].name = "mrdivide";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[46].fileTimeLo = 714027776U;
  c2_info[46].fileTimeHi = 30130994U;
  c2_info[46].mFileTimeLo = 2169964032U;
  c2_info[46].mFileTimeHi = 30114358U;
  c2_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[47].name = "rdivide";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[47].fileTimeLo = 444321280U;
  c2_info[47].fileTimeHi = 30108070U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[48].name = "eml_ixamax";
  c2_info[48].dominantType = "int32";
  c2_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[48].fileTimeLo = 3339288576U;
  c2_info[48].fileTimeHi = 30108069U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c2_info[49].name = "eml_refblas_ixamax";
  c2_info[49].dominantType = "int32";
  c2_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[49].fileTimeLo = 4079288576U;
  c2_info[49].fileTimeHi = 30108069U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[50].name = "eml_xcabs1";
  c2_info[50].dominantType = "double";
  c2_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[50].fileTimeLo = 3359288576U;
  c2_info[50].fileTimeHi = 30108069U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[51].name = "eml_xswap";
  c2_info[51].dominantType = "int32";
  c2_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[51].fileTimeLo = 44321280U;
  c2_info[51].fileTimeHi = 30108070U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c2_info[52].name = "eml_refblas_xswap";
  c2_info[52].dominantType = "int32";
  c2_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[52].fileTimeLo = 164321280U;
  c2_info[52].fileTimeHi = 30108070U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[53].name = "eml_xgeru";
  c2_info[53].dominantType = "int32";
  c2_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[53].fileTimeLo = 3419288576U;
  c2_info[53].fileTimeHi = 30108069U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[54].name = "eml_xger";
  c2_info[54].dominantType = "int32";
  c2_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[54].fileTimeLo = 3399288576U;
  c2_info[54].fileTimeHi = 30108069U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c2_info[55].name = "eml_refblas_xger";
  c2_info[55].dominantType = "int32";
  c2_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[55].fileTimeLo = 4119288576U;
  c2_info[55].fileTimeHi = 30108069U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[56].name = "eml_refblas_xgerx";
  c2_info[56].dominantType = "int32";
  c2_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[56].fileTimeLo = 4159288576U;
  c2_info[56].fileTimeHi = 30108069U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
  c2_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c2_info[57].name = "eml_ipiv2perm";
  c2_info[57].dominantType = "int32";
  c2_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c2_info[57].fileTimeLo = 4119288576U;
  c2_info[57].fileTimeHi = 30108069U;
  c2_info[57].mFileTimeLo = 0U;
  c2_info[57].mFileTimeHi = 0U;
  c2_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c2_info[58].name = "eml_xtrsm";
  c2_info[58].dominantType = "int32";
  c2_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c2_info[58].fileTimeLo = 44321280U;
  c2_info[58].fileTimeHi = 30108070U;
  c2_info[58].mFileTimeLo = 0U;
  c2_info[58].mFileTimeHi = 0U;
  c2_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c2_info[59].name = "eml_refblas_xtrsm";
  c2_info[59].dominantType = "int32";
  c2_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[59].fileTimeLo = 164321280U;
  c2_info[59].fileTimeHi = 30108070U;
  c2_info[59].mFileTimeLo = 0U;
  c2_info[59].mFileTimeHi = 0U;
  c2_info[60].context = "";
  c2_info[60].name = "mldivide";
  c2_info[60].dominantType = "double";
  c2_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[60].fileTimeLo = 714027776U;
  c2_info[60].fileTimeHi = 30130994U;
  c2_info[60].mFileTimeLo = 2149964032U;
  c2_info[60].mFileTimeHi = 30114358U;
  c2_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[61].name = "eml_lusolve";
  c2_info[61].dominantType = "double";
  c2_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[61].fileTimeLo = 4159288576U;
  c2_info[61].fileTimeHi = 30108069U;
  c2_info[61].mFileTimeLo = 0U;
  c2_info[61].mFileTimeHi = 0U;
}

static real_T c2_atan2(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_y, real_T c2_x)
{
  real_T c2_b_y;
  real_T c2_b_x;
  c2_eml_scalar_eg(chartInstance);
  c2_b_y = c2_y;
  c2_b_x = c2_x;
  return muDoubleScalarAtan2(c2_b_y, c2_b_x);
}

static void c2_eml_scalar_eg(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
}

static real_T c2_mpower(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_a)
{
  return c2_power(chartInstance, c2_a, 2.0);
}

static real_T c2_power(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_b)
{
  real_T c2_ak;
  real_T c2_bk;
  real_T c2_x;
  real_T c2_b_x;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_a;
  c2_bk = c2_b;
  if (c2_ak < 0.0) {
    c2_x = c2_bk;
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarFloor(c2_b_x);
    if (c2_b_x != c2_bk) {
      c2_eml_error(chartInstance);
    }
  }

  return muDoubleScalarPower(c2_ak, c2_bk);
}

static void c2_eml_error(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
  int32_T c2_i115;
  static char_T c2_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  for (c2_i115 = 0; c2_i115 < 31; c2_i115++) {
    c2_u[c2_i115] = c2_varargin_1[c2_i115];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static real_T c2_sqrt(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_b_eml_error(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
  int32_T c2_i116;
  static char_T c2_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i116 = 0; c2_i116 < 30; c2_i116++) {
    c2_u[c2_i116] = c2_varargin_1[c2_i116];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_inv(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                   real_T c2_x[9], real_T c2_y[9])
{
  int32_T c2_i117;
  real_T c2_b_x[9];
  int32_T c2_i118;
  real_T c2_c_x[9];
  real_T c2_n1x;
  int32_T c2_i119;
  real_T c2_b_y[9];
  real_T c2_n1xinv;
  real_T c2_a;
  real_T c2_b;
  real_T c2_c_y;
  real_T c2_rc;
  real_T c2_d_x;
  boolean_T c2_b_b;
  real_T c2_e_x;
  int32_T c2_i120;
  static char_T c2_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c2_u[8];
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_g_y = NULL;
  char_T c2_str[14];
  int32_T c2_i121;
  char_T c2_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  for (c2_i117 = 0; c2_i117 < 9; c2_i117++) {
    c2_b_x[c2_i117] = c2_x[c2_i117];
  }

  c2_inv3x3(chartInstance, c2_b_x, c2_y);
  for (c2_i118 = 0; c2_i118 < 9; c2_i118++) {
    c2_c_x[c2_i118] = c2_x[c2_i118];
  }

  c2_n1x = c2_norm(chartInstance, c2_c_x);
  for (c2_i119 = 0; c2_i119 < 9; c2_i119++) {
    c2_b_y[c2_i119] = c2_y[c2_i119];
  }

  c2_n1xinv = c2_norm(chartInstance, c2_b_y);
  c2_a = c2_n1x;
  c2_b = c2_n1xinv;
  c2_c_y = c2_a * c2_b;
  c2_rc = 1.0 / c2_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c2_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c2_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c2_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c2_d_x = c2_rc;
    c2_b_b = muDoubleScalarIsNaN(c2_d_x);
    guard3 = FALSE;
    if (c2_b_b) {
      guard3 = TRUE;
    } else {
      if (c2_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c2_e_x = c2_rc;
      for (c2_i120 = 0; c2_i120 < 8; c2_i120++) {
        c2_u[c2_i120] = c2_cv0[c2_i120];
      }

      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 8));
      c2_b_u = 14.0;
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
      c2_c_u = 6.0;
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
      c2_d_u = c2_e_x;
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
      c2_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c2_d_y, 14, c2_e_y, 14,
        c2_f_y), 14, c2_g_y), "sprintf", c2_str);
      for (c2_i121 = 0; c2_i121 < 14; c2_i121++) {
        c2_b_str[c2_i121] = c2_str[c2_i121];
      }

      c2_b_eml_warning(chartInstance, c2_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c2_eml_warning(chartInstance);
  }
}

static void c2_inv3x3(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x[9], real_T c2_y[9])
{
  int32_T c2_p1;
  int32_T c2_p2;
  int32_T c2_p3;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_absx11;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_absx21;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_absx31;
  real_T c2_t1;
  real_T c2_h_x;
  real_T c2_b_y;
  real_T c2_i_x;
  real_T c2_c_y;
  real_T c2_z;
  real_T c2_j_x;
  real_T c2_d_y;
  real_T c2_k_x;
  real_T c2_e_y;
  real_T c2_b_z;
  real_T c2_a;
  real_T c2_b;
  real_T c2_f_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_g_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_h_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_i_y;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_j_y;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_k_y;
  int32_T c2_itmp;
  real_T c2_p_x;
  real_T c2_l_y;
  real_T c2_q_x;
  real_T c2_m_y;
  real_T c2_c_z;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_n_y;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_o_y;
  real_T c2_r_x;
  real_T c2_p_y;
  real_T c2_s_x;
  real_T c2_q_y;
  real_T c2_t3;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_r_y;
  real_T c2_t_x;
  real_T c2_s_y;
  real_T c2_u_x;
  real_T c2_t_y;
  real_T c2_t2;
  int32_T c2_h_a;
  int32_T c2_c;
  real_T c2_i_a;
  real_T c2_h_b;
  real_T c2_u_y;
  real_T c2_j_a;
  real_T c2_i_b;
  real_T c2_v_y;
  real_T c2_v_x;
  real_T c2_w_y;
  real_T c2_w_x;
  real_T c2_x_y;
  real_T c2_d_z;
  int32_T c2_k_a;
  int32_T c2_b_c;
  int32_T c2_l_a;
  int32_T c2_c_c;
  real_T c2_x_x;
  real_T c2_y_y;
  real_T c2_y_x;
  real_T c2_ab_y;
  real_T c2_m_a;
  real_T c2_j_b;
  real_T c2_bb_y;
  real_T c2_ab_x;
  real_T c2_cb_y;
  real_T c2_bb_x;
  real_T c2_db_y;
  int32_T c2_n_a;
  int32_T c2_d_c;
  real_T c2_o_a;
  real_T c2_k_b;
  real_T c2_eb_y;
  real_T c2_p_a;
  real_T c2_l_b;
  real_T c2_fb_y;
  real_T c2_cb_x;
  real_T c2_gb_y;
  real_T c2_db_x;
  real_T c2_hb_y;
  real_T c2_e_z;
  int32_T c2_q_a;
  int32_T c2_e_c;
  int32_T c2_r_a;
  int32_T c2_f_c;
  real_T c2_ib_y;
  real_T c2_jb_y;
  real_T c2_s_a;
  real_T c2_m_b;
  real_T c2_kb_y;
  real_T c2_eb_x;
  real_T c2_lb_y;
  real_T c2_fb_x;
  real_T c2_mb_y;
  int32_T c2_t_a;
  int32_T c2_g_c;
  real_T c2_u_a;
  real_T c2_n_b;
  real_T c2_nb_y;
  real_T c2_v_a;
  real_T c2_o_b;
  real_T c2_ob_y;
  real_T c2_gb_x;
  real_T c2_pb_y;
  real_T c2_hb_x;
  real_T c2_qb_y;
  real_T c2_f_z;
  int32_T c2_w_a;
  int32_T c2_h_c;
  int32_T c2_x_a;
  int32_T c2_i_c;
  boolean_T guard1 = FALSE;
  c2_p1 = 0;
  c2_p2 = 3;
  c2_p3 = 6;
  c2_b_x = c2_x[0];
  c2_c_x = c2_b_x;
  c2_absx11 = muDoubleScalarAbs(c2_c_x);
  c2_d_x = c2_x[1];
  c2_e_x = c2_d_x;
  c2_absx21 = muDoubleScalarAbs(c2_e_x);
  c2_f_x = c2_x[2];
  c2_g_x = c2_f_x;
  c2_absx31 = muDoubleScalarAbs(c2_g_x);
  guard1 = FALSE;
  if (c2_absx21 > c2_absx11) {
    if (c2_absx21 > c2_absx31) {
      c2_p1 = 3;
      c2_p2 = 0;
      c2_t1 = c2_x[0];
      c2_x[0] = c2_x[1];
      c2_x[1] = c2_t1;
      c2_t1 = c2_x[3];
      c2_x[3] = c2_x[4];
      c2_x[4] = c2_t1;
      c2_t1 = c2_x[6];
      c2_x[6] = c2_x[7];
      c2_x[7] = c2_t1;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    if (c2_absx31 > c2_absx11) {
      c2_p1 = 6;
      c2_p3 = 0;
      c2_t1 = c2_x[0];
      c2_x[0] = c2_x[2];
      c2_x[2] = c2_t1;
      c2_t1 = c2_x[3];
      c2_x[3] = c2_x[5];
      c2_x[5] = c2_t1;
      c2_t1 = c2_x[6];
      c2_x[6] = c2_x[8];
      c2_x[8] = c2_t1;
    }
  }

  c2_h_x = c2_x[1];
  c2_b_y = c2_x[0];
  c2_i_x = c2_h_x;
  c2_c_y = c2_b_y;
  c2_z = c2_i_x / c2_c_y;
  c2_x[1] = c2_z;
  c2_j_x = c2_x[2];
  c2_d_y = c2_x[0];
  c2_k_x = c2_j_x;
  c2_e_y = c2_d_y;
  c2_b_z = c2_k_x / c2_e_y;
  c2_x[2] = c2_b_z;
  c2_a = c2_x[1];
  c2_b = c2_x[3];
  c2_f_y = c2_a * c2_b;
  c2_x[4] -= c2_f_y;
  c2_b_a = c2_x[2];
  c2_b_b = c2_x[3];
  c2_g_y = c2_b_a * c2_b_b;
  c2_x[5] -= c2_g_y;
  c2_c_a = c2_x[1];
  c2_c_b = c2_x[6];
  c2_h_y = c2_c_a * c2_c_b;
  c2_x[7] -= c2_h_y;
  c2_d_a = c2_x[2];
  c2_d_b = c2_x[6];
  c2_i_y = c2_d_a * c2_d_b;
  c2_x[8] -= c2_i_y;
  c2_l_x = c2_x[5];
  c2_m_x = c2_l_x;
  c2_j_y = muDoubleScalarAbs(c2_m_x);
  c2_n_x = c2_x[4];
  c2_o_x = c2_n_x;
  c2_k_y = muDoubleScalarAbs(c2_o_x);
  if (c2_j_y > c2_k_y) {
    c2_itmp = c2_p2;
    c2_p2 = c2_p3;
    c2_p3 = c2_itmp;
    c2_t1 = c2_x[1];
    c2_x[1] = c2_x[2];
    c2_x[2] = c2_t1;
    c2_t1 = c2_x[4];
    c2_x[4] = c2_x[5];
    c2_x[5] = c2_t1;
    c2_t1 = c2_x[7];
    c2_x[7] = c2_x[8];
    c2_x[8] = c2_t1;
  }

  c2_p_x = c2_x[5];
  c2_l_y = c2_x[4];
  c2_q_x = c2_p_x;
  c2_m_y = c2_l_y;
  c2_c_z = c2_q_x / c2_m_y;
  c2_x[5] = c2_c_z;
  c2_e_a = c2_x[5];
  c2_e_b = c2_x[7];
  c2_n_y = c2_e_a * c2_e_b;
  c2_x[8] -= c2_n_y;
  c2_f_a = c2_x[5];
  c2_f_b = c2_x[1];
  c2_o_y = c2_f_a * c2_f_b;
  c2_r_x = c2_o_y - c2_x[2];
  c2_p_y = c2_x[8];
  c2_s_x = c2_r_x;
  c2_q_y = c2_p_y;
  c2_t3 = c2_s_x / c2_q_y;
  c2_g_a = c2_x[7];
  c2_g_b = c2_t3;
  c2_r_y = c2_g_a * c2_g_b;
  c2_t_x = -(c2_x[1] + c2_r_y);
  c2_s_y = c2_x[4];
  c2_u_x = c2_t_x;
  c2_t_y = c2_s_y;
  c2_t2 = c2_u_x / c2_t_y;
  c2_h_a = c2_p1;
  c2_c = c2_h_a;
  c2_i_a = c2_x[3];
  c2_h_b = c2_t2;
  c2_u_y = c2_i_a * c2_h_b;
  c2_j_a = c2_x[6];
  c2_i_b = c2_t3;
  c2_v_y = c2_j_a * c2_i_b;
  c2_v_x = (1.0 - c2_u_y) - c2_v_y;
  c2_w_y = c2_x[0];
  c2_w_x = c2_v_x;
  c2_x_y = c2_w_y;
  c2_d_z = c2_w_x / c2_x_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_c + 1)), 1, 9, 1, 0) - 1] = c2_d_z;
  c2_k_a = c2_p1;
  c2_b_c = c2_k_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_b_c + 2)), 1, 9, 1, 0) - 1] = c2_t2;
  c2_l_a = c2_p1;
  c2_c_c = c2_l_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_c_c + 3)), 1, 9, 1, 0) - 1] = c2_t3;
  c2_x_x = -c2_x[5];
  c2_y_y = c2_x[8];
  c2_y_x = c2_x_x;
  c2_ab_y = c2_y_y;
  c2_t3 = c2_y_x / c2_ab_y;
  c2_m_a = c2_x[7];
  c2_j_b = c2_t3;
  c2_bb_y = c2_m_a * c2_j_b;
  c2_ab_x = 1.0 - c2_bb_y;
  c2_cb_y = c2_x[4];
  c2_bb_x = c2_ab_x;
  c2_db_y = c2_cb_y;
  c2_t2 = c2_bb_x / c2_db_y;
  c2_n_a = c2_p2;
  c2_d_c = c2_n_a;
  c2_o_a = c2_x[3];
  c2_k_b = c2_t2;
  c2_eb_y = c2_o_a * c2_k_b;
  c2_p_a = c2_x[6];
  c2_l_b = c2_t3;
  c2_fb_y = c2_p_a * c2_l_b;
  c2_cb_x = -(c2_eb_y + c2_fb_y);
  c2_gb_y = c2_x[0];
  c2_db_x = c2_cb_x;
  c2_hb_y = c2_gb_y;
  c2_e_z = c2_db_x / c2_hb_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_d_c + 1)), 1, 9, 1, 0) - 1] = c2_e_z;
  c2_q_a = c2_p2;
  c2_e_c = c2_q_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_e_c + 2)), 1, 9, 1, 0) - 1] = c2_t2;
  c2_r_a = c2_p2;
  c2_f_c = c2_r_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_f_c + 3)), 1, 9, 1, 0) - 1] = c2_t3;
  c2_ib_y = c2_x[8];
  c2_jb_y = c2_ib_y;
  c2_t3 = 1.0 / c2_jb_y;
  c2_s_a = -c2_x[7];
  c2_m_b = c2_t3;
  c2_kb_y = c2_s_a * c2_m_b;
  c2_eb_x = c2_kb_y;
  c2_lb_y = c2_x[4];
  c2_fb_x = c2_eb_x;
  c2_mb_y = c2_lb_y;
  c2_t2 = c2_fb_x / c2_mb_y;
  c2_t_a = c2_p3;
  c2_g_c = c2_t_a;
  c2_u_a = c2_x[3];
  c2_n_b = c2_t2;
  c2_nb_y = c2_u_a * c2_n_b;
  c2_v_a = c2_x[6];
  c2_o_b = c2_t3;
  c2_ob_y = c2_v_a * c2_o_b;
  c2_gb_x = -(c2_nb_y + c2_ob_y);
  c2_pb_y = c2_x[0];
  c2_hb_x = c2_gb_x;
  c2_qb_y = c2_pb_y;
  c2_f_z = c2_hb_x / c2_qb_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_g_c + 1)), 1, 9, 1, 0) - 1] = c2_f_z;
  c2_w_a = c2_p3;
  c2_h_c = c2_w_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_h_c + 2)), 1, 9, 1, 0) - 1] = c2_t2;
  c2_x_a = c2_p3;
  c2_i_c = c2_x_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    (c2_i_c + 3)), 1, 9, 1, 0) - 1] = c2_t3;
}

static real_T c2_norm(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x[9])
{
  real_T c2_y;
  real_T c2_j;
  real_T c2_b_j;
  real_T c2_s;
  real_T c2_i;
  real_T c2_b_i;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  boolean_T c2_b;
  boolean_T exitg1;
  c2_y = 0.0;
  c2_j = 1.0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c2_j <= 3.0)) {
    c2_b_j = c2_j;
    c2_s = 0.0;
    for (c2_i = 1.0; c2_i <= 3.0; c2_i++) {
      c2_b_i = c2_i;
      c2_b_x = c2_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c2_b_i), 1, 3, 1, 0) + 3 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_j), 1, 3, 2, 0) - 1)) - 1];
      c2_c_x = c2_b_x;
      c2_b_y = muDoubleScalarAbs(c2_c_x);
      c2_s += c2_b_y;
    }

    c2_d_x = c2_s;
    c2_b = muDoubleScalarIsNaN(c2_d_x);
    if (c2_b) {
      c2_y = rtNaN;
      exitg1 = 1U;
    } else {
      if (c2_s > c2_y) {
        c2_y = c2_s;
      }

      c2_j++;
    }
  }

  return c2_y;
}

static void c2_eml_warning(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
  int32_T c2_i122;
  static char_T c2_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c2_u[27];
  const mxArray *c2_y = NULL;
  for (c2_i122 = 0; c2_i122 < 27; c2_i122++) {
    c2_u[c2_i122] = c2_varargin_1[c2_i122];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 27));
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c2_y));
}

static void c2_eps(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static void c2_b_eml_warning(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, char_T c2_varargin_2[14])
{
  int32_T c2_i123;
  static char_T c2_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c2_u[33];
  const mxArray *c2_y = NULL;
  int32_T c2_i124;
  char_T c2_b_u[14];
  const mxArray *c2_b_y = NULL;
  for (c2_i123 = 0; c2_i123 < 33; c2_i123++) {
    c2_u[c2_i123] = c2_varargin_1[c2_i123];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 33));
  for (c2_i124 = 0; c2_i124 < 14; c2_i124++) {
    c2_b_u[c2_i124] = c2_varargin_2[c2_i124];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 14));
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c2_y, 14, c2_b_y));
}

static void c2_eye(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                   real_T c2_I[9])
{
  int32_T c2_i125;
  int32_T c2_i;
  int32_T c2_b_i;
  for (c2_i125 = 0; c2_i125 < 9; c2_i125++) {
    c2_I[c2_i125] = 0.0;
  }

  for (c2_i = 1; c2_i < 4; c2_i++) {
    c2_b_i = c2_i;
    c2_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 3, 2, 0) - 1)) -
      1] = 1.0;
  }
}

static void c2_b_eml_scalar_eg(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
}

static void c2_b_inv(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                     real_T c2_x[16], real_T c2_y[16])
{
  int32_T c2_i126;
  real_T c2_b_x[16];
  int32_T c2_i127;
  real_T c2_c_x[16];
  real_T c2_n1x;
  int32_T c2_i128;
  real_T c2_b_y[16];
  real_T c2_n1xinv;
  real_T c2_a;
  real_T c2_b;
  real_T c2_c_y;
  real_T c2_rc;
  real_T c2_d_x;
  boolean_T c2_b_b;
  real_T c2_e_x;
  int32_T c2_i129;
  static char_T c2_cv1[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c2_u[8];
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_g_y = NULL;
  char_T c2_str[14];
  int32_T c2_i130;
  char_T c2_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  for (c2_i126 = 0; c2_i126 < 16; c2_i126++) {
    c2_b_x[c2_i126] = c2_x[c2_i126];
  }

  c2_invNxN(chartInstance, c2_b_x, c2_y);
  for (c2_i127 = 0; c2_i127 < 16; c2_i127++) {
    c2_c_x[c2_i127] = c2_x[c2_i127];
  }

  c2_n1x = c2_b_norm(chartInstance, c2_c_x);
  for (c2_i128 = 0; c2_i128 < 16; c2_i128++) {
    c2_b_y[c2_i128] = c2_y[c2_i128];
  }

  c2_n1xinv = c2_b_norm(chartInstance, c2_b_y);
  c2_a = c2_n1x;
  c2_b = c2_n1xinv;
  c2_c_y = c2_a * c2_b;
  c2_rc = 1.0 / c2_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c2_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c2_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c2_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c2_d_x = c2_rc;
    c2_b_b = muDoubleScalarIsNaN(c2_d_x);
    guard3 = FALSE;
    if (c2_b_b) {
      guard3 = TRUE;
    } else {
      if (c2_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c2_e_x = c2_rc;
      for (c2_i129 = 0; c2_i129 < 8; c2_i129++) {
        c2_u[c2_i129] = c2_cv1[c2_i129];
      }

      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 8));
      c2_b_u = 14.0;
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
      c2_c_u = 6.0;
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
      c2_d_u = c2_e_x;
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
      c2_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c2_d_y, 14, c2_e_y, 14,
        c2_f_y), 14, c2_g_y), "sprintf", c2_str);
      for (c2_i130 = 0; c2_i130 < 14; c2_i130++) {
        c2_b_str[c2_i130] = c2_str[c2_i130];
      }

      c2_b_eml_warning(chartInstance, c2_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c2_eml_warning(chartInstance);
  }
}

static void c2_invNxN(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T c2_x[16], real_T c2_y[16])
{
  int32_T c2_i131;
  int32_T c2_info;
  int32_T c2_ipiv[4];
  int32_T c2_i132;
  int32_T c2_p[4];
  real_T c2_k;
  real_T c2_b_k;
  int32_T c2_ipk;
  int32_T c2_pipk;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_c;
  int32_T c2_e_k;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_i133;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_b_a;
  real_T c2_b;
  real_T c2_b_y;
  int32_T c2_i134;
  real_T c2_b_x[16];
  for (c2_i131 = 0; c2_i131 < 16; c2_i131++) {
    c2_y[c2_i131] = 0.0;
  }

  c2_b_eml_matlab_zgetrf(chartInstance, c2_x, c2_ipiv, &c2_info);
  for (c2_i132 = 0; c2_i132 < 4; c2_i132++) {
    c2_p[c2_i132] = 1 + c2_i132;
  }

  for (c2_k = 1.0; c2_k <= 3.0; c2_k++) {
    c2_b_k = c2_k;
    c2_ipk = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", c2_b_k), 1, 4, 1, 0) - 1];
    if ((real_T)c2_ipk > c2_b_k) {
      c2_pipk = c2_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c2_ipk), 1, 4, 1, 0) - 1];
      c2_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_ipk), 1, 4, 1, 0) - 1] = c2_p[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", c2_b_k), 1, 4, 1, 0) - 1];
      c2_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_k), 1, 4, 1, 0) - 1] = c2_pipk;
    }
  }

  for (c2_c_k = 1; c2_c_k < 5; c2_c_k++) {
    c2_d_k = c2_c_k;
    c2_c = c2_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_d_k), 1, 4, 1, 0) - 1];
    c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_d_k), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_c), 1, 4, 2, 0) - 1) <<
           2)) - 1] = 1.0;
    c2_e_k = c2_d_k;
    for (c2_j = c2_e_k; c2_j < 5; c2_j++) {
      c2_b_j = c2_j;
      if (c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c2_b_j), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_c), 1, 4, 2, 0) - 1) <<
            2)) - 1] != 0.0) {
        c2_a = c2_b_j;
        c2_i133 = c2_a;
        for (c2_i = c2_i133 + 1; c2_i < 5; c2_i++) {
          c2_b_i = c2_i;
          c2_b_a = c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_c), 1, 4, 2, 0) - 1) << 2)) - 1];
          c2_b = c2_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
          c2_b_y = c2_b_a * c2_b;
          c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c2_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                   "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_c), 1, 4, 2, 0)
                  - 1) << 2)) - 1] = c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) +
            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_c), 1, 4, 2, 0) - 1) << 2)) - 1] - c2_b_y;
        }
      }
    }
  }

  for (c2_i134 = 0; c2_i134 < 16; c2_i134++) {
    c2_b_x[c2_i134] = c2_x[c2_i134];
  }

  c2_d_eml_blas_xtrsm(chartInstance, 4, 4, 1.0, c2_b_x, 1, 4, c2_y, 1, 4);
}

static void c2_eml_matlab_zgetrf(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, real_T c2_A[16], real_T c2_b_A[16], int32_T c2_ipiv[4],
  int32_T *c2_info)
{
  int32_T c2_i135;
  for (c2_i135 = 0; c2_i135 < 16; c2_i135++) {
    c2_b_A[c2_i135] = c2_A[c2_i135];
  }

  c2_b_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, c2_info);
}

static int32_T c2_eml_ixamax(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0)
{
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_i136;
  real_T c2_b_x[16];
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  for (c2_i136 = 0; c2_i136 < 16; c2_i136++) {
    c2_b_x[c2_i136] = c2_x[c2_i136];
  }

  return c2_ceval_ixamax(chartInstance, c2_b_n, c2_b_x, c2_b_ix0, 1);
}

static int32_T c2_ceval_ixamax(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, int32_T c2_incx)
{
  return idamax32(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 16, 1, 0) - 1], &c2_incx);
}

static void c2_ceval_xswap(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy, real_T c2_b_x[16])
{
  int32_T c2_i137;
  for (c2_i137 = 0; c2_i137 < 16; c2_i137++) {
    c2_b_x[c2_i137] = c2_x[c2_i137];
  }

  c2_b_ceval_xswap(chartInstance, c2_n, c2_b_x, c2_ix0, c2_incx, c2_iy0, c2_incy);
}

static void c2_ceval_xger(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_A[16], int32_T
  c2_ia0, int32_T c2_lda, real_T c2_b_A[16])
{
  int32_T c2_i138;
  for (c2_i138 = 0; c2_i138 < 16; c2_i138++) {
    c2_b_A[c2_i138] = c2_A[c2_i138];
  }

  c2_b_ceval_xger(chartInstance, c2_m, c2_n, c2_alpha1, c2_ix0, c2_incx, c2_iy0,
                  c2_incy, c2_b_A, c2_ia0, c2_lda);
}

static void c2_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[16], int32_T c2_ib0, int32_T
  c2_ldb, real_T c2_b_B[16])
{
  int32_T c2_i139;
  int32_T c2_i140;
  real_T c2_b_A[16];
  for (c2_i139 = 0; c2_i139 < 16; c2_i139++) {
    c2_b_B[c2_i139] = c2_B[c2_i139];
  }

  for (c2_i140 = 0; c2_i140 < 16; c2_i140++) {
    c2_b_A[c2_i140] = c2_A[c2_i140];
  }

  c2_d_eml_blas_xtrsm(chartInstance, c2_m, c2_n, c2_alpha1, c2_b_A, c2_ia0,
                      c2_lda, c2_b_B, c2_ib0, c2_ldb);
}

static real_T c2_b_norm(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
  real_T c2_x[16])
{
  real_T c2_y;
  real_T c2_j;
  real_T c2_b_j;
  real_T c2_s;
  real_T c2_i;
  real_T c2_b_i;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  boolean_T c2_b;
  boolean_T exitg1;
  c2_y = 0.0;
  c2_j = 1.0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c2_j <= 4.0)) {
    c2_b_j = c2_j;
    c2_s = 0.0;
    for (c2_i = 1.0; c2_i <= 4.0; c2_i++) {
      c2_b_i = c2_i;
      c2_b_x = c2_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c2_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", c2_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
      c2_c_x = c2_b_x;
      c2_b_y = muDoubleScalarAbs(c2_c_x);
      c2_s += c2_b_y;
    }

    c2_d_x = c2_s;
    c2_b = muDoubleScalarIsNaN(c2_d_x);
    if (c2_b) {
      c2_y = rtNaN;
      exitg1 = 1U;
    } else {
      if (c2_s > c2_y) {
        c2_y = c2_s;
      }

      c2_j++;
    }
  }

  return c2_y;
}

static void c2_b_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb,
  real_T c2_b_B[4])
{
  int32_T c2_i141;
  int32_T c2_i142;
  real_T c2_b_A[16];
  for (c2_i141 = 0; c2_i141 < 4; c2_i141++) {
    c2_b_B[c2_i141] = c2_B[c2_i141];
  }

  for (c2_i142 = 0; c2_i142 < 16; c2_i142++) {
    c2_b_A[c2_i142] = c2_A[c2_i142];
  }

  c2_e_eml_blas_xtrsm(chartInstance, c2_m, c2_n, c2_alpha1, c2_b_A, c2_ia0,
                      c2_lda, c2_b_B, c2_ib0, c2_ldb);
}

static void c2_c_eml_scalar_eg(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
}

static void c2_c_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb,
  real_T c2_b_B[4])
{
  int32_T c2_i143;
  int32_T c2_i144;
  real_T c2_b_A[16];
  for (c2_i143 = 0; c2_i143 < 4; c2_i143++) {
    c2_b_B[c2_i143] = c2_B[c2_i143];
  }

  for (c2_i144 = 0; c2_i144 < 16; c2_i144++) {
    c2_b_A[c2_i144] = c2_A[c2_i144];
  }

  c2_f_eml_blas_xtrsm(chartInstance, c2_m, c2_n, c2_alpha1, c2_b_A, c2_ia0,
                      c2_lda, c2_b_B, c2_ib0, c2_ldb);
}

static void c2_i_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_y[14])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_j_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[14])
{
  char_T c2_cv2[14];
  int32_T c2_i145;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_cv2, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c2_i145 = 0; c2_i145 < 14; c2_i145++) {
    c2_y[c2_i145] = c2_cv2[c2_i145];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_k_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i146;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i146, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i146;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_l_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Cinematica_JA_reducido, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Cinematica_JA_reducido), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Cinematica_JA_reducido);
  return c2_y;
}

static uint8_T c2_m_emlrt_marshallIn(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance,
                      real_T *c2_x)
{
  if (*c2_x < 0.0) {
    c2_b_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void c2_b_eml_matlab_zgetrf(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, real_T c2_A[16], int32_T c2_ipiv[4], int32_T *c2_info)
{
  int32_T c2_i147;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_jm1;
  int32_T c2_b;
  int32_T c2_mmj;
  int32_T c2_b_a;
  int32_T c2_c;
  int32_T c2_b_b;
  int32_T c2_jj;
  int32_T c2_c_a;
  int32_T c2_jp1j;
  int32_T c2_d_a;
  int32_T c2_b_c;
  int32_T c2_i148;
  int32_T c2_i149;
  int32_T c2_i150;
  real_T c2_b_A[16];
  int32_T c2_e_a;
  int32_T c2_jpiv_offset;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_jpiv;
  int32_T c2_g_a;
  int32_T c2_d_b;
  int32_T c2_c_c;
  int32_T c2_e_b;
  int32_T c2_jrow;
  int32_T c2_h_a;
  int32_T c2_f_b;
  int32_T c2_jprow;
  int32_T c2_ix0;
  int32_T c2_iy0;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_jp1j;
  int32_T c2_i_a;
  int32_T c2_d_c;
  int32_T c2_j_a;
  int32_T c2_g_b;
  int32_T c2_loop_ub;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_z;
  int32_T c2_h_b;
  int32_T c2_e_c;
  int32_T c2_k_a;
  int32_T c2_f_c;
  int32_T c2_l_a;
  int32_T c2_g_c;
  int32_T c2_m;
  int32_T c2_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_ia0;
  int32_T c2_b_m;
  int32_T c2_b_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_b_ia0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_c_ia0;
  c2_eps(chartInstance);
  for (c2_i147 = 0; c2_i147 < 4; c2_i147++) {
    c2_ipiv[c2_i147] = 1 + c2_i147;
  }

  *c2_info = 0;
  for (c2_j = 1; c2_j < 4; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j - 1;
    c2_jm1 = c2_a;
    c2_b = c2_b_j - 4;
    c2_mmj = -c2_b;
    c2_b_a = c2_jm1;
    c2_c = c2_b_a * 5;
    c2_b_b = c2_c + 1;
    c2_jj = c2_b_b;
    c2_c_a = c2_jj + 1;
    c2_jp1j = c2_c_a;
    c2_d_a = c2_mmj;
    c2_b_c = c2_d_a;
    c2_i148 = 0;
    for (c2_i149 = 0; c2_i149 < 4; c2_i149++) {
      for (c2_i150 = 0; c2_i150 < 4; c2_i150++) {
        c2_b_A[c2_i150 + c2_i148] = c2_A[c2_i150 + c2_i148];
      }

      c2_i148 += 4;
    }

    c2_e_a = c2_eml_ixamax(chartInstance, c2_b_c + 1, c2_b_A, c2_jj) - 1;
    c2_jpiv_offset = c2_e_a;
    c2_f_a = c2_jj;
    c2_c_b = c2_jpiv_offset;
    c2_jpiv = c2_f_a + c2_c_b;
    if (c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if ((real_T)c2_jpiv_offset != 0.0) {
        c2_g_a = c2_b_j;
        c2_d_b = c2_jpiv_offset;
        c2_c_c = c2_g_a + c2_d_b;
        c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 4, 1, 0) - 1] = c2_c_c;
        c2_e_b = c2_jm1 + 1;
        c2_jrow = c2_e_b;
        c2_h_a = c2_jrow;
        c2_f_b = c2_jpiv_offset;
        c2_jprow = c2_h_a + c2_f_b;
        c2_ix0 = c2_jrow;
        c2_iy0 = c2_jprow;
        c2_b_ix0 = c2_ix0;
        c2_b_iy0 = c2_iy0;
        c2_b_ceval_xswap(chartInstance, 4, c2_A, c2_b_ix0, 4, c2_b_iy0, 4);
      }

      c2_b_jp1j = c2_jp1j;
      c2_i_a = c2_mmj;
      c2_d_c = c2_i_a;
      c2_j_a = c2_jp1j;
      c2_g_b = c2_d_c;
      c2_loop_ub = (c2_j_a + c2_g_b) - 1;
      for (c2_i = c2_b_jp1j; c2_i <= c2_loop_ub; c2_i++) {
        c2_b_i = c2_i;
        c2_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_b_i), 1, 16, 1, 0) - 1];
        c2_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_jj), 1, 16, 1, 0) - 1];
        c2_b_x = c2_x;
        c2_b_y = c2_y;
        c2_z = c2_b_x / c2_b_y;
        c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 16, 1, 0) - 1] = c2_z;
      }
    } else {
      *c2_info = c2_b_j;
    }

    c2_h_b = c2_b_j;
    c2_e_c = -c2_h_b;
    c2_k_a = c2_jj;
    c2_f_c = c2_k_a;
    c2_l_a = c2_jj;
    c2_g_c = c2_l_a;
    c2_m = c2_mmj;
    c2_n = c2_e_c;
    c2_c_ix0 = c2_jp1j;
    c2_c_iy0 = c2_f_c;
    c2_ia0 = c2_g_c;
    c2_b_m = c2_m;
    c2_b_n = c2_n;
    c2_d_ix0 = c2_c_ix0;
    c2_d_iy0 = c2_c_iy0;
    c2_b_ia0 = c2_ia0;
    c2_c_m = c2_b_m;
    c2_c_n = c2_b_n + 4;
    c2_e_ix0 = c2_d_ix0;
    c2_e_iy0 = c2_d_iy0;
    c2_c_ia0 = c2_b_ia0;
    if ((real_T)c2_c_m < 1.0) {
    } else if ((real_T)c2_c_n < 1.0) {
    } else {
      c2_b_ceval_xger(chartInstance, c2_c_m, c2_c_n, -1.0, c2_e_ix0, 1, c2_e_iy0
                      + 4, 4, c2_A, c2_c_ia0 + 5, 4);
    }
  }

  if ((real_T)*c2_info == 0.0) {
    if (!(c2_A[15] != 0.0)) {
      *c2_info = 4;
    }
  }
}

static void c2_b_ceval_xswap(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, int32_T c2_incx,
  int32_T c2_iy0, int32_T c2_incy)
{
  dswap32(&c2_n, &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 16, 1, 0) - 1], &c2_incx,
          &c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy0), 1, 16, 1, 0) - 1], &c2_incy);
}

static void c2_b_ceval_xger(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0,
  int32_T c2_incx, int32_T c2_iy0, int32_T c2_incy, real_T c2_A[16], int32_T
  c2_ia0, int32_T c2_lda)
{
  dger32(&c2_m, &c2_n, &c2_alpha1, &c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ix0), 1, 16, 1, 0) - 1],
         &c2_incx, &c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_iy0), 1, 16, 1, 0) - 1], &c2_incy,
         &c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
           (real_T)c2_ia0), 1, 16, 1, 0) - 1], &c2_lda);
}

static void c2_d_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[16], int32_T c2_ib0, int32_T
  c2_ldb)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_ia0;
  int32_T c2_b_lda;
  int32_T c2_b_ib0;
  int32_T c2_b_ldb;
  boolean_T c2_NON_UNIT_ALPHA;
  int32_T c2_a;
  int32_T c2_Aoffset;
  int32_T c2_b_a;
  int32_T c2_Boffset;
  int32_T c2_loop_ub;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_c_a;
  int32_T c2_c;
  int32_T c2_d_a;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_e_a;
  int32_T c2_b_b;
  int32_T c2_jBcol;
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_c_loop_ub;
  int32_T c2_c_j;
  int32_T c2_g_a;
  int32_T c2_d_c;
  int32_T c2_h_a;
  int32_T c2_d_b;
  int32_T c2_e_c;
  int32_T c2_i_a;
  int32_T c2_e_b;
  int32_T c2_d_loop_ub;
  int32_T c2_c_i;
  int32_T c2_j_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_k_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_c_m;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_l_a;
  int32_T c2_h_c;
  int32_T c2_m_a;
  int32_T c2_h_b;
  int32_T c2_i_c;
  int32_T c2_n_a;
  int32_T c2_i_b;
  int32_T c2_kAcol;
  int32_T c2_o_a;
  int32_T c2_j_b;
  int32_T c2_j_c;
  int32_T c2_p_a;
  int32_T c2_k_b;
  int32_T c2_k_c;
  int32_T c2_q_a;
  int32_T c2_l_b;
  int32_T c2_l_c;
  int32_T c2_r_a;
  int32_T c2_m_b;
  int32_T c2_m_c;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_z;
  int32_T c2_s_a;
  int32_T c2_e_loop_ub;
  int32_T c2_d_i;
  int32_T c2_t_a;
  int32_T c2_n_b;
  int32_T c2_n_c;
  int32_T c2_u_a;
  int32_T c2_o_b;
  int32_T c2_o_c;
  int32_T c2_v_a;
  int32_T c2_p_b;
  int32_T c2_p_c;
  int32_T c2_w_a;
  int32_T c2_q_b;
  int32_T c2_q_c;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_ia0 = c2_ia0;
  c2_b_lda = c2_lda;
  c2_b_ib0 = c2_ib0;
  c2_b_ldb = c2_ldb;
  c2_NON_UNIT_ALPHA = (c2_b_alpha1 != 1.0);
  if ((real_T)c2_b_n == 0.0) {
  } else {
    c2_a = c2_b_ia0;
    c2_Aoffset = c2_a;
    c2_b_a = c2_b_ib0 - 1;
    c2_Boffset = c2_b_a;
    if (c2_b_alpha1 == 0.0) {
      c2_loop_ub = c2_b_n;
      for (c2_j = 1; c2_j <= c2_loop_ub; c2_j++) {
        c2_b_j = c2_j;
        c2_c_a = c2_b_j;
        c2_c = c2_c_a;
        c2_d_a = c2_b_ldb;
        c2_b = c2_c;
        c2_b_c = c2_d_a * (c2_b - 1);
        c2_e_a = c2_Boffset;
        c2_b_b = c2_b_c;
        c2_jBcol = c2_e_a + c2_b_b;
        c2_b_loop_ub = c2_b_m;
        for (c2_i = 1; c2_i <= c2_b_loop_ub; c2_i++) {
          c2_b_i = c2_i;
          c2_f_a = c2_b_i;
          c2_c_b = c2_jBcol;
          c2_c_c = c2_f_a + c2_c_b;
          c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_c_c), 1, 16, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_c_loop_ub = c2_b_n;
      for (c2_c_j = 1; c2_c_j <= c2_c_loop_ub; c2_c_j++) {
        c2_b_j = c2_c_j;
        c2_g_a = c2_b_j;
        c2_d_c = c2_g_a;
        c2_h_a = c2_b_ldb;
        c2_d_b = c2_d_c;
        c2_e_c = c2_h_a * (c2_d_b - 1);
        c2_i_a = c2_Boffset;
        c2_e_b = c2_e_c;
        c2_jBcol = c2_i_a + c2_e_b;
        if (c2_NON_UNIT_ALPHA) {
          c2_d_loop_ub = c2_b_m;
          for (c2_c_i = 1; c2_c_i <= c2_d_loop_ub; c2_c_i++) {
            c2_b_i = c2_c_i;
            c2_j_a = c2_b_i;
            c2_f_b = c2_jBcol;
            c2_f_c = c2_j_a + c2_f_b;
            c2_k_a = c2_b_i;
            c2_g_b = c2_jBcol;
            c2_g_c = c2_k_a + c2_g_b;
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_f_c), 1, 16, 1, 0) - 1] = c2_b_alpha1 *
              c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_g_c), 1, 16, 1, 0) - 1];
          }
        }

        c2_c_m = c2_b_m;
        for (c2_k = c2_c_m; c2_k > 0; c2_k--) {
          c2_b_k = c2_k;
          c2_l_a = c2_b_k;
          c2_h_c = c2_l_a;
          c2_m_a = c2_b_lda;
          c2_h_b = c2_h_c;
          c2_i_c = c2_m_a * (c2_h_b - 1);
          c2_n_a = c2_Aoffset;
          c2_i_b = c2_i_c - 1;
          c2_kAcol = c2_n_a + c2_i_b;
          c2_o_a = c2_b_k;
          c2_j_b = c2_jBcol;
          c2_j_c = c2_o_a + c2_j_b;
          if (c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_j_c), 1, 16, 1, 0) - 1] != 0.0) {
            c2_p_a = c2_b_k;
            c2_k_b = c2_jBcol;
            c2_k_c = c2_p_a + c2_k_b;
            c2_q_a = c2_b_k;
            c2_l_b = c2_jBcol;
            c2_l_c = c2_q_a + c2_l_b;
            c2_r_a = c2_b_k;
            c2_m_b = c2_kAcol;
            c2_m_c = c2_r_a + c2_m_b;
            c2_x = c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_l_c), 1, 16, 1, 0) - 1];
            c2_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_m_c), 1, 16, 1, 0) - 1];
            c2_b_x = c2_x;
            c2_b_y = c2_y;
            c2_z = c2_b_x / c2_b_y;
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_k_c), 1, 16, 1, 0) - 1] = c2_z;
            c2_s_a = c2_b_k;
            c2_e_loop_ub = c2_s_a;
            for (c2_d_i = 1; c2_d_i <= c2_e_loop_ub - 1; c2_d_i++) {
              c2_b_i = c2_d_i;
              c2_t_a = c2_b_i;
              c2_n_b = c2_jBcol;
              c2_n_c = c2_t_a + c2_n_b;
              c2_u_a = c2_b_i;
              c2_o_b = c2_jBcol;
              c2_o_c = c2_u_a + c2_o_b;
              c2_v_a = c2_b_k;
              c2_p_b = c2_jBcol;
              c2_p_c = c2_v_a + c2_p_b;
              c2_w_a = c2_b_i;
              c2_q_b = c2_kAcol;
              c2_q_c = c2_w_a + c2_q_b;
              c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_n_c), 1, 16, 1, 0) - 1] =
                c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_o_c), 1, 16, 1, 0) - 1] -
                c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_p_c), 1, 16, 1, 0) - 1] *
                c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_q_c), 1, 16, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static void c2_e_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_ia0;
  int32_T c2_b_lda;
  int32_T c2_b_ib0;
  int32_T c2_b_ldb;
  boolean_T c2_NON_UNIT_ALPHA;
  int32_T c2_a;
  int32_T c2_Aoffset;
  int32_T c2_b_a;
  int32_T c2_Boffset;
  int32_T c2_loop_ub;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_c_a;
  int32_T c2_c;
  int32_T c2_d_a;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_e_a;
  int32_T c2_b_b;
  int32_T c2_jBcol;
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_c_loop_ub;
  int32_T c2_c_j;
  int32_T c2_g_a;
  int32_T c2_d_c;
  int32_T c2_h_a;
  int32_T c2_d_b;
  int32_T c2_e_c;
  int32_T c2_i_a;
  int32_T c2_e_b;
  int32_T c2_d_loop_ub;
  int32_T c2_c_i;
  int32_T c2_j_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_k_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_e_loop_ub;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_l_a;
  int32_T c2_h_c;
  int32_T c2_m_a;
  int32_T c2_h_b;
  int32_T c2_i_c;
  int32_T c2_n_a;
  int32_T c2_i_b;
  int32_T c2_kAcol;
  int32_T c2_o_a;
  int32_T c2_j_b;
  int32_T c2_j_c;
  int32_T c2_p_a;
  int32_T c2_i151;
  int32_T c2_f_loop_ub;
  int32_T c2_d_i;
  int32_T c2_q_a;
  int32_T c2_k_b;
  int32_T c2_k_c;
  int32_T c2_r_a;
  int32_T c2_l_b;
  int32_T c2_l_c;
  int32_T c2_s_a;
  int32_T c2_m_b;
  int32_T c2_m_c;
  int32_T c2_t_a;
  int32_T c2_n_b;
  int32_T c2_n_c;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_ia0 = c2_ia0;
  c2_b_lda = c2_lda;
  c2_b_ib0 = c2_ib0;
  c2_b_ldb = c2_ldb;
  c2_NON_UNIT_ALPHA = (c2_b_alpha1 != 1.0);
  if ((real_T)c2_b_n == 0.0) {
  } else {
    c2_c_eml_scalar_eg(chartInstance);
    c2_a = c2_b_ia0;
    c2_Aoffset = c2_a;
    c2_b_a = c2_b_ib0 - 1;
    c2_Boffset = c2_b_a;
    if (c2_b_alpha1 == 0.0) {
      c2_loop_ub = c2_b_n;
      for (c2_j = 1; c2_j <= c2_loop_ub; c2_j++) {
        c2_b_j = c2_j;
        c2_c_a = c2_b_j;
        c2_c = c2_c_a;
        c2_d_a = c2_b_ldb;
        c2_b = c2_c;
        c2_b_c = c2_d_a * (c2_b - 1);
        c2_e_a = c2_Boffset;
        c2_b_b = c2_b_c;
        c2_jBcol = c2_e_a + c2_b_b;
        c2_b_loop_ub = c2_b_m;
        for (c2_i = 1; c2_i <= c2_b_loop_ub; c2_i++) {
          c2_b_i = c2_i;
          c2_f_a = c2_b_i;
          c2_c_b = c2_jBcol;
          c2_c_c = c2_f_a + c2_c_b;
          c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_c_c), 1, 4, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_c_loop_ub = c2_b_n;
      for (c2_c_j = 1; c2_c_j <= c2_c_loop_ub; c2_c_j++) {
        c2_b_j = c2_c_j;
        c2_g_a = c2_b_j;
        c2_d_c = c2_g_a;
        c2_h_a = c2_b_ldb;
        c2_d_b = c2_d_c;
        c2_e_c = c2_h_a * (c2_d_b - 1);
        c2_i_a = c2_Boffset;
        c2_e_b = c2_e_c;
        c2_jBcol = c2_i_a + c2_e_b;
        if (c2_NON_UNIT_ALPHA) {
          c2_d_loop_ub = c2_b_m;
          for (c2_c_i = 1; c2_c_i <= c2_d_loop_ub; c2_c_i++) {
            c2_b_i = c2_c_i;
            c2_j_a = c2_b_i;
            c2_f_b = c2_jBcol;
            c2_f_c = c2_j_a + c2_f_b;
            c2_k_a = c2_b_i;
            c2_g_b = c2_jBcol;
            c2_g_c = c2_k_a + c2_g_b;
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_f_c), 1, 4, 1, 0) - 1] = c2_b_alpha1 *
              c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_g_c), 1, 4, 1, 0) - 1];
          }
        }

        c2_e_loop_ub = c2_b_m;
        for (c2_k = 1; c2_k <= c2_e_loop_ub; c2_k++) {
          c2_b_k = c2_k;
          c2_l_a = c2_b_k;
          c2_h_c = c2_l_a;
          c2_m_a = c2_b_lda;
          c2_h_b = c2_h_c;
          c2_i_c = c2_m_a * (c2_h_b - 1);
          c2_n_a = c2_Aoffset;
          c2_i_b = c2_i_c - 1;
          c2_kAcol = c2_n_a + c2_i_b;
          c2_o_a = c2_b_k;
          c2_j_b = c2_jBcol;
          c2_j_c = c2_o_a + c2_j_b;
          if (c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_j_c), 1, 4, 1, 0) - 1] != 0.0) {
            c2_p_a = c2_b_k;
            c2_i151 = c2_p_a;
            c2_f_loop_ub = c2_b_m;
            for (c2_d_i = c2_i151 + 1; c2_d_i <= c2_f_loop_ub; c2_d_i++) {
              c2_b_i = c2_d_i;
              c2_q_a = c2_b_i;
              c2_k_b = c2_jBcol;
              c2_k_c = c2_q_a + c2_k_b;
              c2_r_a = c2_b_i;
              c2_l_b = c2_jBcol;
              c2_l_c = c2_r_a + c2_l_b;
              c2_s_a = c2_b_k;
              c2_m_b = c2_jBcol;
              c2_m_c = c2_s_a + c2_m_b;
              c2_t_a = c2_b_i;
              c2_n_b = c2_kAcol;
              c2_n_c = c2_t_a + c2_n_b;
              c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_k_c), 1, 4, 1, 0) - 1] =
                c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_l_c), 1, 4, 1, 0) - 1] -
                c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_m_c), 1, 4, 1, 0) - 1] *
                c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_n_c), 1, 16, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static void c2_f_eml_blas_xtrsm(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, int32_T c2_m, int32_T c2_n, real_T c2_alpha1, real_T c2_A[16],
  int32_T c2_ia0, int32_T c2_lda, real_T c2_B[4], int32_T c2_ib0, int32_T c2_ldb)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_ia0;
  int32_T c2_b_lda;
  int32_T c2_b_ib0;
  int32_T c2_b_ldb;
  boolean_T c2_NON_UNIT_ALPHA;
  int32_T c2_a;
  int32_T c2_Aoffset;
  int32_T c2_b_a;
  int32_T c2_Boffset;
  int32_T c2_loop_ub;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_c_a;
  int32_T c2_c;
  int32_T c2_d_a;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_e_a;
  int32_T c2_b_b;
  int32_T c2_jBcol;
  int32_T c2_b_loop_ub;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_c_c;
  int32_T c2_c_loop_ub;
  int32_T c2_c_j;
  int32_T c2_g_a;
  int32_T c2_d_c;
  int32_T c2_h_a;
  int32_T c2_d_b;
  int32_T c2_e_c;
  int32_T c2_i_a;
  int32_T c2_e_b;
  int32_T c2_d_loop_ub;
  int32_T c2_c_i;
  int32_T c2_j_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_k_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_c_m;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_l_a;
  int32_T c2_h_c;
  int32_T c2_m_a;
  int32_T c2_h_b;
  int32_T c2_i_c;
  int32_T c2_n_a;
  int32_T c2_i_b;
  int32_T c2_kAcol;
  int32_T c2_o_a;
  int32_T c2_j_b;
  int32_T c2_j_c;
  int32_T c2_p_a;
  int32_T c2_k_b;
  int32_T c2_k_c;
  int32_T c2_q_a;
  int32_T c2_l_b;
  int32_T c2_l_c;
  int32_T c2_r_a;
  int32_T c2_m_b;
  int32_T c2_m_c;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_z;
  int32_T c2_s_a;
  int32_T c2_e_loop_ub;
  int32_T c2_d_i;
  int32_T c2_t_a;
  int32_T c2_n_b;
  int32_T c2_n_c;
  int32_T c2_u_a;
  int32_T c2_o_b;
  int32_T c2_o_c;
  int32_T c2_v_a;
  int32_T c2_p_b;
  int32_T c2_p_c;
  int32_T c2_w_a;
  int32_T c2_q_b;
  int32_T c2_q_c;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_ia0 = c2_ia0;
  c2_b_lda = c2_lda;
  c2_b_ib0 = c2_ib0;
  c2_b_ldb = c2_ldb;
  c2_NON_UNIT_ALPHA = (c2_b_alpha1 != 1.0);
  if ((real_T)c2_b_n == 0.0) {
  } else {
    c2_c_eml_scalar_eg(chartInstance);
    c2_a = c2_b_ia0;
    c2_Aoffset = c2_a;
    c2_b_a = c2_b_ib0 - 1;
    c2_Boffset = c2_b_a;
    if (c2_b_alpha1 == 0.0) {
      c2_loop_ub = c2_b_n;
      for (c2_j = 1; c2_j <= c2_loop_ub; c2_j++) {
        c2_b_j = c2_j;
        c2_c_a = c2_b_j;
        c2_c = c2_c_a;
        c2_d_a = c2_b_ldb;
        c2_b = c2_c;
        c2_b_c = c2_d_a * (c2_b - 1);
        c2_e_a = c2_Boffset;
        c2_b_b = c2_b_c;
        c2_jBcol = c2_e_a + c2_b_b;
        c2_b_loop_ub = c2_b_m;
        for (c2_i = 1; c2_i <= c2_b_loop_ub; c2_i++) {
          c2_b_i = c2_i;
          c2_f_a = c2_b_i;
          c2_c_b = c2_jBcol;
          c2_c_c = c2_f_a + c2_c_b;
          c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_c_c), 1, 4, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c2_c_loop_ub = c2_b_n;
      for (c2_c_j = 1; c2_c_j <= c2_c_loop_ub; c2_c_j++) {
        c2_b_j = c2_c_j;
        c2_g_a = c2_b_j;
        c2_d_c = c2_g_a;
        c2_h_a = c2_b_ldb;
        c2_d_b = c2_d_c;
        c2_e_c = c2_h_a * (c2_d_b - 1);
        c2_i_a = c2_Boffset;
        c2_e_b = c2_e_c;
        c2_jBcol = c2_i_a + c2_e_b;
        if (c2_NON_UNIT_ALPHA) {
          c2_d_loop_ub = c2_b_m;
          for (c2_c_i = 1; c2_c_i <= c2_d_loop_ub; c2_c_i++) {
            c2_b_i = c2_c_i;
            c2_j_a = c2_b_i;
            c2_f_b = c2_jBcol;
            c2_f_c = c2_j_a + c2_f_b;
            c2_k_a = c2_b_i;
            c2_g_b = c2_jBcol;
            c2_g_c = c2_k_a + c2_g_b;
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_f_c), 1, 4, 1, 0) - 1] = c2_b_alpha1 *
              c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_g_c), 1, 4, 1, 0) - 1];
          }
        }

        c2_c_m = c2_b_m;
        for (c2_k = c2_c_m; c2_k > 0; c2_k--) {
          c2_b_k = c2_k;
          c2_l_a = c2_b_k;
          c2_h_c = c2_l_a;
          c2_m_a = c2_b_lda;
          c2_h_b = c2_h_c;
          c2_i_c = c2_m_a * (c2_h_b - 1);
          c2_n_a = c2_Aoffset;
          c2_i_b = c2_i_c - 1;
          c2_kAcol = c2_n_a + c2_i_b;
          c2_o_a = c2_b_k;
          c2_j_b = c2_jBcol;
          c2_j_c = c2_o_a + c2_j_b;
          if (c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_j_c), 1, 4, 1, 0) - 1] != 0.0) {
            c2_p_a = c2_b_k;
            c2_k_b = c2_jBcol;
            c2_k_c = c2_p_a + c2_k_b;
            c2_q_a = c2_b_k;
            c2_l_b = c2_jBcol;
            c2_l_c = c2_q_a + c2_l_b;
            c2_r_a = c2_b_k;
            c2_m_b = c2_kAcol;
            c2_m_c = c2_r_a + c2_m_b;
            c2_x = c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_l_c), 1, 4, 1, 0) - 1];
            c2_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_m_c), 1, 16, 1, 0) - 1];
            c2_b_x = c2_x;
            c2_b_y = c2_y;
            c2_z = c2_b_x / c2_b_y;
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_k_c), 1, 4, 1, 0) - 1] = c2_z;
            c2_s_a = c2_b_k;
            c2_e_loop_ub = c2_s_a;
            for (c2_d_i = 1; c2_d_i <= c2_e_loop_ub - 1; c2_d_i++) {
              c2_b_i = c2_d_i;
              c2_t_a = c2_b_i;
              c2_n_b = c2_jBcol;
              c2_n_c = c2_t_a + c2_n_b;
              c2_u_a = c2_b_i;
              c2_o_b = c2_jBcol;
              c2_o_c = c2_u_a + c2_o_b;
              c2_v_a = c2_b_k;
              c2_p_b = c2_jBcol;
              c2_p_c = c2_v_a + c2_p_b;
              c2_w_a = c2_b_i;
              c2_q_b = c2_kAcol;
              c2_q_c = c2_w_a + c2_q_b;
              c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_n_c), 1, 4, 1, 0) - 1] =
                c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_o_c), 1, 4, 1, 0) - 1] -
                c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_p_c), 1, 4, 1, 0) - 1] *
                c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c2_q_c), 1, 16, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc2_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_Cinematica_JA_reducido_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4262804308U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3357890084U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1961882320U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(123693243U);
}

mxArray *sf_c2_Cinematica_JA_reducido_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(835624523U);
    pr[1] = (double)(1537632843U);
    pr[2] = (double)(2775940140U);
    pr[3] = (double)(3989017646U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_Cinematica_JA_reducido(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[16],T\"X_b\",},{M[1],M[13],T\"qp\",},{M[8],M[0],T\"is_active_c2_Cinematica_JA_reducido\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Cinematica_JA_reducido_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
    chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Cinematica_JA_reducidoMachineNumber_,
           2,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Cinematica_JA_reducidoMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Cinematica_JA_reducidoMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Cinematica_JA_reducidoMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,2,0,1,"qp");
          _SFD_SET_DATA_PROPS(2,2,0,1,"X_b");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Ke");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4894);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c2_q)[4];
          real_T (*c2_qp)[4];
          real_T (*c2_X_b)[4];
          real_T (*c2_Ke)[4];
          c2_Ke = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c2_X_b = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_q);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_qp);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_X_b);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_Ke);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Cinematica_JA_reducidoMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_Cinematica_JA_reducido(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Cinematica_JA_reducido
    ((SFc2_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
  initialize_c2_Cinematica_JA_reducido
    ((SFc2_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Cinematica_JA_reducido(void *chartInstanceVar)
{
  enable_c2_Cinematica_JA_reducido((SFc2_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_Cinematica_JA_reducido(void *chartInstanceVar)
{
  disable_c2_Cinematica_JA_reducido((SFc2_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_Cinematica_JA_reducido(void *chartInstanceVar)
{
  sf_c2_Cinematica_JA_reducido((SFc2_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Cinematica_JA_reducido
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Cinematica_JA_reducido
    ((SFc2_Cinematica_JA_reducidoInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Cinematica_JA_reducido();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_Cinematica_JA_reducido(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Cinematica_JA_reducido();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Cinematica_JA_reducido
    ((SFc2_Cinematica_JA_reducidoInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Cinematica_JA_reducido
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Cinematica_JA_reducido(S);
}

static void sf_opaque_set_sim_state_c2_Cinematica_JA_reducido(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_Cinematica_JA_reducido(S, st);
}

static void sf_opaque_terminate_c2_Cinematica_JA_reducido(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Cinematica_JA_reducidoInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Cinematica_JA_reducido
      ((SFc2_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Cinematica_JA_reducido
    ((SFc2_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Cinematica_JA_reducido(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Cinematica_JA_reducido
      ((SFc2_Cinematica_JA_reducidoInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Cinematica_JA_reducido(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Cinematica_JA_reducido",
      "Cinematica_JA_reducido",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Cinematica_JA_reducido",
                "Cinematica_JA_reducido",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Cinematica_JA_reducido",
      "Cinematica_JA_reducido",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Cinematica_JA_reducido",
        "Cinematica_JA_reducido",2,2);
      sf_mark_chart_reusable_outputs(S,"Cinematica_JA_reducido",
        "Cinematica_JA_reducido",2,2);
    }

    sf_set_rtw_dwork_info(S,"Cinematica_JA_reducido","Cinematica_JA_reducido",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3212661890U));
  ssSetChecksum1(S,(1379292280U));
  ssSetChecksum2(S,(1053684936U));
  ssSetChecksum3(S,(3159074145U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Cinematica_JA_reducido(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Cinematica_JA_reducido",
      "Cinematica_JA_reducido",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Cinematica_JA_reducido(SimStruct *S)
{
  SFc2_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_JA_reducidoInstanceStruct *)malloc(sizeof
    (SFc2_Cinematica_JA_reducidoInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Cinematica_JA_reducidoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Cinematica_JA_reducido;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_Cinematica_JA_reducido_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Cinematica_JA_reducido(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Cinematica_JA_reducido(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Cinematica_JA_reducido(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Cinematica_JA_reducido_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
