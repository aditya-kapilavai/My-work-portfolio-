/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CONTROL_POSICION_sfun.h"
#include "c2_CONTROL_POSICION.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CONTROL_POSICION_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[40] = { "q1", "q2", "q3", "q4", "qt",
  "d2", "a2", "a3", "a4", "a5", "a6", "H", "Pxyz", "R", "r21", "r11", "r31",
  "r32", "r33", "th", "ga", "al", "Theta", "Jg", "Tphi", "iTphi", "Ta_phi", "Ja",
  "U", "S", "V", "lambda", "J_ainv", "Xp", "nargin", "nargout", "q", "ex", "qp",
  "X" };

/* Function Declarations */
static void initialize_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void initialize_params_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void enable_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void disable_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void set_sim_state_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void sf_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void initSimStructsc2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void registerMessagesc2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_X, const char_T *c2_identifier, real_T c2_y
  [6]);
static void c2_b_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_qp, const char_T *c2_identifier, real_T
  c2_y[4]);
static void c2_d_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_i_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[36]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_j_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_k_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[269]);
static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[269]);
static void c2_c_info_helper(c2_ResolvedFunctionInfo c2_info[269]);
static void c2_d_info_helper(c2_ResolvedFunctionInfo c2_info[269]);
static void c2_e_info_helper(c2_ResolvedFunctionInfo c2_info[269]);
static real_T c2_atan2(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_y, real_T c2_x);
static void c2_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static real_T c2_mpower(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a);
static real_T c2_sqrt(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      c2_x);
static void c2_eml_error(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void c2_inv(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                   c2_x[9], real_T c2_y[9]);
static void c2_inv3x3(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      c2_x[9], real_T c2_y[9]);
static real_T c2_abs(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                     c2_x);
static real_T c2_eml_div(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x, real_T c2_y);
static real_T c2_norm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      c2_x[9]);
static void c2_eml_warning(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void c2_eps(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void c2_b_eml_warning(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  char_T c2_varargin_2[14]);
static void c2_eye(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                   c2_I[9]);
static void c2_b_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_c_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_svd(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                   c2_A[24], real_T c2_U[36], real_T c2_S[24], real_T c2_V[16]);
static void c2_b_eml_error(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void c2_eml_xgesvd(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[24], real_T c2_U[36], real_T c2_S[4], real_T c2_V[16]);
static real_T c2_eml_xnrm2(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[24], int32_T c2_ix0);
static void c2_realmin(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void c2_check_forloop_overflow_error(SFc2_CONTROL_POSICIONInstanceStruct *
  chartInstance, boolean_T c2_overflow);
static void c2_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0, real_T c2_b_x[24]);
static real_T c2_eml_xdotc(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[24], int32_T c2_ix0, real_T c2_y[24], int32_T c2_iy0);
static void c2_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[24], int32_T c2_iy0,
  real_T c2_b_y[24]);
static real_T c2_b_eml_xnrm2(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[4], int32_T c2_ix0);
static void c2_b_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0, real_T c2_b_x[4]);
static void c2_b_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0, real_T c2_y[6],
  int32_T c2_iy0, real_T c2_b_y[6]);
static void c2_c_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[6], int32_T c2_ix0, real_T c2_y[24],
  int32_T c2_iy0, real_T c2_b_y[24]);
static real_T c2_b_eml_xdotc(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[36], int32_T c2_ix0, real_T c2_y[36], int32_T c2_iy0);
static void c2_d_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[36], int32_T c2_iy0,
  real_T c2_b_y[36]);
static real_T c2_c_eml_xdotc(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0);
static void c2_e_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0,
  real_T c2_b_y[16]);
static void c2_d_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_c_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[36], int32_T c2_ix0, real_T c2_b_x[36]);
static void c2_d_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[16], int32_T c2_ix0, real_T c2_b_x[16]);
static void c2_c_eml_error(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance);
static void c2_eml_xrotg(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_b, real_T *c2_b_a, real_T *c2_b_b, real_T *c2_c, real_T
  *c2_s);
static void c2_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s,
  real_T c2_b_x[16]);
static void c2_b_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s,
  real_T c2_b_x[36]);
static void c2_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0, real_T c2_b_x[16]);
static void c2_below_threshold(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_b_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0, real_T c2_b_x[36]);
static void c2_e_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_mldivide(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24], real_T c2_Y[24]);
static void c2_eml_matlab_zgetrf(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, real_T c2_A[16], real_T c2_b_A[16], int32_T c2_ipiv[4],
  int32_T *c2_info);
static void c2_eml_xger(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[16], int32_T c2_ia0, real_T c2_b_A[16]);
static void c2_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24], real_T c2_b_B[24]);
static void c2_b_below_threshold(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_f_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_b_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24], real_T c2_b_B[24]);
static void c2_g_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_h_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);
static void c2_l_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_y[14]);
static void c2_m_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[14]);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_n_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_o_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CONTROL_POSICION, const
  char_T *c2_identifier);
static uint8_T c2_p_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      *c2_x);
static void c2_e_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0);
static void c2_f_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[24], int32_T c2_iy0);
static void c2_f_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0);
static void c2_g_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0, real_T c2_y[6],
  int32_T c2_iy0);
static void c2_h_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[6], int32_T c2_ix0, real_T c2_y[24],
  int32_T c2_iy0);
static void c2_i_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[36], int32_T c2_iy0);
static void c2_j_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0);
static void c2_g_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[36], int32_T c2_ix0);
static void c2_h_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[16], int32_T c2_ix0);
static void c2_b_eml_xrotg(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T *c2_a, real_T *c2_b, real_T *c2_c, real_T *c2_s);
static void c2_c_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s);
static void c2_d_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s);
static void c2_c_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0);
static void c2_d_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0);
static void c2_b_eml_matlab_zgetrf(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, real_T c2_A[16], int32_T c2_ipiv[4], int32_T *c2_info);
static void c2_b_eml_xger(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[16], int32_T c2_ia0);
static void c2_c_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24]);
static void c2_d_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24]);
static void init_dsm_address_info(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_CONTROL_POSICION = 0U;
}

static void initialize_params_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
}

