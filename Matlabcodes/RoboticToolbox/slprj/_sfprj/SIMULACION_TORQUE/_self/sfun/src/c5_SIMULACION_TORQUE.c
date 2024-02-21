/* Include files */

#include "blascompat32.h"
#include "SIMULACION_TORQUE_sfun.h"
#include "c5_SIMULACION_TORQUE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SIMULACION_TORQUE_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[15] = { "y", "z", "r1", "r2", "r3",
  "B", "f1", "f2", "nargin", "nargout", "yz", "q1", "q2", "T1", "T2" };

/* Function Declarations */
static void initialize_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void initialize_params_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void enable_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void disable_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void set_sim_state_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void sf_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance);
static void initSimStructsc5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_T2, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[18]);
static real_T c5_mpower(SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance,
  real_T c5_a);
static void c5_eml_error(SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_SIMULACION_TORQUE, const
  char_T *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_SIMULACION_TORQUE = 0U;
}

static void initialize_params_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void enable_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  uint8_T c5_c_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T *c5_T1;
  real_T *c5_T2;
  c5_T2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(3));
  c5_hoistedGlobal = *c5_T1;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_T2;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = chartInstance->c5_is_active_c5_SIMULACION_TORQUE;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 2, c5_d_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_T1;
  real_T *c5_T2;
  c5_T2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_T1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_T1 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "T1");
  *c5_T2 = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "T2");
  chartInstance->c5_is_active_c5_SIMULACION_TORQUE = c5_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
     "is_active_c5_SIMULACION_TORQUE");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_SIMULACION_TORQUE(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

static void sf_c5_SIMULACION_TORQUE(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
  int32_T c5_i0;
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  int32_T c5_i1;
  real_T c5_yz[2];
  real_T c5_q1;
  real_T c5_q2;
  uint32_T c5_debug_family_var_map[15];
  real_T c5_y;
  real_T c5_z;
  real_T c5_r1;
  real_T c5_r2;
  real_T c5_r3;
  real_T c5_B;
  real_T c5_f1;
  real_T c5_f2;
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 2.0;
  real_T c5_T1;
  real_T c5_T2;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_A;
  real_T c5_b_B;
  real_T c5_g_x;
  real_T c5_b_y;
  real_T c5_h_x;
  real_T c5_c_y;
  real_T c5_i_x;
  real_T c5_d_y;
  real_T c5_e_y;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_b;
  real_T c5_f_y;
  real_T c5_a;
  real_T c5_g_y;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_b_a;
  real_T c5_b_b;
  real_T c5_h_y;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_c_b;
  real_T *c5_b_T1;
  real_T *c5_b_T2;
  real_T *c5_b_q1;
  real_T *c5_b_q2;
  real_T (*c5_b_yz)[2];
  c5_b_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_T2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_T1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_yz = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i0 = 0; c5_i0 < 2; c5_i0++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_yz)[c5_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_b_T1, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_T2, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_q1, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_q2, 4U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_q1;
  c5_b_hoistedGlobal = *c5_b_q2;
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_yz[c5_i1] = (*c5_b_yz)[c5_i1];
  }

  c5_q1 = c5_hoistedGlobal;
  c5_q2 = c5_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_y, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_z, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_r1, 2U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_r2, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_r3, 4U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_B, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_f1, 6U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_f2, 7U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c5_yz, 10U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_q1, 11U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_q2, 12U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_T1, 13U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_T2, 14U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 2);
  c5_x = c5_yz[0];
  c5_b_x = c5_x;
  c5_y = muDoubleScalarAbs(c5_b_x);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_c_x = c5_yz[1];
  c5_d_x = c5_c_x;
  c5_z = muDoubleScalarAbs(c5_d_x);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_r1 = 2.3862;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_e_x = c5_mpower(chartInstance, c5_y) + c5_mpower(chartInstance, c5_z);
  c5_r2 = c5_e_x;
  if (c5_r2 < 0.0) {
    c5_eml_error(chartInstance);
  }

  c5_f_x = c5_r2;
  c5_r2 = c5_f_x;
  c5_r2 = muDoubleScalarSqrt(c5_r2);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_r3 = 1.18;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_A = c5_y;
  c5_b_B = c5_z;
  c5_g_x = c5_A;
  c5_b_y = c5_b_B;
  c5_h_x = c5_g_x;
  c5_c_y = c5_b_y;
  c5_i_x = c5_h_x;
  c5_d_y = c5_c_y;
  c5_e_y = c5_i_x / c5_d_y;
  c5_j_x = c5_e_y;
  c5_B = c5_j_x;
  c5_k_x = c5_B;
  c5_B = c5_k_x;
  c5_B = muDoubleScalarAtan(c5_B);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_f1 = 3.9;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_f2 = 3.2;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_l_x = c5_q1;
  c5_m_x = c5_l_x;
  c5_m_x = muDoubleScalarSin(c5_m_x);
  c5_b = c5_m_x;
  c5_f_y = 9.30618 * c5_b;
  c5_a = c5_r2;
  c5_g_y = c5_a * 3.2;
  c5_n_x = c5_B;
  c5_o_x = c5_n_x;
  c5_o_x = muDoubleScalarSin(c5_o_x);
  c5_b_a = c5_g_y;
  c5_b_b = c5_o_x;
  c5_h_y = c5_b_a * c5_b_b;
  c5_T1 = c5_f_y + c5_h_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_p_x = c5_q2;
  c5_q_x = c5_p_x;
  c5_q_x = muDoubleScalarSin(c5_q_x);
  c5_c_b = c5_q_x;
  c5_T2 = 3.776 * c5_c_b;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -15);
  sf_debug_symbol_scope_pop();
  *c5_b_T1 = c5_T1;
  *c5_b_T2 = c5_T2;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_SIMULACION_TORQUEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_SIMULACION_TORQUE
  (SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_T2, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_T2), &c5_thisId);
  sf_mex_destroy(&c5_T2);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_T2;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c5_T2 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_T2), &c5_thisId);
  sf_mex_destroy(&c5_T2);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i2;
  real_T c5_b_inData[2];
  int32_T c5_i3;
  real_T c5_u[2];
  const mxArray *c5_y = NULL;
  SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    c5_b_inData[c5_i2] = (*(real_T (*)[2])c5_inData)[c5_i2];
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_u[c5_i3] = c5_b_inData[c5_i3];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 2));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_SIMULACION_TORQUE_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[18];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i4;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18));
  for (c5_i4 = 0; c5_i4 < 18; c5_i4++) {
    c5_r0 = &c5_info[c5_i4];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i4);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i4);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i4);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i4);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i4);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i4);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i4);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i4);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[18])
{
  c5_info[0].context = "";
  c5_info[0].name = "abs";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[0].fileTimeLo = 3239288576U;
  c5_info[0].fileTimeHi = 30108069U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[1].name = "eml_scalar_abs";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[1].fileTimeLo = 3419288576U;
  c5_info[1].fileTimeHi = 30108069U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context = "";
  c5_info[2].name = "mpower";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[2].fileTimeLo = 424321280U;
  c5_info[2].fileTimeHi = 30108070U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[3].name = "power";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[3].fileTimeLo = 444321280U;
  c5_info[3].fileTimeHi = 30108070U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[4].name = "eml_scalar_eg";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[4].fileTimeLo = 4259288576U;
  c5_info[4].fileTimeHi = 30108069U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[5].name = "eml_scalexp_alloc";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[5].fileTimeLo = 4259288576U;
  c5_info[5].fileTimeHi = 30108069U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[6].name = "eml_scalar_floor";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[6].fileTimeLo = 3559288576U;
  c5_info[6].fileTimeHi = 30108069U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[7].name = "eml_error";
  c5_info[7].dominantType = "char";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[7].fileTimeLo = 3299288576U;
  c5_info[7].fileTimeHi = 30108069U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context = "";
  c5_info[8].name = "sqrt";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[8].fileTimeLo = 3819288576U;
  c5_info[8].fileTimeHi = 30108069U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[9].name = "eml_scalar_sqrt";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c5_info[9].fileTimeLo = 3679288576U;
  c5_info[9].fileTimeHi = 30108069U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context = "";
  c5_info[10].name = "mrdivide";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[10].fileTimeLo = 714027776U;
  c5_info[10].fileTimeHi = 30130994U;
  c5_info[10].mFileTimeLo = 2169964032U;
  c5_info[10].mFileTimeHi = 30114358U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[11].name = "rdivide";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[11].fileTimeLo = 444321280U;
  c5_info[11].fileTimeHi = 30108070U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[12].name = "eml_div";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[12].fileTimeLo = 3279288576U;
  c5_info[12].fileTimeHi = 30108069U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context = "";
  c5_info[13].name = "atan";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c5_info[13].fileTimeLo = 3339288576U;
  c5_info[13].fileTimeHi = 30108069U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c5_info[14].name = "eml_scalar_atan";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c5_info[14].fileTimeLo = 3479288576U;
  c5_info[14].fileTimeHi = 30108069U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context = "";
  c5_info[15].name = "mtimes";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[15].fileTimeLo = 2169964032U;
  c5_info[15].fileTimeHi = 30114358U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context = "";
  c5_info[16].name = "sin";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[16].fileTimeLo = 3799288576U;
  c5_info[16].fileTimeHi = 30108069U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[17].name = "eml_scalar_sin";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c5_info[17].fileTimeLo = 3659288576U;
  c5_info[17].fileTimeHi = 30108069U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
}

