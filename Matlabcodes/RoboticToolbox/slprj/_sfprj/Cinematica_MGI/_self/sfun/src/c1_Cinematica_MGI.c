/* Include files */

#include "blascompat32.h"
#include "Cinematica_MGI_sfun.h"
#include "c1_Cinematica_MGI.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Cinematica_MGI_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[16] = { "nargin", "nargout", "d1",
  "d2", "a2", "a3", "a4", "a5", "a6", "q2", "q3", "q4", "MGD", "px", "py", "pz"
};

/* Function Declarations */
static void initialize_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);
static void initialize_params_c1_Cinematica_MGI
  (SFc1_Cinematica_MGIInstanceStruct *chartInstance);
static void enable_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);
static void disable_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_Cinematica_MGI
  (SFc1_Cinematica_MGIInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Cinematica_MGI
  (SFc1_Cinematica_MGIInstanceStruct *chartInstance);
static void set_sim_state_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);
static void sf_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);
static void initSimStructsc1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_pz, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_MGD, const char_T *c1_identifier, real_T
  c1_y[16]);
static void c1_d_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[16]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Cinematica_MGI, const char_T *
  c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Cinematica_MGI = 0U;
}

static void initialize_params_c1_Cinematica_MGI
  (SFc1_Cinematica_MGIInstanceStruct *chartInstance)
{
}

