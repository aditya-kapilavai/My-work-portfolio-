/* Include files */

#include "blascompat32.h"
#include "untitled_sfun.h"
#include "c2_untitled.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[11] = { "nargin", "nargout", "d1",
  "d2", "a3", "alpha2", "alpha3", "theta2", "theta3", "MGD", "xyz" };

/* Function Declarations */
static void initialize_c2_untitled(SFc2_untitledInstanceStruct *chartInstance);
static void initialize_params_c2_untitled(SFc2_untitledInstanceStruct
  *chartInstance);
static void enable_c2_untitled(SFc2_untitledInstanceStruct *chartInstance);
static void disable_c2_untitled(SFc2_untitledInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_untitled(SFc2_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_untitled(SFc2_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c2_untitled(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_untitled(SFc2_untitledInstanceStruct *chartInstance);
static void sf_c2_untitled(SFc2_untitledInstanceStruct *chartInstance);
static void c2_chartstep_c2_untitled(SFc2_untitledInstanceStruct *chartInstance);
static void initSimStructsc2_untitled(SFc2_untitledInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_xyz, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_MGD, const char_T *c2_identifier, real_T c2_y[16]);
static void c2_d_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15]);
static real_T c2_cosd(SFc2_untitledInstanceStruct *chartInstance, real_T c2_x);
static real_T c2_eml_scalar_round(SFc2_untitledInstanceStruct *chartInstance,
  real_T c2_x);
static real_T c2_eml_scalar_mod(SFc2_untitledInstanceStruct *chartInstance,
  real_T c2_x, real_T c2_y);
static real_T c2_sind(SFc2_untitledInstanceStruct *chartInstance, real_T c2_x);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_untitled, const char_T *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_cosd(SFc2_untitledInstanceStruct *chartInstance, real_T *c2_x);
static void c2_b_eml_scalar_round(SFc2_untitledInstanceStruct *chartInstance,
  real_T *c2_x);
static void c2_b_sind(SFc2_untitledInstanceStruct *chartInstance, real_T *c2_x);
static void init_dsm_address_info(SFc2_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_untitled(SFc2_untitledInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_untitled = 0U;
}

static void initialize_params_c2_untitled(SFc2_untitledInstanceStruct
  *chartInstance)
{
}

static void enable_c2_untitled(SFc2_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_untitled(SFc2_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_untitled(SFc2_untitledInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_untitled(SFc2_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[16];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[3];
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T (*c2_xyz)[3];
  real_T (*c2_MGD)[16];
  c2_xyz = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3));
  for (c2_i0 = 0; c2_i0 < 16; c2_i0++) {
    c2_u[c2_i0] = (*c2_MGD)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_xyz)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_untitled;
  c2_c_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_untitled(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[16];
  int32_T c2_i2;
  real_T c2_dv1[3];
  int32_T c2_i3;
  real_T (*c2_MGD)[16];
  real_T (*c2_xyz)[3];
  c2_xyz = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "MGD", c2_dv0);
  for (c2_i2 = 0; c2_i2 < 16; c2_i2++) {
    (*c2_MGD)[c2_i2] = c2_dv0[c2_i2];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "xyz",
                      c2_dv1);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    (*c2_xyz)[c2_i3] = c2_dv1[c2_i3];
  }

  chartInstance->c2_is_active_c2_untitled = c2_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 2)), "is_active_c2_untitled");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_untitled(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_untitled(SFc2_untitledInstanceStruct *chartInstance)
{
}

static void sf_c2_untitled(SFc2_untitledInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  real_T *c2_d1;
  real_T *c2_d2;
  real_T *c2_a3;
  real_T *c2_alpha2;
  real_T *c2_alpha3;
  real_T *c2_theta2;
  real_T *c2_theta3;
  real_T (*c2_xyz)[3];
  real_T (*c2_MGD)[16];
  c2_theta3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_theta2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_alpha3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_alpha2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_d2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_xyz = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_d1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_d1, 0U);
  for (c2_i4 = 0; c2_i4 < 16; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_MGD)[c2_i4], 1U);
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_xyz)[c2_i5], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_d2, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_a3, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_alpha2, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_alpha3, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_theta2, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_theta3, 8U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_untitled(chartInstance);
  sf_debug_check_for_state_inconsistency(_untitledMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_untitled(SFc2_untitledInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_g_hoistedGlobal;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_a3;
  real_T c2_alpha2;
  real_T c2_alpha3;
  real_T c2_theta2;
  real_T c2_theta3;
  uint32_T c2_debug_family_var_map[11];
  real_T c2_nargin = 7.0;
  real_T c2_nargout = 2.0;
  real_T c2_MGD[16];
  real_T c2_xyz[3];
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_h_a;
  real_T c2_h_b;
  real_T c2_h_y;
  real_T c2_i_a;
  real_T c2_i_b;
  real_T c2_i_y;
  real_T c2_j_a;
  real_T c2_j_b;
  real_T c2_j_y;
  real_T c2_k_a;
  real_T c2_k_b;
  real_T c2_k_y;
  real_T c2_l_a;
  real_T c2_l_b;
  real_T c2_l_y;
  real_T c2_m_a;
  real_T c2_m_b;
  real_T c2_m_y;
  real_T c2_n_a;
  real_T c2_n_b;
  real_T c2_n_y;
  real_T c2_o_a;
  real_T c2_o_b;
  real_T c2_o_y;
  real_T c2_p_a;
  real_T c2_p_b;
  real_T c2_p_y;
  real_T c2_q_a;
  real_T c2_q_b;
  real_T c2_q_y;
  real_T c2_r_a;
  real_T c2_r_b;
  real_T c2_r_y;
  real_T c2_s_a;
  real_T c2_s_b;
  real_T c2_s_y;
  real_T c2_t_a;
  real_T c2_t_b;
  real_T c2_t_y;
  real_T c2_u_a;
  real_T c2_u_b;
  real_T c2_u_y;
  real_T c2_v_a;
  real_T c2_v_b;
  real_T c2_v_y;
  real_T c2_w_a;
  real_T c2_w_b;
  real_T c2_w_y;
  real_T c2_x_a;
  real_T c2_x_b;
  real_T c2_x_y;
  real_T c2_y_a;
  real_T c2_y_b;
  real_T c2_y_y;
  real_T c2_ab_a;
  real_T c2_ab_b;
  real_T c2_ab_y;
  real_T c2_bb_a;
  real_T c2_bb_b;
  real_T c2_bb_y;
  real_T c2_cb_a;
  real_T c2_cb_b;
  real_T c2_cb_y;
  real_T c2_db_a;
  real_T c2_db_b;
  real_T c2_db_y;
  real_T c2_eb_a;
  real_T c2_eb_b;
  real_T c2_eb_y;
  real_T c2_fb_a;
  real_T c2_fb_b;
  real_T c2_fb_y;
  real_T c2_gb_a;
  real_T c2_gb_b;
  real_T c2_gb_y;
  real_T c2_hb_a;
  real_T c2_hb_b;
  real_T c2_hb_y;
  real_T c2_ib_a;
  real_T c2_ib_b;
  real_T c2_ib_y;
  real_T c2_jb_a;
  real_T c2_jb_b;
  real_T c2_jb_y;
  real_T c2_kb_a;
  real_T c2_kb_b;
  real_T c2_kb_y;
  real_T c2_lb_a;
  real_T c2_lb_b;
  real_T c2_lb_y;
  real_T c2_mb_a;
  real_T c2_mb_b;
  real_T c2_mb_y;
  real_T c2_nb_a;
  real_T c2_nb_b;
  real_T c2_nb_y;
  real_T c2_ob_a;
  real_T c2_ob_b;
  real_T c2_ob_y;
  real_T c2_pb_a;
  real_T c2_pb_b;
  real_T c2_pb_y;
  real_T c2_qb_a;
  real_T c2_qb_b;
  real_T c2_qb_y;
  real_T c2_rb_a;
  real_T c2_rb_b;
  real_T c2_rb_y;
  real_T c2_sb_a;
  real_T c2_sb_b;
  real_T c2_sb_y;
  real_T c2_tb_a;
  real_T c2_tb_b;
  real_T c2_tb_y;
  real_T c2_ub_a;
  real_T c2_ub_b;
  real_T c2_ub_y;
  real_T c2_vb_a;
  real_T c2_vb_b;
  real_T c2_vb_y;
  real_T c2_wb_a;
  real_T c2_wb_b;
  real_T c2_wb_y;
  real_T c2_xb_a;
  real_T c2_xb_b;
  real_T c2_xb_y;
  real_T c2_yb_a;
  real_T c2_yb_b;
  real_T c2_yb_y;
  real_T c2_ac_a;
  real_T c2_ac_b;
  real_T c2_ac_y;
  real_T c2_bc_a;
  real_T c2_bc_b;
  real_T c2_bc_y;
  real_T c2_cc_a;
  real_T c2_cc_b;
  real_T c2_cc_y;
  int32_T c2_i6;
  int32_T c2_i7;
  static real_T c2_dv2[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c2_i8;
  real_T c2_u[16];
  const mxArray *c2_dc_y = NULL;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T *c2_b_d1;
  real_T *c2_b_d2;
  real_T *c2_b_a3;
  real_T *c2_b_alpha2;
  real_T *c2_b_alpha3;
  real_T *c2_b_theta2;
  real_T *c2_b_theta3;
  real_T (*c2_b_MGD)[16];
  real_T (*c2_b_xyz)[3];
  c2_b_theta3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_theta2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_alpha3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_alpha2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_d2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_xyz = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_d1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_d1;
  c2_b_hoistedGlobal = *c2_b_d2;
  c2_c_hoistedGlobal = *c2_b_a3;
  c2_d_hoistedGlobal = *c2_b_alpha2;
  c2_e_hoistedGlobal = *c2_b_alpha3;
  c2_f_hoistedGlobal = *c2_b_theta2;
  c2_g_hoistedGlobal = *c2_b_theta3;
  c2_d1 = c2_hoistedGlobal;
  c2_d2 = c2_b_hoistedGlobal;
  c2_a3 = c2_c_hoistedGlobal;
  c2_alpha2 = c2_d_hoistedGlobal;
  c2_alpha3 = c2_e_hoistedGlobal;
  c2_theta2 = c2_f_hoistedGlobal;
  c2_theta3 = c2_g_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_d1, 2U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_d2, 3U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a3, 4U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_alpha2, 5U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_alpha3, 6U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta2, 7U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta3, 8U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_MGD, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_xyz, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_a = c2_theta2;
  c2_b_cosd(chartInstance, &c2_a);
  c2_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_b);
  c2_y = c2_a * c2_b;
  c2_b_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_b_a);
  c2_b_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_b_b);
  c2_b_y = c2_b_a * c2_b_b;
  c2_c_a = c2_b_y;
  c2_c_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_c_b);
  c2_c_y = c2_c_a * c2_c_b;
  c2_d_a = c2_alpha2;
  c2_b_sind(chartInstance, &c2_d_a);
  c2_d_b = c2_alpha3;
  c2_b_sind(chartInstance, &c2_d_b);
  c2_d_y = c2_d_a * c2_d_b;
  c2_e_a = c2_d_y;
  c2_e_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_e_b);
  c2_e_y = c2_e_a * c2_e_b;
  c2_f_a = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_f_a);
  c2_f_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_f_b);
  c2_f_y = c2_f_a * c2_f_b;
  c2_g_a = c2_f_y;
  c2_g_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_g_b);
  c2_g_y = c2_g_a * c2_g_b;
  c2_h_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_h_a);
  c2_h_b = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_h_b);
  c2_h_y = c2_h_a * c2_h_b;
  c2_i_a = c2_h_y;
  c2_i_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_i_b);
  c2_i_y = c2_i_a * c2_i_b;
  c2_j_a = c2_i_y;
  c2_j_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_j_b);
  c2_j_y = c2_j_a * c2_j_b;
  c2_k_a = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_k_a);
  c2_k_b = c2_alpha2;
  c2_b_sind(chartInstance, &c2_k_b);
  c2_k_y = c2_k_a * c2_k_b;
  c2_l_a = c2_k_y;
  c2_l_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_l_b);
  c2_l_y = c2_l_a * c2_l_b;
  c2_m_a = c2_alpha3;
  c2_b_sind(chartInstance, &c2_m_a);
  c2_m_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_m_b);
  c2_m_y = c2_m_a * c2_m_b;
  c2_n_a = c2_m_y;
  c2_n_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_n_b);
  c2_n_y = c2_n_a * c2_n_b;
  c2_o_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_o_a);
  c2_o_b = c2_alpha3;
  c2_b_sind(chartInstance, &c2_o_b);
  c2_o_y = c2_o_a * c2_o_b;
  c2_p_a = c2_o_y;
  c2_p_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_p_b);
  c2_p_y = c2_p_a * c2_p_b;
  c2_q_a = c2_p_y;
  c2_q_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_q_b);
  c2_q_y = c2_q_a * c2_q_b;
  c2_r_a = c2_theta2;
  c2_b_cosd(chartInstance, &c2_r_a);
  c2_r_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_r_b);
  c2_r_y = c2_r_a * c2_r_b;
  c2_s_a = c2_r_y;
  c2_s_b = c2_a3 + c2_d1;
  c2_s_y = c2_s_a * c2_s_b;
  c2_t_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_t_a);
  c2_t_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_t_b);
  c2_t_y = c2_t_a * c2_t_b;
  c2_u_a = c2_t_y;
  c2_u_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_u_b);
  c2_u_y = c2_u_a * c2_u_b;
  c2_v_a = c2_u_y;
  c2_v_b = c2_a3 + c2_d1;
  c2_v_y = c2_v_a * c2_v_b;
  c2_w_a = c2_theta3;
  c2_b_cosd(chartInstance, &c2_w_a);
  c2_w_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_w_b);
  c2_w_y = c2_w_a * c2_w_b;
  c2_x_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_x_a);
  c2_x_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_x_b);
  c2_x_y = c2_x_a * c2_x_b;
  c2_y_a = c2_x_y;
  c2_y_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_y_b);
  c2_y_y = c2_y_a * c2_y_b;
  c2_ab_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_ab_a);
  c2_ab_b = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_ab_b);
  c2_ab_y = c2_ab_a * c2_ab_b;
  c2_bb_a = c2_ab_y;
  c2_bb_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_bb_b);
  c2_bb_y = c2_bb_a * c2_bb_b;
  c2_cb_a = c2_bb_y;
  c2_cb_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_cb_b);
  c2_cb_y = c2_cb_a * c2_cb_b;
  c2_db_a = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_db_a);
  c2_db_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_db_b);
  c2_db_y = c2_db_a * c2_db_b;
  c2_eb_a = c2_db_y;
  c2_eb_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_eb_b);
  c2_eb_y = c2_eb_a * c2_eb_b;
  c2_fb_a = c2_alpha2;
  c2_b_sind(chartInstance, &c2_fb_a);
  c2_fb_b = c2_alpha3;
  c2_b_sind(chartInstance, &c2_fb_b);
  c2_fb_y = c2_fb_a * c2_fb_b;
  c2_gb_a = c2_fb_y;
  c2_gb_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_gb_b);
  c2_gb_y = c2_gb_a * c2_gb_b;
  c2_hb_a = c2_alpha3;
  c2_b_sind(chartInstance, &c2_hb_a);
  c2_hb_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_hb_b);
  c2_hb_y = c2_hb_a * c2_hb_b;
  c2_ib_a = c2_hb_y;
  c2_ib_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_ib_b);
  c2_ib_y = c2_ib_a * c2_ib_b;
  c2_jb_a = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_jb_a);
  c2_jb_b = c2_alpha2;
  c2_b_sind(chartInstance, &c2_jb_b);
  c2_jb_y = c2_jb_a * c2_jb_b;
  c2_kb_a = c2_jb_y;
  c2_kb_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_kb_b);
  c2_kb_y = c2_kb_a * c2_kb_b;
  c2_lb_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_lb_a);
  c2_lb_b = c2_alpha3;
  c2_b_sind(chartInstance, &c2_lb_b);
  c2_lb_y = c2_lb_a * c2_lb_b;
  c2_mb_a = c2_lb_y;
  c2_mb_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_mb_b);
  c2_mb_y = c2_mb_a * c2_mb_b;
  c2_nb_a = c2_mb_y;
  c2_nb_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_nb_b);
  c2_nb_y = c2_nb_a * c2_nb_b;
  c2_ob_a = c2_theta3;
  c2_b_cosd(chartInstance, &c2_ob_a);
  c2_ob_b = c2_theta2;
  c2_b_sind(chartInstance, &c2_ob_b);
  c2_ob_y = c2_ob_a * c2_ob_b;
  c2_pb_a = c2_ob_y;
  c2_pb_b = c2_a3 + c2_d1;
  c2_pb_y = c2_pb_a * c2_pb_b;
  c2_qb_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_qb_a);
  c2_qb_b = c2_theta2;
  c2_b_cosd(chartInstance, &c2_qb_b);
  c2_qb_y = c2_qb_a * c2_qb_b;
  c2_rb_a = c2_qb_y;
  c2_rb_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_rb_b);
  c2_rb_y = c2_rb_a * c2_rb_b;
  c2_sb_a = c2_rb_y;
  c2_sb_b = c2_a3 + c2_d1;
  c2_sb_y = c2_sb_a * c2_sb_b;
  c2_tb_a = c2_alpha2;
  c2_b_sind(chartInstance, &c2_tb_a);
  c2_tb_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_tb_b);
  c2_tb_y = c2_tb_a * c2_tb_b;
  c2_ub_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_ub_a);
  c2_ub_b = c2_alpha3;
  c2_b_sind(chartInstance, &c2_ub_b);
  c2_ub_y = c2_ub_a * c2_ub_b;
  c2_vb_a = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_vb_a);
  c2_vb_b = c2_alpha2;
  c2_b_sind(chartInstance, &c2_vb_b);
  c2_vb_y = c2_vb_a * c2_vb_b;
  c2_wb_a = c2_vb_y;
  c2_wb_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_wb_b);
  c2_wb_y = c2_wb_a * c2_wb_b;
  c2_xb_a = c2_alpha2;
  c2_b_cosd(chartInstance, &c2_xb_a);
  c2_xb_b = c2_alpha3;
  c2_b_cosd(chartInstance, &c2_xb_b);
  c2_xb_y = c2_xb_a * c2_xb_b;
  c2_yb_a = c2_alpha2;
  c2_b_sind(chartInstance, &c2_yb_a);
  c2_yb_b = c2_alpha3;
  c2_b_sind(chartInstance, &c2_yb_b);
  c2_yb_y = c2_yb_a * c2_yb_b;
  c2_ac_a = c2_yb_y;
  c2_ac_b = c2_theta3;
  c2_b_cosd(chartInstance, &c2_ac_b);
  c2_ac_y = c2_ac_a * c2_ac_b;
  c2_bc_a = c2_alpha2;
  c2_b_sind(chartInstance, &c2_bc_a);
  c2_bc_b = c2_theta3;
  c2_b_sind(chartInstance, &c2_bc_b);
  c2_bc_y = c2_bc_a * c2_bc_b;
  c2_cc_a = c2_bc_y;
  c2_cc_b = c2_a3 + c2_d1;
  c2_cc_y = c2_cc_a * c2_cc_b;
  c2_MGD[0] = c2_y - c2_c_y;
  c2_MGD[4] = (c2_e_y - c2_g_y) - c2_j_y;
  c2_MGD[8] = (c2_l_y + c2_n_y) + c2_q_y;
  c2_MGD[12] = c2_s_y - c2_v_y;
  c2_MGD[1] = c2_w_y + c2_y_y;
  c2_MGD[5] = (c2_cb_y - c2_eb_y) - c2_gb_y;
  c2_MGD[9] = (c2_ib_y - c2_kb_y) - c2_nb_y;
  c2_MGD[13] = c2_pb_y + c2_sb_y;
  c2_MGD[2] = c2_tb_y;
  c2_MGD[6] = c2_ub_y + c2_wb_y;
  c2_MGD[10] = c2_xb_y - c2_ac_y;
  c2_MGD[14] = (c2_d1 + c2_d2) + c2_cc_y;
  c2_i6 = 0;
  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    c2_MGD[c2_i6 + 3] = c2_dv2[c2_i7];
    c2_i6 += 4;
  }

  sf_mex_printf("%s =\\n", "MGD");
  for (c2_i8 = 0; c2_i8 < 16; c2_i8++) {
    c2_u[c2_i8] = c2_MGD[c2_i8];
  }

  c2_dc_y = NULL;
  sf_mex_assign(&c2_dc_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_dc_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_xyz[0] = c2_MGD[12];
  c2_xyz[1] = c2_MGD[13];
  c2_xyz[2] = c2_MGD[14];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -22);
  sf_debug_symbol_scope_pop();
  for (c2_i9 = 0; c2_i9 < 16; c2_i9++) {
    (*c2_b_MGD)[c2_i9] = c2_MGD[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    (*c2_b_xyz)[c2_i10] = c2_xyz[c2_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_untitled(SFc2_untitledInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i11;
  real_T c2_b_inData[3];
  int32_T c2_i12;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_b_inData[c2_i11] = (*(real_T (*)[3])c2_inData)[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    c2_u[c2_i12] = c2_b_inData[c2_i12];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_xyz, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_xyz), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_xyz);
}

static void c2_b_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv3[3];
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_y[c2_i13] = c2_dv3[c2_i13];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_xyz;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i14;
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_xyz = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_xyz), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_xyz);
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    (*(real_T (*)[3])c2_outData)[c2_i14] = c2_y[c2_i14];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  real_T c2_b_inData[16];
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i15 = 0;
  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    for (c2_i17 = 0; c2_i17 < 4; c2_i17++) {
      c2_b_inData[c2_i17 + c2_i15] = (*(real_T (*)[16])c2_inData)[c2_i17 +
        c2_i15];
    }

    c2_i15 += 4;
  }

  c2_i18 = 0;
  for (c2_i19 = 0; c2_i19 < 4; c2_i19++) {
    for (c2_i20 = 0; c2_i20 < 4; c2_i20++) {
      c2_u[c2_i20 + c2_i18] = c2_b_inData[c2_i20 + c2_i18];
    }

    c2_i18 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_MGD, const char_T *c2_identifier, real_T c2_y[16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_MGD), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_MGD);
}

