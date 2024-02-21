/* Include files */

#include "blascompat32.h"
#include "SIMULACION_TORQUE_sfun.h"
#include "c2_SIMULACION_TORQUE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMULACION_TORQUE_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[16] = { "d2", "a2", "a3", "a4", "a5",
  "a6", "H", "nargin", "nargout", "q1", "q2", "q3", "q4", "MGD", "yz", "rt" };

/* Function Declarations */
static void initialize_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void initialize_params_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void enable_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void disable_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void set_sim_state_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void sf_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void initSimStructsc2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_rt, const char_T *c2_identifier, real_T
  c2_y[5]);
static void c2_b_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_yz, const char_T *c2_identifier, real_T
  c2_y[2]);
static void c2_d_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_MGD, const char_T *c2_identifier, real_T
  c2_y[16]);
static void c2_f_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_h_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_i_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_SIMULACION_TORQUE, const
  char_T *c2_identifier);
static uint8_T c2_j_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_SIMULACION_TORQUE = 0U;
}

static void initialize_params_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void enable_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[16];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[5];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  real_T c2_c_u[2];
  const mxArray *c2_d_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T (*c2_yz)[2];
  real_T (*c2_rt)[5];
  real_T (*c2_MGD)[16];
  c2_rt = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_yz = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4));
  for (c2_i0 = 0; c2_i0 < 16; c2_i0++) {
    c2_u[c2_i0] = (*c2_MGD)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 5; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_rt)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_c_u[c2_i2] = (*c2_yz)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_SIMULACION_TORQUE;
  c2_d_u = c2_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[16];
  int32_T c2_i3;
  real_T c2_dv1[5];
  int32_T c2_i4;
  real_T c2_dv2[2];
  int32_T c2_i5;
  real_T (*c2_MGD)[16];
  real_T (*c2_yz)[2];
  real_T (*c2_rt)[5];
  c2_rt = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_yz = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "MGD", c2_dv0);
  for (c2_i3 = 0; c2_i3 < 16; c2_i3++) {
    (*c2_MGD)[c2_i3] = c2_dv0[c2_i3];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "rt",
                      c2_dv1);
  for (c2_i4 = 0; c2_i4 < 5; c2_i4++) {
    (*c2_rt)[c2_i4] = c2_dv1[c2_i4];
  }

  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)), "yz",
                        c2_dv2);
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    (*c2_yz)[c2_i5] = c2_dv2[c2_i5];
  }

  chartInstance->c2_is_active_c2_SIMULACION_TORQUE = c2_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_active_c2_SIMULACION_TORQUE");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_SIMULACION_TORQUE(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

