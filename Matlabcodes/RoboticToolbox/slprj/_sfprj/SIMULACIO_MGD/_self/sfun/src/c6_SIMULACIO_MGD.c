/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SIMULACIO_MGD_sfun.h"
#include "c6_SIMULACIO_MGD.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMULACIO_MGD_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[8] = { "Sa", "lambda", "nargin",
  "nargout", "Ja", "J_PI", "S_a", "d_et" };

/* Function Declarations */
static void initialize_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void initialize_params_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct *
  chartInstance);
static void enable_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void disable_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_SIMULACIO_MGD
  (SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_SIMULACIO_MGD
  (SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void set_sim_state_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void sf_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_chartstep_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void initSimStructsc6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void registerMessagesc6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_d_et, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_J_PI, const char_T *c6_identifier, real_T
  c6_y[24]);
static void c6_d_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[24]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_e_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[16]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[260]);
static void c6_b_info_helper(c6_ResolvedFunctionInfo c6_info[260]);
static void c6_c_info_helper(c6_ResolvedFunctionInfo c6_info[260]);
static void c6_d_info_helper(c6_ResolvedFunctionInfo c6_info[260]);
static void c6_e_info_helper(c6_ResolvedFunctionInfo c6_info[260]);
static void c6_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_b_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_c_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_mldivide(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_A[16], real_T c6_B[24], real_T c6_Y[24]);
static void c6_realmin(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_eps(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_eml_matlab_zgetrf(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_b_A[16], int32_T c6_ipiv[4], int32_T *c6_info);
static real_T c6_abs(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
                     c6_x);
static void c6_check_forloop_overflow_error(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, boolean_T c6_overflow);
static void c6_below_threshold(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static real_T c6_eml_div(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_x, real_T c6_y);
static void c6_eml_xger(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, int32_T
  c6_m, int32_T c6_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0, real_T
  c6_A[16], int32_T c6_ia0, real_T c6_b_A[16]);
static void c6_eml_warning(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_A[16], real_T c6_B[24], real_T c6_b_B[24]);
static void c6_b_below_threshold(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_d_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_b_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_B[24], real_T c6_b_B[24]);
static void c6_e_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_eml_error(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_eml_xgesvd(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[24], real_T c6_U[24], real_T c6_S[4], real_T c6_V[16]);
static real_T c6_eml_xnrm2(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[24], int32_T c6_ix0);
static void c6_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_b_x[24]);
static real_T c6_eml_xdotc(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[24], int32_T c6_ix0, real_T c6_y[24], int32_T c6_iy0);
static void c6_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[24], int32_T c6_iy0,
  real_T c6_b_y[24]);
static real_T c6_b_eml_xnrm2(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[4], int32_T c6_ix0);
static void c6_b_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[4], int32_T c6_ix0, real_T c6_b_x[4]);
static void c6_b_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_y[6],
  int32_T c6_iy0, real_T c6_b_y[6]);
static void c6_c_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[6], int32_T c6_ix0, real_T c6_y[24],
  int32_T c6_iy0, real_T c6_b_y[24]);
static real_T c6_b_eml_xdotc(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[16], int32_T c6_ix0, real_T c6_y[16], int32_T c6_iy0);
static void c6_d_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[16], int32_T c6_iy0,
  real_T c6_b_y[16]);
static void c6_c_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_b_x[24]);
static void c6_d_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[16], int32_T c6_ix0, real_T c6_b_x[16]);
static void c6_b_eml_error(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static real_T c6_sqrt(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
                      c6_x);
static void c6_c_eml_error(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c6_eml_xrotg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_b, real_T *c6_b_a, real_T *c6_b_b, real_T *c6_c, real_T *c6_s);
static void c6_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_x[16], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s, real_T
  c6_b_x[16]);
static void c6_b_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s,
  real_T c6_b_x[24]);
static void c6_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_x[16], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[16]);
static void c6_b_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[24]);
static void c6_eml_xgemm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[16], real_T c6_B[24], real_T c6_C[24], real_T
  c6_b_C[24]);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_f_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_g_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_SIMULACIO_MGD, const char_T
  *c6_identifier);
static uint8_T c6_h_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_eml_matlab_zgetrf(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, real_T c6_A[16], int32_T c6_ipiv[4], int32_T *c6_info);
static void c6_b_eml_xger(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_m, int32_T c6_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0,
  real_T c6_A[16], int32_T c6_ia0);
static void c6_c_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_B[24]);
static void c6_d_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_B[24]);
static void c6_e_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0);
static void c6_e_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[24], int32_T c6_iy0);
static void c6_f_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[4], int32_T c6_ix0);
static void c6_f_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_y[6],
  int32_T c6_iy0);
static void c6_g_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[6], int32_T c6_ix0, real_T c6_y[24],
  int32_T c6_iy0);
static void c6_h_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[16], int32_T c6_iy0);
static void c6_g_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[24], int32_T c6_ix0);
static void c6_h_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[16], int32_T c6_ix0);
static void c6_b_sqrt(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
                      *c6_x);
static void c6_b_eml_xrotg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T *c6_a, real_T *c6_b, real_T *c6_c, real_T *c6_s);
static void c6_c_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[16], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s);
static void c6_d_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s);
static void c6_c_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[16], int32_T c6_ix0, int32_T c6_iy0);
static void c6_d_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0);
static void c6_b_eml_xgemm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[16], real_T c6_B[24], real_T c6_C[24]);
static void init_dsm_address_info(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_SIMULACIO_MGD = 0U;
}

static void initialize_params_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct *
  chartInstance)
{
}

static void enable_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_SIMULACIO_MGD
  (SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_SIMULACIO_MGD
  (SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[24];
  const mxArray *c6_b_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_c_hoistedGlobal;
  uint8_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  real_T *c6_S_a;
  real_T *c6_d_et;
  real_T (*c6_J_PI)[24];
  c6_d_et = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_S_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_J_PI = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(4), FALSE);
  for (c6_i0 = 0; c6_i0 < 24; c6_i0++) {
    c6_u[c6_i0] = (*c6_J_PI)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 4, 6), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = *c6_S_a;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_b_hoistedGlobal = *c6_d_et;
  c6_c_u = c6_b_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_c_hoistedGlobal = chartInstance->c6_is_active_c6_SIMULACIO_MGD;
  c6_d_u = c6_c_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[24];
  int32_T c6_i1;
  real_T *c6_S_a;
  real_T *c6_d_et;
  real_T (*c6_J_PI)[24];
  c6_d_et = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_S_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_J_PI = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                        "J_PI", c6_dv0);
  for (c6_i1 = 0; c6_i1 < 24; c6_i1++) {
    (*c6_J_PI)[c6_i1] = c6_dv0[c6_i1];
  }

  *c6_S_a = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
    "S_a");
  *c6_d_et = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u,
    2)), "d_et");
  chartInstance->c6_is_active_c6_SIMULACIO_MGD = c6_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 3)),
     "is_active_c6_SIMULACIO_MGD");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_SIMULACIO_MGD(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
}

static void sf_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  real_T *c6_S_a;
  real_T *c6_d_et;
  real_T (*c6_J_PI)[24];
  real_T (*c6_Ja)[24];
  c6_d_et = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_S_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_J_PI = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_Ja = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 24; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_Ja)[c6_i2], 0U);
  }

  for (c6_i3 = 0; c6_i3 < 24; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_J_PI)[c6_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_S_a, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_d_et, 3U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_SIMULACIO_MGD(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SIMULACIO_MGDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  int32_T c6_i4;
  real_T c6_Ja[24];
  uint32_T c6_debug_family_var_map[8];
  real_T c6_Sa[16];
  real_T c6_lambda;
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 3.0;
  real_T c6_J_PI[24];
  real_T c6_S_a;
  real_T c6_d_et;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  real_T c6_a[24];
  int32_T c6_i9;
  real_T c6_U[24];
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  real_T c6_S[16];
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  int32_T c6_i33;
  static real_T c6_y[16] = { 0.01, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0,
    0.01, 0.0, 0.0, 0.0, 0.0, 0.01 };

  real_T c6_b_S[16];
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  real_T c6_b_Ja[24];
  real_T c6_dv1[24];
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_x;
  real_T c6_b_x;
  boolean_T c6_b;
  boolean_T c6_b0;
  real_T c6_c_x;
  boolean_T c6_b_b;
  boolean_T c6_b1;
  boolean_T c6_c_b;
  int32_T c6_i41;
  real_T c6_b_U[24];
  real_T c6_V[16];
  real_T c6_s[4];
  int32_T c6_i42;
  int32_T c6_c_k;
  real_T c6_d_k;
  real_T c6_d_b;
  real_T c6_b_y;
  real_T c6_b_a;
  real_T c6_tol;
  int32_T c6_r;
  int32_T c6_e_k;
  int32_T c6_f_k;
  int32_T c6_c_a;
  int32_T c6_vcol;
  int32_T c6_b_r;
  int32_T c6_e_b;
  int32_T c6_f_b;
  boolean_T c6_overflow;
  int32_T c6_j;
  int32_T c6_b_j;
  real_T c6_c_y;
  real_T c6_z;
  int32_T c6_d_a;
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  real_T c6_dv2[16];
  int32_T c6_i47;
  real_T c6_dv3[24];
  int32_T c6_i48;
  real_T c6_dv4[16];
  int32_T c6_i49;
  real_T c6_dv5[24];
  int32_T c6_i50;
  int32_T c6_info;
  int32_T c6_ipiv[4];
  int32_T c6_g_k;
  real_T c6_h_k;
  real_T c6_e_a;
  real_T c6_g_b;
  boolean_T c6_isodd;
  int32_T c6_i_k;
  int32_T c6_f_a;
  real_T c6_h_b;
  int32_T c6_g_a;
  real_T c6_i_b;
  int32_T c6_idx;
  real_T c6_flt;
  boolean_T c6_p;
  int32_T c6_i51;
  real_T *c6_b_S_a;
  real_T *c6_b_d_et;
  real_T (*c6_b_J_PI)[24];
  real_T (*c6_c_Ja)[24];
  boolean_T exitg1;
  c6_b_d_et = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c6_b_S_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_J_PI = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_c_Ja = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i4 = 0; c6_i4 < 24; c6_i4++) {
    c6_Ja[c6_i4] = (*c6_c_Ja)[c6_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Sa, 0U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c6_lambda, 1U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 2U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_Ja, 4U, c6_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_J_PI, 5U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_S_a, 6U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_et, 7U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_i5 = 0;
  for (c6_i6 = 0; c6_i6 < 6; c6_i6++) {
    c6_i7 = 0;
    for (c6_i8 = 0; c6_i8 < 4; c6_i8++) {
      c6_a[c6_i8 + c6_i5] = c6_Ja[c6_i7 + c6_i6];
      c6_i7 += 6;
    }

    c6_i5 += 4;
  }

  for (c6_i9 = 0; c6_i9 < 24; c6_i9++) {
    c6_U[c6_i9] = c6_Ja[c6_i9];
  }

  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i10 = 0; c6_i10 < 16; c6_i10++) {
    c6_Sa[c6_i10] = 0.0;
  }

  for (c6_i11 = 0; c6_i11 < 16; c6_i11++) {
    c6_Sa[c6_i11] = 0.0;
  }

  for (c6_i12 = 0; c6_i12 < 16; c6_i12++) {
    c6_S[c6_i12] = c6_Sa[c6_i12];
  }

  for (c6_i13 = 0; c6_i13 < 16; c6_i13++) {
    c6_Sa[c6_i13] = c6_S[c6_i13];
  }

  for (c6_i14 = 0; c6_i14 < 16; c6_i14++) {
    c6_S[c6_i14] = c6_Sa[c6_i14];
  }

  for (c6_i15 = 0; c6_i15 < 16; c6_i15++) {
    c6_Sa[c6_i15] = c6_S[c6_i15];
  }

  for (c6_i16 = 0; c6_i16 < 4; c6_i16++) {
    c6_i17 = 0;
    c6_i18 = 0;
    for (c6_i19 = 0; c6_i19 < 4; c6_i19++) {
      c6_Sa[c6_i17 + c6_i16] = 0.0;
      c6_i20 = 0;
      for (c6_i21 = 0; c6_i21 < 6; c6_i21++) {
        c6_Sa[c6_i17 + c6_i16] += c6_a[c6_i20 + c6_i16] * c6_U[c6_i21 + c6_i18];
        c6_i20 += 4;
      }

      c6_i17 += 4;
      c6_i18 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_lambda = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_S_a = c6_Sa[15];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, c6_Sa[15] < c6_lambda)) {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
    c6_i22 = 0;
    for (c6_i23 = 0; c6_i23 < 6; c6_i23++) {
      c6_i24 = 0;
      for (c6_i25 = 0; c6_i25 < 4; c6_i25++) {
        c6_a[c6_i25 + c6_i22] = c6_Ja[c6_i24 + c6_i23];
        c6_i24 += 6;
      }

      c6_i22 += 4;
    }

    for (c6_i26 = 0; c6_i26 < 24; c6_i26++) {
      c6_U[c6_i26] = c6_Ja[c6_i26];
    }

    c6_eml_scalar_eg(chartInstance);
    c6_eml_scalar_eg(chartInstance);
    for (c6_i27 = 0; c6_i27 < 4; c6_i27++) {
      c6_i28 = 0;
      c6_i29 = 0;
      for (c6_i30 = 0; c6_i30 < 4; c6_i30++) {
        c6_S[c6_i28 + c6_i27] = 0.0;
        c6_i31 = 0;
        for (c6_i32 = 0; c6_i32 < 6; c6_i32++) {
          c6_S[c6_i28 + c6_i27] += c6_a[c6_i31 + c6_i27] * c6_U[c6_i32 + c6_i29];
          c6_i31 += 4;
        }

        c6_i28 += 4;
        c6_i29 += 6;
      }
    }

    for (c6_i33 = 0; c6_i33 < 16; c6_i33++) {
      c6_b_S[c6_i33] = c6_S[c6_i33] + c6_y[c6_i33];
    }

    c6_i34 = 0;
    for (c6_i35 = 0; c6_i35 < 6; c6_i35++) {
      c6_i36 = 0;
      for (c6_i37 = 0; c6_i37 < 4; c6_i37++) {
        c6_b_Ja[c6_i37 + c6_i34] = c6_Ja[c6_i36 + c6_i35];
        c6_i36 += 6;
      }

      c6_i34 += 4;
    }

    c6_mldivide(chartInstance, c6_b_S, c6_b_Ja, c6_dv1);
    for (c6_i38 = 0; c6_i38 < 24; c6_i38++) {
      c6_J_PI[c6_i38] = c6_dv1[c6_i38];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
    for (c6_i39 = 0; c6_i39 < 24; c6_i39++) {
      c6_U[c6_i39] = c6_Ja[c6_i39];
    }

    for (c6_i40 = 0; c6_i40 < 24; c6_i40++) {
      c6_J_PI[c6_i40] = 0.0;
    }

    for (c6_k = 1; c6_k < 25; c6_k++) {
      c6_b_k = c6_k;
      c6_x = c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_k), 1, 24, 1, 0) - 1];
      c6_b_x = c6_x;
      c6_b = muDoubleScalarIsInf(c6_b_x);
      c6_b0 = !c6_b;
      c6_c_x = c6_x;
      c6_b_b = muDoubleScalarIsNaN(c6_c_x);
      c6_b1 = !c6_b_b;
      c6_c_b = (c6_b0 && c6_b1);
      if (!c6_c_b) {
        c6_eml_error(chartInstance);
      }
    }

    for (c6_i41 = 0; c6_i41 < 24; c6_i41++) {
      c6_b_U[c6_i41] = c6_U[c6_i41];
    }

    c6_eml_xgesvd(chartInstance, c6_b_U, c6_U, c6_s, c6_V);
    for (c6_i42 = 0; c6_i42 < 16; c6_i42++) {
      c6_S[c6_i42] = 0.0;
    }

    for (c6_c_k = 0; c6_c_k < 4; c6_c_k++) {
      c6_d_k = 1.0 + (real_T)c6_c_k;
      c6_S[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
             _SFD_INTEGER_CHECK("", c6_d_k), 1, 4, 1, 0) + (((int32_T)(real_T)
              _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                c6_d_k), 1, 4, 2, 0) - 1) << 2)) - 1] = c6_s[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_d_k),
        1, 4, 1, 0) - 1];
    }

    c6_eps(chartInstance);
    c6_d_b = c6_S[0];
    c6_b_y = 6.0 * c6_d_b;
    c6_b_a = c6_b_y;
    c6_tol = c6_b_a * 2.2204460492503131E-16;
    c6_r = 0;
    c6_e_k = 1;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c6_e_k < 5)) {
      c6_f_k = c6_e_k;
      if (!(c6_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_f_k), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_f_k), 1, 4, 2, 0) - 1)
             << 2)) - 1] > c6_tol)) {
        exitg1 = TRUE;
      } else {
        c6_c_a = c6_r + 1;
        c6_r = c6_c_a;
        c6_e_k++;
      }
    }

    if (c6_r > 0) {
      c6_vcol = 1;
      c6_b_r = c6_r;
      c6_e_b = c6_b_r;
      c6_f_b = c6_e_b;
      if (1 > c6_f_b) {
        c6_overflow = FALSE;
      } else {
        c6_overflow = (c6_f_b > 2147483646);
      }

      if (c6_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_overflow);
      }

      for (c6_j = 1; c6_j <= c6_b_r; c6_j++) {
        c6_b_j = c6_j;
        c6_c_y = c6_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 4, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
        c6_z = 1.0 / c6_c_y;
        c6_h_eml_xscal(chartInstance, c6_z, c6_V, c6_vcol);
        c6_d_a = c6_vcol + 4;
        c6_vcol = c6_d_a;
      }

      c6_i43 = c6_r;
      for (c6_i44 = 0; c6_i44 < 24; c6_i44++) {
        c6_J_PI[c6_i44] = 0.0;
      }

      c6_i45 = c6_i43;
      for (c6_i46 = 0; c6_i46 < 16; c6_i46++) {
        c6_dv2[c6_i46] = c6_V[c6_i46];
      }

      for (c6_i47 = 0; c6_i47 < 24; c6_i47++) {
        c6_dv3[c6_i47] = c6_U[c6_i47];
      }

      for (c6_i48 = 0; c6_i48 < 16; c6_i48++) {
        c6_dv4[c6_i48] = c6_dv2[c6_i48];
      }

      for (c6_i49 = 0; c6_i49 < 24; c6_i49++) {
        c6_dv5[c6_i49] = c6_dv3[c6_i49];
      }

      c6_b_eml_xgemm(chartInstance, c6_i45, c6_dv4, c6_dv5, c6_J_PI);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 16);
  for (c6_i50 = 0; c6_i50 < 16; c6_i50++) {
    c6_S[c6_i50] = c6_Sa[c6_i50];
  }

  c6_b_eml_matlab_zgetrf(chartInstance, c6_S, c6_ipiv, &c6_info);
  c6_d_et = c6_S[0];
  for (c6_g_k = 0; c6_g_k < 3; c6_g_k++) {
    c6_h_k = 2.0 + (real_T)c6_g_k;
    c6_e_a = c6_d_et;
    c6_g_b = c6_S[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c6_h_k), 1, 4, 1, 0) + (((int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c6_h_k), 1,
      4, 2, 0) - 1) << 2)) - 1];
    c6_d_et = c6_e_a * c6_g_b;
  }

  c6_isodd = FALSE;
  for (c6_i_k = 0; c6_i_k < 3; c6_i_k++) {
    c6_h_k = 1.0 + (real_T)c6_i_k;
    c6_f_a = c6_ipiv[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c6_h_k), 1, 4, 1, 0) - 1];
    c6_h_b = c6_h_k;
    c6_g_a = c6_f_a;
    c6_i_b = c6_h_b;
    c6_idx = c6_g_a;
    c6_flt = c6_i_b;
    c6_p = ((real_T)c6_idx > c6_flt);
    if (c6_p) {
      c6_isodd = !c6_isodd;
    }
  }

  if (c6_isodd) {
    c6_d_et = -c6_d_et;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i51 = 0; c6_i51 < 24; c6_i51++) {
    (*c6_b_J_PI)[c6_i51] = c6_J_PI[c6_i51];
  }

  *c6_b_S_a = c6_S_a;
  *c6_b_d_et = c6_d_et;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc6_SIMULACIO_MGD(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_d_et, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_d_et), &c6_thisId);
  sf_mex_destroy(&c6_d_et);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_d_et;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_d_et = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_d_et), &c6_thisId);
  sf_mex_destroy(&c6_d_et);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i52;
  int32_T c6_i53;
  int32_T c6_i54;
  real_T c6_b_inData[24];
  int32_T c6_i55;
  int32_T c6_i56;
  int32_T c6_i57;
  real_T c6_u[24];
  const mxArray *c6_y = NULL;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i52 = 0;
  for (c6_i53 = 0; c6_i53 < 6; c6_i53++) {
    for (c6_i54 = 0; c6_i54 < 4; c6_i54++) {
      c6_b_inData[c6_i54 + c6_i52] = (*(real_T (*)[24])c6_inData)[c6_i54 +
        c6_i52];
    }

    c6_i52 += 4;
  }

  c6_i55 = 0;
  for (c6_i56 = 0; c6_i56 < 6; c6_i56++) {
    for (c6_i57 = 0; c6_i57 < 4; c6_i57++) {
      c6_u[c6_i57 + c6_i55] = c6_b_inData[c6_i57 + c6_i55];
    }

    c6_i55 += 4;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 4, 6), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_J_PI, const char_T *c6_identifier, real_T
  c6_y[24])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_J_PI), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_J_PI);
}

