/* Include files */

#include "blascompat32.h"
#include "SIMULACION_TORQUE_sfun.h"
#include "c11_SIMULACION_TORQUE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMULACION_TORQUE_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[17] = { "d2", "a2", "a3", "a4", "a5",
  "a6", "f1", "J", "fy1", "fz1", "F", "nargin", "nargout", "q2", "q3", "q4",
  "T1" };

/* Function Declarations */
static void initialize_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void initialize_params_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void enable_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void disable_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct *
  chartInstance);
static void c11_update_debugger_state_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void set_sim_state_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c11_st);
static void finalize_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void sf_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c11_chartstep_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void initSimStructsc11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_T1, const char_T *c11_identifier, real_T
  c11_y[4]);
static void c11_b_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_c_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_d_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6]);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_e_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[24]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[16]);
static void c11_eml_scalar_eg(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_f_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_g_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_SIMULACION_TORQUE, const
  char_T *c11_identifier);
static uint8_T c11_h_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_is_active_c11_SIMULACION_TORQUE = 0U;
}

static void initialize_params_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void enable_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[4];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T (*c11_T1)[4];
  c11_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2));
  for (c11_i0 = 0; c11_i0 < 4; c11_i0++) {
    c11_u[c11_i0] = (*c11_T1)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_SIMULACION_TORQUE;
  c11_b_u = c11_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y);
  return c11_st;
}

static void set_sim_state_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[4];
  int32_T c11_i1;
  real_T (*c11_T1)[4];
  c11_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)), "T1",
                       c11_dv0);
  for (c11_i1 = 0; c11_i1 < 4; c11_i1++) {
    (*c11_T1)[c11_i1] = c11_dv0[c11_i1];
  }

  chartInstance->c11_is_active_c11_SIMULACION_TORQUE = c11_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_SIMULACION_TORQUE");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_SIMULACION_TORQUE(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