static void c2_d_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[16])
{
  real_T c2_dv4[16];
  int32_T c2_i21;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i21 = 0; c2_i21 < 16; c2_i21++) {
    c2_y[c2_i21] = c2_dv4[c2_i21];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_MGD;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_MGD = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_MGD), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_MGD);
  c2_i22 = 0;
  for (c2_i23 = 0; c2_i23 < 4; c2_i23++) {
    for (c2_i24 = 0; c2_i24 < 4; c2_i24++) {
      (*(real_T (*)[16])c2_outData)[c2_i24 + c2_i22] = c2_y[c2_i24 + c2_i22];
    }

    c2_i22 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
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
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[15];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i25;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15));
  for (c2_i25 = 0; c2_i25 < 15; c2_i25++) {
    c2_r0 = &c2_info[c2_i25];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i25);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[15])
{
  c2_info[0].context = "";
  c2_info[0].name = "cosd";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c2_info[0].fileTimeLo = 3359288576U;
  c2_info[0].fileTimeHi = 30108069U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cosd.m";
  c2_info[1].name = "eml_scalar_cosd";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c2_info[1].fileTimeLo = 3519288576U;
  c2_info[1].fileTimeHi = 30108069U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c2_info[2].name = "eml_scalar_round";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[2].fileTimeLo = 1529964032U;
  c2_info[2].fileTimeHi = 30114358U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c2_info[3].name = "eps";
  c2_info[3].dominantType = "char";
  c2_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[3].fileTimeLo = 3159288576U;
  c2_info[3].fileTimeHi = 30108069U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[4].name = "eml_is_float_class";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[4].fileTimeLo = 4119288576U;
  c2_info[4].fileTimeHi = 30108069U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c2_info[5].name = "mrdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].fileTimeLo = 714027776U;
  c2_info[5].fileTimeHi = 30130994U;
  c2_info[5].mFileTimeLo = 2169964032U;
  c2_info[5].mFileTimeHi = 30114358U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileTimeLo = 444321280U;
  c2_info[6].fileTimeHi = 30108070U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "eml_div";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[7].fileTimeLo = 3279288576U;
  c2_info[7].fileTimeHi = 30108069U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cosd.m";
  c2_info[8].name = "eml_scalar_mod";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[8].fileTimeLo = 3599288576U;
  c2_info[8].fileTimeHi = 30108069U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[9].name = "eml_scalar_eg";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[9].fileTimeLo = 4259288576U;
  c2_info[9].fileTimeHi = 30108069U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[10].name = "eml_scalar_floor";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[10].fileTimeLo = 3559288576U;
  c2_info[10].fileTimeHi = 30108069U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[11].name = "eml_scalar_abs";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[11].fileTimeLo = 3419288576U;
  c2_info[11].fileTimeHi = 30108069U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_mod.m";
  c2_info[12].name = "mtimes";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].fileTimeLo = 2169964032U;
  c2_info[12].fileTimeHi = 30114358U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "sind";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m";
  c2_info[13].fileTimeLo = 3799288576U;
  c2_info[13].fileTimeHi = 30108069U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sind.m";
  c2_info[14].name = "eml_scalar_sind";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sind.m";
  c2_info[14].fileTimeLo = 3679288576U;
  c2_info[14].fileTimeHi = 30108069U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
}

