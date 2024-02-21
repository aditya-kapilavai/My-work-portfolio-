/* Include files */

#include "blascompat32.h"
#include "Cinematica_JA_reducido_sfun.h"
#include "c6_Cinematica_JA_reducido.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Cinematica_JA_reducido_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[4] = { "nargin", "nargout", "inp",
  "outp" };

/* Function Declarations */
static void initialize_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void initialize_params_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void enable_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void disable_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void set_sim_state_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance, const mxArray
   *c6_st);
static void finalize_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void sf_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void initSimStructsc6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_outp, const char_T *c6_identifier, real_T
  c6_y[4]);
static void c6_b_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Cinematica_JA_reducido, const
  char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_Cinematica_JA_reducido = 0U;
}

static void initialize_params_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static void enable_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[4];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_outp)[4];
  c6_outp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  for (c6_i0 = 0; c6_i0 < 4; c6_i0++) {
    c6_u[c6_i0] = (*c6_outp)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Cinematica_JA_reducido;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance, const mxArray
   *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[4];
  int32_T c6_i1;
  real_T (*c6_outp)[4];
  c6_outp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "outp",
                      c6_dv0);
  for (c6_i1 = 0; c6_i1 < 4; c6_i1++) {
    (*c6_outp)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_Cinematica_JA_reducido = c6_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_Cinematica_JA_reducido");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Cinematica_JA_reducido(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static void sf_c6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  real_T c6_hoistedGlobal;
  real_T c6_inp;
  uint32_T c6_debug_family_var_map[4];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_outp[4];
  int32_T c6_i3;
  real_T *c6_b_inp;
  real_T (*c6_b_outp)[4];
  c6_b_outp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_inp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_b_inp, 0U);
  for (c6_i2 = 0; c6_i2 < 4; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_b_outp)[c6_i2], 1U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_inp;
  c6_inp = c6_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 0U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_inp, 2U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_outp, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 2);
  c6_outp[0] = 0.0;
  c6_outp[1] = 0.0;
  c6_outp[2] = 1.0;
  c6_outp[3] = c6_inp;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -2);
  sf_debug_symbol_scope_pop();
  for (c6_i3 = 0; c6_i3 < 4; c6_i3++) {
    (*c6_b_outp)[c6_i3] = c6_outp[c6_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  sf_debug_check_for_state_inconsistency(_Cinematica_JA_reducidoMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc6_Cinematica_JA_reducido
  (SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i4;
  real_T c6_b_inData[4];
  int32_T c6_i5;
  real_T c6_u[4];
  const mxArray *c6_y = NULL;
  SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i4 = 0; c6_i4 < 4; c6_i4++) {
    c6_b_inData[c6_i4] = (*(real_T (*)[4])c6_inData)[c6_i4];
  }

  for (c6_i5 = 0; c6_i5 < 4; c6_i5++) {
    c6_u[c6_i5] = c6_b_inData[c6_i5];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 4));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_outp, const char_T *c6_identifier, real_T
  c6_y[4])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_outp), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_outp);
}

static void c6_b_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[4])
{
  real_T c6_dv1[4];
  int32_T c6_i6;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c6_i6 = 0; c6_i6 < 4; c6_i6++) {
    c6_y[c6_i6] = c6_dv1[c6_i6];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_outp;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[4];
  int32_T c6_i7;
  SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c6_outp = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_outp), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_outp);
  for (c6_i7 = 0; c6_i7 < 4; c6_i7++) {
    (*(real_T (*)[4])c6_outData)[c6_i7] = c6_y[c6_i7];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
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
  SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Cinematica_JA_reducido_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c6_nameCaptureInfo;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_mxArrayOutData, c6_y);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i8;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i8, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i8;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Cinematica_JA_reducido, const
  char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Cinematica_JA_reducido), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Cinematica_JA_reducido);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_Cinematica_JA_reducidoInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_Cinematica_JA_reducido_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(428076528U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3208919818U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2882736036U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2080730417U);
}