static void enable_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[6];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[4];
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T (*c2_qp)[4];
  real_T (*c2_X)[6];
  c2_X = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0++) {
    c2_u[c2_i0] = (*c2_X)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_qp)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_CONTROL_POSICION;
  c2_c_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[6];
  int32_T c2_i2;
  real_T c2_dv1[4];
  int32_T c2_i3;
  real_T (*c2_X)[6];
  real_T (*c2_qp)[4];
  c2_X = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "X",
                      c2_dv0);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    (*c2_X)[c2_i2] = c2_dv0[c2_i2];
  }

  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "qp",
                        c2_dv1);
  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    (*c2_qp)[c2_i3] = c2_dv1[c2_i3];
  }

  chartInstance->c2_is_active_c2_CONTROL_POSICION = c2_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_CONTROL_POSICION");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_CONTROL_POSICION(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void sf_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  real_T (*c2_X)[6];
  real_T (*c2_qp)[4];
  real_T (*c2_ex)[6];
  real_T (*c2_q)[4];
  c2_X = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_ex = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c2_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_q)[c2_i4], 0U);
  }

  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_ex)[c2_i5], 1U);
  }

  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*c2_qp)[c2_i6], 2U);
  }

  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_X)[c2_i7], 3U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_CONTROL_POSICION(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CONTROL_POSICIONMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_CONTROL_POSICION(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
  int32_T c2_i8;
  real_T c2_q[4];
  int32_T c2_i9;
  real_T c2_ex[6];
  uint32_T c2_debug_family_var_map[40];
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
  real_T c2_th;
  real_T c2_ga;
  real_T c2_al;
  real_T c2_Theta[3];
  real_T c2_Jg[24];
  real_T c2_Tphi[9];
  real_T c2_iTphi[9];
  real_T c2_Ta_phi[36];
  real_T c2_Ja[24];
  real_T c2_U[36];
  real_T c2_S[24];
  real_T c2_V[16];
  real_T c2_lambda;
  real_T c2_J_ainv[24];
  real_T c2_Xp[6];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 2.0;
  real_T c2_qp[4];
  real_T c2_X[6];
  real_T c2_b_q1[4];
  int32_T c2_i10;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_c_a;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_h_b;
  real_T c2_h_y;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_i_b;
  real_T c2_i_y;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_j_b;
  real_T c2_j_y;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_k_b;
  real_T c2_k_y;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_d_a;
  real_T c2_l_b;
  real_T c2_l_y;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_e_a;
  real_T c2_m_b;
  real_T c2_m_y;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_n_b;
  real_T c2_n_y;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_f_a;
  real_T c2_o_b;
  real_T c2_o_y;
  real_T c2_g_a;
  real_T c2_p_y;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_h_a;
  real_T c2_p_b;
  real_T c2_q_y;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_i_a;
  real_T c2_q_b;
  real_T c2_r_y;
  real_T c2_j_a;
  real_T c2_s_y;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_k_a;
  real_T c2_r_b;
  real_T c2_t_y;
  real_T c2_ic_x;
  real_T c2_jc_x;
  real_T c2_l_a;
  real_T c2_s_b;
  real_T c2_u_y;
  real_T c2_m_a;
  real_T c2_v_y;
  int32_T c2_i11;
  int32_T c2_i12;
  static real_T c2_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  real_T c2_b_H[3];
  int32_T c2_i13;
  real_T c2_kc_x;
  real_T c2_lc_x;
  real_T c2_mc_x;
  real_T c2_nc_x;
  real_T c2_n_a;
  real_T c2_t_b;
  real_T c2_w_y;
  real_T c2_oc_x;
  real_T c2_pc_x;
  real_T c2_qc_x;
  real_T c2_rc_x;
  real_T c2_o_a;
  real_T c2_u_b;
  real_T c2_x_y;
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
  real_T c2_y_y;
  real_T c2_dd_x;
  real_T c2_ed_x;
  real_T c2_fd_x;
  real_T c2_gd_x;
  real_T c2_q_a;
  real_T c2_w_b;
  real_T c2_ab_y;
  real_T c2_hd_x;
  real_T c2_id_x;
  real_T c2_d0;
  real_T c2_b_al[3];
  int32_T c2_i14;
  real_T c2_jd_x;
  real_T c2_kd_x;
  real_T c2_ld_x;
  real_T c2_md_x;
  real_T c2_x_b;
  real_T c2_bb_y;
  real_T c2_nd_x;
  real_T c2_od_x;
  real_T c2_y_b;
  real_T c2_cb_y;
  real_T c2_pd_x;
  real_T c2_qd_x;
  real_T c2_ab_b;
  real_T c2_db_y;
  real_T c2_rd_x;
  real_T c2_sd_x;
  real_T c2_bb_b;
  real_T c2_eb_y;
  real_T c2_r_a;
  real_T c2_cb_b;
  real_T c2_fb_y;
  real_T c2_td_x;
  real_T c2_ud_x;
  real_T c2_vd_x;
  real_T c2_wd_x;
  real_T c2_db_b;
  real_T c2_gb_y;
  real_T c2_xd_x;
  real_T c2_yd_x;
  real_T c2_eb_b;
  real_T c2_hb_y;
  real_T c2_ae_x;
  real_T c2_be_x;
  real_T c2_fb_b;
  real_T c2_ib_y;
  real_T c2_ce_x;
  real_T c2_de_x;
  real_T c2_gb_b;
  real_T c2_jb_y;
  real_T c2_s_a;
  real_T c2_hb_b;
  real_T c2_kb_y;
  real_T c2_ee_x;
  real_T c2_fe_x;
  real_T c2_ge_x;
  real_T c2_he_x;
  real_T c2_t_a;
  real_T c2_ib_b;
  real_T c2_lb_y;
  real_T c2_u_a;
  real_T c2_mb_y;
  real_T c2_ie_x;
  real_T c2_je_x;
  real_T c2_jb_b;
  real_T c2_nb_y;
  real_T c2_ke_x;
  real_T c2_le_x;
  real_T c2_kb_b;
  real_T c2_ob_y;
  real_T c2_me_x;
  real_T c2_ne_x;
  real_T c2_lb_b;
  real_T c2_pb_y;
  real_T c2_oe_x;
  real_T c2_pe_x;
  real_T c2_mb_b;
  real_T c2_qb_y;
  real_T c2_qe_x;
  real_T c2_re_x;
  real_T c2_v_a;
  real_T c2_rb_y;
  real_T c2_se_x;
  real_T c2_te_x;
  real_T c2_ue_x;
  real_T c2_ve_x;
  real_T c2_nb_b;
  real_T c2_sb_y;
  real_T c2_we_x;
  real_T c2_xe_x;
  real_T c2_ob_b;
  real_T c2_tb_y;
  real_T c2_ye_x;
  real_T c2_af_x;
  real_T c2_pb_b;
  real_T c2_ub_y;
  real_T c2_bf_x;
  real_T c2_cf_x;
  real_T c2_qb_b;
  real_T c2_vb_y;
  real_T c2_w_a;
  real_T c2_rb_b;
  real_T c2_wb_y;
  real_T c2_df_x;
  real_T c2_ef_x;
  real_T c2_ff_x;
  real_T c2_gf_x;
  real_T c2_sb_b;
  real_T c2_xb_y;
  real_T c2_hf_x;
  real_T c2_if_x;
  real_T c2_tb_b;
  real_T c2_yb_y;
  real_T c2_jf_x;
  real_T c2_kf_x;
  real_T c2_ub_b;
  real_T c2_ac_y;
  real_T c2_lf_x;
  real_T c2_mf_x;
  real_T c2_vb_b;
  real_T c2_bc_y;
  real_T c2_x_a;
  real_T c2_wb_b;
  real_T c2_cc_y;
  real_T c2_nf_x;
  real_T c2_of_x;
  real_T c2_pf_x;
  real_T c2_qf_x;
  real_T c2_y_a;
  real_T c2_xb_b;
  real_T c2_dc_y;
  real_T c2_ab_a;
  real_T c2_ec_y;
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
  real_T c2_fc_y;
  real_T c2_eg_x;
  real_T c2_fg_x;
  real_T c2_gg_x;
  real_T c2_hg_x;
  real_T c2_ig_x;
  real_T c2_jg_x;
  real_T c2_cb_a;
  real_T c2_ac_b;
  real_T c2_gc_y;
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
  real_T c2_b_Ja[24];
  real_T c2_b_V[16];
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  real_T c2_eb_a[24];
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  static real_T c2_hc_y[16] = { 0.01, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
    0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 0.01 };

  real_T c2_c_V[16];
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  real_T c2_c_Ja[24];
  real_T c2_dv6[24];
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  real_T c2_d_V[16];
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  real_T c2_d_Ja[24];
  real_T c2_dv7[24];
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  real_T c2_u[6];
  const mxArray *c2_ic_y = NULL;
  int32_T c2_i87;
  int32_T c2_i88;
  real_T c2_cc_b[6];
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  real_T c2_b_C[4];
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  int32_T c2_i105;
  int32_T c2_i106;
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i110;
  real_T (*c2_b_qp)[4];
  real_T (*c2_b_X)[6];
  real_T (*c2_b_ex)[6];
  real_T (*c2_b_q)[4];
  c2_b_X = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_ex = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
    c2_q[c2_i8] = (*c2_b_q)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 6; c2_i9++) {
    c2_ex[c2_i9] = (*c2_b_ex)[c2_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 40U, 40U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q1, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q2, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q3, 2U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q4, 3U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_qt, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d2, 5U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_a2, 6U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_a3, 7U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_a4, 8U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_a5, 9U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_a6, 10U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_H, 11U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Pxyz, 12U, c2_i_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R, 13U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_r21, 14U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_r11, 15U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_r31, 16U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_r32, 17U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_r33, 18U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_th, 19U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ga, 20U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_al, 21U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Theta, 22U, c2_i_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jg, 23U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Tphi, 24U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_iTphi, 25U, c2_h_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Ta_phi, 26U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Ja, 27U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_U, 28U, c2_g_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_S, 29U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_V, 30U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_lambda, 31U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_J_ainv, 32U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Xp, 33U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 34U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 35U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_q, 36U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_ex, 37U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_qp, 38U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_X, 39U, c2_sf_marshallOut,
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
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_b_q1[0] = c2_q1;
  c2_b_q1[1] = c2_q2;
  c2_b_q1[2] = c2_q3;
  c2_b_q1[3] = c2_q4;
  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_qt[c2_i10] = c2_b_q1[c2_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_d2 = 1.20349;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_a5 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_a6 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_x = c2_q3 + c2_q4;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_q2;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_a = -c2_b_x;
  c2_b = c2_d_x;
  c2_y = c2_a * c2_b;
  c2_e_x = c2_q3 + c2_q4;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_q2;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_b_a = c2_f_x;
  c2_b_b = c2_h_x;
  c2_b_y = c2_b_a * c2_b_b;
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
  c2_c_y = 0.8862 * c2_c_b;
  c2_o_x = c2_q3 + c2_q4;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarCos(c2_p_x);
  c2_d_b = c2_p_x;
  c2_d_y = 1.5 * c2_d_b;
  c2_q_x = c2_q3;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarCos(c2_r_x);
  c2_e_b = c2_r_x;
  c2_e_y = 0.8862 * c2_e_b;
  c2_s_x = c2_q3;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_f_b = c2_t_x;
  c2_f_y = 1.5 * c2_f_b;
  c2_c_a = -c2_l_x;
  c2_g_b = (((c2_a2 + c2_c_y) + c2_d_y) + c2_e_y) + c2_f_y;
  c2_g_y = c2_c_a * c2_g_b;
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
  c2_h_y = 0.8862 * c2_h_b;
  c2_bb_x = c2_q3 + c2_q4;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarSin(c2_cb_x);
  c2_i_b = c2_cb_x;
  c2_i_y = 1.5 * c2_i_b;
  c2_db_x = c2_q3;
  c2_eb_x = c2_db_x;
  c2_eb_x = muDoubleScalarSin(c2_eb_x);
  c2_j_b = c2_eb_x;
  c2_j_y = 0.8862 * c2_j_b;
  c2_fb_x = c2_q3;
  c2_gb_x = c2_fb_x;
  c2_gb_x = muDoubleScalarSin(c2_gb_x);
  c2_k_b = c2_gb_x;
  c2_k_y = 1.5 * c2_k_b;
  c2_hb_x = c2_q3 + c2_q4;
  c2_ib_x = c2_hb_x;
  c2_ib_x = muDoubleScalarCos(c2_ib_x);
  c2_jb_x = c2_q2;
  c2_kb_x = c2_jb_x;
  c2_kb_x = muDoubleScalarCos(c2_kb_x);
  c2_d_a = c2_ib_x;
  c2_l_b = c2_kb_x;
  c2_l_y = c2_d_a * c2_l_b;
  c2_lb_x = c2_q3 + c2_q4;
  c2_mb_x = c2_lb_x;
  c2_mb_x = muDoubleScalarSin(c2_mb_x);
  c2_nb_x = c2_q2;
  c2_ob_x = c2_nb_x;
  c2_ob_x = muDoubleScalarCos(c2_ob_x);
  c2_e_a = -c2_mb_x;
  c2_m_b = c2_ob_x;
  c2_m_y = c2_e_a * c2_m_b;
  c2_pb_x = c2_q2;
  c2_qb_x = c2_pb_x;
  c2_qb_x = muDoubleScalarSin(c2_qb_x);
  c2_rb_x = c2_q2;
  c2_sb_x = c2_rb_x;
  c2_sb_x = muDoubleScalarCos(c2_sb_x);
  c2_n_b = c2_sb_x;
  c2_n_y = 0.9907 * c2_n_b;
  c2_tb_x = c2_q2;
  c2_ub_x = c2_tb_x;
  c2_ub_x = muDoubleScalarCos(c2_ub_x);
  c2_vb_x = c2_q3;
  c2_wb_x = c2_vb_x;
  c2_wb_x = muDoubleScalarCos(c2_wb_x);
  c2_f_a = c2_ub_x;
  c2_o_b = c2_wb_x;
  c2_o_y = c2_f_a * c2_o_b;
  c2_g_a = c2_o_y;
  c2_p_y = c2_g_a * 2.3862;
  c2_xb_x = c2_q2;
  c2_yb_x = c2_xb_x;
  c2_yb_x = muDoubleScalarCos(c2_yb_x);
  c2_ac_x = c2_q3;
  c2_bc_x = c2_ac_x;
  c2_bc_x = muDoubleScalarSin(c2_bc_x);
  c2_h_a = c2_yb_x;
  c2_p_b = c2_bc_x;
  c2_q_y = c2_h_a * c2_p_b;
  c2_cc_x = c2_q4;
  c2_dc_x = c2_cc_x;
  c2_dc_x = muDoubleScalarSin(c2_dc_x);
  c2_i_a = c2_q_y;
  c2_q_b = c2_dc_x;
  c2_r_y = c2_i_a * c2_q_b;
  c2_j_a = c2_r_y;
  c2_s_y = c2_j_a * 2.3862;
  c2_ec_x = c2_q2;
  c2_fc_x = c2_ec_x;
  c2_fc_x = muDoubleScalarCos(c2_fc_x);
  c2_gc_x = c2_q3;
  c2_hc_x = c2_gc_x;
  c2_hc_x = muDoubleScalarCos(c2_hc_x);
  c2_k_a = c2_fc_x;
  c2_r_b = c2_hc_x;
  c2_t_y = c2_k_a * c2_r_b;
  c2_ic_x = c2_q4;
  c2_jc_x = c2_ic_x;
  c2_jc_x = muDoubleScalarCos(c2_jc_x);
  c2_l_a = c2_t_y;
  c2_s_b = c2_jc_x;
  c2_u_y = c2_l_a * c2_s_b;
  c2_m_a = c2_u_y;
  c2_v_y = c2_m_a * 2.3862;
  c2_H[0] = c2_y;
  c2_H[4] = c2_b_y;
  c2_H[8] = c2_j_x;
  c2_H[12] = c2_g_y;
  c2_H[1] = -c2_v_x;
  c2_H[5] = -c2_x_x;
  c2_H[9] = 0.0;
  c2_H[13] = (((-c2_d2 - c2_h_y) - c2_i_y) - c2_j_y) - c2_k_y;
  c2_H[2] = c2_l_y;
  c2_H[6] = c2_m_y;
  c2_H[10] = c2_qb_x;
  c2_H[14] = (((c2_q1 + c2_n_y) + c2_p_y) - c2_s_y) + c2_v_y;
  c2_i11 = 0;
  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    c2_H[c2_i11 + 3] = c2_dv2[c2_i12];
    c2_i11 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_b_H[0] = c2_H[12];
  c2_b_H[1] = c2_H[13];
  c2_b_H[2] = c2_H[14];
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_Pxyz[c2_i13] = c2_b_H[c2_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_kc_x = c2_q3 + c2_q4;
  c2_lc_x = c2_kc_x;
  c2_lc_x = muDoubleScalarCos(c2_lc_x);
  c2_mc_x = c2_q2;
  c2_nc_x = c2_mc_x;
  c2_nc_x = muDoubleScalarSin(c2_nc_x);
  c2_n_a = -c2_lc_x;
  c2_t_b = c2_nc_x;
  c2_w_y = c2_n_a * c2_t_b;
  c2_oc_x = c2_q3 + c2_q4;
  c2_pc_x = c2_oc_x;
  c2_pc_x = muDoubleScalarSin(c2_pc_x);
  c2_qc_x = c2_q2;
  c2_rc_x = c2_qc_x;
  c2_rc_x = muDoubleScalarSin(c2_rc_x);
  c2_o_a = c2_pc_x;
  c2_u_b = c2_rc_x;
  c2_x_y = c2_o_a * c2_u_b;
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
  c2_y_y = c2_p_a * c2_v_b;
  c2_dd_x = c2_q3 + c2_q4;
  c2_ed_x = c2_dd_x;
  c2_ed_x = muDoubleScalarSin(c2_ed_x);
  c2_fd_x = c2_q2;
  c2_gd_x = c2_fd_x;
  c2_gd_x = muDoubleScalarCos(c2_gd_x);
  c2_q_a = -c2_ed_x;
  c2_w_b = c2_gd_x;
  c2_ab_y = c2_q_a * c2_w_b;
  c2_hd_x = c2_q2;
  c2_id_x = c2_hd_x;
  c2_id_x = muDoubleScalarSin(c2_id_x);
  c2_R[0] = c2_w_y;
  c2_R[3] = c2_x_y;
  c2_R[6] = c2_tc_x;
  c2_R[1] = -c2_vc_x;
  c2_R[4] = -c2_xc_x;
  c2_R[7] = 0.0;
  c2_R[2] = c2_y_y;
  c2_R[5] = c2_ab_y;
  c2_R[8] = c2_id_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_r21 = c2_R[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  c2_r11 = c2_R[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_r31 = c2_R[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
  c2_r32 = c2_R[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
  c2_r33 = c2_R[8];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_th = c2_atan2(chartInstance, c2_r21, c2_r11);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  c2_d0 = c2_mpower(chartInstance, c2_r32) + c2_mpower(chartInstance, c2_r33);
  c2_b_sqrt(chartInstance, &c2_d0);
  c2_ga = c2_atan2(chartInstance, -c2_r31, c2_d0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
  c2_al = c2_atan2(chartInstance, c2_r32, c2_r33);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
  c2_b_al[0] = c2_al;
  c2_b_al[1] = c2_ga;
  c2_b_al[2] = c2_th;
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    c2_Theta[c2_i14] = c2_b_al[c2_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
  c2_jd_x = c2_q2;
  c2_kd_x = c2_jd_x;
  c2_kd_x = muDoubleScalarCos(c2_kd_x);
  c2_ld_x = c2_q3 + c2_q4;
  c2_md_x = c2_ld_x;
  c2_md_x = muDoubleScalarCos(c2_md_x);
  c2_x_b = c2_md_x;
  c2_bb_y = 0.8862 * c2_x_b;
  c2_nd_x = c2_q3 + c2_q4;
  c2_od_x = c2_nd_x;
  c2_od_x = muDoubleScalarCos(c2_od_x);
  c2_y_b = c2_od_x;
  c2_cb_y = 1.5 * c2_y_b;
  c2_pd_x = c2_q3;
  c2_qd_x = c2_pd_x;
  c2_qd_x = muDoubleScalarCos(c2_qd_x);
  c2_ab_b = c2_qd_x;
  c2_db_y = 0.8862 * c2_ab_b;
  c2_rd_x = c2_q3;
  c2_sd_x = c2_rd_x;
  c2_sd_x = muDoubleScalarCos(c2_sd_x);
  c2_bb_b = c2_sd_x;
  c2_eb_y = 1.5 * c2_bb_b;
  c2_r_a = -c2_kd_x;
  c2_cb_b = (((c2_a2 + c2_bb_y) + c2_cb_y) + c2_db_y) + c2_eb_y;
  c2_fb_y = c2_r_a * c2_cb_b;
  c2_td_x = c2_q2;
  c2_ud_x = c2_td_x;
  c2_ud_x = muDoubleScalarSin(c2_ud_x);
  c2_vd_x = c2_q3 + c2_q4;
  c2_wd_x = c2_vd_x;
  c2_wd_x = muDoubleScalarSin(c2_wd_x);
  c2_db_b = c2_wd_x;
  c2_gb_y = 0.8862 * c2_db_b;
  c2_xd_x = c2_q3 + c2_q4;
  c2_yd_x = c2_xd_x;
  c2_yd_x = muDoubleScalarSin(c2_yd_x);
  c2_eb_b = c2_yd_x;
  c2_hb_y = 1.5 * c2_eb_b;
  c2_ae_x = c2_q3;
  c2_be_x = c2_ae_x;
  c2_be_x = muDoubleScalarSin(c2_be_x);
  c2_fb_b = c2_be_x;
  c2_ib_y = 0.8862 * c2_fb_b;
  c2_ce_x = c2_q3;
  c2_de_x = c2_ce_x;
  c2_de_x = muDoubleScalarSin(c2_de_x);
  c2_gb_b = c2_de_x;
  c2_jb_y = 1.5 * c2_gb_b;
  c2_s_a = c2_ud_x;
  c2_hb_b = ((c2_gb_y + c2_hb_y) + c2_ib_y) + c2_jb_y;
  c2_kb_y = c2_s_a * c2_hb_b;
  c2_ee_x = c2_q3 + c2_q4;
  c2_fe_x = c2_ee_x;
  c2_fe_x = muDoubleScalarSin(c2_fe_x);
  c2_ge_x = c2_q2;
  c2_he_x = c2_ge_x;
  c2_he_x = muDoubleScalarSin(c2_he_x);
  c2_t_a = c2_fe_x;
  c2_ib_b = c2_he_x;
  c2_lb_y = c2_t_a * c2_ib_b;
  c2_u_a = c2_lb_y;
  c2_mb_y = c2_u_a * 2.3862;
  c2_ie_x = c2_q3 + c2_q4;
  c2_je_x = c2_ie_x;
  c2_je_x = muDoubleScalarCos(c2_je_x);
  c2_jb_b = c2_je_x;
  c2_nb_y = -0.8862 * c2_jb_b;
  c2_ke_x = c2_q3 + c2_q4;
  c2_le_x = c2_ke_x;
  c2_le_x = muDoubleScalarCos(c2_le_x);
  c2_kb_b = c2_le_x;
  c2_ob_y = 1.5 * c2_kb_b;
  c2_me_x = c2_q3;
  c2_ne_x = c2_me_x;
  c2_ne_x = muDoubleScalarCos(c2_ne_x);
  c2_lb_b = c2_ne_x;
  c2_pb_y = 0.8862 * c2_lb_b;
  c2_oe_x = c2_q3;
  c2_pe_x = c2_oe_x;
  c2_pe_x = muDoubleScalarCos(c2_pe_x);
  c2_mb_b = c2_pe_x;
  c2_qb_y = 1.5 * c2_mb_b;
  c2_qe_x = c2_q3 + c2_q4;
  c2_re_x = c2_qe_x;
  c2_re_x = muDoubleScalarCos(c2_re_x);
  c2_v_a = -c2_re_x;
  c2_rb_y = c2_v_a * 2.3862;
  c2_se_x = c2_q2;
  c2_te_x = c2_se_x;
  c2_te_x = muDoubleScalarSin(c2_te_x);
  c2_ue_x = c2_q3 + c2_q4;
  c2_ve_x = c2_ue_x;
  c2_ve_x = muDoubleScalarCos(c2_ve_x);
  c2_nb_b = c2_ve_x;
  c2_sb_y = 0.8862 * c2_nb_b;
  c2_we_x = c2_q3 + c2_q4;
  c2_xe_x = c2_we_x;
  c2_xe_x = muDoubleScalarCos(c2_xe_x);
  c2_ob_b = c2_xe_x;
  c2_tb_y = 1.5 * c2_ob_b;
  c2_ye_x = c2_q3;
  c2_af_x = c2_ye_x;
  c2_af_x = muDoubleScalarCos(c2_af_x);
  c2_pb_b = c2_af_x;
  c2_ub_y = 0.8862 * c2_pb_b;
  c2_bf_x = c2_q3;
  c2_cf_x = c2_bf_x;
  c2_cf_x = muDoubleScalarCos(c2_cf_x);
  c2_qb_b = c2_cf_x;
  c2_vb_y = 1.5 * c2_qb_b;
  c2_w_a = -c2_te_x;
  c2_rb_b = (((c2_a2 + c2_sb_y) + c2_tb_y) + c2_ub_y) + c2_vb_y;
  c2_wb_y = c2_w_a * c2_rb_b;
  c2_df_x = c2_q2;
  c2_ef_x = c2_df_x;
  c2_ef_x = muDoubleScalarCos(c2_ef_x);
  c2_ff_x = c2_q3 + c2_q4;
  c2_gf_x = c2_ff_x;
  c2_gf_x = muDoubleScalarSin(c2_gf_x);
  c2_sb_b = c2_gf_x;
  c2_xb_y = 0.8862 * c2_sb_b;
  c2_hf_x = c2_q3 + c2_q4;
  c2_if_x = c2_hf_x;
  c2_if_x = muDoubleScalarSin(c2_if_x);
  c2_tb_b = c2_if_x;
  c2_yb_y = 1.5 * c2_tb_b;
  c2_jf_x = c2_q3;
  c2_kf_x = c2_jf_x;
  c2_kf_x = muDoubleScalarSin(c2_kf_x);
  c2_ub_b = c2_kf_x;
  c2_ac_y = 0.8862 * c2_ub_b;
  c2_lf_x = c2_q3;
  c2_mf_x = c2_lf_x;
  c2_mf_x = muDoubleScalarSin(c2_mf_x);
  c2_vb_b = c2_mf_x;
  c2_bc_y = 1.5 * c2_vb_b;
  c2_x_a = -c2_ef_x;
  c2_wb_b = ((c2_xb_y + c2_yb_y) + c2_ac_y) + c2_bc_y;
  c2_cc_y = c2_x_a * c2_wb_b;
  c2_nf_x = c2_q3 + c2_q4;
  c2_of_x = c2_nf_x;
  c2_of_x = muDoubleScalarSin(c2_of_x);
  c2_pf_x = c2_q2;
  c2_qf_x = c2_pf_x;
  c2_qf_x = muDoubleScalarCos(c2_qf_x);
  c2_y_a = -c2_of_x;
  c2_xb_b = c2_qf_x;
  c2_dc_y = c2_y_a * c2_xb_b;
  c2_ab_a = c2_dc_y;
  c2_ec_y = c2_ab_a * 2.3862;
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
  c2_Jg[6] = c2_fb_y;
  c2_Jg[12] = c2_kb_y;
  c2_Jg[18] = c2_mb_y;
  c2_Jg[1] = 0.0;
  c2_Jg[7] = 0.0;
  c2_Jg[13] = ((c2_nb_y - c2_ob_y) - c2_pb_y) - c2_qb_y;
  c2_Jg[19] = c2_rb_y;
  c2_Jg[2] = 1.0;
  c2_Jg[8] = c2_wb_y;
  c2_Jg[14] = c2_cc_y;
  c2_Jg[20] = c2_ec_y;
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
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
  c2_ag_x = c2_ga;
  c2_bg_x = c2_ag_x;
  c2_bg_x = muDoubleScalarCos(c2_bg_x);
  c2_cg_x = c2_th;
  c2_dg_x = c2_cg_x;
  c2_dg_x = muDoubleScalarCos(c2_dg_x);
  c2_bb_a = c2_bg_x;
  c2_yb_b = c2_dg_x;
  c2_fc_y = c2_bb_a * c2_yb_b;
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
  c2_gc_y = c2_cb_a * c2_ac_b;
  c2_kg_x = c2_th;
  c2_lg_x = c2_kg_x;
  c2_lg_x = muDoubleScalarCos(c2_lg_x);
  c2_mg_x = c2_ga;
  c2_ng_x = c2_mg_x;
  c2_ng_x = muDoubleScalarSin(c2_ng_x);
  c2_Tphi[0] = c2_fc_y;
  c2_Tphi[3] = -c2_fg_x;
  c2_Tphi[6] = 0.0;
  c2_Tphi[1] = c2_gc_y;
  c2_Tphi[4] = c2_lg_x;
  c2_Tphi[7] = 0.0;
  c2_Tphi[2] = -c2_ng_x;
  c2_Tphi[5] = 0.0;
  c2_Tphi[8] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 76);
  for (c2_i17 = 0; c2_i17 < 9; c2_i17++) {
    c2_b_Tphi[c2_i17] = c2_Tphi[c2_i17];
  }

  c2_inv(chartInstance, c2_b_Tphi, c2_dv4);
  for (c2_i18 = 0; c2_i18 < 9; c2_i18++) {
    c2_iTphi[c2_i18] = c2_dv4[c2_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
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

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 85);
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

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
  for (c2_i46 = 0; c2_i46 < 24; c2_i46++) {
    c2_b_Ja[c2_i46] = c2_Ja[c2_i46];
  }

  c2_svd(chartInstance, c2_b_Ja, c2_db_a, c2_bc_b, c2_b_V);
  for (c2_i47 = 0; c2_i47 < 36; c2_i47++) {
    c2_U[c2_i47] = c2_db_a[c2_i47];
  }

  for (c2_i48 = 0; c2_i48 < 24; c2_i48++) {
    c2_S[c2_i48] = c2_bc_b[c2_i48];
  }

  for (c2_i49 = 0; c2_i49 < 16; c2_i49++) {
    c2_V[c2_i49] = c2_b_V[c2_i49];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
  c2_lambda = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
  if (CV_EML_IF(0, 1, 0, c2_S[21] < c2_lambda)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
    c2_i50 = 0;
    for (c2_i51 = 0; c2_i51 < 6; c2_i51++) {
      c2_i52 = 0;
      for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
        c2_eb_a[c2_i53 + c2_i50] = c2_Ja[c2_i52 + c2_i51];
        c2_i52 += 6;
      }

      c2_i50 += 4;
    }

    for (c2_i54 = 0; c2_i54 < 24; c2_i54++) {
      c2_bc_b[c2_i54] = c2_Ja[c2_i54];
    }

    c2_e_eml_scalar_eg(chartInstance);
    c2_e_eml_scalar_eg(chartInstance);
    for (c2_i55 = 0; c2_i55 < 4; c2_i55++) {
      c2_i56 = 0;
      c2_i57 = 0;
      for (c2_i58 = 0; c2_i58 < 4; c2_i58++) {
        c2_b_V[c2_i56 + c2_i55] = 0.0;
        c2_i59 = 0;
        for (c2_i60 = 0; c2_i60 < 6; c2_i60++) {
          c2_b_V[c2_i56 + c2_i55] += c2_eb_a[c2_i59 + c2_i55] * c2_bc_b[c2_i60 +
            c2_i57];
          c2_i59 += 4;
        }

        c2_i56 += 4;
        c2_i57 += 6;
      }
    }

    for (c2_i61 = 0; c2_i61 < 16; c2_i61++) {
      c2_c_V[c2_i61] = c2_b_V[c2_i61] + c2_hc_y[c2_i61];
    }

    c2_i62 = 0;
    for (c2_i63 = 0; c2_i63 < 6; c2_i63++) {
      c2_i64 = 0;
      for (c2_i65 = 0; c2_i65 < 4; c2_i65++) {
        c2_c_Ja[c2_i65 + c2_i62] = c2_Ja[c2_i64 + c2_i63];
        c2_i64 += 6;
      }

      c2_i62 += 4;
    }

    c2_mldivide(chartInstance, c2_c_V, c2_c_Ja, c2_dv6);
    for (c2_i66 = 0; c2_i66 < 24; c2_i66++) {
      c2_J_ainv[c2_i66] = c2_dv6[c2_i66];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 97);
    c2_i67 = 0;
    for (c2_i68 = 0; c2_i68 < 6; c2_i68++) {
      c2_i69 = 0;
      for (c2_i70 = 0; c2_i70 < 4; c2_i70++) {
        c2_eb_a[c2_i70 + c2_i67] = c2_Ja[c2_i69 + c2_i68];
        c2_i69 += 6;
      }

      c2_i67 += 4;
    }

    for (c2_i71 = 0; c2_i71 < 24; c2_i71++) {
      c2_bc_b[c2_i71] = c2_Ja[c2_i71];
    }

    c2_e_eml_scalar_eg(chartInstance);
    c2_e_eml_scalar_eg(chartInstance);
    for (c2_i72 = 0; c2_i72 < 4; c2_i72++) {
      c2_i73 = 0;
      c2_i74 = 0;
      for (c2_i75 = 0; c2_i75 < 4; c2_i75++) {
        c2_b_V[c2_i73 + c2_i72] = 0.0;
        c2_i76 = 0;
        for (c2_i77 = 0; c2_i77 < 6; c2_i77++) {
          c2_b_V[c2_i73 + c2_i72] += c2_eb_a[c2_i76 + c2_i72] * c2_bc_b[c2_i77 +
            c2_i74];
          c2_i76 += 4;
        }

        c2_i73 += 4;
        c2_i74 += 6;
      }
    }

    for (c2_i78 = 0; c2_i78 < 16; c2_i78++) {
      c2_d_V[c2_i78] = c2_b_V[c2_i78];
    }

    c2_i79 = 0;
    for (c2_i80 = 0; c2_i80 < 6; c2_i80++) {
      c2_i81 = 0;
      for (c2_i82 = 0; c2_i82 < 4; c2_i82++) {
        c2_d_Ja[c2_i82 + c2_i79] = c2_Ja[c2_i81 + c2_i80];
        c2_i81 += 6;
      }

      c2_i79 += 4;
    }

    c2_mldivide(chartInstance, c2_d_V, c2_d_Ja, c2_dv7);
    for (c2_i83 = 0; c2_i83 < 24; c2_i83++) {
      c2_J_ainv[c2_i83] = c2_dv7[c2_i83];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 105);
  for (c2_i84 = 0; c2_i84 < 3; c2_i84++) {
    c2_X[c2_i84] = c2_Pxyz[c2_i84];
  }

  for (c2_i85 = 0; c2_i85 < 3; c2_i85++) {
    c2_X[c2_i85 + 3] = c2_Theta[c2_i85];
  }

  sf_mex_printf("%s =\\n", "X");
  for (c2_i86 = 0; c2_i86 < 6; c2_i86++) {
    c2_u[c2_i86] = c2_X[c2_i86];
  }

  c2_ic_y = NULL;
  sf_mex_assign(&c2_ic_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_ic_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 106);
  for (c2_i87 = 0; c2_i87 < 24; c2_i87++) {
    c2_eb_a[c2_i87] = c2_J_ainv[c2_i87];
  }

  for (c2_i88 = 0; c2_i88 < 6; c2_i88++) {
    c2_cc_b[c2_i88] = c2_ex[c2_i88];
  }

  c2_g_eml_scalar_eg(chartInstance);
  c2_g_eml_scalar_eg(chartInstance);
  for (c2_i89 = 0; c2_i89 < 4; c2_i89++) {
    c2_qp[c2_i89] = 0.0;
  }

  for (c2_i90 = 0; c2_i90 < 4; c2_i90++) {
    c2_qp[c2_i90] = 0.0;
  }

  for (c2_i91 = 0; c2_i91 < 4; c2_i91++) {
    c2_b_C[c2_i91] = c2_qp[c2_i91];
  }

  for (c2_i92 = 0; c2_i92 < 4; c2_i92++) {
    c2_qp[c2_i92] = c2_b_C[c2_i92];
  }

  for (c2_i93 = 0; c2_i93 < 4; c2_i93++) {
    c2_b_C[c2_i93] = c2_qp[c2_i93];
  }

  for (c2_i94 = 0; c2_i94 < 4; c2_i94++) {
    c2_qp[c2_i94] = c2_b_C[c2_i94];
  }

  for (c2_i95 = 0; c2_i95 < 4; c2_i95++) {
    c2_qp[c2_i95] = 0.0;
    c2_i96 = 0;
    for (c2_i97 = 0; c2_i97 < 6; c2_i97++) {
      c2_qp[c2_i95] += c2_eb_a[c2_i96 + c2_i95] * c2_cc_b[c2_i97];
      c2_i96 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
  for (c2_i98 = 0; c2_i98 < 24; c2_i98++) {
    c2_bc_b[c2_i98] = c2_Ja[c2_i98];
  }

  for (c2_i99 = 0; c2_i99 < 4; c2_i99++) {
    c2_b_C[c2_i99] = c2_qp[c2_i99];
  }

  c2_h_eml_scalar_eg(chartInstance);
  c2_h_eml_scalar_eg(chartInstance);
  for (c2_i100 = 0; c2_i100 < 6; c2_i100++) {
    c2_Xp[c2_i100] = 0.0;
  }

  for (c2_i101 = 0; c2_i101 < 6; c2_i101++) {
    c2_Xp[c2_i101] = 0.0;
  }

  for (c2_i102 = 0; c2_i102 < 6; c2_i102++) {
    c2_cc_b[c2_i102] = c2_Xp[c2_i102];
  }

  for (c2_i103 = 0; c2_i103 < 6; c2_i103++) {
    c2_Xp[c2_i103] = c2_cc_b[c2_i103];
  }

  for (c2_i104 = 0; c2_i104 < 6; c2_i104++) {
    c2_cc_b[c2_i104] = c2_Xp[c2_i104];
  }

  for (c2_i105 = 0; c2_i105 < 6; c2_i105++) {
    c2_Xp[c2_i105] = c2_cc_b[c2_i105];
  }

  for (c2_i106 = 0; c2_i106 < 6; c2_i106++) {
    c2_Xp[c2_i106] = 0.0;
    c2_i107 = 0;
    for (c2_i108 = 0; c2_i108 < 4; c2_i108++) {
      c2_Xp[c2_i106] += c2_bc_b[c2_i107 + c2_i106] * c2_b_C[c2_i108];
      c2_i107 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -107);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i109 = 0; c2_i109 < 4; c2_i109++) {
    (*c2_b_qp)[c2_i109] = c2_qp[c2_i109];
  }

  for (c2_i110 = 0; c2_i110 < 6; c2_i110++) {
    (*c2_b_X)[c2_i110] = c2_X[c2_i110];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_CONTROL_POSICION
  (SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i111;
  real_T c2_b_inData[6];
  int32_T c2_i112;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i111 = 0; c2_i111 < 6; c2_i111++) {
    c2_b_inData[c2_i111] = (*(real_T (*)[6])c2_inData)[c2_i111];
  }

  for (c2_i112 = 0; c2_i112 < 6; c2_i112++) {
    c2_u[c2_i112] = c2_b_inData[c2_i112];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_X, const char_T *c2_identifier, real_T c2_y
  [6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_X), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_X);
}

static void c2_b_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6])
{
  real_T c2_dv8[6];
  int32_T c2_i113;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv8, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i113 = 0; c2_i113 < 6; c2_i113++) {
    c2_y[c2_i113] = c2_dv8[c2_i113];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_X;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i114;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_X = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_X), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_X);
  for (c2_i114 = 0; c2_i114 < 6; c2_i114++) {
    (*(real_T (*)[6])c2_outData)[c2_i114] = c2_y[c2_i114];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i115;
  real_T c2_b_inData[4];
  int32_T c2_i116;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i115 = 0; c2_i115 < 4; c2_i115++) {
    c2_b_inData[c2_i115] = (*(real_T (*)[4])c2_inData)[c2_i115];
  }

  for (c2_i116 = 0; c2_i116 < 4; c2_i116++) {
    c2_u[c2_i116] = c2_b_inData[c2_i116];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_qp, const char_T *c2_identifier, real_T
  c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_qp), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_qp);
}

static void c2_d_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4])
{
  real_T c2_dv9[4];
  int32_T c2_i117;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv9, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i117 = 0; c2_i117 < 4; c2_i117++) {
    c2_y[c2_i117] = c2_dv9[c2_i117];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_qp;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i118;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_qp = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_qp), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_qp);
  for (c2_i118 = 0; c2_i118 < 4; c2_i118++) {
    (*(real_T (*)[4])c2_outData)[c2_i118] = c2_y[c2_i118];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i119;
  int32_T c2_i120;
  int32_T c2_i121;
  real_T c2_b_inData[24];
  int32_T c2_i122;
  int32_T c2_i123;
  int32_T c2_i124;
  real_T c2_u[24];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i119 = 0;
  for (c2_i120 = 0; c2_i120 < 6; c2_i120++) {
    for (c2_i121 = 0; c2_i121 < 4; c2_i121++) {
      c2_b_inData[c2_i121 + c2_i119] = (*(real_T (*)[24])c2_inData)[c2_i121 +
        c2_i119];
    }

    c2_i119 += 4;
  }

  c2_i122 = 0;
  for (c2_i123 = 0; c2_i123 < 6; c2_i123++) {
    for (c2_i124 = 0; c2_i124 < 4; c2_i124++) {
      c2_u[c2_i124 + c2_i122] = c2_b_inData[c2_i124 + c2_i122];
    }

    c2_i122 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24])
{
  real_T c2_dv10[24];
  int32_T c2_i125;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv10, 1, 0, 0U, 1, 0U, 2, 4, 6);
  for (c2_i125 = 0; c2_i125 < 24; c2_i125++) {
    c2_y[c2_i125] = c2_dv10[c2_i125];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_J_ainv;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[24];
  int32_T c2_i126;
  int32_T c2_i127;
  int32_T c2_i128;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_J_ainv = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_J_ainv), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_J_ainv);
  c2_i126 = 0;
  for (c2_i127 = 0; c2_i127 < 6; c2_i127++) {
    for (c2_i128 = 0; c2_i128 < 4; c2_i128++) {
      (*(real_T (*)[24])c2_outData)[c2_i128 + c2_i126] = c2_y[c2_i128 + c2_i126];
    }

    c2_i126 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i129;
  int32_T c2_i130;
  int32_T c2_i131;
  real_T c2_b_inData[16];
  int32_T c2_i132;
  int32_T c2_i133;
  int32_T c2_i134;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i129 = 0;
  for (c2_i130 = 0; c2_i130 < 4; c2_i130++) {
    for (c2_i131 = 0; c2_i131 < 4; c2_i131++) {
      c2_b_inData[c2_i131 + c2_i129] = (*(real_T (*)[16])c2_inData)[c2_i131 +
        c2_i129];
    }

    c2_i129 += 4;
  }

  c2_i132 = 0;
  for (c2_i133 = 0; c2_i133 < 4; c2_i133++) {
    for (c2_i134 = 0; c2_i134 < 4; c2_i134++) {
      c2_u[c2_i134 + c2_i132] = c2_b_inData[c2_i134 + c2_i132];
    }

    c2_i132 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_dv11[16];
  int32_T c2_i135;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i135 = 0; c2_i135 < 16; c2_i135++) {
    c2_y[c2_i135] = c2_dv11[c2_i135];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_V;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i136;
  int32_T c2_i137;
  int32_T c2_i138;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_V = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_V), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_V);
  c2_i136 = 0;
  for (c2_i137 = 0; c2_i137 < 4; c2_i137++) {
    for (c2_i138 = 0; c2_i138 < 4; c2_i138++) {
      (*(real_T (*)[16])c2_outData)[c2_i138 + c2_i136] = c2_y[c2_i138 + c2_i136];
    }

    c2_i136 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i139;
  int32_T c2_i140;
  int32_T c2_i141;
  real_T c2_b_inData[24];
  int32_T c2_i142;
  int32_T c2_i143;
  int32_T c2_i144;
  real_T c2_u[24];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i139 = 0;
  for (c2_i140 = 0; c2_i140 < 4; c2_i140++) {
    for (c2_i141 = 0; c2_i141 < 6; c2_i141++) {
      c2_b_inData[c2_i141 + c2_i139] = (*(real_T (*)[24])c2_inData)[c2_i141 +
        c2_i139];
    }

    c2_i139 += 6;
  }

  c2_i142 = 0;
  for (c2_i143 = 0; c2_i143 < 4; c2_i143++) {
    for (c2_i144 = 0; c2_i144 < 6; c2_i144++) {
      c2_u[c2_i144 + c2_i142] = c2_b_inData[c2_i144 + c2_i142];
    }

    c2_i142 += 6;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 6, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[24])
{
  real_T c2_dv12[24];
  int32_T c2_i145;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv12, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c2_i145 = 0; c2_i145 < 24; c2_i145++) {
    c2_y[c2_i145] = c2_dv12[c2_i145];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_S;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[24];
  int32_T c2_i146;
  int32_T c2_i147;
  int32_T c2_i148;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_S = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_S), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_S);
  c2_i146 = 0;
  for (c2_i147 = 0; c2_i147 < 4; c2_i147++) {
    for (c2_i148 = 0; c2_i148 < 6; c2_i148++) {
      (*(real_T (*)[24])c2_outData)[c2_i148 + c2_i146] = c2_y[c2_i148 + c2_i146];
    }

    c2_i146 += 6;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i149;
  int32_T c2_i150;
  int32_T c2_i151;
  real_T c2_b_inData[36];
  int32_T c2_i152;
  int32_T c2_i153;
  int32_T c2_i154;
  real_T c2_u[36];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i149 = 0;
  for (c2_i150 = 0; c2_i150 < 6; c2_i150++) {
    for (c2_i151 = 0; c2_i151 < 6; c2_i151++) {
      c2_b_inData[c2_i151 + c2_i149] = (*(real_T (*)[36])c2_inData)[c2_i151 +
        c2_i149];
    }

    c2_i149 += 6;
  }

  c2_i152 = 0;
  for (c2_i153 = 0; c2_i153 < 6; c2_i153++) {
    for (c2_i154 = 0; c2_i154 < 6; c2_i154++) {
      c2_u[c2_i154 + c2_i152] = c2_b_inData[c2_i154 + c2_i152];
    }

    c2_i152 += 6;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_i_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[36])
{
  real_T c2_dv13[36];
  int32_T c2_i155;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv13, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c2_i155 = 0; c2_i155 < 36; c2_i155++) {
    c2_y[c2_i155] = c2_dv13[c2_i155];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_U;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[36];
  int32_T c2_i156;
  int32_T c2_i157;
  int32_T c2_i158;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_U = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_U), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_U);
  c2_i156 = 0;
  for (c2_i157 = 0; c2_i157 < 6; c2_i157++) {
    for (c2_i158 = 0; c2_i158 < 6; c2_i158++) {
      (*(real_T (*)[36])c2_outData)[c2_i158 + c2_i156] = c2_y[c2_i158 + c2_i156];
    }

    c2_i156 += 6;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i159;
  int32_T c2_i160;
  int32_T c2_i161;
  real_T c2_b_inData[9];
  int32_T c2_i162;
  int32_T c2_i163;
  int32_T c2_i164;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i159 = 0;
  for (c2_i160 = 0; c2_i160 < 3; c2_i160++) {
    for (c2_i161 = 0; c2_i161 < 3; c2_i161++) {
      c2_b_inData[c2_i161 + c2_i159] = (*(real_T (*)[9])c2_inData)[c2_i161 +
        c2_i159];
    }

    c2_i159 += 3;
  }

  c2_i162 = 0;
  for (c2_i163 = 0; c2_i163 < 3; c2_i163++) {
    for (c2_i164 = 0; c2_i164 < 3; c2_i164++) {
      c2_u[c2_i164 + c2_i162] = c2_b_inData[c2_i164 + c2_i162];
    }

    c2_i162 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_j_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9])
{
  real_T c2_dv14[9];
  int32_T c2_i165;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv14, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i165 = 0; c2_i165 < 9; c2_i165++) {
    c2_y[c2_i165] = c2_dv14[c2_i165];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_iTphi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i166;
  int32_T c2_i167;
  int32_T c2_i168;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_iTphi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_iTphi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_iTphi);
  c2_i166 = 0;
  for (c2_i167 = 0; c2_i167 < 3; c2_i167++) {
    for (c2_i168 = 0; c2_i168 < 3; c2_i168++) {
      (*(real_T (*)[9])c2_outData)[c2_i168 + c2_i166] = c2_y[c2_i168 + c2_i166];
    }

    c2_i166 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i169;
  real_T c2_b_inData[3];
  int32_T c2_i170;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i169 = 0; c2_i169 < 3; c2_i169++) {
    c2_b_inData[c2_i169] = (*(real_T (*)[3])c2_inData)[c2_i169];
  }

  for (c2_i170 = 0; c2_i170 < 3; c2_i170++) {
    c2_u[c2_i170] = c2_b_inData[c2_i170];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_k_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv15[3];
  int32_T c2_i171;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv15, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i171 = 0; c2_i171 < 3; c2_i171++) {
    c2_y[c2_i171] = c2_dv15[c2_i171];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Theta;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i172;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_Theta = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Theta), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Theta);
  for (c2_i172 = 0; c2_i172 < 3; c2_i172++) {
    (*(real_T (*)[3])c2_outData)[c2_i172] = c2_y[c2_i172];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_CONTROL_POSICION_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[269];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i173;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info_helper(c2_info);
  c2_c_info_helper(c2_info);
  c2_d_info_helper(c2_info);
  c2_e_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 269), FALSE);
  for (c2_i173 = 0; c2_i173 < 269; c2_i173++) {
    c2_r0 = &c2_info[c2_i173];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i173);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i173);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i173);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i173);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i173);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i173);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i173);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i173);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[269])
{
  c2_info[0].context = "";
  c2_info[0].name = "cos";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[0].fileTimeLo = 1343830372U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[1].name = "eml_scalar_cos";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[1].fileTimeLo = 1286818722U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "sin";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[2].fileTimeLo = 1343830386U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[3].name = "eml_scalar_sin";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[3].fileTimeLo = 1286818736U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "mtimes";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].fileTimeLo = 1289519692U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "atan2";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[5].fileTimeLo = 1343830372U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[6].name = "eml_scalar_eg";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[6].fileTimeLo = 1286818796U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[7].name = "eml_scalexp_alloc";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[7].fileTimeLo = 1352424860U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[8].name = "eml_scalar_atan2";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c2_info[8].fileTimeLo = 1286818720U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "mpower";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[9].fileTimeLo = 1286818842U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[10].name = "power";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[10].fileTimeLo = 1348191930U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[11].name = "eml_scalar_eg";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[11].fileTimeLo = 1286818796U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[12].name = "eml_scalexp_alloc";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[12].fileTimeLo = 1352424860U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[13].name = "floor";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[13].fileTimeLo = 1343830380U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[14].name = "eml_scalar_floor";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[14].fileTimeLo = 1286818726U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c2_info[15].name = "eml_scalar_eg";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[15].fileTimeLo = 1286818796U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c2_info[16].name = "mtimes";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[16].fileTimeLo = 1289519692U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "";
  c2_info[17].name = "sqrt";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[17].fileTimeLo = 1343830386U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[18].name = "eml_error";
  c2_info[18].dominantType = "char";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[18].fileTimeLo = 1343830358U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[19].name = "eml_scalar_sqrt";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[19].fileTimeLo = 1286818738U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context = "";
  c2_info[20].name = "inv";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c2_info[20].fileTimeLo = 1305318000U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[21].name = "eml_index_class";
  c2_info[21].dominantType = "";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[21].fileTimeLo = 1323170578U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[22].name = "abs";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[22].fileTimeLo = 1343830366U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[23].name = "eml_scalar_abs";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[23].fileTimeLo = 1286818712U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[24].name = "eml_div";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[24].fileTimeLo = 1313347810U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[25].name = "mtimes";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[25].fileTimeLo = 1289519692U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c2_info[26].name = "eml_index_plus";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[26].fileTimeLo = 1286818778U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[27].name = "eml_index_class";
  c2_info[27].dominantType = "";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[27].fileTimeLo = 1323170578U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[28].name = "norm";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[28].fileTimeLo = 1336522094U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c2_info[29].name = "abs";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[29].fileTimeLo = 1343830366U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c2_info[30].name = "isnan";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[30].fileTimeLo = 1286818760U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c2_info[31].name = "eml_guarded_nan";
  c2_info[31].dominantType = "char";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[31].fileTimeLo = 1286818776U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[32].name = "eml_is_float_class";
  c2_info[32].dominantType = "char";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[32].fileTimeLo = 1286818782U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[33].name = "mtimes";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[33].fileTimeLo = 1289519692U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[34].name = "eml_warning";
  c2_info[34].dominantType = "char";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[34].fileTimeLo = 1286818802U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[35].name = "isnan";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[35].fileTimeLo = 1286818760U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[36].name = "eps";
  c2_info[36].dominantType = "char";
  c2_info[36].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[36].fileTimeLo = 1326727996U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[37].name = "eml_is_float_class";
  c2_info[37].dominantType = "char";
  c2_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[37].fileTimeLo = 1286818782U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[38].name = "eml_eps";
  c2_info[38].dominantType = "char";
  c2_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[38].fileTimeLo = 1326727996U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[39].name = "eml_float_model";
  c2_info[39].dominantType = "char";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[39].fileTimeLo = 1326727996U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c2_info[40].name = "eml_flt2str";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c2_info[40].fileTimeLo = 1309451196U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c2_info[41].name = "char";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c2_info[41].fileTimeLo = 1319729968U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context = "";
  c2_info[42].name = "eye";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c2_info[42].fileTimeLo = 1286818688U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[43].name = "eml_assert_valid_size_arg";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[43].fileTimeLo = 1286818694U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c2_info[44].name = "isinf";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[44].fileTimeLo = 1286818760U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c2_info[45].name = "mtimes";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[45].fileTimeLo = 1289519692U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[46].name = "eml_index_class";
  c2_info[46].dominantType = "";
  c2_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[46].fileTimeLo = 1323170578U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[47].name = "intmax";
  c2_info[47].dominantType = "char";
  c2_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[47].fileTimeLo = 1311255316U;
  c2_info[47].fileTimeHi = 0U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[48].name = "eml_is_float_class";
  c2_info[48].dominantType = "char";
  c2_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[48].fileTimeLo = 1286818782U;
  c2_info[48].fileTimeHi = 0U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[49].name = "min";
  c2_info[49].dominantType = "double";
  c2_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[49].fileTimeLo = 1311255318U;
  c2_info[49].fileTimeHi = 0U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[50].name = "eml_min_or_max";
  c2_info[50].dominantType = "char";
  c2_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[50].fileTimeLo = 1334071490U;
  c2_info[50].fileTimeHi = 0U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[51].name = "eml_scalar_eg";
  c2_info[51].dominantType = "double";
  c2_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[51].fileTimeLo = 1286818796U;
  c2_info[51].fileTimeHi = 0U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[52].name = "eml_scalexp_alloc";
  c2_info[52].dominantType = "double";
  c2_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[52].fileTimeLo = 1352424860U;
  c2_info[52].fileTimeHi = 0U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[53].name = "eml_index_class";
  c2_info[53].dominantType = "";
  c2_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[53].fileTimeLo = 1323170578U;
  c2_info[53].fileTimeHi = 0U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[54].name = "eml_scalar_eg";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[54].fileTimeLo = 1286818796U;
  c2_info[54].fileTimeHi = 0U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[55].name = "eml_index_class";
  c2_info[55].dominantType = "";
  c2_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[55].fileTimeLo = 1323170578U;
  c2_info[55].fileTimeHi = 0U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c2_info[56].name = "eml_int_forloop_overflow_check";
  c2_info[56].dominantType = "";
  c2_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[56].fileTimeLo = 1346510340U;
  c2_info[56].fileTimeHi = 0U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
  c2_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[57].name = "intmax";
  c2_info[57].dominantType = "char";
  c2_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[57].fileTimeLo = 1311255316U;
  c2_info[57].fileTimeHi = 0U;
  c2_info[57].mFileTimeLo = 0U;
  c2_info[57].mFileTimeHi = 0U;
  c2_info[58].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[58].name = "eml_index_class";
  c2_info[58].dominantType = "";
  c2_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[58].fileTimeLo = 1323170578U;
  c2_info[58].fileTimeHi = 0U;
  c2_info[58].mFileTimeLo = 0U;
  c2_info[58].mFileTimeHi = 0U;
  c2_info[59].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[59].name = "eml_scalar_eg";
  c2_info[59].dominantType = "double";
  c2_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[59].fileTimeLo = 1286818796U;
  c2_info[59].fileTimeHi = 0U;
  c2_info[59].mFileTimeLo = 0U;
  c2_info[59].mFileTimeHi = 0U;
  c2_info[60].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[60].name = "eml_xgemm";
  c2_info[60].dominantType = "char";
  c2_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[60].fileTimeLo = 1299076772U;
  c2_info[60].fileTimeHi = 0U;
  c2_info[60].mFileTimeLo = 0U;
  c2_info[60].mFileTimeHi = 0U;
  c2_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[61].name = "eml_blas_inline";
  c2_info[61].dominantType = "";
  c2_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[61].fileTimeLo = 1299076768U;
  c2_info[61].fileTimeHi = 0U;
  c2_info[61].mFileTimeLo = 0U;
  c2_info[61].mFileTimeHi = 0U;
  c2_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[62].name = "mtimes";
  c2_info[62].dominantType = "double";
  c2_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[62].fileTimeLo = 1289519692U;
  c2_info[62].fileTimeHi = 0U;
  c2_info[62].mFileTimeLo = 0U;
  c2_info[62].mFileTimeHi = 0U;
  c2_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[63].name = "eml_index_class";
  c2_info[63].dominantType = "";
  c2_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[63].fileTimeLo = 1323170578U;
  c2_info[63].fileTimeHi = 0U;
  c2_info[63].mFileTimeLo = 0U;
  c2_info[63].mFileTimeHi = 0U;
}