static void c6_d_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[24])
{
  real_T c6_dv6[24];
  int32_T c6_i58;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv6, 1, 0, 0U, 1, 0U, 2, 4, 6);
  for (c6_i58 = 0; c6_i58 < 24; c6_i58++) {
    c6_y[c6_i58] = c6_dv6[c6_i58];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_J_PI;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[24];
  int32_T c6_i59;
  int32_T c6_i60;
  int32_T c6_i61;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_J_PI = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_J_PI), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_J_PI);
  c6_i59 = 0;
  for (c6_i60 = 0; c6_i60 < 6; c6_i60++) {
    for (c6_i61 = 0; c6_i61 < 4; c6_i61++) {
      (*(real_T (*)[24])c6_outData)[c6_i61 + c6_i59] = c6_y[c6_i61 + c6_i59];
    }

    c6_i59 += 4;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i62;
  int32_T c6_i63;
  int32_T c6_i64;
  real_T c6_b_inData[24];
  int32_T c6_i65;
  int32_T c6_i66;
  int32_T c6_i67;
  real_T c6_u[24];
  const mxArray *c6_y = NULL;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i62 = 0;
  for (c6_i63 = 0; c6_i63 < 4; c6_i63++) {
    for (c6_i64 = 0; c6_i64 < 6; c6_i64++) {
      c6_b_inData[c6_i64 + c6_i62] = (*(real_T (*)[24])c6_inData)[c6_i64 +
        c6_i62];
    }

    c6_i62 += 6;
  }

  c6_i65 = 0;
  for (c6_i66 = 0; c6_i66 < 4; c6_i66++) {
    for (c6_i67 = 0; c6_i67 < 6; c6_i67++) {
      c6_u[c6_i67 + c6_i65] = c6_b_inData[c6_i67 + c6_i65];
    }

    c6_i65 += 6;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 6, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i68;
  int32_T c6_i69;
  int32_T c6_i70;
  real_T c6_b_inData[16];
  int32_T c6_i71;
  int32_T c6_i72;
  int32_T c6_i73;
  real_T c6_u[16];
  const mxArray *c6_y = NULL;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i68 = 0;
  for (c6_i69 = 0; c6_i69 < 4; c6_i69++) {
    for (c6_i70 = 0; c6_i70 < 4; c6_i70++) {
      c6_b_inData[c6_i70 + c6_i68] = (*(real_T (*)[16])c6_inData)[c6_i70 +
        c6_i68];
    }

    c6_i68 += 4;
  }

  c6_i71 = 0;
  for (c6_i72 = 0; c6_i72 < 4; c6_i72++) {
    for (c6_i73 = 0; c6_i73 < 4; c6_i73++) {
      c6_u[c6_i73 + c6_i71] = c6_b_inData[c6_i73 + c6_i71];
    }

    c6_i71 += 4;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_e_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[16])
{
  real_T c6_dv7[16];
  int32_T c6_i74;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv7, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c6_i74 = 0; c6_i74 < 16; c6_i74++) {
    c6_y[c6_i74] = c6_dv7[c6_i74];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Sa;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[16];
  int32_T c6_i75;
  int32_T c6_i76;
  int32_T c6_i77;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_Sa = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Sa), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_Sa);
  c6_i75 = 0;
  for (c6_i76 = 0; c6_i76 < 4; c6_i76++) {
    for (c6_i77 = 0; c6_i77 < 4; c6_i77++) {
      (*(real_T (*)[16])c6_outData)[c6_i77 + c6_i75] = c6_y[c6_i77 + c6_i75];
    }

    c6_i75 += 4;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_SIMULACIO_MGD_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[260];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i78;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  c6_b_info_helper(c6_info);
  c6_c_info_helper(c6_info);
  c6_d_info_helper(c6_info);
  c6_e_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 260), FALSE);
  for (c6_i78 = 0; c6_i78 < 260; c6_i78++) {
    c6_r0 = &c6_info[c6_i78];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i78);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i78);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i78);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i78);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i78);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i78);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i78);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i78);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[260])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileTimeLo = 1289519692U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[1].name = "eml_index_class";
  c6_info[1].dominantType = "";
  c6_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[1].fileTimeLo = 1323170578U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[2].name = "eml_scalar_eg";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[2].fileTimeLo = 1286818796U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[3].name = "eml_xgemm";
  c6_info[3].dominantType = "char";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[3].fileTimeLo = 1299076772U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[4].name = "eml_blas_inline";
  c6_info[4].dominantType = "";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[4].fileTimeLo = 1299076768U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c6_info[5].name = "mtimes";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[5].fileTimeLo = 1289519692U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[6].name = "eml_index_class";
  c6_info[6].dominantType = "";
  c6_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[6].fileTimeLo = 1323170578U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[7].name = "eml_scalar_eg";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[7].fileTimeLo = 1286818796U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[8].name = "eml_refblas_xgemm";
  c6_info[8].dominantType = "char";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[8].fileTimeLo = 1299076774U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context = "";
  c6_info[9].name = "eye";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c6_info[9].fileTimeLo = 1286818688U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[10].name = "eml_assert_valid_size_arg";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[10].fileTimeLo = 1286818694U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c6_info[11].name = "isinf";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c6_info[11].fileTimeLo = 1286818760U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c6_info[12].name = "mtimes";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[12].fileTimeLo = 1289519692U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[13].name = "eml_index_class";
  c6_info[13].dominantType = "";
  c6_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[13].fileTimeLo = 1323170578U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[14].name = "intmax";
  c6_info[14].dominantType = "char";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[14].fileTimeLo = 1311255316U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[15].name = "eml_is_float_class";
  c6_info[15].dominantType = "char";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c6_info[15].fileTimeLo = 1286818782U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[16].name = "min";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[16].fileTimeLo = 1311255318U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[17].name = "eml_min_or_max";
  c6_info[17].dominantType = "char";
  c6_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[17].fileTimeLo = 1334071490U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[18].name = "eml_scalar_eg";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[18].fileTimeLo = 1286818796U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[19].name = "eml_scalexp_alloc";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[19].fileTimeLo = 1352424860U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[20].name = "eml_index_class";
  c6_info[20].dominantType = "";
  c6_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[20].fileTimeLo = 1323170578U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c6_info[21].name = "eml_scalar_eg";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[21].fileTimeLo = 1286818796U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[22].name = "eml_index_class";
  c6_info[22].dominantType = "";
  c6_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[22].fileTimeLo = 1323170578U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 0U;
  c6_info[22].mFileTimeHi = 0U;
  c6_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c6_info[23].name = "eml_int_forloop_overflow_check";
  c6_info[23].dominantType = "";
  c6_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[23].fileTimeLo = 1346510340U;
  c6_info[23].fileTimeHi = 0U;
  c6_info[23].mFileTimeLo = 0U;
  c6_info[23].mFileTimeHi = 0U;
  c6_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c6_info[24].name = "intmax";
  c6_info[24].dominantType = "char";
  c6_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[24].fileTimeLo = 1311255316U;
  c6_info[24].fileTimeHi = 0U;
  c6_info[24].mFileTimeLo = 0U;
  c6_info[24].mFileTimeHi = 0U;
  c6_info[25].context = "";
  c6_info[25].name = "mldivide";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c6_info[25].fileTimeLo = 1357951548U;
  c6_info[25].fileTimeHi = 0U;
  c6_info[25].mFileTimeLo = 1319729966U;
  c6_info[25].mFileTimeHi = 0U;
  c6_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c6_info[26].name = "eml_lusolve";
  c6_info[26].dominantType = "double";
  c6_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c6_info[26].fileTimeLo = 1309451196U;
  c6_info[26].fileTimeHi = 0U;
  c6_info[26].mFileTimeLo = 0U;
  c6_info[26].mFileTimeHi = 0U;
  c6_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c6_info[27].name = "eml_index_class";
  c6_info[27].dominantType = "";
  c6_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[27].fileTimeLo = 1323170578U;
  c6_info[27].fileTimeHi = 0U;
  c6_info[27].mFileTimeLo = 0U;
  c6_info[27].mFileTimeHi = 0U;
  c6_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c6_info[28].name = "eml_index_class";
  c6_info[28].dominantType = "";
  c6_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[28].fileTimeLo = 1323170578U;
  c6_info[28].fileTimeHi = 0U;
  c6_info[28].mFileTimeLo = 0U;
  c6_info[28].mFileTimeHi = 0U;
  c6_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c6_info[29].name = "eml_xgetrf";
  c6_info[29].dominantType = "double";
  c6_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c6_info[29].fileTimeLo = 1286818806U;
  c6_info[29].fileTimeHi = 0U;
  c6_info[29].mFileTimeLo = 0U;
  c6_info[29].mFileTimeHi = 0U;
  c6_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c6_info[30].name = "eml_lapack_xgetrf";
  c6_info[30].dominantType = "double";
  c6_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c6_info[30].fileTimeLo = 1286818810U;
  c6_info[30].fileTimeHi = 0U;
  c6_info[30].mFileTimeLo = 0U;
  c6_info[30].mFileTimeHi = 0U;
  c6_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c6_info[31].name = "eml_matlab_zgetrf";
  c6_info[31].dominantType = "double";
  c6_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[31].fileTimeLo = 1302688994U;
  c6_info[31].fileTimeHi = 0U;
  c6_info[31].mFileTimeLo = 0U;
  c6_info[31].mFileTimeHi = 0U;
  c6_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[32].name = "realmin";
  c6_info[32].dominantType = "char";
  c6_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c6_info[32].fileTimeLo = 1307651242U;
  c6_info[32].fileTimeHi = 0U;
  c6_info[32].mFileTimeLo = 0U;
  c6_info[32].mFileTimeHi = 0U;
  c6_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c6_info[33].name = "eml_realmin";
  c6_info[33].dominantType = "char";
  c6_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c6_info[33].fileTimeLo = 1307651244U;
  c6_info[33].fileTimeHi = 0U;
  c6_info[33].mFileTimeLo = 0U;
  c6_info[33].mFileTimeHi = 0U;
  c6_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c6_info[34].name = "eml_float_model";
  c6_info[34].dominantType = "char";
  c6_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[34].fileTimeLo = 1326727996U;
  c6_info[34].fileTimeHi = 0U;
  c6_info[34].mFileTimeLo = 0U;
  c6_info[34].mFileTimeHi = 0U;
  c6_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[35].name = "eps";
  c6_info[35].dominantType = "char";
  c6_info[35].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[35].fileTimeLo = 1326727996U;
  c6_info[35].fileTimeHi = 0U;
  c6_info[35].mFileTimeLo = 0U;
  c6_info[35].mFileTimeHi = 0U;
  c6_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[36].name = "eml_is_float_class";
  c6_info[36].dominantType = "char";
  c6_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c6_info[36].fileTimeLo = 1286818782U;
  c6_info[36].fileTimeHi = 0U;
  c6_info[36].mFileTimeLo = 0U;
  c6_info[36].mFileTimeHi = 0U;
  c6_info[37].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[37].name = "eml_eps";
  c6_info[37].dominantType = "char";
  c6_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c6_info[37].fileTimeLo = 1326727996U;
  c6_info[37].fileTimeHi = 0U;
  c6_info[37].mFileTimeLo = 0U;
  c6_info[37].mFileTimeHi = 0U;
  c6_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c6_info[38].name = "eml_float_model";
  c6_info[38].dominantType = "char";
  c6_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[38].fileTimeLo = 1326727996U;
  c6_info[38].fileTimeHi = 0U;
  c6_info[38].mFileTimeLo = 0U;
  c6_info[38].mFileTimeHi = 0U;
  c6_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[39].name = "min";
  c6_info[39].dominantType = "coder.internal.indexInt";
  c6_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[39].fileTimeLo = 1311255318U;
  c6_info[39].fileTimeHi = 0U;
  c6_info[39].mFileTimeLo = 0U;
  c6_info[39].mFileTimeHi = 0U;
  c6_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[40].name = "eml_scalar_eg";
  c6_info[40].dominantType = "coder.internal.indexInt";
  c6_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[40].fileTimeLo = 1286818796U;
  c6_info[40].fileTimeHi = 0U;
  c6_info[40].mFileTimeLo = 0U;
  c6_info[40].mFileTimeHi = 0U;
  c6_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[41].name = "eml_scalexp_alloc";
  c6_info[41].dominantType = "coder.internal.indexInt";
  c6_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[41].fileTimeLo = 1352424860U;
  c6_info[41].fileTimeHi = 0U;
  c6_info[41].mFileTimeLo = 0U;
  c6_info[41].mFileTimeHi = 0U;
  c6_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c6_info[42].name = "eml_scalar_eg";
  c6_info[42].dominantType = "coder.internal.indexInt";
  c6_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[42].fileTimeLo = 1286818796U;
  c6_info[42].fileTimeHi = 0U;
  c6_info[42].mFileTimeLo = 0U;
  c6_info[42].mFileTimeHi = 0U;
  c6_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[43].name = "colon";
  c6_info[43].dominantType = "double";
  c6_info[43].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[43].fileTimeLo = 1348191928U;
  c6_info[43].fileTimeHi = 0U;
  c6_info[43].mFileTimeLo = 0U;
  c6_info[43].mFileTimeHi = 0U;
  c6_info[44].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[44].name = "colon";
  c6_info[44].dominantType = "double";
  c6_info[44].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[44].fileTimeLo = 1348191928U;
  c6_info[44].fileTimeHi = 0U;
  c6_info[44].mFileTimeLo = 0U;
  c6_info[44].mFileTimeHi = 0U;
  c6_info[45].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[45].name = "floor";
  c6_info[45].dominantType = "double";
  c6_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[45].fileTimeLo = 1343830380U;
  c6_info[45].fileTimeHi = 0U;
  c6_info[45].mFileTimeLo = 0U;
  c6_info[45].mFileTimeHi = 0U;
  c6_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[46].name = "eml_scalar_floor";
  c6_info[46].dominantType = "double";
  c6_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[46].fileTimeLo = 1286818726U;
  c6_info[46].fileTimeHi = 0U;
  c6_info[46].mFileTimeLo = 0U;
  c6_info[46].mFileTimeHi = 0U;
  c6_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c6_info[47].name = "intmin";
  c6_info[47].dominantType = "char";
  c6_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c6_info[47].fileTimeLo = 1311255318U;
  c6_info[47].fileTimeHi = 0U;
  c6_info[47].mFileTimeLo = 0U;
  c6_info[47].mFileTimeHi = 0U;
  c6_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c6_info[48].name = "intmax";
  c6_info[48].dominantType = "char";
  c6_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[48].fileTimeLo = 1311255316U;
  c6_info[48].fileTimeHi = 0U;
  c6_info[48].mFileTimeLo = 0U;
  c6_info[48].mFileTimeHi = 0U;
  c6_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c6_info[49].name = "intmin";
  c6_info[49].dominantType = "char";
  c6_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c6_info[49].fileTimeLo = 1311255318U;
  c6_info[49].fileTimeHi = 0U;
  c6_info[49].mFileTimeLo = 0U;
  c6_info[49].mFileTimeHi = 0U;
  c6_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c6_info[50].name = "intmax";
  c6_info[50].dominantType = "char";
  c6_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[50].fileTimeLo = 1311255316U;
  c6_info[50].fileTimeHi = 0U;
  c6_info[50].mFileTimeLo = 0U;
  c6_info[50].mFileTimeHi = 0U;
  c6_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c6_info[51].name = "eml_isa_uint";
  c6_info[51].dominantType = "coder.internal.indexInt";
  c6_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c6_info[51].fileTimeLo = 1286818784U;
  c6_info[51].fileTimeHi = 0U;
  c6_info[51].mFileTimeLo = 0U;
  c6_info[51].mFileTimeHi = 0U;
  c6_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c6_info[52].name = "eml_unsigned_class";
  c6_info[52].dominantType = "char";
  c6_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c6_info[52].fileTimeLo = 1323170580U;
  c6_info[52].fileTimeHi = 0U;
  c6_info[52].mFileTimeLo = 0U;
  c6_info[52].mFileTimeHi = 0U;
  c6_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c6_info[53].name = "eml_index_class";
  c6_info[53].dominantType = "";
  c6_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[53].fileTimeLo = 1323170578U;
  c6_info[53].fileTimeHi = 0U;
  c6_info[53].mFileTimeLo = 0U;
  c6_info[53].mFileTimeHi = 0U;
  c6_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c6_info[54].name = "eml_index_class";
  c6_info[54].dominantType = "";
  c6_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[54].fileTimeLo = 1323170578U;
  c6_info[54].fileTimeHi = 0U;
  c6_info[54].mFileTimeLo = 0U;
  c6_info[54].mFileTimeHi = 0U;
  c6_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c6_info[55].name = "intmax";
  c6_info[55].dominantType = "char";
  c6_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[55].fileTimeLo = 1311255316U;
  c6_info[55].fileTimeHi = 0U;
  c6_info[55].mFileTimeLo = 0U;
  c6_info[55].mFileTimeHi = 0U;
  c6_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c6_info[56].name = "eml_isa_uint";
  c6_info[56].dominantType = "coder.internal.indexInt";
  c6_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c6_info[56].fileTimeLo = 1286818784U;
  c6_info[56].fileTimeHi = 0U;
  c6_info[56].mFileTimeLo = 0U;
  c6_info[56].mFileTimeHi = 0U;
  c6_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c6_info[57].name = "eml_index_plus";
  c6_info[57].dominantType = "double";
  c6_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[57].fileTimeLo = 1286818778U;
  c6_info[57].fileTimeHi = 0U;
  c6_info[57].mFileTimeLo = 0U;
  c6_info[57].mFileTimeHi = 0U;
  c6_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[58].name = "eml_index_class";
  c6_info[58].dominantType = "";
  c6_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[58].fileTimeLo = 1323170578U;
  c6_info[58].fileTimeHi = 0U;
  c6_info[58].mFileTimeLo = 0U;
  c6_info[58].mFileTimeHi = 0U;
  c6_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c6_info[59].name = "eml_int_forloop_overflow_check";
  c6_info[59].dominantType = "";
  c6_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[59].fileTimeLo = 1346510340U;
  c6_info[59].fileTimeHi = 0U;
  c6_info[59].mFileTimeLo = 0U;
  c6_info[59].mFileTimeHi = 0U;
  c6_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[60].name = "eml_index_class";
  c6_info[60].dominantType = "";
  c6_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[60].fileTimeLo = 1323170578U;
  c6_info[60].fileTimeHi = 0U;
  c6_info[60].mFileTimeLo = 0U;
  c6_info[60].mFileTimeHi = 0U;
  c6_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[61].name = "eml_index_plus";
  c6_info[61].dominantType = "double";
  c6_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[61].fileTimeLo = 1286818778U;
  c6_info[61].fileTimeHi = 0U;
  c6_info[61].mFileTimeLo = 0U;
  c6_info[61].mFileTimeHi = 0U;
  c6_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[62].name = "eml_int_forloop_overflow_check";
  c6_info[62].dominantType = "";
  c6_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[62].fileTimeLo = 1346510340U;
  c6_info[62].fileTimeHi = 0U;
  c6_info[62].mFileTimeLo = 0U;
  c6_info[62].mFileTimeHi = 0U;
  c6_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[63].name = "eml_index_minus";
  c6_info[63].dominantType = "double";
  c6_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[63].fileTimeLo = 1286818778U;
  c6_info[63].fileTimeHi = 0U;
  c6_info[63].mFileTimeLo = 0U;
  c6_info[63].mFileTimeHi = 0U;
}

static void c6_b_info_helper(c6_ResolvedFunctionInfo c6_info[260])
{
  c6_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[64].name = "eml_index_class";
  c6_info[64].dominantType = "";
  c6_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[64].fileTimeLo = 1323170578U;
  c6_info[64].fileTimeHi = 0U;
  c6_info[64].mFileTimeLo = 0U;
  c6_info[64].mFileTimeHi = 0U;
  c6_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[65].name = "eml_index_minus";
  c6_info[65].dominantType = "coder.internal.indexInt";
  c6_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[65].fileTimeLo = 1286818778U;
  c6_info[65].fileTimeHi = 0U;
  c6_info[65].mFileTimeLo = 0U;
  c6_info[65].mFileTimeHi = 0U;
  c6_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[66].name = "eml_index_times";
  c6_info[66].dominantType = "coder.internal.indexInt";
  c6_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[66].fileTimeLo = 1286818780U;
  c6_info[66].fileTimeHi = 0U;
  c6_info[66].mFileTimeLo = 0U;
  c6_info[66].mFileTimeHi = 0U;
  c6_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[67].name = "eml_index_class";
  c6_info[67].dominantType = "";
  c6_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[67].fileTimeLo = 1323170578U;
  c6_info[67].fileTimeHi = 0U;
  c6_info[67].mFileTimeLo = 0U;
  c6_info[67].mFileTimeHi = 0U;
  c6_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[68].name = "eml_index_plus";
  c6_info[68].dominantType = "coder.internal.indexInt";
  c6_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[68].fileTimeLo = 1286818778U;
  c6_info[68].fileTimeHi = 0U;
  c6_info[68].mFileTimeLo = 0U;
  c6_info[68].mFileTimeHi = 0U;
  c6_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[69].name = "eml_ixamax";
  c6_info[69].dominantType = "double";
  c6_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c6_info[69].fileTimeLo = 1299076770U;
  c6_info[69].fileTimeHi = 0U;
  c6_info[69].mFileTimeLo = 0U;
  c6_info[69].mFileTimeHi = 0U;
  c6_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c6_info[70].name = "eml_blas_inline";
  c6_info[70].dominantType = "";
  c6_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[70].fileTimeLo = 1299076768U;
  c6_info[70].fileTimeHi = 0U;
  c6_info[70].mFileTimeLo = 0U;
  c6_info[70].mFileTimeHi = 0U;
  c6_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c6_info[71].name = "length";
  c6_info[71].dominantType = "double";
  c6_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[71].fileTimeLo = 1303146206U;
  c6_info[71].fileTimeHi = 0U;
  c6_info[71].mFileTimeLo = 0U;
  c6_info[71].mFileTimeHi = 0U;
  c6_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c6_info[72].name = "eml_index_class";
  c6_info[72].dominantType = "";
  c6_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[72].fileTimeLo = 1323170578U;
  c6_info[72].fileTimeHi = 0U;
  c6_info[72].mFileTimeLo = 0U;
  c6_info[72].mFileTimeHi = 0U;
  c6_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c6_info[73].name = "eml_index_class";
  c6_info[73].dominantType = "";
  c6_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[73].fileTimeLo = 1323170578U;
  c6_info[73].fileTimeHi = 0U;
  c6_info[73].mFileTimeLo = 0U;
  c6_info[73].mFileTimeHi = 0U;
  c6_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c6_info[74].name = "eml_refblas_ixamax";
  c6_info[74].dominantType = "double";
  c6_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c6_info[74].fileTimeLo = 1299076770U;
  c6_info[74].fileTimeHi = 0U;
  c6_info[74].mFileTimeLo = 0U;
  c6_info[74].mFileTimeHi = 0U;
  c6_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c6_info[75].name = "eml_index_class";
  c6_info[75].dominantType = "";
  c6_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[75].fileTimeLo = 1323170578U;
  c6_info[75].fileTimeHi = 0U;
  c6_info[75].mFileTimeLo = 0U;
  c6_info[75].mFileTimeHi = 0U;
  c6_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c6_info[76].name = "eml_xcabs1";
  c6_info[76].dominantType = "double";
  c6_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c6_info[76].fileTimeLo = 1286818706U;
  c6_info[76].fileTimeHi = 0U;
  c6_info[76].mFileTimeLo = 0U;
  c6_info[76].mFileTimeHi = 0U;
  c6_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c6_info[77].name = "abs";
  c6_info[77].dominantType = "double";
  c6_info[77].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[77].fileTimeLo = 1343830366U;
  c6_info[77].fileTimeHi = 0U;
  c6_info[77].mFileTimeLo = 0U;
  c6_info[77].mFileTimeHi = 0U;
  c6_info[78].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[78].name = "eml_scalar_abs";
  c6_info[78].dominantType = "double";
  c6_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[78].fileTimeLo = 1286818712U;
  c6_info[78].fileTimeHi = 0U;
  c6_info[78].mFileTimeLo = 0U;
  c6_info[78].mFileTimeHi = 0U;
  c6_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c6_info[79].name = "eml_int_forloop_overflow_check";
  c6_info[79].dominantType = "";
  c6_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[79].fileTimeLo = 1346510340U;
  c6_info[79].fileTimeHi = 0U;
  c6_info[79].mFileTimeLo = 0U;
  c6_info[79].mFileTimeHi = 0U;
  c6_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c6_info[80].name = "eml_index_plus";
  c6_info[80].dominantType = "coder.internal.indexInt";
  c6_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[80].fileTimeLo = 1286818778U;
  c6_info[80].fileTimeHi = 0U;
  c6_info[80].mFileTimeLo = 0U;
  c6_info[80].mFileTimeHi = 0U;
  c6_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[81].name = "eml_xswap";
  c6_info[81].dominantType = "double";
  c6_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c6_info[81].fileTimeLo = 1299076778U;
  c6_info[81].fileTimeHi = 0U;
  c6_info[81].mFileTimeLo = 0U;
  c6_info[81].mFileTimeHi = 0U;
  c6_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c6_info[82].name = "eml_blas_inline";
  c6_info[82].dominantType = "";
  c6_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[82].fileTimeLo = 1299076768U;
  c6_info[82].fileTimeHi = 0U;
  c6_info[82].mFileTimeLo = 0U;
  c6_info[82].mFileTimeHi = 0U;
  c6_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c6_info[83].name = "eml_index_class";
  c6_info[83].dominantType = "";
  c6_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[83].fileTimeLo = 1323170578U;
  c6_info[83].fileTimeHi = 0U;
  c6_info[83].mFileTimeLo = 0U;
  c6_info[83].mFileTimeHi = 0U;
  c6_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c6_info[84].name = "eml_refblas_xswap";
  c6_info[84].dominantType = "double";
  c6_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c6_info[84].fileTimeLo = 1299076786U;
  c6_info[84].fileTimeHi = 0U;
  c6_info[84].mFileTimeLo = 0U;
  c6_info[84].mFileTimeHi = 0U;
  c6_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c6_info[85].name = "eml_index_class";
  c6_info[85].dominantType = "";
  c6_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[85].fileTimeLo = 1323170578U;
  c6_info[85].fileTimeHi = 0U;
  c6_info[85].mFileTimeLo = 0U;
  c6_info[85].mFileTimeHi = 0U;
  c6_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c6_info[86].name = "abs";
  c6_info[86].dominantType = "coder.internal.indexInt";
  c6_info[86].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[86].fileTimeLo = 1343830366U;
  c6_info[86].fileTimeHi = 0U;
  c6_info[86].mFileTimeLo = 0U;
  c6_info[86].mFileTimeHi = 0U;
  c6_info[87].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[87].name = "eml_scalar_abs";
  c6_info[87].dominantType = "coder.internal.indexInt";
  c6_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[87].fileTimeLo = 1286818712U;
  c6_info[87].fileTimeHi = 0U;
  c6_info[87].mFileTimeLo = 0U;
  c6_info[87].mFileTimeHi = 0U;
  c6_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c6_info[88].name = "eml_int_forloop_overflow_check";
  c6_info[88].dominantType = "";
  c6_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[88].fileTimeLo = 1346510340U;
  c6_info[88].fileTimeHi = 0U;
  c6_info[88].mFileTimeLo = 0U;
  c6_info[88].mFileTimeHi = 0U;
  c6_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c6_info[89].name = "eml_index_plus";
  c6_info[89].dominantType = "coder.internal.indexInt";
  c6_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[89].fileTimeLo = 1286818778U;
  c6_info[89].fileTimeHi = 0U;
  c6_info[89].mFileTimeLo = 0U;
  c6_info[89].mFileTimeHi = 0U;
  c6_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[90].name = "eml_div";
  c6_info[90].dominantType = "double";
  c6_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[90].fileTimeLo = 1313347810U;
  c6_info[90].fileTimeHi = 0U;
  c6_info[90].mFileTimeLo = 0U;
  c6_info[90].mFileTimeHi = 0U;
  c6_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c6_info[91].name = "eml_xgeru";
  c6_info[91].dominantType = "double";
  c6_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c6_info[91].fileTimeLo = 1299076774U;
  c6_info[91].fileTimeHi = 0U;
  c6_info[91].mFileTimeLo = 0U;
  c6_info[91].mFileTimeHi = 0U;
  c6_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c6_info[92].name = "eml_blas_inline";
  c6_info[92].dominantType = "";
  c6_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[92].fileTimeLo = 1299076768U;
  c6_info[92].fileTimeHi = 0U;
  c6_info[92].mFileTimeLo = 0U;
  c6_info[92].mFileTimeHi = 0U;
  c6_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c6_info[93].name = "eml_xger";
  c6_info[93].dominantType = "double";
  c6_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c6_info[93].fileTimeLo = 1299076774U;
  c6_info[93].fileTimeHi = 0U;
  c6_info[93].mFileTimeLo = 0U;
  c6_info[93].mFileTimeHi = 0U;
  c6_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c6_info[94].name = "eml_blas_inline";
  c6_info[94].dominantType = "";
  c6_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[94].fileTimeLo = 1299076768U;
  c6_info[94].fileTimeHi = 0U;
  c6_info[94].mFileTimeLo = 0U;
  c6_info[94].mFileTimeHi = 0U;
  c6_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c6_info[95].name = "intmax";
  c6_info[95].dominantType = "char";
  c6_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[95].fileTimeLo = 1311255316U;
  c6_info[95].fileTimeHi = 0U;
  c6_info[95].mFileTimeLo = 0U;
  c6_info[95].mFileTimeHi = 0U;
  c6_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c6_info[96].name = "min";
  c6_info[96].dominantType = "double";
  c6_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[96].fileTimeLo = 1311255318U;
  c6_info[96].fileTimeHi = 0U;
  c6_info[96].mFileTimeLo = 0U;
  c6_info[96].mFileTimeHi = 0U;
  c6_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c6_info[97].name = "mtimes";
  c6_info[97].dominantType = "double";
  c6_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[97].fileTimeLo = 1289519692U;
  c6_info[97].fileTimeHi = 0U;
  c6_info[97].mFileTimeLo = 0U;
  c6_info[97].mFileTimeHi = 0U;
  c6_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c6_info[98].name = "eml_index_class";
  c6_info[98].dominantType = "";
  c6_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[98].fileTimeLo = 1323170578U;
  c6_info[98].fileTimeHi = 0U;
  c6_info[98].mFileTimeLo = 0U;
  c6_info[98].mFileTimeHi = 0U;
  c6_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c6_info[99].name = "eml_refblas_xger";
  c6_info[99].dominantType = "double";
  c6_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c6_info[99].fileTimeLo = 1299076776U;
  c6_info[99].fileTimeHi = 0U;
  c6_info[99].mFileTimeLo = 0U;
  c6_info[99].mFileTimeHi = 0U;
  c6_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c6_info[100].name = "eml_refblas_xgerx";
  c6_info[100].dominantType = "char";
  c6_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[100].fileTimeLo = 1299076778U;
  c6_info[100].fileTimeHi = 0U;
  c6_info[100].mFileTimeLo = 0U;
  c6_info[100].mFileTimeHi = 0U;
  c6_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[101].name = "eml_index_class";
  c6_info[101].dominantType = "";
  c6_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[101].fileTimeLo = 1323170578U;
  c6_info[101].fileTimeHi = 0U;
  c6_info[101].mFileTimeLo = 0U;
  c6_info[101].mFileTimeHi = 0U;
  c6_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[102].name = "abs";
  c6_info[102].dominantType = "coder.internal.indexInt";
  c6_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[102].fileTimeLo = 1343830366U;
  c6_info[102].fileTimeHi = 0U;
  c6_info[102].mFileTimeLo = 0U;
  c6_info[102].mFileTimeHi = 0U;
  c6_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[103].name = "eml_index_minus";
  c6_info[103].dominantType = "double";
  c6_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[103].fileTimeLo = 1286818778U;
  c6_info[103].fileTimeHi = 0U;
  c6_info[103].mFileTimeLo = 0U;
  c6_info[103].mFileTimeHi = 0U;
  c6_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[104].name = "eml_int_forloop_overflow_check";
  c6_info[104].dominantType = "";
  c6_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[104].fileTimeLo = 1346510340U;
  c6_info[104].fileTimeHi = 0U;
  c6_info[104].mFileTimeLo = 0U;
  c6_info[104].mFileTimeHi = 0U;
  c6_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[105].name = "eml_index_plus";
  c6_info[105].dominantType = "double";
  c6_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[105].fileTimeLo = 1286818778U;
  c6_info[105].fileTimeHi = 0U;
  c6_info[105].mFileTimeLo = 0U;
  c6_info[105].mFileTimeHi = 0U;
  c6_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[106].name = "eml_index_plus";
  c6_info[106].dominantType = "coder.internal.indexInt";
  c6_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[106].fileTimeLo = 1286818778U;
  c6_info[106].fileTimeHi = 0U;
  c6_info[106].mFileTimeLo = 0U;
  c6_info[106].mFileTimeHi = 0U;
  c6_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c6_info[107].name = "eml_warning";
  c6_info[107].dominantType = "char";
  c6_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c6_info[107].fileTimeLo = 1286818802U;
  c6_info[107].fileTimeHi = 0U;
  c6_info[107].mFileTimeLo = 0U;
  c6_info[107].mFileTimeHi = 0U;
  c6_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c6_info[108].name = "eml_scalar_eg";
  c6_info[108].dominantType = "double";
  c6_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[108].fileTimeLo = 1286818796U;
  c6_info[108].fileTimeHi = 0U;
  c6_info[108].mFileTimeLo = 0U;
  c6_info[108].mFileTimeHi = 0U;
  c6_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c6_info[109].name = "eml_int_forloop_overflow_check";
  c6_info[109].dominantType = "";
  c6_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[109].fileTimeLo = 1346510340U;
  c6_info[109].fileTimeHi = 0U;
  c6_info[109].mFileTimeLo = 0U;
  c6_info[109].mFileTimeHi = 0U;
  c6_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c6_info[110].name = "eml_xtrsm";
  c6_info[110].dominantType = "char";
  c6_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c6_info[110].fileTimeLo = 1299076778U;
  c6_info[110].fileTimeHi = 0U;
  c6_info[110].mFileTimeLo = 0U;
  c6_info[110].mFileTimeHi = 0U;
  c6_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c6_info[111].name = "eml_blas_inline";
  c6_info[111].dominantType = "";
  c6_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[111].fileTimeLo = 1299076768U;
  c6_info[111].fileTimeHi = 0U;
  c6_info[111].mFileTimeLo = 0U;
  c6_info[111].mFileTimeHi = 0U;
  c6_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c6_info[112].name = "mtimes";
  c6_info[112].dominantType = "double";
  c6_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[112].fileTimeLo = 1289519692U;
  c6_info[112].fileTimeHi = 0U;
  c6_info[112].mFileTimeLo = 0U;
  c6_info[112].mFileTimeHi = 0U;
  c6_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c6_info[113].name = "eml_index_class";
  c6_info[113].dominantType = "";
  c6_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[113].fileTimeLo = 1323170578U;
  c6_info[113].fileTimeHi = 0U;
  c6_info[113].mFileTimeLo = 0U;
  c6_info[113].mFileTimeHi = 0U;
  c6_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c6_info[114].name = "eml_scalar_eg";
  c6_info[114].dominantType = "double";
  c6_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[114].fileTimeLo = 1286818796U;
  c6_info[114].fileTimeHi = 0U;
  c6_info[114].mFileTimeLo = 0U;
  c6_info[114].mFileTimeHi = 0U;
  c6_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c6_info[115].name = "eml_refblas_xtrsm";
  c6_info[115].dominantType = "char";
  c6_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[115].fileTimeLo = 1299076786U;
  c6_info[115].fileTimeHi = 0U;
  c6_info[115].mFileTimeLo = 0U;
  c6_info[115].mFileTimeHi = 0U;
  c6_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[116].name = "eml_scalar_eg";
  c6_info[116].dominantType = "double";
  c6_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[116].fileTimeLo = 1286818796U;
  c6_info[116].fileTimeHi = 0U;
  c6_info[116].mFileTimeLo = 0U;
  c6_info[116].mFileTimeHi = 0U;
  c6_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[117].name = "eml_index_minus";
  c6_info[117].dominantType = "double";
  c6_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[117].fileTimeLo = 1286818778U;
  c6_info[117].fileTimeHi = 0U;
  c6_info[117].mFileTimeLo = 0U;
  c6_info[117].mFileTimeHi = 0U;
  c6_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[118].name = "eml_index_class";
  c6_info[118].dominantType = "";
  c6_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[118].fileTimeLo = 1323170578U;
  c6_info[118].fileTimeHi = 0U;
  c6_info[118].mFileTimeLo = 0U;
  c6_info[118].mFileTimeHi = 0U;
  c6_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[119].name = "eml_int_forloop_overflow_check";
  c6_info[119].dominantType = "";
  c6_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[119].fileTimeLo = 1346510340U;
  c6_info[119].fileTimeHi = 0U;
  c6_info[119].mFileTimeLo = 0U;
  c6_info[119].mFileTimeHi = 0U;
  c6_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[120].name = "eml_index_times";
  c6_info[120].dominantType = "coder.internal.indexInt";
  c6_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[120].fileTimeLo = 1286818780U;
  c6_info[120].fileTimeHi = 0U;
  c6_info[120].mFileTimeLo = 0U;
  c6_info[120].mFileTimeHi = 0U;
  c6_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[121].name = "eml_index_plus";
  c6_info[121].dominantType = "coder.internal.indexInt";
  c6_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[121].fileTimeLo = 1286818778U;
  c6_info[121].fileTimeHi = 0U;
  c6_info[121].mFileTimeLo = 0U;
  c6_info[121].mFileTimeHi = 0U;
  c6_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[122].name = "eml_index_plus";
  c6_info[122].dominantType = "double";
  c6_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[122].fileTimeLo = 1286818778U;
  c6_info[122].fileTimeHi = 0U;
  c6_info[122].mFileTimeLo = 0U;
  c6_info[122].mFileTimeHi = 0U;
  c6_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c6_info[123].name = "intmin";
  c6_info[123].dominantType = "char";
  c6_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c6_info[123].fileTimeLo = 1311255318U;
  c6_info[123].fileTimeHi = 0U;
  c6_info[123].mFileTimeLo = 0U;
  c6_info[123].mFileTimeHi = 0U;
  c6_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[124].name = "eml_div";
  c6_info[124].dominantType = "double";
  c6_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[124].fileTimeLo = 1313347810U;
  c6_info[124].fileTimeHi = 0U;
  c6_info[124].mFileTimeLo = 0U;
  c6_info[124].mFileTimeHi = 0U;
  c6_info[125].context = "";
  c6_info[125].name = "pinv";
  c6_info[125].dominantType = "double";
  c6_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m";
  c6_info[125].fileTimeLo = 1286818828U;
  c6_info[125].fileTimeHi = 0U;
  c6_info[125].mFileTimeLo = 0U;
  c6_info[125].mFileTimeHi = 0U;
  c6_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[126].name = "eml_index_class";
  c6_info[126].dominantType = "";
  c6_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[126].fileTimeLo = 1323170578U;
  c6_info[126].fileTimeHi = 0U;
  c6_info[126].mFileTimeLo = 0U;
  c6_info[126].mFileTimeHi = 0U;
  c6_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[127].name = "eml_scalar_eg";
  c6_info[127].dominantType = "double";
  c6_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[127].fileTimeLo = 1286818796U;
  c6_info[127].fileTimeHi = 0U;
  c6_info[127].mFileTimeLo = 0U;
  c6_info[127].mFileTimeHi = 0U;
}