static void sf_c11_SIMULACION_TORQUE(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  int32_T c11_i2;
  real_T *c11_q2;
  real_T *c11_q3;
  real_T *c11_q4;
  real_T (*c11_T1)[4];
  c11_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c11_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  for (c11_i2 = 0; c11_i2 < 4; c11_i2++) {
    _SFD_DATA_RANGE_CHECK((*c11_T1)[c11_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c11_q2, 1U);
  _SFD_DATA_RANGE_CHECK(*c11_q3, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_q4, 3U);
  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_SIMULACION_TORQUE(chartInstance);
  sf_debug_check_for_state_inconsistency(_SIMULACION_TORQUEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_chartstep_c11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_hoistedGlobal;
  real_T c11_q2;
  real_T c11_q3;
  real_T c11_q4;
  uint32_T c11_debug_family_var_map[17];
  real_T c11_d2;
  real_T c11_a2;
  real_T c11_a3;
  real_T c11_a4;
  real_T c11_a5;
  real_T c11_a6;
  real_T c11_f1;
  real_T c11_J[24];
  real_T c11_fy1;
  real_T c11_fz1;
  real_T c11_F[6];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  real_T c11_T1[4];
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_b;
  real_T c11_y;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_b_b;
  real_T c11_b_y;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_c_b;
  real_T c11_c_y;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_d_b;
  real_T c11_d_y;
  real_T c11_a;
  real_T c11_e_b;
  real_T c11_e_y;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_n_x;
  real_T c11_f_b;
  real_T c11_f_y;
  real_T c11_o_x;
  real_T c11_p_x;
  real_T c11_g_b;
  real_T c11_g_y;
  real_T c11_q_x;
  real_T c11_r_x;
  real_T c11_h_b;
  real_T c11_h_y;
  real_T c11_s_x;
  real_T c11_t_x;
  real_T c11_i_b;
  real_T c11_i_y;
  real_T c11_b_a;
  real_T c11_j_b;
  real_T c11_j_y;
  real_T c11_u_x;
  real_T c11_v_x;
  real_T c11_w_x;
  real_T c11_x_x;
  real_T c11_c_a;
  real_T c11_k_b;
  real_T c11_k_y;
  real_T c11_d_a;
  real_T c11_l_y;
  real_T c11_y_x;
  real_T c11_ab_x;
  real_T c11_l_b;
  real_T c11_m_y;
  real_T c11_bb_x;
  real_T c11_cb_x;
  real_T c11_m_b;
  real_T c11_n_y;
  real_T c11_db_x;
  real_T c11_eb_x;
  real_T c11_n_b;
  real_T c11_o_y;
  real_T c11_fb_x;
  real_T c11_gb_x;
  real_T c11_o_b;
  real_T c11_p_y;
  real_T c11_hb_x;
  real_T c11_ib_x;
  real_T c11_e_a;
  real_T c11_q_y;
  real_T c11_jb_x;
  real_T c11_kb_x;
  real_T c11_lb_x;
  real_T c11_mb_x;
  real_T c11_p_b;
  real_T c11_r_y;
  real_T c11_nb_x;
  real_T c11_ob_x;
  real_T c11_q_b;
  real_T c11_s_y;
  real_T c11_pb_x;
  real_T c11_qb_x;
  real_T c11_r_b;
  real_T c11_t_y;
  real_T c11_rb_x;
  real_T c11_sb_x;
  real_T c11_s_b;
  real_T c11_u_y;
  real_T c11_f_a;
  real_T c11_t_b;
  real_T c11_v_y;
  real_T c11_tb_x;
  real_T c11_ub_x;
  real_T c11_vb_x;
  real_T c11_wb_x;
  real_T c11_u_b;
  real_T c11_w_y;
  real_T c11_xb_x;
  real_T c11_yb_x;
  real_T c11_v_b;
  real_T c11_x_y;
  real_T c11_ac_x;
  real_T c11_bc_x;
  real_T c11_w_b;
  real_T c11_y_y;
  real_T c11_cc_x;
  real_T c11_dc_x;
  real_T c11_x_b;
  real_T c11_ab_y;
  real_T c11_g_a;
  real_T c11_y_b;
  real_T c11_bb_y;
  real_T c11_ec_x;
  real_T c11_fc_x;
  real_T c11_gc_x;
  real_T c11_hc_x;
  real_T c11_h_a;
  real_T c11_ab_b;
  real_T c11_cb_y;
  real_T c11_i_a;
  real_T c11_db_y;
  real_T c11_ic_x;
  real_T c11_jc_x;
  real_T c11_kc_x;
  real_T c11_lc_x;
  real_T c11_mc_x;
  real_T c11_nc_x;
  real_T c11_oc_x;
  real_T c11_pc_x;
  int32_T c11_i3;
  int32_T c11_i4;
  static real_T c11_dv1[4] = { 0.0, -1.0, 0.0, 0.0 };

  real_T c11_qc_x;
  real_T c11_rc_x;
  real_T c11_bb_b;
  real_T c11_sc_x;
  real_T c11_tc_x;
  real_T c11_cb_b;
  real_T c11_dv2[6];
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  real_T c11_j_a[24];
  int32_T c11_i10;
  real_T c11_db_b[6];
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  real_T c11_C[4];
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i20;
  real_T *c11_b_q2;
  real_T *c11_b_q3;
  real_T *c11_b_q4;
  real_T (*c11_b_T1)[4];
  c11_b_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_b_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c11_b_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *c11_b_q2;
  c11_b_hoistedGlobal = *c11_b_q3;
  c11_c_hoistedGlobal = *c11_b_q4;
  c11_q2 = c11_hoistedGlobal;
  c11_q3 = c11_b_hoistedGlobal;
  c11_q4 = c11_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 17U, 17U, c11_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c11_d2, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_a2, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c11_a3, 2U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_a4, 3U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_a5, 4U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_a6, 5U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_f1, 6U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c11_J, 7U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_fy1, 8U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_fz1, 9U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c11_F, 10U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargin, 11U,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargout, 12U,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c11_q2, 13U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_q3, 14U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_q4, 15U, c11_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c11_T1, 16U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 3);
  c11_d2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  c11_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_a5 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_a6 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_f1 = 3.9;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  c11_x = c11_q2;
  c11_b_x = c11_x;
  c11_b_x = muDoubleScalarCos(c11_b_x);
  c11_c_x = c11_q3 + c11_q4;
  c11_d_x = c11_c_x;
  c11_d_x = muDoubleScalarCos(c11_d_x);
  c11_b = c11_d_x;
  c11_y = 0.59 * c11_b;
  c11_e_x = c11_q3 + c11_q4;
  c11_f_x = c11_e_x;
  c11_f_x = muDoubleScalarCos(c11_f_x);
  c11_b_b = c11_f_x;
  c11_b_y = 0.59 * c11_b_b;
  c11_g_x = c11_q3;
  c11_h_x = c11_g_x;
  c11_h_x = muDoubleScalarCos(c11_h_x);
  c11_c_b = c11_h_x;
  c11_c_y = 0.8862 * c11_c_b;
  c11_i_x = c11_q3;
  c11_j_x = c11_i_x;
  c11_j_x = muDoubleScalarCos(c11_j_x);
  c11_d_b = c11_j_x;
  c11_d_y = 1.5 * c11_d_b;
  c11_a = -c11_b_x;
  c11_e_b = (((c11_a2 + c11_y) + c11_b_y) + c11_c_y) + c11_d_y;
  c11_e_y = c11_a * c11_e_b;
  c11_k_x = c11_q2;
  c11_l_x = c11_k_x;
  c11_l_x = muDoubleScalarSin(c11_l_x);
  c11_m_x = c11_q3 + c11_q4;
  c11_n_x = c11_m_x;
  c11_n_x = muDoubleScalarSin(c11_n_x);
  c11_f_b = c11_n_x;
  c11_f_y = 0.59 * c11_f_b;
  c11_o_x = c11_q3 + c11_q4;
  c11_p_x = c11_o_x;
  c11_p_x = muDoubleScalarSin(c11_p_x);
  c11_g_b = c11_p_x;
  c11_g_y = 0.59 * c11_g_b;
  c11_q_x = c11_q3;
  c11_r_x = c11_q_x;
  c11_r_x = muDoubleScalarSin(c11_r_x);
  c11_h_b = c11_r_x;
  c11_h_y = 0.8862 * c11_h_b;
  c11_s_x = c11_q3;
  c11_t_x = c11_s_x;
  c11_t_x = muDoubleScalarSin(c11_t_x);
  c11_i_b = c11_t_x;
  c11_i_y = 1.5 * c11_i_b;
  c11_b_a = c11_l_x;
  c11_j_b = ((c11_f_y + c11_g_y) + c11_h_y) + c11_i_y;
  c11_j_y = c11_b_a * c11_j_b;
  c11_u_x = c11_q3 + c11_q4;
  c11_v_x = c11_u_x;
  c11_v_x = muDoubleScalarSin(c11_v_x);
  c11_w_x = c11_q2;
  c11_x_x = c11_w_x;
  c11_x_x = muDoubleScalarSin(c11_x_x);
  c11_c_a = c11_v_x;
  c11_k_b = c11_x_x;
  c11_k_y = c11_c_a * c11_k_b;
  c11_d_a = c11_k_y;
  c11_l_y = c11_d_a * 1.18;
  c11_y_x = c11_q3 + c11_q4;
  c11_ab_x = c11_y_x;
  c11_ab_x = muDoubleScalarCos(c11_ab_x);
  c11_l_b = c11_ab_x;
  c11_m_y = -0.59 * c11_l_b;
  c11_bb_x = c11_q3 + c11_q4;
  c11_cb_x = c11_bb_x;
  c11_cb_x = muDoubleScalarCos(c11_cb_x);
  c11_m_b = c11_cb_x;
  c11_n_y = 0.59 * c11_m_b;
  c11_db_x = c11_q3;
  c11_eb_x = c11_db_x;
  c11_eb_x = muDoubleScalarCos(c11_eb_x);
  c11_n_b = c11_eb_x;
  c11_o_y = 0.8862 * c11_n_b;
  c11_fb_x = c11_q3;
  c11_gb_x = c11_fb_x;
  c11_gb_x = muDoubleScalarCos(c11_gb_x);
  c11_o_b = c11_gb_x;
  c11_p_y = 1.5 * c11_o_b;
  c11_hb_x = c11_q3 + c11_q4;
  c11_ib_x = c11_hb_x;
  c11_ib_x = muDoubleScalarCos(c11_ib_x);
  c11_e_a = -c11_ib_x;
  c11_q_y = c11_e_a * 1.18;
  c11_jb_x = c11_q2;
  c11_kb_x = c11_jb_x;
  c11_kb_x = muDoubleScalarSin(c11_kb_x);
  c11_lb_x = c11_q3 + c11_q4;
  c11_mb_x = c11_lb_x;
  c11_mb_x = muDoubleScalarCos(c11_mb_x);
  c11_p_b = c11_mb_x;
  c11_r_y = 0.59 * c11_p_b;
  c11_nb_x = c11_q3 + c11_q4;
  c11_ob_x = c11_nb_x;
  c11_ob_x = muDoubleScalarCos(c11_ob_x);
  c11_q_b = c11_ob_x;
  c11_s_y = 0.59 * c11_q_b;
  c11_pb_x = c11_q3;
  c11_qb_x = c11_pb_x;
  c11_qb_x = muDoubleScalarCos(c11_qb_x);
  c11_r_b = c11_qb_x;
  c11_t_y = 0.8862 * c11_r_b;
  c11_rb_x = c11_q3;
  c11_sb_x = c11_rb_x;
  c11_sb_x = muDoubleScalarCos(c11_sb_x);
  c11_s_b = c11_sb_x;
  c11_u_y = 1.5 * c11_s_b;
  c11_f_a = -c11_kb_x;
  c11_t_b = (((c11_a2 + c11_r_y) + c11_s_y) + c11_t_y) + c11_u_y;
  c11_v_y = c11_f_a * c11_t_b;
  c11_tb_x = c11_q2;
  c11_ub_x = c11_tb_x;
  c11_ub_x = muDoubleScalarCos(c11_ub_x);
  c11_vb_x = c11_q3 + c11_q4;
  c11_wb_x = c11_vb_x;
  c11_wb_x = muDoubleScalarSin(c11_wb_x);
  c11_u_b = c11_wb_x;
  c11_w_y = 0.59 * c11_u_b;
  c11_xb_x = c11_q3 + c11_q4;
  c11_yb_x = c11_xb_x;
  c11_yb_x = muDoubleScalarSin(c11_yb_x);
  c11_v_b = c11_yb_x;
  c11_x_y = 0.59 * c11_v_b;
  c11_ac_x = c11_q3;
  c11_bc_x = c11_ac_x;
  c11_bc_x = muDoubleScalarSin(c11_bc_x);
  c11_w_b = c11_bc_x;
  c11_y_y = 0.8862 * c11_w_b;
  c11_cc_x = c11_q3;
  c11_dc_x = c11_cc_x;
  c11_dc_x = muDoubleScalarSin(c11_dc_x);
  c11_x_b = c11_dc_x;
  c11_ab_y = 1.5 * c11_x_b;
  c11_g_a = -c11_ub_x;
  c11_y_b = ((c11_w_y + c11_x_y) + c11_y_y) + c11_ab_y;
  c11_bb_y = c11_g_a * c11_y_b;
  c11_ec_x = c11_q3 + c11_q4;
  c11_fc_x = c11_ec_x;
  c11_fc_x = muDoubleScalarSin(c11_fc_x);
  c11_gc_x = c11_q2;
  c11_hc_x = c11_gc_x;
  c11_hc_x = muDoubleScalarCos(c11_hc_x);
  c11_h_a = -c11_fc_x;
  c11_ab_b = c11_hc_x;
  c11_cb_y = c11_h_a * c11_ab_b;
  c11_i_a = c11_cb_y;
  c11_db_y = c11_i_a * 1.18;
  c11_ic_x = c11_q2;
  c11_jc_x = c11_ic_x;
  c11_jc_x = muDoubleScalarCos(c11_jc_x);
  c11_kc_x = c11_q2;
  c11_lc_x = c11_kc_x;
  c11_lc_x = muDoubleScalarCos(c11_lc_x);
  c11_mc_x = c11_q2;
  c11_nc_x = c11_mc_x;
  c11_nc_x = muDoubleScalarSin(c11_nc_x);
  c11_oc_x = c11_q2;
  c11_pc_x = c11_oc_x;
  c11_pc_x = muDoubleScalarSin(c11_pc_x);
  c11_J[0] = 0.0;
  c11_J[6] = c11_e_y;
  c11_J[12] = c11_j_y;
  c11_J[18] = c11_l_y;
  c11_J[1] = 0.0;
  c11_J[7] = 0.0;
  c11_J[13] = ((c11_m_y - c11_n_y) - c11_o_y) - c11_p_y;
  c11_J[19] = c11_q_y;
  c11_J[2] = 1.0;
  c11_J[8] = c11_v_y;
  c11_J[14] = c11_bb_y;
  c11_J[20] = c11_db_y;
  c11_J[3] = 0.0;
  c11_J[9] = 0.0;
  c11_J[15] = c11_jc_x;
  c11_J[21] = c11_lc_x;
  c11_i3 = 0;
  for (c11_i4 = 0; c11_i4 < 4; c11_i4++) {
    c11_J[c11_i3 + 4] = c11_dv1[c11_i4];
    c11_i3 += 6;
  }

  c11_J[5] = 0.0;
  c11_J[11] = 0.0;
  c11_J[17] = c11_nc_x;
  c11_J[23] = c11_pc_x;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 21);
  c11_qc_x = c11_q4;
  c11_rc_x = c11_qc_x;
  c11_rc_x = muDoubleScalarSin(c11_rc_x);
  c11_bb_b = c11_rc_x;
  c11_fy1 = 3.9 * c11_bb_b;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 22);
  c11_sc_x = c11_q4;
  c11_tc_x = c11_sc_x;
  c11_tc_x = muDoubleScalarCos(c11_tc_x);
  c11_cb_b = c11_tc_x;
  c11_fz1 = 3.9 * c11_cb_b;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 24);
  c11_dv2[0] = 0.0;
  c11_dv2[1] = c11_fy1;
  c11_dv2[2] = c11_fz1;
  c11_dv2[3] = 0.0;
  c11_dv2[4] = 0.0;
  c11_dv2[5] = 0.0;
  for (c11_i5 = 0; c11_i5 < 6; c11_i5++) {
    c11_F[c11_i5] = c11_dv2[c11_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 25);
  c11_i6 = 0;
  for (c11_i7 = 0; c11_i7 < 6; c11_i7++) {
    c11_i8 = 0;
    for (c11_i9 = 0; c11_i9 < 4; c11_i9++) {
      c11_j_a[c11_i9 + c11_i6] = c11_J[c11_i8 + c11_i7];
      c11_i8 += 6;
    }

    c11_i6 += 4;
  }

  for (c11_i10 = 0; c11_i10 < 6; c11_i10++) {
    c11_db_b[c11_i10] = c11_F[c11_i10];
  }

  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i11 = 0; c11_i11 < 4; c11_i11++) {
    c11_T1[c11_i11] = 0.0;
  }

  for (c11_i12 = 0; c11_i12 < 4; c11_i12++) {
    c11_T1[c11_i12] = 0.0;
  }

  for (c11_i13 = 0; c11_i13 < 4; c11_i13++) {
    c11_C[c11_i13] = c11_T1[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 4; c11_i14++) {
    c11_T1[c11_i14] = c11_C[c11_i14];
  }

  for (c11_i15 = 0; c11_i15 < 4; c11_i15++) {
    c11_C[c11_i15] = c11_T1[c11_i15];
  }

  for (c11_i16 = 0; c11_i16 < 4; c11_i16++) {
    c11_T1[c11_i16] = c11_C[c11_i16];
  }

  for (c11_i17 = 0; c11_i17 < 4; c11_i17++) {
    c11_T1[c11_i17] = 0.0;
    c11_i18 = 0;
    for (c11_i19 = 0; c11_i19 < 6; c11_i19++) {
      c11_T1[c11_i17] += c11_j_a[c11_i18 + c11_i17] * c11_db_b[c11_i19];
      c11_i18 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -25);
  sf_debug_symbol_scope_pop();
  for (c11_i20 = 0; c11_i20 < 4; c11_i20++) {
    (*c11_b_T1)[c11_i20] = c11_T1[c11_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_SIMULACION_TORQUE
  (SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i21;
  real_T c11_b_inData[4];
  int32_T c11_i22;
  real_T c11_u[4];
  const mxArray *c11_y = NULL;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i21 = 0; c11_i21 < 4; c11_i21++) {
    c11_b_inData[c11_i21] = (*(real_T (*)[4])c11_inData)[c11_i21];
  }

  for (c11_i22 = 0; c11_i22 < 4; c11_i22++) {
    c11_u[c11_i22] = c11_b_inData[c11_i22];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_T1, const char_T *c11_identifier, real_T
  c11_y[4])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_T1), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_T1);
}

static void c11_b_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4])
{
  real_T c11_dv3[4];
  int32_T c11_i23;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c11_i23 = 0; c11_i23 < 4; c11_i23++) {
    c11_y[c11_i23] = c11_dv3[c11_i23];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_T1;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[4];
  int32_T c11_i24;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_T1 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_T1), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_T1);
  for (c11_i24 = 0; c11_i24 < 4; c11_i24++) {
    (*(real_T (*)[4])c11_outData)[c11_i24] = c11_y[c11_i24];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static real_T c11_c_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i25;
  real_T c11_b_inData[6];
  int32_T c11_i26;
  real_T c11_u[6];
  const mxArray *c11_y = NULL;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i25 = 0; c11_i25 < 6; c11_i25++) {
    c11_b_inData[c11_i25] = (*(real_T (*)[6])c11_inData)[c11_i25];
  }

  for (c11_i26 = 0; c11_i26 < 6; c11_i26++) {
    c11_u[c11_i26] = c11_b_inData[c11_i26];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static void c11_d_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[6])
{
  real_T c11_dv4[6];
  int32_T c11_i27;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c11_i27 = 0; c11_i27 < 6; c11_i27++) {
    c11_y[c11_i27] = c11_dv4[c11_i27];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_F;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[6];
  int32_T c11_i28;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_F = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_F), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_F);
  for (c11_i28 = 0; c11_i28 < 6; c11_i28++) {
    (*(real_T (*)[6])c11_outData)[c11_i28] = c11_y[c11_i28];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i29;
  int32_T c11_i30;
  int32_T c11_i31;
  real_T c11_b_inData[24];
  int32_T c11_i32;
  int32_T c11_i33;
  int32_T c11_i34;
  real_T c11_u[24];
  const mxArray *c11_y = NULL;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i29 = 0;
  for (c11_i30 = 0; c11_i30 < 4; c11_i30++) {
    for (c11_i31 = 0; c11_i31 < 6; c11_i31++) {
      c11_b_inData[c11_i31 + c11_i29] = (*(real_T (*)[24])c11_inData)[c11_i31 +
        c11_i29];
    }

    c11_i29 += 6;
  }

  c11_i32 = 0;
  for (c11_i33 = 0; c11_i33 < 4; c11_i33++) {
    for (c11_i34 = 0; c11_i34 < 6; c11_i34++) {
      c11_u[c11_i34 + c11_i32] = c11_b_inData[c11_i34 + c11_i32];
    }

    c11_i32 += 6;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static void c11_e_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[24])
{
  real_T c11_dv5[24];
  int32_T c11_i35;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv5, 1, 0, 0U, 1, 0U, 2, 6,
                4);
  for (c11_i35 = 0; c11_i35 < 24; c11_i35++) {
    c11_y[c11_i35] = c11_dv5[c11_i35];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_J;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[24];
  int32_T c11_i36;
  int32_T c11_i37;
  int32_T c11_i38;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_J = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_J), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_J);
  c11_i36 = 0;
  for (c11_i37 = 0; c11_i37 < 4; c11_i37++) {
    for (c11_i38 = 0; c11_i38 < 6; c11_i38++) {
      (*(real_T (*)[24])c11_outData)[c11_i38 + c11_i36] = c11_y[c11_i38 +
        c11_i36];
    }

    c11_i36 += 6;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_SIMULACION_TORQUE_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo;
  c11_ResolvedFunctionInfo c11_info[16];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i39;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16));
  for (c11_i39 = 0; c11_i39 < 16; c11_i39++) {
    c11_r0 = &c11_info[c11_i39];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context", "nameCaptureInfo",
                    c11_i39);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name", "nameCaptureInfo",
                    c11_i39);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i39);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)), "resolved",
                    "nameCaptureInfo", c11_i39);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c11_i39);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c11_i39);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c11_i39);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c11_i39);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[16])
{
  c11_info[0].context = "";
  c11_info[0].name = "cos";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[0].fileTimeLo = 3359288576U;
  c11_info[0].fileTimeHi = 30108069U;
  c11_info[0].mFileTimeLo = 0U;
  c11_info[0].mFileTimeHi = 0U;
  c11_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[1].name = "eml_scalar_cos";
  c11_info[1].dominantType = "double";
  c11_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c11_info[1].fileTimeLo = 3519288576U;
  c11_info[1].fileTimeHi = 30108069U;
  c11_info[1].mFileTimeLo = 0U;
  c11_info[1].mFileTimeHi = 0U;
  c11_info[2].context = "";
  c11_info[2].name = "mtimes";
  c11_info[2].dominantType = "double";
  c11_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[2].fileTimeLo = 2169964032U;
  c11_info[2].fileTimeHi = 30114358U;
  c11_info[2].mFileTimeLo = 0U;
  c11_info[2].mFileTimeHi = 0U;
  c11_info[3].context = "";
  c11_info[3].name = "sin";
  c11_info[3].dominantType = "double";
  c11_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[3].fileTimeLo = 3799288576U;
  c11_info[3].fileTimeHi = 30108069U;
  c11_info[3].mFileTimeLo = 0U;
  c11_info[3].mFileTimeHi = 0U;
  c11_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[4].name = "eml_scalar_sin";
  c11_info[4].dominantType = "double";
  c11_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c11_info[4].fileTimeLo = 3659288576U;
  c11_info[4].fileTimeHi = 30108069U;
  c11_info[4].mFileTimeLo = 0U;
  c11_info[4].mFileTimeHi = 0U;
  c11_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[5].name = "eml_index_class";
  c11_info[5].dominantType = "";
  c11_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[5].fileTimeLo = 4079288576U;
  c11_info[5].fileTimeHi = 30108069U;
  c11_info[5].mFileTimeLo = 0U;
  c11_info[5].mFileTimeHi = 0U;
  c11_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[6].name = "eml_scalar_eg";
  c11_info[6].dominantType = "double";
  c11_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[6].fileTimeLo = 4259288576U;
  c11_info[6].fileTimeHi = 30108069U;
  c11_info[6].mFileTimeLo = 0U;
  c11_info[6].mFileTimeHi = 0U;
  c11_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[7].name = "eml_xgemm";
  c11_info[7].dominantType = "int32";
  c11_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[7].fileTimeLo = 3399288576U;
  c11_info[7].fileTimeHi = 30108069U;
  c11_info[7].mFileTimeLo = 0U;
  c11_info[7].mFileTimeHi = 0U;
  c11_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c11_info[8].name = "length";
  c11_info[8].dominantType = "double";
  c11_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c11_info[8].fileTimeLo = 3899288576U;
  c11_info[8].fileTimeHi = 30108069U;
  c11_info[8].mFileTimeLo = 0U;
  c11_info[8].mFileTimeHi = 0U;
  c11_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c11_info[9].name = "min";
  c11_info[9].dominantType = "double";
  c11_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c11_info[9].fileTimeLo = 3259288576U;
  c11_info[9].fileTimeHi = 30108069U;
  c11_info[9].mFileTimeLo = 0U;
  c11_info[9].mFileTimeHi = 0U;
  c11_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c11_info[10].name = "eml_min_or_max";
  c11_info[10].dominantType = "char";
  c11_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c11_info[10].fileTimeLo = 4179288576U;
  c11_info[10].fileTimeHi = 30108069U;
  c11_info[10].mFileTimeLo = 0U;
  c11_info[10].mFileTimeHi = 0U;
  c11_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c11_info[11].name = "eml_scalexp_alloc";
  c11_info[11].dominantType = "double";
  c11_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c11_info[11].fileTimeLo = 4259288576U;
  c11_info[11].fileTimeHi = 30108069U;
  c11_info[11].mFileTimeLo = 0U;
  c11_info[11].mFileTimeHi = 0U;
  c11_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[12].name = "eml_refblas_xgemm";
  c11_info[12].dominantType = "int32";
  c11_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[12].fileTimeLo = 4119288576U;
  c11_info[12].fileTimeHi = 30108069U;
  c11_info[12].mFileTimeLo = 0U;
  c11_info[12].mFileTimeHi = 0U;
  c11_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[13].name = "eml_index_minus";
  c11_info[13].dominantType = "int32";
  c11_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c11_info[13].fileTimeLo = 4079288576U;
  c11_info[13].fileTimeHi = 30108069U;
  c11_info[13].mFileTimeLo = 0U;
  c11_info[13].mFileTimeHi = 0U;
  c11_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[14].name = "eml_index_times";
  c11_info[14].dominantType = "int32";
  c11_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c11_info[14].fileTimeLo = 4099288576U;
  c11_info[14].fileTimeHi = 30108069U;
  c11_info[14].mFileTimeLo = 0U;
  c11_info[14].mFileTimeHi = 0U;
  c11_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[15].name = "eml_index_plus";
  c11_info[15].dominantType = "int32";
  c11_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c11_info[15].fileTimeLo = 4079288576U;
  c11_info[15].fileTimeHi = 30108069U;
  c11_info[15].mFileTimeLo = 0U;
  c11_info[15].mFileTimeHi = 0U;
}