static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[269])
{
  c2_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[64].name = "eml_scalar_eg";
  c2_info[64].dominantType = "double";
  c2_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[64].fileTimeLo = 1286818796U;
  c2_info[64].fileTimeHi = 0U;
  c2_info[64].mFileTimeLo = 0U;
  c2_info[64].mFileTimeHi = 0U;
  c2_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[65].name = "eml_refblas_xgemm";
  c2_info[65].dominantType = "char";
  c2_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[65].fileTimeLo = 1299076774U;
  c2_info[65].fileTimeHi = 0U;
  c2_info[65].mFileTimeLo = 0U;
  c2_info[65].mFileTimeHi = 0U;
  c2_info[66].context = "";
  c2_info[66].name = "svd";
  c2_info[66].dominantType = "double";
  c2_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c2_info[66].fileTimeLo = 1286818832U;
  c2_info[66].fileTimeHi = 0U;
  c2_info[66].mFileTimeLo = 0U;
  c2_info[66].mFileTimeHi = 0U;
  c2_info[67].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c2_info[67].name = "eml_index_class";
  c2_info[67].dominantType = "";
  c2_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[67].fileTimeLo = 1323170578U;
  c2_info[67].fileTimeHi = 0U;
  c2_info[67].mFileTimeLo = 0U;
  c2_info[67].mFileTimeHi = 0U;
  c2_info[68].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c2_info[68].name = "eml_int_forloop_overflow_check";
  c2_info[68].dominantType = "";
  c2_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[68].fileTimeLo = 1346510340U;
  c2_info[68].fileTimeHi = 0U;
  c2_info[68].mFileTimeLo = 0U;
  c2_info[68].mFileTimeHi = 0U;
  c2_info[69].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c2_info[69].name = "isfinite";
  c2_info[69].dominantType = "double";
  c2_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[69].fileTimeLo = 1286818758U;
  c2_info[69].fileTimeHi = 0U;
  c2_info[69].mFileTimeLo = 0U;
  c2_info[69].mFileTimeHi = 0U;
  c2_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[70].name = "isinf";
  c2_info[70].dominantType = "double";
  c2_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[70].fileTimeLo = 1286818760U;
  c2_info[70].fileTimeHi = 0U;
  c2_info[70].mFileTimeLo = 0U;
  c2_info[70].mFileTimeHi = 0U;
  c2_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[71].name = "isnan";
  c2_info[71].dominantType = "double";
  c2_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[71].fileTimeLo = 1286818760U;
  c2_info[71].fileTimeHi = 0U;
  c2_info[71].mFileTimeLo = 0U;
  c2_info[71].mFileTimeHi = 0U;
  c2_info[72].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c2_info[72].name = "eml_error";
  c2_info[72].dominantType = "char";
  c2_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[72].fileTimeLo = 1343830358U;
  c2_info[72].fileTimeHi = 0U;
  c2_info[72].mFileTimeLo = 0U;
  c2_info[72].mFileTimeHi = 0U;
  c2_info[73].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c2_info[73].name = "eml_xgesvd";
  c2_info[73].dominantType = "double";
  c2_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c2_info[73].fileTimeLo = 1286818806U;
  c2_info[73].fileTimeHi = 0U;
  c2_info[73].mFileTimeLo = 0U;
  c2_info[73].mFileTimeHi = 0U;
  c2_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c2_info[74].name = "eml_lapack_xgesvd";
  c2_info[74].dominantType = "double";
  c2_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c2_info[74].fileTimeLo = 1286818810U;
  c2_info[74].fileTimeHi = 0U;
  c2_info[74].mFileTimeLo = 0U;
  c2_info[74].mFileTimeHi = 0U;
  c2_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c2_info[75].name = "eml_matlab_zsvdc";
  c2_info[75].dominantType = "double";
  c2_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[75].fileTimeLo = 1295284866U;
  c2_info[75].fileTimeHi = 0U;
  c2_info[75].mFileTimeLo = 0U;
  c2_info[75].mFileTimeHi = 0U;
  c2_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[76].name = "eml_index_class";
  c2_info[76].dominantType = "";
  c2_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[76].fileTimeLo = 1323170578U;
  c2_info[76].fileTimeHi = 0U;
  c2_info[76].mFileTimeLo = 0U;
  c2_info[76].mFileTimeHi = 0U;
  c2_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[77].name = "eml_scalar_eg";
  c2_info[77].dominantType = "double";
  c2_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[77].fileTimeLo = 1286818796U;
  c2_info[77].fileTimeHi = 0U;
  c2_info[77].mFileTimeLo = 0U;
  c2_info[77].mFileTimeHi = 0U;
  c2_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[78].name = "eml_index_plus";
  c2_info[78].dominantType = "double";
  c2_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[78].fileTimeLo = 1286818778U;
  c2_info[78].fileTimeHi = 0U;
  c2_info[78].mFileTimeLo = 0U;
  c2_info[78].mFileTimeHi = 0U;
  c2_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[79].name = "min";
  c2_info[79].dominantType = "coder.internal.indexInt";
  c2_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[79].fileTimeLo = 1311255318U;
  c2_info[79].fileTimeHi = 0U;
  c2_info[79].mFileTimeLo = 0U;
  c2_info[79].mFileTimeHi = 0U;
  c2_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[80].name = "eml_scalar_eg";
  c2_info[80].dominantType = "coder.internal.indexInt";
  c2_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[80].fileTimeLo = 1286818796U;
  c2_info[80].fileTimeHi = 0U;
  c2_info[80].mFileTimeLo = 0U;
  c2_info[80].mFileTimeHi = 0U;
  c2_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[81].name = "eml_scalexp_alloc";
  c2_info[81].dominantType = "coder.internal.indexInt";
  c2_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[81].fileTimeLo = 1352424860U;
  c2_info[81].fileTimeHi = 0U;
  c2_info[81].mFileTimeLo = 0U;
  c2_info[81].mFileTimeHi = 0U;
  c2_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[82].name = "eml_scalar_eg";
  c2_info[82].dominantType = "coder.internal.indexInt";
  c2_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[82].fileTimeLo = 1286818796U;
  c2_info[82].fileTimeHi = 0U;
  c2_info[82].mFileTimeLo = 0U;
  c2_info[82].mFileTimeHi = 0U;
  c2_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[83].name = "max";
  c2_info[83].dominantType = "double";
  c2_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[83].fileTimeLo = 1311255316U;
  c2_info[83].fileTimeHi = 0U;
  c2_info[83].mFileTimeLo = 0U;
  c2_info[83].mFileTimeHi = 0U;
  c2_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[84].name = "eml_min_or_max";
  c2_info[84].dominantType = "char";
  c2_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[84].fileTimeLo = 1334071490U;
  c2_info[84].fileTimeHi = 0U;
  c2_info[84].mFileTimeLo = 0U;
  c2_info[84].mFileTimeHi = 0U;
  c2_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[85].name = "eml_relop";
  c2_info[85].dominantType = "function_handle";
  c2_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c2_info[85].fileTimeLo = 1342451182U;
  c2_info[85].fileTimeHi = 0U;
  c2_info[85].mFileTimeLo = 0U;
  c2_info[85].mFileTimeHi = 0U;
  c2_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c2_info[86].name = "coder.internal.indexIntRelop";
  c2_info[86].dominantType = "";
  c2_info[86].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c2_info[86].fileTimeLo = 1326728322U;
  c2_info[86].fileTimeHi = 0U;
  c2_info[86].mFileTimeLo = 0U;
  c2_info[86].mFileTimeHi = 0U;
  c2_info[87].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c2_info[87].name = "eml_float_model";
  c2_info[87].dominantType = "char";
  c2_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[87].fileTimeLo = 1326727996U;
  c2_info[87].fileTimeHi = 0U;
  c2_info[87].mFileTimeLo = 0U;
  c2_info[87].mFileTimeHi = 0U;
  c2_info[88].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c2_info[88].name = "intmin";
  c2_info[88].dominantType = "char";
  c2_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[88].fileTimeLo = 1311255318U;
  c2_info[88].fileTimeHi = 0U;
  c2_info[88].mFileTimeLo = 0U;
  c2_info[88].mFileTimeHi = 0U;
  c2_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[89].name = "isnan";
  c2_info[89].dominantType = "coder.internal.indexInt";
  c2_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[89].fileTimeLo = 1286818760U;
  c2_info[89].fileTimeHi = 0U;
  c2_info[89].mFileTimeLo = 0U;
  c2_info[89].mFileTimeHi = 0U;
  c2_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[90].name = "eml_index_minus";
  c2_info[90].dominantType = "double";
  c2_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[90].fileTimeLo = 1286818778U;
  c2_info[90].fileTimeHi = 0U;
  c2_info[90].mFileTimeLo = 0U;
  c2_info[90].mFileTimeHi = 0U;
  c2_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[91].name = "eml_index_class";
  c2_info[91].dominantType = "";
  c2_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[91].fileTimeLo = 1323170578U;
  c2_info[91].fileTimeHi = 0U;
  c2_info[91].mFileTimeLo = 0U;
  c2_info[91].mFileTimeHi = 0U;
  c2_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[92].name = "max";
  c2_info[92].dominantType = "coder.internal.indexInt";
  c2_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[92].fileTimeLo = 1311255316U;
  c2_info[92].fileTimeHi = 0U;
  c2_info[92].mFileTimeLo = 0U;
  c2_info[92].mFileTimeHi = 0U;
  c2_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[93].name = "eml_int_forloop_overflow_check";
  c2_info[93].dominantType = "";
  c2_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[93].fileTimeLo = 1346510340U;
  c2_info[93].fileTimeHi = 0U;
  c2_info[93].mFileTimeLo = 0U;
  c2_info[93].mFileTimeHi = 0U;
  c2_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[94].name = "eml_index_times";
  c2_info[94].dominantType = "coder.internal.indexInt";
  c2_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[94].fileTimeLo = 1286818780U;
  c2_info[94].fileTimeHi = 0U;
  c2_info[94].mFileTimeLo = 0U;
  c2_info[94].mFileTimeHi = 0U;
  c2_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[95].name = "eml_index_class";
  c2_info[95].dominantType = "";
  c2_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[95].fileTimeLo = 1323170578U;
  c2_info[95].fileTimeHi = 0U;
  c2_info[95].mFileTimeLo = 0U;
  c2_info[95].mFileTimeHi = 0U;
  c2_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[96].name = "eml_index_plus";
  c2_info[96].dominantType = "coder.internal.indexInt";
  c2_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[96].fileTimeLo = 1286818778U;
  c2_info[96].fileTimeHi = 0U;
  c2_info[96].mFileTimeLo = 0U;
  c2_info[96].mFileTimeHi = 0U;
  c2_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[97].name = "eml_index_minus";
  c2_info[97].dominantType = "coder.internal.indexInt";
  c2_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[97].fileTimeLo = 1286818778U;
  c2_info[97].fileTimeHi = 0U;
  c2_info[97].mFileTimeLo = 0U;
  c2_info[97].mFileTimeHi = 0U;
  c2_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[98].name = "eml_xnrm2";
  c2_info[98].dominantType = "double";
  c2_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c2_info[98].fileTimeLo = 1299076776U;
  c2_info[98].fileTimeHi = 0U;
  c2_info[98].mFileTimeLo = 0U;
  c2_info[98].mFileTimeHi = 0U;
  c2_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c2_info[99].name = "eml_blas_inline";
  c2_info[99].dominantType = "";
  c2_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[99].fileTimeLo = 1299076768U;
  c2_info[99].fileTimeHi = 0U;
  c2_info[99].mFileTimeLo = 0U;
  c2_info[99].mFileTimeHi = 0U;
  c2_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c2_info[100].name = "length";
  c2_info[100].dominantType = "double";
  c2_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[100].fileTimeLo = 1303146206U;
  c2_info[100].fileTimeHi = 0U;
  c2_info[100].mFileTimeLo = 0U;
  c2_info[100].mFileTimeHi = 0U;
  c2_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c2_info[101].name = "eml_index_class";
  c2_info[101].dominantType = "";
  c2_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[101].fileTimeLo = 1323170578U;
  c2_info[101].fileTimeHi = 0U;
  c2_info[101].mFileTimeLo = 0U;
  c2_info[101].mFileTimeHi = 0U;
  c2_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[102].name = "eml_index_class";
  c2_info[102].dominantType = "";
  c2_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[102].fileTimeLo = 1323170578U;
  c2_info[102].fileTimeHi = 0U;
  c2_info[102].mFileTimeLo = 0U;
  c2_info[102].mFileTimeHi = 0U;
  c2_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[103].name = "eml_refblas_xnrm2";
  c2_info[103].dominantType = "double";
  c2_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[103].fileTimeLo = 1299076784U;
  c2_info[103].fileTimeHi = 0U;
  c2_info[103].mFileTimeLo = 0U;
  c2_info[103].mFileTimeHi = 0U;
  c2_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[104].name = "abs";
  c2_info[104].dominantType = "double";
  c2_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[104].fileTimeLo = 1343830366U;
  c2_info[104].fileTimeHi = 0U;
  c2_info[104].mFileTimeLo = 0U;
  c2_info[104].mFileTimeHi = 0U;
  c2_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[105].name = "realmin";
  c2_info[105].dominantType = "char";
  c2_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[105].fileTimeLo = 1307651242U;
  c2_info[105].fileTimeHi = 0U;
  c2_info[105].mFileTimeLo = 0U;
  c2_info[105].mFileTimeHi = 0U;
  c2_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[106].name = "eml_realmin";
  c2_info[106].dominantType = "char";
  c2_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c2_info[106].fileTimeLo = 1307651244U;
  c2_info[106].fileTimeHi = 0U;
  c2_info[106].mFileTimeLo = 0U;
  c2_info[106].mFileTimeHi = 0U;
  c2_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c2_info[107].name = "eml_float_model";
  c2_info[107].dominantType = "char";
  c2_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[107].fileTimeLo = 1326727996U;
  c2_info[107].fileTimeHi = 0U;
  c2_info[107].mFileTimeLo = 0U;
  c2_info[107].mFileTimeHi = 0U;
  c2_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[108].name = "eml_index_class";
  c2_info[108].dominantType = "";
  c2_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[108].fileTimeLo = 1323170578U;
  c2_info[108].fileTimeHi = 0U;
  c2_info[108].mFileTimeLo = 0U;
  c2_info[108].mFileTimeHi = 0U;
  c2_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[109].name = "eml_index_minus";
  c2_info[109].dominantType = "double";
  c2_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[109].fileTimeLo = 1286818778U;
  c2_info[109].fileTimeHi = 0U;
  c2_info[109].mFileTimeLo = 0U;
  c2_info[109].mFileTimeHi = 0U;
  c2_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[110].name = "eml_index_times";
  c2_info[110].dominantType = "coder.internal.indexInt";
  c2_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[110].fileTimeLo = 1286818780U;
  c2_info[110].fileTimeHi = 0U;
  c2_info[110].mFileTimeLo = 0U;
  c2_info[110].mFileTimeHi = 0U;
  c2_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[111].name = "eml_index_plus";
  c2_info[111].dominantType = "coder.internal.indexInt";
  c2_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[111].fileTimeLo = 1286818778U;
  c2_info[111].fileTimeHi = 0U;
  c2_info[111].mFileTimeLo = 0U;
  c2_info[111].mFileTimeHi = 0U;
  c2_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[112].name = "eml_int_forloop_overflow_check";
  c2_info[112].dominantType = "";
  c2_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[112].fileTimeLo = 1346510340U;
  c2_info[112].fileTimeHi = 0U;
  c2_info[112].mFileTimeLo = 0U;
  c2_info[112].mFileTimeHi = 0U;
  c2_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[113].name = "eml_div";
  c2_info[113].dominantType = "double";
  c2_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[113].fileTimeLo = 1313347810U;
  c2_info[113].fileTimeHi = 0U;
  c2_info[113].mFileTimeLo = 0U;
  c2_info[113].mFileTimeHi = 0U;
  c2_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[114].name = "eml_xscal";
  c2_info[114].dominantType = "double";
  c2_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c2_info[114].fileTimeLo = 1299076776U;
  c2_info[114].fileTimeHi = 0U;
  c2_info[114].mFileTimeLo = 0U;
  c2_info[114].mFileTimeHi = 0U;
  c2_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c2_info[115].name = "eml_blas_inline";
  c2_info[115].dominantType = "";
  c2_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[115].fileTimeLo = 1299076768U;
  c2_info[115].fileTimeHi = 0U;
  c2_info[115].mFileTimeLo = 0U;
  c2_info[115].mFileTimeHi = 0U;
  c2_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold";
  c2_info[116].name = "length";
  c2_info[116].dominantType = "double";
  c2_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[116].fileTimeLo = 1303146206U;
  c2_info[116].fileTimeHi = 0U;
  c2_info[116].mFileTimeLo = 0U;
  c2_info[116].mFileTimeHi = 0U;
  c2_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c2_info[117].name = "eml_index_class";
  c2_info[117].dominantType = "";
  c2_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[117].fileTimeLo = 1323170578U;
  c2_info[117].fileTimeHi = 0U;
  c2_info[117].mFileTimeLo = 0U;
  c2_info[117].mFileTimeHi = 0U;
  c2_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c2_info[118].name = "eml_scalar_eg";
  c2_info[118].dominantType = "double";
  c2_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[118].fileTimeLo = 1286818796U;
  c2_info[118].fileTimeHi = 0U;
  c2_info[118].mFileTimeLo = 0U;
  c2_info[118].mFileTimeHi = 0U;
  c2_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c2_info[119].name = "eml_refblas_xscal";
  c2_info[119].dominantType = "double";
  c2_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[119].fileTimeLo = 1299076784U;
  c2_info[119].fileTimeHi = 0U;
  c2_info[119].mFileTimeLo = 0U;
  c2_info[119].mFileTimeHi = 0U;
  c2_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[120].name = "eml_index_class";
  c2_info[120].dominantType = "";
  c2_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[120].fileTimeLo = 1323170578U;
  c2_info[120].fileTimeHi = 0U;
  c2_info[120].mFileTimeLo = 0U;
  c2_info[120].mFileTimeHi = 0U;
  c2_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[121].name = "eml_index_minus";
  c2_info[121].dominantType = "double";
  c2_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[121].fileTimeLo = 1286818778U;
  c2_info[121].fileTimeHi = 0U;
  c2_info[121].mFileTimeLo = 0U;
  c2_info[121].mFileTimeHi = 0U;
  c2_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[122].name = "eml_index_times";
  c2_info[122].dominantType = "coder.internal.indexInt";
  c2_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[122].fileTimeLo = 1286818780U;
  c2_info[122].fileTimeHi = 0U;
  c2_info[122].mFileTimeLo = 0U;
  c2_info[122].mFileTimeHi = 0U;
  c2_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[123].name = "eml_index_plus";
  c2_info[123].dominantType = "coder.internal.indexInt";
  c2_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[123].fileTimeLo = 1286818778U;
  c2_info[123].fileTimeHi = 0U;
  c2_info[123].mFileTimeLo = 0U;
  c2_info[123].mFileTimeHi = 0U;
  c2_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c2_info[124].name = "eml_int_forloop_overflow_check";
  c2_info[124].dominantType = "";
  c2_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[124].fileTimeLo = 1346510340U;
  c2_info[124].fileTimeHi = 0U;
  c2_info[124].mFileTimeLo = 0U;
  c2_info[124].mFileTimeHi = 0U;
  c2_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[125].name = "eml_xdotc";
  c2_info[125].dominantType = "double";
  c2_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c2_info[125].fileTimeLo = 1299076772U;
  c2_info[125].fileTimeHi = 0U;
  c2_info[125].mFileTimeLo = 0U;
  c2_info[125].mFileTimeHi = 0U;
  c2_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c2_info[126].name = "eml_blas_inline";
  c2_info[126].dominantType = "";
  c2_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[126].fileTimeLo = 1299076768U;
  c2_info[126].fileTimeHi = 0U;
  c2_info[126].mFileTimeLo = 0U;
  c2_info[126].mFileTimeHi = 0U;
  c2_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c2_info[127].name = "eml_xdot";
  c2_info[127].dominantType = "double";
  c2_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[127].fileTimeLo = 1299076772U;
  c2_info[127].fileTimeHi = 0U;
  c2_info[127].mFileTimeLo = 0U;
  c2_info[127].mFileTimeHi = 0U;
}

static void c2_c_info_helper(c2_ResolvedFunctionInfo c2_info[269])
{
  c2_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[128].name = "eml_blas_inline";
  c2_info[128].dominantType = "";
  c2_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[128].fileTimeLo = 1299076768U;
  c2_info[128].fileTimeHi = 0U;
  c2_info[128].mFileTimeLo = 0U;
  c2_info[128].mFileTimeHi = 0U;
  c2_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c2_info[129].name = "length";
  c2_info[129].dominantType = "double";
  c2_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[129].fileTimeLo = 1303146206U;
  c2_info[129].fileTimeHi = 0U;
  c2_info[129].mFileTimeLo = 0U;
  c2_info[129].mFileTimeHi = 0U;
  c2_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c2_info[130].name = "eml_index_class";
  c2_info[130].dominantType = "";
  c2_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[130].fileTimeLo = 1323170578U;
  c2_info[130].fileTimeHi = 0U;
  c2_info[130].mFileTimeLo = 0U;
  c2_info[130].mFileTimeHi = 0U;
  c2_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c2_info[131].name = "eml_refblas_xdot";
  c2_info[131].dominantType = "double";
  c2_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[131].fileTimeLo = 1299076772U;
  c2_info[131].fileTimeHi = 0U;
  c2_info[131].mFileTimeLo = 0U;
  c2_info[131].mFileTimeHi = 0U;
  c2_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[132].name = "eml_refblas_xdotx";
  c2_info[132].dominantType = "char";
  c2_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[132].fileTimeLo = 1299076774U;
  c2_info[132].fileTimeHi = 0U;
  c2_info[132].mFileTimeLo = 0U;
  c2_info[132].mFileTimeHi = 0U;
  c2_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[133].name = "eml_scalar_eg";
  c2_info[133].dominantType = "double";
  c2_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[133].fileTimeLo = 1286818796U;
  c2_info[133].fileTimeHi = 0U;
  c2_info[133].mFileTimeLo = 0U;
  c2_info[133].mFileTimeHi = 0U;
  c2_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[134].name = "eml_index_class";
  c2_info[134].dominantType = "";
  c2_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[134].fileTimeLo = 1323170578U;
  c2_info[134].fileTimeHi = 0U;
  c2_info[134].mFileTimeLo = 0U;
  c2_info[134].mFileTimeHi = 0U;
  c2_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[135].name = "eml_int_forloop_overflow_check";
  c2_info[135].dominantType = "";
  c2_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[135].fileTimeLo = 1346510340U;
  c2_info[135].fileTimeHi = 0U;
  c2_info[135].mFileTimeLo = 0U;
  c2_info[135].mFileTimeHi = 0U;
  c2_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[136].name = "eml_index_plus";
  c2_info[136].dominantType = "coder.internal.indexInt";
  c2_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[136].fileTimeLo = 1286818778U;
  c2_info[136].fileTimeHi = 0U;
  c2_info[136].mFileTimeLo = 0U;
  c2_info[136].mFileTimeHi = 0U;
  c2_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[137].name = "eml_xaxpy";
  c2_info[137].dominantType = "double";
  c2_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c2_info[137].fileTimeLo = 1299076770U;
  c2_info[137].fileTimeHi = 0U;
  c2_info[137].mFileTimeLo = 0U;
  c2_info[137].mFileTimeHi = 0U;
  c2_info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c2_info[138].name = "eml_blas_inline";
  c2_info[138].dominantType = "";
  c2_info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[138].fileTimeLo = 1299076768U;
  c2_info[138].fileTimeHi = 0U;
  c2_info[138].mFileTimeLo = 0U;
  c2_info[138].mFileTimeHi = 0U;
  c2_info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m!below_threshold";
  c2_info[139].name = "length";
  c2_info[139].dominantType = "double";
  c2_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[139].fileTimeLo = 1303146206U;
  c2_info[139].fileTimeHi = 0U;
  c2_info[139].mFileTimeLo = 0U;
  c2_info[139].mFileTimeHi = 0U;
  c2_info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c2_info[140].name = "eml_index_class";
  c2_info[140].dominantType = "";
  c2_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[140].fileTimeLo = 1323170578U;
  c2_info[140].fileTimeHi = 0U;
  c2_info[140].mFileTimeLo = 0U;
  c2_info[140].mFileTimeHi = 0U;
  c2_info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c2_info[141].name = "eml_scalar_eg";
  c2_info[141].dominantType = "double";
  c2_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[141].fileTimeLo = 1286818796U;
  c2_info[141].fileTimeHi = 0U;
  c2_info[141].mFileTimeLo = 0U;
  c2_info[141].mFileTimeHi = 0U;
  c2_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c2_info[142].name = "eml_refblas_xaxpy";
  c2_info[142].dominantType = "double";
  c2_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c2_info[142].fileTimeLo = 1299076772U;
  c2_info[142].fileTimeHi = 0U;
  c2_info[142].mFileTimeLo = 0U;
  c2_info[142].mFileTimeHi = 0U;
  c2_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c2_info[143].name = "eml_index_class";
  c2_info[143].dominantType = "";
  c2_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[143].fileTimeLo = 1323170578U;
  c2_info[143].fileTimeHi = 0U;
  c2_info[143].mFileTimeLo = 0U;
  c2_info[143].mFileTimeHi = 0U;
  c2_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c2_info[144].name = "eml_isa_uint";
  c2_info[144].dominantType = "coder.internal.indexInt";
  c2_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[144].fileTimeLo = 1286818784U;
  c2_info[144].fileTimeHi = 0U;
  c2_info[144].mFileTimeLo = 0U;
  c2_info[144].mFileTimeHi = 0U;
  c2_info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c2_info[145].name = "eml_index_minus";
  c2_info[145].dominantType = "double";
  c2_info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[145].fileTimeLo = 1286818778U;
  c2_info[145].fileTimeHi = 0U;
  c2_info[145].mFileTimeLo = 0U;
  c2_info[145].mFileTimeHi = 0U;
  c2_info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c2_info[146].name = "eml_int_forloop_overflow_check";
  c2_info[146].dominantType = "";
  c2_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[146].fileTimeLo = 1346510340U;
  c2_info[146].fileTimeHi = 0U;
  c2_info[146].mFileTimeLo = 0U;
  c2_info[146].mFileTimeHi = 0U;
  c2_info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c2_info[147].name = "eml_index_plus";
  c2_info[147].dominantType = "double";
  c2_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[147].fileTimeLo = 1286818778U;
  c2_info[147].fileTimeHi = 0U;
  c2_info[147].mFileTimeLo = 0U;
  c2_info[147].mFileTimeHi = 0U;
  c2_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c2_info[148].name = "eml_index_plus";
  c2_info[148].dominantType = "coder.internal.indexInt";
  c2_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[148].fileTimeLo = 1286818778U;
  c2_info[148].fileTimeHi = 0U;
  c2_info[148].mFileTimeLo = 0U;
  c2_info[148].mFileTimeHi = 0U;
  c2_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[149].name = "intmin";
  c2_info[149].dominantType = "char";
  c2_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[149].fileTimeLo = 1311255318U;
  c2_info[149].fileTimeHi = 0U;
  c2_info[149].mFileTimeLo = 0U;
  c2_info[149].mFileTimeHi = 0U;
  c2_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[150].name = "abs";
  c2_info[150].dominantType = "double";
  c2_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[150].fileTimeLo = 1343830366U;
  c2_info[150].fileTimeHi = 0U;
  c2_info[150].mFileTimeLo = 0U;
  c2_info[150].mFileTimeHi = 0U;
  c2_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[151].name = "mtimes";
  c2_info[151].dominantType = "double";
  c2_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[151].fileTimeLo = 1289519692U;
  c2_info[151].fileTimeHi = 0U;
  c2_info[151].mFileTimeLo = 0U;
  c2_info[151].mFileTimeHi = 0U;
  c2_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[152].name = "realmin";
  c2_info[152].dominantType = "char";
  c2_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[152].fileTimeLo = 1307651242U;
  c2_info[152].fileTimeHi = 0U;
  c2_info[152].mFileTimeLo = 0U;
  c2_info[152].mFileTimeHi = 0U;
  c2_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[153].name = "eps";
  c2_info[153].dominantType = "char";
  c2_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[153].fileTimeLo = 1326727996U;
  c2_info[153].fileTimeHi = 0U;
  c2_info[153].mFileTimeLo = 0U;
  c2_info[153].mFileTimeHi = 0U;
  c2_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[154].name = "eml_error";
  c2_info[154].dominantType = "char";
  c2_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[154].fileTimeLo = 1343830358U;
  c2_info[154].fileTimeHi = 0U;
  c2_info[154].mFileTimeLo = 0U;
  c2_info[154].mFileTimeHi = 0U;
  c2_info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c2_info[155].name = "eml_const_nonsingleton_dim";
  c2_info[155].dominantType = "double";
  c2_info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[155].fileTimeLo = 1286818696U;
  c2_info[155].fileTimeHi = 0U;
  c2_info[155].mFileTimeLo = 0U;
  c2_info[155].mFileTimeHi = 0U;
  c2_info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c2_info[156].name = "eml_scalar_eg";
  c2_info[156].dominantType = "double";
  c2_info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[156].fileTimeLo = 1286818796U;
  c2_info[156].fileTimeHi = 0U;
  c2_info[156].mFileTimeLo = 0U;
  c2_info[156].mFileTimeHi = 0U;
  c2_info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c2_info[157].name = "eml_index_class";
  c2_info[157].dominantType = "";
  c2_info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[157].fileTimeLo = 1323170578U;
  c2_info[157].fileTimeHi = 0U;
  c2_info[157].mFileTimeLo = 0U;
  c2_info[157].mFileTimeHi = 0U;
  c2_info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[158].name = "eml_index_class";
  c2_info[158].dominantType = "";
  c2_info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[158].fileTimeLo = 1323170578U;
  c2_info[158].fileTimeHi = 0U;
  c2_info[158].mFileTimeLo = 0U;
  c2_info[158].mFileTimeHi = 0U;
  c2_info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[159].name = "isnan";
  c2_info[159].dominantType = "double";
  c2_info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[159].fileTimeLo = 1286818760U;
  c2_info[159].fileTimeHi = 0U;
  c2_info[159].mFileTimeLo = 0U;
  c2_info[159].mFileTimeHi = 0U;
  c2_info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[160].name = "eml_index_plus";
  c2_info[160].dominantType = "coder.internal.indexInt";
  c2_info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[160].fileTimeLo = 1286818778U;
  c2_info[160].fileTimeHi = 0U;
  c2_info[160].mFileTimeLo = 0U;
  c2_info[160].mFileTimeHi = 0U;
  c2_info[161].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[161].name = "eml_int_forloop_overflow_check";
  c2_info[161].dominantType = "";
  c2_info[161].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[161].fileTimeLo = 1346510340U;
  c2_info[161].fileTimeHi = 0U;
  c2_info[161].mFileTimeLo = 0U;
  c2_info[161].mFileTimeHi = 0U;
  c2_info[162].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[162].name = "eml_relop";
  c2_info[162].dominantType = "function_handle";
  c2_info[162].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c2_info[162].fileTimeLo = 1342451182U;
  c2_info[162].fileTimeHi = 0U;
  c2_info[162].mFileTimeLo = 0U;
  c2_info[162].mFileTimeHi = 0U;
  c2_info[163].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[163].name = "sqrt";
  c2_info[163].dominantType = "double";
  c2_info[163].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[163].fileTimeLo = 1343830386U;
  c2_info[163].fileTimeHi = 0U;
  c2_info[163].mFileTimeLo = 0U;
  c2_info[163].mFileTimeHi = 0U;
  c2_info[164].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[164].name = "eml_xrotg";
  c2_info[164].dominantType = "double";
  c2_info[164].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c2_info[164].fileTimeLo = 1299076776U;
  c2_info[164].fileTimeHi = 0U;
  c2_info[164].mFileTimeLo = 0U;
  c2_info[164].mFileTimeHi = 0U;
  c2_info[165].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c2_info[165].name = "eml_blas_inline";
  c2_info[165].dominantType = "";
  c2_info[165].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[165].fileTimeLo = 1299076768U;
  c2_info[165].fileTimeHi = 0U;
  c2_info[165].mFileTimeLo = 0U;
  c2_info[165].mFileTimeHi = 0U;
  c2_info[166].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c2_info[166].name = "eml_refblas_xrotg";
  c2_info[166].dominantType = "double";
  c2_info[166].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c2_info[166].fileTimeLo = 1299076784U;
  c2_info[166].fileTimeHi = 0U;
  c2_info[166].mFileTimeLo = 0U;
  c2_info[166].mFileTimeHi = 0U;
  c2_info[167].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c2_info[167].name = "abs";
  c2_info[167].dominantType = "double";
  c2_info[167].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[167].fileTimeLo = 1343830366U;
  c2_info[167].fileTimeHi = 0U;
  c2_info[167].mFileTimeLo = 0U;
  c2_info[167].mFileTimeHi = 0U;
  c2_info[168].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c2_info[168].name = "mrdivide";
  c2_info[168].dominantType = "double";
  c2_info[168].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[168].fileTimeLo = 1357951548U;
  c2_info[168].fileTimeHi = 0U;
  c2_info[168].mFileTimeLo = 1319729966U;
  c2_info[168].mFileTimeHi = 0U;
  c2_info[169].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[169].name = "rdivide";
  c2_info[169].dominantType = "double";
  c2_info[169].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[169].fileTimeLo = 1346510388U;
  c2_info[169].fileTimeHi = 0U;
  c2_info[169].mFileTimeLo = 0U;
  c2_info[169].mFileTimeHi = 0U;
  c2_info[170].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[170].name = "eml_scalexp_compatible";
  c2_info[170].dominantType = "double";
  c2_info[170].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[170].fileTimeLo = 1286818796U;
  c2_info[170].fileTimeHi = 0U;
  c2_info[170].mFileTimeLo = 0U;
  c2_info[170].mFileTimeHi = 0U;
  c2_info[171].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[171].name = "eml_div";
  c2_info[171].dominantType = "double";
  c2_info[171].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[171].fileTimeLo = 1313347810U;
  c2_info[171].fileTimeHi = 0U;
  c2_info[171].mFileTimeLo = 0U;
  c2_info[171].mFileTimeHi = 0U;
  c2_info[172].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c2_info[172].name = "sqrt";
  c2_info[172].dominantType = "double";
  c2_info[172].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[172].fileTimeLo = 1343830386U;
  c2_info[172].fileTimeHi = 0U;
  c2_info[172].mFileTimeLo = 0U;
  c2_info[172].mFileTimeHi = 0U;
  c2_info[173].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m!eml_ceval_xrotg";
  c2_info[173].name = "eml_scalar_eg";
  c2_info[173].dominantType = "double";
  c2_info[173].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[173].fileTimeLo = 1286818796U;
  c2_info[173].fileTimeHi = 0U;
  c2_info[173].mFileTimeLo = 0U;
  c2_info[173].mFileTimeHi = 0U;
  c2_info[174].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[174].name = "eml_xrot";
  c2_info[174].dominantType = "double";
  c2_info[174].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c2_info[174].fileTimeLo = 1299076776U;
  c2_info[174].fileTimeHi = 0U;
  c2_info[174].mFileTimeLo = 0U;
  c2_info[174].mFileTimeHi = 0U;
  c2_info[175].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c2_info[175].name = "eml_blas_inline";
  c2_info[175].dominantType = "";
  c2_info[175].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[175].fileTimeLo = 1299076768U;
  c2_info[175].fileTimeHi = 0U;
  c2_info[175].mFileTimeLo = 0U;
  c2_info[175].mFileTimeHi = 0U;
  c2_info[176].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c2_info[176].name = "eml_index_class";
  c2_info[176].dominantType = "";
  c2_info[176].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[176].fileTimeLo = 1323170578U;
  c2_info[176].fileTimeHi = 0U;
  c2_info[176].mFileTimeLo = 0U;
  c2_info[176].mFileTimeHi = 0U;
  c2_info[177].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c2_info[177].name = "eml_scalar_eg";
  c2_info[177].dominantType = "double";
  c2_info[177].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[177].fileTimeLo = 1286818796U;
  c2_info[177].fileTimeHi = 0U;
  c2_info[177].mFileTimeLo = 0U;
  c2_info[177].mFileTimeHi = 0U;
  c2_info[178].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c2_info[178].name = "eml_refblas_xrot";
  c2_info[178].dominantType = "double";
  c2_info[178].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c2_info[178].fileTimeLo = 1299076784U;
  c2_info[178].fileTimeHi = 0U;
  c2_info[178].mFileTimeLo = 0U;
  c2_info[178].mFileTimeHi = 0U;
  c2_info[179].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c2_info[179].name = "eml_index_class";
  c2_info[179].dominantType = "";
  c2_info[179].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[179].fileTimeLo = 1323170578U;
  c2_info[179].fileTimeHi = 0U;
  c2_info[179].mFileTimeLo = 0U;
  c2_info[179].mFileTimeHi = 0U;
  c2_info[180].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c2_info[180].name = "eml_int_forloop_overflow_check";
  c2_info[180].dominantType = "";
  c2_info[180].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[180].fileTimeLo = 1346510340U;
  c2_info[180].fileTimeHi = 0U;
  c2_info[180].mFileTimeLo = 0U;
  c2_info[180].mFileTimeHi = 0U;
  c2_info[181].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c2_info[181].name = "mtimes";
  c2_info[181].dominantType = "double";
  c2_info[181].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[181].fileTimeLo = 1289519692U;
  c2_info[181].fileTimeHi = 0U;
  c2_info[181].mFileTimeLo = 0U;
  c2_info[181].mFileTimeHi = 0U;
  c2_info[182].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c2_info[182].name = "eml_index_plus";
  c2_info[182].dominantType = "coder.internal.indexInt";
  c2_info[182].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[182].fileTimeLo = 1286818778U;
  c2_info[182].fileTimeHi = 0U;
  c2_info[182].mFileTimeLo = 0U;
  c2_info[182].mFileTimeHi = 0U;
  c2_info[183].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c2_info[183].name = "eml_xswap";
  c2_info[183].dominantType = "double";
  c2_info[183].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[183].fileTimeLo = 1299076778U;
  c2_info[183].fileTimeHi = 0U;
  c2_info[183].mFileTimeLo = 0U;
  c2_info[183].mFileTimeHi = 0U;
  c2_info[184].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[184].name = "eml_blas_inline";
  c2_info[184].dominantType = "";
  c2_info[184].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[184].fileTimeLo = 1299076768U;
  c2_info[184].fileTimeHi = 0U;
  c2_info[184].mFileTimeLo = 0U;
  c2_info[184].mFileTimeHi = 0U;
  c2_info[185].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c2_info[185].name = "eml_index_class";
  c2_info[185].dominantType = "";
  c2_info[185].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[185].fileTimeLo = 1323170578U;
  c2_info[185].fileTimeHi = 0U;
  c2_info[185].mFileTimeLo = 0U;
  c2_info[185].mFileTimeHi = 0U;
  c2_info[186].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c2_info[186].name = "eml_refblas_xswap";
  c2_info[186].dominantType = "double";
  c2_info[186].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[186].fileTimeLo = 1299076786U;
  c2_info[186].fileTimeHi = 0U;
  c2_info[186].mFileTimeLo = 0U;
  c2_info[186].mFileTimeHi = 0U;
  c2_info[187].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[187].name = "eml_index_class";
  c2_info[187].dominantType = "";
  c2_info[187].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[187].fileTimeLo = 1323170578U;
  c2_info[187].fileTimeHi = 0U;
  c2_info[187].mFileTimeLo = 0U;
  c2_info[187].mFileTimeHi = 0U;
  c2_info[188].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[188].name = "abs";
  c2_info[188].dominantType = "coder.internal.indexInt";
  c2_info[188].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[188].fileTimeLo = 1343830366U;
  c2_info[188].fileTimeHi = 0U;
  c2_info[188].mFileTimeLo = 0U;
  c2_info[188].mFileTimeHi = 0U;
  c2_info[189].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[189].name = "eml_scalar_abs";
  c2_info[189].dominantType = "coder.internal.indexInt";
  c2_info[189].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[189].fileTimeLo = 1286818712U;
  c2_info[189].fileTimeHi = 0U;
  c2_info[189].mFileTimeLo = 0U;
  c2_info[189].mFileTimeHi = 0U;
  c2_info[190].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[190].name = "eml_int_forloop_overflow_check";
  c2_info[190].dominantType = "";
  c2_info[190].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[190].fileTimeLo = 1346510340U;
  c2_info[190].fileTimeHi = 0U;
  c2_info[190].mFileTimeLo = 0U;
  c2_info[190].mFileTimeHi = 0U;
  c2_info[191].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[191].name = "eml_index_plus";
  c2_info[191].dominantType = "coder.internal.indexInt";
  c2_info[191].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[191].fileTimeLo = 1286818778U;
  c2_info[191].fileTimeHi = 0U;
  c2_info[191].mFileTimeLo = 0U;
  c2_info[191].mFileTimeHi = 0U;
}