static real_T c2_cosd(SFc2_untitledInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_cosd(chartInstance, &c2_b_x);
  return c2_b_x;
}

static real_T c2_eml_scalar_round(SFc2_untitledInstanceStruct *chartInstance,
  real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_eml_scalar_round(chartInstance, &c2_b_x);
  return c2_b_x;
}

static real_T c2_eml_scalar_mod(SFc2_untitledInstanceStruct *chartInstance,
  real_T c2_x, real_T c2_y)
{
  real_T c2_r;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_d1;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_g_x;
  real_T c2_c_y;
  real_T c2_b;
  real_T c2_d_y;
  real_T c2_h_x;
  real_T c2_i_x;
  if (c2_y == 0.0) {
    c2_r = c2_x;
  } else {
    c2_b_x = c2_y;
    c2_c_x = c2_b_x;
    c2_c_x = muDoubleScalarFloor(c2_c_x);
    if (c2_y == c2_c_x) {
      c2_d_x = c2_x / c2_y;
      c2_e_x = c2_d_x;
      c2_e_x = muDoubleScalarFloor(c2_e_x);
      c2_r = c2_x - c2_e_x * c2_y;
    } else {
      c2_r = c2_x / c2_y;
      c2_d1 = c2_r;
      c2_b_eml_scalar_round(chartInstance, &c2_d1);
      c2_f_x = c2_r - c2_d1;
      c2_b_y = muDoubleScalarAbs(c2_f_x);
      c2_g_x = c2_r;
      c2_c_y = muDoubleScalarAbs(c2_g_x);
      c2_b = c2_c_y;
      c2_d_y = 2.2204460492503131E-16 * c2_b;
      if (c2_b_y <= c2_d_y) {
        c2_r = 0.0;
      } else {
        c2_h_x = c2_r;
        c2_i_x = c2_h_x;
        c2_i_x = muDoubleScalarFloor(c2_i_x);
        c2_r = (c2_r - c2_i_x) * c2_y;
      }
    }
  }

  return c2_r;
}

