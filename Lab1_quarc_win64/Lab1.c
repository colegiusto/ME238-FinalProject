/*
 * Lab1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Lab1".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Dec  3 11:13:44 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab1.h"
#include "rtwtypes.h"
#include "Lab1_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Lab1_dt.h"

/* Block signals (default storage) */
B_Lab1_T Lab1_B;

/* Block states (default storage) */
DW_Lab1_T Lab1_DW;

/* Real-time model */
static RT_MODEL_Lab1_T Lab1_M_;
RT_MODEL_Lab1_T *const Lab1_M = &Lab1_M_;

/* Model output function */
void Lab1_output(void)
{
  real_T rtb_raag[2];
  real_T rtb_Gain2;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Gain2 = Lab1_P.Gain2_Gain * Lab1_P.Constant_Value;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Lab1/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Lab1_DW.HILInitialize_Card,
      &Lab1_P.HILWriteAnalog_channels, 1, &rtb_Gain2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab1_M, _rt_error_message);
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Lab1/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Lab1_DW.HILInitialize_Card,
      Lab1_P.HILReadEncoder_channels, 2, &Lab1_DW.HILReadEncoder_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab1_M, _rt_error_message);
    } else {
      rtb_raag[0] = Lab1_DW.HILReadEncoder_Buffer[0];
      rtb_raag[1] = Lab1_DW.HILReadEncoder_Buffer[1];
    }
  }

  /* Gain: '<Root>/Gain' */
  Lab1_B.Gain = Lab1_P.Gain_Gain * rtb_raag[0];

  /* Gain: '<Root>/Gain1' */
  Lab1_B.Gain1 = Lab1_P.Gain1_Gain * rtb_raag[1];

  /* SignalConversion generated from: '<Root>/To Workspace' */
  Lab1_B.TmpSignalConversionAtToWorkspac[0] = Lab1_B.Gain;
  Lab1_B.TmpSignalConversionAtToWorkspac[1] = Lab1_B.Gain1;

  /* Step: '<Root>/Step' */
  if (Lab1_M->Timing.t[0] < Lab1_P.Step_Time) {
    /* Step: '<Root>/Step' */
    Lab1_B.Step = Lab1_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    Lab1_B.Step = Lab1_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
}

