/* Include files */

#include "blascompat32.h"
#include "SIMULACION_TORQUE_sfun.h"
#include "c6_SIMULACION_TORQUE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMULACION_TORQUE_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[17] = { "d2", "a2", "a3", "a4", "a5",
  "a6", "f1", "J", "fy1", "fz1", "F", "nargin", "nargout", "q2", "q3", "q4",
  "T1" };

/* Function Declarations */
static void initialize_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void initialize_params_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void enable_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void disable_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void set_sim_state_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c6_st);
static void finalize_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void sf_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c6_chartstep_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void initSimStructsc6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_T1, const char_T *c6_identifier, real_T
  c6_y[4]);
static void c6_b_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[6]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_e_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[24]);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[16]);
static void c6_eml_scalar_eg(SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_f_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_g_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_SIMULACION_TORQUE, const
  char_T *c6_identifier);
static uint8_T c6_h_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_SIMULACION_TORQUE = 0U;
}

static void initialize_params_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void enable_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[4];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_T1)[4];
  c6_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  for (c6_i0 = 0; c6_i0 < 4; c6_i0++) {
    c6_u[c6_i0] = (*c6_T1)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_SIMULACION_TORQUE;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[4];
  int32_T c6_i1;
  real_T (*c6_T1)[4];
  c6_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "T1",
                      c6_dv0);
  for (c6_i1 = 0; c6_i1 < 4; c6_i1++) {
    (*c6_T1)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_SIMULACION_TORQUE = c6_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_SIMULACION_TORQUE");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_SIMULACION_TORQUE(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

static void sf_c6_SIMULACION_TORQUE(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  int32_T c6_i2;
  real_T *c6_q2;
  real_T *c6_q3;
  real_T *c6_q4;
  real_T (*c6_T1)[4];
  c6_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 4; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_T1)[c6_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_q2, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_q3, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_q4, 3U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_SIMULACION_TORQUE(chartInstance);
  sf_debug_check_for_state_inconsistency(_SIMULACION_TORQUEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_q2;
  real_T c6_q3;
  real_T c6_q4;
  uint32_T c6_debug_family_var_map[17];
  real_T c6_d2;
  real_T c6_a2;
  real_T c6_a3;
  real_T c6_a4;
  real_T c6_a5;
  real_T c6_a6;
  real_T c6_f1;
  real_T c6_J[24];
  real_T c6_fy1;
  real_T c6_fz1;
  real_T c6_F[6];
  real_T c6_nargin = 3.0;
  real_T c6_nargout = 1.0;
  real_T c6_T1[4];
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_b;
  real_T c6_y;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_b_b;
  real_T c6_b_y;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_c_b;
  real_T c6_c_y;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_d_b;
  real_T c6_d_y;
  real_T c6_a;
  real_T c6_e_b;
  real_T c6_e_y;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_f_b;
  real_T c6_f_y;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_g_b;
  real_T c6_g_y;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_h_b;
  real_T c6_h_y;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_i_b;
  real_T c6_i_y;
  real_T c6_b_a;
  real_T c6_j_b;
  real_T c6_j_y;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_w_x;
  real_T c6_x_x;
  real_T c6_c_a;
  real_T c6_k_b;
  real_T c6_k_y;
  real_T c6_d_a;
  real_T c6_l_y;
  real_T c6_y_x;
  real_T c6_ab_x;
  real_T c6_l_b;
  real_T c6_m_y;
  real_T c6_bb_x;
  real_T c6_cb_x;
  real_T c6_m_b;
  real_T c6_n_y;
  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_n_b;
  real_T c6_o_y;
  real_T c6_fb_x;
  real_T c6_gb_x;
  real_T c6_o_b;
  real_T c6_p_y;
  real_T c6_hb_x;
  real_T c6_ib_x;
  real_T c6_e_a;
  real_T c6_q_y;
  real_T c6_jb_x;
  real_T c6_kb_x;
  real_T c6_lb_x;
  real_T c6_mb_x;
  real_T c6_p_b;
  real_T c6_r_y;
  real_T c6_nb_x;
  real_T c6_ob_x;
  real_T c6_q_b;
  real_T c6_s_y;
  real_T c6_pb_x;
  real_T c6_qb_x;
  real_T c6_r_b;
  real_T c6_t_y;
  real_T c6_rb_x;
  real_T c6_sb_x;
  real_T c6_s_b;
  real_T c6_u_y;
  real_T c6_f_a;
  real_T c6_t_b;
  real_T c6_v_y;
  real_T c6_tb_x;
  real_T c6_ub_x;
  real_T c6_vb_x;
  real_T c6_wb_x;
  real_T c6_u_b;
  real_T c6_w_y;
  real_T c6_xb_x;
  real_T c6_yb_x;
  real_T c6_v_b;
  real_T c6_x_y;
  real_T c6_ac_x;
  real_T c6_bc_x;
  real_T c6_w_b;
  real_T c6_y_y;
  real_T c6_cc_x;
  real_T c6_dc_x;
  real_T c6_x_b;
  real_T c6_ab_y;
  real_T c6_g_a;
  real_T c6_y_b;
  real_T c6_bb_y;
  real_T c6_ec_x;
  real_T c6_fc_x;
  real_T c6_gc_x;
  real_T c6_hc_x;
  real_T c6_h_a;
  real_T c6_ab_b;
  real_T c6_cb_y;
  real_T c6_i_a;
  real_T c6_db_y;
  real_T c6_ic_x;
  real_T c6_jc_x;
  real_T c6_kc_x;
  real_T c6_lc_x;
  real_T c6_mc_x;
  real_T c6_nc_x;
  real_T c6_oc_x;
  real_T c6_pc_x;
  int32_T c6_i3;
  int32_T c6_i4;
  static real_T c6_dv1[4] = { 0.0, -1.0, 0.0, 0.0 };

  real_T c6_qc_x;
  real_T c6_rc_x;
  real_T c6_bb_b;
  real_T c6_sc_x;
  real_T c6_tc_x;
  real_T c6_cb_b;
  real_T c6_dv2[6];
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  real_T c6_j_a[24];
  int32_T c6_i10;
  real_T c6_db_b[6];
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  real_T c6_C[4];
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  real_T *c6_b_q2;
  real_T *c6_b_q3;
  real_T *c6_b_q4;
  real_T (*c6_b_T1)[4];
  c6_b_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_b_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_q2;
  c6_b_hoistedGlobal = *c6_b_q3;
  c6_c_hoistedGlobal = *c6_b_q4;
  c6_q2 = c6_hoistedGlobal;
  c6_q3 = c6_b_hoistedGlobal;
  c6_q4 = c6_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c6_d2, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_a2, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_a3, 2U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_a4, 3U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_a5, 4U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_a6, 5U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_f1, 6U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_J, 7U, c6_d_sf_marshallOut,
    c6_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_fy1, 8U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_fz1, 9U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_F, 10U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 11U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 12U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_q2, 13U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_q3, 14U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_q4, 15U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_T1, 16U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_d2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_a5 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_a6 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_f1 = 3.9;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  c6_x = c6_q2;
  c6_b_x = c6_x;
  c6_b_x = muDoubleScalarCos(c6_b_x);
  c6_c_x = c6_q3 + c6_q4;
  c6_d_x = c6_c_x;
  c6_d_x = muDoubleScalarCos(c6_d_x);
  c6_b = c6_d_x;
  c6_y = 0.59 * c6_b;
  c6_e_x = c6_q3 + c6_q4;
  c6_f_x = c6_e_x;
  c6_f_x = muDoubleScalarCos(c6_f_x);
  c6_b_b = c6_f_x;
  c6_b_y = 0.59 * c6_b_b;
  c6_g_x = c6_q3;
  c6_h_x = c6_g_x;
  c6_h_x = muDoubleScalarCos(c6_h_x);
  c6_c_b = c6_h_x;
  c6_c_y = 0.8862 * c6_c_b;
  c6_i_x = c6_q3;
  c6_j_x = c6_i_x;
  c6_j_x = muDoubleScalarCos(c6_j_x);
  c6_d_b = c6_j_x;
  c6_d_y = 1.5 * c6_d_b;
  c6_a = -c6_b_x;
  c6_e_b = (((c6_a2 + c6_y) + c6_b_y) + c6_c_y) + c6_d_y;
  c6_e_y = c6_a * c6_e_b;
  c6_k_x = c6_q2;
  c6_l_x = c6_k_x;
  c6_l_x = muDoubleScalarSin(c6_l_x);
  c6_m_x = c6_q3 + c6_q4;
  c6_n_x = c6_m_x;
  c6_n_x = muDoubleScalarSin(c6_n_x);
  c6_f_b = c6_n_x;
  c6_f_y = 0.59 * c6_f_b;
  c6_o_x = c6_q3 + c6_q4;
  c6_p_x = c6_o_x;
  c6_p_x = muDoubleScalarSin(c6_p_x);
  c6_g_b = c6_p_x;
  c6_g_y = 0.59 * c6_g_b;
  c6_q_x = c6_q3;
  c6_r_x = c6_q_x;
  c6_r_x = muDoubleScalarSin(c6_r_x);
  c6_h_b = c6_r_x;
  c6_h_y = 0.8862 * c6_h_b;
  c6_s_x = c6_q3;
  c6_t_x = c6_s_x;
  c6_t_x = muDoubleScalarSin(c6_t_x);
  c6_i_b = c6_t_x;
  c6_i_y = 1.5 * c6_i_b;
  c6_b_a = c6_l_x;
  c6_j_b = ((c6_f_y + c6_g_y) + c6_h_y) + c6_i_y;
  c6_j_y = c6_b_a * c6_j_b;
  c6_u_x = c6_q3 + c6_q4;
  c6_v_x = c6_u_x;
  c6_v_x = muDoubleScalarSin(c6_v_x);
  c6_w_x = c6_q2;
  c6_x_x = c6_w_x;
  c6_x_x = muDoubleScalarSin(c6_x_x);
  c6_c_a = c6_v_x;
  c6_k_b = c6_x_x;
  c6_k_y = c6_c_a * c6_k_b;
  c6_d_a = c6_k_y;
  c6_l_y = c6_d_a * 1.18;
  c6_y_x = c6_q3 + c6_q4;
  c6_ab_x = c6_y_x;
  c6_ab_x = muDoubleScalarCos(c6_ab_x);
  c6_l_b = c6_ab_x;
  c6_m_y = -0.59 * c6_l_b;
  c6_bb_x = c6_q3 + c6_q4;
  c6_cb_x = c6_bb_x;
  c6_cb_x = muDoubleScalarCos(c6_cb_x);
  c6_m_b = c6_cb_x;
  c6_n_y = 0.59 * c6_m_b;
  c6_db_x = c6_q3;
  c6_eb_x = c6_db_x;
  c6_eb_x = muDoubleScalarCos(c6_eb_x);
  c6_n_b = c6_eb_x;
  c6_o_y = 0.8862 * c6_n_b;
  c6_fb_x = c6_q3;
  c6_gb_x = c6_fb_x;
  c6_gb_x = muDoubleScalarCos(c6_gb_x);
  c6_o_b = c6_gb_x;
  c6_p_y = 1.5 * c6_o_b;
  c6_hb_x = c6_q3 + c6_q4;
  c6_ib_x = c6_hb_x;
  c6_ib_x = muDoubleScalarCos(c6_ib_x);
  c6_e_a = -c6_ib_x;
  c6_q_y = c6_e_a * 1.18;
  c6_jb_x = c6_q2;
  c6_kb_x = c6_jb_x;
  c6_kb_x = muDoubleScalarSin(c6_kb_x);
  c6_lb_x = c6_q3 + c6_q4;
  c6_mb_x = c6_lb_x;
  c6_mb_x = muDoubleScalarCos(c6_mb_x);
  c6_p_b = c6_mb_x;
  c6_r_y = 0.59 * c6_p_b;
  c6_nb_x = c6_q3 + c6_q4;
  c6_ob_x = c6_nb_x;
  c6_ob_x = muDoubleScalarCos(c6_ob_x);
  c6_q_b = c6_ob_x;
  c6_s_y = 0.59 * c6_q_b;
  c6_pb_x = c6_q3;
  c6_qb_x = c6_pb_x;
  c6_qb_x = muDoubleScalarCos(c6_qb_x);
  c6_r_b = c6_qb_x;
  c6_t_y = 0.8862 * c6_r_b;
  c6_rb_x = c6_q3;
  c6_sb_x = c6_rb_x;
  c6_sb_x = muDoubleScalarCos(c6_sb_x);
  c6_s_b = c6_sb_x;
  c6_u_y = 1.5 * c6_s_b;
  c6_f_a = -c6_kb_x;
  c6_t_b = (((c6_a2 + c6_r_y) + c6_s_y) + c6_t_y) + c6_u_y;
  c6_v_y = c6_f_a * c6_t_b;
  c6_tb_x = c6_q2;
  c6_ub_x = c6_tb_x;
  c6_ub_x = muDoubleScalarCos(c6_ub_x);
  c6_vb_x = c6_q3 + c6_q4;
  c6_wb_x = c6_vb_x;
  c6_wb_x = muDoubleScalarSin(c6_wb_x);
  c6_u_b = c6_wb_x;
  c6_w_y = 0.59 * c6_u_b;
  c6_xb_x = c6_q3 + c6_q4;
  c6_yb_x = c6_xb_x;
  c6_yb_x = muDoubleScalarSin(c6_yb_x);
  c6_v_b = c6_yb_x;
  c6_x_y = 0.59 * c6_v_b;
  c6_ac_x = c6_q3;
  c6_bc_x = c6_ac_x;
  c6_bc_x = muDoubleScalarSin(c6_bc_x);
  c6_w_b = c6_bc_x;
  c6_y_y = 0.8862 * c6_w_b;
  c6_cc_x = c6_q3;
  c6_dc_x = c6_cc_x;
  c6_dc_x = muDoubleScalarSin(c6_dc_x);
  c6_x_b = c6_dc_x;
  c6_ab_y = 1.5 * c6_x_b;
  c6_g_a = -c6_ub_x;
  c6_y_b = ((c6_w_y + c6_x_y) + c6_y_y) + c6_ab_y;
  c6_bb_y = c6_g_a * c6_y_b;
  c6_ec_x = c6_q3 + c6_q4;
  c6_fc_x = c6_ec_x;
  c6_fc_x = muDoubleScalarSin(c6_fc_x);
  c6_gc_x = c6_q2;
  c6_hc_x = c6_gc_x;
  c6_hc_x = muDoubleScalarCos(c6_hc_x);
  c6_h_a = -c6_fc_x;
  c6_ab_b = c6_hc_x;
  c6_cb_y = c6_h_a * c6_ab_b;
  c6_i_a = c6_cb_y;
  c6_db_y = c6_i_a * 1.18;
  c6_ic_x = c6_q2;
  c6_jc_x = c6_ic_x;
  c6_jc_x = muDoubleScalarCos(c6_jc_x);
  c6_kc_x = c6_q2;
  c6_lc_x = c6_kc_x;
  c6_lc_x = muDoubleScalarCos(c6_lc_x);
  c6_mc_x = c6_q2;
  c6_nc_x = c6_mc_x;
  c6_nc_x = muDoubleScalarSin(c6_nc_x);
  c6_oc_x = c6_q2;
  c6_pc_x = c6_oc_x;
  c6_pc_x = muDoubleScalarSin(c6_pc_x);
  c6_J[0] = 0.0;
  c6_J[6] = c6_e_y;
  c6_J[12] = c6_j_y;
  c6_J[18] = c6_l_y;
  c6_J[1] = 0.0;
  c6_J[7] = 0.0;
  c6_J[13] = ((c6_m_y - c6_n_y) - c6_o_y) - c6_p_y;
  c6_J[19] = c6_q_y;
  c6_J[2] = 1.0;
  c6_J[8] = c6_v_y;
  c6_J[14] = c6_bb_y;
  c6_J[20] = c6_db_y;
  c6_J[3] = 0.0;
  c6_J[9] = 0.0;
  c6_J[15] = c6_jc_x;
  c6_J[21] = c6_lc_x;
  c6_i3 = 0;
  for (c6_i4 = 0; c6_i4 < 4; c6_i4++) {
    c6_J[c6_i3 + 4] = c6_dv1[c6_i4];
    c6_i3 += 6;
  }

  c6_J[5] = 0.0;
  c6_J[11] = 0.0;
  c6_J[17] = c6_nc_x;
  c6_J[23] = c6_pc_x;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 21);
  c6_qc_x = c6_q3;
  c6_rc_x = c6_qc_x;
  c6_rc_x = muDoubleScalarSin(c6_rc_x);
  c6_bb_b = c6_rc_x;
  c6_fy1 = 3.9 * c6_bb_b;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 22);
  c6_sc_x = c6_q3;
  c6_tc_x = c6_sc_x;
  c6_tc_x = muDoubleScalarCos(c6_tc_x);
  c6_cb_b = c6_tc_x;
  c6_fz1 = 3.9 * c6_cb_b;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 24);
  c6_dv2[0] = 0.0;
  c6_dv2[1] = c6_fy1;
  c6_dv2[2] = c6_fz1;
  c6_dv2[3] = 0.0;
  c6_dv2[4] = 0.0;
  c6_dv2[5] = 0.0;
  for (c6_i5 = 0; c6_i5 < 6; c6_i5++) {
    c6_F[c6_i5] = c6_dv2[c6_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 25);
  c6_i6 = 0;
  for (c6_i7 = 0; c6_i7 < 6; c6_i7++) {
    c6_i8 = 0;
    for (c6_i9 = 0; c6_i9 < 4; c6_i9++) {
      c6_j_a[c6_i9 + c6_i6] = c6_J[c6_i8 + c6_i7];
      c6_i8 += 6;
    }

    c6_i6 += 4;
  }

  for (c6_i10 = 0; c6_i10 < 6; c6_i10++) {
    c6_db_b[c6_i10] = c6_F[c6_i10];
  }

  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i11 = 0; c6_i11 < 4; c6_i11++) {
    c6_T1[c6_i11] = 0.0;
  }

  for (c6_i12 = 0; c6_i12 < 4; c6_i12++) {
    c6_T1[c6_i12] = 0.0;
  }

  for (c6_i13 = 0; c6_i13 < 4; c6_i13++) {
    c6_C[c6_i13] = c6_T1[c6_i13];
  }

  for (c6_i14 = 0; c6_i14 < 4; c6_i14++) {
    c6_T1[c6_i14] = c6_C[c6_i14];
  }

  for (c6_i15 = 0; c6_i15 < 4; c6_i15++) {
    c6_C[c6_i15] = c6_T1[c6_i15];
  }

  for (c6_i16 = 0; c6_i16 < 4; c6_i16++) {
    c6_T1[c6_i16] = c6_C[c6_i16];
  }

  for (c6_i17 = 0; c6_i17 < 4; c6_i17++) {
    c6_T1[c6_i17] = 0.0;
    c6_i18 = 0;
    for (c6_i19 = 0; c6_i19 < 6; c6_i19++) {
      c6_T1[c6_i17] += c6_j_a[c6_i18 + c6_i17] * c6_db_b[c6_i19];
      c6_i18 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -25);
  sf_debug_symbol_scope_pop();
  for (c6_i20 = 0; c6_i20 < 4; c6_i20++) {
    (*c6_b_T1)[c6_i20] = c6_T1[c6_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_SIMULACION_TORQUE
  (SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i21;
  real_T c6_b_inData[4];
  int32_T c6_i22;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i21 = 0; c6_i21 < 4; c6_i21++) {
    c6_b_inData[c6_i21] = (*(real_T (*)[4])c6_inData)[c6_i21];
  }

  for (c6_i22 = 0; c6_i22 < 4; c6_i22++) {
    c6_u[c6_i22] = c6_b_inData[c6_i22];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_T1, const char_T *c6_identifier, real_T
  c6_y[4])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_T1), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_T1);
}