static void c2_d_info_helper(c2_ResolvedFunctionInfo c2_info[269])
{
  c2_info[192].context = "";
  c2_info[192].name = "mldivide";
  c2_info[192].dominantType = "double";
  c2_info[192].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[192].fileTimeLo = 1357951548U;
  c2_info[192].fileTimeHi = 0U;
  c2_info[192].mFileTimeLo = 1319729966U;
  c2_info[192].mFileTimeHi = 0U;
  c2_info[193].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[193].name = "eml_lusolve";
  c2_info[193].dominantType = "double";
  c2_info[193].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[193].fileTimeLo = 1309451196U;
  c2_info[193].fileTimeHi = 0U;
  c2_info[193].mFileTimeLo = 0U;
  c2_info[193].mFileTimeHi = 0U;
  c2_info[194].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[194].name = "eml_index_class";
  c2_info[194].dominantType = "";
  c2_info[194].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[194].fileTimeLo = 1323170578U;
  c2_info[194].fileTimeHi = 0U;
  c2_info[194].mFileTimeLo = 0U;
  c2_info[194].mFileTimeHi = 0U;
  c2_info[195].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[195].name = "eml_index_class";
  c2_info[195].dominantType = "";
  c2_info[195].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[195].fileTimeLo = 1323170578U;
  c2_info[195].fileTimeHi = 0U;
  c2_info[195].mFileTimeLo = 0U;
  c2_info[195].mFileTimeHi = 0U;
  c2_info[196].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[196].name = "eml_xgetrf";
  c2_info[196].dominantType = "double";
  c2_info[196].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c2_info[196].fileTimeLo = 1286818806U;
  c2_info[196].fileTimeHi = 0U;
  c2_info[196].mFileTimeLo = 0U;
  c2_info[196].mFileTimeHi = 0U;
  c2_info[197].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c2_info[197].name = "eml_lapack_xgetrf";
  c2_info[197].dominantType = "double";
  c2_info[197].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c2_info[197].fileTimeLo = 1286818810U;
  c2_info[197].fileTimeHi = 0U;
  c2_info[197].mFileTimeLo = 0U;
  c2_info[197].mFileTimeHi = 0U;
  c2_info[198].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c2_info[198].name = "eml_matlab_zgetrf";
  c2_info[198].dominantType = "double";
  c2_info[198].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[198].fileTimeLo = 1302688994U;
  c2_info[198].fileTimeHi = 0U;
  c2_info[198].mFileTimeLo = 0U;
  c2_info[198].mFileTimeHi = 0U;
  c2_info[199].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[199].name = "realmin";
  c2_info[199].dominantType = "char";
  c2_info[199].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[199].fileTimeLo = 1307651242U;
  c2_info[199].fileTimeHi = 0U;
  c2_info[199].mFileTimeLo = 0U;
  c2_info[199].mFileTimeHi = 0U;
  c2_info[200].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[200].name = "eps";
  c2_info[200].dominantType = "char";
  c2_info[200].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[200].fileTimeLo = 1326727996U;
  c2_info[200].fileTimeHi = 0U;
  c2_info[200].mFileTimeLo = 0U;
  c2_info[200].mFileTimeHi = 0U;
  c2_info[201].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[201].name = "min";
  c2_info[201].dominantType = "coder.internal.indexInt";
  c2_info[201].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[201].fileTimeLo = 1311255318U;
  c2_info[201].fileTimeHi = 0U;
  c2_info[201].mFileTimeLo = 0U;
  c2_info[201].mFileTimeHi = 0U;
  c2_info[202].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[202].name = "colon";
  c2_info[202].dominantType = "double";
  c2_info[202].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[202].fileTimeLo = 1348191928U;
  c2_info[202].fileTimeHi = 0U;
  c2_info[202].mFileTimeLo = 0U;
  c2_info[202].mFileTimeHi = 0U;
  c2_info[203].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[203].name = "colon";
  c2_info[203].dominantType = "double";
  c2_info[203].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[203].fileTimeLo = 1348191928U;
  c2_info[203].fileTimeHi = 0U;
  c2_info[203].mFileTimeLo = 0U;
  c2_info[203].mFileTimeHi = 0U;
  c2_info[204].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[204].name = "floor";
  c2_info[204].dominantType = "double";
  c2_info[204].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[204].fileTimeLo = 1343830380U;
  c2_info[204].fileTimeHi = 0U;
  c2_info[204].mFileTimeLo = 0U;
  c2_info[204].mFileTimeHi = 0U;
  c2_info[205].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[205].name = "intmin";
  c2_info[205].dominantType = "char";
  c2_info[205].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[205].fileTimeLo = 1311255318U;
  c2_info[205].fileTimeHi = 0U;
  c2_info[205].mFileTimeLo = 0U;
  c2_info[205].mFileTimeHi = 0U;
  c2_info[206].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[206].name = "intmax";
  c2_info[206].dominantType = "char";
  c2_info[206].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[206].fileTimeLo = 1311255316U;
  c2_info[206].fileTimeHi = 0U;
  c2_info[206].mFileTimeLo = 0U;
  c2_info[206].mFileTimeHi = 0U;
  c2_info[207].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[207].name = "intmin";
  c2_info[207].dominantType = "char";
  c2_info[207].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[207].fileTimeLo = 1311255318U;
  c2_info[207].fileTimeHi = 0U;
  c2_info[207].mFileTimeLo = 0U;
  c2_info[207].mFileTimeHi = 0U;
  c2_info[208].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[208].name = "intmax";
  c2_info[208].dominantType = "char";
  c2_info[208].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[208].fileTimeLo = 1311255316U;
  c2_info[208].fileTimeHi = 0U;
  c2_info[208].mFileTimeLo = 0U;
  c2_info[208].mFileTimeHi = 0U;
  c2_info[209].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[209].name = "eml_isa_uint";
  c2_info[209].dominantType = "coder.internal.indexInt";
  c2_info[209].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[209].fileTimeLo = 1286818784U;
  c2_info[209].fileTimeHi = 0U;
  c2_info[209].mFileTimeLo = 0U;
  c2_info[209].mFileTimeHi = 0U;
  c2_info[210].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[210].name = "eml_unsigned_class";
  c2_info[210].dominantType = "char";
  c2_info[210].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[210].fileTimeLo = 1323170580U;
  c2_info[210].fileTimeHi = 0U;
  c2_info[210].mFileTimeLo = 0U;
  c2_info[210].mFileTimeHi = 0U;
  c2_info[211].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[211].name = "eml_index_class";
  c2_info[211].dominantType = "";
  c2_info[211].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[211].fileTimeLo = 1323170578U;
  c2_info[211].fileTimeHi = 0U;
  c2_info[211].mFileTimeLo = 0U;
  c2_info[211].mFileTimeHi = 0U;
  c2_info[212].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[212].name = "eml_index_class";
  c2_info[212].dominantType = "";
  c2_info[212].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[212].fileTimeLo = 1323170578U;
  c2_info[212].fileTimeHi = 0U;
  c2_info[212].mFileTimeLo = 0U;
  c2_info[212].mFileTimeHi = 0U;
  c2_info[213].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[213].name = "intmax";
  c2_info[213].dominantType = "char";
  c2_info[213].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[213].fileTimeLo = 1311255316U;
  c2_info[213].fileTimeHi = 0U;
  c2_info[213].mFileTimeLo = 0U;
  c2_info[213].mFileTimeHi = 0U;
  c2_info[214].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[214].name = "eml_isa_uint";
  c2_info[214].dominantType = "coder.internal.indexInt";
  c2_info[214].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[214].fileTimeLo = 1286818784U;
  c2_info[214].fileTimeHi = 0U;
  c2_info[214].mFileTimeLo = 0U;
  c2_info[214].mFileTimeHi = 0U;
  c2_info[215].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[215].name = "eml_index_plus";
  c2_info[215].dominantType = "double";
  c2_info[215].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[215].fileTimeLo = 1286818778U;
  c2_info[215].fileTimeHi = 0U;
  c2_info[215].mFileTimeLo = 0U;
  c2_info[215].mFileTimeHi = 0U;
  c2_info[216].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c2_info[216].name = "eml_int_forloop_overflow_check";
  c2_info[216].dominantType = "";
  c2_info[216].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[216].fileTimeLo = 1346510340U;
  c2_info[216].fileTimeHi = 0U;
  c2_info[216].mFileTimeLo = 0U;
  c2_info[216].mFileTimeHi = 0U;
  c2_info[217].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[217].name = "eml_index_class";
  c2_info[217].dominantType = "";
  c2_info[217].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[217].fileTimeLo = 1323170578U;
  c2_info[217].fileTimeHi = 0U;
  c2_info[217].mFileTimeLo = 0U;
  c2_info[217].mFileTimeHi = 0U;
  c2_info[218].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[218].name = "eml_index_plus";
  c2_info[218].dominantType = "double";
  c2_info[218].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[218].fileTimeLo = 1286818778U;
  c2_info[218].fileTimeHi = 0U;
  c2_info[218].mFileTimeLo = 0U;
  c2_info[218].mFileTimeHi = 0U;
  c2_info[219].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[219].name = "eml_int_forloop_overflow_check";
  c2_info[219].dominantType = "";
  c2_info[219].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[219].fileTimeLo = 1346510340U;
  c2_info[219].fileTimeHi = 0U;
  c2_info[219].mFileTimeLo = 0U;
  c2_info[219].mFileTimeHi = 0U;
  c2_info[220].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[220].name = "eml_index_minus";
  c2_info[220].dominantType = "double";
  c2_info[220].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[220].fileTimeLo = 1286818778U;
  c2_info[220].fileTimeHi = 0U;
  c2_info[220].mFileTimeLo = 0U;
  c2_info[220].mFileTimeHi = 0U;
  c2_info[221].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[221].name = "eml_index_minus";
  c2_info[221].dominantType = "coder.internal.indexInt";
  c2_info[221].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[221].fileTimeLo = 1286818778U;
  c2_info[221].fileTimeHi = 0U;
  c2_info[221].mFileTimeLo = 0U;
  c2_info[221].mFileTimeHi = 0U;
  c2_info[222].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[222].name = "eml_index_times";
  c2_info[222].dominantType = "coder.internal.indexInt";
  c2_info[222].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[222].fileTimeLo = 1286818780U;
  c2_info[222].fileTimeHi = 0U;
  c2_info[222].mFileTimeLo = 0U;
  c2_info[222].mFileTimeHi = 0U;
  c2_info[223].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[223].name = "eml_index_plus";
  c2_info[223].dominantType = "coder.internal.indexInt";
  c2_info[223].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[223].fileTimeLo = 1286818778U;
  c2_info[223].fileTimeHi = 0U;
  c2_info[223].mFileTimeLo = 0U;
  c2_info[223].mFileTimeHi = 0U;
  c2_info[224].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[224].name = "eml_ixamax";
  c2_info[224].dominantType = "double";
  c2_info[224].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[224].fileTimeLo = 1299076770U;
  c2_info[224].fileTimeHi = 0U;
  c2_info[224].mFileTimeLo = 0U;
  c2_info[224].mFileTimeHi = 0U;
  c2_info[225].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[225].name = "eml_blas_inline";
  c2_info[225].dominantType = "";
  c2_info[225].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[225].fileTimeLo = 1299076768U;
  c2_info[225].fileTimeHi = 0U;
  c2_info[225].mFileTimeLo = 0U;
  c2_info[225].mFileTimeHi = 0U;
  c2_info[226].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c2_info[226].name = "length";
  c2_info[226].dominantType = "double";
  c2_info[226].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[226].fileTimeLo = 1303146206U;
  c2_info[226].fileTimeHi = 0U;
  c2_info[226].mFileTimeLo = 0U;
  c2_info[226].mFileTimeHi = 0U;
  c2_info[227].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c2_info[227].name = "eml_index_class";
  c2_info[227].dominantType = "";
  c2_info[227].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[227].fileTimeLo = 1323170578U;
  c2_info[227].fileTimeHi = 0U;
  c2_info[227].mFileTimeLo = 0U;
  c2_info[227].mFileTimeHi = 0U;
  c2_info[228].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c2_info[228].name = "eml_refblas_ixamax";
  c2_info[228].dominantType = "double";
  c2_info[228].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[228].fileTimeLo = 1299076770U;
  c2_info[228].fileTimeHi = 0U;
  c2_info[228].mFileTimeLo = 0U;
  c2_info[228].mFileTimeHi = 0U;
  c2_info[229].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[229].name = "eml_index_class";
  c2_info[229].dominantType = "";
  c2_info[229].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[229].fileTimeLo = 1323170578U;
  c2_info[229].fileTimeHi = 0U;
  c2_info[229].mFileTimeLo = 0U;
  c2_info[229].mFileTimeHi = 0U;
  c2_info[230].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[230].name = "eml_xcabs1";
  c2_info[230].dominantType = "double";
  c2_info[230].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[230].fileTimeLo = 1286818706U;
  c2_info[230].fileTimeHi = 0U;
  c2_info[230].mFileTimeLo = 0U;
  c2_info[230].mFileTimeHi = 0U;
  c2_info[231].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[231].name = "abs";
  c2_info[231].dominantType = "double";
  c2_info[231].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[231].fileTimeLo = 1343830366U;
  c2_info[231].fileTimeHi = 0U;
  c2_info[231].mFileTimeLo = 0U;
  c2_info[231].mFileTimeHi = 0U;
  c2_info[232].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[232].name = "eml_int_forloop_overflow_check";
  c2_info[232].dominantType = "";
  c2_info[232].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[232].fileTimeLo = 1346510340U;
  c2_info[232].fileTimeHi = 0U;
  c2_info[232].mFileTimeLo = 0U;
  c2_info[232].mFileTimeHi = 0U;
  c2_info[233].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[233].name = "eml_index_plus";
  c2_info[233].dominantType = "coder.internal.indexInt";
  c2_info[233].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[233].fileTimeLo = 1286818778U;
  c2_info[233].fileTimeHi = 0U;
  c2_info[233].mFileTimeLo = 0U;
  c2_info[233].mFileTimeHi = 0U;
  c2_info[234].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[234].name = "eml_xswap";
  c2_info[234].dominantType = "double";
  c2_info[234].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[234].fileTimeLo = 1299076778U;
  c2_info[234].fileTimeHi = 0U;
  c2_info[234].mFileTimeLo = 0U;
  c2_info[234].mFileTimeHi = 0U;
  c2_info[235].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[235].name = "eml_div";
  c2_info[235].dominantType = "double";
  c2_info[235].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[235].fileTimeLo = 1313347810U;
  c2_info[235].fileTimeHi = 0U;
  c2_info[235].mFileTimeLo = 0U;
  c2_info[235].mFileTimeHi = 0U;
  c2_info[236].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[236].name = "eml_xgeru";
  c2_info[236].dominantType = "double";
  c2_info[236].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[236].fileTimeLo = 1299076774U;
  c2_info[236].fileTimeHi = 0U;
  c2_info[236].mFileTimeLo = 0U;
  c2_info[236].mFileTimeHi = 0U;
  c2_info[237].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[237].name = "eml_blas_inline";
  c2_info[237].dominantType = "";
  c2_info[237].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[237].fileTimeLo = 1299076768U;
  c2_info[237].fileTimeHi = 0U;
  c2_info[237].mFileTimeLo = 0U;
  c2_info[237].mFileTimeHi = 0U;
  c2_info[238].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[238].name = "eml_xger";
  c2_info[238].dominantType = "double";
  c2_info[238].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[238].fileTimeLo = 1299076774U;
  c2_info[238].fileTimeHi = 0U;
  c2_info[238].mFileTimeLo = 0U;
  c2_info[238].mFileTimeHi = 0U;
  c2_info[239].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[239].name = "eml_blas_inline";
  c2_info[239].dominantType = "";
  c2_info[239].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[239].fileTimeLo = 1299076768U;
  c2_info[239].fileTimeHi = 0U;
  c2_info[239].mFileTimeLo = 0U;
  c2_info[239].mFileTimeHi = 0U;
  c2_info[240].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c2_info[240].name = "intmax";
  c2_info[240].dominantType = "char";
  c2_info[240].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[240].fileTimeLo = 1311255316U;
  c2_info[240].fileTimeHi = 0U;
  c2_info[240].mFileTimeLo = 0U;
  c2_info[240].mFileTimeHi = 0U;
  c2_info[241].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c2_info[241].name = "min";
  c2_info[241].dominantType = "double";
  c2_info[241].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[241].fileTimeLo = 1311255318U;
  c2_info[241].fileTimeHi = 0U;
  c2_info[241].mFileTimeLo = 0U;
  c2_info[241].mFileTimeHi = 0U;
  c2_info[242].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c2_info[242].name = "mtimes";
  c2_info[242].dominantType = "double";
  c2_info[242].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[242].fileTimeLo = 1289519692U;
  c2_info[242].fileTimeHi = 0U;
  c2_info[242].mFileTimeLo = 0U;
  c2_info[242].mFileTimeHi = 0U;
  c2_info[243].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c2_info[243].name = "eml_index_class";
  c2_info[243].dominantType = "";
  c2_info[243].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[243].fileTimeLo = 1323170578U;
  c2_info[243].fileTimeHi = 0U;
  c2_info[243].mFileTimeLo = 0U;
  c2_info[243].mFileTimeHi = 0U;
  c2_info[244].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c2_info[244].name = "eml_refblas_xger";
  c2_info[244].dominantType = "double";
  c2_info[244].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[244].fileTimeLo = 1299076776U;
  c2_info[244].fileTimeHi = 0U;
  c2_info[244].mFileTimeLo = 0U;
  c2_info[244].mFileTimeHi = 0U;
  c2_info[245].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[245].name = "eml_refblas_xgerx";
  c2_info[245].dominantType = "char";
  c2_info[245].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[245].fileTimeLo = 1299076778U;
  c2_info[245].fileTimeHi = 0U;
  c2_info[245].mFileTimeLo = 0U;
  c2_info[245].mFileTimeHi = 0U;
  c2_info[246].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[246].name = "eml_index_class";
  c2_info[246].dominantType = "";
  c2_info[246].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[246].fileTimeLo = 1323170578U;
  c2_info[246].fileTimeHi = 0U;
  c2_info[246].mFileTimeLo = 0U;
  c2_info[246].mFileTimeHi = 0U;
  c2_info[247].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[247].name = "abs";
  c2_info[247].dominantType = "coder.internal.indexInt";
  c2_info[247].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[247].fileTimeLo = 1343830366U;
  c2_info[247].fileTimeHi = 0U;
  c2_info[247].mFileTimeLo = 0U;
  c2_info[247].mFileTimeHi = 0U;
  c2_info[248].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[248].name = "eml_index_minus";
  c2_info[248].dominantType = "double";
  c2_info[248].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[248].fileTimeLo = 1286818778U;
  c2_info[248].fileTimeHi = 0U;
  c2_info[248].mFileTimeLo = 0U;
  c2_info[248].mFileTimeHi = 0U;
  c2_info[249].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[249].name = "eml_int_forloop_overflow_check";
  c2_info[249].dominantType = "";
  c2_info[249].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[249].fileTimeLo = 1346510340U;
  c2_info[249].fileTimeHi = 0U;
  c2_info[249].mFileTimeLo = 0U;
  c2_info[249].mFileTimeHi = 0U;
  c2_info[250].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[250].name = "eml_index_plus";
  c2_info[250].dominantType = "double";
  c2_info[250].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[250].fileTimeLo = 1286818778U;
  c2_info[250].fileTimeHi = 0U;
  c2_info[250].mFileTimeLo = 0U;
  c2_info[250].mFileTimeHi = 0U;
  c2_info[251].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[251].name = "eml_index_plus";
  c2_info[251].dominantType = "coder.internal.indexInt";
  c2_info[251].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[251].fileTimeLo = 1286818778U;
  c2_info[251].fileTimeHi = 0U;
  c2_info[251].mFileTimeLo = 0U;
  c2_info[251].mFileTimeHi = 0U;
  c2_info[252].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c2_info[252].name = "eml_warning";
  c2_info[252].dominantType = "char";
  c2_info[252].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[252].fileTimeLo = 1286818802U;
  c2_info[252].fileTimeHi = 0U;
  c2_info[252].mFileTimeLo = 0U;
  c2_info[252].mFileTimeHi = 0U;
  c2_info[253].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[253].name = "eml_scalar_eg";
  c2_info[253].dominantType = "double";
  c2_info[253].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[253].fileTimeLo = 1286818796U;
  c2_info[253].fileTimeHi = 0U;
  c2_info[253].mFileTimeLo = 0U;
  c2_info[253].mFileTimeHi = 0U;
  c2_info[254].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[254].name = "eml_int_forloop_overflow_check";
  c2_info[254].dominantType = "";
  c2_info[254].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[254].fileTimeLo = 1346510340U;
  c2_info[254].fileTimeHi = 0U;
  c2_info[254].mFileTimeLo = 0U;
  c2_info[254].mFileTimeHi = 0U;
  c2_info[255].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[255].name = "eml_xtrsm";
  c2_info[255].dominantType = "char";
  c2_info[255].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c2_info[255].fileTimeLo = 1299076778U;
  c2_info[255].fileTimeHi = 0U;
  c2_info[255].mFileTimeLo = 0U;
  c2_info[255].mFileTimeHi = 0U;
}

static void c2_e_info_helper(c2_ResolvedFunctionInfo c2_info[269])
{
  c2_info[256].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c2_info[256].name = "eml_blas_inline";
  c2_info[256].dominantType = "";
  c2_info[256].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[256].fileTimeLo = 1299076768U;
  c2_info[256].fileTimeHi = 0U;
  c2_info[256].mFileTimeLo = 0U;
  c2_info[256].mFileTimeHi = 0U;
  c2_info[257].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c2_info[257].name = "mtimes";
  c2_info[257].dominantType = "double";
  c2_info[257].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[257].fileTimeLo = 1289519692U;
  c2_info[257].fileTimeHi = 0U;
  c2_info[257].mFileTimeLo = 0U;
  c2_info[257].mFileTimeHi = 0U;
  c2_info[258].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c2_info[258].name = "eml_index_class";
  c2_info[258].dominantType = "";
  c2_info[258].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[258].fileTimeLo = 1323170578U;
  c2_info[258].fileTimeHi = 0U;
  c2_info[258].mFileTimeLo = 0U;
  c2_info[258].mFileTimeHi = 0U;
  c2_info[259].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c2_info[259].name = "eml_scalar_eg";
  c2_info[259].dominantType = "double";
  c2_info[259].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[259].fileTimeLo = 1286818796U;
  c2_info[259].fileTimeHi = 0U;
  c2_info[259].mFileTimeLo = 0U;
  c2_info[259].mFileTimeHi = 0U;
  c2_info[260].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c2_info[260].name = "eml_refblas_xtrsm";
  c2_info[260].dominantType = "char";
  c2_info[260].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[260].fileTimeLo = 1299076786U;
  c2_info[260].fileTimeHi = 0U;
  c2_info[260].mFileTimeLo = 0U;
  c2_info[260].mFileTimeHi = 0U;
  c2_info[261].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[261].name = "eml_scalar_eg";
  c2_info[261].dominantType = "double";
  c2_info[261].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[261].fileTimeLo = 1286818796U;
  c2_info[261].fileTimeHi = 0U;
  c2_info[261].mFileTimeLo = 0U;
  c2_info[261].mFileTimeHi = 0U;
  c2_info[262].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[262].name = "eml_index_minus";
  c2_info[262].dominantType = "double";
  c2_info[262].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[262].fileTimeLo = 1286818778U;
  c2_info[262].fileTimeHi = 0U;
  c2_info[262].mFileTimeLo = 0U;
  c2_info[262].mFileTimeHi = 0U;
  c2_info[263].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[263].name = "eml_index_class";
  c2_info[263].dominantType = "";
  c2_info[263].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[263].fileTimeLo = 1323170578U;
  c2_info[263].fileTimeHi = 0U;
  c2_info[263].mFileTimeLo = 0U;
  c2_info[263].mFileTimeHi = 0U;
  c2_info[264].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[264].name = "eml_int_forloop_overflow_check";
  c2_info[264].dominantType = "";
  c2_info[264].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[264].fileTimeLo = 1346510340U;
  c2_info[264].fileTimeHi = 0U;
  c2_info[264].mFileTimeLo = 0U;
  c2_info[264].mFileTimeHi = 0U;
  c2_info[265].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[265].name = "eml_index_times";
  c2_info[265].dominantType = "coder.internal.indexInt";
  c2_info[265].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[265].fileTimeLo = 1286818780U;
  c2_info[265].fileTimeHi = 0U;
  c2_info[265].mFileTimeLo = 0U;
  c2_info[265].mFileTimeHi = 0U;
  c2_info[266].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[266].name = "eml_index_plus";
  c2_info[266].dominantType = "coder.internal.indexInt";
  c2_info[266].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[266].fileTimeLo = 1286818778U;
  c2_info[266].fileTimeHi = 0U;
  c2_info[266].mFileTimeLo = 0U;
  c2_info[266].mFileTimeHi = 0U;
  c2_info[267].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[267].name = "eml_index_plus";
  c2_info[267].dominantType = "double";
  c2_info[267].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[267].fileTimeLo = 1286818778U;
  c2_info[267].fileTimeHi = 0U;
  c2_info[267].mFileTimeLo = 0U;
  c2_info[267].mFileTimeHi = 0U;
  c2_info[268].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[268].name = "eml_div";
  c2_info[268].dominantType = "double";
  c2_info[268].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[268].fileTimeLo = 1313347810U;
  c2_info[268].fileTimeHi = 0U;
  c2_info[268].mFileTimeLo = 0U;
  c2_info[268].mFileTimeHi = 0U;
}

