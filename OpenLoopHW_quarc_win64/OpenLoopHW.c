/*
 * OpenLoopHW.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OpenLoopHW".
 *
 * Model version              : 1.15
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Dec  5 12:03:37 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OpenLoopHW.h"
#include "rtwtypes.h"
#include <math.h>
#include "OpenLoopHW_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "OpenLoopHW_dt.h"

/* Named constants for MATLAB Function: '<S1>/MATLAB Function' */
#define OpenLoopHW_CALL_EVENT          (-1)

/* Block signals (default storage) */
B_OpenLoopHW_T OpenLoopHW_B;

/* Block states (default storage) */
DW_OpenLoopHW_T OpenLoopHW_DW;

/* Real-time model */
static RT_MODEL_OpenLoopHW_T OpenLoopHW_M_;
RT_MODEL_OpenLoopHW_T *const OpenLoopHW_M = &OpenLoopHW_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* Model output function */
void OpenLoopHW_output(void)
{
  /* local block i/o variables */
  real_T rtb_raag[2];
  real_T d11;
  real_T d11_tmp;
  real_T d11_tmp_0;
  real_T h1_tmp;
  real_T phi1_tmp;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Clock: '<Root>/Clock'
   *  Lookup_n-D: '<Root>/1-D Lookup Table'
   */
  OpenLoopHW_B.Gain2 = OpenLoopHW_P.Gain2_Gain * look1_binlxpw
    (OpenLoopHW_M->Timing.t[0], OpenLoopHW_P.t_control, OpenLoopHW_P.ut, 99U);

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: OpenLoopHW/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(OpenLoopHW_DW.HILInitialize_Card,
      &OpenLoopHW_P.HILWriteAnalog_channels, 1, &OpenLoopHW_B.Gain2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
    }
  }

  /* Constant: '<S1>/Constant1' */
  OpenLoopHW_B.Constant1[0] = OpenLoopHW_P.x0[0];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  OpenLoopHW_B.x[0] = OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Constant: '<S1>/Constant1' */
  OpenLoopHW_B.Constant1[1] = OpenLoopHW_P.x0[1];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  OpenLoopHW_B.x[1] = OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Constant: '<S1>/Constant1' */
  OpenLoopHW_B.Constant1[2] = OpenLoopHW_P.x0[2];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  OpenLoopHW_B.x[2] = OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[2];

  /* Constant: '<S1>/Constant1' */
  OpenLoopHW_B.Constant1[3] = OpenLoopHW_P.x0[3];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  OpenLoopHW_B.x[3] = OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[3];

  /* Reshape: '<Root>/Reshape' */
  OpenLoopHW_B.Reshape[0] = OpenLoopHW_B.x[0];
  OpenLoopHW_B.Reshape[1] = OpenLoopHW_B.x[1];

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  OpenLoopHW_DW.sfEvent = OpenLoopHW_CALL_EVENT;
  d11_tmp = cos(OpenLoopHW_B.x[1]);
  d11_tmp_0 = 2.0 * OpenLoopHW_P.p.T3;
  d11 = d11_tmp_0 * d11_tmp + (OpenLoopHW_P.p.T1 + OpenLoopHW_P.p.T2);
  d11_tmp = OpenLoopHW_P.p.T3 * d11_tmp + OpenLoopHW_P.p.T2;
  h1_tmp = sin(OpenLoopHW_B.x[1]);
  phi1_tmp = OpenLoopHW_P.p.T5 * OpenLoopHW_P.p.g * cos(OpenLoopHW_B.x[0] +
    OpenLoopHW_B.x[1]);
  OpenLoopHW_B.dx[0] = OpenLoopHW_B.x[2];
  OpenLoopHW_B.dx[1] = OpenLoopHW_B.x[3];
  d11_tmp_0 = ((-OpenLoopHW_P.p.T3 * h1_tmp * (OpenLoopHW_B.x[3] *
    OpenLoopHW_B.x[3]) - d11_tmp_0 * h1_tmp * OpenLoopHW_B.x[3] *
                OpenLoopHW_B.x[2]) + (OpenLoopHW_P.p.T4 * OpenLoopHW_P.p.g * cos
    (OpenLoopHW_B.x[0]) + phi1_tmp)) - OpenLoopHW_B.Gain2;
  h1_tmp = OpenLoopHW_P.p.T3 * h1_tmp * (OpenLoopHW_B.x[2] * OpenLoopHW_B.x[2])
    + phi1_tmp;
  phi1_tmp = d11 * OpenLoopHW_P.p.T2 - d11_tmp * d11_tmp;
  OpenLoopHW_B.dx[2] = (h1_tmp * d11_tmp - d11_tmp_0 * OpenLoopHW_P.p.T2) /
    phi1_tmp;
  OpenLoopHW_B.dx[3] = (d11_tmp_0 * d11_tmp - h1_tmp * d11) / phi1_tmp;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: OpenLoopHW/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(OpenLoopHW_DW.HILInitialize_Card,
      OpenLoopHW_P.HILReadEncoder_channels, 2,
      &OpenLoopHW_DW.HILReadEncoder_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
    } else {
      rtb_raag[0] = OpenLoopHW_DW.HILReadEncoder_Buffer[0];
      rtb_raag[1] = OpenLoopHW_DW.HILReadEncoder_Buffer[1];
    }
  }

  /* Step: '<Root>/Step' */
  if (OpenLoopHW_M->Timing.t[0] < OpenLoopHW_P.Step_Time) {
    /* Step: '<Root>/Step' */
    OpenLoopHW_B.Step = OpenLoopHW_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    OpenLoopHW_B.Step = OpenLoopHW_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
}