static real_T c5_mpower(SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance,
  real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_ak;
  c5_b_a = c5_a;
  c5_ak = c5_b_a;
  return muDoubleScalarPower(c5_ak, 2.0);
}

static void c5_eml_error(SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance)
{
  int32_T c5_i5;
  static char_T c5_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c5_u[30];
  const mxArray *c5_y = NULL;
  for (c5_i5 = 0; c5_i5 < 30; c5_i5++) {
    c5_u[c5_i5] = c5_varargin_1[c5_i5];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c5_y));
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_mxArrayOutData, c5_y);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i6;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i6, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i6;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACION_TORQUEInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_SIMULACION_TORQUE, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_SIMULACION_TORQUE), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_SIMULACION_TORQUE);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_SIMULACION_TORQUEInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_SIMULACION_TORQUE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1484141150U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1201151443U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2088168839U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(968251739U);
}

mxArray *sf_c5_SIMULACION_TORQUE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1530488404U);
    pr[1] = (double)(2492317923U);
    pr[2] = (double)(2228741659U);
    pr[3] = (double)(708944312U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c5_SIMULACION_TORQUE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"T1\",},{M[1],M[24],T\"T2\",},{M[8],M[0],T\"is_active_c5_SIMULACION_TORQUE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_SIMULACION_TORQUE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance;
    chartInstance = (SFc5_SIMULACION_TORQUEInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_SIMULACION_TORQUEMachineNumber_,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"yz");
          _SFD_SET_DATA_PROPS(1,2,0,1,"T1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"T2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q1");
          _SFD_SET_DATA_PROPS(4,1,1,0,"q2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,198);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c5_T1;
          real_T *c5_T2;
          real_T *c5_q1;
          real_T *c5_q2;
          real_T (*c5_yz)[2];
          c5_q2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_q1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_T2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_T1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_yz = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_yz);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_T1);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_T2);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_q1);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_q2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_SIMULACION_TORQUEMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_SIMULACION_TORQUE(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
  initialize_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_SIMULACION_TORQUE(void *chartInstanceVar)
{
  enable_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_SIMULACION_TORQUE(void *chartInstanceVar)
{
  disable_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_SIMULACION_TORQUE(void *chartInstanceVar)
{
  sf_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_SIMULACION_TORQUE(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_SIMULACION_TORQUE
    ((SFc5_SIMULACION_TORQUEInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_SIMULACION_TORQUE();/* state var info */
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

extern void sf_internal_set_sim_state_c5_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_SIMULACION_TORQUE();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_SIMULACION_TORQUE(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_SIMULACION_TORQUE(S);
}

static void sf_opaque_set_sim_state_c5_SIMULACION_TORQUE(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_SIMULACION_TORQUE(S, st);
}

static void sf_opaque_terminate_c5_SIMULACION_TORQUE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_SIMULACION_TORQUEInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_SIMULACION_TORQUE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_SIMULACION_TORQUE((SFc5_SIMULACION_TORQUEInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",
                5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"SIMULACION_TORQUE",
      "SIMULACION_TORQUE",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"SIMULACION_TORQUE",
        "SIMULACION_TORQUE",5,3);
      sf_mark_chart_reusable_outputs(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",5,
        2);
    }

    sf_set_rtw_dwork_info(S,"SIMULACION_TORQUE","SIMULACION_TORQUE",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1723749631U));
  ssSetChecksum1(S,(1858402852U));
  ssSetChecksum2(S,(2337477755U));
  ssSetChecksum3(S,(2525573938U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_SIMULACION_TORQUE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "SIMULACION_TORQUE", "SIMULACION_TORQUE",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_SIMULACION_TORQUE(SimStruct *S)
{
  SFc5_SIMULACION_TORQUEInstanceStruct *chartInstance;
  chartInstance = (SFc5_SIMULACION_TORQUEInstanceStruct *)malloc(sizeof
    (SFc5_SIMULACION_TORQUEInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_SIMULACION_TORQUEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_SIMULACION_TORQUE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_SIMULACION_TORQUE;
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

void c5_SIMULACION_TORQUE_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_SIMULACION_TORQUE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_SIMULACION_TORQUE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_SIMULACION_TORQUE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
