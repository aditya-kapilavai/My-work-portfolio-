/* Include files */

#include "SIMULACIO_MGD_sfun.h"
#include "SIMULACIO_MGD_sfun_debug_macros.h"
#include "c1_SIMULACIO_MGD.h"
#include "c2_SIMULACIO_MGD.h"
#include "c3_SIMULACIO_MGD.h"
#include "c4_SIMULACIO_MGD.h"
#include "c5_SIMULACIO_MGD.h"
#include "c6_SIMULACIO_MGD.h"
#include "c7_SIMULACIO_MGD.h"
#include "c10_SIMULACIO_MGD.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SIMULACIO_MGDMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void SIMULACIO_MGD_initializer(void)
{
}

void SIMULACIO_MGD_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SIMULACIO_MGD_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_SIMULACIO_MGD_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SIMULACIO_MGD_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2057550667U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4119949236U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3850288019U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(578920504U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4140201493U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(594148626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4139938693U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(951449594U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c1_SIMULACIO_MGD_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c2_SIMULACIO_MGD_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c3_SIMULACIO_MGD_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c4_SIMULACIO_MGD_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c5_SIMULACIO_MGD_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c6_SIMULACIO_MGD_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c7_SIMULACIO_MGD_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_SIMULACIO_MGD_get_check_sum(mxArray *plhs[]);
          sf_c10_SIMULACIO_MGD_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1659206273U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(312981895U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3051038146U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(396864675U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SIMULACIO_MGD_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "18cHKj4qQf8SyqWjAF9yf") == 0) {
          extern mxArray *sf_c1_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c1_SIMULACIO_MGD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "97t5bFwRK1idyaIMZgU1sD") == 0) {
          extern mxArray *sf_c2_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c2_SIMULACIO_MGD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "18cHKj4qQf8SyqWjAF9yf") == 0) {
          extern mxArray *sf_c3_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c3_SIMULACIO_MGD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "upoYDWs9XZGb9rMhvt1mzE") == 0) {
          extern mxArray *sf_c4_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c4_SIMULACIO_MGD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "xV4zcXUCKdGt9m1mlulcT") == 0) {
          extern mxArray *sf_c5_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c5_SIMULACIO_MGD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "0pFtxr0N1dew49QQvFlmTC") == 0) {
          extern mxArray *sf_c6_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c6_SIMULACIO_MGD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "qmbYzKhv7F4xCy5V65uou") == 0) {
          extern mxArray *sf_c7_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c7_SIMULACIO_MGD_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "18cHKj4qQf8SyqWjAF9yf") == 0) {
          extern mxArray *sf_c10_SIMULACIO_MGD_get_autoinheritance_info(void);
          plhs[0] = sf_c10_SIMULACIO_MGD_get_autoinheritance_info();
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

unsigned int sf_SIMULACIO_MGD_get_eml_resolved_functions_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SIMULACIO_MGD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_SIMULACIO_MGD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SIMULACIO_MGD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_SIMULACIO_MGD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_SIMULACIO_MGD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_SIMULACIO_MGD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_SIMULACIO_MGD_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_SIMULACIO_MGD_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_SIMULACIO_MGD_get_eml_resolved_functions_info();
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

unsigned int sf_SIMULACIO_MGD_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "STvfMjSdegBdYfSspDx7L") == 0) {
          extern mxArray *sf_c1_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c1_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "FJ3vu96axIDH9CA5sX1VsD") == 0) {
          extern mxArray *sf_c2_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c2_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "STvfMjSdegBdYfSspDx7L") == 0) {
          extern mxArray *sf_c3_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c3_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "80nooc6ByFK5BJxPp2tChH") == 0) {
          extern mxArray *sf_c4_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c4_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "tFTq4HXlvEhnRWEdwPftfH") == 0) {
          extern mxArray *sf_c5_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c5_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "WamA6i9j8Y7d2ASGwlAHh") == 0) {
          extern mxArray *sf_c6_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c6_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "DCYlaSDVhVmYy6D7IytM0") == 0) {
          extern mxArray *sf_c7_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c7_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "STvfMjSdegBdYfSspDx7L") == 0) {
          extern mxArray *sf_c10_SIMULACIO_MGD_third_party_uses_info(void);
          plhs[0] = sf_c10_SIMULACIO_MGD_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void SIMULACIO_MGD_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _SIMULACIO_MGDMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "SIMULACIO_MGD","sfun",0,8,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _SIMULACIO_MGDMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _SIMULACIO_MGDMachineNumber_,0);
}

void SIMULACIO_MGD_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SIMULACIO_MGD_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("SIMULACIO_MGD",
      "SIMULACIO_MGD");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SIMULACIO_MGD_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