static void c6_b_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4])
{
  real_T c6_dv3[4];
  int32_T c6_i23;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c6_i23 = 0; c6_i23 < 4; c6_i23++) {
    c6_y[c6_i23] = c6_dv3[c6_i23];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_T1;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[4];
  int32_T c6_i24;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_T1 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_T1), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_T1);
  for (c6_i24 = 0; c6_i24 < 4; c6_i24++) {
    (*(real_T (*)[4])c6_outData)[c6_i24] = c6_y[c6_i24];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i25;
  real_T c6_b_inData[6];
  int32_T c6_i26;
  real_T c6_u[6];
  const mxArray *c6_y = NULL;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i25 = 0; c6_i25 < 6; c6_i25++) {
    c6_b_inData[c6_i25] = (*(real_T (*)[6])c6_inData)[c6_i25];
  }

  for (c6_i26 = 0; c6_i26 < 6; c6_i26++) {
    c6_u[c6_i26] = c6_b_inData[c6_i26];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[6])
{
  real_T c6_dv4[6];
  int32_T c6_i27;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c6_i27 = 0; c6_i27 < 6; c6_i27++) {
    c6_y[c6_i27] = c6_dv4[c6_i27];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_F;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[6];
  int32_T c6_i28;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_F = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_F), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_F);
  for (c6_i28 = 0; c6_i28 < 6; c6_i28++) {
    (*(real_T (*)[6])c6_outData)[c6_i28] = c6_y[c6_i28];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  real_T c6_b_inData[24];
  int32_T c6_i32;
  int32_T c6_i33;
  int32_T c6_i34;
  real_T c6_u[24];
  const mxArray *c6_y = NULL;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i29 = 0;
  for (c6_i30 = 0; c6_i30 < 4; c6_i30++) {
    for (c6_i31 = 0; c6_i31 < 6; c6_i31++) {
      c6_b_inData[c6_i31 + c6_i29] = (*(real_T (*)[24])c6_inData)[c6_i31 +
        c6_i29];
    }

    c6_i29 += 6;
  }

  c6_i32 = 0;
  for (c6_i33 = 0; c6_i33 < 4; c6_i33++) {
    for (c6_i34 = 0; c6_i34 < 6; c6_i34++) {
      c6_u[c6_i34 + c6_i32] = c6_b_inData[c6_i34 + c6_i32];
    }

    c6_i32 += 6;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static void c6_e_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[24])
{
  real_T c6_dv5[24];
  int32_T c6_i35;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv5, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c6_i35 = 0; c6_i35 < 24; c6_i35++) {
    c6_y[c6_i35] = c6_dv5[c6_i35];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_J;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[24];
  int32_T c6_i36;
  int32_T c6_i37;
  int32_T c6_i38;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_J = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_J), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_J);
  c6_i36 = 0;
  for (c6_i37 = 0; c6_i37 < 4; c6_i37++) {
    for (c6_i38 = 0; c6_i38 < 6; c6_i38++) {
      (*(real_T (*)[24])c6_outData)[c6_i38 + c6_i36] = c6_y[c6_i38 + c6_i36];
    }

    c6_i36 += 6;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_SIMULACION_TORQUE_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[16];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i39;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16));
  for (c6_i39 = 0; c6_i39 < 16; c6_i39++) {
    c6_r0 = &c6_info[c6_i39];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i39);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i39);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i39);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i39);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i39);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i39);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i39);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i39);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[16])
{
  c6_info[0].context = "";
  c6_info[0].name = "cos";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[0].fileTimeLo = 3359288576U;
  c6_info[0].fileTimeHi = 30108069U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[1].name = "eml_scalar_cos";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[1].fileTimeLo = 3519288576U;
  c6_info[1].fileTimeHi = 30108069U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context = "";
  c6_info[2].name = "mtimes";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[2].fileTimeLo = 2169964032U;
  c6_info[2].fileTimeHi = 30114358U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context = "";
  c6_info[3].name = "sin";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[3].fileTimeLo = 3799288576U;
  c6_info[3].fileTimeHi = 30108069U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[4].name = "eml_scalar_sin";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c6_info[4].fileTimeLo = 3659288576U;
  c6_info[4].fileTimeHi = 30108069U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[5].name = "eml_index_class";
  c6_info[5].dominantType = "";
  c6_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[5].fileTimeLo = 4079288576U;
  c6_info[5].fileTimeHi = 30108069U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[6].name = "eml_scalar_eg";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[6].fileTimeLo = 4259288576U;
  c6_info[6].fileTimeHi = 30108069U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[7].name = "eml_xgemm";
  c6_info[7].dominantType = "int32";
  c6_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[7].fileTimeLo = 3399288576U;
  c6_info[7].fileTimeHi = 30108069U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c6_info[8].name = "length";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[8].fileTimeLo = 3899288576U;
  c6_info[8].fileTimeHi = 30108069U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c6_info[9].name = "min";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[9].fileTimeLo = 3259288576U;
  c6_info[9].fileTimeHi = 30108069U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[10].name = "eml_min_or_max";
  c6_info[10].dominantType = "char";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[10].fileTimeLo = 4179288576U;
  c6_info[10].fileTimeHi = 30108069U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[11].name = "eml_scalexp_alloc";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[11].fileTimeLo = 4259288576U;
  c6_info[11].fileTimeHi = 30108069U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[12].name = "eml_refblas_xgemm";
  c6_info[12].dominantType = "int32";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[12].fileTimeLo = 4119288576U;
  c6_info[12].fileTimeHi = 30108069U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[13].name = "eml_index_minus";
  c6_info[13].dominantType = "int32";
  c6_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[13].fileTimeLo = 4079288576U;
  c6_info[13].fileTimeHi = 30108069U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[14].name = "eml_index_times";
  c6_info[14].dominantType = "int32";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[14].fileTimeLo = 4099288576U;
  c6_info[14].fileTimeHi = 30108069U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[15].name = "eml_index_plus";
  c6_info[15].dominantType = "int32";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[15].fileTimeLo = 4079288576U;
  c6_info[15].fileTimeHi = 30108069U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
}