static real_T c2_atan2(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_y, real_T c2_x)
{
  real_T c2_b_y;
  real_T c2_b_x;
  c2_eml_scalar_eg(chartInstance);
  c2_b_y = c2_y;
  c2_b_x = c2_x;
  return muDoubleScalarAtan2(c2_b_y, c2_b_x);
}

static void c2_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
}

static real_T c2_mpower(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  real_T c2_e_a;
  real_T c2_b;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  c2_e_a = c2_d_a;
  c2_b = c2_d_a;
  return c2_e_a * c2_b;
}

static real_T c2_sqrt(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_eml_error(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
  int32_T c2_i174;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  int32_T c2_i175;
  static char_T c2_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  for (c2_i174 = 0; c2_i174 < 30; c2_i174++) {
    c2_u[c2_i174] = c2_cv0[c2_i174];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c2_i175 = 0; c2_i175 < 4; c2_i175++) {
    c2_b_u[c2_i175] = c2_cv1[c2_i175];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c2_y, 14, c2_b_y));
}

static void c2_inv(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                   c2_x[9], real_T c2_y[9])
{
  int32_T c2_i176;
  real_T c2_b_x[9];
  int32_T c2_i177;
  real_T c2_c_x[9];
  real_T c2_n1x;
  int32_T c2_i178;
  real_T c2_b_y[9];
  real_T c2_n1xinv;
  real_T c2_a;
  real_T c2_b;
  real_T c2_c_y;
  real_T c2_rc;
  real_T c2_d_x;
  boolean_T c2_b_b;
  real_T c2_e_x;
  int32_T c2_i179;
  static char_T c2_cv2[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c2_u[8];
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_g_y = NULL;
  char_T c2_str[14];
  int32_T c2_i180;
  char_T c2_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  for (c2_i176 = 0; c2_i176 < 9; c2_i176++) {
    c2_b_x[c2_i176] = c2_x[c2_i176];
  }

  c2_inv3x3(chartInstance, c2_b_x, c2_y);
  for (c2_i177 = 0; c2_i177 < 9; c2_i177++) {
    c2_c_x[c2_i177] = c2_x[c2_i177];
  }

  c2_n1x = c2_norm(chartInstance, c2_c_x);
  for (c2_i178 = 0; c2_i178 < 9; c2_i178++) {
    c2_b_y[c2_i178] = c2_y[c2_i178];
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
      c2_eps(chartInstance);
      if (c2_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c2_e_x = c2_rc;
      for (c2_i179 = 0; c2_i179 < 8; c2_i179++) {
        c2_u[c2_i179] = c2_cv2[c2_i179];
      }

      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c2_b_u = 14.0;
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c2_c_u = 6.0;
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c2_d_u = c2_e_x;
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c2_l_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c2_d_y, 14, c2_e_y, 14,
        c2_f_y), 14, c2_g_y), "sprintf", c2_str);
      for (c2_i180 = 0; c2_i180 < 14; c2_i180++) {
        c2_b_str[c2_i180] = c2_str[c2_i180];
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

static void c2_inv3x3(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      c2_x[9], real_T c2_y[9])
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
  real_T c2_z;
  real_T c2_i_x;
  real_T c2_c_y;
  real_T c2_b_z;
  real_T c2_a;
  real_T c2_b;
  real_T c2_d_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_e_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_f_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_g_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_h_y;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_i_y;
  int32_T c2_itmp;
  real_T c2_n_x;
  real_T c2_j_y;
  real_T c2_c_z;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_k_y;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_l_y;
  real_T c2_o_x;
  real_T c2_m_y;
  real_T c2_t3;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_n_y;
  real_T c2_p_x;
  real_T c2_o_y;
  real_T c2_t2;
  int32_T c2_h_a;
  int32_T c2_c;
  real_T c2_i_a;
  real_T c2_h_b;
  real_T c2_p_y;
  real_T c2_j_a;
  real_T c2_i_b;
  real_T c2_q_y;
  real_T c2_q_x;
  real_T c2_r_y;
  real_T c2_d_z;
  int32_T c2_k_a;
  int32_T c2_b_c;
  int32_T c2_l_a;
  int32_T c2_c_c;
  real_T c2_r_x;
  real_T c2_s_y;
  real_T c2_m_a;
  real_T c2_j_b;
  real_T c2_t_y;
  real_T c2_s_x;
  real_T c2_u_y;
  int32_T c2_n_a;
  int32_T c2_d_c;
  real_T c2_o_a;
  real_T c2_k_b;
  real_T c2_v_y;
  real_T c2_p_a;
  real_T c2_l_b;
  real_T c2_w_y;
  real_T c2_t_x;
  real_T c2_x_y;
  real_T c2_e_z;
  int32_T c2_q_a;
  int32_T c2_e_c;
  int32_T c2_r_a;
  int32_T c2_f_c;
  real_T c2_y_y;
  real_T c2_s_a;
  real_T c2_m_b;
  real_T c2_ab_y;
  real_T c2_u_x;
  real_T c2_bb_y;
  int32_T c2_t_a;
  int32_T c2_g_c;
  real_T c2_u_a;
  real_T c2_n_b;
  real_T c2_cb_y;
  real_T c2_v_a;
  real_T c2_o_b;
  real_T c2_db_y;
  real_T c2_v_x;
  real_T c2_eb_y;
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
  c2_z = c2_h_x / c2_b_y;
  c2_x[1] = c2_z;
  c2_i_x = c2_x[2];
  c2_c_y = c2_x[0];
  c2_b_z = c2_i_x / c2_c_y;
  c2_x[2] = c2_b_z;
  c2_a = c2_x[1];
  c2_b = c2_x[3];
  c2_d_y = c2_a * c2_b;
  c2_x[4] -= c2_d_y;
  c2_b_a = c2_x[2];
  c2_b_b = c2_x[3];
  c2_e_y = c2_b_a * c2_b_b;
  c2_x[5] -= c2_e_y;
  c2_c_a = c2_x[1];
  c2_c_b = c2_x[6];
  c2_f_y = c2_c_a * c2_c_b;
  c2_x[7] -= c2_f_y;
  c2_d_a = c2_x[2];
  c2_d_b = c2_x[6];
  c2_g_y = c2_d_a * c2_d_b;
  c2_x[8] -= c2_g_y;
  c2_j_x = c2_x[5];
  c2_k_x = c2_j_x;
  c2_h_y = muDoubleScalarAbs(c2_k_x);
  c2_l_x = c2_x[4];
  c2_m_x = c2_l_x;
  c2_i_y = muDoubleScalarAbs(c2_m_x);
  if (c2_h_y > c2_i_y) {
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

  c2_n_x = c2_x[5];
  c2_j_y = c2_x[4];
  c2_c_z = c2_n_x / c2_j_y;
  c2_x[5] = c2_c_z;
  c2_e_a = c2_x[5];
  c2_e_b = c2_x[7];
  c2_k_y = c2_e_a * c2_e_b;
  c2_x[8] -= c2_k_y;
  c2_f_a = c2_x[5];
  c2_f_b = c2_x[1];
  c2_l_y = c2_f_a * c2_f_b;
  c2_o_x = c2_l_y - c2_x[2];
  c2_m_y = c2_x[8];
  c2_t3 = c2_o_x / c2_m_y;
  c2_g_a = c2_x[7];
  c2_g_b = c2_t3;
  c2_n_y = c2_g_a * c2_g_b;
  c2_p_x = -(c2_x[1] + c2_n_y);
  c2_o_y = c2_x[4];
  c2_t2 = c2_p_x / c2_o_y;
  c2_h_a = c2_p1 + 1;
  c2_c = c2_h_a;
  c2_i_a = c2_x[3];
  c2_h_b = c2_t2;
  c2_p_y = c2_i_a * c2_h_b;
  c2_j_a = c2_x[6];
  c2_i_b = c2_t3;
  c2_q_y = c2_j_a * c2_i_b;
  c2_q_x = (1.0 - c2_p_y) - c2_q_y;
  c2_r_y = c2_x[0];
  c2_d_z = c2_q_x / c2_r_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_c), 1, 9, 1, 0) - 1] = c2_d_z;
  c2_k_a = c2_p1 + 2;
  c2_b_c = c2_k_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_b_c), 1, 9, 1, 0) - 1] = c2_t2;
  c2_l_a = c2_p1 + 3;
  c2_c_c = c2_l_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_c_c), 1, 9, 1, 0) - 1] = c2_t3;
  c2_r_x = -c2_x[5];
  c2_s_y = c2_x[8];
  c2_t3 = c2_r_x / c2_s_y;
  c2_m_a = c2_x[7];
  c2_j_b = c2_t3;
  c2_t_y = c2_m_a * c2_j_b;
  c2_s_x = 1.0 - c2_t_y;
  c2_u_y = c2_x[4];
  c2_t2 = c2_s_x / c2_u_y;
  c2_n_a = c2_p2 + 1;
  c2_d_c = c2_n_a;
  c2_o_a = c2_x[3];
  c2_k_b = c2_t2;
  c2_v_y = c2_o_a * c2_k_b;
  c2_p_a = c2_x[6];
  c2_l_b = c2_t3;
  c2_w_y = c2_p_a * c2_l_b;
  c2_t_x = -(c2_v_y + c2_w_y);
  c2_x_y = c2_x[0];
  c2_e_z = c2_t_x / c2_x_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_d_c), 1, 9, 1, 0) - 1] = c2_e_z;
  c2_q_a = c2_p2 + 2;
  c2_e_c = c2_q_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_e_c), 1, 9, 1, 0) - 1] = c2_t2;
  c2_r_a = c2_p2 + 3;
  c2_f_c = c2_r_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_f_c), 1, 9, 1, 0) - 1] = c2_t3;
  c2_y_y = c2_x[8];
  c2_t3 = 1.0 / c2_y_y;
  c2_s_a = -c2_x[7];
  c2_m_b = c2_t3;
  c2_ab_y = c2_s_a * c2_m_b;
  c2_u_x = c2_ab_y;
  c2_bb_y = c2_x[4];
  c2_t2 = c2_u_x / c2_bb_y;
  c2_t_a = c2_p3 + 1;
  c2_g_c = c2_t_a;
  c2_u_a = c2_x[3];
  c2_n_b = c2_t2;
  c2_cb_y = c2_u_a * c2_n_b;
  c2_v_a = c2_x[6];
  c2_o_b = c2_t3;
  c2_db_y = c2_v_a * c2_o_b;
  c2_v_x = -(c2_cb_y + c2_db_y);
  c2_eb_y = c2_x[0];
  c2_f_z = c2_v_x / c2_eb_y;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_g_c), 1, 9, 1, 0) - 1] = c2_f_z;
  c2_w_a = c2_p3 + 2;
  c2_h_c = c2_w_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_h_c), 1, 9, 1, 0) - 1] = c2_t2;
  c2_x_a = c2_p3 + 3;
  c2_i_c = c2_x_a;
  c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_i_c), 1, 9, 1, 0) - 1] = c2_t3;
}

static real_T c2_abs(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                     c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  return muDoubleScalarAbs(c2_b_x);
}

static real_T c2_eml_div(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x, real_T c2_y)
{
  return c2_x / c2_y;
}

static real_T c2_norm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      c2_x[9])
{
  real_T c2_y;
  int32_T c2_j;
  real_T c2_b_j;
  real_T c2_s;
  int32_T c2_i;
  real_T c2_b_i;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  boolean_T c2_b;
  boolean_T exitg1;
  c2_y = 0.0;
  c2_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c2_j < 3)) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_s = 0.0;
    for (c2_i = 0; c2_i < 3; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_b_x = c2_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 3, 1, 0) + 3 * ((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_j),
        1, 3, 2, 0) - 1)) - 1];
      c2_c_x = c2_b_x;
      c2_b_y = muDoubleScalarAbs(c2_c_x);
      c2_s += c2_b_y;
    }

    c2_d_x = c2_s;
    c2_b = muDoubleScalarIsNaN(c2_d_x);
    if (c2_b) {
      c2_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c2_s > c2_y) {
        c2_y = c2_s;
      }

      c2_j++;
    }
  }

  return c2_y;
}

static void c2_eml_warning(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
  int32_T c2_i181;
  static char_T c2_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c2_u[27];
  const mxArray *c2_y = NULL;
  for (c2_i181 = 0; c2_i181 < 27; c2_i181++) {
    c2_u[c2_i181] = c2_varargin_1[c2_i181];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c2_y));
}

static void c2_eps(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
}

static void c2_b_eml_warning(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  char_T c2_varargin_2[14])
{
  int32_T c2_i182;
  static char_T c2_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c2_u[33];
  const mxArray *c2_y = NULL;
  int32_T c2_i183;
  char_T c2_b_u[14];
  const mxArray *c2_b_y = NULL;
  for (c2_i182 = 0; c2_i182 < 33; c2_i182++) {
    c2_u[c2_i182] = c2_varargin_1[c2_i182];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c2_i183 = 0; c2_i183 < 14; c2_i183++) {
    c2_b_u[c2_i183] = c2_varargin_2[c2_i183];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c2_y, 14, c2_b_y));
}

static void c2_eye(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                   c2_I[9])
{
  int32_T c2_i184;
  int32_T c2_i;
  int32_T c2_b_i;
  for (c2_i184 = 0; c2_i184 < 9; c2_i184++) {
    c2_I[c2_i184] = 0.0;
  }

  for (c2_i = 1; c2_i < 4; c2_i++) {
    c2_b_i = c2_i;
    c2_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 3, 2, 0) - 1)) -
      1] = 1.0;
  }
}

static void c2_b_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_c_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_svd(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                   c2_A[24], real_T c2_U[36], real_T c2_S[24], real_T c2_V[16])
{
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_x;
  real_T c2_b_x;
  boolean_T c2_b;
  boolean_T c2_b0;
  real_T c2_c_x;
  boolean_T c2_b_b;
  boolean_T c2_b1;
  boolean_T c2_c_b;
  int32_T c2_i185;
  real_T c2_b_A[24];
  real_T c2_s[4];
  int32_T c2_i186;
  int32_T c2_c_k;
  real_T c2_d_k;
  for (c2_k = 1; c2_k < 25; c2_k++) {
    c2_b_k = c2_k;
    c2_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 24, 1, 0) - 1];
    c2_b_x = c2_x;
    c2_b = muDoubleScalarIsInf(c2_b_x);
    c2_b0 = !c2_b;
    c2_c_x = c2_x;
    c2_b_b = muDoubleScalarIsNaN(c2_c_x);
    c2_b1 = !c2_b_b;
    c2_c_b = (c2_b0 && c2_b1);
    if (!c2_c_b) {
      c2_b_eml_error(chartInstance);
    }
  }

  for (c2_i185 = 0; c2_i185 < 24; c2_i185++) {
    c2_b_A[c2_i185] = c2_A[c2_i185];
  }

  c2_eml_xgesvd(chartInstance, c2_b_A, c2_U, c2_s, c2_V);
  for (c2_i186 = 0; c2_i186 < 24; c2_i186++) {
    c2_S[c2_i186] = 0.0;
  }

  for (c2_c_k = 0; c2_c_k < 4; c2_c_k++) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    c2_S[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c2_d_k), 1, 6, 1, 0) + 6 * ((int32_T)(real_T)
           _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             c2_d_k), 1, 4, 2, 0) - 1)) - 1] = c2_s[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_d_k), 1,
      4, 1, 0) - 1];
  }
}