static void c11_eml_scalar_eg(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_mxArrayOutData, c11_y);
  return c11_mxArrayOutData;
}

static int32_T c11_f_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i40;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i40, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i40;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_g_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_SIMULACION_TORQUE, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_SIMULACION_TORQUE), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_SIMULACION_TORQUE);
  return c11_y;
}

static uint8_T c11_h_emlrt_marshallIn(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c11_SIMULACION_TORQUE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(941409813U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2774934821U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3697080897U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3564741772U);
}

mxArray *sf_c11_SIMULACION_TORQUE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2069646204U);
    pr[1] = (double)(467811579U);
    pr[2] = (double)(3770715826U);
    pr[3] = (double)(1807538732U);
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

static const mxArray *sf_get_sim_state_info_c11_SIMULACION_TORQUE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"T1\",},{M[8],M[0],T\"is_active_c11_SIMULACION_TORQUE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_SIMULACION_TORQUE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
    chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMULACION_TORQUEMachineNumber_,
           11,
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
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c11_q2;
          real_T *c11_q3;
          real_T *c11_q4;
          real_T (*c11_T1)[4];
          c11_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c11_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c11_T1 = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c11_T1);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_q2);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_q3);
          _SFD_SET_DATA_VALUE_PTR(3U, c11_q4);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMULACION_TORQUEMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c11_SIMULACION_TORQUE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
  initialize_c11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_SIMULACION_TORQUE(void *chartInstanceVar)
{
  enable_c11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_SIMULACION_TORQUE(void *chartInstanceVar)
{
  disable_c11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_SIMULACION_TORQUE(void *chartInstanceVar)
{
  sf_c11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_SIMULACION_TORQUE(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_SIMULACION_TORQUE
    ((SFc11_SIMULACION_TORQUEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_SIMULACION_TORQUE();/* state var info */
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

extern void sf_internal_set_sim_state_c11_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_SIMULACION_TORQUE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_SIMULACION_TORQUE(SimStruct* S)
{
  return sf_internal_get_sim_state_c11_SIMULACION_TORQUE(S);
}

static void sf_opaque_set_sim_state_c11_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c11_SIMULACION_TORQUE(S, st);
}

static void sf_opaque_terminate_c11_SIMULACION_TORQUE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_SIMULACION_TORQUEInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_SIMULACION_TORQUE((SFc11_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_SIMULACION_TORQUE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_SIMULACION_TORQUE
      ((SFc11_SIMULACION_TORQUEInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",
                11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE",
      "SIMULACION_TORQUE",11,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SIMULACION_TORQUE",
        "SIMULACION_TORQUE",11,3);
      sf_mark_chart_reusable_outputs(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",
        11,1);
    }

    sf_set_rtw_dwork_info(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1912477577U));
  ssSetChecksum1(S,(3151277819U));
  ssSetChecksum2(S,(3964611582U));
  ssSetChecksum3(S,(2437866188U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c11_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMULACION_TORQUE", "SIMULACION_TORQUE",11);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_SIMULACION_TORQUE(SimStruct *S)
{
  SFc11_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc11_SIMULACION_TORQUEInstanceStruct *)malloc(sizeof
    (SFc11_SIMULACION_TORQUEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_SIMULACION_TORQUEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_SIMULACION_TORQUE;
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

void c11_SIMULACION_TORQUE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_SIMULACION_TORQUE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_SIMULACION_TORQUE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