static void c6_eml_scalar_eg(SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static int32_T c6_f_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i40;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i40, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i40;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
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

static uint8_T c6_g_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_SIMULACION_TORQUE, const
  char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_SIMULACION_TORQUE), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_SIMULACION_TORQUE);
  return c6_y;
}

static uint8_T c6_h_emlrt_marshallIn(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_SIMULACION_TORQUE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3950024662U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2384196486U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3579802493U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3072806110U);
}

mxArray *sf_c6_SIMULACION_TORQUE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2663715230U);
    pr[1] = (double)(3125914627U);
    pr[2] = (double)(231024781U);
    pr[3] = (double)(170100149U);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c6_SIMULACION_TORQUE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"T1\",},{M[8],M[0],T\"is_active_c6_SIMULACION_TORQUE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_SIMULACION_TORQUE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
    chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMULACION_TORQUEMachineNumber_,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"q3");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1304);
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
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c6_q2;
          real_T *c6_q3;
          real_T *c6_q4;
          real_T (*c6_T1)[4];
          c6_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c6_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_T1);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_q2);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_q3);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_q4);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMULACION_TORQUEMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_SIMULACION_TORQUE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
  initialize_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_SIMULACION_TORQUE(void *chartInstanceVar)
{
  enable_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_SIMULACION_TORQUE(void *chartInstanceVar)
{
  disable_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_SIMULACION_TORQUE(void *chartInstanceVar)
{
  sf_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_SIMULACION_TORQUE(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_SIMULACION_TORQUE
    ((SFc6_SIMULACION_TORQUEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_SIMULACION_TORQUE();/* state var info */
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

extern void sf_internal_set_sim_state_c6_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_SIMULACION_TORQUE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_SIMULACION_TORQUE(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_SIMULACION_TORQUE(S);
}

static void sf_opaque_set_sim_state_c6_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c6_SIMULACION_TORQUE(S, st);
}

static void sf_opaque_terminate_c6_SIMULACION_TORQUE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_SIMULACION_TORQUEInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_SIMULACION_TORQUE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_SIMULACION_TORQUE((SFc6_SIMULACION_TORQUEInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",
                6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE",
      "SIMULACION_TORQUE",6,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SIMULACION_TORQUE",
        "SIMULACION_TORQUE",6,3);
      sf_mark_chart_reusable_outputs(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",6,
        1);
    }

    sf_set_rtw_dwork_info(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2229682607U));
  ssSetChecksum1(S,(1710000070U));
  ssSetChecksum2(S,(1831079505U));
  ssSetChecksum3(S,(2925670105U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMULACION_TORQUE", "SIMULACION_TORQUE",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_SIMULACION_TORQUE(SimStruct *S)
{
  SFc6_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc6_SIMULACION_TORQUEInstanceStruct *)malloc(sizeof
    (SFc6_SIMULACION_TORQUEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_SIMULACION_TORQUEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_SIMULACION_TORQUE;
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

void c6_SIMULACION_TORQUE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_SIMULACION_TORQUE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_SIMULACION_TORQUE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
