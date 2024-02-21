/* Include files */

#include "blascompat32.h"
#include "SIMULACION_TORQUE_sfun.h"
#include "c9_SIMULACION_TORQUE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMULACION_TORQUE_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[18] = { "f2", "d2", "a2", "a3", "a4",
  "a5", "a6", "Jg2", "fy2", "fz2", "F", "nargin", "nargout", "q1", "q2", "q3",
  "q4", "T2" };

/* Function Declarations */
static void initialize_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void initialize_params_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void enable_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void disable_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void set_sim_state_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void sf_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c9_chartstep_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void initSimStructsc9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_T2, const char_T *c9_identifier, real_T
  c9_y[4]);
static void c9_b_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[4]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[24]);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[16]);
static void c9_eml_scalar_eg(SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_f_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_g_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_SIMULACION_TORQUE, const
  char_T *c9_identifier);
static uint8_T c9_h_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_SIMULACION_TORQUE = 0U;
}

static void initialize_params_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void enable_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[4];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T (*c9_T2)[4];
  c9_T2 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2));
  for (c9_i0 = 0; c9_i0 < 4; c9_i0++) {
    c9_u[c9_i0] = (*c9_T2)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_SIMULACION_TORQUE;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y);
  return c9_st;
}

static void set_sim_state_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[4];
  int32_T c9_i1;
  real_T (*c9_T2)[4];
  c9_T2 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "T2",
                      c9_dv0);
  for (c9_i1 = 0; c9_i1 < 4; c9_i1++) {
    (*c9_T2)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_is_active_c9_SIMULACION_TORQUE = c9_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
     "is_active_c9_SIMULACION_TORQUE");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_SIMULACION_TORQUE(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

static void sf_c9_SIMULACION_TORQUE(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  int32_T c9_i2;
  real_T *c9_q1;
  real_T *c9_q2;
  real_T *c9_q3;
  real_T *c9_q4;
  real_T (*c9_T2)[4];
  c9_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c9_T2 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 4; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*c9_T2)[c9_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_q1, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_q2, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_q3, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_q4, 4U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_SIMULACION_TORQUE(chartInstance);
  sf_debug_check_for_state_inconsistency(_SIMULACION_TORQUEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_chartstep_c9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_q1;
  real_T c9_q2;
  real_T c9_q3;
  real_T c9_q4;
  uint32_T c9_debug_family_var_map[18];
  real_T c9_f2;
  real_T c9_d2;
  real_T c9_a2;
  real_T c9_a3;
  real_T c9_a4;
  real_T c9_a5;
  real_T c9_a6;
  real_T c9_Jg2[24];
  real_T c9_fy2;
  real_T c9_fz2;
  real_T c9_F[6];
  real_T c9_nargin = 4.0;
  real_T c9_nargout = 1.0;
  real_T c9_T2[4];
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_b;
  real_T c9_y;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_b_b;
  real_T c9_b_y;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_c_b;
  real_T c9_c_y;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_d_b;
  real_T c9_d_y;
  real_T c9_a;
  real_T c9_e_b;
  real_T c9_e_y;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_n_x;
  real_T c9_f_b;
  real_T c9_f_y;
  real_T c9_o_x;
  real_T c9_p_x;
  real_T c9_g_b;
  real_T c9_g_y;
  real_T c9_q_x;
  real_T c9_r_x;
  real_T c9_h_b;
  real_T c9_h_y;
  real_T c9_s_x;
  real_T c9_t_x;
  real_T c9_i_b;
  real_T c9_i_y;
  real_T c9_b_a;
  real_T c9_j_b;
  real_T c9_j_y;
  real_T c9_u_x;
  real_T c9_v_x;
  real_T c9_w_x;
  real_T c9_x_x;
  real_T c9_c_a;
  real_T c9_k_b;
  real_T c9_k_y;
  real_T c9_d_a;
  real_T c9_l_y;
  real_T c9_y_x;
  real_T c9_ab_x;
  real_T c9_l_b;
  real_T c9_m_y;
  real_T c9_bb_x;
  real_T c9_cb_x;
  real_T c9_m_b;
  real_T c9_n_y;
  real_T c9_db_x;
  real_T c9_eb_x;
  real_T c9_n_b;
  real_T c9_o_y;
  real_T c9_fb_x;
  real_T c9_gb_x;
  real_T c9_o_b;
  real_T c9_p_y;
  real_T c9_hb_x;
  real_T c9_ib_x;
  real_T c9_e_a;
  real_T c9_q_y;
  real_T c9_jb_x;
  real_T c9_kb_x;
  real_T c9_lb_x;
  real_T c9_mb_x;
  real_T c9_p_b;
  real_T c9_r_y;
  real_T c9_nb_x;
  real_T c9_ob_x;
  real_T c9_q_b;
  real_T c9_s_y;
  real_T c9_pb_x;
  real_T c9_qb_x;
  real_T c9_r_b;
  real_T c9_t_y;
  real_T c9_rb_x;
  real_T c9_sb_x;
  real_T c9_s_b;
  real_T c9_u_y;
  real_T c9_f_a;
  real_T c9_t_b;
  real_T c9_v_y;
  real_T c9_tb_x;
  real_T c9_ub_x;
  real_T c9_vb_x;
  real_T c9_wb_x;
  real_T c9_u_b;
  real_T c9_w_y;
  real_T c9_xb_x;
  real_T c9_yb_x;
  real_T c9_v_b;
  real_T c9_x_y;
  real_T c9_ac_x;
  real_T c9_bc_x;
  real_T c9_w_b;
  real_T c9_y_y;
  real_T c9_cc_x;
  real_T c9_dc_x;
  real_T c9_x_b;
  real_T c9_ab_y;
  real_T c9_g_a;
  real_T c9_y_b;
  real_T c9_bb_y;
  real_T c9_ec_x;
  real_T c9_fc_x;
  real_T c9_gc_x;
  real_T c9_hc_x;
  real_T c9_h_a;
  real_T c9_ab_b;
  real_T c9_cb_y;
  real_T c9_i_a;
  real_T c9_db_y;
  real_T c9_ic_x;
  real_T c9_jc_x;
  real_T c9_kc_x;
  real_T c9_lc_x;
  real_T c9_mc_x;
  real_T c9_nc_x;
  real_T c9_oc_x;
  real_T c9_pc_x;
  int32_T c9_i3;
  int32_T c9_i4;
  static real_T c9_dv1[4] = { 0.0, -1.0, 0.0, 0.0 };

  real_T c9_qc_x;
  real_T c9_rc_x;
  real_T c9_bb_b;
  real_T c9_sc_x;
  real_T c9_tc_x;
  real_T c9_cb_b;
  real_T c9_dv2[6];
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  real_T c9_j_a[24];
  int32_T c9_i10;
  real_T c9_db_b[6];
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  real_T c9_C[4];
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i20;
  real_T *c9_b_q1;
  real_T *c9_b_q2;
  real_T *c9_b_q3;
  real_T *c9_b_q4;
  real_T (*c9_b_T2)[4];
  c9_b_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c9_b_T2 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_q1;
  c9_b_hoistedGlobal = *c9_b_q2;
  c9_c_hoistedGlobal = *c9_b_q3;
  c9_d_hoistedGlobal = *c9_b_q4;
  c9_q1 = c9_hoistedGlobal;
  c9_q2 = c9_b_hoistedGlobal;
  c9_q3 = c9_c_hoistedGlobal;
  c9_q4 = c9_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_f2, 0U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_d2, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_a2, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c9_a3, 3U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_a4, 4U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_a5, 5U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_a6, 6U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c9_Jg2, 7U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_fy2, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_fz2, 9U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_F, 10U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 11U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 12U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c9_q1, 13U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_q2, 14U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_q3, 15U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_q4, 16U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c9_T2, 17U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_f2 = 3.2;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_d2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_a5 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_a6 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
  c9_x = c9_q2;
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarCos(c9_b_x);
  c9_c_x = c9_q3 + c9_q4;
  c9_d_x = c9_c_x;
  c9_d_x = muDoubleScalarCos(c9_d_x);
  c9_b = c9_d_x;
  c9_y = 0.59 * c9_b;
  c9_e_x = c9_q3 + c9_q4;
  c9_f_x = c9_e_x;
  c9_f_x = muDoubleScalarCos(c9_f_x);
  c9_b_b = c9_f_x;
  c9_b_y = 0.59 * c9_b_b;
  c9_g_x = c9_q3;
  c9_h_x = c9_g_x;
  c9_h_x = muDoubleScalarCos(c9_h_x);
  c9_c_b = c9_h_x;
  c9_c_y = 0.8862 * c9_c_b;
  c9_i_x = c9_q3;
  c9_j_x = c9_i_x;
  c9_j_x = muDoubleScalarCos(c9_j_x);
  c9_d_b = c9_j_x;
  c9_d_y = 1.5 * c9_d_b;
  c9_a = -c9_b_x;
  c9_e_b = (((c9_a2 + c9_y) + c9_b_y) + c9_c_y) + c9_d_y;
  c9_e_y = c9_a * c9_e_b;
  c9_k_x = c9_q2;
  c9_l_x = c9_k_x;
  c9_l_x = muDoubleScalarSin(c9_l_x);
  c9_m_x = c9_q3 + c9_q4;
  c9_n_x = c9_m_x;
  c9_n_x = muDoubleScalarSin(c9_n_x);
  c9_f_b = c9_n_x;
  c9_f_y = 0.59 * c9_f_b;
  c9_o_x = c9_q3 + c9_q4;
  c9_p_x = c9_o_x;
  c9_p_x = muDoubleScalarSin(c9_p_x);
  c9_g_b = c9_p_x;
  c9_g_y = 0.59 * c9_g_b;
  c9_q_x = c9_q3;
  c9_r_x = c9_q_x;
  c9_r_x = muDoubleScalarSin(c9_r_x);
  c9_h_b = c9_r_x;
  c9_h_y = 0.8862 * c9_h_b;
  c9_s_x = c9_q3;
  c9_t_x = c9_s_x;
  c9_t_x = muDoubleScalarSin(c9_t_x);
  c9_i_b = c9_t_x;
  c9_i_y = 1.5 * c9_i_b;
  c9_b_a = c9_l_x;
  c9_j_b = ((c9_f_y + c9_g_y) + c9_h_y) + c9_i_y;
  c9_j_y = c9_b_a * c9_j_b;
  c9_u_x = c9_q3 + c9_q4;
  c9_v_x = c9_u_x;
  c9_v_x = muDoubleScalarSin(c9_v_x);
  c9_w_x = c9_q2;
  c9_x_x = c9_w_x;
  c9_x_x = muDoubleScalarSin(c9_x_x);
  c9_c_a = c9_v_x;
  c9_k_b = c9_x_x;
  c9_k_y = c9_c_a * c9_k_b;
  c9_d_a = c9_k_y;
  c9_l_y = c9_d_a * 1.18;
  c9_y_x = c9_q3 + c9_q4;
  c9_ab_x = c9_y_x;
  c9_ab_x = muDoubleScalarCos(c9_ab_x);
  c9_l_b = c9_ab_x;
  c9_m_y = -0.59 * c9_l_b;
  c9_bb_x = c9_q3 + c9_q4;
  c9_cb_x = c9_bb_x;
  c9_cb_x = muDoubleScalarCos(c9_cb_x);
  c9_m_b = c9_cb_x;
  c9_n_y = 0.59 * c9_m_b;
  c9_db_x = c9_q3;
  c9_eb_x = c9_db_x;
  c9_eb_x = muDoubleScalarCos(c9_eb_x);
  c9_n_b = c9_eb_x;
  c9_o_y = 0.8862 * c9_n_b;
  c9_fb_x = c9_q3;
  c9_gb_x = c9_fb_x;
  c9_gb_x = muDoubleScalarCos(c9_gb_x);
  c9_o_b = c9_gb_x;
  c9_p_y = 1.5 * c9_o_b;
  c9_hb_x = c9_q3 + c9_q4;
  c9_ib_x = c9_hb_x;
  c9_ib_x = muDoubleScalarCos(c9_ib_x);
  c9_e_a = -c9_ib_x;
  c9_q_y = c9_e_a * 1.18;
  c9_jb_x = c9_q2;
  c9_kb_x = c9_jb_x;
  c9_kb_x = muDoubleScalarSin(c9_kb_x);
  c9_lb_x = c9_q3 + c9_q4;
  c9_mb_x = c9_lb_x;
  c9_mb_x = muDoubleScalarCos(c9_mb_x);
  c9_p_b = c9_mb_x;
  c9_r_y = 0.59 * c9_p_b;
  c9_nb_x = c9_q3 + c9_q4;
  c9_ob_x = c9_nb_x;
  c9_ob_x = muDoubleScalarCos(c9_ob_x);
  c9_q_b = c9_ob_x;
  c9_s_y = 0.59 * c9_q_b;
  c9_pb_x = c9_q3;
  c9_qb_x = c9_pb_x;
  c9_qb_x = muDoubleScalarCos(c9_qb_x);
  c9_r_b = c9_qb_x;
  c9_t_y = 0.8862 * c9_r_b;
  c9_rb_x = c9_q3;
  c9_sb_x = c9_rb_x;
  c9_sb_x = muDoubleScalarCos(c9_sb_x);
  c9_s_b = c9_sb_x;
  c9_u_y = 1.5 * c9_s_b;
  c9_f_a = -c9_kb_x;
  c9_t_b = (((c9_a2 + c9_r_y) + c9_s_y) + c9_t_y) + c9_u_y;
  c9_v_y = c9_f_a * c9_t_b;
  c9_tb_x = c9_q2;
  c9_ub_x = c9_tb_x;
  c9_ub_x = muDoubleScalarCos(c9_ub_x);
  c9_vb_x = c9_q3 + c9_q4;
  c9_wb_x = c9_vb_x;
  c9_wb_x = muDoubleScalarSin(c9_wb_x);
  c9_u_b = c9_wb_x;
  c9_w_y = 0.59 * c9_u_b;
  c9_xb_x = c9_q3 + c9_q4;
  c9_yb_x = c9_xb_x;
  c9_yb_x = muDoubleScalarSin(c9_yb_x);
  c9_v_b = c9_yb_x;
  c9_x_y = 0.59 * c9_v_b;
  c9_ac_x = c9_q3;
  c9_bc_x = c9_ac_x;
  c9_bc_x = muDoubleScalarSin(c9_bc_x);
  c9_w_b = c9_bc_x;
  c9_y_y = 0.8862 * c9_w_b;
  c9_cc_x = c9_q3;
  c9_dc_x = c9_cc_x;
  c9_dc_x = muDoubleScalarSin(c9_dc_x);
  c9_x_b = c9_dc_x;
  c9_ab_y = 1.5 * c9_x_b;
  c9_g_a = -c9_ub_x;
  c9_y_b = ((c9_w_y + c9_x_y) + c9_y_y) + c9_ab_y;
  c9_bb_y = c9_g_a * c9_y_b;
  c9_ec_x = c9_q3 + c9_q4;
  c9_fc_x = c9_ec_x;
  c9_fc_x = muDoubleScalarSin(c9_fc_x);
  c9_gc_x = c9_q2;
  c9_hc_x = c9_gc_x;
  c9_hc_x = muDoubleScalarCos(c9_hc_x);
  c9_h_a = -c9_fc_x;
  c9_ab_b = c9_hc_x;
  c9_cb_y = c9_h_a * c9_ab_b;
  c9_i_a = c9_cb_y;
  c9_db_y = c9_i_a * 1.18;
  c9_ic_x = c9_q2;
  c9_jc_x = c9_ic_x;
  c9_jc_x = muDoubleScalarCos(c9_jc_x);
  c9_kc_x = c9_q2;
  c9_lc_x = c9_kc_x;
  c9_lc_x = muDoubleScalarCos(c9_lc_x);
  c9_mc_x = c9_q2;
  c9_nc_x = c9_mc_x;
  c9_nc_x = muDoubleScalarSin(c9_nc_x);
  c9_oc_x = c9_q2;
  c9_pc_x = c9_oc_x;
  c9_pc_x = muDoubleScalarSin(c9_pc_x);
  c9_Jg2[0] = 0.0;
  c9_Jg2[6] = c9_e_y;
  c9_Jg2[12] = c9_j_y;
  c9_Jg2[18] = c9_l_y;
  c9_Jg2[1] = 0.0;
  c9_Jg2[7] = 0.0;
  c9_Jg2[13] = ((c9_m_y - c9_n_y) - c9_o_y) - c9_p_y;
  c9_Jg2[19] = c9_q_y;
  c9_Jg2[2] = 1.0;
  c9_Jg2[8] = c9_v_y;
  c9_Jg2[14] = c9_bb_y;
  c9_Jg2[20] = c9_db_y;
  c9_Jg2[3] = 0.0;
  c9_Jg2[9] = 0.0;
  c9_Jg2[15] = c9_jc_x;
  c9_Jg2[21] = c9_lc_x;
  c9_i3 = 0;
  for (c9_i4 = 0; c9_i4 < 4; c9_i4++) {
    c9_Jg2[c9_i3 + 4] = c9_dv1[c9_i4];
    c9_i3 += 6;
  }

  c9_Jg2[5] = 0.0;
  c9_Jg2[11] = 0.0;
  c9_Jg2[17] = c9_nc_x;
  c9_Jg2[23] = c9_pc_x;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
  c9_qc_x = c9_q1;
  c9_rc_x = c9_qc_x;
  c9_rc_x = muDoubleScalarSin(c9_rc_x);
  c9_bb_b = c9_rc_x;
  c9_fy2 = 3.2 * c9_bb_b;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 19);
  c9_sc_x = c9_q1;
  c9_tc_x = c9_sc_x;
  c9_tc_x = muDoubleScalarCos(c9_tc_x);
  c9_cb_b = c9_tc_x;
  c9_fz2 = 3.2 * c9_cb_b;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
  c9_dv2[0] = 0.0;
  c9_dv2[1] = c9_fy2;
  c9_dv2[2] = c9_fz2;
  c9_dv2[3] = 0.0;
  c9_dv2[4] = 0.0;
  c9_dv2[5] = 0.0;
  for (c9_i5 = 0; c9_i5 < 6; c9_i5++) {
    c9_F[c9_i5] = c9_dv2[c9_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
  c9_i6 = 0;
  for (c9_i7 = 0; c9_i7 < 6; c9_i7++) {
    c9_i8 = 0;
    for (c9_i9 = 0; c9_i9 < 4; c9_i9++) {
      c9_j_a[c9_i9 + c9_i6] = c9_Jg2[c9_i8 + c9_i7];
      c9_i8 += 6;
    }

    c9_i6 += 4;
  }

  for (c9_i10 = 0; c9_i10 < 6; c9_i10++) {
    c9_db_b[c9_i10] = c9_F[c9_i10];
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  for (c9_i11 = 0; c9_i11 < 4; c9_i11++) {
    c9_T2[c9_i11] = 0.0;
  }

  for (c9_i12 = 0; c9_i12 < 4; c9_i12++) {
    c9_T2[c9_i12] = 0.0;
  }

  for (c9_i13 = 0; c9_i13 < 4; c9_i13++) {
    c9_C[c9_i13] = c9_T2[c9_i13];
  }

  for (c9_i14 = 0; c9_i14 < 4; c9_i14++) {
    c9_T2[c9_i14] = c9_C[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 4; c9_i15++) {
    c9_C[c9_i15] = c9_T2[c9_i15];
  }

  for (c9_i16 = 0; c9_i16 < 4; c9_i16++) {
    c9_T2[c9_i16] = c9_C[c9_i16];
  }

  for (c9_i17 = 0; c9_i17 < 4; c9_i17++) {
    c9_T2[c9_i17] = 0.0;
    c9_i18 = 0;
    for (c9_i19 = 0; c9_i19 < 6; c9_i19++) {
      c9_T2[c9_i17] += c9_j_a[c9_i18 + c9_i17] * c9_db_b[c9_i19];
      c9_i18 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -22);
  sf_debug_symbol_scope_pop();
  for (c9_i20 = 0; c9_i20 < 4; c9_i20++) {
    (*c9_b_T2)[c9_i20] = c9_T2[c9_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_SIMULACION_TORQUE
  (SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i21;
  real_T c9_b_inData[4];
  int32_T c9_i22;
  real_T c9_u[4];
  const mxArray *c9_y = NULL;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i21 = 0; c9_i21 < 4; c9_i21++) {
    c9_b_inData[c9_i21] = (*(real_T (*)[4])c9_inData)[c9_i21];
  }

  for (c9_i22 = 0; c9_i22 < 4; c9_i22++) {
    c9_u[c9_i22] = c9_b_inData[c9_i22];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_T2, const char_T *c9_identifier, real_T
  c9_y[4])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_T2), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_T2);
}

static void c9_b_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[4])
{
  real_T c9_dv3[4];
  int32_T c9_i23;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c9_i23 = 0; c9_i23 < 4; c9_i23++) {
    c9_y[c9_i23] = c9_dv3[c9_i23];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_T2;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[4];
  int32_T c9_i24;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_T2 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_T2), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_T2);
  for (c9_i24 = 0; c9_i24 < 4; c9_i24++) {
    (*(real_T (*)[4])c9_outData)[c9_i24] = c9_y[c9_i24];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i25;
  real_T c9_b_inData[6];
  int32_T c9_i26;
  real_T c9_u[6];
  const mxArray *c9_y = NULL;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i25 = 0; c9_i25 < 6; c9_i25++) {
    c9_b_inData[c9_i25] = (*(real_T (*)[6])c9_inData)[c9_i25];
  }

  for (c9_i26 = 0; c9_i26 < 6; c9_i26++) {
    c9_u[c9_i26] = c9_b_inData[c9_i26];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static void c9_d_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6])
{
  real_T c9_dv4[6];
  int32_T c9_i27;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c9_i27 = 0; c9_i27 < 6; c9_i27++) {
    c9_y[c9_i27] = c9_dv4[c9_i27];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_F;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[6];
  int32_T c9_i28;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_F = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_F), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_F);
  for (c9_i28 = 0; c9_i28 < 6; c9_i28++) {
    (*(real_T (*)[6])c9_outData)[c9_i28] = c9_y[c9_i28];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  real_T c9_b_inData[24];
  int32_T c9_i32;
  int32_T c9_i33;
  int32_T c9_i34;
  real_T c9_u[24];
  const mxArray *c9_y = NULL;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i29 = 0;
  for (c9_i30 = 0; c9_i30 < 4; c9_i30++) {
    for (c9_i31 = 0; c9_i31 < 6; c9_i31++) {
      c9_b_inData[c9_i31 + c9_i29] = (*(real_T (*)[24])c9_inData)[c9_i31 +
        c9_i29];
    }

    c9_i29 += 6;
  }

  c9_i32 = 0;
  for (c9_i33 = 0; c9_i33 < 4; c9_i33++) {
    for (c9_i34 = 0; c9_i34 < 6; c9_i34++) {
      c9_u[c9_i34 + c9_i32] = c9_b_inData[c9_i34 + c9_i32];
    }

    c9_i32 += 6;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[24])
{
  real_T c9_dv5[24];
  int32_T c9_i35;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv5, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c9_i35 = 0; c9_i35 < 24; c9_i35++) {
    c9_y[c9_i35] = c9_dv5[c9_i35];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_Jg2;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[24];
  int32_T c9_i36;
  int32_T c9_i37;
  int32_T c9_i38;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_Jg2 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Jg2), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Jg2);
  c9_i36 = 0;
  for (c9_i37 = 0; c9_i37 < 4; c9_i37++) {
    for (c9_i38 = 0; c9_i38 < 6; c9_i38++) {
      (*(real_T (*)[24])c9_outData)[c9_i38 + c9_i36] = c9_y[c9_i38 + c9_i36];
    }

    c9_i36 += 6;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_SIMULACION_TORQUE_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[16];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i39;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16));
  for (c9_i39 = 0; c9_i39 < 16; c9_i39++) {
    c9_r0 = &c9_info[c9_i39];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i39);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i39);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i39);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i39);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i39);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i39);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i39);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i39);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[16])
{
  c9_info[0].context = "";
  c9_info[0].name = "cos";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[0].fileTimeLo = 3359288576U;
  c9_info[0].fileTimeHi = 30108069U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c9_info[1].name = "eml_scalar_cos";
  c9_info[1].dominantType = "double";
  c9_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c9_info[1].fileTimeLo = 3519288576U;
  c9_info[1].fileTimeHi = 30108069U;
  c9_info[1].mFileTimeLo = 0U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context = "";
  c9_info[2].name = "mtimes";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[2].fileTimeLo = 2169964032U;
  c9_info[2].fileTimeHi = 30114358U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context = "";
  c9_info[3].name = "sin";
  c9_info[3].dominantType = "double";
  c9_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[3].fileTimeLo = 3799288576U;
  c9_info[3].fileTimeHi = 30108069U;
  c9_info[3].mFileTimeLo = 0U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c9_info[4].name = "eml_scalar_sin";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c9_info[4].fileTimeLo = 3659288576U;
  c9_info[4].fileTimeHi = 30108069U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[5].name = "eml_index_class";
  c9_info[5].dominantType = "";
  c9_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[5].fileTimeLo = 4079288576U;
  c9_info[5].fileTimeHi = 30108069U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[6].name = "eml_scalar_eg";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[6].fileTimeLo = 4259288576U;
  c9_info[6].fileTimeHi = 30108069U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[7].name = "eml_xgemm";
  c9_info[7].dominantType = "int32";
  c9_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[7].fileTimeLo = 3399288576U;
  c9_info[7].fileTimeHi = 30108069U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c9_info[8].name = "length";
  c9_info[8].dominantType = "double";
  c9_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c9_info[8].fileTimeLo = 3899288576U;
  c9_info[8].fileTimeHi = 30108069U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c9_info[9].name = "min";
  c9_info[9].dominantType = "double";
  c9_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[9].fileTimeLo = 3259288576U;
  c9_info[9].fileTimeHi = 30108069U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[10].name = "eml_min_or_max";
  c9_info[10].dominantType = "char";
  c9_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[10].fileTimeLo = 4179288576U;
  c9_info[10].fileTimeHi = 30108069U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[11].name = "eml_scalexp_alloc";
  c9_info[11].dominantType = "double";
  c9_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[11].fileTimeLo = 4259288576U;
  c9_info[11].fileTimeHi = 30108069U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[12].name = "eml_refblas_xgemm";
  c9_info[12].dominantType = "int32";
  c9_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[12].fileTimeLo = 4119288576U;
  c9_info[12].fileTimeHi = 30108069U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
  c9_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[13].name = "eml_index_minus";
  c9_info[13].dominantType = "int32";
  c9_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[13].fileTimeLo = 4079288576U;
  c9_info[13].fileTimeHi = 30108069U;
  c9_info[13].mFileTimeLo = 0U;
  c9_info[13].mFileTimeHi = 0U;
  c9_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[14].name = "eml_index_times";
  c9_info[14].dominantType = "int32";
  c9_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[14].fileTimeLo = 4099288576U;
  c9_info[14].fileTimeHi = 30108069U;
  c9_info[14].mFileTimeLo = 0U;
  c9_info[14].mFileTimeHi = 0U;
  c9_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[15].name = "eml_index_plus";
  c9_info[15].dominantType = "int32";
  c9_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[15].fileTimeLo = 4079288576U;
  c9_info[15].fileTimeHi = 30108069U;
  c9_info[15].mFileTimeLo = 0U;
  c9_info[15].mFileTimeHi = 0U;
}