static void sf_c2_SIMULACION_TORQUE(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  real_T *c2_q1;
  real_T *c2_q2;
  real_T *c2_q3;
  real_T *c2_q4;
  real_T (*c2_rt)[5];
  real_T (*c2_yz)[2];
  real_T (*c2_MGD)[16];
  c2_rt = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_yz = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_q1, 0U);
  for (c2_i6 = 0; c2_i6 < 16; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*c2_MGD)[c2_i6], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_q2, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_q3, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_q4, 4U);
  for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_yz)[c2_i7], 5U);
  }

  for (c2_i8 = 0; c2_i8 < 5; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((*c2_rt)[c2_i8], 6U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_SIMULACION_TORQUE(chartInstance);
  sf_debug_check_for_state_inconsistency(_SIMULACION_TORQUEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_q1;
  real_T c2_q2;
  real_T c2_q3;
  real_T c2_q4;
  uint32_T c2_debug_family_var_map[16];
  real_T c2_d2;
  real_T c2_a2;
  real_T c2_a3;
  real_T c2_a4;
  real_T c2_a5;
  real_T c2_a6;
  real_T c2_H[16];
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 3.0;
  real_T c2_MGD[16];
  real_T c2_yz[2];
  real_T c2_rt[5];
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
  int32_T c2_i9;
  int32_T c2_i10;
  static real_T c2_dv3[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  real_T *c2_b_q1;
  real_T *c2_b_q2;
  real_T *c2_b_q3;
  real_T *c2_b_q4;
  real_T (*c2_b_MGD)[16];
  real_T (*c2_b_rt)[5];
  real_T (*c2_b_yz)[2];
  c2_b_rt = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_yz = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_q1;
  c2_b_hoistedGlobal = *c2_b_q2;
  c2_c_hoistedGlobal = *c2_b_q3;
  c2_d_hoistedGlobal = *c2_b_q4;
  c2_q1 = c2_hoistedGlobal;
  c2_q2 = c2_b_hoistedGlobal;
  c2_q3 = c2_c_hoistedGlobal;
  c2_q4 = c2_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_d2, 0U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_a2, 1U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a3, 2U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a4, 3U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a5, 4U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a6, 5U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_H, 6U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 7U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 8U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_q1, 9U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q2, 10U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q3, 11U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_q4, 12U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_MGD, 13U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_yz, 14U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_rt, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_d2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_a5 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_a6 = 0.59;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
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
  c2_c_y = 0.59 * c2_c_b;
  c2_o_x = c2_q3 + c2_q4;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarCos(c2_p_x);
  c2_d_b = c2_p_x;
  c2_d_y = 0.59 * c2_d_b;
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
  c2_h_y = 0.59 * c2_h_b;
  c2_bb_x = c2_q3 + c2_q4;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarSin(c2_cb_x);
  c2_i_b = c2_cb_x;
  c2_i_y = 0.59 * c2_i_b;
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
  c2_s_y = c2_j_a * 1.18;
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
  c2_v_y = c2_m_a * 1.18;
  c2_MGD[0] = c2_y;
  c2_MGD[4] = c2_b_y;
  c2_MGD[8] = c2_j_x;
  c2_MGD[12] = c2_g_y;
  c2_MGD[1] = -c2_v_x;
  c2_MGD[5] = -c2_x_x;
  c2_MGD[9] = 0.0;
  c2_MGD[13] = (((-c2_d2 - c2_h_y) - c2_i_y) - c2_j_y) - c2_k_y;
  c2_MGD[2] = c2_l_y;
  c2_MGD[6] = c2_m_y;
  c2_MGD[10] = c2_qb_x;
  c2_MGD[14] = (((c2_q1 + c2_n_y) + c2_p_y) - c2_s_y) + c2_v_y;
  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_MGD[c2_i9 + 3] = c2_dv3[c2_i10];
    c2_i9 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  for (c2_i11 = 0; c2_i11 < 16; c2_i11++) {
    c2_H[c2_i11] = c2_MGD[c2_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_yz[0] = c2_MGD[13];
  c2_yz[1] = c2_MGD[14];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_rt[0] = c2_H[1];
  c2_rt[1] = c2_H[0];
  c2_rt[2] = c2_H[2];
  c2_rt[3] = c2_H[6];
  c2_rt[4] = c2_H[10];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -27);
  sf_debug_symbol_scope_pop();
  for (c2_i12 = 0; c2_i12 < 16; c2_i12++) {
    (*c2_b_MGD)[c2_i12] = c2_MGD[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
    (*c2_b_yz)[c2_i13] = c2_yz[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 5; c2_i14++) {
    (*c2_b_rt)[c2_i14] = c2_rt[c2_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_SIMULACION_TORQUE
  (SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  real_T c2_b_inData[5];
  int32_T c2_i16;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i15 = 0; c2_i15 < 5; c2_i15++) {
    c2_b_inData[c2_i15] = (*(real_T (*)[5])c2_inData)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 5; c2_i16++) {
    c2_u[c2_i16] = c2_b_inData[c2_i16];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 5));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_rt, const char_T *c2_identifier, real_T
  c2_y[5])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_rt), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_rt);
}

static void c2_b_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv4[5];
  int32_T c2_i17;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c2_i17 = 0; c2_i17 < 5; c2_i17++) {
    c2_y[c2_i17] = c2_dv4[c2_i17];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_rt;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i18;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_rt = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_rt), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_rt);
  for (c2_i18 = 0; c2_i18 < 5; c2_i18++) {
    (*(real_T (*)[5])c2_outData)[c2_i18] = c2_y[c2_i18];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i19;
  real_T c2_b_inData[2];
  int32_T c2_i20;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_b_inData[c2_i19] = (*(real_T (*)[2])c2_inData)[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    c2_u[c2_i20] = c2_b_inData[c2_i20];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_yz, const char_T *c2_identifier, real_T
  c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_yz), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_yz);
}

static void c2_d_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2])
{
  real_T c2_dv5[2];
  int32_T c2_i21;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
    c2_y[c2_i21] = c2_dv5[c2_i21];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_yz;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i22;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_yz = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_yz), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_yz);
  for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
    (*(real_T (*)[2])c2_outData)[c2_i22] = c2_y[c2_i22];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  real_T c2_b_inData[16];
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i23 = 0;
  for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
    for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
      c2_b_inData[c2_i25 + c2_i23] = (*(real_T (*)[16])c2_inData)[c2_i25 +
        c2_i23];
    }

    c2_i23 += 4;
  }

  c2_i26 = 0;
  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    for (c2_i28 = 0; c2_i28 < 4; c2_i28++) {
      c2_u[c2_i28 + c2_i26] = c2_b_inData[c2_i28 + c2_i26];
    }

    c2_i26 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_MGD, const char_T *c2_identifier, real_T
  c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_MGD), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_MGD);
}