static void c6_c_info_helper(c6_ResolvedFunctionInfo c6_info[260])
{
  c6_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[128].name = "svd";
  c6_info[128].dominantType = "double";
  c6_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c6_info[128].fileTimeLo = 1286818832U;
  c6_info[128].fileTimeHi = 0U;
  c6_info[128].mFileTimeLo = 0U;
  c6_info[128].mFileTimeHi = 0U;
  c6_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c6_info[129].name = "eml_index_class";
  c6_info[129].dominantType = "";
  c6_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[129].fileTimeLo = 1323170578U;
  c6_info[129].fileTimeHi = 0U;
  c6_info[129].mFileTimeLo = 0U;
  c6_info[129].mFileTimeHi = 0U;
  c6_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c6_info[130].name = "eml_int_forloop_overflow_check";
  c6_info[130].dominantType = "";
  c6_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[130].fileTimeLo = 1346510340U;
  c6_info[130].fileTimeHi = 0U;
  c6_info[130].mFileTimeLo = 0U;
  c6_info[130].mFileTimeHi = 0U;
  c6_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c6_info[131].name = "isfinite";
  c6_info[131].dominantType = "double";
  c6_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[131].fileTimeLo = 1286818758U;
  c6_info[131].fileTimeHi = 0U;
  c6_info[131].mFileTimeLo = 0U;
  c6_info[131].mFileTimeHi = 0U;
  c6_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[132].name = "isinf";
  c6_info[132].dominantType = "double";
  c6_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c6_info[132].fileTimeLo = 1286818760U;
  c6_info[132].fileTimeHi = 0U;
  c6_info[132].mFileTimeLo = 0U;
  c6_info[132].mFileTimeHi = 0U;
  c6_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[133].name = "isnan";
  c6_info[133].dominantType = "double";
  c6_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[133].fileTimeLo = 1286818760U;
  c6_info[133].fileTimeHi = 0U;
  c6_info[133].mFileTimeLo = 0U;
  c6_info[133].mFileTimeHi = 0U;
  c6_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c6_info[134].name = "eml_error";
  c6_info[134].dominantType = "char";
  c6_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[134].fileTimeLo = 1343830358U;
  c6_info[134].fileTimeHi = 0U;
  c6_info[134].mFileTimeLo = 0U;
  c6_info[134].mFileTimeHi = 0U;
  c6_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c6_info[135].name = "eml_xgesvd";
  c6_info[135].dominantType = "double";
  c6_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c6_info[135].fileTimeLo = 1286818806U;
  c6_info[135].fileTimeHi = 0U;
  c6_info[135].mFileTimeLo = 0U;
  c6_info[135].mFileTimeHi = 0U;
  c6_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c6_info[136].name = "eml_lapack_xgesvd";
  c6_info[136].dominantType = "double";
  c6_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c6_info[136].fileTimeLo = 1286818810U;
  c6_info[136].fileTimeHi = 0U;
  c6_info[136].mFileTimeLo = 0U;
  c6_info[136].mFileTimeHi = 0U;
  c6_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c6_info[137].name = "eml_matlab_zsvdc";
  c6_info[137].dominantType = "double";
  c6_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[137].fileTimeLo = 1295284866U;
  c6_info[137].fileTimeHi = 0U;
  c6_info[137].mFileTimeLo = 0U;
  c6_info[137].mFileTimeHi = 0U;
  c6_info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[138].name = "eml_index_class";
  c6_info[138].dominantType = "";
  c6_info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[138].fileTimeLo = 1323170578U;
  c6_info[138].fileTimeHi = 0U;
  c6_info[138].mFileTimeLo = 0U;
  c6_info[138].mFileTimeHi = 0U;
  c6_info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[139].name = "eml_scalar_eg";
  c6_info[139].dominantType = "double";
  c6_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[139].fileTimeLo = 1286818796U;
  c6_info[139].fileTimeHi = 0U;
  c6_info[139].mFileTimeLo = 0U;
  c6_info[139].mFileTimeHi = 0U;
  c6_info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[140].name = "eml_index_plus";
  c6_info[140].dominantType = "double";
  c6_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[140].fileTimeLo = 1286818778U;
  c6_info[140].fileTimeHi = 0U;
  c6_info[140].mFileTimeLo = 0U;
  c6_info[140].mFileTimeHi = 0U;
  c6_info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[141].name = "min";
  c6_info[141].dominantType = "coder.internal.indexInt";
  c6_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[141].fileTimeLo = 1311255318U;
  c6_info[141].fileTimeHi = 0U;
  c6_info[141].mFileTimeLo = 0U;
  c6_info[141].mFileTimeHi = 0U;
  c6_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[142].name = "max";
  c6_info[142].dominantType = "double";
  c6_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c6_info[142].fileTimeLo = 1311255316U;
  c6_info[142].fileTimeHi = 0U;
  c6_info[142].mFileTimeLo = 0U;
  c6_info[142].mFileTimeHi = 0U;
  c6_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c6_info[143].name = "eml_min_or_max";
  c6_info[143].dominantType = "char";
  c6_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[143].fileTimeLo = 1334071490U;
  c6_info[143].fileTimeHi = 0U;
  c6_info[143].mFileTimeLo = 0U;
  c6_info[143].mFileTimeHi = 0U;
  c6_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c6_info[144].name = "eml_relop";
  c6_info[144].dominantType = "function_handle";
  c6_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c6_info[144].fileTimeLo = 1342451182U;
  c6_info[144].fileTimeHi = 0U;
  c6_info[144].mFileTimeLo = 0U;
  c6_info[144].mFileTimeHi = 0U;
  c6_info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c6_info[145].name = "coder.internal.indexIntRelop";
  c6_info[145].dominantType = "";
  c6_info[145].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c6_info[145].fileTimeLo = 1326728322U;
  c6_info[145].fileTimeHi = 0U;
  c6_info[145].mFileTimeLo = 0U;
  c6_info[145].mFileTimeHi = 0U;
  c6_info[146].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c6_info[146].name = "eml_float_model";
  c6_info[146].dominantType = "char";
  c6_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c6_info[146].fileTimeLo = 1326727996U;
  c6_info[146].fileTimeHi = 0U;
  c6_info[146].mFileTimeLo = 0U;
  c6_info[146].mFileTimeHi = 0U;
  c6_info[147].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c6_info[147].name = "intmin";
  c6_info[147].dominantType = "char";
  c6_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c6_info[147].fileTimeLo = 1311255318U;
  c6_info[147].fileTimeHi = 0U;
  c6_info[147].mFileTimeLo = 0U;
  c6_info[147].mFileTimeHi = 0U;
  c6_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c6_info[148].name = "isnan";
  c6_info[148].dominantType = "coder.internal.indexInt";
  c6_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[148].fileTimeLo = 1286818760U;
  c6_info[148].fileTimeHi = 0U;
  c6_info[148].mFileTimeLo = 0U;
  c6_info[148].mFileTimeHi = 0U;
  c6_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[149].name = "eml_index_minus";
  c6_info[149].dominantType = "double";
  c6_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[149].fileTimeLo = 1286818778U;
  c6_info[149].fileTimeHi = 0U;
  c6_info[149].mFileTimeLo = 0U;
  c6_info[149].mFileTimeHi = 0U;
  c6_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[150].name = "max";
  c6_info[150].dominantType = "coder.internal.indexInt";
  c6_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c6_info[150].fileTimeLo = 1311255316U;
  c6_info[150].fileTimeHi = 0U;
  c6_info[150].mFileTimeLo = 0U;
  c6_info[150].mFileTimeHi = 0U;
  c6_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[151].name = "eml_int_forloop_overflow_check";
  c6_info[151].dominantType = "";
  c6_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[151].fileTimeLo = 1346510340U;
  c6_info[151].fileTimeHi = 0U;
  c6_info[151].mFileTimeLo = 0U;
  c6_info[151].mFileTimeHi = 0U;
  c6_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[152].name = "eml_index_times";
  c6_info[152].dominantType = "coder.internal.indexInt";
  c6_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[152].fileTimeLo = 1286818780U;
  c6_info[152].fileTimeHi = 0U;
  c6_info[152].mFileTimeLo = 0U;
  c6_info[152].mFileTimeHi = 0U;
  c6_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[153].name = "eml_index_plus";
  c6_info[153].dominantType = "coder.internal.indexInt";
  c6_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[153].fileTimeLo = 1286818778U;
  c6_info[153].fileTimeHi = 0U;
  c6_info[153].mFileTimeLo = 0U;
  c6_info[153].mFileTimeHi = 0U;
  c6_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[154].name = "eml_index_minus";
  c6_info[154].dominantType = "coder.internal.indexInt";
  c6_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[154].fileTimeLo = 1286818778U;
  c6_info[154].fileTimeHi = 0U;
  c6_info[154].mFileTimeLo = 0U;
  c6_info[154].mFileTimeHi = 0U;
  c6_info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[155].name = "eml_xnrm2";
  c6_info[155].dominantType = "double";
  c6_info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c6_info[155].fileTimeLo = 1299076776U;
  c6_info[155].fileTimeHi = 0U;
  c6_info[155].mFileTimeLo = 0U;
  c6_info[155].mFileTimeHi = 0U;
  c6_info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c6_info[156].name = "eml_blas_inline";
  c6_info[156].dominantType = "";
  c6_info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[156].fileTimeLo = 1299076768U;
  c6_info[156].fileTimeHi = 0U;
  c6_info[156].mFileTimeLo = 0U;
  c6_info[156].mFileTimeHi = 0U;
  c6_info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c6_info[157].name = "length";
  c6_info[157].dominantType = "double";
  c6_info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[157].fileTimeLo = 1303146206U;
  c6_info[157].fileTimeHi = 0U;
  c6_info[157].mFileTimeLo = 0U;
  c6_info[157].mFileTimeHi = 0U;
  c6_info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c6_info[158].name = "eml_index_class";
  c6_info[158].dominantType = "";
  c6_info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[158].fileTimeLo = 1323170578U;
  c6_info[158].fileTimeHi = 0U;
  c6_info[158].mFileTimeLo = 0U;
  c6_info[158].mFileTimeHi = 0U;
  c6_info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c6_info[159].name = "eml_refblas_xnrm2";
  c6_info[159].dominantType = "double";
  c6_info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[159].fileTimeLo = 1299076784U;
  c6_info[159].fileTimeHi = 0U;
  c6_info[159].mFileTimeLo = 0U;
  c6_info[159].mFileTimeHi = 0U;
  c6_info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[160].name = "abs";
  c6_info[160].dominantType = "double";
  c6_info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[160].fileTimeLo = 1343830366U;
  c6_info[160].fileTimeHi = 0U;
  c6_info[160].mFileTimeLo = 0U;
  c6_info[160].mFileTimeHi = 0U;
  c6_info[161].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[161].name = "realmin";
  c6_info[161].dominantType = "char";
  c6_info[161].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c6_info[161].fileTimeLo = 1307651242U;
  c6_info[161].fileTimeHi = 0U;
  c6_info[161].mFileTimeLo = 0U;
  c6_info[161].mFileTimeHi = 0U;
  c6_info[162].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[162].name = "eml_index_class";
  c6_info[162].dominantType = "";
  c6_info[162].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[162].fileTimeLo = 1323170578U;
  c6_info[162].fileTimeHi = 0U;
  c6_info[162].mFileTimeLo = 0U;
  c6_info[162].mFileTimeHi = 0U;
  c6_info[163].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[163].name = "eml_index_minus";
  c6_info[163].dominantType = "double";
  c6_info[163].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[163].fileTimeLo = 1286818778U;
  c6_info[163].fileTimeHi = 0U;
  c6_info[163].mFileTimeLo = 0U;
  c6_info[163].mFileTimeHi = 0U;
  c6_info[164].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[164].name = "eml_index_times";
  c6_info[164].dominantType = "coder.internal.indexInt";
  c6_info[164].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[164].fileTimeLo = 1286818780U;
  c6_info[164].fileTimeHi = 0U;
  c6_info[164].mFileTimeLo = 0U;
  c6_info[164].mFileTimeHi = 0U;
  c6_info[165].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[165].name = "eml_index_plus";
  c6_info[165].dominantType = "coder.internal.indexInt";
  c6_info[165].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[165].fileTimeLo = 1286818778U;
  c6_info[165].fileTimeHi = 0U;
  c6_info[165].mFileTimeLo = 0U;
  c6_info[165].mFileTimeHi = 0U;
  c6_info[166].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[166].name = "eml_int_forloop_overflow_check";
  c6_info[166].dominantType = "";
  c6_info[166].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[166].fileTimeLo = 1346510340U;
  c6_info[166].fileTimeHi = 0U;
  c6_info[166].mFileTimeLo = 0U;
  c6_info[166].mFileTimeHi = 0U;
  c6_info[167].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[167].name = "eml_div";
  c6_info[167].dominantType = "double";
  c6_info[167].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[167].fileTimeLo = 1313347810U;
  c6_info[167].fileTimeHi = 0U;
  c6_info[167].mFileTimeLo = 0U;
  c6_info[167].mFileTimeHi = 0U;
  c6_info[168].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[168].name = "eml_xscal";
  c6_info[168].dominantType = "double";
  c6_info[168].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c6_info[168].fileTimeLo = 1299076776U;
  c6_info[168].fileTimeHi = 0U;
  c6_info[168].mFileTimeLo = 0U;
  c6_info[168].mFileTimeHi = 0U;
  c6_info[169].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c6_info[169].name = "eml_blas_inline";
  c6_info[169].dominantType = "";
  c6_info[169].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[169].fileTimeLo = 1299076768U;
  c6_info[169].fileTimeHi = 0U;
  c6_info[169].mFileTimeLo = 0U;
  c6_info[169].mFileTimeHi = 0U;
  c6_info[170].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold";
  c6_info[170].name = "length";
  c6_info[170].dominantType = "double";
  c6_info[170].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[170].fileTimeLo = 1303146206U;
  c6_info[170].fileTimeHi = 0U;
  c6_info[170].mFileTimeLo = 0U;
  c6_info[170].mFileTimeHi = 0U;
  c6_info[171].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c6_info[171].name = "eml_index_class";
  c6_info[171].dominantType = "";
  c6_info[171].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[171].fileTimeLo = 1323170578U;
  c6_info[171].fileTimeHi = 0U;
  c6_info[171].mFileTimeLo = 0U;
  c6_info[171].mFileTimeHi = 0U;
  c6_info[172].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c6_info[172].name = "eml_scalar_eg";
  c6_info[172].dominantType = "double";
  c6_info[172].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[172].fileTimeLo = 1286818796U;
  c6_info[172].fileTimeHi = 0U;
  c6_info[172].mFileTimeLo = 0U;
  c6_info[172].mFileTimeHi = 0U;
  c6_info[173].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c6_info[173].name = "eml_refblas_xscal";
  c6_info[173].dominantType = "double";
  c6_info[173].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c6_info[173].fileTimeLo = 1299076784U;
  c6_info[173].fileTimeHi = 0U;
  c6_info[173].mFileTimeLo = 0U;
  c6_info[173].mFileTimeHi = 0U;
  c6_info[174].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c6_info[174].name = "eml_index_class";
  c6_info[174].dominantType = "";
  c6_info[174].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[174].fileTimeLo = 1323170578U;
  c6_info[174].fileTimeHi = 0U;
  c6_info[174].mFileTimeLo = 0U;
  c6_info[174].mFileTimeHi = 0U;
  c6_info[175].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c6_info[175].name = "eml_index_minus";
  c6_info[175].dominantType = "double";
  c6_info[175].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[175].fileTimeLo = 1286818778U;
  c6_info[175].fileTimeHi = 0U;
  c6_info[175].mFileTimeLo = 0U;
  c6_info[175].mFileTimeHi = 0U;
  c6_info[176].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c6_info[176].name = "eml_index_times";
  c6_info[176].dominantType = "coder.internal.indexInt";
  c6_info[176].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[176].fileTimeLo = 1286818780U;
  c6_info[176].fileTimeHi = 0U;
  c6_info[176].mFileTimeLo = 0U;
  c6_info[176].mFileTimeHi = 0U;
  c6_info[177].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c6_info[177].name = "eml_index_plus";
  c6_info[177].dominantType = "coder.internal.indexInt";
  c6_info[177].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[177].fileTimeLo = 1286818778U;
  c6_info[177].fileTimeHi = 0U;
  c6_info[177].mFileTimeLo = 0U;
  c6_info[177].mFileTimeHi = 0U;
  c6_info[178].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c6_info[178].name = "eml_int_forloop_overflow_check";
  c6_info[178].dominantType = "";
  c6_info[178].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[178].fileTimeLo = 1346510340U;
  c6_info[178].fileTimeHi = 0U;
  c6_info[178].mFileTimeLo = 0U;
  c6_info[178].mFileTimeHi = 0U;
  c6_info[179].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[179].name = "eml_xdotc";
  c6_info[179].dominantType = "double";
  c6_info[179].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c6_info[179].fileTimeLo = 1299076772U;
  c6_info[179].fileTimeHi = 0U;
  c6_info[179].mFileTimeLo = 0U;
  c6_info[179].mFileTimeHi = 0U;
  c6_info[180].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c6_info[180].name = "eml_blas_inline";
  c6_info[180].dominantType = "";
  c6_info[180].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[180].fileTimeLo = 1299076768U;
  c6_info[180].fileTimeHi = 0U;
  c6_info[180].mFileTimeLo = 0U;
  c6_info[180].mFileTimeHi = 0U;
  c6_info[181].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c6_info[181].name = "eml_xdot";
  c6_info[181].dominantType = "double";
  c6_info[181].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c6_info[181].fileTimeLo = 1299076772U;
  c6_info[181].fileTimeHi = 0U;
  c6_info[181].mFileTimeLo = 0U;
  c6_info[181].mFileTimeHi = 0U;
  c6_info[182].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c6_info[182].name = "eml_blas_inline";
  c6_info[182].dominantType = "";
  c6_info[182].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[182].fileTimeLo = 1299076768U;
  c6_info[182].fileTimeHi = 0U;
  c6_info[182].mFileTimeLo = 0U;
  c6_info[182].mFileTimeHi = 0U;
  c6_info[183].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c6_info[183].name = "length";
  c6_info[183].dominantType = "double";
  c6_info[183].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[183].fileTimeLo = 1303146206U;
  c6_info[183].fileTimeHi = 0U;
  c6_info[183].mFileTimeLo = 0U;
  c6_info[183].mFileTimeHi = 0U;
  c6_info[184].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c6_info[184].name = "eml_index_class";
  c6_info[184].dominantType = "";
  c6_info[184].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[184].fileTimeLo = 1323170578U;
  c6_info[184].fileTimeHi = 0U;
  c6_info[184].mFileTimeLo = 0U;
  c6_info[184].mFileTimeHi = 0U;
  c6_info[185].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c6_info[185].name = "eml_refblas_xdot";
  c6_info[185].dominantType = "double";
  c6_info[185].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c6_info[185].fileTimeLo = 1299076772U;
  c6_info[185].fileTimeHi = 0U;
  c6_info[185].mFileTimeLo = 0U;
  c6_info[185].mFileTimeHi = 0U;
  c6_info[186].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c6_info[186].name = "eml_refblas_xdotx";
  c6_info[186].dominantType = "char";
  c6_info[186].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[186].fileTimeLo = 1299076774U;
  c6_info[186].fileTimeHi = 0U;
  c6_info[186].mFileTimeLo = 0U;
  c6_info[186].mFileTimeHi = 0U;
  c6_info[187].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[187].name = "eml_scalar_eg";
  c6_info[187].dominantType = "double";
  c6_info[187].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[187].fileTimeLo = 1286818796U;
  c6_info[187].fileTimeHi = 0U;
  c6_info[187].mFileTimeLo = 0U;
  c6_info[187].mFileTimeHi = 0U;
  c6_info[188].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[188].name = "eml_index_class";
  c6_info[188].dominantType = "";
  c6_info[188].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[188].fileTimeLo = 1323170578U;
  c6_info[188].fileTimeHi = 0U;
  c6_info[188].mFileTimeLo = 0U;
  c6_info[188].mFileTimeHi = 0U;
  c6_info[189].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[189].name = "eml_int_forloop_overflow_check";
  c6_info[189].dominantType = "";
  c6_info[189].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[189].fileTimeLo = 1346510340U;
  c6_info[189].fileTimeHi = 0U;
  c6_info[189].mFileTimeLo = 0U;
  c6_info[189].mFileTimeHi = 0U;
  c6_info[190].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[190].name = "eml_index_plus";
  c6_info[190].dominantType = "coder.internal.indexInt";
  c6_info[190].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[190].fileTimeLo = 1286818778U;
  c6_info[190].fileTimeHi = 0U;
  c6_info[190].mFileTimeLo = 0U;
  c6_info[190].mFileTimeHi = 0U;
  c6_info[191].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[191].name = "eml_xaxpy";
  c6_info[191].dominantType = "double";
  c6_info[191].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c6_info[191].fileTimeLo = 1299076770U;
  c6_info[191].fileTimeHi = 0U;
  c6_info[191].mFileTimeLo = 0U;
  c6_info[191].mFileTimeHi = 0U;
}