static real_T c2_sind(SFc2_untitledInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sind(chartInstance, &c2_b_x);
  return c2_b_x;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i26;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i26, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i26;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_untitled, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_untitled), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_untitled);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_untitledInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_cosd(SFc2_untitledInstanceStruct *chartInstance, real_T *c2_x)
{
  real_T c2_n;
  real_T c2_m;
  c2_n = *c2_x / 90.0;
  c2_b_eml_scalar_round(chartInstance, &c2_n);
  *c2_x -= c2_n * 90.0;
  c2_m = c2_eml_scalar_mod(chartInstance, c2_n, 4.0);
  c2_b_eml_scalar_round(chartInstance, &c2_m);
  if (c2_m < 2.0) {
    if (c2_m < 1.0) {
      *c2_x = muDoubleScalarCos(0.017453292519943295 * *c2_x);
    } else {
      *c2_x = -muDoubleScalarSin(0.017453292519943295 * *c2_x);
    }
  } else if (c2_m < 3.0) {
    *c2_x = -muDoubleScalarCos(0.017453292519943295 * *c2_x);
  } else {
    *c2_x = muDoubleScalarSin(0.017453292519943295 * *c2_x);
  }
}

static void c2_b_eml_scalar_round(SFc2_untitledInstanceStruct *chartInstance,
  real_T *c2_x)
{
  real_T c2_b_x;
  c2_b_x = *c2_x;
  if (muDoubleScalarAbs(c2_b_x) > 4.503599627370496E+15) {
  } else if (c2_b_x >= 0.5) {
    *c2_x = muDoubleScalarFloor(c2_b_x + 0.5);
  } else if (c2_b_x > -0.5) {
    *c2_x = c2_b_x * 0.0;
  } else {
    *c2_x = muDoubleScalarCeil(c2_b_x - 0.5);
  }
}

