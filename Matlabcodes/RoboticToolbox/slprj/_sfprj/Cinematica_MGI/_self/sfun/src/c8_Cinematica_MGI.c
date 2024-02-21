/* Include files */

#include "blascompat32.h"
#include "Cinematica_MGI_sfun.h"
#include "c8_Cinematica_MGI.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Cinematica_MGI_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[4] = { "nargin", "nargout", "rad",
  "grad" };

/* Function Declarations */
static void initialize_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance);
static void initialize_params_c8_Cinematica_MGI
  (SFc8_Cinematica_MGIInstanceStruct *chartInstance);
static void enable_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance);
static void disable_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_Cinematica_MGI
  (SFc8_Cinematica_MGIInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_Cinematica_MGI
  (SFc8_Cinematica_MGIInstanceStruct *chartInstance);
static void set_sim_state_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void finalize_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance);
static void sf_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance);
static void initSimStructsc8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_grad, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_c_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_d_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_Cinematica_MGI, const char_T *
  c8_identifier);
static uint8_T c8_e_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_Cinematica_MGI = 0U;
}

static void initialize_params_c8_Cinematica_MGI
  (SFc8_Cinematica_MGIInstanceStruct *chartInstance)
{
}

static void enable_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_Cinematica_MGI
  (SFc8_Cinematica_MGIInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_Cinematica_MGI
  (SFc8_Cinematica_MGIInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T *c8_grad;
  c8_grad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2));
  c8_hoistedGlobal = *c8_grad;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = chartInstance->c8_is_active_c8_Cinematica_MGI;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y);
  return c8_st;
}

static void set_sim_state_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T *c8_grad;
  c8_grad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_grad = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    0)), "grad");
  chartInstance->c8_is_active_c8_Cinematica_MGI = c8_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_Cinematica_MGI");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_Cinematica_MGI(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

static void sf_c8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance)
{
  creal_T c8_rad;
  uint32_T c8_debug_family_var_map[4];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real_T c8_grad;
  creal_T c8_x;
  real_T c8_x1;
  real_T c8_x2;
  real_T c8_a;
  real_T c8_b;
  real_T c8_b_x;
  boolean_T c8_b_b;
  real_T *c8_b_grad;
  creal_T *c8_b_rad;
  c8_b_grad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_rad = (creal_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c8_b_grad, 1U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  c8_rad.re = c8_b_rad->re;
  c8_rad.im = c8_b_rad->im;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_rad, 2U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_grad, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 3);
  c8_x = c8_rad;
  c8_x1 = c8_x.re;
  c8_x2 = c8_x.im;
  c8_a = muDoubleScalarAbs(c8_x1);
  c8_b = muDoubleScalarAbs(c8_x2);
  if (c8_a < c8_b) {
    c8_a /= c8_b;
    c8_grad = muDoubleScalarSqrt(c8_a * c8_a + 1.0) * c8_b;
  } else if (c8_a > c8_b) {
    c8_b /= c8_a;
    c8_grad = muDoubleScalarSqrt(c8_b * c8_b + 1.0) * c8_a;
  } else {
    c8_b_x = c8_b;
    c8_b_b = muDoubleScalarIsNaN(c8_b_x);
    if (c8_b_b) {
      c8_grad = c8_b;
    } else {
      c8_grad = c8_a * 1.4142135623730951;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -3);
  sf_debug_symbol_scope_pop();
  *c8_b_grad = c8_grad;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  sf_debug_check_for_state_inconsistency(_Cinematica_MGIMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc8_Cinematica_MGI(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc8_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_grad, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_grad), &c8_thisId);
  sf_mex_destroy(&c8_grad);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_grad;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc8_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c8_grad = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_grad), &c8_thisId);
  sf_mex_destroy(&c8_grad);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  creal_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc8_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(creal_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 1U, 0U, 0U, 0));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