static void c6_d_info_helper(c6_ResolvedFunctionInfo c6_info[260])
{
  c6_info[192].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c6_info[192].name = "eml_blas_inline";
  c6_info[192].dominantType = "";
  c6_info[192].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[192].fileTimeLo = 1299076768U;
  c6_info[192].fileTimeHi = 0U;
  c6_info[192].mFileTimeLo = 0U;
  c6_info[192].mFileTimeHi = 0U;
  c6_info[193].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m!below_threshold";
  c6_info[193].name = "length";
  c6_info[193].dominantType = "double";
  c6_info[193].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[193].fileTimeLo = 1303146206U;
  c6_info[193].fileTimeHi = 0U;
  c6_info[193].mFileTimeLo = 0U;
  c6_info[193].mFileTimeHi = 0U;
  c6_info[194].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c6_info[194].name = "eml_index_class";
  c6_info[194].dominantType = "";
  c6_info[194].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[194].fileTimeLo = 1323170578U;
  c6_info[194].fileTimeHi = 0U;
  c6_info[194].mFileTimeLo = 0U;
  c6_info[194].mFileTimeHi = 0U;
  c6_info[195].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c6_info[195].name = "eml_scalar_eg";
  c6_info[195].dominantType = "double";
  c6_info[195].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[195].fileTimeLo = 1286818796U;
  c6_info[195].fileTimeHi = 0U;
  c6_info[195].mFileTimeLo = 0U;
  c6_info[195].mFileTimeHi = 0U;
  c6_info[196].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c6_info[196].name = "eml_refblas_xaxpy";
  c6_info[196].dominantType = "double";
  c6_info[196].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c6_info[196].fileTimeLo = 1299076772U;
  c6_info[196].fileTimeHi = 0U;
  c6_info[196].mFileTimeLo = 0U;
  c6_info[196].mFileTimeHi = 0U;
  c6_info[197].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c6_info[197].name = "eml_index_class";
  c6_info[197].dominantType = "";
  c6_info[197].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[197].fileTimeLo = 1323170578U;
  c6_info[197].fileTimeHi = 0U;
  c6_info[197].mFileTimeLo = 0U;
  c6_info[197].mFileTimeHi = 0U;
  c6_info[198].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c6_info[198].name = "eml_isa_uint";
  c6_info[198].dominantType = "coder.internal.indexInt";
  c6_info[198].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c6_info[198].fileTimeLo = 1286818784U;
  c6_info[198].fileTimeHi = 0U;
  c6_info[198].mFileTimeLo = 0U;
  c6_info[198].mFileTimeHi = 0U;
  c6_info[199].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c6_info[199].name = "eml_index_minus";
  c6_info[199].dominantType = "double";
  c6_info[199].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[199].fileTimeLo = 1286818778U;
  c6_info[199].fileTimeHi = 0U;
  c6_info[199].mFileTimeLo = 0U;
  c6_info[199].mFileTimeHi = 0U;
  c6_info[200].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c6_info[200].name = "eml_int_forloop_overflow_check";
  c6_info[200].dominantType = "";
  c6_info[200].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[200].fileTimeLo = 1346510340U;
  c6_info[200].fileTimeHi = 0U;
  c6_info[200].mFileTimeLo = 0U;
  c6_info[200].mFileTimeHi = 0U;
  c6_info[201].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c6_info[201].name = "eml_index_plus";
  c6_info[201].dominantType = "double";
  c6_info[201].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[201].fileTimeLo = 1286818778U;
  c6_info[201].fileTimeHi = 0U;
  c6_info[201].mFileTimeLo = 0U;
  c6_info[201].mFileTimeHi = 0U;
  c6_info[202].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c6_info[202].name = "eml_index_plus";
  c6_info[202].dominantType = "coder.internal.indexInt";
  c6_info[202].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[202].fileTimeLo = 1286818778U;
  c6_info[202].fileTimeHi = 0U;
  c6_info[202].mFileTimeLo = 0U;
  c6_info[202].mFileTimeHi = 0U;
  c6_info[203].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[203].name = "abs";
  c6_info[203].dominantType = "double";
  c6_info[203].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[203].fileTimeLo = 1343830366U;
  c6_info[203].fileTimeHi = 0U;
  c6_info[203].mFileTimeLo = 0U;
  c6_info[203].mFileTimeHi = 0U;
  c6_info[204].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[204].name = "mtimes";
  c6_info[204].dominantType = "double";
  c6_info[204].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[204].fileTimeLo = 1289519692U;
  c6_info[204].fileTimeHi = 0U;
  c6_info[204].mFileTimeLo = 0U;
  c6_info[204].mFileTimeHi = 0U;
  c6_info[205].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[205].name = "realmin";
  c6_info[205].dominantType = "char";
  c6_info[205].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c6_info[205].fileTimeLo = 1307651242U;
  c6_info[205].fileTimeHi = 0U;
  c6_info[205].mFileTimeLo = 0U;
  c6_info[205].mFileTimeHi = 0U;
  c6_info[206].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[206].name = "eps";
  c6_info[206].dominantType = "char";
  c6_info[206].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[206].fileTimeLo = 1326727996U;
  c6_info[206].fileTimeHi = 0U;
  c6_info[206].mFileTimeLo = 0U;
  c6_info[206].mFileTimeHi = 0U;
  c6_info[207].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[207].name = "eml_error";
  c6_info[207].dominantType = "char";
  c6_info[207].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[207].fileTimeLo = 1343830358U;
  c6_info[207].fileTimeHi = 0U;
  c6_info[207].mFileTimeLo = 0U;
  c6_info[207].mFileTimeHi = 0U;
  c6_info[208].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c6_info[208].name = "eml_const_nonsingleton_dim";
  c6_info[208].dominantType = "double";
  c6_info[208].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c6_info[208].fileTimeLo = 1286818696U;
  c6_info[208].fileTimeHi = 0U;
  c6_info[208].mFileTimeLo = 0U;
  c6_info[208].mFileTimeHi = 0U;
  c6_info[209].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c6_info[209].name = "eml_scalar_eg";
  c6_info[209].dominantType = "double";
  c6_info[209].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[209].fileTimeLo = 1286818796U;
  c6_info[209].fileTimeHi = 0U;
  c6_info[209].mFileTimeLo = 0U;
  c6_info[209].mFileTimeHi = 0U;
  c6_info[210].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c6_info[210].name = "eml_index_class";
  c6_info[210].dominantType = "";
  c6_info[210].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[210].fileTimeLo = 1323170578U;
  c6_info[210].fileTimeHi = 0U;
  c6_info[210].mFileTimeLo = 0U;
  c6_info[210].mFileTimeHi = 0U;
  c6_info[211].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c6_info[211].name = "eml_index_class";
  c6_info[211].dominantType = "";
  c6_info[211].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[211].fileTimeLo = 1323170578U;
  c6_info[211].fileTimeHi = 0U;
  c6_info[211].mFileTimeLo = 0U;
  c6_info[211].mFileTimeHi = 0U;
  c6_info[212].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c6_info[212].name = "isnan";
  c6_info[212].dominantType = "double";
  c6_info[212].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[212].fileTimeLo = 1286818760U;
  c6_info[212].fileTimeHi = 0U;
  c6_info[212].mFileTimeLo = 0U;
  c6_info[212].mFileTimeHi = 0U;
  c6_info[213].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c6_info[213].name = "eml_index_plus";
  c6_info[213].dominantType = "coder.internal.indexInt";
  c6_info[213].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[213].fileTimeLo = 1286818778U;
  c6_info[213].fileTimeHi = 0U;
  c6_info[213].mFileTimeLo = 0U;
  c6_info[213].mFileTimeHi = 0U;
  c6_info[214].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c6_info[214].name = "eml_int_forloop_overflow_check";
  c6_info[214].dominantType = "";
  c6_info[214].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[214].fileTimeLo = 1346510340U;
  c6_info[214].fileTimeHi = 0U;
  c6_info[214].mFileTimeLo = 0U;
  c6_info[214].mFileTimeHi = 0U;
  c6_info[215].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c6_info[215].name = "eml_relop";
  c6_info[215].dominantType = "function_handle";
  c6_info[215].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c6_info[215].fileTimeLo = 1342451182U;
  c6_info[215].fileTimeHi = 0U;
  c6_info[215].mFileTimeLo = 0U;
  c6_info[215].mFileTimeHi = 0U;
  c6_info[216].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[216].name = "sqrt";
  c6_info[216].dominantType = "double";
  c6_info[216].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[216].fileTimeLo = 1343830386U;
  c6_info[216].fileTimeHi = 0U;
  c6_info[216].mFileTimeLo = 0U;
  c6_info[216].mFileTimeHi = 0U;
  c6_info[217].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[217].name = "eml_error";
  c6_info[217].dominantType = "char";
  c6_info[217].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[217].fileTimeLo = 1343830358U;
  c6_info[217].fileTimeHi = 0U;
  c6_info[217].mFileTimeLo = 0U;
  c6_info[217].mFileTimeHi = 0U;
  c6_info[218].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[218].name = "eml_scalar_sqrt";
  c6_info[218].dominantType = "double";
  c6_info[218].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c6_info[218].fileTimeLo = 1286818738U;
  c6_info[218].fileTimeHi = 0U;
  c6_info[218].mFileTimeLo = 0U;
  c6_info[218].mFileTimeHi = 0U;
  c6_info[219].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[219].name = "eml_xrotg";
  c6_info[219].dominantType = "double";
  c6_info[219].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c6_info[219].fileTimeLo = 1299076776U;
  c6_info[219].fileTimeHi = 0U;
  c6_info[219].mFileTimeLo = 0U;
  c6_info[219].mFileTimeHi = 0U;
  c6_info[220].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c6_info[220].name = "eml_blas_inline";
  c6_info[220].dominantType = "";
  c6_info[220].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[220].fileTimeLo = 1299076768U;
  c6_info[220].fileTimeHi = 0U;
  c6_info[220].mFileTimeLo = 0U;
  c6_info[220].mFileTimeHi = 0U;
  c6_info[221].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c6_info[221].name = "eml_refblas_xrotg";
  c6_info[221].dominantType = "double";
  c6_info[221].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c6_info[221].fileTimeLo = 1299076784U;
  c6_info[221].fileTimeHi = 0U;
  c6_info[221].mFileTimeLo = 0U;
  c6_info[221].mFileTimeHi = 0U;
  c6_info[222].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c6_info[222].name = "abs";
  c6_info[222].dominantType = "double";
  c6_info[222].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[222].fileTimeLo = 1343830366U;
  c6_info[222].fileTimeHi = 0U;
  c6_info[222].mFileTimeLo = 0U;
  c6_info[222].mFileTimeHi = 0U;
  c6_info[223].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c6_info[223].name = "mrdivide";
  c6_info[223].dominantType = "double";
  c6_info[223].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[223].fileTimeLo = 1357951548U;
  c6_info[223].fileTimeHi = 0U;
  c6_info[223].mFileTimeLo = 1319729966U;
  c6_info[223].mFileTimeHi = 0U;
  c6_info[224].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[224].name = "rdivide";
  c6_info[224].dominantType = "double";
  c6_info[224].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[224].fileTimeLo = 1346510388U;
  c6_info[224].fileTimeHi = 0U;
  c6_info[224].mFileTimeLo = 0U;
  c6_info[224].mFileTimeHi = 0U;
  c6_info[225].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[225].name = "eml_scalexp_compatible";
  c6_info[225].dominantType = "double";
  c6_info[225].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c6_info[225].fileTimeLo = 1286818796U;
  c6_info[225].fileTimeHi = 0U;
  c6_info[225].mFileTimeLo = 0U;
  c6_info[225].mFileTimeHi = 0U;
  c6_info[226].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[226].name = "eml_div";
  c6_info[226].dominantType = "double";
  c6_info[226].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[226].fileTimeLo = 1313347810U;
  c6_info[226].fileTimeHi = 0U;
  c6_info[226].mFileTimeLo = 0U;
  c6_info[226].mFileTimeHi = 0U;
  c6_info[227].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c6_info[227].name = "sqrt";
  c6_info[227].dominantType = "double";
  c6_info[227].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[227].fileTimeLo = 1343830386U;
  c6_info[227].fileTimeHi = 0U;
  c6_info[227].mFileTimeLo = 0U;
  c6_info[227].mFileTimeHi = 0U;
  c6_info[228].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m!eml_ceval_xrotg";
  c6_info[228].name = "eml_scalar_eg";
  c6_info[228].dominantType = "double";
  c6_info[228].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[228].fileTimeLo = 1286818796U;
  c6_info[228].fileTimeHi = 0U;
  c6_info[228].mFileTimeLo = 0U;
  c6_info[228].mFileTimeHi = 0U;
  c6_info[229].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[229].name = "eml_xrot";
  c6_info[229].dominantType = "double";
  c6_info[229].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c6_info[229].fileTimeLo = 1299076776U;
  c6_info[229].fileTimeHi = 0U;
  c6_info[229].mFileTimeLo = 0U;
  c6_info[229].mFileTimeHi = 0U;
  c6_info[230].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c6_info[230].name = "eml_blas_inline";
  c6_info[230].dominantType = "";
  c6_info[230].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[230].fileTimeLo = 1299076768U;
  c6_info[230].fileTimeHi = 0U;
  c6_info[230].mFileTimeLo = 0U;
  c6_info[230].mFileTimeHi = 0U;
  c6_info[231].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c6_info[231].name = "eml_index_class";
  c6_info[231].dominantType = "";
  c6_info[231].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[231].fileTimeLo = 1323170578U;
  c6_info[231].fileTimeHi = 0U;
  c6_info[231].mFileTimeLo = 0U;
  c6_info[231].mFileTimeHi = 0U;
  c6_info[232].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c6_info[232].name = "eml_scalar_eg";
  c6_info[232].dominantType = "double";
  c6_info[232].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[232].fileTimeLo = 1286818796U;
  c6_info[232].fileTimeHi = 0U;
  c6_info[232].mFileTimeLo = 0U;
  c6_info[232].mFileTimeHi = 0U;
  c6_info[233].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c6_info[233].name = "eml_refblas_xrot";
  c6_info[233].dominantType = "double";
  c6_info[233].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c6_info[233].fileTimeLo = 1299076784U;
  c6_info[233].fileTimeHi = 0U;
  c6_info[233].mFileTimeLo = 0U;
  c6_info[233].mFileTimeHi = 0U;
  c6_info[234].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c6_info[234].name = "eml_index_class";
  c6_info[234].dominantType = "";
  c6_info[234].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[234].fileTimeLo = 1323170578U;
  c6_info[234].fileTimeHi = 0U;
  c6_info[234].mFileTimeLo = 0U;
  c6_info[234].mFileTimeHi = 0U;
  c6_info[235].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c6_info[235].name = "eml_int_forloop_overflow_check";
  c6_info[235].dominantType = "";
  c6_info[235].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[235].fileTimeLo = 1346510340U;
  c6_info[235].fileTimeHi = 0U;
  c6_info[235].mFileTimeLo = 0U;
  c6_info[235].mFileTimeHi = 0U;
  c6_info[236].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c6_info[236].name = "mtimes";
  c6_info[236].dominantType = "double";
  c6_info[236].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[236].fileTimeLo = 1289519692U;
  c6_info[236].fileTimeHi = 0U;
  c6_info[236].mFileTimeLo = 0U;
  c6_info[236].mFileTimeHi = 0U;
  c6_info[237].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c6_info[237].name = "eml_index_plus";
  c6_info[237].dominantType = "coder.internal.indexInt";
  c6_info[237].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[237].fileTimeLo = 1286818778U;
  c6_info[237].fileTimeHi = 0U;
  c6_info[237].mFileTimeLo = 0U;
  c6_info[237].mFileTimeHi = 0U;
  c6_info[238].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c6_info[238].name = "eml_xswap";
  c6_info[238].dominantType = "double";
  c6_info[238].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c6_info[238].fileTimeLo = 1299076778U;
  c6_info[238].fileTimeHi = 0U;
  c6_info[238].mFileTimeLo = 0U;
  c6_info[238].mFileTimeHi = 0U;
  c6_info[239].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[239].name = "mtimes";
  c6_info[239].dominantType = "double";
  c6_info[239].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[239].fileTimeLo = 1289519692U;
  c6_info[239].fileTimeHi = 0U;
  c6_info[239].mFileTimeLo = 0U;
  c6_info[239].mFileTimeHi = 0U;
  c6_info[240].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[240].name = "eps";
  c6_info[240].dominantType = "char";
  c6_info[240].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[240].fileTimeLo = 1326727996U;
  c6_info[240].fileTimeHi = 0U;
  c6_info[240].mFileTimeLo = 0U;
  c6_info[240].mFileTimeHi = 0U;
  c6_info[241].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[241].name = "eml_int_forloop_overflow_check";
  c6_info[241].dominantType = "";
  c6_info[241].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[241].fileTimeLo = 1346510340U;
  c6_info[241].fileTimeHi = 0U;
  c6_info[241].mFileTimeLo = 0U;
  c6_info[241].mFileTimeHi = 0U;
  c6_info[242].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[242].name = "eml_index_plus";
  c6_info[242].dominantType = "double";
  c6_info[242].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[242].fileTimeLo = 1286818778U;
  c6_info[242].fileTimeHi = 0U;
  c6_info[242].mFileTimeLo = 0U;
  c6_info[242].mFileTimeHi = 0U;
  c6_info[243].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[243].name = "eml_div";
  c6_info[243].dominantType = "double";
  c6_info[243].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[243].fileTimeLo = 1313347810U;
  c6_info[243].fileTimeHi = 0U;
  c6_info[243].mFileTimeLo = 0U;
  c6_info[243].mFileTimeHi = 0U;
  c6_info[244].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[244].name = "eml_xscal";
  c6_info[244].dominantType = "double";
  c6_info[244].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c6_info[244].fileTimeLo = 1299076776U;
  c6_info[244].fileTimeHi = 0U;
  c6_info[244].mFileTimeLo = 0U;
  c6_info[244].mFileTimeHi = 0U;
  c6_info[245].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[245].name = "eml_index_plus";
  c6_info[245].dominantType = "coder.internal.indexInt";
  c6_info[245].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[245].fileTimeLo = 1286818778U;
  c6_info[245].fileTimeHi = 0U;
  c6_info[245].mFileTimeLo = 0U;
  c6_info[245].mFileTimeHi = 0U;
  c6_info[246].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c6_info[246].name = "eml_xgemm";
  c6_info[246].dominantType = "char";
  c6_info[246].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[246].fileTimeLo = 1299076772U;
  c6_info[246].fileTimeHi = 0U;
  c6_info[246].mFileTimeLo = 0U;
  c6_info[246].mFileTimeHi = 0U;
  c6_info[247].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c6_info[247].name = "min";
  c6_info[247].dominantType = "double";
  c6_info[247].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[247].fileTimeLo = 1311255318U;
  c6_info[247].fileTimeHi = 0U;
  c6_info[247].mFileTimeLo = 0U;
  c6_info[247].mFileTimeHi = 0U;
  c6_info[248].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[248].name = "eml_index_minus";
  c6_info[248].dominantType = "double";
  c6_info[248].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[248].fileTimeLo = 1286818778U;
  c6_info[248].fileTimeHi = 0U;
  c6_info[248].mFileTimeLo = 0U;
  c6_info[248].mFileTimeHi = 0U;
  c6_info[249].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[249].name = "eml_index_class";
  c6_info[249].dominantType = "";
  c6_info[249].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[249].fileTimeLo = 1323170578U;
  c6_info[249].fileTimeHi = 0U;
  c6_info[249].mFileTimeLo = 0U;
  c6_info[249].mFileTimeHi = 0U;
  c6_info[250].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[250].name = "eml_scalar_eg";
  c6_info[250].dominantType = "double";
  c6_info[250].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[250].fileTimeLo = 1286818796U;
  c6_info[250].fileTimeHi = 0U;
  c6_info[250].mFileTimeLo = 0U;
  c6_info[250].mFileTimeHi = 0U;
  c6_info[251].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[251].name = "eml_index_times";
  c6_info[251].dominantType = "coder.internal.indexInt";
  c6_info[251].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[251].fileTimeLo = 1286818780U;
  c6_info[251].fileTimeHi = 0U;
  c6_info[251].mFileTimeLo = 0U;
  c6_info[251].mFileTimeHi = 0U;
  c6_info[252].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[252].name = "eml_index_plus";
  c6_info[252].dominantType = "coder.internal.indexInt";
  c6_info[252].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[252].fileTimeLo = 1286818778U;
  c6_info[252].fileTimeHi = 0U;
  c6_info[252].mFileTimeLo = 0U;
  c6_info[252].mFileTimeHi = 0U;
  c6_info[253].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[253].name = "eml_int_forloop_overflow_check";
  c6_info[253].dominantType = "";
  c6_info[253].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c6_info[253].fileTimeLo = 1346510340U;
  c6_info[253].fileTimeHi = 0U;
  c6_info[253].mFileTimeLo = 0U;
  c6_info[253].mFileTimeHi = 0U;
  c6_info[254].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[254].name = "eml_index_plus";
  c6_info[254].dominantType = "double";
  c6_info[254].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[254].fileTimeLo = 1286818778U;
  c6_info[254].fileTimeHi = 0U;
  c6_info[254].mFileTimeLo = 0U;
  c6_info[254].mFileTimeHi = 0U;
  c6_info[255].context = "";
  c6_info[255].name = "det";
  c6_info[255].dominantType = "double";
  c6_info[255].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c6_info[255].fileTimeLo = 1286818822U;
  c6_info[255].fileTimeHi = 0U;
  c6_info[255].mFileTimeLo = 0U;
  c6_info[255].mFileTimeHi = 0U;
}

static void c6_e_info_helper(c6_ResolvedFunctionInfo c6_info[260])
{
  c6_info[256].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c6_info[256].name = "eml_index_class";
  c6_info[256].dominantType = "";
  c6_info[256].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[256].fileTimeLo = 1323170578U;
  c6_info[256].fileTimeHi = 0U;
  c6_info[256].mFileTimeLo = 0U;
  c6_info[256].mFileTimeHi = 0U;
  c6_info[257].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c6_info[257].name = "eml_xgetrf";
  c6_info[257].dominantType = "double";
  c6_info[257].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c6_info[257].fileTimeLo = 1286818806U;
  c6_info[257].fileTimeHi = 0U;
  c6_info[257].mFileTimeLo = 0U;
  c6_info[257].mFileTimeHi = 0U;
  c6_info[258].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c6_info[258].name = "mtimes";
  c6_info[258].dominantType = "double";
  c6_info[258].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[258].fileTimeLo = 1289519692U;
  c6_info[258].fileTimeHi = 0U;
  c6_info[258].mFileTimeLo = 0U;
  c6_info[258].mFileTimeHi = 0U;
  c6_info[259].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c6_info[259].name = "coder.internal.indexIntRelop";
  c6_info[259].dominantType = "";
  c6_info[259].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c6_info[259].fileTimeLo = 1326728322U;
  c6_info[259].fileTimeHi = 0U;
  c6_info[259].mFileTimeLo = 0U;
  c6_info[259].mFileTimeHi = 0U;
}

static void c6_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_b_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_c_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_mldivide(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_A[16], real_T c6_B[24], real_T c6_Y[24])
{
  int32_T c6_i79;
  real_T c6_b_A[16];
  int32_T c6_info;
  int32_T c6_ipiv[4];
  int32_T c6_b_info;
  int32_T c6_c_info;
  int32_T c6_d_info;
  int32_T c6_i80;
  int32_T c6_i;
  int32_T c6_b_i;
  int32_T c6_ip;
  int32_T c6_j;
  int32_T c6_b_j;
  real_T c6_temp;
  int32_T c6_i81;
  real_T c6_c_A[16];
  int32_T c6_i82;
  real_T c6_d_A[16];
  for (c6_i79 = 0; c6_i79 < 16; c6_i79++) {
    c6_b_A[c6_i79] = c6_A[c6_i79];
  }

  c6_b_eml_matlab_zgetrf(chartInstance, c6_b_A, c6_ipiv, &c6_info);
  c6_b_info = c6_info;
  c6_c_info = c6_b_info;
  c6_d_info = c6_c_info;
  if (c6_d_info > 0) {
    c6_eml_warning(chartInstance);
  }

  for (c6_i80 = 0; c6_i80 < 24; c6_i80++) {
    c6_Y[c6_i80] = c6_B[c6_i80];
  }

  for (c6_i = 1; c6_i < 5; c6_i++) {
    c6_b_i = c6_i;
    if (c6_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_i), 1, 4, 1, 0) - 1] != c6_b_i) {
      c6_ip = c6_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_b_i), 1, 4, 1, 0) - 1];
      for (c6_j = 1; c6_j < 7; c6_j++) {
        c6_b_j = c6_j;
        c6_temp = c6_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_i), 1, 4, 1, 0) +
                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 6, 2, 0) - 1) << 2)) - 1];
        c6_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 6, 2, 0) -
                1) << 2)) - 1] = c6_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_ip), 1, 4, 1, 0) +
          ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_j), 1, 6, 2, 0) - 1) << 2)) - 1];
        c6_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_ip), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 6, 2, 0) -
                1) << 2)) - 1] = c6_temp;
      }
    }
  }

  for (c6_i81 = 0; c6_i81 < 16; c6_i81++) {
    c6_c_A[c6_i81] = c6_b_A[c6_i81];
  }

  c6_c_eml_xtrsm(chartInstance, c6_c_A, c6_Y);
  for (c6_i82 = 0; c6_i82 < 16; c6_i82++) {
    c6_d_A[c6_i82] = c6_b_A[c6_i82];
  }

  c6_d_eml_xtrsm(chartInstance, c6_d_A, c6_Y);
}

static void c6_realmin(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_eps(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_eml_matlab_zgetrf(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_b_A[16], int32_T c6_ipiv[4], int32_T *c6_info)
{
  int32_T c6_i83;
  for (c6_i83 = 0; c6_i83 < 16; c6_i83++) {
    c6_b_A[c6_i83] = c6_A[c6_i83];
  }

  c6_b_eml_matlab_zgetrf(chartInstance, c6_b_A, c6_ipiv, c6_info);
}

static real_T c6_abs(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
                     c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  return muDoubleScalarAbs(c6_b_x);
}

static void c6_check_forloop_overflow_error(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, boolean_T c6_overflow)
{
  int32_T c6_i84;
  static char_T c6_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c6_u[34];
  const mxArray *c6_y = NULL;
  int32_T c6_i85;
  static char_T c6_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c6_b_u[23];
  const mxArray *c6_b_y = NULL;
  if (!c6_overflow) {
  } else {
    for (c6_i84 = 0; c6_i84 < 34; c6_i84++) {
      c6_u[c6_i84] = c6_cv0[c6_i84];
    }

    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c6_i85 = 0; c6_i85 < 23; c6_i85++) {
      c6_b_u[c6_i85] = c6_cv1[c6_i85];
    }

    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c6_y, 14, c6_b_y));
  }
}

static void c6_below_threshold(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static real_T c6_eml_div(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_x, real_T c6_y)
{
  return c6_x / c6_y;
}

static void c6_eml_xger(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, int32_T
  c6_m, int32_T c6_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0, real_T
  c6_A[16], int32_T c6_ia0, real_T c6_b_A[16])
{
  int32_T c6_i86;
  for (c6_i86 = 0; c6_i86 < 16; c6_i86++) {
    c6_b_A[c6_i86] = c6_A[c6_i86];
  }

  c6_b_eml_xger(chartInstance, c6_m, c6_n, c6_alpha1, c6_ix0, c6_iy0, c6_b_A,
                c6_ia0);
}

static void c6_eml_warning(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  int32_T c6_i87;
  static char_T c6_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c6_u[27];
  const mxArray *c6_y = NULL;
  for (c6_i87 = 0; c6_i87 < 27; c6_i87++) {
    c6_u[c6_i87] = c6_varargin_1[c6_i87];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c6_y));
}

static void c6_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_A[16], real_T c6_B[24], real_T c6_b_B[24])
{
  int32_T c6_i88;
  int32_T c6_i89;
  real_T c6_b_A[16];
  for (c6_i88 = 0; c6_i88 < 24; c6_i88++) {
    c6_b_B[c6_i88] = c6_B[c6_i88];
  }

  for (c6_i89 = 0; c6_i89 < 16; c6_i89++) {
    c6_b_A[c6_i89] = c6_A[c6_i89];
  }

  c6_c_eml_xtrsm(chartInstance, c6_b_A, c6_b_B);
}

static void c6_b_below_threshold(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_d_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_b_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_B[24], real_T c6_b_B[24])
{
  int32_T c6_i90;
  int32_T c6_i91;
  real_T c6_b_A[16];
  for (c6_i90 = 0; c6_i90 < 24; c6_i90++) {
    c6_b_B[c6_i90] = c6_B[c6_i90];
  }

  for (c6_i91 = 0; c6_i91 < 16; c6_i91++) {
    c6_b_A[c6_i91] = c6_A[c6_i91];
  }

  c6_d_eml_xtrsm(chartInstance, c6_b_A, c6_b_B);
}

static void c6_e_eml_scalar_eg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static void c6_eml_error(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  int32_T c6_i92;
  static char_T c6_cv2[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c6_u[33];
  const mxArray *c6_y = NULL;
  for (c6_i92 = 0; c6_i92 < 33; c6_i92++) {
    c6_u[c6_i92] = c6_cv2[c6_i92];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c6_y));
}

