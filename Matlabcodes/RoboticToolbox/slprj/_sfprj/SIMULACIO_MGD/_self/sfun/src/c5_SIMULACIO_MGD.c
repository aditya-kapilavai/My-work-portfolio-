/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SIMULACIO_MGD_sfun.h"
#include "c5_SIMULACIO_MGD.h"
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
static const char * c5_debug_family_names[14] = { "d2", "a2", "a3", "a4", "a5",
  "a6", "nargin", "nargout", "ga", "th", "q2", "q3", "q4", "Ja" };

/* Function Declarations */
static void initialize_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void initialize_params_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct *
  chartInstance);
static void enable_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void disable_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_SIMULACIO_MGD
  (SFc5_SIMULACIO_MGDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_SIMULACIO_MGD
  (SFc5_SIMULACIO_MGDInstanceStruct *chartInstance);
static void set_sim_state_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void sf_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct *chartInstance);
static void c5_chartstep_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void initSimStructsc5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void registerMessagesc5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct *chartInstance,
  const mxArray *c5_Ja, const char_T *c5_identifier, real_T c5_y[24]);
static void c5_b_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[24]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_SIMULACIO_MGD, const char_T
  *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_SIMULACIO_MGD = 0U;
}

static void initialize_params_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct *
  chartInstance)
{
}

static void enable_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_SIMULACIO_MGD
  (SFc5_SIMULACIO_MGDInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_SIMULACIO_MGD
  (SFc5_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[24];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_Ja)[24];
  c5_Ja = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 24; c5_i0++) {
    c5_u[c5_i0] = (*c5_Ja)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 6, 4), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_SIMULACIO_MGD;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[24];
  int32_T c5_i1;
  real_T (*c5_Ja)[24];
  c5_Ja = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "Ja",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 24; c5_i1++) {
    (*c5_Ja)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_SIMULACIO_MGD = c5_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_SIMULACIO_MGD");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_SIMULACIO_MGD(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
}