static void c2_b_eml_error(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
  int32_T c2_i187;
  static char_T c2_cv3[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c2_u[33];
  const mxArray *c2_y = NULL;
  for (c2_i187 = 0; c2_i187 < 33; c2_i187++) {
    c2_u[c2_i187] = c2_cv3[c2_i187];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_eml_xgesvd(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[24], real_T c2_U[36], real_T c2_S[4], real_T c2_V[16])
{
  int32_T c2_i188;
  real_T c2_b_A[24];
  int32_T c2_i189;
  real_T c2_s[4];
  int32_T c2_i190;
  real_T c2_e[4];
  int32_T c2_i191;
  real_T c2_work[6];
  int32_T c2_i192;
  int32_T c2_i193;
  int32_T c2_q;
  int32_T c2_b_q;
  int32_T c2_a;
  int32_T c2_qp1;
  int32_T c2_b_a;
  int32_T c2_qm1;
  int32_T c2_b;
  int32_T c2_c;
  int32_T c2_c_a;
  int32_T c2_b_b;
  int32_T c2_qq;
  int32_T c2_c_b;
  int32_T c2_nmq;
  int32_T c2_d_a;
  int32_T c2_nmqp1;
  int32_T c2_i194;
  real_T c2_c_A[24];
  real_T c2_nrm;
  real_T c2_absx;
  real_T c2_d;
  real_T c2_y;
  real_T c2_d2;
  int32_T c2_b_qp1;
  boolean_T c2_overflow;
  int32_T c2_jj;
  int32_T c2_b_jj;
  int32_T c2_e_a;
  int32_T c2_b_c;
  int32_T c2_d_b;
  int32_T c2_c_c;
  int32_T c2_f_a;
  int32_T c2_e_b;
  int32_T c2_qjj;
  int32_T c2_i195;
  real_T c2_d_A[24];
  int32_T c2_i196;
  real_T c2_e_A[24];
  real_T c2_t;
  int32_T c2_c_q;
  boolean_T c2_b_overflow;
  int32_T c2_ii;
  int32_T c2_b_ii;
  int32_T c2_f_b;
  int32_T c2_pmq;
  int32_T c2_i197;
  real_T c2_b_e[4];
  real_T c2_b_absx;
  real_T c2_b_d;
  real_T c2_b_y;
  real_T c2_d3;
  int32_T c2_c_qp1;
  boolean_T c2_c_overflow;
  int32_T c2_c_ii;
  int32_T c2_d_qp1;
  boolean_T c2_d_overflow;
  int32_T c2_c_jj;
  int32_T c2_g_a;
  int32_T c2_d_c;
  int32_T c2_g_b;
  int32_T c2_e_c;
  int32_T c2_h_a;
  int32_T c2_h_b;
  int32_T c2_qp1jj;
  int32_T c2_i198;
  real_T c2_f_A[24];
  int32_T c2_e_qp1;
  boolean_T c2_e_overflow;
  int32_T c2_d_jj;
  int32_T c2_i_a;
  int32_T c2_f_c;
  int32_T c2_i_b;
  int32_T c2_g_c;
  int32_T c2_j_a;
  int32_T c2_j_b;
  int32_T c2_i199;
  real_T c2_b_work[6];
  int32_T c2_f_qp1;
  boolean_T c2_f_overflow;
  int32_T c2_d_ii;
  int32_T c2_m;
  int32_T c2_e_jj;
  int32_T c2_e_ii;
  int32_T c2_d_q;
  int32_T c2_k_a;
  int32_T c2_k_b;
  int32_T c2_l_a;
  int32_T c2_m_a;
  int32_T c2_h_c;
  int32_T c2_l_b;
  int32_T c2_i_c;
  int32_T c2_n_a;
  int32_T c2_m_b;
  int32_T c2_g_qp1;
  boolean_T c2_g_overflow;
  int32_T c2_f_jj;
  int32_T c2_o_a;
  int32_T c2_j_c;
  int32_T c2_n_b;
  int32_T c2_k_c;
  int32_T c2_p_a;
  int32_T c2_o_b;
  int32_T c2_i200;
  real_T c2_b_U[36];
  int32_T c2_i201;
  real_T c2_c_U[36];
  int32_T c2_e_q;
  boolean_T c2_h_overflow;
  int32_T c2_f_ii;
  int32_T c2_q_a;
  int32_T c2_i202;
  int32_T c2_p_b;
  int32_T c2_q_b;
  boolean_T c2_i_overflow;
  int32_T c2_g_ii;
  int32_T c2_h_ii;
  int32_T c2_f_q;
  int32_T c2_r_a;
  int32_T c2_r_b;
  int32_T c2_s_a;
  int32_T c2_l_c;
  int32_T c2_s_b;
  int32_T c2_m_c;
  int32_T c2_t_a;
  int32_T c2_t_b;
  int32_T c2_qp1q;
  int32_T c2_h_qp1;
  boolean_T c2_j_overflow;
  int32_T c2_g_jj;
  int32_T c2_u_a;
  int32_T c2_n_c;
  int32_T c2_u_b;
  int32_T c2_o_c;
  int32_T c2_v_a;
  int32_T c2_v_b;
  int32_T c2_i203;
  real_T c2_b_V[16];
  int32_T c2_i204;
  real_T c2_c_V[16];
  int32_T c2_i_ii;
  int32_T c2_g_q;
  real_T c2_rt;
  real_T c2_r;
  int32_T c2_w_a;
  int32_T c2_p_c;
  int32_T c2_w_b;
  int32_T c2_q_c;
  int32_T c2_x_b;
  int32_T c2_colq;
  int32_T c2_x_a;
  int32_T c2_r_c;
  int32_T c2_y_a;
  int32_T c2_s_c;
  real_T c2_ab_a;
  real_T c2_y_b;
  real_T c2_c_y;
  int32_T c2_ab_b;
  int32_T c2_t_c;
  int32_T c2_bb_b;
  int32_T c2_colqp1;
  real_T c2_iter;
  real_T c2_tiny;
  real_T c2_snorm;
  int32_T c2_j_ii;
  real_T c2_varargin_1;
  real_T c2_varargin_2;
  real_T c2_b_varargin_2;
  real_T c2_varargin_3;
  real_T c2_x;
  real_T c2_d_y;
  real_T c2_b_x;
  real_T c2_e_y;
  real_T c2_xk;
  real_T c2_yk;
  real_T c2_c_x;
  real_T c2_f_y;
  real_T c2_maxval;
  real_T c2_b_varargin_1;
  real_T c2_c_varargin_2;
  real_T c2_d_varargin_2;
  real_T c2_b_varargin_3;
  real_T c2_d_x;
  real_T c2_g_y;
  real_T c2_e_x;
  real_T c2_h_y;
  real_T c2_b_xk;
  real_T c2_b_yk;
  real_T c2_f_x;
  real_T c2_i_y;
  int32_T c2_bb_a;
  int32_T c2_cb_a;
  int32_T c2_i205;
  boolean_T c2_k_overflow;
  int32_T c2_k_ii;
  int32_T c2_db_a;
  int32_T c2_u_c;
  real_T c2_test0;
  real_T c2_ztest0;
  real_T c2_cb_b;
  real_T c2_j_y;
  real_T c2_db_b;
  real_T c2_k_y;
  int32_T c2_eb_a;
  int32_T c2_v_c;
  real_T c2_kase;
  int32_T c2_qs;
  int32_T c2_b_m;
  int32_T c2_h_q;
  int32_T c2_fb_a;
  int32_T c2_eb_b;
  int32_T c2_gb_a;
  int32_T c2_fb_b;
  boolean_T c2_l_overflow;
  int32_T c2_l_ii;
  real_T c2_test;
  int32_T c2_hb_a;
  int32_T c2_w_c;
  int32_T c2_ib_a;
  int32_T c2_x_c;
  real_T c2_ztest;
  real_T c2_gb_b;
  real_T c2_l_y;
  int32_T c2_jb_a;
  int32_T c2_kb_a;
  int32_T c2_y_c;
  real_T c2_f;
  int32_T c2_lb_a;
  int32_T c2_ab_c;
  int32_T c2_mb_a;
  int32_T c2_i206;
  int32_T c2_i_q;
  int32_T c2_nb_a;
  int32_T c2_hb_b;
  int32_T c2_ob_a;
  int32_T c2_ib_b;
  boolean_T c2_m_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_t1;
  real_T c2_b_t1;
  real_T c2_b_f;
  real_T c2_sn;
  real_T c2_cs;
  real_T c2_b_cs;
  real_T c2_b_sn;
  int32_T c2_pb_a;
  int32_T c2_km1;
  real_T c2_qb_a;
  real_T c2_jb_b;
  real_T c2_rb_a;
  real_T c2_kb_b;
  real_T c2_m_y;
  int32_T c2_sb_a;
  int32_T c2_bb_c;
  int32_T c2_lb_b;
  int32_T c2_cb_c;
  int32_T c2_mb_b;
  int32_T c2_colk;
  int32_T c2_tb_a;
  int32_T c2_db_c;
  int32_T c2_nb_b;
  int32_T c2_eb_c;
  int32_T c2_ob_b;
  int32_T c2_colm;
  int32_T c2_ub_a;
  int32_T c2_j_q;
  int32_T c2_c_m;
  int32_T c2_vb_a;
  int32_T c2_pb_b;
  int32_T c2_wb_a;
  int32_T c2_qb_b;
  boolean_T c2_n_overflow;
  int32_T c2_c_k;
  real_T c2_c_t1;
  real_T c2_unusedU0;
  real_T c2_c_sn;
  real_T c2_c_cs;
  real_T c2_xb_a;
  real_T c2_rb_b;
  real_T c2_yb_a;
  real_T c2_sb_b;
  real_T c2_n_y;
  int32_T c2_ac_a;
  int32_T c2_fb_c;
  int32_T c2_tb_b;
  int32_T c2_gb_c;
  int32_T c2_ub_b;
  int32_T c2_bc_a;
  int32_T c2_hb_c;
  int32_T c2_vb_b;
  int32_T c2_ib_c;
  int32_T c2_wb_b;
  int32_T c2_colqm1;
  int32_T c2_cc_a;
  int32_T c2_mm1;
  real_T c2_d4;
  real_T c2_d5;
  real_T c2_d6;
  real_T c2_d7;
  real_T c2_d8;
  real_T c2_c_varargin_1[5];
  int32_T c2_ixstart;
  real_T c2_mtmp;
  real_T c2_g_x;
  boolean_T c2_xb_b;
  int32_T c2_ix;
  int32_T c2_b_ix;
  real_T c2_h_x;
  boolean_T c2_yb_b;
  int32_T c2_dc_a;
  int32_T c2_i207;
  boolean_T c2_o_overflow;
  int32_T c2_c_ix;
  real_T c2_ec_a;
  real_T c2_ac_b;
  boolean_T c2_p;
  real_T c2_b_mtmp;
  real_T c2_scale;
  real_T c2_sm;
  real_T c2_smm1;
  real_T c2_emm1;
  real_T c2_sqds;
  real_T c2_eqds;
  real_T c2_fc_a;
  real_T c2_bc_b;
  real_T c2_o_y;
  real_T c2_gc_a;
  real_T c2_cc_b;
  real_T c2_p_y;
  real_T c2_dc_b;
  real_T c2_hc_a;
  real_T c2_ec_b;
  real_T c2_jb_c;
  real_T c2_ic_a;
  real_T c2_fc_b;
  real_T c2_shift;
  real_T c2_jc_a;
  real_T c2_gc_b;
  real_T c2_q_y;
  real_T c2_kc_a;
  real_T c2_hc_b;
  real_T c2_r_y;
  real_T c2_lc_a;
  real_T c2_ic_b;
  real_T c2_g;
  int32_T c2_k_q;
  int32_T c2_b_mm1;
  int32_T c2_mc_a;
  int32_T c2_jc_b;
  int32_T c2_nc_a;
  int32_T c2_kc_b;
  boolean_T c2_p_overflow;
  int32_T c2_d_k;
  int32_T c2_oc_a;
  int32_T c2_pc_a;
  int32_T c2_kp1;
  real_T c2_c_f;
  real_T c2_unusedU1;
  real_T c2_d_sn;
  real_T c2_d_cs;
  real_T c2_qc_a;
  real_T c2_lc_b;
  real_T c2_s_y;
  real_T c2_rc_a;
  real_T c2_mc_b;
  real_T c2_t_y;
  real_T c2_sc_a;
  real_T c2_nc_b;
  real_T c2_u_y;
  real_T c2_tc_a;
  real_T c2_oc_b;
  real_T c2_v_y;
  real_T c2_uc_a;
  real_T c2_pc_b;
  real_T c2_vc_a;
  real_T c2_qc_b;
  real_T c2_w_y;
  int32_T c2_wc_a;
  int32_T c2_kb_c;
  int32_T c2_rc_b;
  int32_T c2_lb_c;
  int32_T c2_sc_b;
  int32_T c2_tc_b;
  int32_T c2_mb_c;
  int32_T c2_uc_b;
  int32_T c2_colkp1;
  real_T c2_d_f;
  real_T c2_unusedU2;
  real_T c2_e_sn;
  real_T c2_e_cs;
  real_T c2_xc_a;
  real_T c2_vc_b;
  real_T c2_x_y;
  real_T c2_yc_a;
  real_T c2_wc_b;
  real_T c2_y_y;
  real_T c2_ad_a;
  real_T c2_xc_b;
  real_T c2_ab_y;
  real_T c2_bd_a;
  real_T c2_yc_b;
  real_T c2_bb_y;
  real_T c2_cd_a;
  real_T c2_ad_b;
  real_T c2_dd_a;
  real_T c2_bd_b;
  real_T c2_cb_y;
  int32_T c2_ed_a;
  int32_T c2_nb_c;
  int32_T c2_cd_b;
  int32_T c2_ob_c;
  int32_T c2_dd_b;
  int32_T c2_ed_b;
  int32_T c2_pb_c;
  int32_T c2_fd_b;
  int32_T c2_fd_a;
  int32_T c2_qb_c;
  int32_T c2_e_k;
  int32_T c2_rb_c;
  int32_T c2_gd_a;
  int32_T c2_sb_c;
  int32_T c2_gd_b;
  int32_T c2_hd_b;
  int32_T c2_hd_a;
  int32_T c2_id_a;
  int32_T c2_tb_c;
  int32_T c2_jd_a;
  int32_T c2_ub_c;
  int32_T c2_id_b;
  int32_T c2_jd_b;
  int32_T c2_vb_c;
  int32_T c2_kd_b;
  int32_T c2_ld_b;
  int32_T c2_wb_c;
  int32_T c2_kd_a;
  int32_T c2_xb_c;
  int32_T c2_md_b;
  int32_T c2_nd_b;
  int32_T c2_yb_c;
  int32_T c2_od_b;
  int32_T c2_pd_b;
  int32_T c2_ld_a;
  real_T c2_d9;
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
  for (c2_i188 = 0; c2_i188 < 24; c2_i188++) {
    c2_b_A[c2_i188] = c2_A[c2_i188];
  }

  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i189 = 0; c2_i189 < 4; c2_i189++) {
    c2_s[c2_i189] = 0.0;
  }

  for (c2_i190 = 0; c2_i190 < 4; c2_i190++) {
    c2_e[c2_i190] = 0.0;
  }

  for (c2_i191 = 0; c2_i191 < 6; c2_i191++) {
    c2_work[c2_i191] = 0.0;
  }

  for (c2_i192 = 0; c2_i192 < 36; c2_i192++) {
    c2_U[c2_i192] = 0.0;
  }

  for (c2_i193 = 0; c2_i193 < 16; c2_i193++) {
    c2_V[c2_i193] = 0.0;
  }

  for (c2_q = 1; c2_q < 5; c2_q++) {
    c2_b_q = c2_q;
    c2_a = c2_b_q + 1;
    c2_qp1 = c2_a;
    c2_b_a = c2_b_q;
    c2_qm1 = c2_b_a;
    c2_b = c2_qm1 - 1;
    c2_c = 6 * c2_b;
    c2_c_a = c2_b_q;
    c2_b_b = c2_c;
    c2_qq = c2_c_a + c2_b_b;
    c2_c_b = c2_b_q;
    c2_nmq = 6 - c2_c_b;
    c2_d_a = c2_nmq + 1;
    c2_nmqp1 = c2_d_a;
    if (c2_b_q <= 4) {
      for (c2_i194 = 0; c2_i194 < 24; c2_i194++) {
        c2_c_A[c2_i194] = c2_b_A[c2_i194];
      }

      c2_nrm = c2_eml_xnrm2(chartInstance, c2_nmqp1, c2_c_A, c2_qq);
      if (c2_nrm > 0.0) {
        c2_absx = c2_nrm;
        c2_d = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_qq), 1, 24, 1, 0) - 1];
        if (c2_d < 0.0) {
          c2_y = -c2_absx;
        } else {
          c2_y = c2_absx;
        }

        c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] = c2_y;
        c2_d2 = c2_eml_div(chartInstance, 1.0, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1]);
        c2_e_eml_xscal(chartInstance, c2_nmqp1, c2_d2, c2_b_A, c2_qq);
        c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_qq), 1, 24, 1, 0) - 1] = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_qq), 1, 24, 1, 0) - 1]
          + 1.0;
        c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] = -c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1];
      } else {
        c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] = 0.0;
      }
    }

    c2_b_qp1 = c2_qp1;
    c2_overflow = FALSE;
    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_jj = c2_b_qp1; c2_jj < 5; c2_jj++) {
      c2_b_jj = c2_jj;
      c2_e_a = c2_b_jj;
      c2_b_c = c2_e_a;
      c2_d_b = c2_b_c - 1;
      c2_c_c = 6 * c2_d_b;
      c2_f_a = c2_b_q;
      c2_e_b = c2_c_c;
      c2_qjj = c2_f_a + c2_e_b;
      if (c2_b_q <= 4) {
        if (c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_b_q), 1, 4, 1, 0) - 1] != 0.0) {
          for (c2_i195 = 0; c2_i195 < 24; c2_i195++) {
            c2_d_A[c2_i195] = c2_b_A[c2_i195];
          }

          for (c2_i196 = 0; c2_i196 < 24; c2_i196++) {
            c2_e_A[c2_i196] = c2_b_A[c2_i196];
          }

          c2_t = c2_eml_xdotc(chartInstance, c2_nmqp1, c2_d_A, c2_qq, c2_e_A,
                              c2_qjj);
          c2_t = -c2_eml_div(chartInstance, c2_t, c2_b_A
                             [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 6, 1, 0) + 6 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 2, 0) - 1)) - 1]);
          c2_f_eml_xaxpy(chartInstance, c2_nmqp1, c2_t, c2_qq, c2_b_A, c2_qjj);
        }
      }

      c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_jj), 1, 4, 1, 0) - 1] = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_qjj), 1, 24, 1, 0) - 1];
    }

    if (c2_b_q <= 4) {
      c2_c_q = c2_b_q;
      c2_b_overflow = FALSE;
      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
      }

      for (c2_ii = c2_c_q; c2_ii < 7; c2_ii++) {
        c2_b_ii = c2_ii;
        c2_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 6, 2, 0)
               - 1)) - 1] = c2_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_ii), 1, 6, 1, 0) + 6 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 2, 0) - 1)) - 1];
      }
    }

    if (c2_b_q <= 2) {
      c2_f_b = c2_b_q;
      c2_pmq = 4 - c2_f_b;
      for (c2_i197 = 0; c2_i197 < 4; c2_i197++) {
        c2_b_e[c2_i197] = c2_e[c2_i197];
      }

      c2_nrm = c2_b_eml_xnrm2(chartInstance, c2_pmq, c2_b_e, c2_qp1);
      if (c2_nrm == 0.0) {
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] = 0.0;
      } else {
        c2_b_absx = c2_nrm;
        c2_b_d = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_qp1), 1, 4, 1, 0) - 1];
        if (c2_b_d < 0.0) {
          c2_b_y = -c2_b_absx;
        } else {
          c2_b_y = c2_b_absx;
        }

        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] = c2_b_y;
        c2_d3 = c2_eml_div(chartInstance, 1.0, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1]);
        c2_f_eml_xscal(chartInstance, c2_pmq, c2_d3, c2_e, c2_qp1);
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_qp1), 1, 4, 1, 0) - 1] = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_qp1), 1, 4, 1, 0) - 1]
          + 1.0;
      }

      c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_q), 1, 4, 1, 0) - 1] = -c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1];
      if (c2_qp1 <= 6) {
        if (c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_b_q), 1, 4, 1, 0) - 1] != 0.0) {
          c2_c_qp1 = c2_qp1;
          c2_c_overflow = FALSE;
          if (c2_c_overflow) {
            c2_check_forloop_overflow_error(chartInstance, c2_c_overflow);
          }

          for (c2_c_ii = c2_c_qp1; c2_c_ii < 7; c2_c_ii++) {
            c2_b_ii = c2_c_ii;
            c2_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_b_ii), 1, 6, 1, 0) - 1] = 0.0;
          }

          c2_d_qp1 = c2_qp1;
          c2_d_overflow = FALSE;
          if (c2_d_overflow) {
            c2_check_forloop_overflow_error(chartInstance, c2_d_overflow);
          }

          for (c2_c_jj = c2_d_qp1; c2_c_jj < 5; c2_c_jj++) {
            c2_b_jj = c2_c_jj;
            c2_g_a = c2_b_jj;
            c2_d_c = c2_g_a;
            c2_g_b = c2_d_c - 1;
            c2_e_c = 6 * c2_g_b;
            c2_h_a = c2_qp1;
            c2_h_b = c2_e_c;
            c2_qp1jj = c2_h_a + c2_h_b;
            for (c2_i198 = 0; c2_i198 < 24; c2_i198++) {
              c2_f_A[c2_i198] = c2_b_A[c2_i198];
            }

            c2_g_eml_xaxpy(chartInstance, c2_nmq,
                           c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_b_jj), 1, 4, 1, 0) - 1], c2_f_A,
                           c2_qp1jj, c2_work, c2_qp1);
          }

          c2_e_qp1 = c2_qp1;
          c2_e_overflow = FALSE;
          if (c2_e_overflow) {
            c2_check_forloop_overflow_error(chartInstance, c2_e_overflow);
          }

          for (c2_d_jj = c2_e_qp1; c2_d_jj < 5; c2_d_jj++) {
            c2_b_jj = c2_d_jj;
            c2_t = c2_eml_div(chartInstance, -c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_jj), 1, 4, 1, 0)
                              - 1], c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_qp1), 1, 4, 1, 0) - 1]);
            c2_i_a = c2_b_jj;
            c2_f_c = c2_i_a;
            c2_i_b = c2_f_c - 1;
            c2_g_c = 6 * c2_i_b;
            c2_j_a = c2_qp1;
            c2_j_b = c2_g_c;
            c2_qp1jj = c2_j_a + c2_j_b;
            for (c2_i199 = 0; c2_i199 < 6; c2_i199++) {
              c2_b_work[c2_i199] = c2_work[c2_i199];
            }

            c2_h_eml_xaxpy(chartInstance, c2_nmq, c2_t, c2_b_work, c2_qp1,
                           c2_b_A, c2_qp1jj);
          }
        }
      }

      c2_f_qp1 = c2_qp1;
      c2_f_overflow = FALSE;
      if (c2_f_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_f_overflow);
      }

      for (c2_d_ii = c2_f_qp1; c2_d_ii < 5; c2_d_ii++) {
        c2_b_ii = c2_d_ii;
        c2_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_ii), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 2, 0) -
                1) << 2)) - 1] = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_ii), 1, 4, 1, 0) - 1];
      }
    }
  }

  c2_m = 4;
  c2_e[2] = c2_b_A[20];
  c2_e[3] = 0.0;
  for (c2_e_jj = 5; c2_e_jj < 7; c2_e_jj++) {
    c2_b_jj = c2_e_jj;
    for (c2_e_ii = 1; c2_e_ii < 7; c2_e_ii++) {
      c2_b_ii = c2_e_ii;
      c2_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_jj), 1, 6, 2, 0)
             - 1)) - 1] = 0.0;
    }

    c2_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_jj), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_jj), 1, 6, 2, 0) - 1))
      - 1] = 1.0;
  }

  for (c2_d_q = 4; c2_d_q > 0; c2_d_q--) {
    c2_b_q = c2_d_q;
    c2_k_a = c2_b_q;
    c2_qp1 = c2_k_a;
    c2_k_b = c2_b_q;
    c2_nmq = 6 - c2_k_b;
    c2_l_a = c2_nmq + 1;
    c2_nmqp1 = c2_l_a;
    c2_m_a = c2_b_q;
    c2_h_c = c2_m_a;
    c2_l_b = c2_h_c - 1;
    c2_i_c = 6 * c2_l_b;
    c2_n_a = c2_b_q;
    c2_m_b = c2_i_c;
    c2_qq = c2_n_a + c2_m_b;
    if (c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] != 0.0) {
      c2_g_qp1 = c2_qp1 + 1;
      c2_g_overflow = FALSE;
      if (c2_g_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_g_overflow);
      }

      for (c2_f_jj = c2_g_qp1; c2_f_jj < 7; c2_f_jj++) {
        c2_b_jj = c2_f_jj;
        c2_o_a = c2_b_jj;
        c2_j_c = c2_o_a;
        c2_n_b = c2_j_c - 1;
        c2_k_c = 6 * c2_n_b;
        c2_p_a = c2_b_q;
        c2_o_b = c2_k_c;
        c2_qjj = c2_p_a + c2_o_b;
        for (c2_i200 = 0; c2_i200 < 36; c2_i200++) {
          c2_b_U[c2_i200] = c2_U[c2_i200];
        }

        for (c2_i201 = 0; c2_i201 < 36; c2_i201++) {
          c2_c_U[c2_i201] = c2_U[c2_i201];
        }

        c2_t = c2_b_eml_xdotc(chartInstance, c2_nmqp1, c2_b_U, c2_qq, c2_c_U,
                              c2_qjj);
        c2_t = -c2_eml_div(chartInstance, c2_t, c2_U[_SFD_EML_ARRAY_BOUNDS_CHECK
                           ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_qq),
                            1, 36, 1, 0) - 1]);
        c2_i_eml_xaxpy(chartInstance, c2_nmqp1, c2_t, c2_qq, c2_U, c2_qjj);
      }

      c2_e_q = c2_b_q;
      c2_h_overflow = FALSE;
      if (c2_h_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_h_overflow);
      }

      for (c2_f_ii = c2_e_q; c2_f_ii < 7; c2_f_ii++) {
        c2_b_ii = c2_f_ii;
        c2_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 6, 2, 0)
               - 1)) - 1] = -c2_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_ii), 1, 6, 1, 0) + 6 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 6, 2, 0) - 1)) - 1];
      }

      c2_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_qq), 1, 36, 1, 0) - 1] = c2_U[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_qq), 1, 36, 1, 0) - 1] + 1.0;
      c2_q_a = c2_b_q - 1;
      c2_i202 = c2_q_a;
      c2_p_b = c2_i202;
      c2_q_b = c2_p_b;
      if (1 > c2_q_b) {
        c2_i_overflow = FALSE;
      } else {
        c2_i_overflow = (c2_q_b > 2147483646);
      }

      if (c2_i_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_i_overflow);
      }

      for (c2_g_ii = 1; c2_g_ii <= c2_i202; c2_g_ii++) {
        c2_b_ii = c2_g_ii;
        c2_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 6, 2, 0)
               - 1)) - 1] = 0.0;
      }
    } else {
      for (c2_h_ii = 1; c2_h_ii < 7; c2_h_ii++) {
        c2_b_ii = c2_h_ii;
        c2_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 6, 2, 0)
               - 1)) - 1] = 0.0;
      }

      c2_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_qq), 1, 36, 1, 0) - 1] = 1.0;
    }
  }

  for (c2_f_q = 4; c2_f_q > 0; c2_f_q--) {
    c2_b_q = c2_f_q;
    if (c2_b_q <= 2) {
      if (c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_q), 1, 4, 1, 0) - 1] != 0.0) {
        c2_r_a = c2_b_q + 1;
        c2_qp1 = c2_r_a;
        c2_r_b = c2_b_q;
        c2_pmq = 4 - c2_r_b;
        c2_s_a = c2_b_q;
        c2_l_c = c2_s_a;
        c2_s_b = c2_l_c - 1;
        c2_m_c = c2_s_b << 2;
        c2_t_a = c2_qp1;
        c2_t_b = c2_m_c;
        c2_qp1q = c2_t_a + c2_t_b;
        c2_h_qp1 = c2_qp1;
        c2_j_overflow = FALSE;
        if (c2_j_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_j_overflow);
        }

        for (c2_g_jj = c2_h_qp1; c2_g_jj < 5; c2_g_jj++) {
          c2_b_jj = c2_g_jj;
          c2_u_a = c2_b_jj;
          c2_n_c = c2_u_a;
          c2_u_b = c2_n_c - 1;
          c2_o_c = c2_u_b << 2;
          c2_v_a = c2_qp1;
          c2_v_b = c2_o_c;
          c2_qp1jj = c2_v_a + c2_v_b;
          for (c2_i203 = 0; c2_i203 < 16; c2_i203++) {
            c2_b_V[c2_i203] = c2_V[c2_i203];
          }

          for (c2_i204 = 0; c2_i204 < 16; c2_i204++) {
            c2_c_V[c2_i204] = c2_V[c2_i204];
          }

          c2_t = c2_c_eml_xdotc(chartInstance, c2_pmq, c2_b_V, c2_qp1q, c2_c_V,
                                c2_qp1jj);
          c2_t = -c2_eml_div(chartInstance, c2_t,
                             c2_V[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_qp1q), 1, 16, 1, 0) - 1]);
          c2_j_eml_xaxpy(chartInstance, c2_pmq, c2_t, c2_qp1q, c2_V, c2_qp1jj);
        }
      }
    }

    for (c2_i_ii = 1; c2_i_ii < 5; c2_i_ii++) {
      c2_b_ii = c2_i_ii;
      c2_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_b_ii), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 2, 0) - 1)
             << 2)) - 1] = 0.0;
    }

    c2_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_q), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 2, 0) - 1) <<
           2)) - 1] = 1.0;
  }

  for (c2_g_q = 1; c2_g_q < 5; c2_g_q++) {
    c2_b_q = c2_g_q;
    if (c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] != 0.0) {
      c2_rt = c2_abs(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1]);
      c2_r = c2_eml_div(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1], c2_rt);
      c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_q), 1, 4, 1, 0) - 1] = c2_rt;
      if (c2_b_q < 4) {
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] = c2_eml_div(chartInstance,
          c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1], c2_r);
      }

      if (c2_b_q <= 6) {
        c2_w_a = c2_b_q;
        c2_p_c = c2_w_a;
        c2_w_b = c2_p_c - 1;
        c2_q_c = 6 * c2_w_b;
        c2_x_b = c2_q_c;
        c2_colq = c2_x_b;
        c2_g_eml_xscal(chartInstance, c2_r, c2_U, c2_colq + 1);
      }
    }

    if (c2_b_q < 4) {
      if (c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_q), 1, 4, 1, 0) - 1] != 0.0) {
        c2_rt = c2_abs(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1]);
        c2_r = c2_eml_div(chartInstance, c2_rt, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK
                          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q),
                           1, 4, 1, 0) - 1]);
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_q), 1, 4, 1, 0) - 1] = c2_rt;
        c2_x_a = c2_b_q;
        c2_r_c = c2_x_a;
        c2_y_a = c2_b_q;
        c2_s_c = c2_y_a;
        c2_ab_a = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c2_s_c + 1)), 1, 4, 1, 0) - 1];
        c2_y_b = c2_r;
        c2_c_y = c2_ab_a * c2_y_b;
        c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_r_c + 1)), 1, 4, 1, 0) - 1] = c2_c_y;
        c2_ab_b = c2_b_q;
        c2_t_c = c2_ab_b << 2;
        c2_bb_b = c2_t_c;
        c2_colqp1 = c2_bb_b;
        c2_h_eml_xscal(chartInstance, c2_r, c2_V, c2_colqp1 + 1);
      }
    }
  }

  c2_iter = 0.0;
  c2_realmin(chartInstance);
  c2_eps(chartInstance);
  c2_tiny = c2_eml_div(chartInstance, 2.2250738585072014E-308,
                       2.2204460492503131E-16);
  c2_snorm = 0.0;
  for (c2_j_ii = 1; c2_j_ii < 5; c2_j_ii++) {
    c2_b_ii = c2_j_ii;
    c2_varargin_1 = c2_abs(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_ii), 1, 4, 1, 0) - 1]);
    c2_varargin_2 = c2_abs(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_ii), 1, 4, 1, 0) - 1]);
    c2_b_varargin_2 = c2_varargin_1;
    c2_varargin_3 = c2_varargin_2;
    c2_x = c2_b_varargin_2;
    c2_d_y = c2_varargin_3;
    c2_b_x = c2_x;
    c2_e_y = c2_d_y;
    c2_eml_scalar_eg(chartInstance);
    c2_xk = c2_b_x;
    c2_yk = c2_e_y;
    c2_c_x = c2_xk;
    c2_f_y = c2_yk;
    c2_eml_scalar_eg(chartInstance);
    c2_maxval = muDoubleScalarMax(c2_c_x, c2_f_y);
    c2_b_varargin_1 = c2_snorm;
    c2_c_varargin_2 = c2_maxval;
    c2_d_varargin_2 = c2_b_varargin_1;
    c2_b_varargin_3 = c2_c_varargin_2;
    c2_d_x = c2_d_varargin_2;
    c2_g_y = c2_b_varargin_3;
    c2_e_x = c2_d_x;
    c2_h_y = c2_g_y;
    c2_eml_scalar_eg(chartInstance);
    c2_b_xk = c2_e_x;
    c2_b_yk = c2_h_y;
    c2_f_x = c2_b_xk;
    c2_i_y = c2_b_yk;
    c2_eml_scalar_eg(chartInstance);
    c2_snorm = muDoubleScalarMax(c2_f_x, c2_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c2_m > 0)) {
    if (c2_iter >= 75.0) {
      c2_c_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c2_bb_a = c2_m - 1;
      c2_b_q = c2_bb_a;
      c2_cb_a = c2_m;
      c2_i205 = c2_cb_a;
      c2_k_overflow = FALSE;
      if (c2_k_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_k_overflow);
      }

      c2_k_ii = c2_i205 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c2_k_ii > -1)) {
        c2_b_ii = c2_k_ii;
        c2_b_q = c2_b_ii;
        if (c2_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c2_db_a = c2_b_ii;
          c2_u_c = c2_db_a;
          c2_test0 = c2_abs(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_ii), 1,
            4, 1, 0) - 1]) + c2_abs(chartInstance,
            c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                                      (real_T)(c2_u_c + 1)), 1, 4, 1, 0) - 1]);
          c2_ztest0 = c2_abs(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_ii),
            1, 4, 1, 0) - 1]);
          c2_eps(chartInstance);
          c2_cb_b = c2_test0;
          c2_j_y = 2.2204460492503131E-16 * c2_cb_b;
          if (c2_ztest0 <= c2_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c2_ztest0 <= c2_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c2_iter > 20.0) {
              c2_eps(chartInstance);
              c2_db_b = c2_snorm;
              c2_k_y = 2.2204460492503131E-16 * c2_db_b;
              if (c2_ztest0 <= c2_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c2_k_ii--;
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
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_ii), 1, 4, 1, 0) - 1] = 0.0;
      }

      c2_eb_a = c2_m;
      c2_v_c = c2_eb_a;
      if (c2_b_q == c2_v_c - 1) {
        c2_kase = 4.0;
      } else {
        c2_qs = c2_m;
        c2_b_m = c2_m;
        c2_h_q = c2_b_q;
        c2_fb_a = c2_b_m;
        c2_eb_b = c2_h_q;
        c2_gb_a = c2_fb_a;
        c2_fb_b = c2_eb_b;
        if (c2_gb_a < c2_fb_b) {
          c2_l_overflow = FALSE;
        } else {
          c2_l_overflow = (c2_fb_b < -2147483647);
        }

        if (c2_l_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_l_overflow);
        }

        c2_l_ii = c2_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c2_l_ii >= c2_h_q)) {
          c2_b_ii = c2_l_ii;
          c2_qs = c2_b_ii;
          if (c2_b_ii == c2_b_q) {
            exitg4 = TRUE;
          } else {
            c2_test = 0.0;
            if (c2_b_ii < c2_m) {
              c2_test = c2_abs(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_ii), 1, 4, 1, 0)
                               - 1]);
            }

            c2_hb_a = c2_b_q;
            c2_w_c = c2_hb_a;
            if (c2_b_ii > c2_w_c + 1) {
              c2_ib_a = c2_b_ii;
              c2_x_c = c2_ib_a;
              c2_test += c2_abs(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c2_x_c - 1)), 1, 4,
                1, 0) - 1]);
            }

            c2_ztest = c2_abs(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_ii),
              1, 4, 1, 0) - 1]);
            c2_eps(chartInstance);
            c2_gb_b = c2_test;
            c2_l_y = 2.2204460492503131E-16 * c2_gb_b;
            if (c2_ztest <= c2_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c2_ztest <= c2_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c2_l_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ii), 1, 4, 1, 0) - 1] = 0.0;
        }

        if (c2_qs == c2_b_q) {
          c2_kase = 3.0;
        } else if (c2_qs == c2_m) {
          c2_kase = 1.0;
        } else {
          c2_kase = 2.0;
          c2_b_q = c2_qs;
        }
      }

      c2_jb_a = c2_b_q + 1;
      c2_b_q = c2_jb_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c2_kase)) {
       case 1:
        c2_kb_a = c2_m;
        c2_y_c = c2_kb_a;
        c2_f = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)(c2_y_c - 1)), 1, 4, 1, 0) - 1];
        c2_lb_a = c2_m;
        c2_ab_c = c2_lb_a;
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_ab_c - 1)), 1, 4, 1, 0) - 1] = 0.0;
        c2_mb_a = c2_m - 1;
        c2_i206 = c2_mb_a;
        c2_i_q = c2_b_q;
        c2_nb_a = c2_i206;
        c2_hb_b = c2_i_q;
        c2_ob_a = c2_nb_a;
        c2_ib_b = c2_hb_b;
        if (c2_ob_a < c2_ib_b) {
          c2_m_overflow = FALSE;
        } else {
          c2_m_overflow = (c2_ib_b < -2147483647);
        }

        if (c2_m_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_m_overflow);
        }

        for (c2_k = c2_i206; c2_k >= c2_i_q; c2_k--) {
          c2_b_k = c2_k;
          c2_t1 = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_b_t1 = c2_t1;
          c2_b_f = c2_f;
          c2_b_eml_xrotg(chartInstance, &c2_b_t1, &c2_b_f, &c2_cs, &c2_sn);
          c2_t1 = c2_b_t1;
          c2_f = c2_b_f;
          c2_b_cs = c2_cs;
          c2_b_sn = c2_sn;
          c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 4, 1, 0) - 1] = c2_t1;
          if (c2_b_k > c2_b_q) {
            c2_pb_a = c2_b_k - 1;
            c2_km1 = c2_pb_a;
            c2_qb_a = -c2_b_sn;
            c2_jb_b = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_km1), 1, 4, 1, 0) - 1];
            c2_f = c2_qb_a * c2_jb_b;
            c2_rb_a = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_km1), 1, 4, 1, 0) - 1];
            c2_kb_b = c2_b_cs;
            c2_m_y = c2_rb_a * c2_kb_b;
            c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_km1), 1, 4, 1, 0) - 1] = c2_m_y;
          }

          c2_sb_a = c2_b_k;
          c2_bb_c = c2_sb_a;
          c2_lb_b = c2_bb_c - 1;
          c2_cb_c = c2_lb_b << 2;
          c2_mb_b = c2_cb_c;
          c2_colk = c2_mb_b;
          c2_tb_a = c2_m;
          c2_db_c = c2_tb_a;
          c2_nb_b = c2_db_c - 1;
          c2_eb_c = c2_nb_b << 2;
          c2_ob_b = c2_eb_c;
          c2_colm = c2_ob_b;
          c2_c_eml_xrot(chartInstance, c2_V, c2_colk + 1, c2_colm + 1, c2_b_cs,
                        c2_b_sn);
        }
        break;

       case 2:
        c2_ub_a = c2_b_q - 1;
        c2_qm1 = c2_ub_a;
        c2_f = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_qm1), 1, 4, 1, 0) - 1];
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_qm1), 1, 4, 1, 0) - 1] = 0.0;
        c2_j_q = c2_b_q;
        c2_c_m = c2_m;
        c2_vb_a = c2_j_q;
        c2_pb_b = c2_c_m;
        c2_wb_a = c2_vb_a;
        c2_qb_b = c2_pb_b;
        if (c2_wb_a > c2_qb_b) {
          c2_n_overflow = FALSE;
        } else {
          c2_n_overflow = (c2_qb_b > 2147483646);
        }

        if (c2_n_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_n_overflow);
        }

        for (c2_c_k = c2_j_q; c2_c_k <= c2_c_m; c2_c_k++) {
          c2_b_k = c2_c_k;
          c2_t1 = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_c_t1 = c2_t1;
          c2_unusedU0 = c2_f;
          c2_b_eml_xrotg(chartInstance, &c2_c_t1, &c2_unusedU0, &c2_c_cs,
                         &c2_c_sn);
          c2_t1 = c2_c_t1;
          c2_b_cs = c2_c_cs;
          c2_b_sn = c2_c_sn;
          c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 4, 1, 0) - 1] = c2_t1;
          c2_xb_a = -c2_b_sn;
          c2_rb_b = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_f = c2_xb_a * c2_rb_b;
          c2_yb_a = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_sb_b = c2_b_cs;
          c2_n_y = c2_yb_a * c2_sb_b;
          c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 4, 1, 0) - 1] = c2_n_y;
          c2_ac_a = c2_b_k;
          c2_fb_c = c2_ac_a;
          c2_tb_b = c2_fb_c - 1;
          c2_gb_c = 6 * c2_tb_b;
          c2_ub_b = c2_gb_c;
          c2_colk = c2_ub_b;
          c2_bc_a = c2_qm1;
          c2_hb_c = c2_bc_a;
          c2_vb_b = c2_hb_c - 1;
          c2_ib_c = 6 * c2_vb_b;
          c2_wb_b = c2_ib_c;
          c2_colqm1 = c2_wb_b;
          c2_d_eml_xrot(chartInstance, c2_U, c2_colk + 1, c2_colqm1 + 1, c2_b_cs,
                        c2_b_sn);
        }
        break;

       case 3:
        c2_cc_a = c2_m - 1;
        c2_mm1 = c2_cc_a;
        c2_d4 = c2_abs(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_m), 1, 4, 1, 0) - 1]);
        c2_d5 = c2_abs(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_mm1), 1, 4, 1, 0) - 1]);
        c2_d6 = c2_abs(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_mm1), 1, 4, 1, 0) - 1]);
        c2_d7 = c2_abs(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1]);
        c2_d8 = c2_abs(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1]);
        c2_c_varargin_1[0] = c2_d4;
        c2_c_varargin_1[1] = c2_d5;
        c2_c_varargin_1[2] = c2_d6;
        c2_c_varargin_1[3] = c2_d7;
        c2_c_varargin_1[4] = c2_d8;
        c2_ixstart = 1;
        c2_mtmp = c2_c_varargin_1[0];
        c2_g_x = c2_mtmp;
        c2_xb_b = muDoubleScalarIsNaN(c2_g_x);
        if (c2_xb_b) {
          c2_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c2_ix < 6)) {
            c2_b_ix = c2_ix;
            c2_ixstart = c2_b_ix;
            c2_h_x = c2_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 5, 1, 0) - 1];
            c2_yb_b = muDoubleScalarIsNaN(c2_h_x);
            if (!c2_yb_b) {
              c2_mtmp = c2_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 5, 1, 0) - 1];
              exitg2 = TRUE;
            } else {
              c2_ix++;
            }
          }
        }

        if (c2_ixstart < 5) {
          c2_dc_a = c2_ixstart;
          c2_i207 = c2_dc_a;
          c2_o_overflow = FALSE;
          if (c2_o_overflow) {
            c2_check_forloop_overflow_error(chartInstance, c2_o_overflow);
          }

          for (c2_c_ix = c2_i207 + 1; c2_c_ix < 6; c2_c_ix++) {
            c2_b_ix = c2_c_ix;
            c2_ec_a = c2_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 5, 1, 0) - 1];
            c2_ac_b = c2_mtmp;
            c2_p = (c2_ec_a > c2_ac_b);
            if (c2_p) {
              c2_mtmp = c2_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 5, 1, 0) - 1];
            }
          }
        }

        c2_b_mtmp = c2_mtmp;
        c2_scale = c2_b_mtmp;
        c2_sm = c2_eml_div(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_m), 1, 4, 1, 0) - 1],
                           c2_scale);
        c2_smm1 = c2_eml_div(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_mm1), 1,
          4, 1, 0) - 1], c2_scale);
        c2_emm1 = c2_eml_div(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_mm1), 1,
          4, 1, 0) - 1], c2_scale);
        c2_sqds = c2_eml_div(chartInstance, c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1,
          4, 1, 0) - 1], c2_scale);
        c2_eqds = c2_eml_div(chartInstance, c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1,
          4, 1, 0) - 1], c2_scale);
        c2_fc_a = c2_smm1 + c2_sm;
        c2_bc_b = c2_smm1 - c2_sm;
        c2_o_y = c2_fc_a * c2_bc_b;
        c2_gc_a = c2_emm1;
        c2_cc_b = c2_emm1;
        c2_p_y = c2_gc_a * c2_cc_b;
        c2_dc_b = c2_eml_div(chartInstance, c2_o_y + c2_p_y, 2.0);
        c2_hc_a = c2_sm;
        c2_ec_b = c2_emm1;
        c2_jb_c = c2_hc_a * c2_ec_b;
        c2_ic_a = c2_jb_c;
        c2_fc_b = c2_jb_c;
        c2_jb_c = c2_ic_a * c2_fc_b;
        c2_shift = 0.0;
        guard1 = FALSE;
        if (c2_dc_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c2_jb_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c2_jc_a = c2_dc_b;
          c2_gc_b = c2_dc_b;
          c2_q_y = c2_jc_a * c2_gc_b;
          c2_shift = c2_q_y + c2_jb_c;
          c2_b_sqrt(chartInstance, &c2_shift);
          if (c2_dc_b < 0.0) {
            c2_shift = -c2_shift;
          }

          c2_shift = c2_eml_div(chartInstance, c2_jb_c, c2_dc_b + c2_shift);
        }

        c2_kc_a = c2_sqds + c2_sm;
        c2_hc_b = c2_sqds - c2_sm;
        c2_r_y = c2_kc_a * c2_hc_b;
        c2_f = c2_r_y + c2_shift;
        c2_lc_a = c2_sqds;
        c2_ic_b = c2_eqds;
        c2_g = c2_lc_a * c2_ic_b;
        c2_k_q = c2_b_q;
        c2_b_mm1 = c2_mm1;
        c2_mc_a = c2_k_q;
        c2_jc_b = c2_b_mm1;
        c2_nc_a = c2_mc_a;
        c2_kc_b = c2_jc_b;
        if (c2_nc_a > c2_kc_b) {
          c2_p_overflow = FALSE;
        } else {
          c2_p_overflow = (c2_kc_b > 2147483646);
        }

        if (c2_p_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_p_overflow);
        }

        for (c2_d_k = c2_k_q; c2_d_k <= c2_b_mm1; c2_d_k++) {
          c2_b_k = c2_d_k;
          c2_oc_a = c2_b_k;
          c2_km1 = c2_oc_a;
          c2_pc_a = c2_b_k + 1;
          c2_kp1 = c2_pc_a;
          c2_c_f = c2_f;
          c2_unusedU1 = c2_g;
          c2_b_eml_xrotg(chartInstance, &c2_c_f, &c2_unusedU1, &c2_d_cs,
                         &c2_d_sn);
          c2_f = c2_c_f;
          c2_b_cs = c2_d_cs;
          c2_b_sn = c2_d_sn;
          if (c2_b_k > c2_b_q) {
            c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c2_km1 - 1)), 1, 4, 1, 0) - 1] = c2_f;
          }

          c2_qc_a = c2_b_cs;
          c2_lc_b = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_s_y = c2_qc_a * c2_lc_b;
          c2_rc_a = c2_b_sn;
          c2_mc_b = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_t_y = c2_rc_a * c2_mc_b;
          c2_f = c2_s_y + c2_t_y;
          c2_sc_a = c2_b_cs;
          c2_nc_b = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_u_y = c2_sc_a * c2_nc_b;
          c2_tc_a = c2_b_sn;
          c2_oc_b = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_v_y = c2_tc_a * c2_oc_b;
          c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 4, 1, 0) - 1] = c2_u_y - c2_v_y;
          c2_uc_a = c2_b_sn;
          c2_pc_b = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_kp1), 1, 4, 1, 0) - 1];
          c2_g = c2_uc_a * c2_pc_b;
          c2_vc_a = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_kp1), 1, 4, 1, 0) - 1];
          c2_qc_b = c2_b_cs;
          c2_w_y = c2_vc_a * c2_qc_b;
          c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_kp1), 1, 4, 1, 0) - 1] = c2_w_y;
          c2_wc_a = c2_b_k;
          c2_kb_c = c2_wc_a;
          c2_rc_b = c2_kb_c - 1;
          c2_lb_c = c2_rc_b << 2;
          c2_sc_b = c2_lb_c;
          c2_colk = c2_sc_b;
          c2_tc_b = c2_b_k;
          c2_mb_c = c2_tc_b << 2;
          c2_uc_b = c2_mb_c;
          c2_colkp1 = c2_uc_b;
          c2_c_eml_xrot(chartInstance, c2_V, c2_colk + 1, c2_colkp1 + 1, c2_b_cs,
                        c2_b_sn);
          c2_d_f = c2_f;
          c2_unusedU2 = c2_g;
          c2_b_eml_xrotg(chartInstance, &c2_d_f, &c2_unusedU2, &c2_e_cs,
                         &c2_e_sn);
          c2_f = c2_d_f;
          c2_b_cs = c2_e_cs;
          c2_b_sn = c2_e_sn;
          c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 4, 1, 0) - 1] = c2_f;
          c2_xc_a = c2_b_cs;
          c2_vc_b = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_x_y = c2_xc_a * c2_vc_b;
          c2_yc_a = c2_b_sn;
          c2_wc_b = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_kp1), 1, 4, 1, 0) - 1];
          c2_y_y = c2_yc_a * c2_wc_b;
          c2_f = c2_x_y + c2_y_y;
          c2_ad_a = -c2_b_sn;
          c2_xc_b = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
          c2_ab_y = c2_ad_a * c2_xc_b;
          c2_bd_a = c2_b_cs;
          c2_yc_b = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_kp1), 1, 4, 1, 0) - 1];
          c2_bb_y = c2_bd_a * c2_yc_b;
          c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_kp1), 1, 4, 1, 0) - 1] = c2_ab_y + c2_bb_y;
          c2_cd_a = c2_b_sn;
          c2_ad_b = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_kp1), 1, 4, 1, 0) - 1];
          c2_g = c2_cd_a * c2_ad_b;
          c2_dd_a = c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_kp1), 1, 4, 1, 0) - 1];
          c2_bd_b = c2_b_cs;
          c2_cb_y = c2_dd_a * c2_bd_b;
          c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_kp1), 1, 4, 1, 0) - 1] = c2_cb_y;
          if (c2_b_k < 6) {
            c2_ed_a = c2_b_k;
            c2_nb_c = c2_ed_a;
            c2_cd_b = c2_nb_c - 1;
            c2_ob_c = 6 * c2_cd_b;
            c2_dd_b = c2_ob_c;
            c2_colk = c2_dd_b;
            c2_ed_b = c2_b_k;
            c2_pb_c = 6 * c2_ed_b;
            c2_fd_b = c2_pb_c;
            c2_colkp1 = c2_fd_b;
            c2_d_eml_xrot(chartInstance, c2_U, c2_colk + 1, c2_colkp1 + 1,
                          c2_b_cs, c2_b_sn);
          }
        }

        c2_fd_a = c2_m;
        c2_qb_c = c2_fd_a;
        c2_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c2_qb_c - 1)), 1, 4, 1, 0) - 1] = c2_f;
        c2_iter++;
        break;

       default:
        if (c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_b_q), 1, 4, 1, 0) - 1] < 0.0) {
          c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_q), 1, 4, 1, 0) - 1] =
            -c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_q), 1, 4, 1, 0) - 1];
          c2_gd_a = c2_b_q;
          c2_rb_c = c2_gd_a;
          c2_gd_b = c2_rb_c - 1;
          c2_sb_c = c2_gd_b << 2;
          c2_hd_b = c2_sb_c;
          c2_colq = c2_hd_b;
          c2_d_eml_scalar_eg(chartInstance);
          c2_d9 = -1.0;
          c2_h_eml_xscal(chartInstance, c2_d9, c2_V, c2_colq + 1);
        }

        c2_hd_a = c2_b_q + 1;
        c2_qp1 = c2_hd_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c2_b_q < 4)) {
          if (c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_b_q), 1, 4, 1, 0) - 1] <
              c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c2_qp1), 1, 4, 1, 0) - 1]) {
            c2_rt = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c2_b_q), 1, 4, 1, 0) - 1];
            c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_b_q), 1, 4, 1, 0) - 1] =
              c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c2_qp1), 1, 4, 1, 0) - 1];
            c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c2_qp1), 1, 4, 1, 0) - 1] = c2_rt;
            if (c2_b_q < 4) {
              c2_jd_a = c2_b_q;
              c2_tb_c = c2_jd_a;
              c2_id_b = c2_tb_c - 1;
              c2_ub_c = c2_id_b << 2;
              c2_jd_b = c2_ub_c;
              c2_colq = c2_jd_b;
              c2_kd_b = c2_b_q;
              c2_vb_c = c2_kd_b << 2;
              c2_ld_b = c2_vb_c;
              c2_colqp1 = c2_ld_b;
              c2_c_eml_xswap(chartInstance, c2_V, c2_colq + 1, c2_colqp1 + 1);
            }

            if (c2_b_q < 6) {
              c2_kd_a = c2_b_q;
              c2_wb_c = c2_kd_a;
              c2_md_b = c2_wb_c - 1;
              c2_xb_c = 6 * c2_md_b;
              c2_nd_b = c2_xb_c;
              c2_colq = c2_nd_b;
              c2_od_b = c2_b_q;
              c2_yb_c = 6 * c2_od_b;
              c2_pd_b = c2_yb_c;
              c2_colqp1 = c2_pd_b;
              c2_d_eml_xswap(chartInstance, c2_U, c2_colq + 1, c2_colqp1 + 1);
            }

            c2_b_q = c2_qp1;
            c2_ld_a = c2_b_q + 1;
            c2_qp1 = c2_ld_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c2_iter = 0.0;
        c2_id_a = c2_m - 1;
        c2_m = c2_id_a;
        break;
      }
    }
  }

  for (c2_e_k = 1; c2_e_k < 5; c2_e_k++) {
    c2_b_k = c2_e_k;
    c2_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_k), 1, 4, 1, 0) - 1] = c2_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
  }
}