static void c6_eml_xgesvd(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[24], real_T c6_U[24], real_T c6_S[4], real_T c6_V[16])
{
  int32_T c6_i93;
  real_T c6_b_A[24];
  int32_T c6_i94;
  real_T c6_s[4];
  int32_T c6_i95;
  real_T c6_e[4];
  int32_T c6_i96;
  real_T c6_work[6];
  int32_T c6_i97;
  int32_T c6_i98;
  real_T c6_Vf[16];
  int32_T c6_q;
  int32_T c6_b_q;
  int32_T c6_a;
  int32_T c6_qp1;
  int32_T c6_b_a;
  int32_T c6_qm1;
  int32_T c6_b;
  int32_T c6_c;
  int32_T c6_c_a;
  int32_T c6_b_b;
  int32_T c6_qq;
  int32_T c6_c_b;
  int32_T c6_nmq;
  int32_T c6_d_a;
  int32_T c6_nmqp1;
  int32_T c6_i99;
  real_T c6_c_A[24];
  real_T c6_nrm;
  real_T c6_absx;
  real_T c6_d;
  real_T c6_y;
  real_T c6_d1;
  int32_T c6_b_qp1;
  boolean_T c6_overflow;
  int32_T c6_jj;
  int32_T c6_b_jj;
  int32_T c6_e_a;
  int32_T c6_b_c;
  int32_T c6_d_b;
  int32_T c6_c_c;
  int32_T c6_f_a;
  int32_T c6_e_b;
  int32_T c6_qjj;
  int32_T c6_i100;
  real_T c6_d_A[24];
  int32_T c6_i101;
  real_T c6_e_A[24];
  real_T c6_t;
  int32_T c6_c_q;
  boolean_T c6_b_overflow;
  int32_T c6_ii;
  int32_T c6_b_ii;
  int32_T c6_f_b;
  int32_T c6_pmq;
  int32_T c6_i102;
  real_T c6_b_e[4];
  real_T c6_b_absx;
  real_T c6_b_d;
  real_T c6_b_y;
  real_T c6_d2;
  int32_T c6_c_qp1;
  boolean_T c6_c_overflow;
  int32_T c6_c_ii;
  int32_T c6_d_qp1;
  boolean_T c6_d_overflow;
  int32_T c6_c_jj;
  int32_T c6_g_a;
  int32_T c6_d_c;
  int32_T c6_g_b;
  int32_T c6_e_c;
  int32_T c6_h_a;
  int32_T c6_h_b;
  int32_T c6_qp1jj;
  int32_T c6_i103;
  real_T c6_f_A[24];
  int32_T c6_e_qp1;
  boolean_T c6_e_overflow;
  int32_T c6_d_jj;
  int32_T c6_i_a;
  int32_T c6_f_c;
  int32_T c6_i_b;
  int32_T c6_g_c;
  int32_T c6_j_a;
  int32_T c6_j_b;
  int32_T c6_i104;
  real_T c6_b_work[6];
  int32_T c6_f_qp1;
  boolean_T c6_f_overflow;
  int32_T c6_d_ii;
  int32_T c6_m;
  int32_T c6_d_q;
  int32_T c6_k_a;
  int32_T c6_k_b;
  int32_T c6_l_a;
  int32_T c6_m_a;
  int32_T c6_h_c;
  int32_T c6_l_b;
  int32_T c6_i_c;
  int32_T c6_n_a;
  int32_T c6_m_b;
  int32_T c6_g_qp1;
  boolean_T c6_g_overflow;
  int32_T c6_e_jj;
  int32_T c6_o_a;
  int32_T c6_j_c;
  int32_T c6_n_b;
  int32_T c6_k_c;
  int32_T c6_p_a;
  int32_T c6_o_b;
  int32_T c6_i105;
  real_T c6_b_U[24];
  int32_T c6_i106;
  real_T c6_c_U[24];
  int32_T c6_e_q;
  boolean_T c6_h_overflow;
  int32_T c6_e_ii;
  int32_T c6_q_a;
  int32_T c6_i107;
  int32_T c6_p_b;
  int32_T c6_q_b;
  boolean_T c6_i_overflow;
  int32_T c6_f_ii;
  int32_T c6_g_ii;
  int32_T c6_f_q;
  int32_T c6_r_a;
  int32_T c6_r_b;
  int32_T c6_s_a;
  int32_T c6_l_c;
  int32_T c6_s_b;
  int32_T c6_m_c;
  int32_T c6_t_a;
  int32_T c6_t_b;
  int32_T c6_qp1q;
  int32_T c6_h_qp1;
  boolean_T c6_j_overflow;
  int32_T c6_f_jj;
  int32_T c6_u_a;
  int32_T c6_n_c;
  int32_T c6_u_b;
  int32_T c6_o_c;
  int32_T c6_v_a;
  int32_T c6_v_b;
  int32_T c6_i108;
  real_T c6_b_Vf[16];
  int32_T c6_i109;
  real_T c6_c_Vf[16];
  int32_T c6_h_ii;
  int32_T c6_g_q;
  real_T c6_rt;
  real_T c6_r;
  int32_T c6_w_a;
  int32_T c6_p_c;
  int32_T c6_w_b;
  int32_T c6_q_c;
  int32_T c6_x_b;
  int32_T c6_colq;
  int32_T c6_x_a;
  int32_T c6_r_c;
  int32_T c6_y_a;
  int32_T c6_s_c;
  real_T c6_ab_a;
  real_T c6_y_b;
  real_T c6_c_y;
  int32_T c6_ab_b;
  int32_T c6_t_c;
  int32_T c6_bb_b;
  int32_T c6_colqp1;
  real_T c6_iter;
  real_T c6_tiny;
  real_T c6_snorm;
  int32_T c6_i_ii;
  real_T c6_varargin_1;
  real_T c6_varargin_2;
  real_T c6_b_varargin_2;
  real_T c6_varargin_3;
  real_T c6_x;
  real_T c6_d_y;
  real_T c6_b_x;
  real_T c6_e_y;
  real_T c6_xk;
  real_T c6_yk;
  real_T c6_c_x;
  real_T c6_f_y;
  real_T c6_maxval;
  real_T c6_b_varargin_1;
  real_T c6_c_varargin_2;
  real_T c6_d_varargin_2;
  real_T c6_b_varargin_3;
  real_T c6_d_x;
  real_T c6_g_y;
  real_T c6_e_x;
  real_T c6_h_y;
  real_T c6_b_xk;
  real_T c6_b_yk;
  real_T c6_f_x;
  real_T c6_i_y;
  int32_T c6_bb_a;
  int32_T c6_cb_a;
  int32_T c6_i110;
  boolean_T c6_k_overflow;
  int32_T c6_j_ii;
  int32_T c6_db_a;
  int32_T c6_u_c;
  real_T c6_test0;
  real_T c6_ztest0;
  real_T c6_cb_b;
  real_T c6_j_y;
  real_T c6_db_b;
  real_T c6_k_y;
  int32_T c6_eb_a;
  int32_T c6_v_c;
  real_T c6_kase;
  int32_T c6_qs;
  int32_T c6_b_m;
  int32_T c6_h_q;
  int32_T c6_fb_a;
  int32_T c6_eb_b;
  int32_T c6_gb_a;
  int32_T c6_fb_b;
  boolean_T c6_l_overflow;
  int32_T c6_k_ii;
  real_T c6_test;
  int32_T c6_hb_a;
  int32_T c6_w_c;
  int32_T c6_ib_a;
  int32_T c6_x_c;
  real_T c6_ztest;
  real_T c6_gb_b;
  real_T c6_l_y;
  int32_T c6_jb_a;
  int32_T c6_kb_a;
  int32_T c6_y_c;
  real_T c6_f;
  int32_T c6_lb_a;
  int32_T c6_ab_c;
  int32_T c6_mb_a;
  int32_T c6_i111;
  int32_T c6_i_q;
  int32_T c6_nb_a;
  int32_T c6_hb_b;
  int32_T c6_ob_a;
  int32_T c6_ib_b;
  boolean_T c6_m_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_t1;
  real_T c6_b_t1;
  real_T c6_b_f;
  real_T c6_sn;
  real_T c6_cs;
  real_T c6_b_cs;
  real_T c6_b_sn;
  int32_T c6_pb_a;
  int32_T c6_km1;
  real_T c6_qb_a;
  real_T c6_jb_b;
  real_T c6_rb_a;
  real_T c6_kb_b;
  real_T c6_m_y;
  int32_T c6_sb_a;
  int32_T c6_bb_c;
  int32_T c6_lb_b;
  int32_T c6_cb_c;
  int32_T c6_mb_b;
  int32_T c6_colk;
  int32_T c6_tb_a;
  int32_T c6_db_c;
  int32_T c6_nb_b;
  int32_T c6_eb_c;
  int32_T c6_ob_b;
  int32_T c6_colm;
  int32_T c6_ub_a;
  int32_T c6_j_q;
  int32_T c6_c_m;
  int32_T c6_vb_a;
  int32_T c6_pb_b;
  int32_T c6_wb_a;
  int32_T c6_qb_b;
  boolean_T c6_n_overflow;
  int32_T c6_c_k;
  real_T c6_c_t1;
  real_T c6_unusedU0;
  real_T c6_c_sn;
  real_T c6_c_cs;
  real_T c6_xb_a;
  real_T c6_rb_b;
  real_T c6_yb_a;
  real_T c6_sb_b;
  real_T c6_n_y;
  int32_T c6_ac_a;
  int32_T c6_fb_c;
  int32_T c6_tb_b;
  int32_T c6_gb_c;
  int32_T c6_ub_b;
  int32_T c6_bc_a;
  int32_T c6_hb_c;
  int32_T c6_vb_b;
  int32_T c6_ib_c;
  int32_T c6_wb_b;
  int32_T c6_colqm1;
  int32_T c6_cc_a;
  int32_T c6_mm1;
  real_T c6_d3;
  real_T c6_d4;
  real_T c6_d5;
  real_T c6_d6;
  real_T c6_d7;
  real_T c6_c_varargin_1[5];
  int32_T c6_ixstart;
  real_T c6_mtmp;
  real_T c6_g_x;
  boolean_T c6_xb_b;
  int32_T c6_ix;
  int32_T c6_b_ix;
  real_T c6_h_x;
  boolean_T c6_yb_b;
  int32_T c6_dc_a;
  int32_T c6_i112;
  boolean_T c6_o_overflow;
  int32_T c6_c_ix;
  real_T c6_ec_a;
  real_T c6_ac_b;
  boolean_T c6_p;
  real_T c6_b_mtmp;
  real_T c6_scale;
  real_T c6_sm;
  real_T c6_smm1;
  real_T c6_emm1;
  real_T c6_sqds;
  real_T c6_eqds;
  real_T c6_fc_a;
  real_T c6_bc_b;
  real_T c6_o_y;
  real_T c6_gc_a;
  real_T c6_cc_b;
  real_T c6_p_y;
  real_T c6_dc_b;
  real_T c6_hc_a;
  real_T c6_ec_b;
  real_T c6_jb_c;
  real_T c6_ic_a;
  real_T c6_fc_b;
  real_T c6_shift;
  real_T c6_jc_a;
  real_T c6_gc_b;
  real_T c6_q_y;
  real_T c6_kc_a;
  real_T c6_hc_b;
  real_T c6_r_y;
  real_T c6_lc_a;
  real_T c6_ic_b;
  real_T c6_g;
  int32_T c6_k_q;
  int32_T c6_b_mm1;
  int32_T c6_mc_a;
  int32_T c6_jc_b;
  int32_T c6_nc_a;
  int32_T c6_kc_b;
  boolean_T c6_p_overflow;
  int32_T c6_d_k;
  int32_T c6_oc_a;
  int32_T c6_pc_a;
  int32_T c6_kp1;
  real_T c6_c_f;
  real_T c6_unusedU1;
  real_T c6_d_sn;
  real_T c6_d_cs;
  real_T c6_qc_a;
  real_T c6_lc_b;
  real_T c6_s_y;
  real_T c6_rc_a;
  real_T c6_mc_b;
  real_T c6_t_y;
  real_T c6_sc_a;
  real_T c6_nc_b;
  real_T c6_u_y;
  real_T c6_tc_a;
  real_T c6_oc_b;
  real_T c6_v_y;
  real_T c6_uc_a;
  real_T c6_pc_b;
  real_T c6_vc_a;
  real_T c6_qc_b;
  real_T c6_w_y;
  int32_T c6_wc_a;
  int32_T c6_kb_c;
  int32_T c6_rc_b;
  int32_T c6_lb_c;
  int32_T c6_sc_b;
  int32_T c6_tc_b;
  int32_T c6_mb_c;
  int32_T c6_uc_b;
  int32_T c6_colkp1;
  real_T c6_d_f;
  real_T c6_unusedU2;
  real_T c6_e_sn;
  real_T c6_e_cs;
  real_T c6_xc_a;
  real_T c6_vc_b;
  real_T c6_x_y;
  real_T c6_yc_a;
  real_T c6_wc_b;
  real_T c6_y_y;
  real_T c6_ad_a;
  real_T c6_xc_b;
  real_T c6_ab_y;
  real_T c6_bd_a;
  real_T c6_yc_b;
  real_T c6_bb_y;
  real_T c6_cd_a;
  real_T c6_ad_b;
  real_T c6_dd_a;
  real_T c6_bd_b;
  real_T c6_cb_y;
  int32_T c6_ed_a;
  int32_T c6_nb_c;
  int32_T c6_cd_b;
  int32_T c6_ob_c;
  int32_T c6_dd_b;
  int32_T c6_ed_b;
  int32_T c6_pb_c;
  int32_T c6_fd_b;
  int32_T c6_fd_a;
  int32_T c6_qb_c;
  int32_T c6_e_k;
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_i;
  int32_T c6_b_i;
  int32_T c6_rb_c;
  int32_T c6_gd_a;
  int32_T c6_sb_c;
  int32_T c6_gd_b;
  int32_T c6_hd_b;
  int32_T c6_hd_a;
  int32_T c6_id_a;
  int32_T c6_tb_c;
  int32_T c6_jd_a;
  int32_T c6_ub_c;
  int32_T c6_id_b;
  int32_T c6_jd_b;
  int32_T c6_vb_c;
  int32_T c6_kd_b;
  int32_T c6_ld_b;
  int32_T c6_wb_c;
  int32_T c6_kd_a;
  int32_T c6_xb_c;
  int32_T c6_md_b;
  int32_T c6_nd_b;
  int32_T c6_yb_c;
  int32_T c6_od_b;
  int32_T c6_pd_b;
  int32_T c6_ld_a;
  real_T c6_d8;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = FALSE;
  for (c6_i93 = 0; c6_i93 < 24; c6_i93++) {
    c6_b_A[c6_i93] = c6_A[c6_i93];
  }

  c6_e_eml_scalar_eg(chartInstance);
  for (c6_i94 = 0; c6_i94 < 4; c6_i94++) {
    c6_s[c6_i94] = 0.0;
  }

  for (c6_i95 = 0; c6_i95 < 4; c6_i95++) {
    c6_e[c6_i95] = 0.0;
  }

  for (c6_i96 = 0; c6_i96 < 6; c6_i96++) {
    c6_work[c6_i96] = 0.0;
  }

  for (c6_i97 = 0; c6_i97 < 24; c6_i97++) {
    c6_U[c6_i97] = 0.0;
  }

  for (c6_i98 = 0; c6_i98 < 16; c6_i98++) {
    c6_Vf[c6_i98] = 0.0;
  }

  for (c6_q = 1; c6_q < 5; c6_q++) {
    c6_b_q = c6_q;
    c6_a = c6_b_q + 1;
    c6_qp1 = c6_a;
    c6_b_a = c6_b_q;
    c6_qm1 = c6_b_a;
    c6_b = c6_qm1 - 1;
    c6_c = 6 * c6_b;
    c6_c_a = c6_b_q;
    c6_b_b = c6_c;
    c6_qq = c6_c_a + c6_b_b;
    c6_c_b = c6_b_q;
    c6_nmq = 6 - c6_c_b;
    c6_d_a = c6_nmq + 1;
    c6_nmqp1 = c6_d_a;
    if (c6_b_q <= 4) {
      for (c6_i99 = 0; c6_i99 < 24; c6_i99++) {
        c6_c_A[c6_i99] = c6_b_A[c6_i99];
      }

      c6_nrm = c6_eml_xnrm2(chartInstance, c6_nmqp1, c6_c_A, c6_qq);
      if (c6_nrm > 0.0) {
        c6_absx = c6_nrm;
        c6_d = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_qq), 1, 24, 1, 0) - 1];
        if (c6_d < 0.0) {
          c6_y = -c6_absx;
        } else {
          c6_y = c6_absx;
        }

        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] = c6_y;
        c6_d1 = c6_eml_div(chartInstance, 1.0, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1]);
        c6_e_eml_xscal(chartInstance, c6_nmqp1, c6_d1, c6_b_A, c6_qq);
        c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_qq), 1, 24, 1, 0) - 1] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qq), 1, 24, 1, 0) - 1]
          + 1.0;
        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] = -c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1];
      } else {
        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] = 0.0;
      }
    }

    c6_b_qp1 = c6_qp1;
    c6_overflow = FALSE;
    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_jj = c6_b_qp1; c6_jj < 5; c6_jj++) {
      c6_b_jj = c6_jj;
      c6_e_a = c6_b_jj;
      c6_b_c = c6_e_a;
      c6_d_b = c6_b_c - 1;
      c6_c_c = 6 * c6_d_b;
      c6_f_a = c6_b_q;
      c6_e_b = c6_c_c;
      c6_qjj = c6_f_a + c6_e_b;
      if (c6_b_q <= 4) {
        if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_q), 1, 4, 1, 0) - 1] != 0.0) {
          for (c6_i100 = 0; c6_i100 < 24; c6_i100++) {
            c6_d_A[c6_i100] = c6_b_A[c6_i100];
          }

          for (c6_i101 = 0; c6_i101 < 24; c6_i101++) {
            c6_e_A[c6_i101] = c6_b_A[c6_i101];
          }

          c6_t = c6_eml_xdotc(chartInstance, c6_nmqp1, c6_d_A, c6_qq, c6_e_A,
                              c6_qjj);
          c6_t = -c6_eml_div(chartInstance, c6_t, c6_b_A
                             [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 6, 1, 0) + 6 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2, 0) - 1)) - 1]);
          c6_e_eml_xaxpy(chartInstance, c6_nmqp1, c6_t, c6_qq, c6_b_A, c6_qjj);
        }
      }

      c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_jj), 1, 4, 1, 0) - 1] = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qjj), 1, 24, 1, 0) - 1];
    }

    if (c6_b_q <= 4) {
      c6_c_q = c6_b_q;
      c6_b_overflow = FALSE;
      if (c6_b_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_b_overflow);
      }

      for (c6_ii = c6_c_q; c6_ii < 7; c6_ii++) {
        c6_b_ii = c6_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2, 0)
               - 1)) - 1] = c6_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 6, 1, 0) + 6 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 2, 0) - 1)) - 1];
      }
    }

    if (c6_b_q <= 2) {
      c6_f_b = c6_b_q;
      c6_pmq = 4 - c6_f_b;
      for (c6_i102 = 0; c6_i102 < 4; c6_i102++) {
        c6_b_e[c6_i102] = c6_e[c6_i102];
      }

      c6_nrm = c6_b_eml_xnrm2(chartInstance, c6_pmq, c6_b_e, c6_qp1);
      if (c6_nrm == 0.0) {
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] = 0.0;
      } else {
        c6_b_absx = c6_nrm;
        c6_b_d = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_qp1), 1, 4, 1, 0) - 1];
        if (c6_b_d < 0.0) {
          c6_b_y = -c6_b_absx;
        } else {
          c6_b_y = c6_b_absx;
        }

        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] = c6_b_y;
        c6_d2 = c6_eml_div(chartInstance, 1.0, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1]);
        c6_f_eml_xscal(chartInstance, c6_pmq, c6_d2, c6_e, c6_qp1);
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_qp1), 1, 4, 1, 0) - 1] = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qp1), 1, 4, 1, 0) - 1]
          + 1.0;
      }

      c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_q), 1, 4, 1, 0) - 1] = -c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1];
      if (c6_qp1 <= 6) {
        if (c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_q), 1, 4, 1, 0) - 1] != 0.0) {
          c6_c_qp1 = c6_qp1;
          c6_c_overflow = FALSE;
          if (c6_c_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_c_overflow);
          }

          for (c6_c_ii = c6_c_qp1; c6_c_ii < 7; c6_c_ii++) {
            c6_b_ii = c6_c_ii;
            c6_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_b_ii), 1, 6, 1, 0) - 1] = 0.0;
          }

          c6_d_qp1 = c6_qp1;
          c6_d_overflow = FALSE;
          if (c6_d_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_d_overflow);
          }

          for (c6_c_jj = c6_d_qp1; c6_c_jj < 5; c6_c_jj++) {
            c6_b_jj = c6_c_jj;
            c6_g_a = c6_b_jj;
            c6_d_c = c6_g_a;
            c6_g_b = c6_d_c - 1;
            c6_e_c = 6 * c6_g_b;
            c6_h_a = c6_qp1;
            c6_h_b = c6_e_c;
            c6_qp1jj = c6_h_a + c6_h_b;
            for (c6_i103 = 0; c6_i103 < 24; c6_i103++) {
              c6_f_A[c6_i103] = c6_b_A[c6_i103];
            }

            c6_f_eml_xaxpy(chartInstance, c6_nmq,
                           c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_jj), 1, 4, 1, 0) - 1], c6_f_A,
                           c6_qp1jj, c6_work, c6_qp1);
          }

          c6_e_qp1 = c6_qp1;
          c6_e_overflow = FALSE;
          if (c6_e_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_e_overflow);
          }

          for (c6_d_jj = c6_e_qp1; c6_d_jj < 5; c6_d_jj++) {
            c6_b_jj = c6_d_jj;
            c6_t = c6_eml_div(chartInstance, -c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_jj), 1, 4, 1, 0)
                              - 1], c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qp1), 1, 4, 1, 0) - 1]);
            c6_i_a = c6_b_jj;
            c6_f_c = c6_i_a;
            c6_i_b = c6_f_c - 1;
            c6_g_c = 6 * c6_i_b;
            c6_j_a = c6_qp1;
            c6_j_b = c6_g_c;
            c6_qp1jj = c6_j_a + c6_j_b;
            for (c6_i104 = 0; c6_i104 < 6; c6_i104++) {
              c6_b_work[c6_i104] = c6_work[c6_i104];
            }

            c6_g_eml_xaxpy(chartInstance, c6_nmq, c6_t, c6_b_work, c6_qp1,
                           c6_b_A, c6_qp1jj);
          }
        }
      }

      c6_f_qp1 = c6_qp1;
      c6_f_overflow = FALSE;
      if (c6_f_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_f_overflow);
      }

      for (c6_d_ii = c6_f_qp1; c6_d_ii < 5; c6_d_ii++) {
        c6_b_ii = c6_d_ii;
        c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c6_b_ii), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                  "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2,
                  0) - 1) << 2)) - 1] = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 4, 1, 0) - 1];
      }
    }
  }

  c6_m = 4;
  c6_e[2] = c6_b_A[20];
  c6_e[3] = 0.0;
  for (c6_d_q = 4; c6_d_q > 0; c6_d_q--) {
    c6_b_q = c6_d_q;
    c6_k_a = c6_b_q;
    c6_qp1 = c6_k_a;
    c6_k_b = c6_b_q;
    c6_nmq = 6 - c6_k_b;
    c6_l_a = c6_nmq + 1;
    c6_nmqp1 = c6_l_a;
    c6_m_a = c6_b_q;
    c6_h_c = c6_m_a;
    c6_l_b = c6_h_c - 1;
    c6_i_c = 6 * c6_l_b;
    c6_n_a = c6_b_q;
    c6_m_b = c6_i_c;
    c6_qq = c6_n_a + c6_m_b;
    if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] != 0.0) {
      c6_g_qp1 = c6_qp1 + 1;
      c6_g_overflow = FALSE;
      if (c6_g_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_g_overflow);
      }

      for (c6_e_jj = c6_g_qp1; c6_e_jj < 5; c6_e_jj++) {
        c6_b_jj = c6_e_jj;
        c6_o_a = c6_b_jj;
        c6_j_c = c6_o_a;
        c6_n_b = c6_j_c - 1;
        c6_k_c = 6 * c6_n_b;
        c6_p_a = c6_b_q;
        c6_o_b = c6_k_c;
        c6_qjj = c6_p_a + c6_o_b;
        for (c6_i105 = 0; c6_i105 < 24; c6_i105++) {
          c6_b_U[c6_i105] = c6_U[c6_i105];
        }

        for (c6_i106 = 0; c6_i106 < 24; c6_i106++) {
          c6_c_U[c6_i106] = c6_U[c6_i106];
        }

        c6_t = c6_eml_xdotc(chartInstance, c6_nmqp1, c6_b_U, c6_qq, c6_c_U,
                            c6_qjj);
        c6_t = -c6_eml_div(chartInstance, c6_t, c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK
                           ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qq),
                            1, 24, 1, 0) - 1]);
        c6_e_eml_xaxpy(chartInstance, c6_nmqp1, c6_t, c6_qq, c6_U, c6_qjj);
      }

      c6_e_q = c6_b_q;
      c6_h_overflow = FALSE;
      if (c6_h_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_h_overflow);
      }

      for (c6_e_ii = c6_e_q; c6_e_ii < 7; c6_e_ii++) {
        c6_b_ii = c6_e_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2, 0)
               - 1)) - 1] = -c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 6, 1, 0) + 6 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 2, 0) - 1)) - 1];
      }

      c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_qq), 1, 24, 1, 0) - 1] = c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_qq), 1, 24, 1, 0) - 1] + 1.0;
      c6_q_a = c6_b_q - 1;
      c6_i107 = c6_q_a;
      c6_p_b = c6_i107;
      c6_q_b = c6_p_b;
      if (1 > c6_q_b) {
        c6_i_overflow = FALSE;
      } else {
        c6_i_overflow = (c6_q_b > 2147483646);
      }

      if (c6_i_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_i_overflow);
      }

      for (c6_f_ii = 1; c6_f_ii <= c6_i107; c6_f_ii++) {
        c6_b_ii = c6_f_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2, 0)
               - 1)) - 1] = 0.0;
      }
    } else {
      for (c6_g_ii = 1; c6_g_ii < 7; c6_g_ii++) {
        c6_b_ii = c6_g_ii;
        c6_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c6_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2, 0)
               - 1)) - 1] = 0.0;
      }

      c6_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_qq), 1, 24, 1, 0) - 1] = 1.0;
    }
  }

  for (c6_f_q = 4; c6_f_q > 0; c6_f_q--) {
    c6_b_q = c6_f_q;
    if (c6_b_q <= 2) {
      if (c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 4, 1, 0) - 1] != 0.0) {
        c6_r_a = c6_b_q + 1;
        c6_qp1 = c6_r_a;
        c6_r_b = c6_b_q;
        c6_pmq = 4 - c6_r_b;
        c6_s_a = c6_b_q;
        c6_l_c = c6_s_a;
        c6_s_b = c6_l_c - 1;
        c6_m_c = c6_s_b << 2;
        c6_t_a = c6_qp1;
        c6_t_b = c6_m_c;
        c6_qp1q = c6_t_a + c6_t_b;
        c6_h_qp1 = c6_qp1;
        c6_j_overflow = FALSE;
        if (c6_j_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_j_overflow);
        }

        for (c6_f_jj = c6_h_qp1; c6_f_jj < 5; c6_f_jj++) {
          c6_b_jj = c6_f_jj;
          c6_u_a = c6_b_jj;
          c6_n_c = c6_u_a;
          c6_u_b = c6_n_c - 1;
          c6_o_c = c6_u_b << 2;
          c6_v_a = c6_qp1;
          c6_v_b = c6_o_c;
          c6_qp1jj = c6_v_a + c6_v_b;
          for (c6_i108 = 0; c6_i108 < 16; c6_i108++) {
            c6_b_Vf[c6_i108] = c6_Vf[c6_i108];
          }

          for (c6_i109 = 0; c6_i109 < 16; c6_i109++) {
            c6_c_Vf[c6_i109] = c6_Vf[c6_i109];
          }

          c6_t = c6_b_eml_xdotc(chartInstance, c6_pmq, c6_b_Vf, c6_qp1q, c6_c_Vf,
                                c6_qp1jj);
          c6_t = -c6_eml_div(chartInstance, c6_t,
                             c6_Vf[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_qp1q), 1, 16, 1, 0) - 1]);
          c6_h_eml_xaxpy(chartInstance, c6_pmq, c6_t, c6_qp1q, c6_Vf, c6_qp1jj);
        }
      }
    }

    for (c6_h_ii = 1; c6_h_ii < 5; c6_h_ii++) {
      c6_b_ii = c6_h_ii;
      c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c6_b_ii), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2, 0) - 1)
              << 2)) - 1] = 0.0;
    }

    c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c6_b_q), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 2, 0) - 1) <<
            2)) - 1] = 1.0;
  }

  for (c6_g_q = 1; c6_g_q < 5; c6_g_q++) {
    c6_b_q = c6_g_q;
    if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] != 0.0) {
      c6_rt = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1]);
      c6_r = c6_eml_div(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1], c6_rt);
      c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_q), 1, 4, 1, 0) - 1] = c6_rt;
      if (c6_b_q < 4) {
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] = c6_eml_div(chartInstance,
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1], c6_r);
      }

      if (c6_b_q <= 6) {
        c6_w_a = c6_b_q;
        c6_p_c = c6_w_a;
        c6_w_b = c6_p_c - 1;
        c6_q_c = 6 * c6_w_b;
        c6_x_b = c6_q_c;
        c6_colq = c6_x_b;
        c6_g_eml_xscal(chartInstance, c6_r, c6_U, c6_colq + 1);
      }
    }

    if (c6_b_q < 4) {
      if (c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 4, 1, 0) - 1] != 0.0) {
        c6_rt = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1]);
        c6_r = c6_eml_div(chartInstance, c6_rt, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK
                          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q),
                           1, 4, 1, 0) - 1]);
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_q), 1, 4, 1, 0) - 1] = c6_rt;
        c6_x_a = c6_b_q;
        c6_r_c = c6_x_a;
        c6_y_a = c6_b_q;
        c6_s_c = c6_y_a;
        c6_ab_a = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c6_s_c + 1)), 1, 4, 1, 0) - 1];
        c6_y_b = c6_r;
        c6_c_y = c6_ab_a * c6_y_b;
        c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c6_r_c + 1)), 1, 4, 1, 0) - 1] = c6_c_y;
        c6_ab_b = c6_b_q;
        c6_t_c = c6_ab_b << 2;
        c6_bb_b = c6_t_c;
        c6_colqp1 = c6_bb_b;
        c6_h_eml_xscal(chartInstance, c6_r, c6_Vf, c6_colqp1 + 1);
      }
    }
  }

  c6_iter = 0.0;
  c6_realmin(chartInstance);
  c6_eps(chartInstance);
  c6_tiny = c6_eml_div(chartInstance, 2.2250738585072014E-308,
                       2.2204460492503131E-16);
  c6_snorm = 0.0;
  for (c6_i_ii = 1; c6_i_ii < 5; c6_i_ii++) {
    c6_b_ii = c6_i_ii;
    c6_varargin_1 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 4, 1, 0) - 1]);
    c6_varargin_2 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 4, 1, 0) - 1]);
    c6_b_varargin_2 = c6_varargin_1;
    c6_varargin_3 = c6_varargin_2;
    c6_x = c6_b_varargin_2;
    c6_d_y = c6_varargin_3;
    c6_b_x = c6_x;
    c6_e_y = c6_d_y;
    c6_c_eml_scalar_eg(chartInstance);
    c6_xk = c6_b_x;
    c6_yk = c6_e_y;
    c6_c_x = c6_xk;
    c6_f_y = c6_yk;
    c6_c_eml_scalar_eg(chartInstance);
    c6_maxval = muDoubleScalarMax(c6_c_x, c6_f_y);
    c6_b_varargin_1 = c6_snorm;
    c6_c_varargin_2 = c6_maxval;
    c6_d_varargin_2 = c6_b_varargin_1;
    c6_b_varargin_3 = c6_c_varargin_2;
    c6_d_x = c6_d_varargin_2;
    c6_g_y = c6_b_varargin_3;
    c6_e_x = c6_d_x;
    c6_h_y = c6_g_y;
    c6_c_eml_scalar_eg(chartInstance);
    c6_b_xk = c6_e_x;
    c6_b_yk = c6_h_y;
    c6_f_x = c6_b_xk;
    c6_i_y = c6_b_yk;
    c6_c_eml_scalar_eg(chartInstance);
    c6_snorm = muDoubleScalarMax(c6_f_x, c6_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c6_m > 0)) {
    if (c6_iter >= 75.0) {
      c6_b_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c6_bb_a = c6_m - 1;
      c6_b_q = c6_bb_a;
      c6_cb_a = c6_m;
      c6_i110 = c6_cb_a;
      c6_k_overflow = FALSE;
      if (c6_k_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_k_overflow);
      }

      c6_j_ii = c6_i110 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c6_j_ii > -1)) {
        c6_b_ii = c6_j_ii;
        c6_b_q = c6_b_ii;
        if (c6_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c6_db_a = c6_b_ii;
          c6_u_c = c6_db_a;
          c6_test0 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1,
            4, 1, 0) - 1]) + c6_abs(chartInstance,
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                                      (real_T)(c6_u_c + 1)), 1, 4, 1, 0) - 1]);
          c6_ztest0 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii),
            1, 4, 1, 0) - 1]);
          c6_eps(chartInstance);
          c6_cb_b = c6_test0;
          c6_j_y = 2.2204460492503131E-16 * c6_cb_b;
          if (c6_ztest0 <= c6_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c6_ztest0 <= c6_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c6_iter > 20.0) {
              c6_eps(chartInstance);
              c6_db_b = c6_snorm;
              c6_k_y = 2.2204460492503131E-16 * c6_db_b;
              if (c6_ztest0 <= c6_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c6_j_ii--;
              guard3 = FALSE;
              guard4 = FALSE;
            }
          }
        }
      }

      if (guard4 == TRUE) {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_ii), 1, 4, 1, 0) - 1] = 0.0;
      }

      c6_eb_a = c6_m;
      c6_v_c = c6_eb_a;
      if (c6_b_q == c6_v_c - 1) {
        c6_kase = 4.0;
      } else {
        c6_qs = c6_m;
        c6_b_m = c6_m;
        c6_h_q = c6_b_q;
        c6_fb_a = c6_b_m;
        c6_eb_b = c6_h_q;
        c6_gb_a = c6_fb_a;
        c6_fb_b = c6_eb_b;
        if (c6_gb_a < c6_fb_b) {
          c6_l_overflow = FALSE;
        } else {
          c6_l_overflow = (c6_fb_b < -2147483647);
        }

        if (c6_l_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_l_overflow);
        }

        c6_k_ii = c6_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c6_k_ii >= c6_h_q)) {
          c6_b_ii = c6_k_ii;
          c6_qs = c6_b_ii;
          if (c6_b_ii == c6_b_q) {
            exitg4 = TRUE;
          } else {
            c6_test = 0.0;
            if (c6_b_ii < c6_m) {
              c6_test = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii), 1, 4, 1, 0)
                               - 1]);
            }

            c6_hb_a = c6_b_q;
            c6_w_c = c6_hb_a;
            if (c6_b_ii > c6_w_c + 1) {
              c6_ib_a = c6_b_ii;
              c6_x_c = c6_ib_a;
              c6_test += c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c6_x_c - 1)), 1, 4,
                1, 0) - 1]);
            }

            c6_ztest = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_ii),
              1, 4, 1, 0) - 1]);
            c6_eps(chartInstance);
            c6_gb_b = c6_test;
            c6_l_y = 2.2204460492503131E-16 * c6_gb_b;
            if (c6_ztest <= c6_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c6_ztest <= c6_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c6_k_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ii), 1, 4, 1, 0) - 1] = 0.0;
        }

        if (c6_qs == c6_b_q) {
          c6_kase = 3.0;
        } else if (c6_qs == c6_m) {
          c6_kase = 1.0;
        } else {
          c6_kase = 2.0;
          c6_b_q = c6_qs;
        }
      }

      c6_jb_a = c6_b_q + 1;
      c6_b_q = c6_jb_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c6_kase)) {
       case 1:
        c6_kb_a = c6_m;
        c6_y_c = c6_kb_a;
        c6_f = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)(c6_y_c - 1)), 1, 4, 1, 0) - 1];
        c6_lb_a = c6_m;
        c6_ab_c = c6_lb_a;
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c6_ab_c - 1)), 1, 4, 1, 0) - 1] = 0.0;
        c6_mb_a = c6_m - 1;
        c6_i111 = c6_mb_a;
        c6_i_q = c6_b_q;
        c6_nb_a = c6_i111;
        c6_hb_b = c6_i_q;
        c6_ob_a = c6_nb_a;
        c6_ib_b = c6_hb_b;
        if (c6_ob_a < c6_ib_b) {
          c6_m_overflow = FALSE;
        } else {
          c6_m_overflow = (c6_ib_b < -2147483647);
        }

        if (c6_m_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_m_overflow);
        }

        for (c6_k = c6_i111; c6_k >= c6_i_q; c6_k--) {
          c6_b_k = c6_k;
          c6_t1 = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_b_t1 = c6_t1;
          c6_b_f = c6_f;
          c6_b_eml_xrotg(chartInstance, &c6_b_t1, &c6_b_f, &c6_cs, &c6_sn);
          c6_t1 = c6_b_t1;
          c6_f = c6_b_f;
          c6_b_cs = c6_cs;
          c6_b_sn = c6_sn;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 4, 1, 0) - 1] = c6_t1;
          if (c6_b_k > c6_b_q) {
            c6_pb_a = c6_b_k - 1;
            c6_km1 = c6_pb_a;
            c6_qb_a = -c6_b_sn;
            c6_jb_b = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_km1), 1, 4, 1, 0) - 1];
            c6_f = c6_qb_a * c6_jb_b;
            c6_rb_a = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_km1), 1, 4, 1, 0) - 1];
            c6_kb_b = c6_b_cs;
            c6_m_y = c6_rb_a * c6_kb_b;
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_km1), 1, 4, 1, 0) - 1] = c6_m_y;
          }

          c6_sb_a = c6_b_k;
          c6_bb_c = c6_sb_a;
          c6_lb_b = c6_bb_c - 1;
          c6_cb_c = c6_lb_b << 2;
          c6_mb_b = c6_cb_c;
          c6_colk = c6_mb_b;
          c6_tb_a = c6_m;
          c6_db_c = c6_tb_a;
          c6_nb_b = c6_db_c - 1;
          c6_eb_c = c6_nb_b << 2;
          c6_ob_b = c6_eb_c;
          c6_colm = c6_ob_b;
          c6_c_eml_xrot(chartInstance, c6_Vf, c6_colk + 1, c6_colm + 1, c6_b_cs,
                        c6_b_sn);
        }
        break;

       case 2:
        c6_ub_a = c6_b_q - 1;
        c6_qm1 = c6_ub_a;
        c6_f = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_qm1), 1, 4, 1, 0) - 1];
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_qm1), 1, 4, 1, 0) - 1] = 0.0;
        c6_j_q = c6_b_q;
        c6_c_m = c6_m;
        c6_vb_a = c6_j_q;
        c6_pb_b = c6_c_m;
        c6_wb_a = c6_vb_a;
        c6_qb_b = c6_pb_b;
        if (c6_wb_a > c6_qb_b) {
          c6_n_overflow = FALSE;
        } else {
          c6_n_overflow = (c6_qb_b > 2147483646);
        }

        if (c6_n_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_n_overflow);
        }

        for (c6_c_k = c6_j_q; c6_c_k <= c6_c_m; c6_c_k++) {
          c6_b_k = c6_c_k;
          c6_t1 = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_c_t1 = c6_t1;
          c6_unusedU0 = c6_f;
          c6_b_eml_xrotg(chartInstance, &c6_c_t1, &c6_unusedU0, &c6_c_cs,
                         &c6_c_sn);
          c6_t1 = c6_c_t1;
          c6_b_cs = c6_c_cs;
          c6_b_sn = c6_c_sn;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 4, 1, 0) - 1] = c6_t1;
          c6_xb_a = -c6_b_sn;
          c6_rb_b = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_f = c6_xb_a * c6_rb_b;
          c6_yb_a = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_sb_b = c6_b_cs;
          c6_n_y = c6_yb_a * c6_sb_b;
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 4, 1, 0) - 1] = c6_n_y;
          c6_ac_a = c6_b_k;
          c6_fb_c = c6_ac_a;
          c6_tb_b = c6_fb_c - 1;
          c6_gb_c = 6 * c6_tb_b;
          c6_ub_b = c6_gb_c;
          c6_colk = c6_ub_b;
          c6_bc_a = c6_qm1;
          c6_hb_c = c6_bc_a;
          c6_vb_b = c6_hb_c - 1;
          c6_ib_c = 6 * c6_vb_b;
          c6_wb_b = c6_ib_c;
          c6_colqm1 = c6_wb_b;
          c6_d_eml_xrot(chartInstance, c6_U, c6_colk + 1, c6_colqm1 + 1, c6_b_cs,
                        c6_b_sn);
        }
        break;

       case 3:
        c6_cc_a = c6_m - 1;
        c6_mm1 = c6_cc_a;
        c6_d3 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_m), 1, 4, 1, 0) - 1]);
        c6_d4 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1, 4, 1, 0) - 1]);
        c6_d5 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1, 4, 1, 0) - 1]);
        c6_d6 = c6_abs(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1]);
        c6_d7 = c6_abs(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1]);
        c6_c_varargin_1[0] = c6_d3;
        c6_c_varargin_1[1] = c6_d4;
        c6_c_varargin_1[2] = c6_d5;
        c6_c_varargin_1[3] = c6_d6;
        c6_c_varargin_1[4] = c6_d7;
        c6_ixstart = 1;
        c6_mtmp = c6_c_varargin_1[0];
        c6_g_x = c6_mtmp;
        c6_xb_b = muDoubleScalarIsNaN(c6_g_x);
        if (c6_xb_b) {
          c6_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c6_ix < 6)) {
            c6_b_ix = c6_ix;
            c6_ixstart = c6_b_ix;
            c6_h_x = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
            c6_yb_b = muDoubleScalarIsNaN(c6_h_x);
            if (!c6_yb_b) {
              c6_mtmp = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
              exitg2 = TRUE;
            } else {
              c6_ix++;
            }
          }
        }

        if (c6_ixstart < 5) {
          c6_dc_a = c6_ixstart;
          c6_i112 = c6_dc_a;
          c6_o_overflow = FALSE;
          if (c6_o_overflow) {
            c6_check_forloop_overflow_error(chartInstance, c6_o_overflow);
          }

          for (c6_c_ix = c6_i112 + 1; c6_c_ix < 6; c6_c_ix++) {
            c6_b_ix = c6_c_ix;
            c6_ec_a = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
            c6_ac_b = c6_mtmp;
            c6_p = (c6_ec_a > c6_ac_b);
            if (c6_p) {
              c6_mtmp = c6_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 5, 1, 0) - 1];
            }
          }
        }

        c6_b_mtmp = c6_mtmp;
        c6_scale = c6_b_mtmp;
        c6_sm = c6_eml_div(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_m), 1, 4, 1, 0) - 1],
                           c6_scale);
        c6_smm1 = c6_eml_div(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1,
          4, 1, 0) - 1], c6_scale);
        c6_emm1 = c6_eml_div(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_mm1), 1,
          4, 1, 0) - 1], c6_scale);
        c6_sqds = c6_eml_div(chartInstance, c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1,
          4, 1, 0) - 1], c6_scale);
        c6_eqds = c6_eml_div(chartInstance, c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1,
          4, 1, 0) - 1], c6_scale);
        c6_fc_a = c6_smm1 + c6_sm;
        c6_bc_b = c6_smm1 - c6_sm;
        c6_o_y = c6_fc_a * c6_bc_b;
        c6_gc_a = c6_emm1;
        c6_cc_b = c6_emm1;
        c6_p_y = c6_gc_a * c6_cc_b;
        c6_dc_b = c6_eml_div(chartInstance, c6_o_y + c6_p_y, 2.0);
        c6_hc_a = c6_sm;
        c6_ec_b = c6_emm1;
        c6_jb_c = c6_hc_a * c6_ec_b;
        c6_ic_a = c6_jb_c;
        c6_fc_b = c6_jb_c;
        c6_jb_c = c6_ic_a * c6_fc_b;
        c6_shift = 0.0;
        guard1 = FALSE;
        if (c6_dc_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c6_jb_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c6_jc_a = c6_dc_b;
          c6_gc_b = c6_dc_b;
          c6_q_y = c6_jc_a * c6_gc_b;
          c6_shift = c6_q_y + c6_jb_c;
          c6_b_sqrt(chartInstance, &c6_shift);
          if (c6_dc_b < 0.0) {
            c6_shift = -c6_shift;
          }

          c6_shift = c6_eml_div(chartInstance, c6_jb_c, c6_dc_b + c6_shift);
        }

        c6_kc_a = c6_sqds + c6_sm;
        c6_hc_b = c6_sqds - c6_sm;
        c6_r_y = c6_kc_a * c6_hc_b;
        c6_f = c6_r_y + c6_shift;
        c6_lc_a = c6_sqds;
        c6_ic_b = c6_eqds;
        c6_g = c6_lc_a * c6_ic_b;
        c6_k_q = c6_b_q;
        c6_b_mm1 = c6_mm1;
        c6_mc_a = c6_k_q;
        c6_jc_b = c6_b_mm1;
        c6_nc_a = c6_mc_a;
        c6_kc_b = c6_jc_b;
        if (c6_nc_a > c6_kc_b) {
          c6_p_overflow = FALSE;
        } else {
          c6_p_overflow = (c6_kc_b > 2147483646);
        }

        if (c6_p_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_p_overflow);
        }

        for (c6_d_k = c6_k_q; c6_d_k <= c6_b_mm1; c6_d_k++) {
          c6_b_k = c6_d_k;
          c6_oc_a = c6_b_k;
          c6_km1 = c6_oc_a;
          c6_pc_a = c6_b_k + 1;
          c6_kp1 = c6_pc_a;
          c6_c_f = c6_f;
          c6_unusedU1 = c6_g;
          c6_b_eml_xrotg(chartInstance, &c6_c_f, &c6_unusedU1, &c6_d_cs,
                         &c6_d_sn);
          c6_f = c6_c_f;
          c6_b_cs = c6_d_cs;
          c6_b_sn = c6_d_sn;
          if (c6_b_k > c6_b_q) {
            c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c6_km1 - 1)), 1, 4, 1, 0) - 1] = c6_f;
          }

          c6_qc_a = c6_b_cs;
          c6_lc_b = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_s_y = c6_qc_a * c6_lc_b;
          c6_rc_a = c6_b_sn;
          c6_mc_b = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_t_y = c6_rc_a * c6_mc_b;
          c6_f = c6_s_y + c6_t_y;
          c6_sc_a = c6_b_cs;
          c6_nc_b = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_u_y = c6_sc_a * c6_nc_b;
          c6_tc_a = c6_b_sn;
          c6_oc_b = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_v_y = c6_tc_a * c6_oc_b;
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 4, 1, 0) - 1] = c6_u_y - c6_v_y;
          c6_uc_a = c6_b_sn;
          c6_pc_b = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 4, 1, 0) - 1];
          c6_g = c6_uc_a * c6_pc_b;
          c6_vc_a = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 4, 1, 0) - 1];
          c6_qc_b = c6_b_cs;
          c6_w_y = c6_vc_a * c6_qc_b;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 4, 1, 0) - 1] = c6_w_y;
          c6_wc_a = c6_b_k;
          c6_kb_c = c6_wc_a;
          c6_rc_b = c6_kb_c - 1;
          c6_lb_c = c6_rc_b << 2;
          c6_sc_b = c6_lb_c;
          c6_colk = c6_sc_b;
          c6_tc_b = c6_b_k;
          c6_mb_c = c6_tc_b << 2;
          c6_uc_b = c6_mb_c;
          c6_colkp1 = c6_uc_b;
          c6_c_eml_xrot(chartInstance, c6_Vf, c6_colk + 1, c6_colkp1 + 1,
                        c6_b_cs, c6_b_sn);
          c6_d_f = c6_f;
          c6_unusedU2 = c6_g;
          c6_b_eml_xrotg(chartInstance, &c6_d_f, &c6_unusedU2, &c6_e_cs,
                         &c6_e_sn);
          c6_f = c6_d_f;
          c6_b_cs = c6_e_cs;
          c6_b_sn = c6_e_sn;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_k), 1, 4, 1, 0) - 1] = c6_f;
          c6_xc_a = c6_b_cs;
          c6_vc_b = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_x_y = c6_xc_a * c6_vc_b;
          c6_yc_a = c6_b_sn;
          c6_wc_b = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 4, 1, 0) - 1];
          c6_y_y = c6_yc_a * c6_wc_b;
          c6_f = c6_x_y + c6_y_y;
          c6_ad_a = -c6_b_sn;
          c6_xc_b = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
          c6_ab_y = c6_ad_a * c6_xc_b;
          c6_bd_a = c6_b_cs;
          c6_yc_b = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 4, 1, 0) - 1];
          c6_bb_y = c6_bd_a * c6_yc_b;
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 4, 1, 0) - 1] = c6_ab_y + c6_bb_y;
          c6_cd_a = c6_b_sn;
          c6_ad_b = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 4, 1, 0) - 1];
          c6_g = c6_cd_a * c6_ad_b;
          c6_dd_a = c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_kp1), 1, 4, 1, 0) - 1];
          c6_bd_b = c6_b_cs;
          c6_cb_y = c6_dd_a * c6_bd_b;
          c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_kp1), 1, 4, 1, 0) - 1] = c6_cb_y;
          if (c6_b_k < 6) {
            c6_ed_a = c6_b_k;
            c6_nb_c = c6_ed_a;
            c6_cd_b = c6_nb_c - 1;
            c6_ob_c = 6 * c6_cd_b;
            c6_dd_b = c6_ob_c;
            c6_colk = c6_dd_b;
            c6_ed_b = c6_b_k;
            c6_pb_c = 6 * c6_ed_b;
            c6_fd_b = c6_pb_c;
            c6_colkp1 = c6_fd_b;
            c6_d_eml_xrot(chartInstance, c6_U, c6_colk + 1, c6_colkp1 + 1,
                          c6_b_cs, c6_b_sn);
          }
        }

        c6_fd_a = c6_m;
        c6_qb_c = c6_fd_a;
        c6_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c6_qb_c - 1)), 1, 4, 1, 0) - 1] = c6_f;
        c6_iter++;
        break;

       default:
        if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_q), 1, 4, 1, 0) - 1] < 0.0) {
          c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 4, 1, 0) - 1] =
            -c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_q), 1, 4, 1, 0) - 1];
          c6_gd_a = c6_b_q;
          c6_rb_c = c6_gd_a;
          c6_gd_b = c6_rb_c - 1;
          c6_sb_c = c6_gd_b << 2;
          c6_hd_b = c6_sb_c;
          c6_colq = c6_hd_b;
          c6_b_eml_scalar_eg(chartInstance);
          c6_d8 = -1.0;
          c6_h_eml_xscal(chartInstance, c6_d8, c6_Vf, c6_colq + 1);
        }

        c6_hd_a = c6_b_q + 1;
        c6_qp1 = c6_hd_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c6_b_q < 4)) {
          if (c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c6_b_q), 1, 4, 1, 0) - 1] <
              c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c6_qp1), 1, 4, 1, 0) - 1]) {
            c6_rt = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c6_b_q), 1, 4, 1, 0) - 1];
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_q), 1, 4, 1, 0) - 1] =
              c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c6_qp1), 1, 4, 1, 0) - 1];
            c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_qp1), 1, 4, 1, 0) - 1] = c6_rt;
            if (c6_b_q < 4) {
              c6_jd_a = c6_b_q;
              c6_tb_c = c6_jd_a;
              c6_id_b = c6_tb_c - 1;
              c6_ub_c = c6_id_b << 2;
              c6_jd_b = c6_ub_c;
              c6_colq = c6_jd_b;
              c6_kd_b = c6_b_q;
              c6_vb_c = c6_kd_b << 2;
              c6_ld_b = c6_vb_c;
              c6_colqp1 = c6_ld_b;
              c6_c_eml_xswap(chartInstance, c6_Vf, c6_colq + 1, c6_colqp1 + 1);
            }

            if (c6_b_q < 6) {
              c6_kd_a = c6_b_q;
              c6_wb_c = c6_kd_a;
              c6_md_b = c6_wb_c - 1;
              c6_xb_c = 6 * c6_md_b;
              c6_nd_b = c6_xb_c;
              c6_colq = c6_nd_b;
              c6_od_b = c6_b_q;
              c6_yb_c = 6 * c6_od_b;
              c6_pd_b = c6_yb_c;
              c6_colqp1 = c6_pd_b;
              c6_d_eml_xswap(chartInstance, c6_U, c6_colq + 1, c6_colqp1 + 1);
            }

            c6_b_q = c6_qp1;
            c6_ld_a = c6_b_q + 1;
            c6_qp1 = c6_ld_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c6_iter = 0.0;
        c6_id_a = c6_m - 1;
        c6_m = c6_id_a;
        break;
      }
    }
  }

  for (c6_e_k = 1; c6_e_k < 5; c6_e_k++) {
    c6_b_k = c6_e_k;
    c6_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 4, 1, 0) - 1] = c6_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
  }

  for (c6_j = 1; c6_j < 5; c6_j++) {
    c6_b_j = c6_j;
    for (c6_i = 1; c6_i < 5; c6_i++) {
      c6_b_i = c6_i;
      c6_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c6_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_j), 1, 4, 2, 0) - 1)
             << 2)) - 1] = c6_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_b_i), 1, 4, 1, 0) +
        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
    }
  }
}