static void sf_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  real_T *c5_ga;
  real_T *c5_th;
  real_T *c5_q2;
  real_T *c5_q3;
  real_T *c5_q4;
  real_T (*c5_Ja)[24];
  c5_Ja = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_th = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_ga = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_ga, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_th, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_q2, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_q3, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_q4, 4U);
  for (c5_i2 = 0; c5_i2 < 24; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_Ja)[c5_i2], 5U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_SIMULACIO_MGD(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SIMULACIO_MGDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_e_hoistedGlobal;
  real_T c5_ga;
  real_T c5_th;
  real_T c5_q2;
  real_T c5_q3;
  real_T c5_q4;
  uint32_T c5_debug_family_var_map[14];
  real_T c5_d2;
  real_T c5_a2;
  real_T c5_a3;
  real_T c5_a4;
  real_T c5_a5;
  real_T c5_a6;
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 1.0;
  real_T c5_Ja[24];
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_b;
  real_T c5_y;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_b_b;
  real_T c5_b_y;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_c_b;
  real_T c5_c_y;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_d_b;
  real_T c5_d_y;
  real_T c5_a;
  real_T c5_e_b;
  real_T c5_e_y;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_f_b;
  real_T c5_f_y;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_g_b;
  real_T c5_g_y;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_h_b;
  real_T c5_h_y;
  real_T c5_s_x;
  real_T c5_t_x;
  real_T c5_i_b;
  real_T c5_i_y;
  real_T c5_b_a;
  real_T c5_j_b;
  real_T c5_j_y;
  real_T c5_u_x;
  real_T c5_v_x;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_c_a;
  real_T c5_k_b;
  real_T c5_k_y;
  real_T c5_d_a;
  real_T c5_l_y;
  real_T c5_y_x;
  real_T c5_ab_x;
  real_T c5_l_b;
  real_T c5_m_y;
  real_T c5_bb_x;
  real_T c5_cb_x;
  real_T c5_m_b;
  real_T c5_n_y;
  real_T c5_db_x;
  real_T c5_eb_x;
  real_T c5_n_b;
  real_T c5_o_y;
  real_T c5_fb_x;
  real_T c5_gb_x;
  real_T c5_o_b;
  real_T c5_p_y;
  real_T c5_hb_x;
  real_T c5_ib_x;
  real_T c5_e_a;
  real_T c5_q_y;
  real_T c5_jb_x;
  real_T c5_kb_x;
  real_T c5_lb_x;
  real_T c5_mb_x;
  real_T c5_p_b;
  real_T c5_r_y;
  real_T c5_nb_x;
  real_T c5_ob_x;
  real_T c5_q_b;
  real_T c5_s_y;
  real_T c5_pb_x;
  real_T c5_qb_x;
  real_T c5_r_b;
  real_T c5_t_y;
  real_T c5_rb_x;
  real_T c5_sb_x;
  real_T c5_s_b;
  real_T c5_u_y;
  real_T c5_f_a;
  real_T c5_t_b;
  real_T c5_v_y;
  real_T c5_tb_x;
  real_T c5_ub_x;
  real_T c5_vb_x;
  real_T c5_wb_x;
  real_T c5_u_b;
  real_T c5_w_y;
  real_T c5_xb_x;
  real_T c5_yb_x;
  real_T c5_v_b;
  real_T c5_x_y;
  real_T c5_ac_x;
  real_T c5_bc_x;
  real_T c5_w_b;
  real_T c5_y_y;
  real_T c5_cc_x;
  real_T c5_dc_x;
  real_T c5_x_b;
  real_T c5_ab_y;
  real_T c5_g_a;
  real_T c5_y_b;
  real_T c5_bb_y;
  real_T c5_ec_x;
  real_T c5_fc_x;
  real_T c5_gc_x;
  real_T c5_hc_x;
  real_T c5_h_a;
  real_T c5_ab_b;
  real_T c5_cb_y;
  real_T c5_i_a;
  real_T c5_db_y;
  real_T c5_ic_x;
  real_T c5_jc_x;
  real_T c5_kc_x;
  real_T c5_lc_x;
  real_T c5_A;
  real_T c5_B;
  real_T c5_mc_x;
  real_T c5_eb_y;
  real_T c5_nc_x;
  real_T c5_fb_y;
  real_T c5_gb_y;
  real_T c5_oc_x;
  real_T c5_pc_x;
  real_T c5_qc_x;
  real_T c5_rc_x;
  real_T c5_j_a;
  real_T c5_bb_b;
  real_T c5_hb_y;
  real_T c5_sc_x;
  real_T c5_tc_x;
  real_T c5_b_A;
  real_T c5_b_B;
  real_T c5_uc_x;
  real_T c5_ib_y;
  real_T c5_vc_x;
  real_T c5_jb_y;
  real_T c5_kb_y;
  real_T c5_wc_x;
  real_T c5_xc_x;
  real_T c5_yc_x;
  real_T c5_ad_x;
  real_T c5_k_a;
  real_T c5_cb_b;
  real_T c5_lb_y;
  real_T c5_bd_x;
  real_T c5_cd_x;
  real_T c5_c_A;
  real_T c5_c_B;
  real_T c5_dd_x;
  real_T c5_mb_y;
  real_T c5_ed_x;
  real_T c5_nb_y;
  real_T c5_ob_y;
  real_T c5_fd_x;
  real_T c5_gd_x;
  real_T c5_hd_x;
  real_T c5_id_x;
  real_T c5_jd_x;
  real_T c5_kd_x;
  real_T c5_l_a;
  real_T c5_db_b;
  real_T c5_pb_y;
  real_T c5_ld_x;
  real_T c5_md_x;
  real_T c5_nd_x;
  real_T c5_od_x;
  real_T c5_m_a;
  real_T c5_eb_b;
  real_T c5_qb_y;
  real_T c5_pd_x;
  real_T c5_qd_x;
  real_T c5_rd_x;
  real_T c5_sd_x;
  real_T c5_n_a;
  real_T c5_fb_b;
  real_T c5_rb_y;
  real_T c5_td_x;
  real_T c5_ud_x;
  real_T c5_vd_x;
  real_T c5_wd_x;
  real_T c5_xd_x;
  real_T c5_yd_x;
  real_T c5_o_a;
  real_T c5_gb_b;
  real_T c5_sb_y;
  real_T c5_ae_x;
  real_T c5_be_x;
  real_T c5_p_a;
  real_T c5_hb_b;
  real_T c5_tb_y;
  real_T c5_ce_x;
  real_T c5_de_x;
  real_T c5_d_A;
  real_T c5_d_B;
  real_T c5_ee_x;
  real_T c5_ub_y;
  real_T c5_fe_x;
  real_T c5_vb_y;
  real_T c5_wb_y;
  real_T c5_ge_x;
  real_T c5_he_x;
  real_T c5_ie_x;
  real_T c5_je_x;
  real_T c5_ke_x;
  real_T c5_le_x;
  real_T c5_q_a;
  real_T c5_ib_b;
  real_T c5_xb_y;
  real_T c5_me_x;
  real_T c5_ne_x;
  real_T c5_r_a;
  real_T c5_jb_b;
  real_T c5_yb_y;
  real_T c5_oe_x;
  real_T c5_pe_x;
  real_T c5_e_A;
  real_T c5_e_B;
  real_T c5_qe_x;
  real_T c5_ac_y;
  real_T c5_re_x;
  real_T c5_bc_y;
  real_T c5_cc_y;
  int32_T c5_i3;
  real_T *c5_b_q4;
  real_T *c5_b_q3;
  real_T *c5_b_q2;
  real_T *c5_b_th;
  real_T *c5_b_ga;
  real_T (*c5_b_Ja)[24];
  c5_b_Ja = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_th = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_ga = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_ga;
  c5_b_hoistedGlobal = *c5_b_th;
  c5_c_hoistedGlobal = *c5_b_q2;
  c5_d_hoistedGlobal = *c5_b_q3;
  c5_e_hoistedGlobal = *c5_b_q4;
  c5_ga = c5_hoistedGlobal;
  c5_th = c5_b_hoistedGlobal;
  c5_q2 = c5_c_hoistedGlobal;
  c5_q3 = c5_d_hoistedGlobal;
  c5_q4 = c5_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d2, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_a2, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_a3, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_a4, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_a5, 4U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_a6, 5U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ga, 8U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_th, 9U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_q2, 10U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_q3, 11U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_q4, 12U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Ja, 13U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_d2 = 1.20349;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_a2 = 0.9907;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_a3 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_a4 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_a5 = 0.8862;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_a6 = 1.5;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_x = c5_q2;
  c5_b_x = c5_x;
  c5_b_x = muDoubleScalarCos(c5_b_x);
  c5_c_x = c5_q3 + c5_q4;
  c5_d_x = c5_c_x;
  c5_d_x = muDoubleScalarCos(c5_d_x);
  c5_b = c5_d_x;
  c5_y = 0.8862 * c5_b;
  c5_e_x = c5_q3 + c5_q4;
  c5_f_x = c5_e_x;
  c5_f_x = muDoubleScalarCos(c5_f_x);
  c5_b_b = c5_f_x;
  c5_b_y = 1.5 * c5_b_b;
  c5_g_x = c5_q3;
  c5_h_x = c5_g_x;
  c5_h_x = muDoubleScalarCos(c5_h_x);
  c5_c_b = c5_h_x;
  c5_c_y = 0.8862 * c5_c_b;
  c5_i_x = c5_q3;
  c5_j_x = c5_i_x;
  c5_j_x = muDoubleScalarCos(c5_j_x);
  c5_d_b = c5_j_x;
  c5_d_y = 1.5 * c5_d_b;
  c5_a = -c5_b_x;
  c5_e_b = (((c5_a2 + c5_y) + c5_b_y) + c5_c_y) + c5_d_y;
  c5_e_y = c5_a * c5_e_b;
  c5_k_x = c5_q2;
  c5_l_x = c5_k_x;
  c5_l_x = muDoubleScalarSin(c5_l_x);
  c5_m_x = c5_q3 + c5_q4;
  c5_n_x = c5_m_x;
  c5_n_x = muDoubleScalarSin(c5_n_x);
  c5_f_b = c5_n_x;
  c5_f_y = 0.8862 * c5_f_b;
  c5_o_x = c5_q3 + c5_q4;
  c5_p_x = c5_o_x;
  c5_p_x = muDoubleScalarSin(c5_p_x);
  c5_g_b = c5_p_x;
  c5_g_y = 1.5 * c5_g_b;
  c5_q_x = c5_q3;
  c5_r_x = c5_q_x;
  c5_r_x = muDoubleScalarSin(c5_r_x);
  c5_h_b = c5_r_x;
  c5_h_y = 0.8862 * c5_h_b;
  c5_s_x = c5_q3;
  c5_t_x = c5_s_x;
  c5_t_x = muDoubleScalarSin(c5_t_x);
  c5_i_b = c5_t_x;
  c5_i_y = 1.5 * c5_i_b;
  c5_b_a = c5_l_x;
  c5_j_b = ((c5_f_y + c5_g_y) + c5_h_y) + c5_i_y;
  c5_j_y = c5_b_a * c5_j_b;
  c5_u_x = c5_q3 + c5_q4;
  c5_v_x = c5_u_x;
  c5_v_x = muDoubleScalarSin(c5_v_x);
  c5_w_x = c5_q2;
  c5_x_x = c5_w_x;
  c5_x_x = muDoubleScalarSin(c5_x_x);
  c5_c_a = c5_v_x;
  c5_k_b = c5_x_x;
  c5_k_y = c5_c_a * c5_k_b;
  c5_d_a = c5_k_y;
  c5_l_y = c5_d_a * 2.3862;
  c5_y_x = c5_q3 + c5_q4;
  c5_ab_x = c5_y_x;
  c5_ab_x = muDoubleScalarCos(c5_ab_x);
  c5_l_b = c5_ab_x;
  c5_m_y = -0.8862 * c5_l_b;
  c5_bb_x = c5_q3 + c5_q4;
  c5_cb_x = c5_bb_x;
  c5_cb_x = muDoubleScalarCos(c5_cb_x);
  c5_m_b = c5_cb_x;
  c5_n_y = 1.5 * c5_m_b;
  c5_db_x = c5_q3;
  c5_eb_x = c5_db_x;
  c5_eb_x = muDoubleScalarCos(c5_eb_x);
  c5_n_b = c5_eb_x;
  c5_o_y = 0.8862 * c5_n_b;
  c5_fb_x = c5_q3;
  c5_gb_x = c5_fb_x;
  c5_gb_x = muDoubleScalarCos(c5_gb_x);
  c5_o_b = c5_gb_x;
  c5_p_y = 1.5 * c5_o_b;
  c5_hb_x = c5_q3 + c5_q4;
  c5_ib_x = c5_hb_x;
  c5_ib_x = muDoubleScalarCos(c5_ib_x);
  c5_e_a = -c5_ib_x;
  c5_q_y = c5_e_a * 2.3862;
  c5_jb_x = c5_q2;
  c5_kb_x = c5_jb_x;
  c5_kb_x = muDoubleScalarSin(c5_kb_x);
  c5_lb_x = c5_q3 + c5_q4;
  c5_mb_x = c5_lb_x;
  c5_mb_x = muDoubleScalarCos(c5_mb_x);
  c5_p_b = c5_mb_x;
  c5_r_y = 0.8862 * c5_p_b;
  c5_nb_x = c5_q3 + c5_q4;
  c5_ob_x = c5_nb_x;
  c5_ob_x = muDoubleScalarCos(c5_ob_x);
  c5_q_b = c5_ob_x;
  c5_s_y = 1.5 * c5_q_b;
  c5_pb_x = c5_q3;
  c5_qb_x = c5_pb_x;
  c5_qb_x = muDoubleScalarCos(c5_qb_x);
  c5_r_b = c5_qb_x;
  c5_t_y = 0.8862 * c5_r_b;
  c5_rb_x = c5_q3;
  c5_sb_x = c5_rb_x;
  c5_sb_x = muDoubleScalarCos(c5_sb_x);
  c5_s_b = c5_sb_x;
  c5_u_y = 1.5 * c5_s_b;
  c5_f_a = -c5_kb_x;
  c5_t_b = (((c5_a2 + c5_r_y) + c5_s_y) + c5_t_y) + c5_u_y;
  c5_v_y = c5_f_a * c5_t_b;
  c5_tb_x = c5_q2;
  c5_ub_x = c5_tb_x;
  c5_ub_x = muDoubleScalarCos(c5_ub_x);
  c5_vb_x = c5_q3 + c5_q4;
  c5_wb_x = c5_vb_x;
  c5_wb_x = muDoubleScalarSin(c5_wb_x);
  c5_u_b = c5_wb_x;
  c5_w_y = 0.8862 * c5_u_b;
  c5_xb_x = c5_q3 + c5_q4;
  c5_yb_x = c5_xb_x;
  c5_yb_x = muDoubleScalarSin(c5_yb_x);
  c5_v_b = c5_yb_x;
  c5_x_y = 1.5 * c5_v_b;
  c5_ac_x = c5_q3;
  c5_bc_x = c5_ac_x;
  c5_bc_x = muDoubleScalarSin(c5_bc_x);
  c5_w_b = c5_bc_x;
  c5_y_y = 0.8862 * c5_w_b;
  c5_cc_x = c5_q3;
  c5_dc_x = c5_cc_x;
  c5_dc_x = muDoubleScalarSin(c5_dc_x);
  c5_x_b = c5_dc_x;
  c5_ab_y = 1.5 * c5_x_b;
  c5_g_a = -c5_ub_x;
  c5_y_b = ((c5_w_y + c5_x_y) + c5_y_y) + c5_ab_y;
  c5_bb_y = c5_g_a * c5_y_b;
  c5_ec_x = c5_q3 + c5_q4;
  c5_fc_x = c5_ec_x;
  c5_fc_x = muDoubleScalarSin(c5_fc_x);
  c5_gc_x = c5_q2;
  c5_hc_x = c5_gc_x;
  c5_hc_x = muDoubleScalarCos(c5_hc_x);
  c5_h_a = -c5_fc_x;
  c5_ab_b = c5_hc_x;
  c5_cb_y = c5_h_a * c5_ab_b;
  c5_i_a = c5_cb_y;
  c5_db_y = c5_i_a * 2.3862;
  c5_ic_x = c5_th;
  c5_jc_x = c5_ic_x;
  c5_jc_x = muDoubleScalarSin(c5_jc_x);
  c5_kc_x = c5_ga;
  c5_lc_x = c5_kc_x;
  c5_lc_x = muDoubleScalarCos(c5_lc_x);
  c5_A = -c5_jc_x;
  c5_B = c5_lc_x;
  c5_mc_x = c5_A;
  c5_eb_y = c5_B;
  c5_nc_x = c5_mc_x;
  c5_fb_y = c5_eb_y;
  c5_gb_y = c5_nc_x / c5_fb_y;
  c5_oc_x = c5_q2;
  c5_pc_x = c5_oc_x;
  c5_pc_x = muDoubleScalarCos(c5_pc_x);
  c5_qc_x = c5_th;
  c5_rc_x = c5_qc_x;
  c5_rc_x = muDoubleScalarCos(c5_rc_x);
  c5_j_a = c5_pc_x;
  c5_bb_b = c5_rc_x;
  c5_hb_y = c5_j_a * c5_bb_b;
  c5_sc_x = c5_ga;
  c5_tc_x = c5_sc_x;
  c5_tc_x = muDoubleScalarCos(c5_tc_x);
  c5_b_A = c5_hb_y;
  c5_b_B = c5_tc_x;
  c5_uc_x = c5_b_A;
  c5_ib_y = c5_b_B;
  c5_vc_x = c5_uc_x;
  c5_jb_y = c5_ib_y;
  c5_kb_y = c5_vc_x / c5_jb_y;
  c5_wc_x = c5_q2;
  c5_xc_x = c5_wc_x;
  c5_xc_x = muDoubleScalarCos(c5_xc_x);
  c5_yc_x = c5_th;
  c5_ad_x = c5_yc_x;
  c5_ad_x = muDoubleScalarCos(c5_ad_x);
  c5_k_a = c5_xc_x;
  c5_cb_b = c5_ad_x;
  c5_lb_y = c5_k_a * c5_cb_b;
  c5_bd_x = c5_ga;
  c5_cd_x = c5_bd_x;
  c5_cd_x = muDoubleScalarCos(c5_cd_x);
  c5_c_A = c5_lb_y;
  c5_c_B = c5_cd_x;
  c5_dd_x = c5_c_A;
  c5_mb_y = c5_c_B;
  c5_ed_x = c5_dd_x;
  c5_nb_y = c5_mb_y;
  c5_ob_y = c5_ed_x / c5_nb_y;
  c5_fd_x = c5_th;
  c5_gd_x = c5_fd_x;
  c5_gd_x = muDoubleScalarCos(c5_gd_x);
  c5_hd_x = c5_q2;
  c5_id_x = c5_hd_x;
  c5_id_x = muDoubleScalarCos(c5_id_x);
  c5_jd_x = c5_th;
  c5_kd_x = c5_jd_x;
  c5_kd_x = muDoubleScalarSin(c5_kd_x);
  c5_l_a = -c5_id_x;
  c5_db_b = c5_kd_x;
  c5_pb_y = c5_l_a * c5_db_b;
  c5_ld_x = c5_q2;
  c5_md_x = c5_ld_x;
  c5_md_x = muDoubleScalarCos(c5_md_x);
  c5_nd_x = c5_th;
  c5_od_x = c5_nd_x;
  c5_od_x = muDoubleScalarSin(c5_od_x);
  c5_m_a = -c5_md_x;
  c5_eb_b = c5_od_x;
  c5_qb_y = c5_m_a * c5_eb_b;
  c5_pd_x = c5_ga;
  c5_qd_x = c5_pd_x;
  c5_qd_x = muDoubleScalarTan(c5_qd_x);
  c5_rd_x = c5_th;
  c5_sd_x = c5_rd_x;
  c5_sd_x = muDoubleScalarSin(c5_sd_x);
  c5_n_a = -c5_qd_x;
  c5_fb_b = c5_sd_x;
  c5_rb_y = c5_n_a * c5_fb_b;
  c5_td_x = c5_q2;
  c5_ud_x = c5_td_x;
  c5_ud_x = muDoubleScalarSin(c5_ud_x);
  c5_vd_x = c5_q2;
  c5_wd_x = c5_vd_x;
  c5_wd_x = muDoubleScalarCos(c5_wd_x);
  c5_xd_x = c5_th;
  c5_yd_x = c5_xd_x;
  c5_yd_x = muDoubleScalarCos(c5_yd_x);
  c5_o_a = c5_wd_x;
  c5_gb_b = c5_yd_x;
  c5_sb_y = c5_o_a * c5_gb_b;
  c5_ae_x = c5_ga;
  c5_be_x = c5_ae_x;
  c5_be_x = muDoubleScalarSin(c5_be_x);
  c5_p_a = c5_sb_y;
  c5_hb_b = c5_be_x;
  c5_tb_y = c5_p_a * c5_hb_b;
  c5_ce_x = c5_ga;
  c5_de_x = c5_ce_x;
  c5_de_x = muDoubleScalarCos(c5_de_x);
  c5_d_A = c5_tb_y;
  c5_d_B = c5_de_x;
  c5_ee_x = c5_d_A;
  c5_ub_y = c5_d_B;
  c5_fe_x = c5_ee_x;
  c5_vb_y = c5_ub_y;
  c5_wb_y = c5_fe_x / c5_vb_y;
  c5_ge_x = c5_q2;
  c5_he_x = c5_ge_x;
  c5_he_x = muDoubleScalarSin(c5_he_x);
  c5_ie_x = c5_q2;
  c5_je_x = c5_ie_x;
  c5_je_x = muDoubleScalarCos(c5_je_x);
  c5_ke_x = c5_th;
  c5_le_x = c5_ke_x;
  c5_le_x = muDoubleScalarCos(c5_le_x);
  c5_q_a = c5_je_x;
  c5_ib_b = c5_le_x;
  c5_xb_y = c5_q_a * c5_ib_b;
  c5_me_x = c5_ga;
  c5_ne_x = c5_me_x;
  c5_ne_x = muDoubleScalarSin(c5_ne_x);
  c5_r_a = c5_xb_y;
  c5_jb_b = c5_ne_x;
  c5_yb_y = c5_r_a * c5_jb_b;
  c5_oe_x = c5_ga;
  c5_pe_x = c5_oe_x;
  c5_pe_x = muDoubleScalarCos(c5_pe_x);
  c5_e_A = c5_yb_y;
  c5_e_B = c5_pe_x;
  c5_qe_x = c5_e_A;
  c5_ac_y = c5_e_B;
  c5_re_x = c5_qe_x;
  c5_bc_y = c5_ac_y;
  c5_cc_y = c5_re_x / c5_bc_y;
  c5_Ja[0] = 0.0;
  c5_Ja[6] = c5_e_y;
  c5_Ja[12] = c5_j_y;
  c5_Ja[18] = c5_l_y;
  c5_Ja[1] = 0.0;
  c5_Ja[7] = 0.0;
  c5_Ja[13] = ((c5_m_y - c5_n_y) - c5_o_y) - c5_p_y;
  c5_Ja[19] = c5_q_y;
  c5_Ja[2] = 1.0;
  c5_Ja[8] = c5_v_y;
  c5_Ja[14] = c5_bb_y;
  c5_Ja[20] = c5_db_y;
  c5_Ja[3] = 0.0;
  c5_Ja[9] = c5_gb_y;
  c5_Ja[15] = c5_kb_y;
  c5_Ja[21] = c5_ob_y;
  c5_Ja[4] = 0.0;
  c5_Ja[10] = -c5_gd_x;
  c5_Ja[16] = c5_pb_y;
  c5_Ja[22] = c5_qb_y;
  c5_Ja[5] = 0.0;
  c5_Ja[11] = c5_rb_y;
  c5_Ja[17] = c5_ud_x + c5_wb_y;
  c5_Ja[23] = c5_he_x + c5_cc_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i3 = 0; c5_i3 < 24; c5_i3++) {
    (*c5_b_Ja)[c5_i3] = c5_Ja[c5_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc5_SIMULACIO_MGD(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  real_T c5_b_inData[24];
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_u[24];
  const mxArray *c5_y = NULL;
  SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i4 = 0;
  for (c5_i5 = 0; c5_i5 < 4; c5_i5++) {
    for (c5_i6 = 0; c5_i6 < 6; c5_i6++) {
      c5_b_inData[c5_i6 + c5_i4] = (*(real_T (*)[24])c5_inData)[c5_i6 + c5_i4];
    }

    c5_i4 += 6;
  }

  c5_i7 = 0;
  for (c5_i8 = 0; c5_i8 < 4; c5_i8++) {
    for (c5_i9 = 0; c5_i9 < 6; c5_i9++) {
      c5_u[c5_i9 + c5_i7] = c5_b_inData[c5_i9 + c5_i7];
    }

    c5_i7 += 6;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 6, 4), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct *chartInstance,
  const mxArray *c5_Ja, const char_T *c5_identifier, real_T c5_y[24])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Ja), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_Ja);
}

