/* Include files */

#include "blascompat32.h"
#include "SIMULACION_TORQUE_sfun.h"
#include "c8_SIMULACION_TORQUE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMULACION_TORQUE_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[15] = { "d2", "a2", "a3", "a4", "f1",
  "Jg1", "fy1", "fz1", "F", "nargin", "nargout", "q1", "q2", "q3", "T1" };

/* Function Declarations */
static void initialize_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void initialize_params_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void enable_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void disable_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void set_sim_state_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c8_st);
static void finalize_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void sf_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c8_chartstep_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void initSimStructsc8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_T1, const char_T *c8_identifier, real_T
  c8_y[3]);
static void c8_b_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_d_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6]);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_e_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[18]);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[16]);
static void c8_eml_scalar_eg(SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_f_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_g_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_SIMULACION_TORQUE, const
  char_T *c8_identifier);
static uint8_T c8_h_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_SIMULACION_TORQUE = 0U;
}

static void initialize_params_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void enable_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[3];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T (*c8_T1)[3];
  c8_T1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2));
  for (c8_i0 = 0; c8_i0 < 3; c8_i0++) {
    c8_u[c8_i0] = (*c8_T1)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_SIMULACION_TORQUE;
  c8_b_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y);
  return c8_st;
}

static void set_sim_state_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv0[3];
  int32_T c8_i1;
  real_T (*c8_T1)[3];
  c8_T1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)), "T1",
                      c8_dv0);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    (*c8_T1)[c8_i1] = c8_dv0[c8_i1];
  }

  chartInstance->c8_is_active_c8_SIMULACION_TORQUE = c8_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_SIMULACION_TORQUE");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_SIMULACION_TORQUE(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