static real_T c6_eml_xnrm2(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[24], int32_T c6_ix0)
{
  real_T c6_y;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_scale;
  int32_T c6_kstart;
  int32_T c6_a;
  int32_T c6_c;
  int32_T c6_b_a;
  int32_T c6_b_c;
  int32_T c6_c_a;
  int32_T c6_b;
  int32_T c6_kend;
  int32_T c6_b_kstart;
  int32_T c6_b_kend;
  int32_T c6_d_a;
  int32_T c6_b_b;
  int32_T c6_e_a;
  int32_T c6_c_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_absxk;
  real_T c6_t;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_y = 0.0;
  if (c6_c_n < 1) {
  } else if (c6_c_n == 1) {
    c6_b_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_c_ix0), 1, 24, 1, 0) - 1];
    c6_c_x = c6_b_x;
    c6_y = muDoubleScalarAbs(c6_c_x);
  } else {
    c6_realmin(chartInstance);
    c6_scale = 2.2250738585072014E-308;
    c6_kstart = c6_c_ix0;
    c6_a = c6_c_n;
    c6_c = c6_a;
    c6_b_a = c6_c - 1;
    c6_b_c = c6_b_a;
    c6_c_a = c6_kstart;
    c6_b = c6_b_c;
    c6_kend = c6_c_a + c6_b;
    c6_b_kstart = c6_kstart;
    c6_b_kend = c6_kend;
    c6_d_a = c6_b_kstart;
    c6_b_b = c6_b_kend;
    c6_e_a = c6_d_a;
    c6_c_b = c6_b_b;
    if (c6_e_a > c6_c_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_c_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = c6_b_kstart; c6_k <= c6_b_kend; c6_k++) {
      c6_b_k = c6_k;
      c6_d_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_b_k), 1, 24, 1, 0) - 1];
      c6_e_x = c6_d_x;
      c6_absxk = muDoubleScalarAbs(c6_e_x);
      if (c6_absxk > c6_scale) {
        c6_t = c6_scale / c6_absxk;
        c6_y = 1.0 + c6_y * c6_t * c6_t;
        c6_scale = c6_absxk;
      } else {
        c6_t = c6_absxk / c6_scale;
        c6_y += c6_t * c6_t;
      }
    }

    c6_y = c6_scale * muDoubleScalarSqrt(c6_y);
  }

  return c6_y;
}

