/* Include files */

#include "blascompat32.h"
#include "Cinematica_MGI_sfun.h"
#include "c2_Cinematica_MGI.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Cinematica_MGI_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[23] = { "a2", "a3", "a4", "a5", "a6",
  "a34", "a56", "r", "r_a2", "ctheta4n", "cthetad", "Ctheta4", "Stheta4", "B",
  "alpha", "nargin", "nargout", "px", "py", "pz", "theta2", "theta3", "theta4" };

/* Function Declarations */
static void initialize_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);
static void initialize_params_c2_Cinematica_MGI
  (SFc2_Cinematica_MGIInstanceStruct *chartInstance);
static void enable_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);
static void disable_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_Cinematica_MGI
  (SFc2_Cinematica_MGIInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Cinematica_MGI
  (SFc2_Cinematica_MGIInstanceStruct *chartInstance);
static void set_sim_state_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);
static void sf_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);
static void initSimStructsc2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static creal_T c2_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_theta4, const char_T *c2_identifier);
static creal_T c2_b_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_theta2, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[30]);
static real_T c2_mpower(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
  c2_a);
static real_T c2_power(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
  c2_a, real_T c2_b);
static void c2_eml_scalar_eg(SFc2_Cinematica_MGIInstanceStruct *chartInstance);
static void c2_eml_error(SFc2_Cinematica_MGIInstanceStruct *chartInstance);
static real_T c2_sqrt(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
                      c2_x);
static void c2_b_eml_error(SFc2_Cinematica_MGIInstanceStruct *chartInstance);
static real_T c2_eml_scalar_hypot(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, real_T c2_x, real_T c2_y);
static creal_T c2_mrdivide(SFc2_Cinematica_MGIInstanceStruct *chartInstance,
  creal_T c2_A, real_T c2_B);
static void c2_eml_warning(SFc2_Cinematica_MGIInstanceStruct *chartInstance);
static creal_T c2_eml_scalar_atan(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, creal_T c2_x);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Cinematica_MGI, const char_T *
  c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
                      *c2_x);
static void c2_b_eml_scalar_atan(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, creal_T *c2_x);
static void init_dsm_address_info(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Cinematica_MGI = 0U;
}

static void initialize_params_c2_Cinematica_MGI
  (SFc2_Cinematica_MGIInstanceStruct *chartInstance)
{
}

static void enable_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Cinematica_MGI
  (SFc2_Cinematica_MGIInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Cinematica_MGI
  (SFc2_Cinematica_MGIInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  creal_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  creal_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T *c2_theta2;
  creal_T *c2_theta3;
  creal_T *c2_theta4;
  c2_theta4 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_theta3 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_theta2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4));
  c2_hoistedGlobal = *c2_theta2;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u.re = c2_theta3->re;
  c2_b_u.im = c2_theta3->im;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 1U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_u.re = c2_theta4->re;
  c2_c_u.im = c2_theta4->im;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 1U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_Cinematica_MGI;
  c2_d_u = c2_b_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_theta2;
  creal_T *c2_theta3;
  creal_T *c2_theta4;
  c2_theta4 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_theta3 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_theta2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_theta2 = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "theta2");
  *c2_theta3 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "theta3");
  *c2_theta4 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    2)), "theta4");
  chartInstance->c2_is_active_c2_Cinematica_MGI = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_active_c2_Cinematica_MGI");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Cinematica_MGI(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