static real_T c2_eml_xnrm2(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[24], int32_T c2_ix0)
{
  real_T c2_y;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_scale;
  int32_T c2_kstart;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_c_a;
  int32_T c2_b;
  int32_T c2_kend;
  int32_T c2_b_kstart;
  int32_T c2_b_kend;
  int32_T c2_d_a;
  int32_T c2_b_b;
  int32_T c2_e_a;
  int32_T c2_c_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_absxk;
  real_T c2_t;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_y = 0.0;
  if (c2_c_n < 1) {
  } else if (c2_c_n == 1) {
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_c_ix0), 1, 24, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_y = muDoubleScalarAbs(c2_c_x);
  } else {
    c2_realmin(chartInstance);
    c2_scale = 2.2250738585072014E-308;
    c2_kstart = c2_c_ix0;
    c2_a = c2_c_n;
    c2_c = c2_a;
    c2_b_a = c2_c - 1;
    c2_b_c = c2_b_a;
    c2_c_a = c2_kstart;
    c2_b = c2_b_c;
    c2_kend = c2_c_a + c2_b;
    c2_b_kstart = c2_kstart;
    c2_b_kend = c2_kend;
    c2_d_a = c2_b_kstart;
    c2_b_b = c2_b_kend;
    c2_e_a = c2_d_a;
    c2_c_b = c2_b_b;
    if (c2_e_a > c2_c_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_c_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = c2_b_kstart; c2_k <= c2_b_kend; c2_k++) {
      c2_b_k = c2_k;
      c2_d_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_b_k), 1, 24, 1, 0) - 1];
      c2_e_x = c2_d_x;
      c2_absxk = muDoubleScalarAbs(c2_e_x);
      if (c2_absxk > c2_scale) {
        c2_t = c2_scale / c2_absxk;
        c2_y = 1.0 + c2_y * c2_t * c2_t;
        c2_scale = c2_absxk;
      } else {
        c2_t = c2_absxk / c2_scale;
        c2_y += c2_t * c2_t;
      }
    }

    c2_y = c2_scale * muDoubleScalarSqrt(c2_y);
  }

  return c2_y;
}

static void c2_realmin(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
}

static void c2_check_forloop_overflow_error(SFc2_CONTROL_POSICIONInstanceStruct *
  chartInstance, boolean_T c2_overflow)
{
  int32_T c2_i208;
  static char_T c2_cv4[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i209;
  static char_T c2_cv5[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c2_b_u[23];
  const mxArray *c2_b_y = NULL;
  if (!c2_overflow) {
  } else {
    for (c2_i208 = 0; c2_i208 < 34; c2_i208++) {
      c2_u[c2_i208] = c2_cv4[c2_i208];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i209 = 0; c2_i209 < 23; c2_i209++) {
      c2_b_u[c2_i209] = c2_cv5[c2_i209];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0, real_T c2_b_x[24])
{
  int32_T c2_i210;
  for (c2_i210 = 0; c2_i210 < 24; c2_i210++) {
    c2_b_x[c2_i210] = c2_x[c2_i210];
  }

  c2_e_eml_xscal(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0);
}

static real_T c2_eml_xdotc(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[24], int32_T c2_ix0, real_T c2_y[24], int32_T c2_iy0)
{
  real_T c2_d;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_e_n;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_f_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_a;
  int32_T c2_b_a;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_d_n = c2_c_n;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_e_n = c2_d_n;
  c2_e_ix0 = c2_d_ix0;
  c2_e_iy0 = c2_d_iy0;
  c2_d = 0.0;
  if (c2_e_n < 1) {
  } else {
    c2_ix = c2_e_ix0;
    c2_iy = c2_e_iy0;
    c2_f_n = c2_e_n;
    c2_b = c2_f_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 1; c2_k <= c2_f_n; c2_k++) {
      c2_d += c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_ix), 1, 24, 1, 0) - 1] * c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_iy), 1, 24, 1, 0) - 1];
      c2_a = c2_ix + 1;
      c2_ix = c2_a;
      c2_b_a = c2_iy + 1;
      c2_iy = c2_b_a;
    }
  }

  return c2_d;
}

static void c2_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[24], int32_T c2_iy0,
  real_T c2_b_y[24])
{
  int32_T c2_i211;
  for (c2_i211 = 0; c2_i211 < 24; c2_i211++) {
    c2_b_y[c2_i211] = c2_y[c2_i211];
  }

  c2_f_eml_xaxpy(chartInstance, c2_n, c2_a, c2_ix0, c2_b_y, c2_iy0);
}

static real_T c2_b_eml_xnrm2(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[4], int32_T c2_ix0)
{
  real_T c2_y;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_scale;
  int32_T c2_kstart;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b_a;
  int32_T c2_b_c;
  int32_T c2_c_a;
  int32_T c2_b;
  int32_T c2_kend;
  int32_T c2_b_kstart;
  int32_T c2_b_kend;
  int32_T c2_d_a;
  int32_T c2_b_b;
  int32_T c2_e_a;
  int32_T c2_c_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_absxk;
  real_T c2_t;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_y = 0.0;
  if (c2_c_n < 1) {
  } else if (c2_c_n == 1) {
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_c_ix0), 1, 4, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_y = muDoubleScalarAbs(c2_c_x);
  } else {
    c2_realmin(chartInstance);
    c2_scale = 2.2250738585072014E-308;
    c2_kstart = c2_c_ix0;
    c2_a = c2_c_n;
    c2_c = c2_a;
    c2_b_a = c2_c - 1;
    c2_b_c = c2_b_a;
    c2_c_a = c2_kstart;
    c2_b = c2_b_c;
    c2_kend = c2_c_a + c2_b;
    c2_b_kstart = c2_kstart;
    c2_b_kend = c2_kend;
    c2_d_a = c2_b_kstart;
    c2_b_b = c2_b_kend;
    c2_e_a = c2_d_a;
    c2_c_b = c2_b_b;
    if (c2_e_a > c2_c_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_c_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = c2_b_kstart; c2_k <= c2_b_kend; c2_k++) {
      c2_b_k = c2_k;
      c2_d_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
      c2_e_x = c2_d_x;
      c2_absxk = muDoubleScalarAbs(c2_e_x);
      if (c2_absxk > c2_scale) {
        c2_t = c2_scale / c2_absxk;
        c2_y = 1.0 + c2_y * c2_t * c2_t;
        c2_scale = c2_absxk;
      } else {
        c2_t = c2_absxk / c2_scale;
        c2_y += c2_t * c2_t;
      }
    }

    c2_y = c2_scale * muDoubleScalarSqrt(c2_y);
  }

  return c2_y;
}

static void c2_b_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0, real_T c2_b_x[4])
{
  int32_T c2_i212;
  for (c2_i212 = 0; c2_i212 < 4; c2_i212++) {
    c2_b_x[c2_i212] = c2_x[c2_i212];
  }

  c2_f_eml_xscal(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0);
}

static void c2_b_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0, real_T c2_y[6],
  int32_T c2_iy0, real_T c2_b_y[6])
{
  int32_T c2_i213;
  int32_T c2_i214;
  real_T c2_b_x[24];
  for (c2_i213 = 0; c2_i213 < 6; c2_i213++) {
    c2_b_y[c2_i213] = c2_y[c2_i213];
  }

  for (c2_i214 = 0; c2_i214 < 24; c2_i214++) {
    c2_b_x[c2_i214] = c2_x[c2_i214];
  }

  c2_g_eml_xaxpy(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0, c2_b_y, c2_iy0);
}

static void c2_c_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[6], int32_T c2_ix0, real_T c2_y[24],
  int32_T c2_iy0, real_T c2_b_y[24])
{
  int32_T c2_i215;
  int32_T c2_i216;
  real_T c2_b_x[6];
  for (c2_i215 = 0; c2_i215 < 24; c2_i215++) {
    c2_b_y[c2_i215] = c2_y[c2_i215];
  }

  for (c2_i216 = 0; c2_i216 < 6; c2_i216++) {
    c2_b_x[c2_i216] = c2_x[c2_i216];
  }

  c2_h_eml_xaxpy(chartInstance, c2_n, c2_a, c2_b_x, c2_ix0, c2_b_y, c2_iy0);
}

static real_T c2_b_eml_xdotc(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[36], int32_T c2_ix0, real_T c2_y[36], int32_T c2_iy0)
{
  real_T c2_d;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_e_n;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_f_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_a;
  int32_T c2_b_a;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_d_n = c2_c_n;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_e_n = c2_d_n;
  c2_e_ix0 = c2_d_ix0;
  c2_e_iy0 = c2_d_iy0;
  c2_d = 0.0;
  if (c2_e_n < 1) {
  } else {
    c2_ix = c2_e_ix0;
    c2_iy = c2_e_iy0;
    c2_f_n = c2_e_n;
    c2_b = c2_f_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 1; c2_k <= c2_f_n; c2_k++) {
      c2_d += c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_ix), 1, 36, 1, 0) - 1] * c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_iy), 1, 36, 1, 0) - 1];
      c2_a = c2_ix + 1;
      c2_ix = c2_a;
      c2_b_a = c2_iy + 1;
      c2_iy = c2_b_a;
    }
  }

  return c2_d;
}

static void c2_d_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[36], int32_T c2_iy0,
  real_T c2_b_y[36])
{
  int32_T c2_i217;
  for (c2_i217 = 0; c2_i217 < 36; c2_i217++) {
    c2_b_y[c2_i217] = c2_y[c2_i217];
  }

  c2_i_eml_xaxpy(chartInstance, c2_n, c2_a, c2_ix0, c2_b_y, c2_iy0);
}

static real_T c2_c_eml_xdotc(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_x[16], int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0)
{
  real_T c2_d;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_e_n;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_f_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_a;
  int32_T c2_b_a;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_d_n = c2_c_n;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_e_n = c2_d_n;
  c2_e_ix0 = c2_d_ix0;
  c2_e_iy0 = c2_d_iy0;
  c2_d = 0.0;
  if (c2_e_n < 1) {
  } else {
    c2_ix = c2_e_ix0;
    c2_iy = c2_e_iy0;
    c2_f_n = c2_e_n;
    c2_b = c2_f_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 1; c2_k <= c2_f_n; c2_k++) {
      c2_d += c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_ix), 1, 16, 1, 0) - 1] * c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_iy), 1, 16, 1, 0) - 1];
      c2_a = c2_ix + 1;
      c2_ix = c2_a;
      c2_b_a = c2_iy + 1;
      c2_iy = c2_b_a;
    }
  }

  return c2_d;
}

static void c2_e_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0,
  real_T c2_b_y[16])
{
  int32_T c2_i218;
  for (c2_i218 = 0; c2_i218 < 16; c2_i218++) {
    c2_b_y[c2_i218] = c2_y[c2_i218];
  }

  c2_j_eml_xaxpy(chartInstance, c2_n, c2_a, c2_ix0, c2_b_y, c2_iy0);
}

static void c2_d_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_c_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[36], int32_T c2_ix0, real_T c2_b_x[36])
{
  int32_T c2_i219;
  for (c2_i219 = 0; c2_i219 < 36; c2_i219++) {
    c2_b_x[c2_i219] = c2_x[c2_i219];
  }

  c2_g_eml_xscal(chartInstance, c2_a, c2_b_x, c2_ix0);
}

static void c2_d_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[16], int32_T c2_ix0, real_T c2_b_x[16])
{
  int32_T c2_i220;
  for (c2_i220 = 0; c2_i220 < 16; c2_i220++) {
    c2_b_x[c2_i220] = c2_x[c2_i220];
  }

  c2_h_eml_xscal(chartInstance, c2_a, c2_b_x, c2_ix0);
}

static void c2_c_eml_error(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance)
{
  int32_T c2_i221;
  static char_T c2_cv6[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i221 = 0; c2_i221 < 30; c2_i221++) {
    c2_u[c2_i221] = c2_cv6[c2_i221];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_eml_xrotg(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_b, real_T *c2_b_a, real_T *c2_b_b, real_T *c2_c, real_T
  *c2_s)
{
  *c2_b_a = c2_a;
  *c2_b_b = c2_b;
  c2_b_eml_xrotg(chartInstance, c2_b_a, c2_b_b, c2_c, c2_s);
}

static void c2_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s,
  real_T c2_b_x[16])
{
  int32_T c2_i222;
  for (c2_i222 = 0; c2_i222 < 16; c2_i222++) {
    c2_b_x[c2_i222] = c2_x[c2_i222];
  }

  c2_c_eml_xrot(chartInstance, c2_b_x, c2_ix0, c2_iy0, c2_c, c2_s);
}

static void c2_b_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s,
  real_T c2_b_x[36])
{
  int32_T c2_i223;
  for (c2_i223 = 0; c2_i223 < 36; c2_i223++) {
    c2_b_x[c2_i223] = c2_x[c2_i223];
  }

  c2_d_eml_xrot(chartInstance, c2_b_x, c2_ix0, c2_iy0, c2_c, c2_s);
}

static void c2_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0, real_T c2_b_x[16])
{
  int32_T c2_i224;
  for (c2_i224 = 0; c2_i224 < 16; c2_i224++) {
    c2_b_x[c2_i224] = c2_x[c2_i224];
  }

  c2_c_eml_xswap(chartInstance, c2_b_x, c2_ix0, c2_iy0);
}

static void c2_below_threshold(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_b_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0, real_T c2_b_x[36])
{
  int32_T c2_i225;
  for (c2_i225 = 0; c2_i225 < 36; c2_i225++) {
    c2_b_x[c2_i225] = c2_x[c2_i225];
  }

  c2_d_eml_xswap(chartInstance, c2_b_x, c2_ix0, c2_iy0);
}

static void c2_e_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_mldivide(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24], real_T c2_Y[24])
{
  int32_T c2_i226;
  real_T c2_b_A[16];
  int32_T c2_info;
  int32_T c2_ipiv[4];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_i227;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_ip;
  int32_T c2_j;
  int32_T c2_b_j;
  real_T c2_temp;
  int32_T c2_i228;
  real_T c2_c_A[16];
  int32_T c2_i229;
  real_T c2_d_A[16];
  for (c2_i226 = 0; c2_i226 < 16; c2_i226++) {
    c2_b_A[c2_i226] = c2_A[c2_i226];
  }

  c2_b_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, &c2_info);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if (c2_d_info > 0) {
    c2_eml_warning(chartInstance);
  }

  for (c2_i227 = 0; c2_i227 < 24; c2_i227++) {
    c2_Y[c2_i227] = c2_B[c2_i227];
  }

  for (c2_i = 1; c2_i < 5; c2_i++) {
    c2_b_i = c2_i;
    if (c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 4, 1, 0) - 1] != c2_b_i) {
      c2_ip = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) - 1];
      for (c2_j = 1; c2_j < 7; c2_j++) {
        c2_b_j = c2_j;
        c2_temp = c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 4, 1, 0) +
                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 6, 2, 0) - 1) << 2)) - 1];
        c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 6, 2, 0) -
                1) << 2)) - 1] = c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ip), 1, 4, 1, 0) +
          ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 6, 2, 0) - 1) << 2)) - 1];
        c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_ip), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 6, 2, 0) -
                1) << 2)) - 1] = c2_temp;
      }
    }
  }

  for (c2_i228 = 0; c2_i228 < 16; c2_i228++) {
    c2_c_A[c2_i228] = c2_b_A[c2_i228];
  }

  c2_c_eml_xtrsm(chartInstance, c2_c_A, c2_Y);
  for (c2_i229 = 0; c2_i229 < 16; c2_i229++) {
    c2_d_A[c2_i229] = c2_b_A[c2_i229];
  }

  c2_d_eml_xtrsm(chartInstance, c2_d_A, c2_Y);
}

static void c2_eml_matlab_zgetrf(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, real_T c2_A[16], real_T c2_b_A[16], int32_T c2_ipiv[4],
  int32_T *c2_info)
{
  int32_T c2_i230;
  for (c2_i230 = 0; c2_i230 < 16; c2_i230++) {
    c2_b_A[c2_i230] = c2_A[c2_i230];
  }

  c2_b_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, c2_info);
}

static void c2_eml_xger(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[16], int32_T c2_ia0, real_T c2_b_A[16])
{
  int32_T c2_i231;
  for (c2_i231 = 0; c2_i231 < 16; c2_i231++) {
    c2_b_A[c2_i231] = c2_A[c2_i231];
  }

  c2_b_eml_xger(chartInstance, c2_m, c2_n, c2_alpha1, c2_ix0, c2_iy0, c2_b_A,
                c2_ia0);
}

static void c2_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24], real_T c2_b_B[24])
{
  int32_T c2_i232;
  int32_T c2_i233;
  real_T c2_b_A[16];
  for (c2_i232 = 0; c2_i232 < 24; c2_i232++) {
    c2_b_B[c2_i232] = c2_B[c2_i232];
  }

  for (c2_i233 = 0; c2_i233 < 16; c2_i233++) {
    c2_b_A[c2_i233] = c2_A[c2_i233];
  }

  c2_c_eml_xtrsm(chartInstance, c2_b_A, c2_b_B);
}

static void c2_b_below_threshold(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_f_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_b_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24], real_T c2_b_B[24])
{
  int32_T c2_i234;
  int32_T c2_i235;
  real_T c2_b_A[16];
  for (c2_i234 = 0; c2_i234 < 24; c2_i234++) {
    c2_b_B[c2_i234] = c2_B[c2_i234];
  }

  for (c2_i235 = 0; c2_i235 < 16; c2_i235++) {
    c2_b_A[c2_i235] = c2_A[c2_i235];
  }

  c2_d_eml_xtrsm(chartInstance, c2_b_A, c2_b_B);
}

static void c2_g_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_h_eml_scalar_eg(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance)
{
}

static void c2_l_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_y[14])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_m_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_y[14])
{
  char_T c2_cv7[14];
  int32_T c2_i236;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_cv7, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c2_i236 = 0; c2_i236 < 14; c2_i236++) {
    c2_y[c2_i236] = c2_cv7[c2_i236];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_n_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i237;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i237, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i237;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_o_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CONTROL_POSICION, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_CONTROL_POSICION), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_CONTROL_POSICION);
  return c2_y;
}

static uint8_T c2_p_emlrt_marshallIn(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance, real_T
                      *c2_x)
{
  if (*c2_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void c2_e_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_d_ix0;
  int32_T c2_d_a;
  int32_T c2_c;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_e_a;
  int32_T c2_b_b;
  int32_T c2_i238;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_g_a;
  int32_T c2_d_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_d_ix0 = c2_c_ix0;
  c2_d_a = c2_c_n;
  c2_c = c2_d_a;
  c2_b = c2_c - 1;
  c2_b_c = c2_b;
  c2_e_a = c2_c_ix0;
  c2_b_b = c2_b_c;
  c2_i238 = c2_e_a + c2_b_b;
  c2_f_a = c2_d_ix0;
  c2_c_b = c2_i238;
  c2_g_a = c2_f_a;
  c2_d_b = c2_c_b;
  if (c2_g_a > c2_d_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_d_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, c2_overflow);
  }

  for (c2_k = c2_d_ix0; c2_k <= c2_i238; c2_k++) {
    c2_b_k = c2_k;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_k), 1, 24, 1, 0) - 1] = c2_c_a * c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 24, 1, 0) - 1];
  }
}

static void c2_f_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[24], int32_T c2_iy0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_a;
  int32_T c2_ix;
  int32_T c2_e_a;
  int32_T c2_iy;
  int32_T c2_f_a;
  int32_T c2_i239;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_g_a;
  int32_T c2_c;
  int32_T c2_h_a;
  int32_T c2_b_c;
  int32_T c2_i_a;
  int32_T c2_c_c;
  int32_T c2_j_a;
  int32_T c2_k_a;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  if (c2_c_n < 1) {
  } else if (c2_c_a == 0.0) {
  } else {
    c2_d_a = c2_c_ix0 - 1;
    c2_ix = c2_d_a;
    c2_e_a = c2_c_iy0 - 1;
    c2_iy = c2_e_a;
    c2_f_a = c2_c_n - 1;
    c2_i239 = c2_f_a;
    c2_b = c2_i239;
    c2_b_b = c2_b;
    if (0 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 0; c2_k <= c2_i239; c2_k++) {
      c2_g_a = c2_iy;
      c2_c = c2_g_a;
      c2_h_a = c2_iy;
      c2_b_c = c2_h_a;
      c2_i_a = c2_ix;
      c2_c_c = c2_i_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 24, 1, 0) - 1] =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_c + 1)), 1, 24, 1, 0) - 1] + c2_c_a *
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c_c + 1)), 1, 24, 1, 0) - 1];
      c2_j_a = c2_ix + 1;
      c2_ix = c2_j_a;
      c2_k_a = c2_iy + 1;
      c2_iy = c2_k_a;
    }
  }
}

static void c2_f_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[4], int32_T c2_ix0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_d_ix0;
  int32_T c2_d_a;
  int32_T c2_c;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_e_a;
  int32_T c2_b_b;
  int32_T c2_i240;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_g_a;
  int32_T c2_d_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_d_ix0 = c2_c_ix0;
  c2_d_a = c2_c_n;
  c2_c = c2_d_a;
  c2_b = c2_c - 1;
  c2_b_c = c2_b;
  c2_e_a = c2_c_ix0;
  c2_b_b = c2_b_c;
  c2_i240 = c2_e_a + c2_b_b;
  c2_f_a = c2_d_ix0;
  c2_c_b = c2_i240;
  c2_g_a = c2_f_a;
  c2_d_b = c2_c_b;
  if (c2_g_a > c2_d_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_d_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, c2_overflow);
  }

  for (c2_k = c2_d_ix0; c2_k <= c2_i240; c2_k++) {
    c2_b_k = c2_k;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_k), 1, 4, 1, 0) - 1] = c2_c_a * c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 4, 1, 0) - 1];
  }
}

static void c2_g_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[24], int32_T c2_ix0, real_T c2_y[6],
  int32_T c2_iy0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_a;
  int32_T c2_ix;
  int32_T c2_e_a;
  int32_T c2_iy;
  int32_T c2_f_a;
  int32_T c2_i241;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_g_a;
  int32_T c2_c;
  int32_T c2_h_a;
  int32_T c2_b_c;
  int32_T c2_i_a;
  int32_T c2_c_c;
  int32_T c2_j_a;
  int32_T c2_k_a;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  if (c2_c_n < 1) {
  } else if (c2_c_a == 0.0) {
  } else {
    c2_d_a = c2_c_ix0 - 1;
    c2_ix = c2_d_a;
    c2_e_a = c2_c_iy0 - 1;
    c2_iy = c2_e_a;
    c2_f_a = c2_c_n - 1;
    c2_i241 = c2_f_a;
    c2_b = c2_i241;
    c2_b_b = c2_b;
    if (0 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 0; c2_k <= c2_i241; c2_k++) {
      c2_g_a = c2_iy;
      c2_c = c2_g_a;
      c2_h_a = c2_iy;
      c2_b_c = c2_h_a;
      c2_i_a = c2_ix;
      c2_c_c = c2_i_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 6, 1, 0) - 1] = c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c2_b_c + 1)), 1, 6, 1, 0)
        - 1] + c2_c_a * c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c2_c_c + 1)), 1, 24, 1, 0) - 1];
      c2_j_a = c2_ix + 1;
      c2_ix = c2_j_a;
      c2_k_a = c2_iy + 1;
      c2_iy = c2_k_a;
    }
  }
}

static void c2_h_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, real_T c2_x[6], int32_T c2_ix0, real_T c2_y[24],
  int32_T c2_iy0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_a;
  int32_T c2_ix;
  int32_T c2_e_a;
  int32_T c2_iy;
  int32_T c2_f_a;
  int32_T c2_i242;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_g_a;
  int32_T c2_c;
  int32_T c2_h_a;
  int32_T c2_b_c;
  int32_T c2_i_a;
  int32_T c2_c_c;
  int32_T c2_j_a;
  int32_T c2_k_a;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  if (c2_c_n < 1) {
  } else if (c2_c_a == 0.0) {
  } else {
    c2_d_a = c2_c_ix0 - 1;
    c2_ix = c2_d_a;
    c2_e_a = c2_c_iy0 - 1;
    c2_iy = c2_e_a;
    c2_f_a = c2_c_n - 1;
    c2_i242 = c2_f_a;
    c2_b = c2_i242;
    c2_b_b = c2_b;
    if (0 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 0; c2_k <= c2_i242; c2_k++) {
      c2_g_a = c2_iy;
      c2_c = c2_g_a;
      c2_h_a = c2_iy;
      c2_b_c = c2_h_a;
      c2_i_a = c2_ix;
      c2_c_c = c2_i_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 24, 1, 0) - 1] =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_c + 1)), 1, 24, 1, 0) - 1] + c2_c_a *
        c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c_c + 1)), 1, 6, 1, 0) - 1];
      c2_j_a = c2_ix + 1;
      c2_ix = c2_j_a;
      c2_k_a = c2_iy + 1;
      c2_iy = c2_k_a;
    }
  }
}