static void c6_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_b_x[24])
{
  int32_T c6_i113;
  for (c6_i113 = 0; c6_i113 < 24; c6_i113++) {
    c6_b_x[c6_i113] = c6_x[c6_i113];
  }

  c6_e_eml_xscal(chartInstance, c6_n, c6_a, c6_b_x, c6_ix0);
}

static real_T c6_eml_xdotc(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[24], int32_T c6_ix0, real_T c6_y[24], int32_T c6_iy0)
{
  real_T c6_d;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_n;
  int32_T c6_d_ix0;
  int32_T c6_d_iy0;
  int32_T c6_e_n;
  int32_T c6_e_ix0;
  int32_T c6_e_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_f_n;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_d_n = c6_c_n;
  c6_d_ix0 = c6_c_ix0;
  c6_d_iy0 = c6_c_iy0;
  c6_e_n = c6_d_n;
  c6_e_ix0 = c6_d_ix0;
  c6_e_iy0 = c6_d_iy0;
  c6_d = 0.0;
  if (c6_e_n < 1) {
  } else {
    c6_ix = c6_e_ix0;
    c6_iy = c6_e_iy0;
    c6_f_n = c6_e_n;
    c6_b = c6_f_n;
    c6_b_b = c6_b;
    if (1 > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 1; c6_k <= c6_f_n; c6_k++) {
      c6_d += c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_ix), 1, 24, 1, 0) - 1] * c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 24, 1, 0) - 1];
      c6_a = c6_ix + 1;
      c6_ix = c6_a;
      c6_b_a = c6_iy + 1;
      c6_iy = c6_b_a;
    }
  }

  return c6_d;
}

static void c6_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[24], int32_T c6_iy0,
  real_T c6_b_y[24])
{
  int32_T c6_i114;
  for (c6_i114 = 0; c6_i114 < 24; c6_i114++) {
    c6_b_y[c6_i114] = c6_y[c6_i114];
  }

  c6_e_eml_xaxpy(chartInstance, c6_n, c6_a, c6_ix0, c6_b_y, c6_iy0);
}

static real_T c6_b_eml_xnrm2(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[4], int32_T c6_ix0)
{
  real_T c6_y;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_scale;
  int32_T c6_kstart;
  int32_T c6_a;
  int32_T c6_c;
  int32_T c6_b_a;
  int32_T c6_b_c;
  int32_T c6_c_a;
  int32_T c6_b;
  int32_T c6_kend;
  int32_T c6_b_kstart;
  int32_T c6_b_kend;
  int32_T c6_d_a;
  int32_T c6_b_b;
  int32_T c6_e_a;
  int32_T c6_c_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_absxk;
  real_T c6_t;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_y = 0.0;
  if (c6_c_n < 1) {
  } else if (c6_c_n == 1) {
    c6_b_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_c_ix0), 1, 4, 1, 0) - 1];
    c6_c_x = c6_b_x;
    c6_y = muDoubleScalarAbs(c6_c_x);
  } else {
    c6_realmin(chartInstance);
    c6_scale = 2.2250738585072014E-308;
    c6_kstart = c6_c_ix0;
    c6_a = c6_c_n;
    c6_c = c6_a;
    c6_b_a = c6_c - 1;
    c6_b_c = c6_b_a;
    c6_c_a = c6_kstart;
    c6_b = c6_b_c;
    c6_kend = c6_c_a + c6_b;
    c6_b_kstart = c6_kstart;
    c6_b_kend = c6_kend;
    c6_d_a = c6_b_kstart;
    c6_b_b = c6_b_kend;
    c6_e_a = c6_d_a;
    c6_c_b = c6_b_b;
    if (c6_e_a > c6_c_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_c_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = c6_b_kstart; c6_k <= c6_b_kend; c6_k++) {
      c6_b_k = c6_k;
      c6_d_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
      c6_e_x = c6_d_x;
      c6_absxk = muDoubleScalarAbs(c6_e_x);
      if (c6_absxk > c6_scale) {
        c6_t = c6_scale / c6_absxk;
        c6_y = 1.0 + c6_y * c6_t * c6_t;
        c6_scale = c6_absxk;
      } else {
        c6_t = c6_absxk / c6_scale;
        c6_y += c6_t * c6_t;
      }
    }

    c6_y = c6_scale * muDoubleScalarSqrt(c6_y);
  }

  return c6_y;
}

static void c6_b_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[4], int32_T c6_ix0, real_T c6_b_x[4])
{
  int32_T c6_i115;
  for (c6_i115 = 0; c6_i115 < 4; c6_i115++) {
    c6_b_x[c6_i115] = c6_x[c6_i115];
  }

  c6_f_eml_xscal(chartInstance, c6_n, c6_a, c6_b_x, c6_ix0);
}

static void c6_b_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_y[6],
  int32_T c6_iy0, real_T c6_b_y[6])
{
  int32_T c6_i116;
  int32_T c6_i117;
  real_T c6_b_x[24];
  for (c6_i116 = 0; c6_i116 < 6; c6_i116++) {
    c6_b_y[c6_i116] = c6_y[c6_i116];
  }

  for (c6_i117 = 0; c6_i117 < 24; c6_i117++) {
    c6_b_x[c6_i117] = c6_x[c6_i117];
  }

  c6_f_eml_xaxpy(chartInstance, c6_n, c6_a, c6_b_x, c6_ix0, c6_b_y, c6_iy0);
}

static void c6_c_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[6], int32_T c6_ix0, real_T c6_y[24],
  int32_T c6_iy0, real_T c6_b_y[24])
{
  int32_T c6_i118;
  int32_T c6_i119;
  real_T c6_b_x[6];
  for (c6_i118 = 0; c6_i118 < 24; c6_i118++) {
    c6_b_y[c6_i118] = c6_y[c6_i118];
  }

  for (c6_i119 = 0; c6_i119 < 6; c6_i119++) {
    c6_b_x[c6_i119] = c6_x[c6_i119];
  }

  c6_g_eml_xaxpy(chartInstance, c6_n, c6_a, c6_b_x, c6_ix0, c6_b_y, c6_iy0);
}

static real_T c6_b_eml_xdotc(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_x[16], int32_T c6_ix0, real_T c6_y[16], int32_T c6_iy0)
{
  real_T c6_d;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_n;
  int32_T c6_d_ix0;
  int32_T c6_d_iy0;
  int32_T c6_e_n;
  int32_T c6_e_ix0;
  int32_T c6_e_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_f_n;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_n = c6_n;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_d_n = c6_c_n;
  c6_d_ix0 = c6_c_ix0;
  c6_d_iy0 = c6_c_iy0;
  c6_e_n = c6_d_n;
  c6_e_ix0 = c6_d_ix0;
  c6_e_iy0 = c6_d_iy0;
  c6_d = 0.0;
  if (c6_e_n < 1) {
  } else {
    c6_ix = c6_e_ix0;
    c6_iy = c6_e_iy0;
    c6_f_n = c6_e_n;
    c6_b = c6_f_n;
    c6_b_b = c6_b;
    if (1 > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 1; c6_k <= c6_f_n; c6_k++) {
      c6_d += c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_ix), 1, 16, 1, 0) - 1] * c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 16, 1, 0) - 1];
      c6_a = c6_ix + 1;
      c6_ix = c6_a;
      c6_b_a = c6_iy + 1;
      c6_iy = c6_b_a;
    }
  }

  return c6_d;
}

static void c6_d_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[16], int32_T c6_iy0,
  real_T c6_b_y[16])
{
  int32_T c6_i120;
  for (c6_i120 = 0; c6_i120 < 16; c6_i120++) {
    c6_b_y[c6_i120] = c6_y[c6_i120];
  }

  c6_h_eml_xaxpy(chartInstance, c6_n, c6_a, c6_ix0, c6_b_y, c6_iy0);
}

static void c6_c_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_b_x[24])
{
  int32_T c6_i121;
  for (c6_i121 = 0; c6_i121 < 24; c6_i121++) {
    c6_b_x[c6_i121] = c6_x[c6_i121];
  }

  c6_g_eml_xscal(chartInstance, c6_a, c6_b_x, c6_ix0);
}

static void c6_d_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[16], int32_T c6_ix0, real_T c6_b_x[16])
{
  int32_T c6_i122;
  for (c6_i122 = 0; c6_i122 < 16; c6_i122++) {
    c6_b_x[c6_i122] = c6_x[c6_i122];
  }

  c6_h_eml_xscal(chartInstance, c6_a, c6_b_x, c6_ix0);
}

static void c6_b_eml_error(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  int32_T c6_i123;
  static char_T c6_cv3[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  for (c6_i123 = 0; c6_i123 < 30; c6_i123++) {
    c6_u[c6_i123] = c6_cv3[c6_i123];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c6_y));
}

static real_T c6_sqrt(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
                      c6_x)
{
  real_T c6_b_x;
  c6_b_x = c6_x;
  c6_b_sqrt(chartInstance, &c6_b_x);
  return c6_b_x;
}

static void c6_c_eml_error(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  int32_T c6_i124;
  static char_T c6_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[30];
  const mxArray *c6_y = NULL;
  int32_T c6_i125;
  static char_T c6_cv5[4] = { 's', 'q', 'r', 't' };

  char_T c6_b_u[4];
  const mxArray *c6_b_y = NULL;
  for (c6_i124 = 0; c6_i124 < 30; c6_i124++) {
    c6_u[c6_i124] = c6_cv4[c6_i124];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c6_i125 = 0; c6_i125 < 4; c6_i125++) {
    c6_b_u[c6_i125] = c6_cv5[c6_i125];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c6_y, 14, c6_b_y));
}

static void c6_eml_xrotg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_b, real_T *c6_b_a, real_T *c6_b_b, real_T *c6_c, real_T *c6_s)
{
  *c6_b_a = c6_a;
  *c6_b_b = c6_b;
  c6_b_eml_xrotg(chartInstance, c6_b_a, c6_b_b, c6_c, c6_s);
}

static void c6_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_x[16], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s, real_T
  c6_b_x[16])
{
  int32_T c6_i126;
  for (c6_i126 = 0; c6_i126 < 16; c6_i126++) {
    c6_b_x[c6_i126] = c6_x[c6_i126];
  }

  c6_c_eml_xrot(chartInstance, c6_b_x, c6_ix0, c6_iy0, c6_c, c6_s);
}

static void c6_b_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s,
  real_T c6_b_x[24])
{
  int32_T c6_i127;
  for (c6_i127 = 0; c6_i127 < 24; c6_i127++) {
    c6_b_x[c6_i127] = c6_x[c6_i127];
  }

  c6_d_eml_xrot(chartInstance, c6_b_x, c6_ix0, c6_iy0, c6_c, c6_s);
}

static void c6_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
  c6_x[16], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[16])
{
  int32_T c6_i128;
  for (c6_i128 = 0; c6_i128 < 16; c6_i128++) {
    c6_b_x[c6_i128] = c6_x[c6_i128];
  }

  c6_c_eml_xswap(chartInstance, c6_b_x, c6_ix0, c6_iy0);
}

static void c6_b_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0, real_T c6_b_x[24])
{
  int32_T c6_i129;
  for (c6_i129 = 0; c6_i129 < 24; c6_i129++) {
    c6_b_x[c6_i129] = c6_x[c6_i129];
  }

  c6_d_eml_xswap(chartInstance, c6_b_x, c6_ix0, c6_iy0);
}

static void c6_eml_xgemm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[16], real_T c6_B[24], real_T c6_C[24], real_T
  c6_b_C[24])
{
  int32_T c6_i130;
  int32_T c6_i131;
  real_T c6_b_A[16];
  int32_T c6_i132;
  real_T c6_b_B[24];
  for (c6_i130 = 0; c6_i130 < 24; c6_i130++) {
    c6_b_C[c6_i130] = c6_C[c6_i130];
  }

  for (c6_i131 = 0; c6_i131 < 16; c6_i131++) {
    c6_b_A[c6_i131] = c6_A[c6_i131];
  }

  for (c6_i132 = 0; c6_i132 < 24; c6_i132++) {
    c6_b_B[c6_i132] = c6_B[c6_i132];
  }

  c6_b_eml_xgemm(chartInstance, c6_k, c6_b_A, c6_b_B, c6_b_C);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_f_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i133;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i133, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i133;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_SIMULACIO_MGD, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_SIMULACIO_MGD), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_SIMULACIO_MGD);
  return c6_y;
}

static uint8_T c6_h_emlrt_marshallIn(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_eml_matlab_zgetrf(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance, real_T c6_A[16], int32_T c6_ipiv[4], int32_T *c6_info)
{
  int32_T c6_i134;
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_a;
  int32_T c6_jm1;
  int32_T c6_b;
  int32_T c6_mmj;
  int32_T c6_b_a;
  int32_T c6_c;
  int32_T c6_b_b;
  int32_T c6_jj;
  int32_T c6_c_a;
  int32_T c6_jp1j;
  int32_T c6_d_a;
  int32_T c6_b_c;
  int32_T c6_n;
  int32_T c6_ix0;
  int32_T c6_b_n;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  int32_T c6_c_ix0;
  int32_T c6_idxmax;
  int32_T c6_ix;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_y;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_b_y;
  real_T c6_smax;
  int32_T c6_d_n;
  int32_T c6_c_b;
  int32_T c6_d_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_e_a;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_c_y;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_d_y;
  real_T c6_s;
  int32_T c6_f_a;
  int32_T c6_jpiv_offset;
  int32_T c6_g_a;
  int32_T c6_e_b;
  int32_T c6_jpiv;
  int32_T c6_h_a;
  int32_T c6_f_b;
  int32_T c6_c_c;
  int32_T c6_g_b;
  int32_T c6_jrow;
  int32_T c6_i_a;
  int32_T c6_h_b;
  int32_T c6_jprow;
  int32_T c6_d_ix0;
  int32_T c6_iy0;
  int32_T c6_e_ix0;
  int32_T c6_b_iy0;
  int32_T c6_f_ix0;
  int32_T c6_c_iy0;
  int32_T c6_b_ix;
  int32_T c6_iy;
  int32_T c6_c_k;
  real_T c6_temp;
  int32_T c6_j_a;
  int32_T c6_k_a;
  int32_T c6_b_jp1j;
  int32_T c6_l_a;
  int32_T c6_d_c;
  int32_T c6_m_a;
  int32_T c6_i_b;
  int32_T c6_i135;
  int32_T c6_n_a;
  int32_T c6_j_b;
  int32_T c6_o_a;
  int32_T c6_k_b;
  boolean_T c6_b_overflow;
  int32_T c6_i;
  int32_T c6_b_i;
  real_T c6_k_x;
  real_T c6_e_y;
  real_T c6_z;
  int32_T c6_l_b;
  int32_T c6_e_c;
  int32_T c6_p_a;
  int32_T c6_f_c;
  int32_T c6_q_a;
  int32_T c6_g_c;
  int32_T c6_m;
  int32_T c6_e_n;
  int32_T c6_g_ix0;
  int32_T c6_d_iy0;
  int32_T c6_ia0;
  real_T c6_d9;
  c6_realmin(chartInstance);
  c6_eps(chartInstance);
  for (c6_i134 = 0; c6_i134 < 4; c6_i134++) {
    c6_ipiv[c6_i134] = 1 + c6_i134;
  }

  *c6_info = 0;
  for (c6_j = 1; c6_j < 4; c6_j++) {
    c6_b_j = c6_j;
    c6_a = c6_b_j - 1;
    c6_jm1 = c6_a;
    c6_b = c6_b_j;
    c6_mmj = 4 - c6_b;
    c6_b_a = c6_jm1;
    c6_c = c6_b_a * 5;
    c6_b_b = c6_c + 1;
    c6_jj = c6_b_b;
    c6_c_a = c6_jj + 1;
    c6_jp1j = c6_c_a;
    c6_d_a = c6_mmj;
    c6_b_c = c6_d_a;
    c6_n = c6_b_c + 1;
    c6_ix0 = c6_jj;
    c6_b_n = c6_n;
    c6_b_ix0 = c6_ix0;
    c6_c_n = c6_b_n;
    c6_c_ix0 = c6_b_ix0;
    if (c6_c_n < 1) {
      c6_idxmax = 0;
    } else {
      c6_idxmax = 1;
      if (c6_c_n > 1) {
        c6_ix = c6_c_ix0;
        c6_x = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_ix), 1, 16, 1, 0) - 1];
        c6_b_x = c6_x;
        c6_c_x = c6_b_x;
        c6_y = muDoubleScalarAbs(c6_c_x);
        c6_d_x = 0.0;
        c6_e_x = c6_d_x;
        c6_b_y = muDoubleScalarAbs(c6_e_x);
        c6_smax = c6_y + c6_b_y;
        c6_d_n = c6_c_n;
        c6_c_b = c6_d_n;
        c6_d_b = c6_c_b;
        if (2 > c6_d_b) {
          c6_overflow = FALSE;
        } else {
          c6_overflow = (c6_d_b > 2147483646);
        }

        if (c6_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_overflow);
        }

        for (c6_k = 2; c6_k <= c6_d_n; c6_k++) {
          c6_b_k = c6_k;
          c6_e_a = c6_ix + 1;
          c6_ix = c6_e_a;
          c6_f_x = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_ix), 1, 16, 1, 0) - 1];
          c6_g_x = c6_f_x;
          c6_h_x = c6_g_x;
          c6_c_y = muDoubleScalarAbs(c6_h_x);
          c6_i_x = 0.0;
          c6_j_x = c6_i_x;
          c6_d_y = muDoubleScalarAbs(c6_j_x);
          c6_s = c6_c_y + c6_d_y;
          if (c6_s > c6_smax) {
            c6_idxmax = c6_b_k;
            c6_smax = c6_s;
          }
        }
      }
    }

    c6_f_a = c6_idxmax - 1;
    c6_jpiv_offset = c6_f_a;
    c6_g_a = c6_jj;
    c6_e_b = c6_jpiv_offset;
    c6_jpiv = c6_g_a + c6_e_b;
    if (c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if (c6_jpiv_offset != 0) {
        c6_h_a = c6_b_j;
        c6_f_b = c6_jpiv_offset;
        c6_c_c = c6_h_a + c6_f_b;
        c6_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_j), 1, 4, 1, 0) - 1] = c6_c_c;
        c6_g_b = c6_jm1 + 1;
        c6_jrow = c6_g_b;
        c6_i_a = c6_jrow;
        c6_h_b = c6_jpiv_offset;
        c6_jprow = c6_i_a + c6_h_b;
        c6_d_ix0 = c6_jrow;
        c6_iy0 = c6_jprow;
        c6_e_ix0 = c6_d_ix0;
        c6_b_iy0 = c6_iy0;
        c6_below_threshold(chartInstance);
        c6_f_ix0 = c6_e_ix0;
        c6_c_iy0 = c6_b_iy0;
        c6_b_ix = c6_f_ix0;
        c6_iy = c6_c_iy0;
        for (c6_c_k = 1; c6_c_k < 5; c6_c_k++) {
          c6_temp = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c6_b_ix), 1, 16, 1, 0) - 1];
          c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ix), 1, 16, 1, 0) - 1] =
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_iy), 1, 16, 1, 0) - 1];
          c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_iy), 1, 16, 1, 0) - 1] = c6_temp;
          c6_j_a = c6_b_ix + 4;
          c6_b_ix = c6_j_a;
          c6_k_a = c6_iy + 4;
          c6_iy = c6_k_a;
        }
      }

      c6_b_jp1j = c6_jp1j;
      c6_l_a = c6_mmj;
      c6_d_c = c6_l_a;
      c6_m_a = c6_jp1j;
      c6_i_b = c6_d_c - 1;
      c6_i135 = c6_m_a + c6_i_b;
      c6_n_a = c6_b_jp1j;
      c6_j_b = c6_i135;
      c6_o_a = c6_n_a;
      c6_k_b = c6_j_b;
      if (c6_o_a > c6_k_b) {
        c6_b_overflow = FALSE;
      } else {
        c6_b_overflow = (c6_k_b > 2147483646);
      }

      if (c6_b_overflow) {
        c6_check_forloop_overflow_error(chartInstance, c6_b_overflow);
      }

      for (c6_i = c6_b_jp1j; c6_i <= c6_i135; c6_i++) {
        c6_b_i = c6_i;
        c6_k_x = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_i), 1, 16, 1, 0) - 1];
        c6_e_y = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_jj), 1, 16, 1, 0) - 1];
        c6_z = c6_k_x / c6_e_y;
        c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_b_i), 1, 16, 1, 0) - 1] = c6_z;
      }
    } else {
      *c6_info = c6_b_j;
    }

    c6_l_b = c6_b_j;
    c6_e_c = 4 - c6_l_b;
    c6_p_a = c6_jj;
    c6_f_c = c6_p_a;
    c6_q_a = c6_jj;
    c6_g_c = c6_q_a;
    c6_m = c6_mmj;
    c6_e_n = c6_e_c;
    c6_g_ix0 = c6_jp1j;
    c6_d_iy0 = c6_f_c + 4;
    c6_ia0 = c6_g_c + 5;
    c6_d9 = -1.0;
    c6_b_eml_xger(chartInstance, c6_m, c6_e_n, c6_d9, c6_g_ix0, c6_d_iy0, c6_A,
                  c6_ia0);
  }

  if (*c6_info == 0) {
    if (!(c6_A[15] != 0.0)) {
      *c6_info = 4;
    }
  }
}

static void c6_b_eml_xger(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_m, int32_T c6_n, real_T c6_alpha1, int32_T c6_ix0, int32_T c6_iy0,
  real_T c6_A[16], int32_T c6_ia0)
{
  int32_T c6_b_m;
  int32_T c6_b_n;
  real_T c6_b_alpha1;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_b_ia0;
  int32_T c6_c_m;
  int32_T c6_c_n;
  real_T c6_c_alpha1;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_c_ia0;
  int32_T c6_d_m;
  int32_T c6_d_n;
  real_T c6_d_alpha1;
  int32_T c6_d_ix0;
  int32_T c6_d_iy0;
  int32_T c6_d_ia0;
  int32_T c6_ixstart;
  int32_T c6_a;
  int32_T c6_jA;
  int32_T c6_jy;
  int32_T c6_e_n;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_j;
  real_T c6_yjy;
  real_T c6_temp;
  int32_T c6_ix;
  int32_T c6_c_b;
  int32_T c6_i136;
  int32_T c6_b_a;
  int32_T c6_d_b;
  int32_T c6_i137;
  int32_T c6_c_a;
  int32_T c6_e_b;
  int32_T c6_d_a;
  int32_T c6_f_b;
  boolean_T c6_b_overflow;
  int32_T c6_ijA;
  int32_T c6_b_ijA;
  int32_T c6_e_a;
  int32_T c6_f_a;
  int32_T c6_g_a;
  c6_b_m = c6_m;
  c6_b_n = c6_n;
  c6_b_alpha1 = c6_alpha1;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_b_ia0 = c6_ia0;
  c6_c_m = c6_b_m;
  c6_c_n = c6_b_n;
  c6_c_alpha1 = c6_b_alpha1;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_c_ia0 = c6_b_ia0;
  c6_d_m = c6_c_m;
  c6_d_n = c6_c_n;
  c6_d_alpha1 = c6_c_alpha1;
  c6_d_ix0 = c6_c_ix0;
  c6_d_iy0 = c6_c_iy0;
  c6_d_ia0 = c6_c_ia0;
  if (c6_d_alpha1 == 0.0) {
  } else {
    c6_ixstart = c6_d_ix0;
    c6_a = c6_d_ia0 - 1;
    c6_jA = c6_a;
    c6_jy = c6_d_iy0;
    c6_e_n = c6_d_n;
    c6_b = c6_e_n;
    c6_b_b = c6_b;
    if (1 > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_j = 1; c6_j <= c6_e_n; c6_j++) {
      c6_yjy = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c6_jy), 1, 16, 1, 0) - 1];
      if (c6_yjy != 0.0) {
        c6_temp = c6_yjy * c6_d_alpha1;
        c6_ix = c6_ixstart;
        c6_c_b = c6_jA + 1;
        c6_i136 = c6_c_b;
        c6_b_a = c6_d_m;
        c6_d_b = c6_jA;
        c6_i137 = c6_b_a + c6_d_b;
        c6_c_a = c6_i136;
        c6_e_b = c6_i137;
        c6_d_a = c6_c_a;
        c6_f_b = c6_e_b;
        if (c6_d_a > c6_f_b) {
          c6_b_overflow = FALSE;
        } else {
          c6_b_overflow = (c6_f_b > 2147483646);
        }

        if (c6_b_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_b_overflow);
        }

        for (c6_ijA = c6_i136; c6_ijA <= c6_i137; c6_ijA++) {
          c6_b_ijA = c6_ijA;
          c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ijA), 1, 16, 1, 0) - 1] =
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ijA), 1, 16, 1, 0) - 1] +
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_ix), 1, 16, 1, 0) - 1] * c6_temp;
          c6_e_a = c6_ix + 1;
          c6_ix = c6_e_a;
        }
      }

      c6_f_a = c6_jy + 4;
      c6_jy = c6_f_a;
      c6_g_a = c6_jA + 4;
      c6_jA = c6_g_a;
    }
  }
}