static void sf_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  real_T *c2_px;
  real_T *c2_py;
  real_T *c2_pz;
  real_T *c2_theta2;
  c2_theta2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_pz = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_py = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_px = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_px, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_py, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_pz, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_theta2, 3U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Cinematica_MGI(chartInstance);
  sf_debug_check_for_state_inconsistency(_Cinematica_MGIMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_px;
  real_T c2_py;
  real_T c2_pz;
  uint32_T c2_debug_family_var_map[23];
  real_T c2_a2;
  real_T c2_a3;
  real_T c2_a4;
  real_T c2_a5;
  real_T c2_a6;
  real_T c2_a34;
  real_T c2_a56;
  real_T c2_r;
  real_T c2_r_a2;
  real_T c2_ctheta4n;
  real_T c2_cthetad;
  real_T c2_Ctheta4;
  creal_T c2_Stheta4;
  real_T c2_B;
  creal_T c2_alpha;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 3.0;
  real_T c2_theta2;
  creal_T c2_theta3;
  creal_T c2_theta4;
  real_T c2_A;
  real_T c2_b_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_a;
  real_T c2_c;
  real_T c2_b_c;
  real_T c2_c_c;
  real_T c2_b_A;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_b_a;
  real_T c2_d_c;
  creal_T c2_i_x;
  real_T c2_yr;
  real_T c2_yi;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_z;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_b_z;
  boolean_T c2_b0;
  boolean_T c2_b1;
  boolean_T c2_b;
  real_T c2_p_x;
  boolean_T c2_b_b;
  real_T c2_q_x;
  boolean_T c2_c_b;
  real_T c2_absxr;
  real_T c2_absxi;
  real_T c2_c_a;
  real_T c2_d_a;
  real_T c2_absxd2;
  real_T c2_r_x;
  real_T c2_f_y;
  real_T c2_s_x;
  real_T c2_g_y;
  real_T c2_t_x;
  real_T c2_h_y;
  real_T c2_c_z;
  real_T c2_u_x;
  real_T c2_i_y;
  real_T c2_v_x;
  real_T c2_j_y;
  real_T c2_w_x;
  real_T c2_k_y;
  real_T c2_d_z;
  real_T c2_x_x;
  real_T c2_l_y;
  real_T c2_y_x;
  real_T c2_m_y;
  real_T c2_ab_x;
  real_T c2_n_y;
  real_T c2_e_z;
  creal_T c2_b_u;
  const mxArray *c2_o_y = NULL;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_p_y;
  creal_T c2_c_u;
  const mxArray *c2_q_y = NULL;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_db_x;
  real_T c2_r_y;
  real_T c2_eb_x;
  real_T c2_s_y;
  real_T c2_fb_x;
  real_T c2_t_y;
  real_T c2_u_y;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_d_u;
  const mxArray *c2_v_y = NULL;
  real_T c2_d_b;
  real_T c2_w_y;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_x_y;
  creal_T c2_e_u;
  const mxArray *c2_y_y = NULL;
  creal_T c2_f_u;
  const mxArray *c2_ab_y = NULL;
  real_T *c2_b_px;
  real_T *c2_b_py;
  real_T *c2_b_pz;
  real_T *c2_b_theta2;
  creal_T *c2_b_theta3;
  creal_T *c2_b_theta4;
  boolean_T guard1 = FALSE;
  c2_b_theta4 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_theta3 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_theta2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_pz = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_py = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_px = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_px;
  c2_b_hoistedGlobal = *c2_b_py;
  c2_c_hoistedGlobal = *c2_b_pz;
  c2_px = c2_hoistedGlobal;
  c2_py = c2_b_hoistedGlobal;
  c2_pz = c2_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_a2, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_a3, 1U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a4, 2U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a5, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a6, 4U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a34, 5U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a56, 6U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_r, 7U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r_a2, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_ctheta4n, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_cthetad, 10U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_Ctheta4, 11U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_Stheta4, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_B, 13U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_alpha, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 15U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_px, 17U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_py, 18U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_pz, 19U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta2, 20U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta3, 21U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_theta4, 22U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_a2 = 7.907;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_a3 = 8.862;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_a4 = 15.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_a5 = 8.862;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_a6 = 15.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_a34 = 23.862000000000002;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_a56 = 23.862000000000002;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_r = c2_mpower(chartInstance, c2_px) + c2_mpower(chartInstance, c2_pz);
  c2_b_sqrt(chartInstance, &c2_r);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_r_a2 = c2_r - c2_a2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_A = c2_px;
  c2_b_B = c2_pz;
  c2_x = c2_A;
  c2_y = c2_b_B;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_c_x = c2_b_x;
  c2_c_y = c2_b_y;
  c2_d_y = c2_c_x / c2_c_y;
  c2_d_x = c2_d_y;
  c2_theta2 = c2_d_x;
  c2_e_x = c2_theta2;
  c2_theta2 = c2_e_x;
  c2_theta2 = muDoubleScalarAtan(c2_theta2);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_a = c2_pz;
  c2_c = c2_power(chartInstance, c2_a, 2.0);
  c2_b_c = c2_power(chartInstance, 23.862000000000002, 2.0);
  c2_c_c = c2_power(chartInstance, 23.862000000000002, 2.0);
  c2_ctheta4n = (((c2_mpower(chartInstance, c2_px) + c2_mpower(chartInstance,
    c2_py)) + c2_c) - c2_b_c) - c2_c_c;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_cthetad = 1138.7900880000002;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_b_A = c2_ctheta4n;
  c2_f_x = c2_b_A;
  c2_g_x = c2_f_x;
  c2_h_x = c2_g_x;
  c2_Ctheta4 = c2_h_x / 1138.7900880000002;
  sf_mex_printf("%s =\\n", "Ctheta4");
  c2_u = c2_Ctheta4;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_e_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_b_a = c2_Ctheta4;
  c2_d_c = c2_power(chartInstance, c2_b_a, 2.0);
  c2_i_x.re = 1.0 - c2_d_c;
  c2_i_x.im = 0.0;
  c2_Stheta4 = c2_i_x;
  c2_i_x = c2_Stheta4;
  c2_Stheta4 = c2_i_x;
  c2_i_x = c2_Stheta4;
  c2_Stheta4 = c2_i_x;
  if (c2_Stheta4.im == 0.0) {
    if (c2_Stheta4.re < 0.0) {
      c2_yr = 0.0;
      c2_yi = muDoubleScalarSqrt(muDoubleScalarAbs(c2_Stheta4.re));
    } else {
      c2_yr = muDoubleScalarSqrt(c2_Stheta4.re);
      c2_yi = 0.0;
    }
  } else if (c2_Stheta4.re == 0.0) {
    if (c2_Stheta4.im < 0.0) {
      c2_j_x = -c2_Stheta4.im;
      c2_k_x = c2_j_x;
      c2_l_x = c2_k_x;
      c2_z = c2_l_x / 2.0;
      c2_yr = muDoubleScalarSqrt(c2_z);
      c2_yi = -c2_yr;
    } else {
      c2_m_x = c2_Stheta4.im;
      c2_n_x = c2_m_x;
      c2_o_x = c2_n_x;
      c2_b_z = c2_o_x / 2.0;
      c2_yr = muDoubleScalarSqrt(c2_b_z);
      c2_yi = c2_yr;
    }
  } else {
    c2_i_x = c2_Stheta4;
    c2_b0 = muDoubleScalarIsNaN(c2_i_x.re);
    c2_b1 = muDoubleScalarIsNaN(c2_i_x.im);
    c2_b = (c2_b0 || c2_b1);
    if (c2_b) {
      c2_yr = rtNaN;
      c2_yi = rtNaN;
    } else {
      c2_p_x = c2_Stheta4.im;
      c2_b_b = muDoubleScalarIsInf(c2_p_x);
      if (c2_b_b) {
        c2_yr = rtInf;
        c2_yi = c2_Stheta4.im;
      } else {
        c2_q_x = c2_Stheta4.re;
        c2_c_b = muDoubleScalarIsInf(c2_q_x);
        if (c2_c_b) {
          if (c2_Stheta4.re < 0.0) {
            c2_yr = 0.0;
            c2_yi = rtInf;
          } else {
            c2_yr = rtInf;
            c2_yi = 0.0;
          }
        } else {
          c2_absxr = muDoubleScalarAbs(c2_Stheta4.re);
          c2_absxi = muDoubleScalarAbs(c2_Stheta4.im);
          guard1 = FALSE;
          if (c2_absxr > 4.4942328371557893E+307) {
            guard1 = TRUE;
          } else if (c2_absxi > 4.4942328371557893E+307) {
            guard1 = TRUE;
          } else {
            c2_yr = muDoubleScalarSqrt((c2_eml_scalar_hypot(chartInstance,
              c2_absxr, c2_absxi) + c2_absxr) * 0.5);
          }

          if (guard1 == TRUE) {
            c2_c_a = c2_absxr;
            c2_absxr = c2_c_a * 0.5;
            c2_d_a = c2_absxi;
            c2_absxi = c2_d_a * 0.5;
            c2_absxd2 = c2_eml_scalar_hypot(chartInstance, c2_absxr, c2_absxi);
            if (c2_absxd2 > c2_absxr) {
              c2_r_x = c2_absxr;
              c2_f_y = c2_absxd2;
              c2_s_x = c2_r_x;
              c2_g_y = c2_f_y;
              c2_t_x = c2_s_x;
              c2_h_y = c2_g_y;
              c2_c_z = c2_t_x / c2_h_y;
              c2_yr = muDoubleScalarSqrt(c2_absxd2) * muDoubleScalarSqrt(1.0 +
                c2_c_z);
            } else {
              c2_yr = muDoubleScalarSqrt(c2_absxd2) * 1.4142135623730951;
            }
          }

          if (c2_Stheta4.re > 0.0) {
            c2_u_x = c2_Stheta4.im;
            c2_i_y = c2_yr;
            c2_v_x = c2_u_x;
            c2_j_y = c2_i_y;
            c2_w_x = c2_v_x;
            c2_k_y = c2_j_y;
            c2_d_z = c2_w_x / c2_k_y;
            c2_yi = 0.5 * c2_d_z;
          } else {
            if (c2_Stheta4.im < 0.0) {
              c2_yi = -c2_yr;
            } else {
              c2_yi = c2_yr;
            }

            c2_x_x = c2_Stheta4.im;
            c2_l_y = c2_yi;
            c2_y_x = c2_x_x;
            c2_m_y = c2_l_y;
            c2_ab_x = c2_y_x;
            c2_n_y = c2_m_y;
            c2_e_z = c2_ab_x / c2_n_y;
            c2_yr = 0.5 * c2_e_z;
          }
        }
      }
    }
  }

  c2_Stheta4.re = c2_yr;
  c2_Stheta4.im = c2_yi;
  sf_mex_printf("%s =\\n", "Stheta4");
  c2_b_u = c2_Stheta4;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_b_u, 0, 1U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_o_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_i_x = c2_mrdivide(chartInstance, c2_Stheta4, c2_Ctheta4);
  c2_theta4 = c2_i_x;
  if (c2_theta4.re == 0.0) {
    c2_bb_x = c2_theta4.im;
    c2_cb_x = c2_bb_x;
    c2_p_y = muDoubleScalarAbs(c2_cb_x);
    if (c2_p_y == 1.0) {
      c2_eml_warning(chartInstance);
    }
  }

  c2_b_eml_scalar_atan(chartInstance, &c2_theta4);
  sf_mex_printf("%s =\\n", "theta4");
  c2_c_u = c2_theta4;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_c_u, 0, 1U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_q_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_c_A = c2_py;
  c2_c_B = c2_r_a2;
  c2_db_x = c2_c_A;
  c2_r_y = c2_c_B;
  c2_eb_x = c2_db_x;
  c2_s_y = c2_r_y;
  c2_fb_x = c2_eb_x;
  c2_t_y = c2_s_y;
  c2_u_y = c2_fb_x / c2_t_y;
  c2_gb_x = c2_u_y;
  c2_B = c2_gb_x;
  c2_hb_x = c2_B;
  c2_B = c2_hb_x;
  c2_B = muDoubleScalarAtan(c2_B);
  sf_mex_printf("%s =\\n", "B");
  c2_d_u = c2_B;
  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_v_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_i_x = c2_Stheta4;
  c2_i_x.re *= 23.862000000000002;
  c2_i_x.im *= 23.862000000000002;
  c2_d_b = c2_Ctheta4;
  c2_w_y = 47.724000000000004 * c2_d_b;
  c2_i_x = c2_mrdivide(chartInstance, c2_i_x, c2_w_y);
  c2_alpha = c2_i_x;
  if (c2_alpha.re == 0.0) {
    c2_ib_x = c2_alpha.im;
    c2_jb_x = c2_ib_x;
    c2_x_y = muDoubleScalarAbs(c2_jb_x);
    if (c2_x_y == 1.0) {
      c2_eml_warning(chartInstance);
    }
  }

  c2_b_eml_scalar_atan(chartInstance, &c2_alpha);
  sf_mex_printf("%s =\\n", "alpha");
  c2_e_u = c2_alpha;
  c2_y_y = NULL;
  sf_mex_assign(&c2_y_y, sf_mex_create("y", &c2_e_u, 0, 1U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_y_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_theta3.re = c2_B - c2_alpha.re;
  c2_theta3.im = 0.0 - c2_alpha.im;
  sf_mex_printf("%s =\\n", "theta3");
  c2_f_u = c2_theta3;
  c2_ab_y = NULL;
  sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_f_u, 0, 1U, 0U, 0U, 0));
  sf_mex_call_debug("disp", 0U, 1U, 14, c2_ab_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -29);
  sf_debug_symbol_scope_pop();
  *c2_b_theta2 = c2_theta2;
  c2_b_theta3->re = c2_theta3.re;
  c2_b_theta3->im = c2_theta3.im;
  c2_b_theta4->re = c2_theta4.re;
  c2_b_theta4->im = c2_theta4.im;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Cinematica_MGI(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  creal_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(creal_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 1U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static creal_T c2_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_theta4, const char_T *c2_identifier)
{
  creal_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_theta4), &c2_thisId);
  sf_mex_destroy(&c2_theta4);
  return c2_y;
}