static void c2_i_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[36], int32_T c2_iy0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_a;
  int32_T c2_ix;
  int32_T c2_e_a;
  int32_T c2_iy;
  int32_T c2_f_a;
  int32_T c2_i243;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_g_a;
  int32_T c2_c;
  int32_T c2_h_a;
  int32_T c2_b_c;
  int32_T c2_i_a;
  int32_T c2_c_c;
  int32_T c2_j_a;
  int32_T c2_k_a;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  if (c2_c_n < 1) {
  } else if (c2_c_a == 0.0) {
  } else {
    c2_d_a = c2_c_ix0 - 1;
    c2_ix = c2_d_a;
    c2_e_a = c2_c_iy0 - 1;
    c2_iy = c2_e_a;
    c2_f_a = c2_c_n - 1;
    c2_i243 = c2_f_a;
    c2_b = c2_i243;
    c2_b_b = c2_b;
    if (0 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 0; c2_k <= c2_i243; c2_k++) {
      c2_g_a = c2_iy;
      c2_c = c2_g_a;
      c2_h_a = c2_iy;
      c2_b_c = c2_h_a;
      c2_i_a = c2_ix;
      c2_c_c = c2_i_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 36, 1, 0) - 1] =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_c + 1)), 1, 36, 1, 0) - 1] + c2_c_a *
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c_c + 1)), 1, 36, 1, 0) - 1];
      c2_j_a = c2_ix + 1;
      c2_ix = c2_j_a;
      c2_k_a = c2_iy + 1;
      c2_iy = c2_k_a;
    }
  }
}

static void c2_j_eml_xaxpy(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_n, real_T c2_a, int32_T c2_ix0, real_T c2_y[16], int32_T c2_iy0)
{
  int32_T c2_b_n;
  real_T c2_b_a;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_n;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_d_a;
  int32_T c2_ix;
  int32_T c2_e_a;
  int32_T c2_iy;
  int32_T c2_f_a;
  int32_T c2_i244;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_g_a;
  int32_T c2_c;
  int32_T c2_h_a;
  int32_T c2_b_c;
  int32_T c2_i_a;
  int32_T c2_c_c;
  int32_T c2_j_a;
  int32_T c2_k_a;
  c2_b_n = c2_n;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_n = c2_b_n;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  if (c2_c_n < 1) {
  } else if (c2_c_a == 0.0) {
  } else {
    c2_d_a = c2_c_ix0 - 1;
    c2_ix = c2_d_a;
    c2_e_a = c2_c_iy0 - 1;
    c2_iy = c2_e_a;
    c2_f_a = c2_c_n - 1;
    c2_i244 = c2_f_a;
    c2_b = c2_i244;
    c2_b_b = c2_b;
    if (0 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 0; c2_k <= c2_i244; c2_k++) {
      c2_g_a = c2_iy;
      c2_c = c2_g_a;
      c2_h_a = c2_iy;
      c2_b_c = c2_h_a;
      c2_i_a = c2_ix;
      c2_c_c = c2_i_a;
      c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c + 1)), 1, 16, 1, 0) - 1] =
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_c + 1)), 1, 16, 1, 0) - 1] + c2_c_a *
        c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_c_c + 1)), 1, 16, 1, 0) - 1];
      c2_j_a = c2_ix + 1;
      c2_ix = c2_j_a;
      c2_k_a = c2_iy + 1;
      c2_iy = c2_k_a;
    }
  }
}

static void c2_g_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[36], int32_T c2_ix0)
{
  real_T c2_b_a;
  int32_T c2_b_ix0;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_d_ix0;
  int32_T c2_d_a;
  int32_T c2_i245;
  int32_T c2_e_a;
  int32_T c2_b;
  int32_T c2_f_a;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_d_ix0 = c2_c_ix0;
  c2_d_a = c2_c_ix0 + 5;
  c2_i245 = c2_d_a;
  c2_e_a = c2_d_ix0;
  c2_b = c2_i245;
  c2_f_a = c2_e_a;
  c2_b_b = c2_b;
  if (c2_f_a > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, c2_overflow);
  }

  for (c2_k = c2_d_ix0; c2_k <= c2_i245; c2_k++) {
    c2_b_k = c2_k;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_k), 1, 36, 1, 0) - 1] = c2_c_a * c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 36, 1, 0) - 1];
  }
}

static void c2_h_eml_xscal(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_a, real_T c2_x[16], int32_T c2_ix0)
{
  real_T c2_b_a;
  int32_T c2_b_ix0;
  real_T c2_c_a;
  int32_T c2_c_ix0;
  int32_T c2_d_ix0;
  int32_T c2_d_a;
  int32_T c2_i246;
  int32_T c2_e_a;
  int32_T c2_b;
  int32_T c2_f_a;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_b_a = c2_a;
  c2_b_ix0 = c2_ix0;
  c2_c_a = c2_b_a;
  c2_c_ix0 = c2_b_ix0;
  c2_d_ix0 = c2_c_ix0;
  c2_d_a = c2_c_ix0 + 3;
  c2_i246 = c2_d_a;
  c2_e_a = c2_d_ix0;
  c2_b = c2_i246;
  c2_f_a = c2_e_a;
  c2_b_b = c2_b;
  if (c2_f_a > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, c2_overflow);
  }

  for (c2_k = c2_d_ix0; c2_k <= c2_i246; c2_k++) {
    c2_b_k = c2_k;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_k), 1, 16, 1, 0) - 1] = c2_c_a * c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) - 1];
  }
}

static void c2_b_eml_xrotg(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T *c2_a, real_T *c2_b, real_T *c2_c, real_T *c2_s)
{
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c_b;
  real_T c2_c_a;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_e_b;
  real_T c2_e_a;
  real_T c2_b_c;
  real_T c2_b_s;
  double * c2_a_t;
  double * c2_b_t;
  double * c2_c_t;
  double * c2_s_t;
  real_T c2_c_c;
  real_T c2_c_s;
  c2_b_a = *c2_a;
  c2_b_b = *c2_b;
  c2_c_b = c2_b_b;
  c2_c_a = c2_b_a;
  c2_d_a = c2_c_a;
  c2_d_b = c2_c_b;
  c2_e_b = c2_d_b;
  c2_e_a = c2_d_a;
  c2_b_c = 0.0;
  c2_b_s = 0.0;
  c2_a_t = (double *)(&c2_e_a);
  c2_b_t = (double *)(&c2_e_b);
  c2_c_t = (double *)(&c2_b_c);
  c2_s_t = (double *)(&c2_b_s);
  drotg(c2_a_t, c2_b_t, c2_c_t, c2_s_t);
  c2_c_a = c2_e_a;
  c2_c_b = c2_e_b;
  c2_c_c = c2_b_c;
  c2_c_s = c2_b_s;
  *c2_a = c2_c_a;
  *c2_b = c2_c_b;
  *c2_c = c2_c_c;
  *c2_s = c2_c_s;
}

static void c2_c_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s)
{
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  real_T c2_b_c;
  real_T c2_b_s;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  real_T c2_c_c;
  real_T c2_c_s;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_temp;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_d_y;
  int32_T c2_e_a;
  int32_T c2_f_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_c = c2_c;
  c2_b_s = c2_s;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_c_c = c2_b_c;
  c2_c_s = c2_b_s;
  c2_ix = c2_c_ix0;
  c2_iy = c2_c_iy0;
  for (c2_k = 1; c2_k < 5; c2_k++) {
    c2_a = c2_c_c;
    c2_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_ix), 1, 16, 1, 0) - 1];
    c2_y = c2_a * c2_b;
    c2_b_a = c2_c_s;
    c2_b_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 16, 1, 0) - 1];
    c2_b_y = c2_b_a * c2_b_b;
    c2_temp = c2_y + c2_b_y;
    c2_c_a = c2_c_c;
    c2_c_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 16, 1, 0) - 1];
    c2_c_y = c2_c_a * c2_c_b;
    c2_d_a = c2_c_s;
    c2_d_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_ix), 1, 16, 1, 0) - 1];
    c2_d_y = c2_d_a * c2_d_b;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_iy), 1, 16, 1, 0) - 1] = c2_c_y - c2_d_y;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_ix), 1, 16, 1, 0) - 1] = c2_temp;
    c2_e_a = c2_iy + 1;
    c2_iy = c2_e_a;
    c2_f_a = c2_ix + 1;
    c2_ix = c2_f_a;
  }
}

static void c2_d_eml_xrot(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c, real_T c2_s)
{
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  real_T c2_b_c;
  real_T c2_b_s;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  real_T c2_c_c;
  real_T c2_c_s;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_temp;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_d_y;
  int32_T c2_e_a;
  int32_T c2_f_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_c = c2_c;
  c2_b_s = c2_s;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_c_c = c2_b_c;
  c2_c_s = c2_b_s;
  c2_ix = c2_c_ix0;
  c2_iy = c2_c_iy0;
  for (c2_k = 1; c2_k < 7; c2_k++) {
    c2_a = c2_c_c;
    c2_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_ix), 1, 36, 1, 0) - 1];
    c2_y = c2_a * c2_b;
    c2_b_a = c2_c_s;
    c2_b_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 36, 1, 0) - 1];
    c2_b_y = c2_b_a * c2_b_b;
    c2_temp = c2_y + c2_b_y;
    c2_c_a = c2_c_c;
    c2_c_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 36, 1, 0) - 1];
    c2_c_y = c2_c_a * c2_c_b;
    c2_d_a = c2_c_s;
    c2_d_b = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_ix), 1, 36, 1, 0) - 1];
    c2_d_y = c2_d_a * c2_d_b;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_iy), 1, 36, 1, 0) - 1] = c2_c_y - c2_d_y;
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_ix), 1, 36, 1, 0) - 1] = c2_temp;
    c2_e_a = c2_iy + 1;
    c2_iy = c2_e_a;
    c2_f_a = c2_ix + 1;
    c2_ix = c2_f_a;
  }
}

static void c2_c_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[16], int32_T c2_ix0, int32_T c2_iy0)
{
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  real_T c2_temp;
  int32_T c2_a;
  int32_T c2_b_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_below_threshold(chartInstance);
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_ix = c2_c_ix0;
  c2_iy = c2_c_iy0;
  for (c2_k = 1; c2_k < 5; c2_k++) {
    c2_temp = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c2_ix), 1, 16, 1, 0) - 1];
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_ix), 1, 16, 1, 0) - 1] = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_iy), 1, 16, 1, 0) - 1];
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_iy), 1, 16, 1, 0) - 1] = c2_temp;
    c2_a = c2_ix + 1;
    c2_ix = c2_a;
    c2_b_a = c2_iy + 1;
    c2_iy = c2_b_a;
  }
}

static void c2_d_eml_xswap(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_x[36], int32_T c2_ix0, int32_T c2_iy0)
{
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  real_T c2_temp;
  int32_T c2_a;
  int32_T c2_b_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_ix = c2_c_ix0;
  c2_iy = c2_c_iy0;
  for (c2_k = 1; c2_k < 7; c2_k++) {
    c2_temp = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c2_ix), 1, 36, 1, 0) - 1];
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_ix), 1, 36, 1, 0) - 1] = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_iy), 1, 36, 1, 0) - 1];
    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_iy), 1, 36, 1, 0) - 1] = c2_temp;
    c2_a = c2_ix + 1;
    c2_ix = c2_a;
    c2_b_a = c2_iy + 1;
    c2_iy = c2_b_a;
  }
}

static void c2_b_eml_matlab_zgetrf(SFc2_CONTROL_POSICIONInstanceStruct
  *chartInstance, real_T c2_A[16], int32_T c2_ipiv[4], int32_T *c2_info)
{
  int32_T c2_i247;
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
  int32_T c2_n;
  int32_T c2_ix0;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_idxmax;
  int32_T c2_ix;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_b_y;
  real_T c2_smax;
  int32_T c2_d_n;
  int32_T c2_c_b;
  int32_T c2_d_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_e_a;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_c_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_d_y;
  real_T c2_s;
  int32_T c2_f_a;
  int32_T c2_jpiv_offset;
  int32_T c2_g_a;
  int32_T c2_e_b;
  int32_T c2_jpiv;
  int32_T c2_h_a;
  int32_T c2_f_b;
  int32_T c2_c_c;
  int32_T c2_g_b;
  int32_T c2_jrow;
  int32_T c2_i_a;
  int32_T c2_h_b;
  int32_T c2_jprow;
  int32_T c2_d_ix0;
  int32_T c2_iy0;
  int32_T c2_e_ix0;
  int32_T c2_b_iy0;
  int32_T c2_f_ix0;
  int32_T c2_c_iy0;
  int32_T c2_b_ix;
  int32_T c2_iy;
  int32_T c2_c_k;
  real_T c2_temp;
  int32_T c2_j_a;
  int32_T c2_k_a;
  int32_T c2_b_jp1j;
  int32_T c2_l_a;
  int32_T c2_d_c;
  int32_T c2_m_a;
  int32_T c2_i_b;
  int32_T c2_i248;
  int32_T c2_n_a;
  int32_T c2_j_b;
  int32_T c2_o_a;
  int32_T c2_k_b;
  boolean_T c2_b_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_k_x;
  real_T c2_e_y;
  real_T c2_z;
  int32_T c2_l_b;
  int32_T c2_e_c;
  int32_T c2_p_a;
  int32_T c2_f_c;
  int32_T c2_q_a;
  int32_T c2_g_c;
  int32_T c2_m;
  int32_T c2_e_n;
  int32_T c2_g_ix0;
  int32_T c2_d_iy0;
  int32_T c2_ia0;
  real_T c2_d10;
  c2_realmin(chartInstance);
  c2_eps(chartInstance);
  for (c2_i247 = 0; c2_i247 < 4; c2_i247++) {
    c2_ipiv[c2_i247] = 1 + c2_i247;
  }

  *c2_info = 0;
  for (c2_j = 1; c2_j < 4; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j - 1;
    c2_jm1 = c2_a;
    c2_b = c2_b_j;
    c2_mmj = 4 - c2_b;
    c2_b_a = c2_jm1;
    c2_c = c2_b_a * 5;
    c2_b_b = c2_c + 1;
    c2_jj = c2_b_b;
    c2_c_a = c2_jj + 1;
    c2_jp1j = c2_c_a;
    c2_d_a = c2_mmj;
    c2_b_c = c2_d_a;
    c2_n = c2_b_c + 1;
    c2_ix0 = c2_jj;
    c2_b_n = c2_n;
    c2_b_ix0 = c2_ix0;
    c2_c_n = c2_b_n;
    c2_c_ix0 = c2_b_ix0;
    if (c2_c_n < 1) {
      c2_idxmax = 0;
    } else {
      c2_idxmax = 1;
      if (c2_c_n > 1) {
        c2_ix = c2_c_ix0;
        c2_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_ix), 1, 16, 1, 0) - 1];
        c2_b_x = c2_x;
        c2_c_x = c2_b_x;
        c2_y = muDoubleScalarAbs(c2_c_x);
        c2_d_x = 0.0;
        c2_e_x = c2_d_x;
        c2_b_y = muDoubleScalarAbs(c2_e_x);
        c2_smax = c2_y + c2_b_y;
        c2_d_n = c2_c_n;
        c2_c_b = c2_d_n;
        c2_d_b = c2_c_b;
        if (2 > c2_d_b) {
          c2_overflow = FALSE;
        } else {
          c2_overflow = (c2_d_b > 2147483646);
        }

        if (c2_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_overflow);
        }

        for (c2_k = 2; c2_k <= c2_d_n; c2_k++) {
          c2_b_k = c2_k;
          c2_e_a = c2_ix + 1;
          c2_ix = c2_e_a;
          c2_f_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 16, 1, 0) - 1];
          c2_g_x = c2_f_x;
          c2_h_x = c2_g_x;
          c2_c_y = muDoubleScalarAbs(c2_h_x);
          c2_i_x = 0.0;
          c2_j_x = c2_i_x;
          c2_d_y = muDoubleScalarAbs(c2_j_x);
          c2_s = c2_c_y + c2_d_y;
          if (c2_s > c2_smax) {
            c2_idxmax = c2_b_k;
            c2_smax = c2_s;
          }
        }
      }
    }

    c2_f_a = c2_idxmax - 1;
    c2_jpiv_offset = c2_f_a;
    c2_g_a = c2_jj;
    c2_e_b = c2_jpiv_offset;
    c2_jpiv = c2_g_a + c2_e_b;
    if (c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if (c2_jpiv_offset != 0) {
        c2_h_a = c2_b_j;
        c2_f_b = c2_jpiv_offset;
        c2_c_c = c2_h_a + c2_f_b;
        c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 4, 1, 0) - 1] = c2_c_c;
        c2_g_b = c2_jm1 + 1;
        c2_jrow = c2_g_b;
        c2_i_a = c2_jrow;
        c2_h_b = c2_jpiv_offset;
        c2_jprow = c2_i_a + c2_h_b;
        c2_d_ix0 = c2_jrow;
        c2_iy0 = c2_jprow;
        c2_e_ix0 = c2_d_ix0;
        c2_b_iy0 = c2_iy0;
        c2_below_threshold(chartInstance);
        c2_f_ix0 = c2_e_ix0;
        c2_c_iy0 = c2_b_iy0;
        c2_b_ix = c2_f_ix0;
        c2_iy = c2_c_iy0;
        for (c2_c_k = 1; c2_c_k < 5; c2_c_k++) {
          c2_temp = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 16, 1, 0) - 1];
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ix), 1, 16, 1, 0) - 1] =
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy), 1, 16, 1, 0) - 1];
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy), 1, 16, 1, 0) - 1] = c2_temp;
          c2_j_a = c2_b_ix + 4;
          c2_b_ix = c2_j_a;
          c2_k_a = c2_iy + 4;
          c2_iy = c2_k_a;
        }
      }

      c2_b_jp1j = c2_jp1j;
      c2_l_a = c2_mmj;
      c2_d_c = c2_l_a;
      c2_m_a = c2_jp1j;
      c2_i_b = c2_d_c - 1;
      c2_i248 = c2_m_a + c2_i_b;
      c2_n_a = c2_b_jp1j;
      c2_j_b = c2_i248;
      c2_o_a = c2_n_a;
      c2_k_b = c2_j_b;
      if (c2_o_a > c2_k_b) {
        c2_b_overflow = FALSE;
      } else {
        c2_b_overflow = (c2_k_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
      }

      for (c2_i = c2_b_jp1j; c2_i <= c2_i248; c2_i++) {
        c2_b_i = c2_i;
        c2_k_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 16, 1, 0) - 1];
        c2_e_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_jj), 1, 16, 1, 0) - 1];
        c2_z = c2_k_x / c2_e_y;
        c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 16, 1, 0) - 1] = c2_z;
      }
    } else {
      *c2_info = c2_b_j;
    }

    c2_l_b = c2_b_j;
    c2_e_c = 4 - c2_l_b;
    c2_p_a = c2_jj;
    c2_f_c = c2_p_a;
    c2_q_a = c2_jj;
    c2_g_c = c2_q_a;
    c2_m = c2_mmj;
    c2_e_n = c2_e_c;
    c2_g_ix0 = c2_jp1j;
    c2_d_iy0 = c2_f_c + 4;
    c2_ia0 = c2_g_c + 5;
    c2_d10 = -1.0;
    c2_b_eml_xger(chartInstance, c2_m, c2_e_n, c2_d10, c2_g_ix0, c2_d_iy0, c2_A,
                  c2_ia0);
  }

  if (*c2_info == 0) {
    if (!(c2_A[15] != 0.0)) {
      *c2_info = 4;
    }
  }
}

static void c2_b_eml_xger(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[16], int32_T c2_ia0)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_ia0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_c_ia0;
  int32_T c2_d_m;
  int32_T c2_d_n;
  real_T c2_d_alpha1;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_d_ia0;
  int32_T c2_ixstart;
  int32_T c2_a;
  int32_T c2_jA;
  int32_T c2_jy;
  int32_T c2_e_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_j;
  real_T c2_yjy;
  real_T c2_temp;
  int32_T c2_ix;
  int32_T c2_c_b;
  int32_T c2_i249;
  int32_T c2_b_a;
  int32_T c2_d_b;
  int32_T c2_i250;
  int32_T c2_c_a;
  int32_T c2_e_b;
  int32_T c2_d_a;
  int32_T c2_f_b;
  boolean_T c2_b_overflow;
  int32_T c2_ijA;
  int32_T c2_b_ijA;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_ia0 = c2_ia0;
  c2_c_m = c2_b_m;
  c2_c_n = c2_b_n;
  c2_c_alpha1 = c2_b_alpha1;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_c_ia0 = c2_b_ia0;
  c2_d_m = c2_c_m;
  c2_d_n = c2_c_n;
  c2_d_alpha1 = c2_c_alpha1;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_d_ia0 = c2_c_ia0;
  if (c2_d_alpha1 == 0.0) {
  } else {
    c2_ixstart = c2_d_ix0;
    c2_a = c2_d_ia0 - 1;
    c2_jA = c2_a;
    c2_jy = c2_d_iy0;
    c2_e_n = c2_d_n;
    c2_b = c2_e_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = FALSE;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_j = 1; c2_j <= c2_e_n; c2_j++) {
      c2_yjy = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_jy), 1, 16, 1, 0) - 1];
      if (c2_yjy != 0.0) {
        c2_temp = c2_yjy * c2_d_alpha1;
        c2_ix = c2_ixstart;
        c2_c_b = c2_jA + 1;
        c2_i249 = c2_c_b;
        c2_b_a = c2_d_m;
        c2_d_b = c2_jA;
        c2_i250 = c2_b_a + c2_d_b;
        c2_c_a = c2_i249;
        c2_e_b = c2_i250;
        c2_d_a = c2_c_a;
        c2_f_b = c2_e_b;
        if (c2_d_a > c2_f_b) {
          c2_b_overflow = FALSE;
        } else {
          c2_b_overflow = (c2_f_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
        }

        for (c2_ijA = c2_i249; c2_ijA <= c2_i250; c2_ijA++) {
          c2_b_ijA = c2_ijA;
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 16, 1, 0) - 1] =
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 16, 1, 0) - 1] +
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_ix), 1, 16, 1, 0) - 1] * c2_temp;
          c2_e_a = c2_ix + 1;
          c2_ix = c2_e_a;
        }
      }

      c2_f_a = c2_jy + 4;
      c2_jy = c2_f_a;
      c2_g_a = c2_jA + 4;
      c2_jA = c2_g_a;
    }
  }
}

static void c2_c_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24])
{
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_b_b;
  int32_T c2_jBcol;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_b_a;
  int32_T c2_c_c;
  int32_T c2_c_b;
  int32_T c2_d_c;
  int32_T c2_d_b;
  int32_T c2_kAcol;
  int32_T c2_c_a;
  int32_T c2_e_b;
  int32_T c2_e_c;
  int32_T c2_d_a;
  int32_T c2_i251;
  boolean_T c2_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_e_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_f_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_g_a;
  int32_T c2_h_b;
  int32_T c2_h_c;
  int32_T c2_h_a;
  int32_T c2_i_b;
  int32_T c2_i_c;
  c2_b_below_threshold(chartInstance);
  c2_f_eml_scalar_eg(chartInstance);
  for (c2_j = 1; c2_j < 7; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j;
    c2_c = c2_a;
    c2_b = c2_c - 1;
    c2_b_c = c2_b << 2;
    c2_b_b = c2_b_c;
    c2_jBcol = c2_b_b;
    for (c2_k = 1; c2_k < 5; c2_k++) {
      c2_b_k = c2_k;
      c2_b_a = c2_b_k;
      c2_c_c = c2_b_a;
      c2_c_b = c2_c_c - 1;
      c2_d_c = c2_c_b << 2;
      c2_d_b = c2_d_c;
      c2_kAcol = c2_d_b;
      c2_c_a = c2_b_k;
      c2_e_b = c2_jBcol;
      c2_e_c = c2_c_a + c2_e_b;
      if (c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_e_c), 1, 24, 1, 0) - 1] != 0.0) {
        c2_d_a = c2_b_k;
        c2_i251 = c2_d_a;
        c2_overflow = FALSE;
        if (c2_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_overflow);
        }

        for (c2_i = c2_i251 + 1; c2_i < 5; c2_i++) {
          c2_b_i = c2_i;
          c2_e_a = c2_b_i;
          c2_f_b = c2_jBcol;
          c2_f_c = c2_e_a + c2_f_b;
          c2_f_a = c2_b_i;
          c2_g_b = c2_jBcol;
          c2_g_c = c2_f_a + c2_g_b;
          c2_g_a = c2_b_k;
          c2_h_b = c2_jBcol;
          c2_h_c = c2_g_a + c2_h_b;
          c2_h_a = c2_b_i;
          c2_i_b = c2_kAcol;
          c2_i_c = c2_h_a + c2_i_b;
          c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_f_c), 1, 24, 1, 0) - 1] =
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_g_c), 1, 24, 1, 0) - 1] -
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_h_c), 1, 24, 1, 0) - 1] *
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_i_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void c2_d_eml_xtrsm(SFc2_CONTROL_POSICIONInstanceStruct *chartInstance,
  real_T c2_A[16], real_T c2_B[24])
{
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_b_b;
  int32_T c2_jBcol;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_b_a;
  int32_T c2_c_c;
  int32_T c2_c_b;
  int32_T c2_d_c;
  int32_T c2_d_b;
  int32_T c2_kAcol;
  int32_T c2_c_a;
  int32_T c2_e_b;
  int32_T c2_e_c;
  int32_T c2_d_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_e_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_f_a;
  int32_T c2_h_b;
  int32_T c2_h_c;
  real_T c2_x;
  real_T c2_y;
  real_T c2_z;
  int32_T c2_g_a;
  int32_T c2_i252;
  int32_T c2_i_b;
  int32_T c2_j_b;
  boolean_T c2_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_h_a;
  int32_T c2_k_b;
  int32_T c2_i_c;
  int32_T c2_i_a;
  int32_T c2_l_b;
  int32_T c2_j_c;
  int32_T c2_j_a;
  int32_T c2_m_b;
  int32_T c2_k_c;
  int32_T c2_k_a;
  int32_T c2_n_b;
  int32_T c2_l_c;
  c2_b_below_threshold(chartInstance);
  c2_f_eml_scalar_eg(chartInstance);
  for (c2_j = 1; c2_j < 7; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j;
    c2_c = c2_a;
    c2_b = c2_c - 1;
    c2_b_c = c2_b << 2;
    c2_b_b = c2_b_c;
    c2_jBcol = c2_b_b;
    for (c2_k = 4; c2_k > 0; c2_k--) {
      c2_b_k = c2_k;
      c2_b_a = c2_b_k;
      c2_c_c = c2_b_a;
      c2_c_b = c2_c_c - 1;
      c2_d_c = c2_c_b << 2;
      c2_d_b = c2_d_c;
      c2_kAcol = c2_d_b;
      c2_c_a = c2_b_k;
      c2_e_b = c2_jBcol;
      c2_e_c = c2_c_a + c2_e_b;
      if (c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_e_c), 1, 24, 1, 0) - 1] != 0.0) {
        c2_d_a = c2_b_k;
        c2_f_b = c2_jBcol;
        c2_f_c = c2_d_a + c2_f_b;
        c2_e_a = c2_b_k;
        c2_g_b = c2_jBcol;
        c2_g_c = c2_e_a + c2_g_b;
        c2_f_a = c2_b_k;
        c2_h_b = c2_kAcol;
        c2_h_c = c2_f_a + c2_h_b;
        c2_x = c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_g_c), 1, 24, 1, 0) - 1];
        c2_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_h_c), 1, 16, 1, 0) - 1];
        c2_z = c2_x / c2_y;
        c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_f_c), 1, 24, 1, 0) - 1] = c2_z;
        c2_g_a = c2_b_k - 1;
        c2_i252 = c2_g_a;
        c2_i_b = c2_i252;
        c2_j_b = c2_i_b;
        if (1 > c2_j_b) {
          c2_overflow = FALSE;
        } else {
          c2_overflow = (c2_j_b > 2147483646);
        }

        if (c2_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_overflow);
        }

        for (c2_i = 1; c2_i <= c2_i252; c2_i++) {
          c2_b_i = c2_i;
          c2_h_a = c2_b_i;
          c2_k_b = c2_jBcol;
          c2_i_c = c2_h_a + c2_k_b;
          c2_i_a = c2_b_i;
          c2_l_b = c2_jBcol;
          c2_j_c = c2_i_a + c2_l_b;
          c2_j_a = c2_b_k;
          c2_m_b = c2_jBcol;
          c2_k_c = c2_j_a + c2_m_b;
          c2_k_a = c2_b_i;
          c2_n_b = c2_kAcol;
          c2_l_c = c2_k_a + c2_n_b;
          c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_i_c), 1, 24, 1, 0) - 1] =
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_j_c), 1, 24, 1, 0) - 1] -
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_k_c), 1, 24, 1, 0) - 1] *
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_l_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc2_CONTROL_POSICIONInstanceStruct
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

void sf_c2_CONTROL_POSICION_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(356159512U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(458355310U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1366669892U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(954798777U);
}

mxArray *sf_c2_CONTROL_POSICION_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("21Lnlv0qE5ASYGFWUOgVdB");
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
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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

mxArray *sf_c2_CONTROL_POSICION_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_CONTROL_POSICION(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[16],T\"X\",},{M[1],M[13],T\"qp\",},{M[8],M[0],T\"is_active_c2_CONTROL_POSICION\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CONTROL_POSICION_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
    chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CONTROL_POSICIONMachineNumber_,
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
          init_script_number_translation(_CONTROL_POSICIONMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CONTROL_POSICIONMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CONTROL_POSICIONMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ex");
          _SFD_SET_DATA_PROPS(2,2,0,1,"qp");
          _SFD_SET_DATA_PROPS(3,2,0,1,"X");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4630);
        _SFD_CV_INIT_EML_IF(0,1,0,4318,4338,4380,4504);
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
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T (*c2_q)[4];
          real_T (*c2_ex)[6];
          real_T (*c2_qp)[4];
          real_T (*c2_X)[6];
          c2_X = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_qp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_ex = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c2_q = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_q);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_ex);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_qp);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_X);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CONTROL_POSICIONMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "1xZKXtqcTzT7nbuwjxBZ8D";
}

static void sf_opaque_initialize_c2_CONTROL_POSICION(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_CONTROL_POSICIONInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
    chartInstanceVar);
  initialize_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_CONTROL_POSICION(void *chartInstanceVar)
{
  enable_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_CONTROL_POSICION(void *chartInstanceVar)
{
  disable_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_CONTROL_POSICION(void *chartInstanceVar)
{
  sf_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_CONTROL_POSICION(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_CONTROL_POSICION
    ((SFc2_CONTROL_POSICIONInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CONTROL_POSICION();/* state var info */
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

extern void sf_internal_set_sim_state_c2_CONTROL_POSICION(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CONTROL_POSICION();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_CONTROL_POSICION(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_CONTROL_POSICION(S);
}

static void sf_opaque_set_sim_state_c2_CONTROL_POSICION(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_CONTROL_POSICION(S, st);
}

static void sf_opaque_terminate_c2_CONTROL_POSICION(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CONTROL_POSICIONInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CONTROL_POSICION_optimization_info();
    }

    finalize_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CONTROL_POSICION(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CONTROL_POSICION((SFc2_CONTROL_POSICIONInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_CONTROL_POSICION(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CONTROL_POSICION_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4291302610U));
  ssSetChecksum1(S,(2670571259U));
  ssSetChecksum2(S,(2477918892U));
  ssSetChecksum3(S,(3261359113U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_CONTROL_POSICION(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_CONTROL_POSICION(SimStruct *S)
{
  SFc2_CONTROL_POSICIONInstanceStruct *chartInstance;
  chartInstance = (SFc2_CONTROL_POSICIONInstanceStruct *)utMalloc(sizeof
    (SFc2_CONTROL_POSICIONInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_CONTROL_POSICIONInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_CONTROL_POSICION;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_CONTROL_POSICION;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_CONTROL_POSICION;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_CONTROL_POSICION;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_CONTROL_POSICION;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_CONTROL_POSICION;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_CONTROL_POSICION;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_CONTROL_POSICION;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CONTROL_POSICION;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_CONTROL_POSICION;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_CONTROL_POSICION;
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

void c2_CONTROL_POSICION_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_CONTROL_POSICION(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CONTROL_POSICION(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CONTROL_POSICION(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CONTROL_POSICION_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