static void c2_f_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_dv6[16];
  int32_T c2_i29;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i29 = 0; c2_i29 < 16; c2_i29++) {
    c2_y[c2_i29] = c2_dv6[c2_i29];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_MGD;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_MGD = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_MGD), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_MGD);
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
    for (c2_i32 = 0; c2_i32 < 4; c2_i32++) {
      (*(real_T (*)[16])c2_outData)[c2_i32 + c2_i30] = c2_y[c2_i32 + c2_i30];
    }

    c2_i30 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_SIMULACION_TORQUE_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[5];
  c2_ResolvedFunctionInfo (*c2_b_info)[5];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i33;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[5])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "cos";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[0].fileTimeLo = 3359288576U;
  (*c2_b_info)[0].fileTimeHi = 30108069U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[1].name = "eml_scalar_cos";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c2_b_info)[1].fileTimeLo = 3519288576U;
  (*c2_b_info)[1].fileTimeHi = 30108069U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context = "";
  (*c2_b_info)[2].name = "sin";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[2].fileTimeLo = 3799288576U;
  (*c2_b_info)[2].fileTimeHi = 30108069U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[3].name = "eml_scalar_sin";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c2_b_info)[3].fileTimeLo = 3659288576U;
  (*c2_b_info)[3].fileTimeHi = 30108069U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "mtimes";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[4].fileTimeLo = 2169964032U;
  (*c2_b_info)[4].fileTimeHi = 30114358U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5));
  for (c2_i33 = 0; c2_i33 < 5; c2_i33++) {
    c2_r0 = &c2_info[c2_i33];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i33);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_h_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i34;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i34, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i34;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_i_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_SIMULACION_TORQUE, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_SIMULACION_TORQUE), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_SIMULACION_TORQUE);
  return c2_y;
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_SIMULACION_TORQUE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2112974817U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(116269171U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4114649755U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2100459904U);
}

mxArray *sf_c2_SIMULACION_TORQUE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1389643793U);
    pr[1] = (double)(2836662055U);
    pr[2] = (double)(978941657U);
    pr[3] = (double)(2830731431U);
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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
      pr[1] = (double)(5);
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

static const mxArray *sf_get_sim_state_info_c2_SIMULACION_TORQUE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"MGD\",},{M[1],M[23],T\"rt\",},{M[1],M[20],T\"yz\",},{M[8],M[0],T\"is_active_c2_SIMULACION_TORQUE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_SIMULACION_TORQUE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
    chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMULACION_TORQUEMachineNumber_,
           2,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"MGD");
          _SFD_SET_DATA_PROPS(2,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"q4");
          _SFD_SET_DATA_PROPS(5,2,0,1,"yz");
          _SFD_SET_DATA_PROPS(6,2,0,1,"rt");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1244);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_q1;
          real_T *c2_q2;
          real_T *c2_q3;
          real_T *c2_q4;
          real_T (*c2_MGD)[16];
          real_T (*c2_yz)[2];
          real_T (*c2_rt)[5];
          c2_rt = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_yz = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_q1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_MGD);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_q2);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_q3);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_q4);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_yz);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_rt);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMULACION_TORQUEMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_SIMULACION_TORQUE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
  initialize_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_SIMULACION_TORQUE(void *chartInstanceVar)
{
  enable_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_SIMULACION_TORQUE(void *chartInstanceVar)
{
  disable_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_SIMULACION_TORQUE(void *chartInstanceVar)
{
  sf_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_SIMULACION_TORQUE(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_SIMULACION_TORQUE
    ((SFc2_SIMULACION_TORQUEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SIMULACION_TORQUE();/* state var info */
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

extern void sf_internal_set_sim_state_c2_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SIMULACION_TORQUE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_SIMULACION_TORQUE(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_SIMULACION_TORQUE(S);
}

static void sf_opaque_set_sim_state_c2_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_SIMULACION_TORQUE(S, st);
}

static void sf_opaque_terminate_c2_SIMULACION_TORQUE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_SIMULACION_TORQUEInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_SIMULACION_TORQUE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_SIMULACION_TORQUE((SFc2_SIMULACION_TORQUEInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",
                2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE",
      "SIMULACION_TORQUE",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SIMULACION_TORQUE",
        "SIMULACION_TORQUE",2,4);
      sf_mark_chart_reusable_outputs(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",2,
        3);
    }

    sf_set_rtw_dwork_info(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1789893240U));
  ssSetChecksum1(S,(3741075837U));
  ssSetChecksum2(S,(4196795763U));
  ssSetChecksum3(S,(2681517387U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMULACION_TORQUE", "SIMULACION_TORQUE",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_SIMULACION_TORQUE(SimStruct *S)
{
  SFc2_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc2_SIMULACION_TORQUEInstanceStruct *)malloc(sizeof
    (SFc2_SIMULACION_TORQUEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_SIMULACION_TORQUEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_SIMULACION_TORQUE;
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

void c2_SIMULACION_TORQUE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_SIMULACION_TORQUE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_SIMULACION_TORQUE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}