static creal_T c2_b_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  creal_T c2_y;
  creal_T c2_dc0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_dc0, 1, 0, 1U, 0, 0U, 0);
  c2_y = c2_dc0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_theta4;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  creal_T c2_y;
  SFc2_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c2_theta4 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_theta4), &c2_thisId);
  sf_mex_destroy(&c2_theta4);
  *(creal_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_theta2, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_theta2), &c2_thisId);
  sf_mex_destroy(&c2_theta2);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_theta2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c2_theta2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_theta2), &c2_thisId);
  sf_mex_destroy(&c2_theta2);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Cinematica_MGI_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[30];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 30));
  for (c2_i0 = 0; c2_i0 < 30; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[30])
{
  c2_info[0].context = "";
  c2_info[0].name = "mpower";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[0].fileTimeLo = 424321280U;
  c2_info[0].fileTimeHi = 30108070U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].name = "power";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[1].fileTimeLo = 444321280U;
  c2_info[1].fileTimeHi = 30108070U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[2].name = "eml_scalar_eg";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[2].fileTimeLo = 4259288576U;
  c2_info[2].fileTimeHi = 30108069U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[3].name = "eml_scalexp_alloc";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[3].fileTimeLo = 4259288576U;
  c2_info[3].fileTimeHi = 30108069U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[4].name = "eml_scalar_floor";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[4].fileTimeLo = 3559288576U;
  c2_info[4].fileTimeHi = 30108069U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[5].name = "eml_error";
  c2_info[5].dominantType = "char";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[5].fileTimeLo = 3299288576U;
  c2_info[5].fileTimeHi = 30108069U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "sqrt";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[6].fileTimeLo = 3819288576U;
  c2_info[6].fileTimeHi = 30108069U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[7].name = "eml_scalar_sqrt";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[7].fileTimeLo = 3679288576U;
  c2_info[7].fileTimeHi = 30108069U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "mrdivide";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[8].fileTimeLo = 714027776U;
  c2_info[8].fileTimeHi = 30130994U;
  c2_info[8].mFileTimeLo = 2169964032U;
  c2_info[8].mFileTimeHi = 30114358U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[9].name = "rdivide";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[9].fileTimeLo = 444321280U;
  c2_info[9].fileTimeHi = 30108070U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[10].name = "eml_div";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[10].fileTimeLo = 3279288576U;
  c2_info[10].fileTimeHi = 30108069U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "atan";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[11].fileTimeLo = 3339288576U;
  c2_info[11].fileTimeHi = 30108069U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[12].name = "eml_scalar_atan";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c2_info[12].fileTimeLo = 3479288576U;
  c2_info[12].fileTimeHi = 30108069U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "mtimes";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].fileTimeLo = 2169964032U;
  c2_info[13].fileTimeHi = 30114358U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  c2_info[14].name = "isnan";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[14].fileTimeLo = 3899288576U;
  c2_info[14].fileTimeHi = 30108069U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  c2_info[15].name = "eml_guarded_nan";
  c2_info[15].dominantType = "char";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[15].fileTimeLo = 4059288576U;
  c2_info[15].fileTimeHi = 30108069U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[16].name = "eml_is_float_class";
  c2_info[16].dominantType = "char";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[16].fileTimeLo = 4119288576U;
  c2_info[16].fileTimeHi = 30108069U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  c2_info[17].name = "isinf";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[17].fileTimeLo = 3899288576U;
  c2_info[17].fileTimeHi = 30108069U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  c2_info[18].name = "eml_guarded_inf";
  c2_info[18].dominantType = "char";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m";
  c2_info[18].fileTimeLo = 4059288576U;
  c2_info[18].fileTimeHi = 30108069U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  c2_info[19].name = "realmax";
  c2_info[19].dominantType = "char";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[19].fileTimeLo = 3959288576U;
  c2_info[19].fileTimeHi = 30108069U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt";
  c2_info[20].name = "eml_scalar_hypot";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m";
  c2_info[20].fileTimeLo = 3559288576U;
  c2_info[20].fileTimeHi = 30108069U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m";
  c2_info[21].name = "eml_dlapy2";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c2_info[21].fileTimeLo = 3279288576U;
  c2_info[21].fileTimeHi = 30108069U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[22].name = "abs";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[22].fileTimeLo = 3239288576U;
  c2_info[22].fileTimeHi = 30108069U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[23].name = "eml_scalar_abs";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[23].fileTimeLo = 3419288576U;
  c2_info[23].fileTimeHi = 30108069U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c2_info[24].name = "eml_warning";
  c2_info[24].dominantType = "char";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[24].fileTimeLo = 24321280U;
  c2_info[24].fileTimeHi = 30108070U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c2_info[25].name = "eml_scalar_atanh";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atanh.m";
  c2_info[25].fileTimeLo = 3499288576U;
  c2_info[25].fileTimeHi = 30108069U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atanh.m!scalar_complex_atanh";
  c2_info[26].name = "eml_scalar_log1p";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m";
  c2_info[26].fileTimeLo = 3579288576U;
  c2_info[26].fileTimeHi = 30108069U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m";
  c2_info[27].name = "eps";
  c2_info[27].dominantType = "char";
  c2_info[27].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[27].fileTimeLo = 3159288576U;
  c2_info[27].fileTimeHi = 30108069U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m";
  c2_info[28].name = "isfinite";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[28].fileTimeLo = 3879288576U;
  c2_info[28].fileTimeHi = 30108069U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m";
  c2_info[29].name = "eml_scalar_log";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m";
  c2_info[29].fileTimeLo = 3579288576U;
  c2_info[29].fileTimeHi = 30108069U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
}