/* Model update function */
void Lab1_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab1_M->Timing.clockTick0)) {
    ++Lab1_M->Timing.clockTickH0;
  }

  Lab1_M->Timing.t[0] = Lab1_M->Timing.clockTick0 * Lab1_M->Timing.stepSize0 +
    Lab1_M->Timing.clockTickH0 * Lab1_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Lab1_M->Timing.clockTick1)) {
      ++Lab1_M->Timing.clockTickH1;
    }

    Lab1_M->Timing.t[1] = Lab1_M->Timing.clockTick1 * Lab1_M->Timing.stepSize1 +
      Lab1_M->Timing.clockTickH1 * Lab1_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Lab1_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab1/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &Lab1_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab1_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((Lab1_P.HILInitialize_CKPStart && !is_switching) ||
        (Lab1_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(Lab1_DW.HILInitialize_Card, (t_clock *)
        Lab1_P.HILInitialize_CKChannels, 2U, (t_clock_mode *)
        Lab1_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(Lab1_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Lab1_M, _rt_error_message);
      return;
    }

    if ((Lab1_P.HILInitialize_AIPStart && !is_switching) ||
        (Lab1_P.HILInitialize_AIPEnter && is_switching)) {
      Lab1_DW.HILInitialize_AIMinimums[0] = (Lab1_P.HILInitialize_AILow);
      Lab1_DW.HILInitialize_AIMinimums[1] = (Lab1_P.HILInitialize_AILow);
      Lab1_DW.HILInitialize_AIMinimums[2] = (Lab1_P.HILInitialize_AILow);
      Lab1_DW.HILInitialize_AIMinimums[3] = (Lab1_P.HILInitialize_AILow);
      Lab1_DW.HILInitialize_AIMaximums[0] = Lab1_P.HILInitialize_AIHigh;
      Lab1_DW.HILInitialize_AIMaximums[1] = Lab1_P.HILInitialize_AIHigh;
      Lab1_DW.HILInitialize_AIMaximums[2] = Lab1_P.HILInitialize_AIHigh;
      Lab1_DW.HILInitialize_AIMaximums[3] = Lab1_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(Lab1_DW.HILInitialize_Card,
        Lab1_P.HILInitialize_AIChannels, 4U,
        &Lab1_DW.HILInitialize_AIMinimums[0], &Lab1_DW.HILInitialize_AIMaximums
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Lab1_P.HILInitialize_AOPStart && !is_switching) ||
        (Lab1_P.HILInitialize_AOPEnter && is_switching)) {
      Lab1_DW.HILInitialize_AOMinimums[0] = (Lab1_P.HILInitialize_AOLow);
      Lab1_DW.HILInitialize_AOMinimums[1] = (Lab1_P.HILInitialize_AOLow);
      Lab1_DW.HILInitialize_AOMinimums[2] = (Lab1_P.HILInitialize_AOLow);
      Lab1_DW.HILInitialize_AOMinimums[3] = (Lab1_P.HILInitialize_AOLow);
      Lab1_DW.HILInitialize_AOMaximums[0] = Lab1_P.HILInitialize_AOHigh;
      Lab1_DW.HILInitialize_AOMaximums[1] = Lab1_P.HILInitialize_AOHigh;
      Lab1_DW.HILInitialize_AOMaximums[2] = Lab1_P.HILInitialize_AOHigh;
      Lab1_DW.HILInitialize_AOMaximums[3] = Lab1_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(Lab1_DW.HILInitialize_Card,
        Lab1_P.HILInitialize_AOChannels, 4U,
        &Lab1_DW.HILInitialize_AOMinimums[0], &Lab1_DW.HILInitialize_AOMaximums
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Lab1_P.HILInitialize_AOStart && !is_switching) ||
        (Lab1_P.HILInitialize_AOEnter && is_switching)) {
      Lab1_DW.HILInitialize_AOVoltages[0] = Lab1_P.HILInitialize_AOInitial;
      Lab1_DW.HILInitialize_AOVoltages[1] = Lab1_P.HILInitialize_AOInitial;
      Lab1_DW.HILInitialize_AOVoltages[2] = Lab1_P.HILInitialize_AOInitial;
      Lab1_DW.HILInitialize_AOVoltages[3] = Lab1_P.HILInitialize_AOInitial;
      result = hil_write_analog(Lab1_DW.HILInitialize_Card,
        Lab1_P.HILInitialize_AOChannels, 4U, &Lab1_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }
    }

    if (Lab1_P.HILInitialize_AOReset) {
      Lab1_DW.HILInitialize_AOVoltages[0] = Lab1_P.HILInitialize_AOWatchdog;
      Lab1_DW.HILInitialize_AOVoltages[1] = Lab1_P.HILInitialize_AOWatchdog;
      Lab1_DW.HILInitialize_AOVoltages[2] = Lab1_P.HILInitialize_AOWatchdog;
      Lab1_DW.HILInitialize_AOVoltages[3] = Lab1_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Lab1_DW.HILInitialize_Card, Lab1_P.HILInitialize_AOChannels, 4U,
         &Lab1_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Lab1_P.HILInitialize_EIPStart && !is_switching) ||
        (Lab1_P.HILInitialize_EIPEnter && is_switching)) {
      Lab1_DW.HILInitialize_QuadratureModes[0] =
        Lab1_P.HILInitialize_EIQuadrature;
      Lab1_DW.HILInitialize_QuadratureModes[1] =
        Lab1_P.HILInitialize_EIQuadrature;
      Lab1_DW.HILInitialize_QuadratureModes[2] =
        Lab1_P.HILInitialize_EIQuadrature;
      Lab1_DW.HILInitialize_QuadratureModes[3] =
        Lab1_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(Lab1_DW.HILInitialize_Card,
        Lab1_P.HILInitialize_EIChannels, 4U, (t_encoder_quadrature_mode *)
        &Lab1_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }

      Lab1_DW.HILInitialize_FilterFrequency[0] =
        Lab1_P.HILInitialize_EIFrequency;
      Lab1_DW.HILInitialize_FilterFrequency[1] =
        Lab1_P.HILInitialize_EIFrequency;
      Lab1_DW.HILInitialize_FilterFrequency[2] =
        Lab1_P.HILInitialize_EIFrequency;
      Lab1_DW.HILInitialize_FilterFrequency[3] =
        Lab1_P.HILInitialize_EIFrequency;
      result = hil_set_encoder_filter_frequency(Lab1_DW.HILInitialize_Card,
        Lab1_P.HILInitialize_EIChannels, 4U,
        &Lab1_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Lab1_P.HILInitialize_EIStart && !is_switching) ||
        (Lab1_P.HILInitialize_EIEnter && is_switching)) {
      Lab1_DW.HILInitialize_InitialEICounts[0] = Lab1_P.HILInitialize_EIInitial;
      Lab1_DW.HILInitialize_InitialEICounts[1] = Lab1_P.HILInitialize_EIInitial;
      Lab1_DW.HILInitialize_InitialEICounts[2] = Lab1_P.HILInitialize_EIInitial;
      Lab1_DW.HILInitialize_InitialEICounts[3] = Lab1_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Lab1_DW.HILInitialize_Card,
        Lab1_P.HILInitialize_EIChannels, 4U,
        &Lab1_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Lab1_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Lab1/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Lab1_DW.HILInitialize_Card);
    hil_monitor_stop_all(Lab1_DW.HILInitialize_Card);
    is_switching = false;
    if ((Lab1_P.HILInitialize_AOTerminate && !is_switching) ||
        (Lab1_P.HILInitialize_AOExit && is_switching)) {
      Lab1_DW.HILInitialize_AOVoltages[0] = Lab1_P.HILInitialize_AOFinal;
      Lab1_DW.HILInitialize_AOVoltages[1] = Lab1_P.HILInitialize_AOFinal;
      Lab1_DW.HILInitialize_AOVoltages[2] = Lab1_P.HILInitialize_AOFinal;
      Lab1_DW.HILInitialize_AOVoltages[3] = Lab1_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 4U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Lab1_DW.HILInitialize_Card,
        Lab1_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Lab1_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Lab1_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Lab1_DW.HILInitialize_Card);
    hil_monitor_delete_all(Lab1_DW.HILInitialize_Card);
    hil_close(Lab1_DW.HILInitialize_Card);
    Lab1_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Lab1_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Lab1_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Lab1_initialize();
}