static void sf_c8_SIMULACION_TORQUE(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  int32_T c8_i2;
  real_T *c8_q1;
  real_T *c8_q2;
  real_T *c8_q3;
  real_T (*c8_T1)[3];
  c8_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_T1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
    _SFD_DATA_RANGE_CHECK((*c8_T1)[c8_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c8_q1, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_q2, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_q3, 3U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_SIMULACION_TORQUE(chartInstance);
  sf_debug_check_for_state_inconsistency(_SIMULACION_TORQUEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_chartstep_c8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  real_T c8_q1;
  real_T c8_q2;
  real_T c8_q3;
  uint32_T c8_debug_family_var_map[15];
  real_T c8_d2;
  real_T c8_a2;
  real_T c8_a3;
  real_T c8_a4;
  real_T c8_f1;
  real_T c8_Jg1[18];
  real_T c8_fy1;
  real_T c8_fz1;
  real_T c8_F[6];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  real_T c8_T1[3];
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_b;
  real_T c8_y;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_b_b;
  real_T c8_b_y;
  real_T c8_a;
  real_T c8_c_b;
  real_T c8_c_y;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_b_a;
  real_T c8_d_b;
  real_T c8_d_y;
  real_T c8_c_a;
  real_T c8_e_y;
  real_T c8_k_x;
  real_T c8_l_x;
  real_T c8_d_a;
  real_T c8_f_y;
  real_T c8_m_x;
  real_T c8_n_x;
  real_T c8_o_x;
  real_T c8_p_x;
  real_T c8_e_b;
  real_T c8_g_y;
  real_T c8_q_x;
  real_T c8_r_x;
  real_T c8_f_b;
  real_T c8_h_y;
  real_T c8_e_a;
  real_T c8_g_b;
  real_T c8_i_y;
  real_T c8_s_x;
  real_T c8_t_x;
  real_T c8_u_x;
  real_T c8_v_x;
  real_T c8_f_a;
  real_T c8_h_b;
  real_T c8_j_y;
  real_T c8_g_a;
  real_T c8_k_y;
  real_T c8_w_x;
  real_T c8_x_x;
  real_T c8_y_x;
  real_T c8_ab_x;
  int32_T c8_i3;
  int32_T c8_i4;
  static real_T c8_dv1[3] = { 0.0, -1.0, 0.0 };

  real_T c8_bb_x;
  real_T c8_cb_x;
  real_T c8_i_b;
  real_T c8_db_x;
  real_T c8_eb_x;
  real_T c8_j_b;
  real_T c8_dv2[6];
  int32_T c8_i5;
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_i9;
  real_T c8_h_a[18];
  int32_T c8_i10;
  real_T c8_k_b[6];
  int32_T c8_i11;
  int32_T c8_i12;
  int32_T c8_i13;
  real_T c8_C[3];
  int32_T c8_i14;
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i20;
  real_T *c8_b_q1;
  real_T *c8_b_q2;
  real_T *c8_b_q3;
  real_T (*c8_b_T1)[3];
  c8_b_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_b_T1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_b_q1;
  c8_b_hoistedGlobal = *c8_b_q2;
  c8_c_hoistedGlobal = *c8_b_q3;
  c8_q1 = c8_hoistedGlobal;
  c8_q2 = c8_b_hoistedGlobal;
  c8_q3 = c8_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_d2, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a2, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_a3, 2U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_a4, 3U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_f1, 4U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c8_Jg1, 5U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_fy1, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_fz1, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c8_F, 8U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 9U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 10U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_q1, 11U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_q2, 12U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_q3, 13U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c8_T1, 14U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 3);
  c8_d2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  c8_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  c8_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_f1 = 3.9;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
  c8_x = c8_q2;
  c8_b_x = c8_x;
  c8_b_x = muDoubleScalarCos(c8_b_x);
  c8_c_x = c8_q3;
  c8_d_x = c8_c_x;
  c8_d_x = muDoubleScalarCos(c8_d_x);
  c8_b = c8_d_x;
  c8_y = 0.8862 * c8_b;
  c8_e_x = c8_q3;
  c8_f_x = c8_e_x;
  c8_f_x = muDoubleScalarCos(c8_f_x);
  c8_b_b = c8_f_x;
  c8_b_y = 1.5 * c8_b_b;
  c8_a = -c8_b_x;
  c8_c_b = (c8_a2 + c8_y) + c8_b_y;
  c8_c_y = c8_a * c8_c_b;
  c8_g_x = c8_q2;
  c8_h_x = c8_g_x;
  c8_h_x = muDoubleScalarSin(c8_h_x);
  c8_i_x = c8_q3;
  c8_j_x = c8_i_x;
  c8_j_x = muDoubleScalarSin(c8_j_x);
  c8_b_a = c8_h_x;
  c8_d_b = c8_j_x;
  c8_d_y = c8_b_a * c8_d_b;
  c8_c_a = c8_d_y;
  c8_e_y = c8_c_a * 2.3862;
  c8_k_x = c8_q3;
  c8_l_x = c8_k_x;
  c8_l_x = muDoubleScalarCos(c8_l_x);
  c8_d_a = -c8_l_x;
  c8_f_y = c8_d_a * 2.3862;
  c8_m_x = c8_q2;
  c8_n_x = c8_m_x;
  c8_n_x = muDoubleScalarSin(c8_n_x);
  c8_o_x = c8_q3;
  c8_p_x = c8_o_x;
  c8_p_x = muDoubleScalarCos(c8_p_x);
  c8_e_b = c8_p_x;
  c8_g_y = 0.8862 * c8_e_b;
  c8_q_x = c8_q3;
  c8_r_x = c8_q_x;
  c8_r_x = muDoubleScalarCos(c8_r_x);
  c8_f_b = c8_r_x;
  c8_h_y = 1.5 * c8_f_b;
  c8_e_a = -c8_n_x;
  c8_g_b = (c8_a2 + c8_g_y) + c8_h_y;
  c8_i_y = c8_e_a * c8_g_b;
  c8_s_x = c8_q2;
  c8_t_x = c8_s_x;
  c8_t_x = muDoubleScalarCos(c8_t_x);
  c8_u_x = c8_q3;
  c8_v_x = c8_u_x;
  c8_v_x = muDoubleScalarSin(c8_v_x);
  c8_f_a = -c8_t_x;
  c8_h_b = c8_v_x;
  c8_j_y = c8_f_a * c8_h_b;
  c8_g_a = c8_j_y;
  c8_k_y = c8_g_a * 2.3862;
  c8_w_x = c8_q2;
  c8_x_x = c8_w_x;
  c8_x_x = muDoubleScalarCos(c8_x_x);
  c8_y_x = c8_q2;
  c8_ab_x = c8_y_x;
  c8_ab_x = muDoubleScalarSin(c8_ab_x);
  c8_Jg1[0] = 0.0;
  c8_Jg1[6] = c8_c_y;
  c8_Jg1[12] = c8_e_y;
  c8_Jg1[1] = 0.0;
  c8_Jg1[7] = 0.0;
  c8_Jg1[13] = c8_f_y;
  c8_Jg1[2] = 1.0;
  c8_Jg1[8] = c8_i_y;
  c8_Jg1[14] = c8_k_y;
  c8_Jg1[3] = 0.0;
  c8_Jg1[9] = 0.0;
  c8_Jg1[15] = c8_x_x;
  c8_i3 = 0;
  for (c8_i4 = 0; c8_i4 < 3; c8_i4++) {
    c8_Jg1[c8_i3 + 4] = c8_dv1[c8_i4];
    c8_i3 += 6;
  }

  c8_Jg1[5] = 0.0;
  c8_Jg1[11] = 0.0;
  c8_Jg1[17] = c8_ab_x;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 17);
  c8_bb_x = c8_q1;
  c8_cb_x = c8_bb_x;
  c8_cb_x = muDoubleScalarSin(c8_cb_x);
  c8_i_b = c8_cb_x;
  c8_fy1 = 3.9 * c8_i_b;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 18);
  c8_db_x = c8_q1;
  c8_eb_x = c8_db_x;
  c8_eb_x = muDoubleScalarCos(c8_eb_x);
  c8_j_b = c8_eb_x;
  c8_fz1 = 3.9 * c8_j_b;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 20);
  c8_dv2[0] = 0.0;
  c8_dv2[1] = c8_fy1;
  c8_dv2[2] = c8_fz1;
  c8_dv2[3] = 0.0;
  c8_dv2[4] = 0.0;
  c8_dv2[5] = 0.0;
  for (c8_i5 = 0; c8_i5 < 6; c8_i5++) {
    c8_F[c8_i5] = c8_dv2[c8_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 21);
  c8_i6 = 0;
  for (c8_i7 = 0; c8_i7 < 6; c8_i7++) {
    c8_i8 = 0;
    for (c8_i9 = 0; c8_i9 < 3; c8_i9++) {
      c8_h_a[c8_i9 + c8_i6] = c8_Jg1[c8_i8 + c8_i7];
      c8_i8 += 6;
    }

    c8_i6 += 3;
  }

  for (c8_i10 = 0; c8_i10 < 6; c8_i10++) {
    c8_k_b[c8_i10] = c8_F[c8_i10];
  }

  c8_eml_scalar_eg(chartInstance);
  c8_eml_scalar_eg(chartInstance);
  for (c8_i11 = 0; c8_i11 < 3; c8_i11++) {
    c8_T1[c8_i11] = 0.0;
  }

  for (c8_i12 = 0; c8_i12 < 3; c8_i12++) {
    c8_T1[c8_i12] = 0.0;
  }

  for (c8_i13 = 0; c8_i13 < 3; c8_i13++) {
    c8_C[c8_i13] = c8_T1[c8_i13];
  }

  for (c8_i14 = 0; c8_i14 < 3; c8_i14++) {
    c8_T1[c8_i14] = c8_C[c8_i14];
  }

  for (c8_i15 = 0; c8_i15 < 3; c8_i15++) {
    c8_C[c8_i15] = c8_T1[c8_i15];
  }

  for (c8_i16 = 0; c8_i16 < 3; c8_i16++) {
    c8_T1[c8_i16] = c8_C[c8_i16];
  }

  for (c8_i17 = 0; c8_i17 < 3; c8_i17++) {
    c8_T1[c8_i17] = 0.0;
    c8_i18 = 0;
    for (c8_i19 = 0; c8_i19 < 6; c8_i19++) {
      c8_T1[c8_i17] += c8_h_a[c8_i18 + c8_i17] * c8_k_b[c8_i19];
      c8_i18 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -21);
  sf_debug_symbol_scope_pop();
  for (c8_i20 = 0; c8_i20 < 3; c8_i20++) {
    (*c8_b_T1)[c8_i20] = c8_T1[c8_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_SIMULACION_TORQUE
  (SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i21;
  real_T c8_b_inData[3];
  int32_T c8_i22;
  real_T c8_u[3];
  const mxArray *c8_y = NULL;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i21 = 0; c8_i21 < 3; c8_i21++) {
    c8_b_inData[c8_i21] = (*(real_T (*)[3])c8_inData)[c8_i21];
  }

  for (c8_i22 = 0; c8_i22 < 3; c8_i22++) {
    c8_u[c8_i22] = c8_b_inData[c8_i22];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_T1, const char_T *c8_identifier, real_T
  c8_y[3])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_T1), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_T1);
}

static void c8_b_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3])
{
  real_T c8_dv3[3];
  int32_T c8_i23;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c8_i23 = 0; c8_i23 < 3; c8_i23++) {
    c8_y[c8_i23] = c8_dv3[c8_i23];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_T1;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[3];
  int32_T c8_i24;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_T1 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_T1), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_T1);
  for (c8_i24 = 0; c8_i24 < 3; c8_i24++) {
    (*(real_T (*)[3])c8_outData)[c8_i24] = c8_y[c8_i24];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i25;
  real_T c8_b_inData[6];
  int32_T c8_i26;
  real_T c8_u[6];
  const mxArray *c8_y = NULL;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i25 = 0; c8_i25 < 6; c8_i25++) {
    c8_b_inData[c8_i25] = (*(real_T (*)[6])c8_inData)[c8_i25];
  }

  for (c8_i26 = 0; c8_i26 < 6; c8_i26++) {
    c8_u[c8_i26] = c8_b_inData[c8_i26];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

static void c8_d_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6])
{
  real_T c8_dv4[6];
  int32_T c8_i27;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c8_i27 = 0; c8_i27 < 6; c8_i27++) {
    c8_y[c8_i27] = c8_dv4[c8_i27];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_F;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[6];
  int32_T c8_i28;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_F = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_F), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_F);
  for (c8_i28 = 0; c8_i28 < 6; c8_i28++) {
    (*(real_T (*)[6])c8_outData)[c8_i28] = c8_y[c8_i28];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i29;
  int32_T c8_i30;
  int32_T c8_i31;
  real_T c8_b_inData[18];
  int32_T c8_i32;
  int32_T c8_i33;
  int32_T c8_i34;
  real_T c8_u[18];
  const mxArray *c8_y = NULL;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i29 = 0;
  for (c8_i30 = 0; c8_i30 < 3; c8_i30++) {
    for (c8_i31 = 0; c8_i31 < 6; c8_i31++) {
      c8_b_inData[c8_i31 + c8_i29] = (*(real_T (*)[18])c8_inData)[c8_i31 +
        c8_i29];
    }

    c8_i29 += 6;
  }

  c8_i32 = 0;
  for (c8_i33 = 0; c8_i33 < 3; c8_i33++) {
    for (c8_i34 = 0; c8_i34 < 6; c8_i34++) {
      c8_u[c8_i34 + c8_i32] = c8_b_inData[c8_i34 + c8_i32];
    }

    c8_i32 += 6;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 6, 3));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

