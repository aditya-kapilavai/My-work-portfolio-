/* Include files */

#include "CONTROL_POSICION_sfun.h"
#include "CONTROL_POSICION_sfun_debug_macros.h"
#include "c1_CONTROL_POSICION.h"
#include "c2_CONTROL_POSICION.h"
#include "c3_CONTROL_POSICION.h"
#include "c4_CONTROL_POSICION.h"
#include "c5_CONTROL_POSICION.h"
#include "c6_CONTROL_POSICION.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CONTROL_POSICIONMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void CONTROL_POSICION_initializer(void)
{
}

void CONTROL_POSICION_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CONTROL_POSICION_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_CONTROL_POSICION_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_CONTROL_POSICION_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_CONTROL_POSICION_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_CONTROL_POSICION_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_CONTROL_POSICION_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_CONTROL_POSICION_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_CONTROL_POSICION_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2692590011U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3334120836U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(707710623U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(365736127U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3841034439U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3863155520U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3858969536U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1598896109U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_CONTROL_POSICION_get_check_sum(mxArray *plhs[]);
          sf_c1_CONTROL_POSICION_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_CONTROL_POSICION_get_check_sum(mxArray *plhs[]);
          sf_c2_CONTROL_POSICION_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_CONTROL_POSICION_get_check_sum(mxArray *plhs[]);
          sf_c3_CONTROL_POSICION_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_CONTROL_POSICION_get_check_sum(mxArray *plhs[]);
          sf_c4_CONTROL_POSICION_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_CONTROL_POSICION_get_check_sum(mxArray *plhs[]);
          sf_c5_CONTROL_POSICION_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_CONTROL_POSICION_get_check_sum(mxArray *plhs[]);
          sf_c6_CONTROL_POSICION_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(846264881U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1652831170U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3082711593U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1316968870U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CONTROL_POSICION_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "19Dgqhll5JvU1i0l9PAjL") == 0) {
          extern mxArray *sf_c1_CONTROL_POSICION_get_autoinheritance_info(void);
          plhs[0] = sf_c1_CONTROL_POSICION_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "21Lnlv0qE5ASYGFWUOgVdB") == 0) {
          extern mxArray *sf_c2_CONTROL_POSICION_get_autoinheritance_info(void);
          plhs[0] = sf_c2_CONTROL_POSICION_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "qt9PasxyWEVFHQCrZagdZH") == 0) {
          extern mxArray *sf_c3_CONTROL_POSICION_get_autoinheritance_info(void);
          plhs[0] = sf_c3_CONTROL_POSICION_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "1TBhmtu1pNvM2USmzz8Nk") == 0) {
          extern mxArray *sf_c4_CONTROL_POSICION_get_autoinheritance_info(void);
          plhs[0] = sf_c4_CONTROL_POSICION_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "TiGvxp2biOPjI8IFD0PTGC") == 0) {
          extern mxArray *sf_c5_CONTROL_POSICION_get_autoinheritance_info(void);
          plhs[0] = sf_c5_CONTROL_POSICION_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "TiGvxp2biOPjI8IFD0PTGC") == 0) {
          extern mxArray *sf_c6_CONTROL_POSICION_get_autoinheritance_info(void);
          plhs[0] = sf_c6_CONTROL_POSICION_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CONTROL_POSICION_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_CONTROL_POSICION_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CONTROL_POSICION_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_CONTROL_POSICION_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_CONTROL_POSICION_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_CONTROL_POSICION_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_CONTROL_POSICION_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_CONTROL_POSICION_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_CONTROL_POSICION_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_CONTROL_POSICION_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_CONTROL_POSICION_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_CONTROL_POSICION_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_CONTROL_POSICION_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CONTROL_POSICION_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "XcwVZo5fKnZY4k0jPLKGME") == 0) {
          extern mxArray *sf_c1_CONTROL_POSICION_third_party_uses_info(void);
          plhs[0] = sf_c1_CONTROL_POSICION_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "1xZKXtqcTzT7nbuwjxBZ8D") == 0) {
          extern mxArray *sf_c2_CONTROL_POSICION_third_party_uses_info(void);
          plhs[0] = sf_c2_CONTROL_POSICION_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "0J6y9PKLT8TJJbijnOg4PD") == 0) {
          extern mxArray *sf_c3_CONTROL_POSICION_third_party_uses_info(void);
          plhs[0] = sf_c3_CONTROL_POSICION_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "4TOIRtOT1k1ISe25zE3a3E") == 0) {
          extern mxArray *sf_c4_CONTROL_POSICION_third_party_uses_info(void);
          plhs[0] = sf_c4_CONTROL_POSICION_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "bAd2E1J1EBFdYi4837m9hE") == 0) {
          extern mxArray *sf_c5_CONTROL_POSICION_third_party_uses_info(void);
          plhs[0] = sf_c5_CONTROL_POSICION_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "bAd2E1J1EBFdYi4837m9hE") == 0) {
          extern mxArray *sf_c6_CONTROL_POSICION_third_party_uses_info(void);
          plhs[0] = sf_c6_CONTROL_POSICION_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void CONTROL_POSICION_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _CONTROL_POSICIONMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "CONTROL_POSICION","sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _CONTROL_POSICIONMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _CONTROL_POSICIONMachineNumber_,0);
}

void CONTROL_POSICION_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_CONTROL_POSICION_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "CONTROL_POSICION", "CONTROL_POSICION");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CONTROL_POSICION_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