void MdlTerminate(void)
{
  Lab1_terminate();
}

/* Registration function */
RT_MODEL_Lab1_T *Lab1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab1_M, 0,
                sizeof(RT_MODEL_Lab1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab1_M->solverInfo, &Lab1_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab1_M->solverInfo, &rtmGetTPtr(Lab1_M));
    rtsiSetStepSizePtr(&Lab1_M->solverInfo, &Lab1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Lab1_M->solverInfo, (&rtmGetErrorStatus(Lab1_M)));
    rtsiSetRTModelPtr(&Lab1_M->solverInfo, Lab1_M);
  }

  rtsiSetSimTimeStep(&Lab1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Lab1_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Lab1_M points to
       static memory which is guaranteed to be non-NULL" */
    Lab1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab1_M->Timing.sampleTimes = (&Lab1_M->Timing.sampleTimesArray[0]);
    Lab1_M->Timing.offsetTimes = (&Lab1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab1_M->Timing.sampleTimes[0] = (0.0);
    Lab1_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Lab1_M->Timing.offsetTimes[0] = (0.0);
    Lab1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Lab1_M, &Lab1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Lab1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab1_M, 30.0);
  Lab1_M->Timing.stepSize0 = 0.001;
  Lab1_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Lab1_M->Sizes.checksums[0] = (1798072705U);
  Lab1_M->Sizes.checksums[1] = (941403783U);
  Lab1_M->Sizes.checksums[2] = (3784757093U);
  Lab1_M->Sizes.checksums[3] = (3963580342U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Lab1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Lab1_M->extModeInfo,
      &Lab1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Lab1_M->extModeInfo, Lab1_M->Sizes.checksums);
    rteiSetTPtr(Lab1_M->extModeInfo, rtmGetTPtr(Lab1_M));
  }

  Lab1_M->solverInfoPtr = (&Lab1_M->solverInfo);
  Lab1_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab1_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lab1_M->blockIO = ((void *) &Lab1_B);
  (void) memset(((void *) &Lab1_B), 0,
                sizeof(B_Lab1_T));

  /* parameters */
  Lab1_M->defaultParam = ((real_T *)&Lab1_P);

  /* states (dwork) */
  Lab1_M->dwork = ((void *) &Lab1_DW);
  (void) memset((void *)&Lab1_DW, 0,
                sizeof(DW_Lab1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Lab1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Lab1_M->Sizes.numContStates = (0);   /* Number of continuous states */
  Lab1_M->Sizes.numY = (0);            /* Number of model outputs */
  Lab1_M->Sizes.numU = (0);            /* Number of model inputs */
  Lab1_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  Lab1_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  Lab1_M->Sizes.numBlocks = (12);      /* Number of blocks */
  Lab1_M->Sizes.numBlockIO = (4);      /* Number of block outputs */
  Lab1_M->Sizes.numBlockPrms = (82);   /* Sum of parameter "widths" */
  return Lab1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