static void enable_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Cinematica_MGI
  (SFc1_Cinematica_MGIInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Cinematica_MGI
  (SFc1_Cinematica_MGIInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[16];
  const mxArray *c1_b_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T *c1_px;
  real_T *c1_py;
  real_T *c1_pz;
  real_T (*c1_MGD)[16];
  c1_pz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_py = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_px = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(5));
  for (c1_i0 = 0; c1_i0 < 16; c1_i0++) {
    c1_u[c1_i0] = (*c1_MGD)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = *c1_px;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_b_hoistedGlobal = *c1_py;
  c1_c_u = c1_b_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_c_hoistedGlobal = *c1_pz;
  c1_d_u = c1_c_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_Cinematica_MGI;
  c1_e_u = c1_d_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[16];
  int32_T c1_i1;
  real_T *c1_px;
  real_T *c1_py;
  real_T *c1_pz;
  real_T (*c1_MGD)[16];
  c1_pz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_py = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_px = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "MGD", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 16; c1_i1++) {
    (*c1_MGD)[c1_i1] = c1_dv0[c1_i1];
  }

  *c1_px = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "px");
  *c1_py = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "py");
  *c1_pz = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "pz");
  chartInstance->c1_is_active_c1_Cinematica_MGI = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
     "is_active_c1_Cinematica_MGI");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Cinematica_MGI(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

static void sf_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  real_T *c1_d1;
  real_T *c1_d2;
  real_T *c1_a2;
  real_T *c1_a3;
  real_T *c1_a4;
  real_T *c1_a5;
  real_T *c1_a6;
  real_T *c1_q2;
  real_T *c1_q3;
  real_T *c1_q4;
  real_T *c1_px;
  real_T *c1_py;
  real_T *c1_pz;
  real_T (*c1_MGD)[16];
  c1_pz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_py = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_px = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_a6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_a5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_a4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_a2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_d2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_d1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_d1, 0U);
  for (c1_i2 = 0; c1_i2 < 16; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_MGD)[c1_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_d2, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_a2, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_a3, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_a4, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_a5, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_a6, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_q2, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_q3, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_q4, 10U);
  _SFD_DATA_RANGE_CHECK(*c1_px, 11U);
  _SFD_DATA_RANGE_CHECK(*c1_py, 12U);
  _SFD_DATA_RANGE_CHECK(*c1_pz, 13U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_Cinematica_MGI(chartInstance);
  sf_debug_check_for_state_inconsistency(_Cinematica_MGIMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_i_hoistedGlobal;
  real_T c1_j_hoistedGlobal;
  real_T c1_d1;
  real_T c1_d2;
  real_T c1_a2;
  real_T c1_a3;
  real_T c1_a4;
  real_T c1_a5;
  real_T c1_a6;
  real_T c1_q2;
  real_T c1_q3;
  real_T c1_q4;
  uint32_T c1_debug_family_var_map[16];
  real_T c1_nargin = 10.0;
  real_T c1_nargout = 4.0;
  real_T c1_MGD[16];
  real_T c1_px;
  real_T c1_py;
  real_T c1_pz;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_a;
  real_T c1_b;
  real_T c1_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_e_a;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_f_a;
  real_T c1_f_b;
  real_T c1_f_y;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_g_y;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_h_a;
  real_T c1_h_b;
  real_T c1_h_y;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_i_a;
  real_T c1_i_b;
  real_T c1_i_y;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_j_a;
  real_T c1_j_b;
  real_T c1_j_y;
  real_T c1_k_a;
  real_T c1_k_b;
  real_T c1_k_y;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_jb_x;
  real_T c1_kb_x;
  real_T c1_l_a;
  real_T c1_l_b;
  real_T c1_l_y;
  real_T c1_lb_x;
  real_T c1_mb_x;
  real_T c1_m_a;
  real_T c1_m_b;
  real_T c1_m_y;
  real_T c1_n_a;
  real_T c1_n_b;
  real_T c1_n_y;
  real_T c1_nb_x;
  real_T c1_ob_x;
  real_T c1_pb_x;
  real_T c1_qb_x;
  real_T c1_o_a;
  real_T c1_o_b;
  real_T c1_o_y;
  real_T c1_rb_x;
  real_T c1_sb_x;
  real_T c1_p_a;
  real_T c1_p_b;
  real_T c1_p_y;
  real_T c1_q_a;
  real_T c1_q_b;
  real_T c1_q_y;
  real_T c1_tb_x;
  real_T c1_ub_x;
  real_T c1_vb_x;
  real_T c1_wb_x;
  real_T c1_r_a;
  real_T c1_r_b;
  real_T c1_r_y;
  real_T c1_xb_x;
  real_T c1_yb_x;
  real_T c1_ac_x;
  real_T c1_bc_x;
  real_T c1_s_a;
  real_T c1_s_b;
  real_T c1_s_y;
  real_T c1_cc_x;
  real_T c1_dc_x;
  real_T c1_ec_x;
  real_T c1_fc_x;
  real_T c1_t_a;
  real_T c1_t_b;
  real_T c1_t_y;
  real_T c1_gc_x;
  real_T c1_hc_x;
  real_T c1_ic_x;
  real_T c1_jc_x;
  real_T c1_u_a;
  real_T c1_u_b;
  real_T c1_u_y;
  real_T c1_kc_x;
  real_T c1_lc_x;
  real_T c1_v_a;
  real_T c1_v_b;
  real_T c1_v_y;
  real_T c1_mc_x;
  real_T c1_nc_x;
  real_T c1_oc_x;
  real_T c1_pc_x;
  real_T c1_w_a;
  real_T c1_w_b;
  real_T c1_w_y;
  real_T c1_x_a;
  real_T c1_x_b;
  real_T c1_x_y;
  real_T c1_qc_x;
  real_T c1_rc_x;
  real_T c1_sc_x;
  real_T c1_tc_x;
  real_T c1_y_a;
  real_T c1_y_b;
  real_T c1_y_y;
  real_T c1_ab_a;
  real_T c1_ab_b;
  real_T c1_ab_y;
  real_T c1_uc_x;
  real_T c1_vc_x;
  real_T c1_wc_x;
  real_T c1_xc_x;
  real_T c1_bb_a;
  real_T c1_bb_b;
  real_T c1_bb_y;
  real_T c1_yc_x;
  real_T c1_ad_x;
  real_T c1_cb_a;
  real_T c1_cb_b;
  real_T c1_cb_y;
  real_T c1_bd_x;
  real_T c1_cd_x;
  real_T c1_dd_x;
  real_T c1_ed_x;
  real_T c1_db_a;
  real_T c1_db_b;
  real_T c1_db_y;
  real_T c1_fd_x;
  real_T c1_gd_x;
  real_T c1_eb_a;
  real_T c1_eb_b;
  real_T c1_eb_y;
  real_T c1_hd_x;
  real_T c1_id_x;
  real_T c1_jd_x;
  real_T c1_kd_x;
  real_T c1_fb_a;
  real_T c1_fb_b;
  real_T c1_fb_y;
  real_T c1_ld_x;
  real_T c1_md_x;
  real_T c1_gb_a;
  real_T c1_gb_b;
  real_T c1_gb_y;
  real_T c1_nd_x;
  real_T c1_od_x;
  real_T c1_pd_x;
  real_T c1_qd_x;
  real_T c1_hb_a;
  real_T c1_hb_b;
  real_T c1_hb_y;
  real_T c1_rd_x;
  real_T c1_sd_x;
  real_T c1_ib_a;
  real_T c1_ib_b;
  real_T c1_ib_y;
  real_T c1_td_x;
  real_T c1_ud_x;
  real_T c1_vd_x;
  real_T c1_wd_x;
  real_T c1_jb_a;
  real_T c1_jb_b;
  real_T c1_jb_y;
  real_T c1_xd_x;
  real_T c1_yd_x;
  real_T c1_ae_x;
  real_T c1_be_x;
  real_T c1_kb_a;
  real_T c1_kb_b;
  real_T c1_kb_y;
  real_T c1_lb_a;
  real_T c1_lb_b;
  real_T c1_lb_y;
  real_T c1_ce_x;
  real_T c1_de_x;
  real_T c1_ee_x;
  real_T c1_fe_x;
  real_T c1_mb_a;
  real_T c1_mb_b;
  real_T c1_mb_y;
  real_T c1_ge_x;
  real_T c1_he_x;
  real_T c1_nb_a;
  real_T c1_nb_b;
  real_T c1_nb_y;
  real_T c1_ob_a;
  real_T c1_ob_b;
  real_T c1_ob_y;
  real_T c1_ie_x;
  real_T c1_je_x;
  real_T c1_ke_x;
  real_T c1_le_x;
  real_T c1_pb_a;
  real_T c1_pb_b;
  real_T c1_pb_y;
  real_T c1_me_x;
  real_T c1_ne_x;
  real_T c1_qb_a;
  real_T c1_qb_b;
  real_T c1_qb_y;
  real_T c1_rb_a;
  real_T c1_rb_b;
  real_T c1_rb_y;
  int32_T c1_i3;
  int32_T c1_i4;
  static real_T c1_dv1[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c1_i5;
  real_T *c1_b_d1;
  real_T *c1_b_d2;
  real_T *c1_b_a2;
  real_T *c1_b_a3;
  real_T *c1_b_a4;
  real_T *c1_b_a5;
  real_T *c1_b_a6;
  real_T *c1_b_q2;
  real_T *c1_b_q3;
  real_T *c1_b_q4;
  real_T *c1_b_px;
  real_T *c1_b_py;
  real_T *c1_b_pz;
  real_T (*c1_b_MGD)[16];
  c1_b_pz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_py = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_px = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_b_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_a6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_a5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_a4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_a2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_d2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_d1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_d1;
  c1_b_hoistedGlobal = *c1_b_d2;
  c1_c_hoistedGlobal = *c1_b_a2;
  c1_d_hoistedGlobal = *c1_b_a3;
  c1_e_hoistedGlobal = *c1_b_a4;
  c1_f_hoistedGlobal = *c1_b_a5;
  c1_g_hoistedGlobal = *c1_b_a6;
  c1_h_hoistedGlobal = *c1_b_q2;
  c1_i_hoistedGlobal = *c1_b_q3;
  c1_j_hoistedGlobal = *c1_b_q4;
  c1_d1 = c1_hoistedGlobal;
  c1_d2 = c1_b_hoistedGlobal;
  c1_a2 = c1_c_hoistedGlobal;
  c1_a3 = c1_d_hoistedGlobal;
  c1_a4 = c1_e_hoistedGlobal;
  c1_a5 = c1_f_hoistedGlobal;
  c1_a6 = c1_g_hoistedGlobal;
  c1_q2 = c1_h_hoistedGlobal;
  c1_q3 = c1_i_hoistedGlobal;
  c1_q4 = c1_j_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_d1, 2U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_d2, 3U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a2, 4U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a3, 5U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a4, 6U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a5, 7U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_a6, 8U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_q2, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_q3, 10U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_q4, 11U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_MGD, 12U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_px, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_py, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_pz, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_x = c1_q3;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_q4;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_a = c1_b_x;
  c1_b = c1_d_x;
  c1_y = c1_a * c1_b;
  c1_e_x = 1.5707963267948966 + c1_q2;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarCos(c1_f_x);
  c1_b_a = c1_y;
  c1_b_b = c1_f_x;
  c1_b_y = c1_b_a * c1_b_b;
  c1_g_x = 1.5707963267948966 + c1_q2;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_i_x = c1_q3;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarSin(c1_j_x);
  c1_c_a = c1_h_x;
  c1_c_b = c1_j_x;
  c1_c_y = c1_c_a * c1_c_b;
  c1_k_x = c1_q4;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarSin(c1_l_x);
  c1_d_a = c1_c_y;
  c1_d_b = c1_l_x;
  c1_d_y = c1_d_a * c1_d_b;
  c1_m_x = c1_q3;
  c1_n_x = c1_m_x;
  c1_n_x = muDoubleScalarCos(c1_n_x);
  c1_o_x = 1.5707963267948966 + c1_q2;
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarCos(c1_p_x);
  c1_e_a = -c1_n_x;
  c1_e_b = c1_p_x;
  c1_e_y = c1_e_a * c1_e_b;
  c1_q_x = c1_q4;
  c1_r_x = c1_q_x;
  c1_r_x = muDoubleScalarSin(c1_r_x);
  c1_f_a = c1_e_y;
  c1_f_b = c1_r_x;
  c1_f_y = c1_f_a * c1_f_b;
  c1_s_x = c1_q4;
  c1_t_x = c1_s_x;
  c1_t_x = muDoubleScalarCos(c1_t_x);
  c1_u_x = 1.5707963267948966 + c1_q2;
  c1_v_x = c1_u_x;
  c1_v_x = muDoubleScalarCos(c1_v_x);
  c1_g_a = c1_t_x;
  c1_g_b = c1_v_x;
  c1_g_y = c1_g_a * c1_g_b;
  c1_w_x = c1_q3;
  c1_x_x = c1_w_x;
  c1_x_x = muDoubleScalarSin(c1_x_x);
  c1_h_a = c1_g_y;
  c1_h_b = c1_x_x;
  c1_h_y = c1_h_a * c1_h_b;
  c1_y_x = 1.5707963267948966 + c1_q2;
  c1_ab_x = c1_y_x;
  c1_ab_x = muDoubleScalarSin(c1_ab_x);
  c1_bb_x = 1.5707963267948966 + c1_q2;
  c1_cb_x = c1_bb_x;
  c1_cb_x = muDoubleScalarCos(c1_cb_x);
  c1_i_a = c1_a2;
  c1_i_b = c1_cb_x;
  c1_i_y = c1_i_a * c1_i_b;
  c1_db_x = c1_q3;
  c1_eb_x = c1_db_x;
  c1_eb_x = muDoubleScalarCos(c1_eb_x);
  c1_fb_x = 1.5707963267948966 + c1_q2;
  c1_gb_x = c1_fb_x;
  c1_gb_x = muDoubleScalarCos(c1_gb_x);
  c1_j_a = c1_eb_x;
  c1_j_b = c1_gb_x;
  c1_j_y = c1_j_a * c1_j_b;
  c1_k_a = c1_j_y;
  c1_k_b = c1_a3 + c1_a4;
  c1_k_y = c1_k_a * c1_k_b;
  c1_hb_x = c1_q3;
  c1_ib_x = c1_hb_x;
  c1_ib_x = muDoubleScalarCos(c1_ib_x);
  c1_jb_x = c1_q4;
  c1_kb_x = c1_jb_x;
  c1_kb_x = muDoubleScalarCos(c1_kb_x);
  c1_l_a = c1_ib_x;
  c1_l_b = c1_kb_x;
  c1_l_y = c1_l_a * c1_l_b;
  c1_lb_x = 1.5707963267948966 + c1_q2;
  c1_mb_x = c1_lb_x;
  c1_mb_x = muDoubleScalarCos(c1_mb_x);
  c1_m_a = c1_l_y;
  c1_m_b = c1_mb_x;
  c1_m_y = c1_m_a * c1_m_b;
  c1_n_a = c1_m_y;
  c1_n_b = c1_a5 + c1_a6;
  c1_n_y = c1_n_a * c1_n_b;
  c1_nb_x = 1.5707963267948966 + c1_q2;
  c1_ob_x = c1_nb_x;
  c1_ob_x = muDoubleScalarCos(c1_ob_x);
  c1_pb_x = c1_q3;
  c1_qb_x = c1_pb_x;
  c1_qb_x = muDoubleScalarSin(c1_qb_x);
  c1_o_a = c1_ob_x;
  c1_o_b = c1_qb_x;
  c1_o_y = c1_o_a * c1_o_b;
  c1_rb_x = c1_q4;
  c1_sb_x = c1_rb_x;
  c1_sb_x = muDoubleScalarSin(c1_sb_x);
  c1_p_a = c1_o_y;
  c1_p_b = c1_sb_x;
  c1_p_y = c1_p_a * c1_p_b;
  c1_q_a = c1_p_y;
  c1_q_b = c1_a5 + c1_a6;
  c1_q_y = c1_q_a * c1_q_b;
  c1_tb_x = c1_q3;
  c1_ub_x = c1_tb_x;
  c1_ub_x = muDoubleScalarCos(c1_ub_x);
  c1_vb_x = c1_q4;
  c1_wb_x = c1_vb_x;
  c1_wb_x = muDoubleScalarSin(c1_wb_x);
  c1_r_a = -c1_ub_x;
  c1_r_b = c1_wb_x;
  c1_r_y = c1_r_a * c1_r_b;
  c1_xb_x = c1_q4;
  c1_yb_x = c1_xb_x;
  c1_yb_x = muDoubleScalarCos(c1_yb_x);
  c1_ac_x = c1_q3;
  c1_bc_x = c1_ac_x;
  c1_bc_x = muDoubleScalarSin(c1_bc_x);
  c1_s_a = c1_yb_x;
  c1_s_b = c1_bc_x;
  c1_s_y = c1_s_a * c1_s_b;
  c1_cc_x = c1_q3;
  c1_dc_x = c1_cc_x;
  c1_dc_x = muDoubleScalarSin(c1_dc_x);
  c1_ec_x = c1_q4;
  c1_fc_x = c1_ec_x;
  c1_fc_x = muDoubleScalarSin(c1_fc_x);
  c1_t_a = c1_dc_x;
  c1_t_b = c1_fc_x;
  c1_t_y = c1_t_a * c1_t_b;
  c1_gc_x = c1_q3;
  c1_hc_x = c1_gc_x;
  c1_hc_x = muDoubleScalarCos(c1_hc_x);
  c1_ic_x = c1_q4;
  c1_jc_x = c1_ic_x;
  c1_jc_x = muDoubleScalarCos(c1_jc_x);
  c1_u_a = c1_hc_x;
  c1_u_b = c1_jc_x;
  c1_u_y = c1_u_a * c1_u_b;
  c1_kc_x = c1_q3;
  c1_lc_x = c1_kc_x;
  c1_lc_x = muDoubleScalarSin(c1_lc_x);
  c1_v_a = c1_lc_x;
  c1_v_b = c1_a3 + c1_a4;
  c1_v_y = c1_v_a * c1_v_b;
  c1_mc_x = c1_q3;
  c1_nc_x = c1_mc_x;
  c1_nc_x = muDoubleScalarCos(c1_nc_x);
  c1_oc_x = c1_q4;
  c1_pc_x = c1_oc_x;
  c1_pc_x = muDoubleScalarSin(c1_pc_x);
  c1_w_a = c1_nc_x;
  c1_w_b = c1_pc_x;
  c1_w_y = c1_w_a * c1_w_b;
  c1_x_a = c1_w_y;
  c1_x_b = c1_a5 + c1_a6;
  c1_x_y = c1_x_a * c1_x_b;
  c1_qc_x = c1_q4;
  c1_rc_x = c1_qc_x;
  c1_rc_x = muDoubleScalarCos(c1_rc_x);
  c1_sc_x = c1_q3;
  c1_tc_x = c1_sc_x;
  c1_tc_x = muDoubleScalarSin(c1_tc_x);
  c1_y_a = c1_rc_x;
  c1_y_b = c1_tc_x;
  c1_y_y = c1_y_a * c1_y_b;
  c1_ab_a = c1_y_y;
  c1_ab_b = c1_a5 + c1_a6;
  c1_ab_y = c1_ab_a * c1_ab_b;
  c1_uc_x = c1_q3;
  c1_vc_x = c1_uc_x;
  c1_vc_x = muDoubleScalarCos(c1_vc_x);
  c1_wc_x = c1_q4;
  c1_xc_x = c1_wc_x;
  c1_xc_x = muDoubleScalarCos(c1_xc_x);
  c1_bb_a = c1_vc_x;
  c1_bb_b = c1_xc_x;
  c1_bb_y = c1_bb_a * c1_bb_b;
  c1_yc_x = 1.5707963267948966 + c1_q2;
  c1_ad_x = c1_yc_x;
  c1_ad_x = muDoubleScalarSin(c1_ad_x);
  c1_cb_a = c1_bb_y;
  c1_cb_b = c1_ad_x;
  c1_cb_y = c1_cb_a * c1_cb_b;
  c1_bd_x = c1_q3;
  c1_cd_x = c1_bd_x;
  c1_cd_x = muDoubleScalarSin(c1_cd_x);
  c1_dd_x = c1_q4;
  c1_ed_x = c1_dd_x;
  c1_ed_x = muDoubleScalarSin(c1_ed_x);
  c1_db_a = c1_cd_x;
  c1_db_b = c1_ed_x;
  c1_db_y = c1_db_a * c1_db_b;
  c1_fd_x = 1.5707963267948966 + c1_q2;
  c1_gd_x = c1_fd_x;
  c1_gd_x = muDoubleScalarSin(c1_gd_x);
  c1_eb_a = c1_db_y;
  c1_eb_b = c1_gd_x;
  c1_eb_y = c1_eb_a * c1_eb_b;
  c1_hd_x = c1_q3;
  c1_id_x = c1_hd_x;
  c1_id_x = muDoubleScalarCos(c1_id_x);
  c1_jd_x = c1_q4;
  c1_kd_x = c1_jd_x;
  c1_kd_x = muDoubleScalarSin(c1_kd_x);
  c1_fb_a = -c1_id_x;
  c1_fb_b = c1_kd_x;
  c1_fb_y = c1_fb_a * c1_fb_b;
  c1_ld_x = 1.5707963267948966 + c1_q2;
  c1_md_x = c1_ld_x;
  c1_md_x = muDoubleScalarSin(c1_md_x);
  c1_gb_a = c1_fb_y;
  c1_gb_b = c1_md_x;
  c1_gb_y = c1_gb_a * c1_gb_b;
  c1_nd_x = c1_q4;
  c1_od_x = c1_nd_x;
  c1_od_x = muDoubleScalarCos(c1_od_x);
  c1_pd_x = c1_q3;
  c1_qd_x = c1_pd_x;
  c1_qd_x = muDoubleScalarSin(c1_qd_x);
  c1_hb_a = c1_od_x;
  c1_hb_b = c1_qd_x;
  c1_hb_y = c1_hb_a * c1_hb_b;
  c1_rd_x = 1.5707963267948966 + c1_q2;
  c1_sd_x = c1_rd_x;
  c1_sd_x = muDoubleScalarSin(c1_sd_x);
  c1_ib_a = c1_hb_y;
  c1_ib_b = c1_sd_x;
  c1_ib_y = c1_ib_a * c1_ib_b;
  c1_td_x = 1.5707963267948966 + c1_q2;
  c1_ud_x = c1_td_x;
  c1_ud_x = muDoubleScalarCos(c1_ud_x);
  c1_vd_x = 1.5707963267948966 + c1_q2;
  c1_wd_x = c1_vd_x;
  c1_wd_x = muDoubleScalarSin(c1_wd_x);
  c1_jb_a = c1_a2;
  c1_jb_b = c1_wd_x;
  c1_jb_y = c1_jb_a * c1_jb_b;
  c1_xd_x = c1_q3;
  c1_yd_x = c1_xd_x;
  c1_yd_x = muDoubleScalarCos(c1_yd_x);
  c1_ae_x = 1.5707963267948966 + c1_q2;
  c1_be_x = c1_ae_x;
  c1_be_x = muDoubleScalarSin(c1_be_x);
  c1_kb_a = c1_yd_x;
  c1_kb_b = c1_be_x;
  c1_kb_y = c1_kb_a * c1_kb_b;
  c1_lb_a = c1_kb_y;
  c1_lb_b = c1_a3 + c1_a4;
  c1_lb_y = c1_lb_a * c1_lb_b;
  c1_ce_x = c1_q3;
  c1_de_x = c1_ce_x;
  c1_de_x = muDoubleScalarCos(c1_de_x);
  c1_ee_x = c1_q4;
  c1_fe_x = c1_ee_x;
  c1_fe_x = muDoubleScalarCos(c1_fe_x);
  c1_mb_a = c1_de_x;
  c1_mb_b = c1_fe_x;
  c1_mb_y = c1_mb_a * c1_mb_b;
  c1_ge_x = 1.5707963267948966 + c1_q2;
  c1_he_x = c1_ge_x;
  c1_he_x = muDoubleScalarSin(c1_he_x);
  c1_nb_a = c1_mb_y;
  c1_nb_b = c1_he_x;
  c1_nb_y = c1_nb_a * c1_nb_b;
  c1_ob_a = c1_nb_y;
  c1_ob_b = c1_a5 + c1_a6;
  c1_ob_y = c1_ob_a * c1_ob_b;
  c1_ie_x = c1_q3;
  c1_je_x = c1_ie_x;
  c1_je_x = muDoubleScalarSin(c1_je_x);
  c1_ke_x = c1_q4;
  c1_le_x = c1_ke_x;
  c1_le_x = muDoubleScalarSin(c1_le_x);
  c1_pb_a = c1_je_x;
  c1_pb_b = c1_le_x;
  c1_pb_y = c1_pb_a * c1_pb_b;
  c1_me_x = 1.5707963267948966 + c1_q2;
  c1_ne_x = c1_me_x;
  c1_ne_x = muDoubleScalarSin(c1_ne_x);
  c1_qb_a = c1_pb_y;
  c1_qb_b = c1_ne_x;
  c1_qb_y = c1_qb_a * c1_qb_b;
  c1_rb_a = c1_qb_y;
  c1_rb_b = c1_a5 + c1_a6;
  c1_rb_y = c1_rb_a * c1_rb_b;
  c1_MGD[0] = c1_b_y - c1_d_y;
  c1_MGD[4] = c1_f_y - c1_h_y;
  c1_MGD[8] = c1_ab_x;
  c1_MGD[12] = ((c1_i_y + c1_k_y) + c1_n_y) - c1_q_y;
  c1_MGD[1] = c1_r_y - c1_s_y;
  c1_MGD[5] = c1_t_y - c1_u_y;
  c1_MGD[9] = 0.0;
  c1_MGD[13] = ((-c1_d2 - c1_v_y) - c1_x_y) - c1_ab_y;
  c1_MGD[2] = c1_cb_y - c1_eb_y;
  c1_MGD[6] = c1_gb_y - c1_ib_y;
  c1_MGD[10] = -c1_ud_x;
  c1_MGD[14] = (((c1_d1 + c1_jb_y) + c1_lb_y) + c1_ob_y) - c1_rb_y;
  c1_i3 = 0;
  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    c1_MGD[c1_i3 + 3] = c1_dv1[c1_i4];
    c1_i3 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_px = c1_MGD[12];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_py = c1_MGD[13];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_pz = c1_MGD[14];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -18);
  sf_debug_symbol_scope_pop();
  for (c1_i5 = 0; c1_i5 < 16; c1_i5++) {
    (*c1_b_MGD)[c1_i5] = c1_MGD[c1_i5];
  }

  *c1_b_px = c1_px;
  *c1_b_py = c1_py;
  *c1_b_pz = c1_pz;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_Cinematica_MGI(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc1_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_pz, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_pz), &c1_thisId);
  sf_mex_destroy(&c1_pz);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_pz;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc1_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c1_pz = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_pz), &c1_thisId);
  sf_mex_destroy(&c1_pz);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T c1_b_inData[16];
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_u[16];
  const mxArray *c1_y = NULL;
  SFc1_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc1_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i6 = 0;
  for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
    for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
      c1_b_inData[c1_i8 + c1_i6] = (*(real_T (*)[16])c1_inData)[c1_i8 + c1_i6];
    }

    c1_i6 += 4;
  }

  c1_i9 = 0;
  for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
    for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
      c1_u[c1_i11 + c1_i9] = c1_b_inData[c1_i11 + c1_i9];
    }

    c1_i9 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_MGD, const char_T *c1_identifier, real_T
  c1_y[16])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_MGD), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_MGD);
}