const mxArray *sf_c8_Cinematica_MGI_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[4];
  c8_ResolvedFunctionInfo (*c8_b_info)[4];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i0;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_b_info = (c8_ResolvedFunctionInfo (*)[4])c8_info;
  (*c8_b_info)[0].context = "";
  (*c8_b_info)[0].name = "abs";
  (*c8_b_info)[0].dominantType = "double";
  (*c8_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c8_b_info)[0].fileTimeLo = 3239288576U;
  (*c8_b_info)[0].fileTimeHi = 30108069U;
  (*c8_b_info)[0].mFileTimeLo = 0U;
  (*c8_b_info)[0].mFileTimeHi = 0U;
  (*c8_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c8_b_info)[1].name = "eml_scalar_abs";
  (*c8_b_info)[1].dominantType = "double";
  (*c8_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c8_b_info)[1].fileTimeLo = 3419288576U;
  (*c8_b_info)[1].fileTimeHi = 30108069U;
  (*c8_b_info)[1].mFileTimeLo = 0U;
  (*c8_b_info)[1].mFileTimeHi = 0U;
  (*c8_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c8_b_info)[2].name = "eml_dlapy2";
  (*c8_b_info)[2].dominantType = "double";
  (*c8_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  (*c8_b_info)[2].fileTimeLo = 3279288576U;
  (*c8_b_info)[2].fileTimeHi = 30108069U;
  (*c8_b_info)[2].mFileTimeLo = 0U;
  (*c8_b_info)[2].mFileTimeHi = 0U;
  (*c8_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  (*c8_b_info)[3].name = "isnan";
  (*c8_b_info)[3].dominantType = "double";
  (*c8_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  (*c8_b_info)[3].fileTimeLo = 3899288576U;
  (*c8_b_info)[3].fileTimeHi = 30108069U;
  (*c8_b_info)[3].mFileTimeLo = 0U;
  (*c8_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c8_i0 = 0; c8_i0 < 4; c8_i0++) {
    c8_r0 = &c8_info[c8_i0];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i0);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc8_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_mxArrayOutData, c8_y);
  return c8_mxArrayOutData;
}

static int32_T c8_c_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i1, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc8_Cinematica_MGIInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_d_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_Cinematica_MGI, const char_T *
  c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_Cinematica_MGI), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_Cinematica_MGI);
  return c8_y;
}

static uint8_T c8_e_emlrt_marshallIn(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_Cinematica_MGIInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_Cinematica_MGI_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1931000695U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(123627109U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3628437010U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2278606398U);
}

mxArray *sf_c8_Cinematica_MGI_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2259173477U);
    pr[1] = (double)(1815802398U);
    pr[2] = (double)(3214972299U);
    pr[3] = (double)(491712870U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c8_Cinematica_MGI(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[13],T\"grad\",},{M[8],M[0],T\"is_active_c8_Cinematica_MGI\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_Cinematica_MGI_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_Cinematica_MGIInstanceStruct *chartInstance;
    chartInstance = (SFc8_Cinematica_MGIInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Cinematica_MGIMachineNumber_,
           8,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"rad");
          _SFD_SET_DATA_PROPS(1,2,0,1,"grad");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,47);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);

        {
          creal_T *c8_rad;
          real_T *c8_grad;
          c8_grad = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c8_rad = (creal_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_rad);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_grad);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_Cinematica_MGIMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c8_Cinematica_MGI(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_Cinematica_MGIInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
  initialize_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_Cinematica_MGI(void *chartInstanceVar)
{
  enable_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_Cinematica_MGI(void *chartInstanceVar)
{
  disable_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_Cinematica_MGI(void *chartInstanceVar)
{
  sf_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_Cinematica_MGI(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_Cinematica_MGI
    ((SFc8_Cinematica_MGIInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_Cinematica_MGI();/* state var info */
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

extern void sf_internal_set_sim_state_c8_Cinematica_MGI(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_Cinematica_MGI();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_Cinematica_MGI(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_Cinematica_MGI(S);
}

static void sf_opaque_set_sim_state_c8_Cinematica_MGI(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c8_Cinematica_MGI(S, st);
}

static void sf_opaque_terminate_c8_Cinematica_MGI(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_Cinematica_MGIInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Cinematica_MGI(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_Cinematica_MGI((SFc8_Cinematica_MGIInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_Cinematica_MGI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Cinematica_MGI","Cinematica_MGI",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Cinematica_MGI","Cinematica_MGI",8,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Cinematica_MGI",
      "Cinematica_MGI",8,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Cinematica_MGI","Cinematica_MGI",8,
        1);
      sf_mark_chart_reusable_outputs(S,"Cinematica_MGI","Cinematica_MGI",8,1);
    }

    sf_set_rtw_dwork_info(S,"Cinematica_MGI","Cinematica_MGI",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1940113390U));
  ssSetChecksum1(S,(1336218195U));
  ssSetChecksum2(S,(2651371207U));
  ssSetChecksum3(S,(693890940U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_Cinematica_MGI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Cinematica_MGI", "Cinematica_MGI",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_Cinematica_MGI(SimStruct *S)
{
  SFc8_Cinematica_MGIInstanceStruct *chartInstance;
  chartInstance = (SFc8_Cinematica_MGIInstanceStruct *)malloc(sizeof
    (SFc8_Cinematica_MGIInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_Cinematica_MGIInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Cinematica_MGI;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_Cinematica_MGI;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_Cinematica_MGI;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_Cinematica_MGI;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_Cinematica_MGI;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_Cinematica_MGI;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_Cinematica_MGI;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_Cinematica_MGI;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_Cinematica_MGI;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_Cinematica_MGI;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_Cinematica_MGI;
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

void c8_Cinematica_MGI_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_Cinematica_MGI(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Cinematica_MGI(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Cinematica_MGI(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_Cinematica_MGI_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