mxArray *sf_c6_Cinematica_JA_reducido_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(435967243U);
    pr[1] = (double)(4001445290U);
    pr[2] = (double)(854945597U);
    pr[3] = (double)(355840554U);
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

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c6_Cinematica_JA_reducido(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"outp\",},{M[8],M[0],T\"is_active_c6_Cinematica_JA_reducido\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Cinematica_JA_reducido_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
    chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Cinematica_JA_reducidoMachineNumber_,
           6,
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
          init_script_number_translation(_Cinematica_JA_reducidoMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Cinematica_JA_reducidoMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Cinematica_JA_reducidoMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"inp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"outp");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,45);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          real_T *c6_inp;
          real_T (*c6_outp)[4];
          c6_outp = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_inp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_inp);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_outp);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Cinematica_JA_reducidoMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_Cinematica_JA_reducido(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_Cinematica_JA_reducido
    ((SFc6_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
  initialize_c6_Cinematica_JA_reducido
    ((SFc6_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_Cinematica_JA_reducido(void *chartInstanceVar)
{
  enable_c6_Cinematica_JA_reducido((SFc6_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_Cinematica_JA_reducido(void *chartInstanceVar)
{
  disable_c6_Cinematica_JA_reducido((SFc6_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_Cinematica_JA_reducido(void *chartInstanceVar)
{
  sf_c6_Cinematica_JA_reducido((SFc6_Cinematica_JA_reducidoInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_Cinematica_JA_reducido
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_Cinematica_JA_reducido
    ((SFc6_Cinematica_JA_reducidoInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Cinematica_JA_reducido();/* state var info */
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

extern void sf_internal_set_sim_state_c6_Cinematica_JA_reducido(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Cinematica_JA_reducido();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_Cinematica_JA_reducido
    ((SFc6_Cinematica_JA_reducidoInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_Cinematica_JA_reducido
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c6_Cinematica_JA_reducido(S);
}

static void sf_opaque_set_sim_state_c6_Cinematica_JA_reducido(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c6_Cinematica_JA_reducido(S, st);
}

static void sf_opaque_terminate_c6_Cinematica_JA_reducido(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_Cinematica_JA_reducidoInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_Cinematica_JA_reducido
      ((SFc6_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Cinematica_JA_reducido
    ((SFc6_Cinematica_JA_reducidoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Cinematica_JA_reducido(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_Cinematica_JA_reducido
      ((SFc6_Cinematica_JA_reducidoInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Cinematica_JA_reducido(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Cinematica_JA_reducido",
      "Cinematica_JA_reducido",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Cinematica_JA_reducido",
                "Cinematica_JA_reducido",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Cinematica_JA_reducido",
      "Cinematica_JA_reducido",6,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Cinematica_JA_reducido",
        "Cinematica_JA_reducido",6,1);
      sf_mark_chart_reusable_outputs(S,"Cinematica_JA_reducido",
        "Cinematica_JA_reducido",6,1);
    }

    sf_set_rtw_dwork_info(S,"Cinematica_JA_reducido","Cinematica_JA_reducido",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2141209375U));
  ssSetChecksum1(S,(1580416322U));
  ssSetChecksum2(S,(851730977U));
  ssSetChecksum3(S,(1082385805U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_Cinematica_JA_reducido(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Cinematica_JA_reducido",
      "Cinematica_JA_reducido",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Cinematica_JA_reducido(SimStruct *S)
{
  SFc6_Cinematica_JA_reducidoInstanceStruct *chartInstance;
  chartInstance = (SFc6_Cinematica_JA_reducidoInstanceStruct *)malloc(sizeof
    (SFc6_Cinematica_JA_reducidoInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_Cinematica_JA_reducidoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Cinematica_JA_reducido;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_Cinematica_JA_reducido;
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

void c6_Cinematica_JA_reducido_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Cinematica_JA_reducido(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Cinematica_JA_reducido(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Cinematica_JA_reducido(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Cinematica_JA_reducido_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