/* Model update function */
void OpenLoopHW_update(void)
{
  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    OpenLoopHW_P.DiscreteTimeIntegrator_gainval * OpenLoopHW_B.dx[0];
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    OpenLoopHW_P.DiscreteTimeIntegrator_gainval * OpenLoopHW_B.dx[1];
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[2] +=
    OpenLoopHW_P.DiscreteTimeIntegrator_gainval * OpenLoopHW_B.dx[2];
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[3] +=
    OpenLoopHW_P.DiscreteTimeIntegrator_gainval * OpenLoopHW_B.dx[3];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++OpenLoopHW_M->Timing.clockTick0)) {
    ++OpenLoopHW_M->Timing.clockTickH0;
  }

  OpenLoopHW_M->Timing.t[0] = OpenLoopHW_M->Timing.clockTick0 *
    OpenLoopHW_M->Timing.stepSize0 + OpenLoopHW_M->Timing.clockTickH0 *
    OpenLoopHW_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++OpenLoopHW_M->Timing.clockTick1)) {
      ++OpenLoopHW_M->Timing.clockTickH1;
    }

    OpenLoopHW_M->Timing.t[1] = OpenLoopHW_M->Timing.clockTick1 *
      OpenLoopHW_M->Timing.stepSize1 + OpenLoopHW_M->Timing.clockTickH1 *
      OpenLoopHW_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void OpenLoopHW_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: OpenLoopHW/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &OpenLoopHW_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((OpenLoopHW_P.HILInitialize_CKPStart && !is_switching) ||
        (OpenLoopHW_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(OpenLoopHW_DW.HILInitialize_Card, (t_clock *)
        OpenLoopHW_P.HILInitialize_CKChannels, 2U, (t_clock_mode *)
        OpenLoopHW_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(OpenLoopHW_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
      return;
    }

    if ((OpenLoopHW_P.HILInitialize_AIPStart && !is_switching) ||
        (OpenLoopHW_P.HILInitialize_AIPEnter && is_switching)) {
      OpenLoopHW_DW.HILInitialize_AIMinimums[0] =
        (OpenLoopHW_P.HILInitialize_AILow);
      OpenLoopHW_DW.HILInitialize_AIMinimums[1] =
        (OpenLoopHW_P.HILInitialize_AILow);
      OpenLoopHW_DW.HILInitialize_AIMinimums[2] =
        (OpenLoopHW_P.HILInitialize_AILow);
      OpenLoopHW_DW.HILInitialize_AIMinimums[3] =
        (OpenLoopHW_P.HILInitialize_AILow);
      OpenLoopHW_DW.HILInitialize_AIMaximums[0] =
        OpenLoopHW_P.HILInitialize_AIHigh;
      OpenLoopHW_DW.HILInitialize_AIMaximums[1] =
        OpenLoopHW_P.HILInitialize_AIHigh;
      OpenLoopHW_DW.HILInitialize_AIMaximums[2] =
        OpenLoopHW_P.HILInitialize_AIHigh;
      OpenLoopHW_DW.HILInitialize_AIMaximums[3] =
        OpenLoopHW_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(OpenLoopHW_DW.HILInitialize_Card,
        OpenLoopHW_P.HILInitialize_AIChannels, 4U,
        &OpenLoopHW_DW.HILInitialize_AIMinimums[0],
        &OpenLoopHW_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }
    }

    if ((OpenLoopHW_P.HILInitialize_AOPStart && !is_switching) ||
        (OpenLoopHW_P.HILInitialize_AOPEnter && is_switching)) {
      OpenLoopHW_DW.HILInitialize_AOMinimums[0] =
        (OpenLoopHW_P.HILInitialize_AOLow);
      OpenLoopHW_DW.HILInitialize_AOMinimums[1] =
        (OpenLoopHW_P.HILInitialize_AOLow);
      OpenLoopHW_DW.HILInitialize_AOMinimums[2] =
        (OpenLoopHW_P.HILInitialize_AOLow);
      OpenLoopHW_DW.HILInitialize_AOMinimums[3] =
        (OpenLoopHW_P.HILInitialize_AOLow);
      OpenLoopHW_DW.HILInitialize_AOMaximums[0] =
        OpenLoopHW_P.HILInitialize_AOHigh;
      OpenLoopHW_DW.HILInitialize_AOMaximums[1] =
        OpenLoopHW_P.HILInitialize_AOHigh;
      OpenLoopHW_DW.HILInitialize_AOMaximums[2] =
        OpenLoopHW_P.HILInitialize_AOHigh;
      OpenLoopHW_DW.HILInitialize_AOMaximums[3] =
        OpenLoopHW_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(OpenLoopHW_DW.HILInitialize_Card,
        OpenLoopHW_P.HILInitialize_AOChannels, 4U,
        &OpenLoopHW_DW.HILInitialize_AOMinimums[0],
        &OpenLoopHW_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }
    }

    if ((OpenLoopHW_P.HILInitialize_AOStart && !is_switching) ||
        (OpenLoopHW_P.HILInitialize_AOEnter && is_switching)) {
      OpenLoopHW_DW.HILInitialize_AOVoltages[0] =
        OpenLoopHW_P.HILInitialize_AOInitial;
      OpenLoopHW_DW.HILInitialize_AOVoltages[1] =
        OpenLoopHW_P.HILInitialize_AOInitial;
      OpenLoopHW_DW.HILInitialize_AOVoltages[2] =
        OpenLoopHW_P.HILInitialize_AOInitial;
      OpenLoopHW_DW.HILInitialize_AOVoltages[3] =
        OpenLoopHW_P.HILInitialize_AOInitial;
      result = hil_write_analog(OpenLoopHW_DW.HILInitialize_Card,
        OpenLoopHW_P.HILInitialize_AOChannels, 4U,
        &OpenLoopHW_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }
    }

    if (OpenLoopHW_P.HILInitialize_AOReset) {
      OpenLoopHW_DW.HILInitialize_AOVoltages[0] =
        OpenLoopHW_P.HILInitialize_AOWatchdog;
      OpenLoopHW_DW.HILInitialize_AOVoltages[1] =
        OpenLoopHW_P.HILInitialize_AOWatchdog;
      OpenLoopHW_DW.HILInitialize_AOVoltages[2] =
        OpenLoopHW_P.HILInitialize_AOWatchdog;
      OpenLoopHW_DW.HILInitialize_AOVoltages[3] =
        OpenLoopHW_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (OpenLoopHW_DW.HILInitialize_Card, OpenLoopHW_P.HILInitialize_AOChannels,
         4U, &OpenLoopHW_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }
    }

    if ((OpenLoopHW_P.HILInitialize_EIPStart && !is_switching) ||
        (OpenLoopHW_P.HILInitialize_EIPEnter && is_switching)) {
      OpenLoopHW_DW.HILInitialize_QuadratureModes[0] =
        OpenLoopHW_P.HILInitialize_EIQuadrature;
      OpenLoopHW_DW.HILInitialize_QuadratureModes[1] =
        OpenLoopHW_P.HILInitialize_EIQuadrature;
      OpenLoopHW_DW.HILInitialize_QuadratureModes[2] =
        OpenLoopHW_P.HILInitialize_EIQuadrature;
      OpenLoopHW_DW.HILInitialize_QuadratureModes[3] =
        OpenLoopHW_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(OpenLoopHW_DW.HILInitialize_Card,
        OpenLoopHW_P.HILInitialize_EIChannels, 4U, (t_encoder_quadrature_mode *)
        &OpenLoopHW_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }

      OpenLoopHW_DW.HILInitialize_FilterFrequency[0] =
        OpenLoopHW_P.HILInitialize_EIFrequency;
      OpenLoopHW_DW.HILInitialize_FilterFrequency[1] =
        OpenLoopHW_P.HILInitialize_EIFrequency;
      OpenLoopHW_DW.HILInitialize_FilterFrequency[2] =
        OpenLoopHW_P.HILInitialize_EIFrequency;
      OpenLoopHW_DW.HILInitialize_FilterFrequency[3] =
        OpenLoopHW_P.HILInitialize_EIFrequency;
      result = hil_set_encoder_filter_frequency(OpenLoopHW_DW.HILInitialize_Card,
        OpenLoopHW_P.HILInitialize_EIChannels, 4U,
        &OpenLoopHW_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }
    }

    if ((OpenLoopHW_P.HILInitialize_EIStart && !is_switching) ||
        (OpenLoopHW_P.HILInitialize_EIEnter && is_switching)) {
      OpenLoopHW_DW.HILInitialize_InitialEICounts[0] =
        OpenLoopHW_P.HILInitialize_EIInitial;
      OpenLoopHW_DW.HILInitialize_InitialEICounts[1] =
        OpenLoopHW_P.HILInitialize_EIInitial;
      OpenLoopHW_DW.HILInitialize_InitialEICounts[2] =
        OpenLoopHW_P.HILInitialize_EIInitial;
      OpenLoopHW_DW.HILInitialize_InitialEICounts[3] =
        OpenLoopHW_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(OpenLoopHW_DW.HILInitialize_Card,
        OpenLoopHW_P.HILInitialize_EIChannels, 4U,
        &OpenLoopHW_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Constant: '<S1>/Constant1' */
  OpenLoopHW_B.Constant1[0] = OpenLoopHW_P.x0[0];
  OpenLoopHW_B.Constant1[1] = OpenLoopHW_P.x0[1];
  OpenLoopHW_B.Constant1[2] = OpenLoopHW_P.x0[2];
  OpenLoopHW_B.Constant1[3] = OpenLoopHW_P.x0[3];

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[0] = OpenLoopHW_B.Constant1[0];
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[1] = OpenLoopHW_B.Constant1[1];
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[2] = OpenLoopHW_B.Constant1[2];
  OpenLoopHW_DW.DiscreteTimeIntegrator_DSTATE[3] = OpenLoopHW_B.Constant1[3];

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  OpenLoopHW_DW.sfEvent = OpenLoopHW_CALL_EVENT;
  OpenLoopHW_DW.is_active_c1_OpenLoopHW = 0U;
}

/* Model terminate function */
void OpenLoopHW_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: OpenLoopHW/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(OpenLoopHW_DW.HILInitialize_Card);
    hil_monitor_stop_all(OpenLoopHW_DW.HILInitialize_Card);
    is_switching = false;
    if ((OpenLoopHW_P.HILInitialize_AOTerminate && !is_switching) ||
        (OpenLoopHW_P.HILInitialize_AOExit && is_switching)) {
      OpenLoopHW_DW.HILInitialize_AOVoltages[0] =
        OpenLoopHW_P.HILInitialize_AOFinal;
      OpenLoopHW_DW.HILInitialize_AOVoltages[1] =
        OpenLoopHW_P.HILInitialize_AOFinal;
      OpenLoopHW_DW.HILInitialize_AOVoltages[2] =
        OpenLoopHW_P.HILInitialize_AOFinal;
      OpenLoopHW_DW.HILInitialize_AOVoltages[3] =
        OpenLoopHW_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 4U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(OpenLoopHW_DW.HILInitialize_Card,
        OpenLoopHW_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &OpenLoopHW_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(OpenLoopHW_M, _rt_error_message);
      }
    }

    hil_task_delete_all(OpenLoopHW_DW.HILInitialize_Card);
    hil_monitor_delete_all(OpenLoopHW_DW.HILInitialize_Card);
    hil_close(OpenLoopHW_DW.HILInitialize_Card);
    OpenLoopHW_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  OpenLoopHW_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  OpenLoopHW_update();
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
  OpenLoopHW_initialize();
}

void MdlTerminate(void)
{
  OpenLoopHW_terminate();
}

/* Registration function */
RT_MODEL_OpenLoopHW_T *OpenLoopHW(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)OpenLoopHW_M, 0,
                sizeof(RT_MODEL_OpenLoopHW_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&OpenLoopHW_M->solverInfo,
                          &OpenLoopHW_M->Timing.simTimeStep);
    rtsiSetTPtr(&OpenLoopHW_M->solverInfo, &rtmGetTPtr(OpenLoopHW_M));
    rtsiSetStepSizePtr(&OpenLoopHW_M->solverInfo,
                       &OpenLoopHW_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&OpenLoopHW_M->solverInfo, (&rtmGetErrorStatus
      (OpenLoopHW_M)));
    rtsiSetRTModelPtr(&OpenLoopHW_M->solverInfo, OpenLoopHW_M);
  }

  rtsiSetSimTimeStep(&OpenLoopHW_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&OpenLoopHW_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = OpenLoopHW_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "OpenLoopHW_M points to
       static memory which is guaranteed to be non-NULL" */
    OpenLoopHW_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    OpenLoopHW_M->Timing.sampleTimes = (&OpenLoopHW_M->Timing.sampleTimesArray[0]);
    OpenLoopHW_M->Timing.offsetTimes = (&OpenLoopHW_M->Timing.offsetTimesArray[0]);

    /* task periods */
    OpenLoopHW_M->Timing.sampleTimes[0] = (0.0);
    OpenLoopHW_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    OpenLoopHW_M->Timing.offsetTimes[0] = (0.0);
    OpenLoopHW_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(OpenLoopHW_M, &OpenLoopHW_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = OpenLoopHW_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    OpenLoopHW_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(OpenLoopHW_M, 10.0);
  OpenLoopHW_M->Timing.stepSize0 = 0.001;
  OpenLoopHW_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  OpenLoopHW_M->Sizes.checksums[0] = (3368250566U);
  OpenLoopHW_M->Sizes.checksums[1] = (1952631749U);
  OpenLoopHW_M->Sizes.checksums[2] = (1717565681U);
  OpenLoopHW_M->Sizes.checksums[3] = (2220358810U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    OpenLoopHW_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(OpenLoopHW_M->extModeInfo,
      &OpenLoopHW_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(OpenLoopHW_M->extModeInfo, OpenLoopHW_M->Sizes.checksums);
    rteiSetTPtr(OpenLoopHW_M->extModeInfo, rtmGetTPtr(OpenLoopHW_M));
  }

  OpenLoopHW_M->solverInfoPtr = (&OpenLoopHW_M->solverInfo);
  OpenLoopHW_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&OpenLoopHW_M->solverInfo, 0.001);
  rtsiSetSolverMode(&OpenLoopHW_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  OpenLoopHW_M->blockIO = ((void *) &OpenLoopHW_B);
  (void) memset(((void *) &OpenLoopHW_B), 0,
                sizeof(B_OpenLoopHW_T));

  /* parameters */
  OpenLoopHW_M->defaultParam = ((real_T *)&OpenLoopHW_P);

  /* states (dwork) */
  OpenLoopHW_M->dwork = ((void *) &OpenLoopHW_DW);
  (void) memset((void *)&OpenLoopHW_DW, 0,
                sizeof(DW_OpenLoopHW_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    OpenLoopHW_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  OpenLoopHW_M->Sizes.numContStates = (0);/* Number of continuous states */
  OpenLoopHW_M->Sizes.numY = (0);      /* Number of model outputs */
  OpenLoopHW_M->Sizes.numU = (0);      /* Number of model inputs */
  OpenLoopHW_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  OpenLoopHW_M->Sizes.numSampTimes = (2);/* Number of sample times */
  OpenLoopHW_M->Sizes.numBlocks = (16);/* Number of blocks */
  OpenLoopHW_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  OpenLoopHW_M->Sizes.numBlockPrms = (285);/* Sum of parameter "widths" */
  return OpenLoopHW_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