static void c5_b_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[24])
{
  real_T c5_dv1[24];
  int32_T c5_i10;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c5_i10 = 0; c5_i10 < 24; c5_i10++) {
    c5_y[c5_i10] = c5_dv1[c5_i10];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_Ja;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[24];
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c5_Ja = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Ja), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_Ja);
  c5_i11 = 0;
  for (c5_i12 = 0; c5_i12 < 4; c5_i12++) {
    for (c5_i13 = 0; c5_i13 < 6; c5_i13++) {
      (*(real_T (*)[24])c5_outData)[c5_i13 + c5_i11] = c5_y[c5_i13 + c5_i11];
    }

    c5_i11 += 6;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_SIMULACIO_MGD_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[11];
  c5_ResolvedFunctionInfo (*c5_b_info)[11];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i14;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[11])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "cos";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[0].fileTimeLo = 1343830372U;
  (*c5_b_info)[0].fileTimeHi = 0U;
  (*c5_b_info)[0].mFileTimeLo = 0U;
  (*c5_b_info)[0].mFileTimeHi = 0U;
  (*c5_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[1].name = "eml_scalar_cos";
  (*c5_b_info)[1].dominantType = "double";
  (*c5_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c5_b_info)[1].fileTimeLo = 1286818722U;
  (*c5_b_info)[1].fileTimeHi = 0U;
  (*c5_b_info)[1].mFileTimeLo = 0U;
  (*c5_b_info)[1].mFileTimeHi = 0U;
  (*c5_b_info)[2].context = "";
  (*c5_b_info)[2].name = "mtimes";
  (*c5_b_info)[2].dominantType = "double";
  (*c5_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[2].fileTimeLo = 1289519692U;
  (*c5_b_info)[2].fileTimeHi = 0U;
  (*c5_b_info)[2].mFileTimeLo = 0U;
  (*c5_b_info)[2].mFileTimeHi = 0U;
  (*c5_b_info)[3].context = "";
  (*c5_b_info)[3].name = "sin";
  (*c5_b_info)[3].dominantType = "double";
  (*c5_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[3].fileTimeLo = 1343830386U;
  (*c5_b_info)[3].fileTimeHi = 0U;
  (*c5_b_info)[3].mFileTimeLo = 0U;
  (*c5_b_info)[3].mFileTimeHi = 0U;
  (*c5_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[4].name = "eml_scalar_sin";
  (*c5_b_info)[4].dominantType = "double";
  (*c5_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c5_b_info)[4].fileTimeLo = 1286818736U;
  (*c5_b_info)[4].fileTimeHi = 0U;
  (*c5_b_info)[4].mFileTimeLo = 0U;
  (*c5_b_info)[4].mFileTimeHi = 0U;
  (*c5_b_info)[5].context = "";
  (*c5_b_info)[5].name = "mrdivide";
  (*c5_b_info)[5].dominantType = "double";
  (*c5_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c5_b_info)[5].fileTimeLo = 1357951548U;
  (*c5_b_info)[5].fileTimeHi = 0U;
  (*c5_b_info)[5].mFileTimeLo = 1319729966U;
  (*c5_b_info)[5].mFileTimeHi = 0U;
  (*c5_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c5_b_info)[6].name = "rdivide";
  (*c5_b_info)[6].dominantType = "double";
  (*c5_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c5_b_info)[6].fileTimeLo = 1346510388U;
  (*c5_b_info)[6].fileTimeHi = 0U;
  (*c5_b_info)[6].mFileTimeLo = 0U;
  (*c5_b_info)[6].mFileTimeHi = 0U;
  (*c5_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c5_b_info)[7].name = "eml_scalexp_compatible";
  (*c5_b_info)[7].dominantType = "double";
  (*c5_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c5_b_info)[7].fileTimeLo = 1286818796U;
  (*c5_b_info)[7].fileTimeHi = 0U;
  (*c5_b_info)[7].mFileTimeLo = 0U;
  (*c5_b_info)[7].mFileTimeHi = 0U;
  (*c5_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c5_b_info)[8].name = "eml_div";
  (*c5_b_info)[8].dominantType = "double";
  (*c5_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c5_b_info)[8].fileTimeLo = 1313347810U;
  (*c5_b_info)[8].fileTimeHi = 0U;
  (*c5_b_info)[8].mFileTimeLo = 0U;
  (*c5_b_info)[8].mFileTimeHi = 0U;
  (*c5_b_info)[9].context = "";
  (*c5_b_info)[9].name = "tan";
  (*c5_b_info)[9].dominantType = "double";
  (*c5_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/tan.m";
  (*c5_b_info)[9].fileTimeLo = 1343830386U;
  (*c5_b_info)[9].fileTimeHi = 0U;
  (*c5_b_info)[9].mFileTimeLo = 0U;
  (*c5_b_info)[9].mFileTimeHi = 0U;
  (*c5_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/tan.m";
  (*c5_b_info)[10].name = "eml_scalar_tan";
  (*c5_b_info)[10].dominantType = "double";
  (*c5_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_tan.m";
  (*c5_b_info)[10].fileTimeLo = 1286818738U;
  (*c5_b_info)[10].fileTimeHi = 0U;
  (*c5_b_info)[10].mFileTimeLo = 0U;
  (*c5_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c5_i14 = 0; c5_i14 < 11; c5_i14++) {
    c5_r0 = &c5_info[c5_i14];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i14);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i14);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i14);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i14);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i14);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i14);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i14);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i14);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i15;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i15, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i15;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_SIMULACIO_MGD, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_SIMULACIO_MGD), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_SIMULACIO_MGD);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_SIMULACIO_MGDInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_SIMULACIO_MGDInstanceStruct
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