static void c8_e_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[18])
{
  real_T c8_dv5[18];
  int32_T c8_i35;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv5, 1, 0, 0U, 1, 0U, 2, 6, 3);
  for (c8_i35 = 0; c8_i35 < 18; c8_i35++) {
    c8_y[c8_i35] = c8_dv5[c8_i35];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_Jg1;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[18];
  int32_T c8_i36;
  int32_T c8_i37;
  int32_T c8_i38;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_Jg1 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Jg1), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_Jg1);
  c8_i36 = 0;
  for (c8_i37 = 0; c8_i37 < 3; c8_i37++) {
    for (c8_i38 = 0; c8_i38 < 6; c8_i38++) {
      (*(real_T (*)[18])c8_outData)[c8_i38 + c8_i36] = c8_y[c8_i38 + c8_i36];
    }

    c8_i36 += 6;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_SIMULACION_TORQUE_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[16];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i39;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16));
  for (c8_i39 = 0; c8_i39 < 16; c8_i39++) {
    c8_r0 = &c8_info[c8_i39];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i39);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i39);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i39);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i39);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i39);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i39);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i39);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i39);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[16])
{
  c8_info[0].context = "";
  c8_info[0].name = "cos";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[0].fileTimeLo = 3359288576U;
  c8_info[0].fileTimeHi = 30108069U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[1].name = "eml_scalar_cos";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c8_info[1].fileTimeLo = 3519288576U;
  c8_info[1].fileTimeHi = 30108069U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context = "";
  c8_info[2].name = "mtimes";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[2].fileTimeLo = 2169964032U;
  c8_info[2].fileTimeHi = 30114358U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context = "";
  c8_info[3].name = "sin";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[3].fileTimeLo = 3799288576U;
  c8_info[3].fileTimeHi = 30108069U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[4].name = "eml_scalar_sin";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c8_info[4].fileTimeLo = 3659288576U;
  c8_info[4].fileTimeHi = 30108069U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[5].name = "eml_index_class";
  c8_info[5].dominantType = "";
  c8_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[5].fileTimeLo = 4079288576U;
  c8_info[5].fileTimeHi = 30108069U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[6].name = "eml_scalar_eg";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[6].fileTimeLo = 4259288576U;
  c8_info[6].fileTimeHi = 30108069U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[7].name = "eml_xgemm";
  c8_info[7].dominantType = "int32";
  c8_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[7].fileTimeLo = 3399288576U;
  c8_info[7].fileTimeHi = 30108069U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c8_info[8].name = "length";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[8].fileTimeLo = 3899288576U;
  c8_info[8].fileTimeHi = 30108069U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c8_info[9].name = "min";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[9].fileTimeLo = 3259288576U;
  c8_info[9].fileTimeHi = 30108069U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[10].name = "eml_min_or_max";
  c8_info[10].dominantType = "char";
  c8_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[10].fileTimeLo = 4179288576U;
  c8_info[10].fileTimeHi = 30108069U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[11].name = "eml_scalexp_alloc";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[11].fileTimeLo = 4259288576U;
  c8_info[11].fileTimeHi = 30108069U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[12].name = "eml_refblas_xgemm";
  c8_info[12].dominantType = "int32";
  c8_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[12].fileTimeLo = 4119288576U;
  c8_info[12].fileTimeHi = 30108069U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[13].name = "eml_index_minus";
  c8_info[13].dominantType = "int32";
  c8_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[13].fileTimeLo = 4079288576U;
  c8_info[13].fileTimeHi = 30108069U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
  c8_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[14].name = "eml_index_times";
  c8_info[14].dominantType = "int32";
  c8_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[14].fileTimeLo = 4099288576U;
  c8_info[14].fileTimeHi = 30108069U;
  c8_info[14].mFileTimeLo = 0U;
  c8_info[14].mFileTimeHi = 0U;
  c8_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[15].name = "eml_index_plus";
  c8_info[15].dominantType = "int32";
  c8_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[15].fileTimeLo = 4079288576U;
  c8_info[15].fileTimeHi = 30108069U;
  c8_info[15].mFileTimeLo = 0U;
  c8_info[15].mFileTimeHi = 0U;
}