static void c6_c_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_B[24])
{
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_a;
  int32_T c6_c;
  int32_T c6_b;
  int32_T c6_b_c;
  int32_T c6_b_b;
  int32_T c6_jBcol;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_b_a;
  int32_T c6_c_c;
  int32_T c6_c_b;
  int32_T c6_d_c;
  int32_T c6_d_b;
  int32_T c6_kAcol;
  int32_T c6_c_a;
  int32_T c6_e_b;
  int32_T c6_e_c;
  int32_T c6_d_a;
  int32_T c6_i138;
  boolean_T c6_overflow;
  int32_T c6_i;
  int32_T c6_b_i;
  int32_T c6_e_a;
  int32_T c6_f_b;
  int32_T c6_f_c;
  int32_T c6_f_a;
  int32_T c6_g_b;
  int32_T c6_g_c;
  int32_T c6_g_a;
  int32_T c6_h_b;
  int32_T c6_h_c;
  int32_T c6_h_a;
  int32_T c6_i_b;
  int32_T c6_i_c;
  c6_b_below_threshold(chartInstance);
  c6_d_eml_scalar_eg(chartInstance);
  for (c6_j = 1; c6_j < 7; c6_j++) {
    c6_b_j = c6_j;
    c6_a = c6_b_j;
    c6_c = c6_a;
    c6_b = c6_c - 1;
    c6_b_c = c6_b << 2;
    c6_b_b = c6_b_c;
    c6_jBcol = c6_b_b;
    for (c6_k = 1; c6_k < 5; c6_k++) {
      c6_b_k = c6_k;
      c6_b_a = c6_b_k;
      c6_c_c = c6_b_a;
      c6_c_b = c6_c_c - 1;
      c6_d_c = c6_c_b << 2;
      c6_d_b = c6_d_c;
      c6_kAcol = c6_d_b;
      c6_c_a = c6_b_k;
      c6_e_b = c6_jBcol;
      c6_e_c = c6_c_a + c6_e_b;
      if (c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_e_c), 1, 24, 1, 0) - 1] != 0.0) {
        c6_d_a = c6_b_k;
        c6_i138 = c6_d_a;
        c6_overflow = FALSE;
        if (c6_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_overflow);
        }

        for (c6_i = c6_i138 + 1; c6_i < 5; c6_i++) {
          c6_b_i = c6_i;
          c6_e_a = c6_b_i;
          c6_f_b = c6_jBcol;
          c6_f_c = c6_e_a + c6_f_b;
          c6_f_a = c6_b_i;
          c6_g_b = c6_jBcol;
          c6_g_c = c6_f_a + c6_g_b;
          c6_g_a = c6_b_k;
          c6_h_b = c6_jBcol;
          c6_h_c = c6_g_a + c6_h_b;
          c6_h_a = c6_b_i;
          c6_i_b = c6_kAcol;
          c6_i_c = c6_h_a + c6_i_b;
          c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_f_c), 1, 24, 1, 0) - 1] =
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_g_c), 1, 24, 1, 0) - 1] -
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_h_c), 1, 24, 1, 0) - 1] *
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_i_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void c6_d_eml_xtrsm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_A[16], real_T c6_B[24])
{
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_a;
  int32_T c6_c;
  int32_T c6_b;
  int32_T c6_b_c;
  int32_T c6_b_b;
  int32_T c6_jBcol;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_b_a;
  int32_T c6_c_c;
  int32_T c6_c_b;
  int32_T c6_d_c;
  int32_T c6_d_b;
  int32_T c6_kAcol;
  int32_T c6_c_a;
  int32_T c6_e_b;
  int32_T c6_e_c;
  int32_T c6_d_a;
  int32_T c6_f_b;
  int32_T c6_f_c;
  int32_T c6_e_a;
  int32_T c6_g_b;
  int32_T c6_g_c;
  int32_T c6_f_a;
  int32_T c6_h_b;
  int32_T c6_h_c;
  real_T c6_x;
  real_T c6_y;
  real_T c6_z;
  int32_T c6_g_a;
  int32_T c6_i139;
  int32_T c6_i_b;
  int32_T c6_j_b;
  boolean_T c6_overflow;
  int32_T c6_i;
  int32_T c6_b_i;
  int32_T c6_h_a;
  int32_T c6_k_b;
  int32_T c6_i_c;
  int32_T c6_i_a;
  int32_T c6_l_b;
  int32_T c6_j_c;
  int32_T c6_j_a;
  int32_T c6_m_b;
  int32_T c6_k_c;
  int32_T c6_k_a;
  int32_T c6_n_b;
  int32_T c6_l_c;
  c6_b_below_threshold(chartInstance);
  c6_d_eml_scalar_eg(chartInstance);
  for (c6_j = 1; c6_j < 7; c6_j++) {
    c6_b_j = c6_j;
    c6_a = c6_b_j;
    c6_c = c6_a;
    c6_b = c6_c - 1;
    c6_b_c = c6_b << 2;
    c6_b_b = c6_b_c;
    c6_jBcol = c6_b_b;
    for (c6_k = 4; c6_k > 0; c6_k--) {
      c6_b_k = c6_k;
      c6_b_a = c6_b_k;
      c6_c_c = c6_b_a;
      c6_c_b = c6_c_c - 1;
      c6_d_c = c6_c_b << 2;
      c6_d_b = c6_d_c;
      c6_kAcol = c6_d_b;
      c6_c_a = c6_b_k;
      c6_e_b = c6_jBcol;
      c6_e_c = c6_c_a + c6_e_b;
      if (c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_e_c), 1, 24, 1, 0) - 1] != 0.0) {
        c6_d_a = c6_b_k;
        c6_f_b = c6_jBcol;
        c6_f_c = c6_d_a + c6_f_b;
        c6_e_a = c6_b_k;
        c6_g_b = c6_jBcol;
        c6_g_c = c6_e_a + c6_g_b;
        c6_f_a = c6_b_k;
        c6_h_b = c6_kAcol;
        c6_h_c = c6_f_a + c6_h_b;
        c6_x = c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_g_c), 1, 24, 1, 0) - 1];
        c6_y = c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c6_h_c), 1, 16, 1, 0) - 1];
        c6_z = c6_x / c6_y;
        c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c6_f_c), 1, 24, 1, 0) - 1] = c6_z;
        c6_g_a = c6_b_k - 1;
        c6_i139 = c6_g_a;
        c6_i_b = c6_i139;
        c6_j_b = c6_i_b;
        if (1 > c6_j_b) {
          c6_overflow = FALSE;
        } else {
          c6_overflow = (c6_j_b > 2147483646);
        }

        if (c6_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_overflow);
        }

        for (c6_i = 1; c6_i <= c6_i139; c6_i++) {
          c6_b_i = c6_i;
          c6_h_a = c6_b_i;
          c6_k_b = c6_jBcol;
          c6_i_c = c6_h_a + c6_k_b;
          c6_i_a = c6_b_i;
          c6_l_b = c6_jBcol;
          c6_j_c = c6_i_a + c6_l_b;
          c6_j_a = c6_b_k;
          c6_m_b = c6_jBcol;
          c6_k_c = c6_j_a + c6_m_b;
          c6_k_a = c6_b_i;
          c6_n_b = c6_kAcol;
          c6_l_c = c6_k_a + c6_n_b;
          c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_i_c), 1, 24, 1, 0) - 1] =
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_j_c), 1, 24, 1, 0) - 1] -
            c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_k_c), 1, 24, 1, 0) - 1] *
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_l_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void c6_e_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_d_ix0;
  int32_T c6_d_a;
  int32_T c6_c;
  int32_T c6_b;
  int32_T c6_b_c;
  int32_T c6_e_a;
  int32_T c6_b_b;
  int32_T c6_i140;
  int32_T c6_f_a;
  int32_T c6_c_b;
  int32_T c6_g_a;
  int32_T c6_d_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_d_ix0 = c6_c_ix0;
  c6_d_a = c6_c_n;
  c6_c = c6_d_a;
  c6_b = c6_c - 1;
  c6_b_c = c6_b;
  c6_e_a = c6_c_ix0;
  c6_b_b = c6_b_c;
  c6_i140 = c6_e_a + c6_b_b;
  c6_f_a = c6_d_ix0;
  c6_c_b = c6_i140;
  c6_g_a = c6_f_a;
  c6_d_b = c6_c_b;
  if (c6_g_a > c6_d_b) {
    c6_overflow = FALSE;
  } else {
    c6_overflow = (c6_d_b > 2147483646);
  }

  if (c6_overflow) {
    c6_check_forloop_overflow_error(chartInstance, c6_overflow);
  }

  for (c6_k = c6_d_ix0; c6_k <= c6_i140; c6_k++) {
    c6_b_k = c6_k;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 24, 1, 0) - 1] = c6_c_a * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 24, 1, 0) - 1];
  }
}

static void c6_e_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[24], int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i141;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i141 = c6_f_a;
    c6_b = c6_i141;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i141; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 24, 1, 0) - 1] =
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_b_c + 1)), 1, 24, 1, 0) - 1] + c6_c_a *
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c_c + 1)), 1, 24, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_f_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[4], int32_T c6_ix0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_d_ix0;
  int32_T c6_d_a;
  int32_T c6_c;
  int32_T c6_b;
  int32_T c6_b_c;
  int32_T c6_e_a;
  int32_T c6_b_b;
  int32_T c6_i142;
  int32_T c6_f_a;
  int32_T c6_c_b;
  int32_T c6_g_a;
  int32_T c6_d_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_d_ix0 = c6_c_ix0;
  c6_d_a = c6_c_n;
  c6_c = c6_d_a;
  c6_b = c6_c - 1;
  c6_b_c = c6_b;
  c6_e_a = c6_c_ix0;
  c6_b_b = c6_b_c;
  c6_i142 = c6_e_a + c6_b_b;
  c6_f_a = c6_d_ix0;
  c6_c_b = c6_i142;
  c6_g_a = c6_f_a;
  c6_d_b = c6_c_b;
  if (c6_g_a > c6_d_b) {
    c6_overflow = FALSE;
  } else {
    c6_overflow = (c6_d_b > 2147483646);
  }

  if (c6_overflow) {
    c6_check_forloop_overflow_error(chartInstance, c6_overflow);
  }

  for (c6_k = c6_d_ix0; c6_k <= c6_i142; c6_k++) {
    c6_b_k = c6_k;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 4, 1, 0) - 1] = c6_c_a * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 4, 1, 0) - 1];
  }
}

static void c6_f_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[24], int32_T c6_ix0, real_T c6_y[6],
  int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i143;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i143 = c6_f_a;
    c6_b = c6_i143;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i143; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 6, 1, 0) - 1] = c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c6_b_c + 1)), 1, 6, 1, 0)
        - 1] + c6_c_a * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c6_c_c + 1)), 1, 24, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_g_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, real_T c6_x[6], int32_T c6_ix0, real_T c6_y[24],
  int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i144;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i144 = c6_f_a;
    c6_b = c6_i144;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i144; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 24, 1, 0) - 1] =
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_b_c + 1)), 1, 24, 1, 0) - 1] + c6_c_a *
        c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c_c + 1)), 1, 6, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_h_eml_xaxpy(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_n, real_T c6_a, int32_T c6_ix0, real_T c6_y[16], int32_T c6_iy0)
{
  int32_T c6_b_n;
  real_T c6_b_a;
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_n;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_d_a;
  int32_T c6_ix;
  int32_T c6_e_a;
  int32_T c6_iy;
  int32_T c6_f_a;
  int32_T c6_i145;
  int32_T c6_b;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_g_a;
  int32_T c6_c;
  int32_T c6_h_a;
  int32_T c6_b_c;
  int32_T c6_i_a;
  int32_T c6_c_c;
  int32_T c6_j_a;
  int32_T c6_k_a;
  c6_b_n = c6_n;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_n = c6_b_n;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  if (c6_c_n < 1) {
  } else if (c6_c_a == 0.0) {
  } else {
    c6_d_a = c6_c_ix0 - 1;
    c6_ix = c6_d_a;
    c6_e_a = c6_c_iy0 - 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_c_n - 1;
    c6_i145 = c6_f_a;
    c6_b = c6_i145;
    c6_b_b = c6_b;
    if (0 > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_k = 0; c6_k <= c6_i145; c6_k++) {
      c6_g_a = c6_iy;
      c6_c = c6_g_a;
      c6_h_a = c6_iy;
      c6_b_c = c6_h_a;
      c6_i_a = c6_ix;
      c6_c_c = c6_i_a;
      c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c + 1)), 1, 16, 1, 0) - 1] =
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_b_c + 1)), 1, 16, 1, 0) - 1] + c6_c_a *
        c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c6_c_c + 1)), 1, 16, 1, 0) - 1];
      c6_j_a = c6_ix + 1;
      c6_ix = c6_j_a;
      c6_k_a = c6_iy + 1;
      c6_iy = c6_k_a;
    }
  }
}

static void c6_g_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[24], int32_T c6_ix0)
{
  real_T c6_b_a;
  int32_T c6_b_ix0;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_d_ix0;
  int32_T c6_d_a;
  int32_T c6_i146;
  int32_T c6_e_a;
  int32_T c6_b;
  int32_T c6_f_a;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_d_ix0 = c6_c_ix0;
  c6_d_a = c6_c_ix0 + 5;
  c6_i146 = c6_d_a;
  c6_e_a = c6_d_ix0;
  c6_b = c6_i146;
  c6_f_a = c6_e_a;
  c6_b_b = c6_b;
  if (c6_f_a > c6_b_b) {
    c6_overflow = FALSE;
  } else {
    c6_overflow = (c6_b_b > 2147483646);
  }

  if (c6_overflow) {
    c6_check_forloop_overflow_error(chartInstance, c6_overflow);
  }

  for (c6_k = c6_d_ix0; c6_k <= c6_i146; c6_k++) {
    c6_b_k = c6_k;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 24, 1, 0) - 1] = c6_c_a * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 24, 1, 0) - 1];
  }
}

static void c6_h_eml_xscal(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_a, real_T c6_x[16], int32_T c6_ix0)
{
  real_T c6_b_a;
  int32_T c6_b_ix0;
  real_T c6_c_a;
  int32_T c6_c_ix0;
  int32_T c6_d_ix0;
  int32_T c6_d_a;
  int32_T c6_i147;
  int32_T c6_e_a;
  int32_T c6_b;
  int32_T c6_f_a;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_k;
  int32_T c6_b_k;
  c6_b_a = c6_a;
  c6_b_ix0 = c6_ix0;
  c6_c_a = c6_b_a;
  c6_c_ix0 = c6_b_ix0;
  c6_d_ix0 = c6_c_ix0;
  c6_d_a = c6_c_ix0 + 3;
  c6_i147 = c6_d_a;
  c6_e_a = c6_d_ix0;
  c6_b = c6_i147;
  c6_f_a = c6_e_a;
  c6_b_b = c6_b;
  if (c6_f_a > c6_b_b) {
    c6_overflow = FALSE;
  } else {
    c6_overflow = (c6_b_b > 2147483646);
  }

  if (c6_overflow) {
    c6_check_forloop_overflow_error(chartInstance, c6_overflow);
  }

  for (c6_k = c6_d_ix0; c6_k <= c6_i147; c6_k++) {
    c6_b_k = c6_k;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 16, 1, 0) - 1] = c6_c_a * c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 16, 1, 0) - 1];
  }
}

static void c6_b_sqrt(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance, real_T
                      *c6_x)
{
  if (*c6_x < 0.0) {
    c6_c_eml_error(chartInstance);
  }

  *c6_x = muDoubleScalarSqrt(*c6_x);
}

static void c6_b_eml_xrotg(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T *c6_a, real_T *c6_b, real_T *c6_c, real_T *c6_s)
{
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_c_b;
  real_T c6_c_a;
  real_T c6_d_a;
  real_T c6_d_b;
  real_T c6_e_b;
  real_T c6_e_a;
  real_T c6_b_c;
  real_T c6_b_s;
  double * c6_a_t;
  double * c6_b_t;
  double * c6_c_t;
  double * c6_s_t;
  real_T c6_c_c;
  real_T c6_c_s;
  c6_b_a = *c6_a;
  c6_b_b = *c6_b;
  c6_c_b = c6_b_b;
  c6_c_a = c6_b_a;
  c6_d_a = c6_c_a;
  c6_d_b = c6_c_b;
  c6_e_b = c6_d_b;
  c6_e_a = c6_d_a;
  c6_b_c = 0.0;
  c6_b_s = 0.0;
  c6_a_t = (double *)(&c6_e_a);
  c6_b_t = (double *)(&c6_e_b);
  c6_c_t = (double *)(&c6_b_c);
  c6_s_t = (double *)(&c6_b_s);
  drotg(c6_a_t, c6_b_t, c6_c_t, c6_s_t);
  c6_c_a = c6_e_a;
  c6_c_b = c6_e_b;
  c6_c_c = c6_b_c;
  c6_c_s = c6_b_s;
  *c6_a = c6_c_a;
  *c6_b = c6_c_b;
  *c6_c = c6_c_c;
  *c6_s = c6_c_s;
}

static void c6_c_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[16], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  real_T c6_b_c;
  real_T c6_b_s;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  real_T c6_c_c;
  real_T c6_c_s;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_a;
  real_T c6_b;
  real_T c6_y;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_b_y;
  real_T c6_temp;
  real_T c6_c_a;
  real_T c6_c_b;
  real_T c6_c_y;
  real_T c6_d_a;
  real_T c6_d_b;
  real_T c6_d_y;
  int32_T c6_e_a;
  int32_T c6_f_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_b_c = c6_c;
  c6_b_s = c6_s;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_c_c = c6_b_c;
  c6_c_s = c6_b_s;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  for (c6_k = 1; c6_k < 5; c6_k++) {
    c6_a = c6_c_c;
    c6_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_ix), 1, 16, 1, 0) - 1];
    c6_y = c6_a * c6_b;
    c6_b_a = c6_c_s;
    c6_b_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_iy), 1, 16, 1, 0) - 1];
    c6_b_y = c6_b_a * c6_b_b;
    c6_temp = c6_y + c6_b_y;
    c6_c_a = c6_c_c;
    c6_c_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_iy), 1, 16, 1, 0) - 1];
    c6_c_y = c6_c_a * c6_c_b;
    c6_d_a = c6_c_s;
    c6_d_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_ix), 1, 16, 1, 0) - 1];
    c6_d_y = c6_d_a * c6_d_b;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 16, 1, 0) - 1] = c6_c_y - c6_d_y;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 16, 1, 0) - 1] = c6_temp;
    c6_e_a = c6_iy + 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_ix + 1;
    c6_ix = c6_f_a;
  }
}

static void c6_d_eml_xrot(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0, real_T c6_c, real_T c6_s)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  real_T c6_b_c;
  real_T c6_b_s;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  real_T c6_c_c;
  real_T c6_c_s;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_a;
  real_T c6_b;
  real_T c6_y;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_b_y;
  real_T c6_temp;
  real_T c6_c_a;
  real_T c6_c_b;
  real_T c6_c_y;
  real_T c6_d_a;
  real_T c6_d_b;
  real_T c6_d_y;
  int32_T c6_e_a;
  int32_T c6_f_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_b_c = c6_c;
  c6_b_s = c6_s;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_c_c = c6_b_c;
  c6_c_s = c6_b_s;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  for (c6_k = 1; c6_k < 7; c6_k++) {
    c6_a = c6_c_c;
    c6_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_ix), 1, 24, 1, 0) - 1];
    c6_y = c6_a * c6_b;
    c6_b_a = c6_c_s;
    c6_b_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_iy), 1, 24, 1, 0) - 1];
    c6_b_y = c6_b_a * c6_b_b;
    c6_temp = c6_y + c6_b_y;
    c6_c_a = c6_c_c;
    c6_c_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_iy), 1, 24, 1, 0) - 1];
    c6_c_y = c6_c_a * c6_c_b;
    c6_d_a = c6_c_s;
    c6_d_b = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_ix), 1, 24, 1, 0) - 1];
    c6_d_y = c6_d_a * c6_d_b;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 24, 1, 0) - 1] = c6_c_y - c6_d_y;
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 24, 1, 0) - 1] = c6_temp;
    c6_e_a = c6_iy + 1;
    c6_iy = c6_e_a;
    c6_f_a = c6_ix + 1;
    c6_ix = c6_f_a;
  }
}

static void c6_c_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[16], int32_T c6_ix0, int32_T c6_iy0)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_temp;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_below_threshold(chartInstance);
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  for (c6_k = 1; c6_k < 5; c6_k++) {
    c6_temp = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c6_ix), 1, 16, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 16, 1, 0) - 1] = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 16, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 16, 1, 0) - 1] = c6_temp;
    c6_a = c6_ix + 1;
    c6_ix = c6_a;
    c6_b_a = c6_iy + 1;
    c6_iy = c6_b_a;
  }
}

static void c6_d_eml_xswap(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  real_T c6_x[24], int32_T c6_ix0, int32_T c6_iy0)
{
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_c_ix0;
  int32_T c6_c_iy0;
  int32_T c6_ix;
  int32_T c6_iy;
  int32_T c6_k;
  real_T c6_temp;
  int32_T c6_a;
  int32_T c6_b_a;
  c6_b_ix0 = c6_ix0;
  c6_b_iy0 = c6_iy0;
  c6_c_ix0 = c6_b_ix0;
  c6_c_iy0 = c6_b_iy0;
  c6_ix = c6_c_ix0;
  c6_iy = c6_c_iy0;
  for (c6_k = 1; c6_k < 7; c6_k++) {
    c6_temp = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c6_ix), 1, 24, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_ix), 1, 24, 1, 0) - 1] = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_iy), 1, 24, 1, 0) - 1];
    c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_iy), 1, 24, 1, 0) - 1] = c6_temp;
    c6_a = c6_ix + 1;
    c6_ix = c6_a;
    c6_b_a = c6_iy + 1;
    c6_iy = c6_b_a;
  }
}

static void c6_b_eml_xgemm(SFc6_SIMULACIO_MGDInstanceStruct *chartInstance,
  int32_T c6_k, real_T c6_A[16], real_T c6_B[24], real_T c6_C[24])
{
  int32_T c6_b_k;
  int32_T c6_c_k;
  int32_T c6_a;
  int32_T c6_km1;
  int32_T c6_cr;
  int32_T c6_b_cr;
  int32_T c6_b_a;
  int32_T c6_i148;
  int32_T c6_c_a;
  int32_T c6_i149;
  int32_T c6_d_a;
  int32_T c6_b;
  int32_T c6_e_a;
  int32_T c6_b_b;
  boolean_T c6_overflow;
  int32_T c6_ic;
  int32_T c6_b_ic;
  int32_T c6_br;
  int32_T c6_c_cr;
  int32_T c6_ar;
  int32_T c6_f_a;
  int32_T c6_b_br;
  int32_T c6_c_b;
  int32_T c6_c;
  int32_T c6_g_a;
  int32_T c6_d_b;
  int32_T c6_i150;
  int32_T c6_h_a;
  int32_T c6_e_b;
  int32_T c6_i_a;
  int32_T c6_f_b;
  boolean_T c6_b_overflow;
  int32_T c6_ib;
  int32_T c6_b_ib;
  real_T c6_temp;
  int32_T c6_ia;
  int32_T c6_j_a;
  int32_T c6_i151;
  int32_T c6_k_a;
  int32_T c6_i152;
  int32_T c6_l_a;
  int32_T c6_g_b;
  int32_T c6_m_a;
  int32_T c6_h_b;
  boolean_T c6_c_overflow;
  int32_T c6_c_ic;
  int32_T c6_n_a;
  int32_T c6_o_a;
  c6_b_k = c6_k;
  c6_c_k = c6_b_k;
  c6_a = c6_c_k;
  c6_km1 = c6_a;
  for (c6_cr = 0; c6_cr < 21; c6_cr += 4) {
    c6_b_cr = c6_cr;
    c6_b_a = c6_b_cr + 1;
    c6_i148 = c6_b_a;
    c6_c_a = c6_b_cr + 4;
    c6_i149 = c6_c_a;
    c6_d_a = c6_i148;
    c6_b = c6_i149;
    c6_e_a = c6_d_a;
    c6_b_b = c6_b;
    if (c6_e_a > c6_b_b) {
      c6_overflow = FALSE;
    } else {
      c6_overflow = (c6_b_b > 2147483646);
    }

    if (c6_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_overflow);
    }

    for (c6_ic = c6_i148; c6_ic <= c6_i149; c6_ic++) {
      c6_b_ic = c6_ic;
      c6_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_b_ic), 1, 24, 1, 0) - 1] = 0.0;
    }
  }

  c6_br = 0;
  for (c6_c_cr = 0; c6_c_cr < 21; c6_c_cr += 4) {
    c6_b_cr = c6_c_cr;
    c6_ar = 0;
    c6_f_a = c6_br + 1;
    c6_br = c6_f_a;
    c6_b_br = c6_br;
    c6_c_b = c6_km1 - 1;
    c6_c = 6 * c6_c_b;
    c6_g_a = c6_br;
    c6_d_b = c6_c;
    c6_i150 = c6_g_a + c6_d_b;
    c6_h_a = c6_b_br;
    c6_e_b = c6_i150;
    c6_i_a = c6_h_a;
    c6_f_b = c6_e_b;
    if (c6_i_a > c6_f_b) {
      c6_b_overflow = FALSE;
    } else {
      c6_b_overflow = (c6_f_b > 2147483641);
    }

    if (c6_b_overflow) {
      c6_check_forloop_overflow_error(chartInstance, c6_b_overflow);
    }

    for (c6_ib = c6_b_br; c6_ib <= c6_i150; c6_ib += 6) {
      c6_b_ib = c6_ib;
      if (c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ib), 1, 24, 1, 0) - 1] != 0.0) {
        c6_temp = c6_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c6_b_ib), 1, 24, 1, 0) - 1];
        c6_ia = c6_ar;
        c6_j_a = c6_b_cr + 1;
        c6_i151 = c6_j_a;
        c6_k_a = c6_b_cr + 4;
        c6_i152 = c6_k_a;
        c6_l_a = c6_i151;
        c6_g_b = c6_i152;
        c6_m_a = c6_l_a;
        c6_h_b = c6_g_b;
        if (c6_m_a > c6_h_b) {
          c6_c_overflow = FALSE;
        } else {
          c6_c_overflow = (c6_h_b > 2147483646);
        }

        if (c6_c_overflow) {
          c6_check_forloop_overflow_error(chartInstance, c6_c_overflow);
        }

        for (c6_c_ic = c6_i151; c6_c_ic <= c6_i152; c6_c_ic++) {
          c6_b_ic = c6_c_ic;
          c6_n_a = c6_ia + 1;
          c6_ia = c6_n_a;
          c6_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ic), 1, 24, 1, 0) - 1] =
            c6_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_b_ic), 1, 24, 1, 0) - 1] + c6_temp *
            c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c6_ia), 1, 16, 1, 0) - 1];
        }
      }

      c6_o_a = c6_ar + 4;
      c6_ar = c6_o_a;
    }
  }
}

static void init_dsm_address_info(SFc6_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c6_SIMULACIO_MGD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1280013797U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(110687047U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3700342329U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1129458463U);
}

mxArray *sf_c6_SIMULACIO_MGD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0pFtxr0N1dew49QQvFlmTC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(6);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_SIMULACIO_MGD_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c6_SIMULACIO_MGD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[25],T\"J_PI\",},{M[1],M[27],T\"S_a\",},{M[1],M[28],T\"d_et\",},{M[8],M[0],T\"is_active_c6_SIMULACIO_MGD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_SIMULACIO_MGD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
    chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SIMULACIO_MGDMachineNumber_,
           6,
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
          init_script_number_translation(_SIMULACIO_MGDMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_SIMULACIO_MGDMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _SIMULACIO_MGDMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ja");
          _SFD_SET_DATA_PROPS(1,2,0,1,"J_PI");
          _SFD_SET_DATA_PROPS(2,2,0,1,"S_a");
          _SFD_SET_DATA_PROPS(3,2,0,1,"d_et");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,581);
        _SFD_CV_INIT_EML_IF(0,1,0,162,182,228,291);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)
            c6_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_S_a;
          real_T *c6_d_et;
          real_T (*c6_Ja)[24];
          real_T (*c6_J_PI)[24];
          c6_d_et = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c6_S_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c6_J_PI = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_Ja = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_Ja);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_J_PI);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_S_a);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_d_et);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _SIMULACIO_MGDMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "WamA6i9j8Y7d2ASGwlAHh";
}

static void sf_opaque_initialize_c6_SIMULACIO_MGD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar);
  initialize_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_SIMULACIO_MGD(void *chartInstanceVar)
{
  enable_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_SIMULACIO_MGD(void *chartInstanceVar)
{
  disable_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_SIMULACIO_MGD(void *chartInstanceVar)
{
  sf_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_SIMULACIO_MGD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_SIMULACIO_MGD
    ((SFc6_SIMULACIO_MGDInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_SIMULACIO_MGD();/* state var info */
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

extern void sf_internal_set_sim_state_c6_SIMULACIO_MGD(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_SIMULACIO_MGD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_SIMULACIO_MGD(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_SIMULACIO_MGD(S);
}

static void sf_opaque_set_sim_state_c6_SIMULACIO_MGD(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c6_SIMULACIO_MGD(S, st);
}

static void sf_opaque_terminate_c6_SIMULACIO_MGD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_SIMULACIO_MGDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SIMULACIO_MGD_optimization_info();
    }

    finalize_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_SIMULACIO_MGD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_SIMULACIO_MGD((SFc6_SIMULACIO_MGDInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_SIMULACIO_MGD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SIMULACIO_MGD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1075591818U));
  ssSetChecksum1(S,(284262277U));
  ssSetChecksum2(S,(1412589395U));
  ssSetChecksum3(S,(1009599468U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_SIMULACIO_MGD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_SIMULACIO_MGD(SimStruct *S)
{
  SFc6_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACIO_MGDInstanceStruct *)utMalloc(sizeof
    (SFc6_SIMULACIO_MGDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_SIMULACIO_MGDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_SIMULACIO_MGD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_SIMULACIO_MGD;
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

void c6_SIMULACIO_MGD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_SIMULACIO_MGD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_SIMULACIO_MGD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_SIMULACIO_MGD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_SIMULACIO_MGD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