static real_T c2_mpower(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
  c2_a)
{
  return c2_power(chartInstance, c2_a, 2.0);
}

static real_T c2_power(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
  c2_a, real_T c2_b)
{
  real_T c2_ak;
  real_T c2_bk;
  real_T c2_x;
  real_T c2_b_x;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_a;
  c2_bk = c2_b;
  if (c2_ak < 0.0) {
    c2_x = c2_bk;
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarFloor(c2_b_x);
    if (c2_b_x != c2_bk) {
      c2_eml_error(chartInstance);
    }
  }

  return muDoubleScalarPower(c2_ak, c2_bk);
}

static void c2_eml_scalar_eg(SFc2_Cinematica_MGIInstanceStruct *chartInstance)
{
}

static void c2_eml_error(SFc2_Cinematica_MGIInstanceStruct *chartInstance)
{
  int32_T c2_i1;
  static char_T c2_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  for (c2_i1 = 0; c2_i1 < 31; c2_i1++) {
    c2_u[c2_i1] = c2_varargin_1[c2_i1];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static real_T c2_sqrt(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
                      c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_b_eml_error(SFc2_Cinematica_MGIInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  static char_T c2_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i2 = 0; c2_i2 < 30; c2_i2++) {
    c2_u[c2_i2] = c2_varargin_1[c2_i2];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static real_T c2_eml_scalar_hypot(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, real_T c2_x, real_T c2_y)
{
  real_T c2_z;
  real_T c2_x1;
  real_T c2_x2;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_x;
  boolean_T c2_b_b;
  c2_eml_scalar_eg(chartInstance);
  c2_x1 = c2_x;
  c2_x2 = c2_y;
  c2_a = muDoubleScalarAbs(c2_x1);
  c2_b = muDoubleScalarAbs(c2_x2);
  if (c2_a < c2_b) {
    c2_a /= c2_b;
    c2_z = muDoubleScalarSqrt(c2_a * c2_a + 1.0) * c2_b;
  } else if (c2_a > c2_b) {
    c2_b /= c2_a;
    c2_z = muDoubleScalarSqrt(c2_b * c2_b + 1.0) * c2_a;
  } else {
    c2_b_x = c2_b;
    c2_b_b = muDoubleScalarIsNaN(c2_b_x);
    if (c2_b_b) {
      c2_z = c2_b;
    } else {
      c2_z = c2_a * 1.4142135623730951;
    }
  }

  return c2_z;
}

static creal_T c2_mrdivide(SFc2_Cinematica_MGIInstanceStruct *chartInstance,
  creal_T c2_A, real_T c2_B)
{
  creal_T c2_y;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_yk;
  real_T c2_ar;
  real_T c2_ai;
  real_T c2_br;
  real_T c2_bi;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_brm;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_bim;
  real_T c2_s;
  real_T c2_a;
  real_T c2_b;
  real_T c2_e_y;
  real_T c2_d;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_f_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_g_y;
  real_T c2_brs;
  real_T c2_bis;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_h_y;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_i_y;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_j_y;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_k_y;
  real_T c2_h_a;
  real_T c2_h_b;
  real_T c2_l_y;
  real_T c2_i_a;
  real_T c2_i_b;
  real_T c2_m_y;
  real_T c2_j_a;
  real_T c2_j_b;
  real_T c2_n_y;
  c2_b_y = c2_B;
  c2_c_y = c2_b_y;
  c2_d_y = c2_c_y;
  c2_yk = c2_d_y;
  c2_ar = c2_A.re;
  c2_ai = c2_A.im;
  c2_br = c2_yk;
  c2_bi = 0.0;
  c2_x = c2_br;
  c2_b_x = c2_x;
  c2_brm = muDoubleScalarAbs(c2_b_x);
  c2_c_x = c2_bi;
  c2_d_x = c2_c_x;
  c2_bim = muDoubleScalarAbs(c2_d_x);
  if (c2_bi == 0.0) {
    if (c2_ai == 0.0) {
      c2_y.re = c2_ar / c2_br;
      c2_y.im = 0.0;
    } else if (c2_ar == 0.0) {
      c2_y.re = 0.0;
      c2_y.im = c2_ai / c2_br;
    } else {
      c2_y.re = c2_ar / c2_br;
      c2_y.im = c2_ai / c2_br;
    }
  } else if (c2_br == 0.0) {
    if (c2_ar == 0.0) {
      c2_y.re = c2_ai / c2_bi;
      c2_y.im = 0.0;
    } else if (c2_ai == 0.0) {
      c2_y.re = 0.0;
      c2_y.im = -c2_ar / c2_bi;
    } else {
      c2_y.re = c2_ai / c2_bi;
      c2_y.im = -c2_ar / c2_bi;
    }
  } else if (c2_brm > c2_bim) {
    c2_s = c2_bi / c2_br;
    c2_a = c2_s;
    c2_b = c2_bi;
    c2_e_y = c2_a * c2_b;
    c2_d = c2_br + c2_e_y;
    c2_b_a = c2_s;
    c2_b_b = c2_ai;
    c2_f_y = c2_b_a * c2_b_b;
    c2_c_a = c2_s;
    c2_c_b = c2_ar;
    c2_g_y = c2_c_a * c2_c_b;
    c2_y.re = (c2_ar + c2_f_y) / c2_d;
    c2_y.im = (c2_ai - c2_g_y) / c2_d;
  } else if (c2_brm == c2_bim) {
    c2_brs = 0.5;
    if (c2_br < 0.0) {
      c2_brs = -0.5;
    }

    c2_bis = 0.5;
    if (c2_bi < 0.0) {
      c2_bis = -0.5;
    }

    c2_d_a = c2_ar;
    c2_d_b = c2_brs;
    c2_h_y = c2_d_a * c2_d_b;
    c2_e_a = c2_ai;
    c2_e_b = c2_bis;
    c2_i_y = c2_e_a * c2_e_b;
    c2_f_a = c2_ai;
    c2_f_b = c2_brs;
    c2_j_y = c2_f_a * c2_f_b;
    c2_g_a = c2_ar;
    c2_g_b = c2_bis;
    c2_k_y = c2_g_a * c2_g_b;
    c2_y.re = (c2_h_y + c2_i_y) / c2_brm;
    c2_y.im = (c2_j_y - c2_k_y) / c2_brm;
  } else {
    c2_s = c2_br / c2_bi;
    c2_h_a = c2_s;
    c2_h_b = c2_br;
    c2_l_y = c2_h_a * c2_h_b;
    c2_d = c2_bi + c2_l_y;
    c2_i_a = c2_s;
    c2_i_b = c2_ar;
    c2_m_y = c2_i_a * c2_i_b;
    c2_j_a = c2_s;
    c2_j_b = c2_ai;
    c2_n_y = c2_j_a * c2_j_b;
    c2_y.re = (c2_m_y + c2_ai) / c2_d;
    c2_y.im = (c2_n_y - c2_ar) / c2_d;
  }

  return c2_y;
}

static void c2_eml_warning(SFc2_Cinematica_MGIInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  static char_T c2_varargin_1[29] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 't', 'a', 'n', '_', 's', 'i', 'n', 'g', 'u',
    'l', 'a', 'r', 'i', 't', 'y' };

  char_T c2_u[29];
  const mxArray *c2_y = NULL;
  for (c2_i3 = 0; c2_i3 < 29; c2_i3++) {
    c2_u[c2_i3] = c2_varargin_1[c2_i3];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 29));
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c2_y));
}