static void c1_d_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[16])
{
  real_T c1_dv2[16];
  int32_T c1_i12;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c1_i12 = 0; c1_i12 < 16; c1_i12++) {
    c1_y[c1_i12] = c1_dv2[c1_i12];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_MGD;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[16];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  SFc1_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc1_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c1_MGD = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_MGD), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_MGD);
  c1_i13 = 0;
  for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
    for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
      (*(real_T (*)[16])c1_outData)[c1_i15 + c1_i13] = c1_y[c1_i15 + c1_i13];
    }

    c1_i13 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Cinematica_MGI_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[8];
  c1_ResolvedFunctionInfo (*c1_b_info)[8];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i16;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[8])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "cos";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c1_b_info)[0].fileTimeLo = 3359288576U;
  (*c1_b_info)[0].fileTimeHi = 30108069U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c1_b_info)[1].name = "eml_scalar_cos";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c1_b_info)[1].fileTimeLo = 3519288576U;
  (*c1_b_info)[1].fileTimeHi = 30108069U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context = "";
  (*c1_b_info)[2].name = "mtimes";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[2].fileTimeLo = 2169964032U;
  (*c1_b_info)[2].fileTimeHi = 30114358U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context = "";
  (*c1_b_info)[3].name = "mrdivide";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[3].fileTimeLo = 714027776U;
  (*c1_b_info)[3].fileTimeHi = 30130994U;
  (*c1_b_info)[3].mFileTimeLo = 2169964032U;
  (*c1_b_info)[3].mFileTimeHi = 30114358U;
  (*c1_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[4].name = "rdivide";
  (*c1_b_info)[4].dominantType = "double";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[4].fileTimeLo = 444321280U;
  (*c1_b_info)[4].fileTimeHi = 30108070U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[5].name = "eml_div";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[5].fileTimeLo = 3279288576U;
  (*c1_b_info)[5].fileTimeHi = 30108069U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context = "";
  (*c1_b_info)[6].name = "sin";
  (*c1_b_info)[6].dominantType = "double";
  (*c1_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c1_b_info)[6].fileTimeLo = 3799288576U;
  (*c1_b_info)[6].fileTimeHi = 30108069U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c1_b_info)[7].name = "eml_scalar_sin";
  (*c1_b_info)[7].dominantType = "double";
  (*c1_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c1_b_info)[7].fileTimeLo = 3659288576U;
  (*c1_b_info)[7].fileTimeHi = 30108069U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8));
  for (c1_i16 = 0; c1_i16 < 8; c1_i16++) {
    c1_r0 = &c1_info[c1_i16];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i16);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i16);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc1_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i17;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i17, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i17;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc1_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Cinematica_MGI, const char_T *
  c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Cinematica_MGI), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Cinematica_MGI);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_Cinematica_MGI_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3717546792U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(146543588U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2075613740U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2902611202U);
}