static void c9_eml_scalar_eg(SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_mxArrayOutData, c9_y);
  return c9_mxArrayOutData;
}

static int32_T c9_f_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i40;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i40, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i40;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_g_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_SIMULACION_TORQUE, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_SIMULACION_TORQUE), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_SIMULACION_TORQUE);
  return c9_y;
}

static uint8_T c9_h_emlrt_marshallIn(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_SIMULACION_TORQUE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(451730331U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4139307543U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2305584999U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4017091651U);
}

mxArray *sf_c9_SIMULACION_TORQUE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(95505761U);
    pr[1] = (double)(2087048672U);
    pr[2] = (double)(1303018352U);
    pr[3] = (double)(2644315669U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c9_SIMULACION_TORQUE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"T2\",},{M[8],M[0],T\"is_active_c9_SIMULACION_TORQUE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_SIMULACION_TORQUE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
    chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMULACION_TORQUEMachineNumber_,
           9,
           1,
           1,
           5,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"T2");
          _SFD_SET_DATA_PROPS(1,1,1,0,"q1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"q4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1314);
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
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c9_q1;
          real_T *c9_q2;
          real_T *c9_q3;
          real_T *c9_q4;
          real_T (*c9_T2)[4];
          c9_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c9_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c9_T2 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_T2);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_q1);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_q2);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_q3);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_q4);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMULACION_TORQUEMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c9_SIMULACION_TORQUE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
  initialize_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_SIMULACION_TORQUE(void *chartInstanceVar)
{
  enable_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_SIMULACION_TORQUE(void *chartInstanceVar)
{
  disable_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_SIMULACION_TORQUE(void *chartInstanceVar)
{
  sf_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_SIMULACION_TORQUE(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_SIMULACION_TORQUE
    ((SFc9_SIMULACION_TORQUEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_SIMULACION_TORQUE();/* state var info */
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

extern void sf_internal_set_sim_state_c9_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_SIMULACION_TORQUE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_SIMULACION_TORQUE(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_SIMULACION_TORQUE(S);
}

static void sf_opaque_set_sim_state_c9_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_SIMULACION_TORQUE(S, st);
}

static void sf_opaque_terminate_c9_SIMULACION_TORQUE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_SIMULACION_TORQUEInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_SIMULACION_TORQUE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_SIMULACION_TORQUE((SFc9_SIMULACION_TORQUEInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",
                9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE",
      "SIMULACION_TORQUE",9,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SIMULACION_TORQUE",
        "SIMULACION_TORQUE",9,4);
      sf_mark_chart_reusable_outputs(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",9,
        1);
    }

    sf_set_rtw_dwork_info(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2425014012U));
  ssSetChecksum1(S,(586984887U));
  ssSetChecksum2(S,(440320802U));
  ssSetChecksum3(S,(568441837U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMULACION_TORQUE", "SIMULACION_TORQUE",9);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_SIMULACION_TORQUE(SimStruct *S)
{
  SFc9_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc9_SIMULACION_TORQUEInstanceStruct *)malloc(sizeof
    (SFc9_SIMULACION_TORQUEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_SIMULACION_TORQUEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_SIMULACION_TORQUE;
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

void c9_SIMULACION_TORQUE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_SIMULACION_TORQUE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_SIMULACION_TORQUE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