static creal_T c2_eml_scalar_atan(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, creal_T c2_x)
{
  creal_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_eml_scalar_atan(chartInstance, &c2_b_x);
  return c2_b_x;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i4;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i4, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i4;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Cinematica_MGI, const char_T *
  c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Cinematica_MGI), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Cinematica_MGI);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_Cinematica_MGIInstanceStruct *chartInstance, real_T
                      *c2_x)
{
  if (*c2_x < 0.0) {
    c2_b_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void c2_b_eml_scalar_atan(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance, creal_T *c2_x)
{
  creal_T c2_t;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_xr;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_xi;
  creal_T c2_yk;
  real_T c2_br;
  real_T c2_bi;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_brm;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_bim;
  real_T c2_s;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_d;
  real_T c2_b_a;
  real_T c2_b_y;
  real_T c2_c_a;
  real_T c2_c_y;
  real_T c2_brs;
  real_T c2_bis;
  real_T c2_b_b;
  real_T c2_d_y;
  real_T c2_c_b;
  real_T c2_e_y;
  real_T c2_d_b;
  real_T c2_f_y;
  real_T c2_e_b;
  real_T c2_g_y;
  real_T c2_d_a;
  real_T c2_f_b;
  real_T c2_h_y;
  real_T c2_e_a;
  real_T c2_i_y;
  real_T c2_f_a;
  real_T c2_j_y;
  real_T c2_b_t;
  real_T c2_z;
  real_T c2_b_z;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_absz;
  real_T c2_l_x;
  real_T c2_m_x;
  boolean_T c2_g_b;
  boolean_T c2_b2;
  real_T c2_n_x;
  boolean_T c2_h_b;
  boolean_T c2_b3;
  boolean_T c2_i_b;
  real_T c2_o_x;
  real_T c2_u;
  real_T c2_p_x;
  real_T c2_q_x;
  creal_T c2_c_t;
  creal_T c2_d_t;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c2_t.re = -c2_x->im;
  c2_t.im = c2_x->re;
  c2_b_x = c2_t.re;
  c2_c_x = c2_b_x;
  c2_xr = muDoubleScalarAbs(c2_c_x);
  c2_d_x = c2_t.im;
  c2_e_x = c2_d_x;
  c2_xi = muDoubleScalarAbs(c2_e_x);
  guard2 = FALSE;
  if (c2_xr > 3.3519519824856489E+153) {
    guard2 = TRUE;
  } else if (c2_xi > 3.3519519824856489E+153) {
    guard2 = TRUE;
  } else {
    guard3 = FALSE;
    if (c2_xr == 1.0) {
      if (c2_xi == 0.0) {
        c2_xr = rtInf;
        c2_xi = 0.0;
      } else {
        guard3 = TRUE;
      }
    } else {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      if (c2_xr == 1.0) {
        c2_b_t = c2_xi + 2.9833362924800834E-154;
        c2_xr = muDoubleScalarLog(muDoubleScalarSqrt(muDoubleScalarSqrt(4.0 +
          c2_xi * c2_xi)) / muDoubleScalarSqrt(c2_b_t));
        c2_xi = (1.5707963267948966 + muDoubleScalarAtan(c2_b_t / 2.0)) / 2.0;
      } else {
        c2_b_t = c2_xi + 2.9833362924800834E-154;
        c2_xi = muDoubleScalarAtan2(2.0 * c2_xi, (1.0 - c2_xr) * (1.0 + c2_xr) -
          c2_b_t * c2_b_t) / 2.0;
        c2_z = 4.0 * (c2_xr / ((1.0 - c2_xr) * (1.0 - c2_xr) + c2_b_t * c2_b_t));
        c2_b_z = c2_z;
        c2_j_x = c2_b_z;
        c2_k_x = c2_j_x;
        c2_absz = muDoubleScalarAbs(c2_k_x);
        guard4 = FALSE;
        if (c2_absz > 4.503599627370496E+15) {
          guard4 = TRUE;
        } else {
          c2_l_x = c2_b_z;
          c2_m_x = c2_l_x;
          c2_g_b = muDoubleScalarIsInf(c2_m_x);
          c2_b2 = !c2_g_b;
          c2_n_x = c2_l_x;
          c2_h_b = muDoubleScalarIsNaN(c2_n_x);
          c2_b3 = !c2_h_b;
          c2_i_b = (c2_b2 && c2_b3);
          if (!c2_i_b) {
            guard4 = TRUE;
          } else if (c2_absz < 2.2204460492503131E-16) {
          } else {
            c2_u = 1.0 + c2_b_z;
            c2_p_x = c2_u;
            c2_q_x = c2_p_x;
            c2_q_x = muDoubleScalarLog(c2_q_x);
            c2_b_z = c2_q_x * (c2_b_z / (c2_u - 1.0));
          }
        }

        if (guard4 == TRUE) {
          c2_o_x = 1.0 + c2_b_z;
          c2_b_z = c2_o_x;
          c2_b_z = muDoubleScalarLog(c2_b_z);
        }

        c2_xr = c2_b_z / 4.0;
      }
    }
  }

  if (guard2 == TRUE) {
    c2_yk.re = c2_xr;
    c2_yk.im = c2_xi;
    c2_br = c2_yk.re;
    c2_bi = c2_yk.im;
    c2_f_x = c2_br;
    c2_g_x = c2_f_x;
    c2_brm = muDoubleScalarAbs(c2_g_x);
    c2_h_x = c2_bi;
    c2_i_x = c2_h_x;
    c2_bim = muDoubleScalarAbs(c2_i_x);
    if (c2_bi == 0.0) {
      c2_yk.re = 1.0 / c2_br;
      c2_yk.im = 0.0;
    } else if (c2_br == 0.0) {
      c2_yk.re = 0.0;
      c2_yk.im = -1.0 / c2_bi;
    } else if (c2_brm > c2_bim) {
      c2_s = c2_bi / c2_br;
      c2_a = c2_s;
      c2_b = c2_bi;
      c2_y = c2_a * c2_b;
      c2_d = c2_br + c2_y;
      c2_b_a = c2_s;
      c2_b_y = c2_b_a * 0.0;
      c2_c_a = c2_s;
      c2_c_y = c2_c_a;
      c2_yk.re = (1.0 + c2_b_y) / c2_d;
      c2_yk.im = (0.0 - c2_c_y) / c2_d;
    } else if (c2_brm == c2_bim) {
      c2_brs = 0.5;
      if (c2_br < 0.0) {
        c2_brs = -0.5;
      }

      c2_bis = 0.5;
      if (c2_bi < 0.0) {
        c2_bis = -0.5;
      }

      c2_b_b = c2_brs;
      c2_d_y = c2_b_b;
      c2_c_b = c2_bis;
      c2_e_y = 0.0 * c2_c_b;
      c2_d_b = c2_brs;
      c2_f_y = 0.0 * c2_d_b;
      c2_e_b = c2_bis;
      c2_g_y = c2_e_b;
      c2_yk.re = (c2_d_y + c2_e_y) / c2_brm;
      c2_yk.im = (c2_f_y - c2_g_y) / c2_brm;
    } else {
      c2_s = c2_br / c2_bi;
      c2_d_a = c2_s;
      c2_f_b = c2_br;
      c2_h_y = c2_d_a * c2_f_b;
      c2_d = c2_bi + c2_h_y;
      c2_e_a = c2_s;
      c2_i_y = c2_e_a;
      c2_f_a = c2_s;
      c2_j_y = c2_f_a * 0.0;
      c2_yk.re = c2_i_y / c2_d;
      c2_yk.im = (c2_j_y - 1.0) / c2_d;
    }

    c2_xr = c2_yk.re;
    c2_xi = 1.5707963267948966;
  }

  if (c2_t.re < 0.0) {
    c2_xr = -c2_xr;
  }

  guard1 = FALSE;
  if (c2_t.im < 0.0) {
    guard1 = TRUE;
  } else {
    if (c2_t.im == 0.0) {
      if (c2_t.re < -1.0) {
        guard1 = TRUE;
      }
    }
  }

  if (guard1 == TRUE) {
    c2_xi = -c2_xi;
  }

  c2_t.re = c2_xr;
  c2_t.im = c2_xi;
  c2_c_t = c2_t;
  c2_d_t = c2_t;
  c2_x->re = c2_c_t.im;
  c2_x->im = -c2_d_t.re;
}

static void init_dsm_address_info(SFc2_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_Cinematica_MGI_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3349648338U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2990596867U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1837793814U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(699425603U);
}

mxArray *sf_c2_Cinematica_MGI_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1073710296U);
    pr[1] = (double)(34367281U);
    pr[2] = (double)(2007934015U);
    pr[3] = (double)(3508263447U);
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

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(1));

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

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_Cinematica_MGI(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[13],T\"theta2\",},{M[1],M[14],T\"theta3\",},{M[1],M[15],T\"theta4\",},{M[8],M[0],T\"is_active_c2_Cinematica_MGI\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Cinematica_MGI_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Cinematica_MGIInstanceStruct *chartInstance;
    chartInstance = (SFc2_Cinematica_MGIInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Cinematica_MGIMachineNumber_,
           2,
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
          init_script_number_translation(_Cinematica_MGIMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Cinematica_MGIMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Cinematica_MGIMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"px");
          _SFD_SET_DATA_PROPS(1,1,1,0,"py");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pz");
          _SFD_SET_DATA_PROPS(3,2,0,1,"theta2");
          _SFD_SET_DATA_PROPS(4,2,0,1,"theta3");
          _SFD_SET_DATA_PROPS(5,2,0,1,"theta4");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,769);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_px;
          real_T *c2_py;
          real_T *c2_pz;
          real_T *c2_theta2;
          creal_T *c2_theta3;
          creal_T *c2_theta4;
          c2_theta4 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_theta3 = (creal_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_theta2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_pz = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_py = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_px = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_px);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_py);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_pz);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_theta2);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_theta3);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_theta4);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Cinematica_MGIMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_Cinematica_MGI(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Cinematica_MGIInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
  initialize_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_Cinematica_MGI(void *chartInstanceVar)
{
  enable_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Cinematica_MGI(void *chartInstanceVar)
{
  disable_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_Cinematica_MGI(void *chartInstanceVar)
{
  sf_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Cinematica_MGI(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Cinematica_MGI
    ((SFc2_Cinematica_MGIInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Cinematica_MGI();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Cinematica_MGI(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Cinematica_MGI();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Cinematica_MGI(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Cinematica_MGI(S);
}

static void sf_opaque_set_sim_state_c2_Cinematica_MGI(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_Cinematica_MGI(S, st);
}

static void sf_opaque_terminate_c2_Cinematica_MGI(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Cinematica_MGIInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Cinematica_MGI(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Cinematica_MGI((SFc2_Cinematica_MGIInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Cinematica_MGI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Cinematica_MGI","Cinematica_MGI",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Cinematica_MGI","Cinematica_MGI",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Cinematica_MGI",
      "Cinematica_MGI",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Cinematica_MGI","Cinematica_MGI",2,
        3);
      sf_mark_chart_reusable_outputs(S,"Cinematica_MGI","Cinematica_MGI",2,3);
    }

    sf_set_rtw_dwork_info(S,"Cinematica_MGI","Cinematica_MGI",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1765951253U));
  ssSetChecksum1(S,(4286807761U));
  ssSetChecksum2(S,(3963940753U));
  ssSetChecksum3(S,(855605014U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Cinematica_MGI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Cinematica_MGI", "Cinematica_MGI",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Cinematica_MGI(SimStruct *S)
{
  SFc2_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Cinematica_MGIInstanceStruct *)malloc(sizeof
    (SFc2_Cinematica_MGIInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Cinematica_MGIInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Cinematica_MGI;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Cinematica_MGI;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Cinematica_MGI;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Cinematica_MGI;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Cinematica_MGI;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Cinematica_MGI;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Cinematica_MGI;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Cinematica_MGI;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Cinematica_MGI;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Cinematica_MGI;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Cinematica_MGI;
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

void c2_Cinematica_MGI_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Cinematica_MGI(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Cinematica_MGI(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Cinematica_MGI(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Cinematica_MGI_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