mxArray *sf_c1_Cinematica_MGI_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1807771605U);
    pr[1] = (double)(355015715U);
    pr[2] = (double)(984399304U);
    pr[3] = (double)(1384197483U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_Cinematica_MGI(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"MGD\",},{M[1],M[16],T\"px\",},{M[1],M[17],T\"py\",},{M[1],M[18],T\"pz\",},{M[8],M[0],T\"is_active_c1_Cinematica_MGI\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Cinematica_MGI_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Cinematica_MGIInstanceStruct *chartInstance;
    chartInstance = (SFc1_Cinematica_MGIInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Cinematica_MGIMachineNumber_,
           1,
           1,
           1,
           14,
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
          init_script_number_translation(_Cinematica_MGIMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Cinematica_MGIMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Cinematica_MGIMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"d1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"MGD");
          _SFD_SET_DATA_PROPS(2,1,1,0,"d2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"a2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"a3");
          _SFD_SET_DATA_PROPS(5,1,1,0,"a4");
          _SFD_SET_DATA_PROPS(6,1,1,0,"a5");
          _SFD_SET_DATA_PROPS(7,1,1,0,"a6");
          _SFD_SET_DATA_PROPS(8,1,1,0,"q2");
          _SFD_SET_DATA_PROPS(9,1,1,0,"q3");
          _SFD_SET_DATA_PROPS(10,1,1,0,"q4");
          _SFD_SET_DATA_PROPS(11,2,0,1,"px");
          _SFD_SET_DATA_PROPS(12,2,0,1,"py");
          _SFD_SET_DATA_PROPS(13,2,0,1,"pz");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,6096);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_d1;
          real_T *c1_d2;
          real_T *c1_a2;
          real_T *c1_a3;
          real_T *c1_a4;
          real_T *c1_a5;
          real_T *c1_a6;
          real_T *c1_q2;
          real_T *c1_q3;
          real_T *c1_q4;
          real_T *c1_px;
          real_T *c1_py;
          real_T *c1_pz;
          real_T (*c1_MGD)[16];
          c1_pz = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_py = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_px = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_q4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_q3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_a6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_a5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_a4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_a3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_a2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_d2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_MGD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_d1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_d1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_MGD);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_d2);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_a2);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_a3);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_a4);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_a5);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_a6);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_q2);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_q3);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_q4);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_px);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_py);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_pz);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Cinematica_MGIMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_Cinematica_MGI(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Cinematica_MGIInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Cinematica_MGI(void *chartInstanceVar)
{
  enable_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Cinematica_MGI(void *chartInstanceVar)
{
  disable_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Cinematica_MGI(void *chartInstanceVar)
{
  sf_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Cinematica_MGI(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Cinematica_MGI
    ((SFc1_Cinematica_MGIInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Cinematica_MGI();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Cinematica_MGI(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Cinematica_MGI();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Cinematica_MGI(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Cinematica_MGI(S);
}

static void sf_opaque_set_sim_state_c1_Cinematica_MGI(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_Cinematica_MGI(S, st);
}

static void sf_opaque_terminate_c1_Cinematica_MGI(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Cinematica_MGIInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Cinematica_MGI(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Cinematica_MGI((SFc1_Cinematica_MGIInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Cinematica_MGI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Cinematica_MGI","Cinematica_MGI",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Cinematica_MGI","Cinematica_MGI",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Cinematica_MGI",
      "Cinematica_MGI",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Cinematica_MGI","Cinematica_MGI",1,
        10);
      sf_mark_chart_reusable_outputs(S,"Cinematica_MGI","Cinematica_MGI",1,4);
    }

    sf_set_rtw_dwork_info(S,"Cinematica_MGI","Cinematica_MGI",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(343922675U));
  ssSetChecksum1(S,(3449822969U));
  ssSetChecksum2(S,(1877714807U));
  ssSetChecksum3(S,(2185293634U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_Cinematica_MGI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Cinematica_MGI", "Cinematica_MGI",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Cinematica_MGI(SimStruct *S)
{
  SFc1_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc1_Cinematica_MGIInstanceStruct *)malloc(sizeof
    (SFc1_Cinematica_MGIInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Cinematica_MGIInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Cinematica_MGI;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Cinematica_MGI;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Cinematica_MGI;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Cinematica_MGI;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Cinematica_MGI;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Cinematica_MGI;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Cinematica_MGI;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Cinematica_MGI;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Cinematica_MGI;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Cinematica_MGI;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Cinematica_MGI;
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

void c1_Cinematica_MGI_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Cinematica_MGI(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Cinematica_MGI(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Cinematica_MGI(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Cinematica_MGI_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