static void c8_eml_scalar_eg(SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

static int32_T c8_f_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i40;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i40, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i40;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_g_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_SIMULACION_TORQUE, const
  char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_SIMULACION_TORQUE), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_SIMULACION_TORQUE);
  return c8_y;
}

static uint8_T c8_h_emlrt_marshallIn(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_SIMULACION_TORQUE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(919521540U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3323434037U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4281159629U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(334306686U);
}

mxArray *sf_c8_SIMULACION_TORQUE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3588225878U);
    pr[1] = (double)(3868768025U);
    pr[2] = (double)(2477449907U);
    pr[3] = (double)(1309225982U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c8_SIMULACION_TORQUE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"T1\",},{M[8],M[0],T\"is_active_c8_SIMULACION_TORQUE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_SIMULACION_TORQUE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
    chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMULACION_TORQUEMachineNumber_,
           8,
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
          init_script_number_translation(_SIMULACION_TORQUEMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_SIMULACION_TORQUEMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_SIMULACION_TORQUEMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"T1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"q1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q3");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,624);
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c8_q1;
          real_T *c8_q2;
          real_T *c8_q3;
          real_T (*c8_T1)[3];
          c8_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c8_T1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c8_T1);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_q1);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_q2);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_q3);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMULACION_TORQUEMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c8_SIMULACION_TORQUE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
  initialize_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_SIMULACION_TORQUE(void *chartInstanceVar)
{
  enable_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_SIMULACION_TORQUE(void *chartInstanceVar)
{
  disable_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_SIMULACION_TORQUE(void *chartInstanceVar)
{
  sf_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_SIMULACION_TORQUE(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_SIMULACION_TORQUE
    ((SFc8_SIMULACION_TORQUEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_SIMULACION_TORQUE();/* state var info */
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

extern void sf_internal_set_sim_state_c8_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_SIMULACION_TORQUE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_SIMULACION_TORQUE(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_SIMULACION_TORQUE(S);
}

static void sf_opaque_set_sim_state_c8_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c8_SIMULACION_TORQUE(S, st);
}

static void sf_opaque_terminate_c8_SIMULACION_TORQUE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_SIMULACION_TORQUEInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_SIMULACION_TORQUE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_SIMULACION_TORQUE((SFc8_SIMULACION_TORQUEInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",
                8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE",
      "SIMULACION_TORQUE",8,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SIMULACION_TORQUE",
        "SIMULACION_TORQUE",8,3);
      sf_mark_chart_reusable_outputs(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",8,
        1);
    }

    sf_set_rtw_dwork_info(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4274835356U));
  ssSetChecksum1(S,(3996622537U));
  ssSetChecksum2(S,(4100376909U));
  ssSetChecksum3(S,(3573873285U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMULACION_TORQUE", "SIMULACION_TORQUE",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_SIMULACION_TORQUE(SimStruct *S)
{
  SFc8_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc8_SIMULACION_TORQUEInstanceStruct *)malloc(sizeof
    (SFc8_SIMULACION_TORQUEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_SIMULACION_TORQUEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_SIMULACION_TORQUE;
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

void c8_SIMULACION_TORQUE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_SIMULACION_TORQUE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_SIMULACION_TORQUE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