static void c2_b_sind(SFc2_untitledInstanceStruct *chartInstance, real_T *c2_x)
{
  real_T c2_n;
  real_T c2_m;
  c2_n = *c2_x / 90.0;
  c2_b_eml_scalar_round(chartInstance, &c2_n);
  *c2_x -= c2_n * 90.0;
  c2_m = c2_eml_scalar_mod(chartInstance, c2_n, 4.0);
  c2_b_eml_scalar_round(chartInstance, &c2_m);
  if (c2_m < 2.0) {
    if (c2_m < 1.0) {
      *c2_x = muDoubleScalarSin(0.017453292519943295 * *c2_x);
    } else {
      *c2_x = muDoubleScalarCos(0.017453292519943295 * *c2_x);
    }
  } else if (c2_m < 3.0) {
    *c2_x = -muDoubleScalarSin(0.017453292519943295 * *c2_x);
  } else {
    *c2_x = -muDoubleScalarCos(0.017453292519943295 * *c2_x);
  }
}

static void init_dsm_address_info(SFc2_untitledInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1648836597U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2624856956U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1948064666U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2862645593U);
}

mxArray *sf_c2_untitled_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1867346993U);
    pr[1] = (double)(899440427U);
    pr[2] = (double)(2031764299U);
    pr[3] = (double)(3037375315U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
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
      pr[1] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c2_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"MGD\",},{M[1],M[20],T\"xyz\",},{M[8],M[0],T\"is_active_c2_untitled\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_untitledInstanceStruct *chartInstance;
    chartInstance = (SFc2_untitledInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_untitledMachineNumber_,
          2,
          1,
          1,
          9,
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
          init_script_number_translation(_untitledMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_untitledMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_untitledMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"d1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"MGD");
          _SFD_SET_DATA_PROPS(2,2,0,1,"xyz");
          _SFD_SET_DATA_PROPS(3,1,1,0,"d2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"a3");
          _SFD_SET_DATA_PROPS(5,1,1,0,"alpha2");
          _SFD_SET_DATA_PROPS(6,1,1,0,"alpha3");
          _SFD_SET_DATA_PROPS(7,1,1,0,"theta2");
          _SFD_SET_DATA_PROPS(8,1,1,0,"theta3");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2696);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_d1;
          real_T *c2_d2;
          real_T *c2_a3;
          real_T *c2_alpha2;
          real_T *c2_alpha3;
          real_T *c2_theta2;
          real_T *c2_theta3;
          real_T (*c2_MGD)[16];
          real_T (*c2_xyz)[3];
          c2_theta3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_theta2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_alpha3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_alpha2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_d2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_xyz = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_d1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_d1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_MGD);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_xyz);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_d2);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_a3);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_alpha2);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_alpha3);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_theta2);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_theta3);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_untitledMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_untitled(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_untitledInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_untitled((SFc2_untitledInstanceStruct*) chartInstanceVar);
  initialize_c2_untitled((SFc2_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_untitled(void *chartInstanceVar)
{
  enable_c2_untitled((SFc2_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_untitled(void *chartInstanceVar)
{
  disable_c2_untitled((SFc2_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_untitled(void *chartInstanceVar)
{
  sf_c2_untitled((SFc2_untitledInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_untitled(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_untitled((SFc2_untitledInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_untitled();/* state var info */
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

extern void sf_internal_set_sim_state_c2_untitled(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_untitled();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_untitled((SFc2_untitledInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_untitled(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_untitled(S);
}

static void sf_opaque_set_sim_state_c2_untitled(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_untitled(S, st);
}

static void sf_opaque_terminate_c2_untitled(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_untitled((SFc2_untitledInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_untitled((SFc2_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_untitled(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_untitled((SFc2_untitledInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"untitled","untitled",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"untitled","untitled",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"untitled","untitled",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"untitled","untitled",2,7);
      sf_mark_chart_reusable_outputs(S,"untitled","untitled",2,2);
    }

    sf_set_rtw_dwork_info(S,"untitled","untitled",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(711378303U));
  ssSetChecksum1(S,(1488253102U));
  ssSetChecksum2(S,(687711964U));
  ssSetChecksum3(S,(1594409515U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "untitled", "untitled",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_untitled(SimStruct *S)
{
  SFc2_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc2_untitledInstanceStruct *)malloc(sizeof
    (SFc2_untitledInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_untitled;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_untitled;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_untitled;
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

void c2_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