void sf_c5_SIMULACIO_MGD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3516608800U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1754392157U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2259636190U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(743316856U);
}

mxArray *sf_c5_SIMULACIO_MGD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xV4zcXUCKdGt9m1mlulcT");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_SIMULACIO_MGD_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c5_SIMULACIO_MGD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[25],T\"Ja\",},{M[8],M[0],T\"is_active_c5_SIMULACIO_MGD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_SIMULACIO_MGD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
    chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SIMULACIO_MGDMachineNumber_,
           5,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"ga");
          _SFD_SET_DATA_PROPS(1,1,1,0,"th");
          _SFD_SET_DATA_PROPS(2,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"q4");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Ja");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1365);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          real_T *c5_ga;
          real_T *c5_th;
          real_T *c5_q2;
          real_T *c5_q3;
          real_T *c5_q4;
          real_T (*c5_Ja)[24];
          c5_Ja = (real_T (*)[24])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c5_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_th = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_ga = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_ga);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_th);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_q2);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_q3);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_q4);
          _SFD_SET_DATA_VALUE_PTR(5U, *c5_Ja);
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
  return "tFTq4HXlvEhnRWEdwPftfH";
}

static void sf_opaque_initialize_c5_SIMULACIO_MGD(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar);
  initialize_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_SIMULACIO_MGD(void *chartInstanceVar)
{
  enable_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_SIMULACIO_MGD(void *chartInstanceVar)
{
  disable_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_SIMULACIO_MGD(void *chartInstanceVar)
{
  sf_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_SIMULACIO_MGD(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_SIMULACIO_MGD
    ((SFc5_SIMULACIO_MGDInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_SIMULACIO_MGD();/* state var info */
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

extern void sf_internal_set_sim_state_c5_SIMULACIO_MGD(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_SIMULACIO_MGD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_SIMULACIO_MGD(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_SIMULACIO_MGD(S);
}

static void sf_opaque_set_sim_state_c5_SIMULACIO_MGD(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_SIMULACIO_MGD(S, st);
}

static void sf_opaque_terminate_c5_SIMULACIO_MGD(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_SIMULACIO_MGDInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SIMULACIO_MGD_optimization_info();
    }

    finalize_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_SIMULACIO_MGD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_SIMULACIO_MGD((SFc5_SIMULACIO_MGDInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_SIMULACIO_MGD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SIMULACIO_MGD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1050464614U));
  ssSetChecksum1(S,(2765443586U));
  ssSetChecksum2(S,(3655444766U));
  ssSetChecksum3(S,(4198025183U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_SIMULACIO_MGD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_SIMULACIO_MGD(SimStruct *S)
{
  SFc5_SIMULACIO_MGDInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACIO_MGDInstanceStruct *)utMalloc(sizeof
    (SFc5_SIMULACIO_MGDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_SIMULACIO_MGDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_SIMULACIO_MGD;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_SIMULACIO_MGD;
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

void c5_SIMULACIO_MGD_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_SIMULACIO_MGD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_SIMULACIO_MGD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_SIMULACIO_MGD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_SIMULACIO_MGD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
