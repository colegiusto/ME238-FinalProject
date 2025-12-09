/*
 * ClosedLoopHW.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ClosedLoopHW".
 *
 * Model version              : 1.53
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Tue Dec  9 11:22:27 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ClosedLoopHW.h"
#include "rtwtypes.h"
#include "ClosedLoopHW_types.h"
#include <emmintrin.h>
#include "ClosedLoopHW_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "ClosedLoopHW_dt.h"

/* Named constants for MATLAB Function: '<S2>/MATLAB Function' */
#define ClosedLoopHW_CALL_EVENT        (-1)

/* Block signals (default storage) */
B_ClosedLoopHW_T ClosedLoopHW_B;

/* Block states (default storage) */
DW_ClosedLoopHW_T ClosedLoopHW_DW;

/* Real-time model */
static RT_MODEL_ClosedLoopHW_T ClosedLoopHW_M_;
RT_MODEL_ClosedLoopHW_T *const ClosedLoopHW_M = &ClosedLoopHW_M_;

/* Model output function */
void ClosedLoopHW_output(void)
{
  __m128d tmp_0;
  b_dsp_FIRFilter_0_ClosedLoopH_T *obj_0;
  b_dspcodegen_FIRFilter_Closed_T *obj;
  real_T rtb_raag[2];
  real_T Delay_DSTATE_m;
  real_T Delay_DSTATE_m_0;
  real_T Delay_DSTATE_m_1;
  real_T tmp;
  real_T u0;
  real_T zCurr;
  real_T zNext;
  int32_T k;
  int32_T n;

  /* MATLAB Function: '<S3>/MATLAB Function' */
  ClosedLoopHW_DW.sfEvent = ClosedLoopHW_CALL_EVENT;

  /* Delay: '<Root>/Delay' */
  ClosedLoopHW_B.Delay[0] = ClosedLoopHW_DW.Delay_DSTATE[0];
  ClosedLoopHW_B.Delay[1] = ClosedLoopHW_DW.Delay_DSTATE[1];
  ClosedLoopHW_B.Delay[2] = ClosedLoopHW_DW.Delay_DSTATE[2];
  ClosedLoopHW_B.Delay[3] = ClosedLoopHW_DW.Delay_DSTATE[3];

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Delay: '<Root>/Delay'
   */
  u0 = ((((ClosedLoopHW_DW.Delay_DSTATE[0] - ClosedLoopHW_P.c.x_star[0]) *
          -ClosedLoopHW_P.c.K[0] + (ClosedLoopHW_DW.Delay_DSTATE[1] -
           ClosedLoopHW_P.c.x_star[1]) * -ClosedLoopHW_P.c.K[1]) +
         (ClosedLoopHW_DW.Delay_DSTATE[2] - ClosedLoopHW_P.c.x_star[2]) *
         -ClosedLoopHW_P.c.K[2]) + (ClosedLoopHW_DW.Delay_DSTATE[3] -
         ClosedLoopHW_P.c.x_star[3]) * -ClosedLoopHW_P.c.K[3]) +
    ClosedLoopHW_P.c.u_star;

  /* Saturate: '<Root>/Saturation1' */
  if (u0 > ClosedLoopHW_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    ClosedLoopHW_B.Saturation1 = ClosedLoopHW_P.Saturation1_UpperSat;
  } else if (u0 < ClosedLoopHW_P.Saturation1_LowerSat) {
    /* Saturate: '<Root>/Saturation1' */
    ClosedLoopHW_B.Saturation1 = ClosedLoopHW_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    ClosedLoopHW_B.Saturation1 = u0;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Gain: '<Root>/Gain2' */
  u0 = ClosedLoopHW_P.Gain2_Gain * ClosedLoopHW_B.Saturation1;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > ClosedLoopHW_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    ClosedLoopHW_B.Saturation = ClosedLoopHW_P.Saturation_UpperSat;
  } else if (u0 < ClosedLoopHW_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    ClosedLoopHW_B.Saturation = ClosedLoopHW_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    ClosedLoopHW_B.Saturation = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: ClosedLoopHW/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(ClosedLoopHW_DW.HILInitialize_Card,
      &ClosedLoopHW_P.HILWriteAnalog_channels, 1, &ClosedLoopHW_B.Saturation);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: ClosedLoopHW/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(ClosedLoopHW_DW.HILInitialize_Card,
      ClosedLoopHW_P.HILReadEncoder_channels, 2,
      &ClosedLoopHW_DW.HILReadEncoder_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
    } else {
      rtb_raag[0] = ClosedLoopHW_DW.HILReadEncoder_Buffer[0];
      rtb_raag[1] = ClosedLoopHW_DW.HILReadEncoder_Buffer[1];
    }
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  ClosedLoopHW_B.Add = ClosedLoopHW_P.Gain_Gain * rtb_raag[0] +
    ClosedLoopHW_P.Constant_Value;

  /* Gain: '<Root>/Gain1' */
  ClosedLoopHW_B.Gain1 = ClosedLoopHW_P.Gain1_Gain * rtb_raag[1];

  /* SignalConversion generated from: '<Root>/To Workspace' */
  ClosedLoopHW_B.TmpSignalConversionAtToWorkspac[0] = ClosedLoopHW_B.Add;
  ClosedLoopHW_B.TmpSignalConversionAtToWorkspac[1] = ClosedLoopHW_B.Gain1;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  ClosedLoopHW_B.TSamp[0] = ClosedLoopHW_B.TmpSignalConversionAtToWorkspac[0] *
    ClosedLoopHW_P.TSamp_WtEt;
  ClosedLoopHW_B.TSamp[1] = ClosedLoopHW_B.TmpSignalConversionAtToWorkspac[1] *
    ClosedLoopHW_P.TSamp_WtEt;

  /* MATLABSystem: '<Root>/Lowpass Filter' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  obj = ClosedLoopHW_DW.obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (k = 0; k < 85; k++) {
      obj->cSFunObject.W0_states[k] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  rtb_raag[0] = ClosedLoopHW_B.TSamp[0] - ClosedLoopHW_DW.UD_DSTATE[0];
  rtb_raag[1] = ClosedLoopHW_B.TSamp[1] - ClosedLoopHW_DW.UD_DSTATE[1];
  for (k = 0; k < 2; k++) {
    u0 = 0.0;

    /* load input sample */
    zNext = rtb_raag[k];
    for (n = 0; n < 85; n++) {
      /* shift state */
      zCurr = zNext;
      zNext = obj_0->W0_states[n];
      obj_0->W0_states[n] = zCurr;

      /* compute one tap */
      zCurr *= obj_0->P1_Coefficients[n];
      u0 += zCurr;
    }

    /* compute last tap */
    zCurr = obj_0->P1_Coefficients[n] * zNext;

    /* store output sample */
    rtb_raag[k] = u0 + zCurr;
  }

  /* MATLABSystem: '<Root>/Lowpass Filter' */
  ClosedLoopHW_B.LowpassFilter[0] = rtb_raag[0];
  ClosedLoopHW_B.LowpassFilter[1] = rtb_raag[1];

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/x_star'
   */
  u0 = ClosedLoopHW_B.Add - ClosedLoopHW_P.c.x_star[0];
  zNext = ClosedLoopHW_B.Gain1 - ClosedLoopHW_P.c.x_star[1];
  zCurr = ClosedLoopHW_B.LowpassFilter[0] - ClosedLoopHW_P.c.x_star[2];
  tmp = ClosedLoopHW_B.LowpassFilter[1] - ClosedLoopHW_P.c.x_star[3];
  for (k = 0; k <= 0; k += 2) {
    /* Gain: '<Root>/Multiply' */
    _mm_storeu_pd(&ClosedLoopHW_B.Multiply[k], _mm_add_pd(_mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[k + 2]), _mm_set1_pd(zNext)),
       _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[k]), _mm_set1_pd(u0))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[k + 4]), _mm_set1_pd(zCurr))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[k + 6]), _mm_set1_pd(tmp))));
  }

  /* Delay: '<S2>/Delay' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (ClosedLoopHW_DW.icLoad) {
    ClosedLoopHW_DW.Delay_DSTATE_m[0] = ClosedLoopHW_P.x0[0] -
      ClosedLoopHW_P.c.x_star[0];
    ClosedLoopHW_DW.Delay_DSTATE_m[1] = ClosedLoopHW_P.x0[1] -
      ClosedLoopHW_P.c.x_star[1];
    ClosedLoopHW_DW.Delay_DSTATE_m[2] = ClosedLoopHW_P.x0[2] -
      ClosedLoopHW_P.c.x_star[2];
    ClosedLoopHW_DW.Delay_DSTATE_m[3] = ClosedLoopHW_P.x0[3] -
      ClosedLoopHW_P.c.x_star[3];
  }

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Sum: '<S2>/Subtract'
   */
  ClosedLoopHW_DW.sfEvent_k = ClosedLoopHW_CALL_EVENT;
  u0 = ClosedLoopHW_B.Saturation1 - ClosedLoopHW_P.c.u_star;
  zNext = ClosedLoopHW_B.Multiply[0];
  zCurr = ClosedLoopHW_B.Multiply[1];

  /* Delay: '<S2>/Delay' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   */
  tmp = ClosedLoopHW_DW.Delay_DSTATE_m[1];
  Delay_DSTATE_m = ClosedLoopHW_DW.Delay_DSTATE_m[0];
  Delay_DSTATE_m_0 = ClosedLoopHW_DW.Delay_DSTATE_m[2];
  Delay_DSTATE_m_1 = ClosedLoopHW_DW.Delay_DSTATE_m[3];
  for (k = 0; k <= 2; k += 2) {
    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  Delay: '<S2>/Delay'
     */
    tmp_0 = _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
      &ClosedLoopHW_P.est_param.A[k + 4]), _mm_set1_pd(tmp)), _mm_mul_pd
      (_mm_loadu_pd(&ClosedLoopHW_P.est_param.A[k]), _mm_set1_pd(Delay_DSTATE_m))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.est_param.A[k + 8]), _mm_set1_pd
                 (Delay_DSTATE_m_0))), _mm_mul_pd(_mm_loadu_pd
      (&ClosedLoopHW_P.est_param.A[k + 12]), _mm_set1_pd(Delay_DSTATE_m_1))),
                       _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&ClosedLoopHW_P.est_param.B[k + 4]), _mm_set1_pd(zNext)), _mm_mul_pd
      (_mm_loadu_pd(&ClosedLoopHW_P.est_param.B[k]), _mm_set1_pd(u0))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.est_param.B[k + 8]), _mm_set1_pd
                 (zCurr))));
    _mm_storeu_pd(&ClosedLoopHW_B.x_hat[k], tmp_0);

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/x_star'
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    _mm_storeu_pd(&ClosedLoopHW_B.Sum[k], _mm_add_pd(tmp_0, _mm_loadu_pd
      (&ClosedLoopHW_P.c.x_star[k])));
  }

  /* Reshape: '<Root>/Reshape1' incorporates:
   *  Sum: '<Root>/Sum'
   */
  ClosedLoopHW_B.Reshape1[0] = ClosedLoopHW_B.Sum[0];
  ClosedLoopHW_B.Reshape1[1] = ClosedLoopHW_B.Sum[1];
  ClosedLoopHW_B.Reshape1[2] = ClosedLoopHW_B.Sum[2];
  ClosedLoopHW_B.Reshape1[3] = ClosedLoopHW_B.Sum[3];

  /* Step: '<Root>/Step' */
  if (ClosedLoopHW_M->Timing.t[0] < ClosedLoopHW_P.Step_Time) {
    /* Step: '<Root>/Step' */
    ClosedLoopHW_B.Step = ClosedLoopHW_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    ClosedLoopHW_B.Step = ClosedLoopHW_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
}

/* Model update function */
void ClosedLoopHW_update(void)
{
  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Sum: '<Root>/Sum'
   */
  ClosedLoopHW_DW.Delay_DSTATE[0] = ClosedLoopHW_B.Sum[0];
  ClosedLoopHW_DW.Delay_DSTATE[1] = ClosedLoopHW_B.Sum[1];
  ClosedLoopHW_DW.Delay_DSTATE[2] = ClosedLoopHW_B.Sum[2];
  ClosedLoopHW_DW.Delay_DSTATE[3] = ClosedLoopHW_B.Sum[3];

  /* Update for UnitDelay: '<S1>/UD' */
  ClosedLoopHW_DW.UD_DSTATE[0] = ClosedLoopHW_B.TSamp[0];
  ClosedLoopHW_DW.UD_DSTATE[1] = ClosedLoopHW_B.TSamp[1];

  /* Update for Delay: '<S2>/Delay' */
  ClosedLoopHW_DW.icLoad = false;
  ClosedLoopHW_DW.Delay_DSTATE_m[0] = ClosedLoopHW_B.x_hat[0];
  ClosedLoopHW_DW.Delay_DSTATE_m[1] = ClosedLoopHW_B.x_hat[1];
  ClosedLoopHW_DW.Delay_DSTATE_m[2] = ClosedLoopHW_B.x_hat[2];
  ClosedLoopHW_DW.Delay_DSTATE_m[3] = ClosedLoopHW_B.x_hat[3];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ClosedLoopHW_M->Timing.clockTick0)) {
    ++ClosedLoopHW_M->Timing.clockTickH0;
  }

  ClosedLoopHW_M->Timing.t[0] = ClosedLoopHW_M->Timing.clockTick0 *
    ClosedLoopHW_M->Timing.stepSize0 + ClosedLoopHW_M->Timing.clockTickH0 *
    ClosedLoopHW_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++ClosedLoopHW_M->Timing.clockTick1)) {
      ++ClosedLoopHW_M->Timing.clockTickH1;
    }

    ClosedLoopHW_M->Timing.t[1] = ClosedLoopHW_M->Timing.clockTick1 *
      ClosedLoopHW_M->Timing.stepSize1 + ClosedLoopHW_M->Timing.clockTickH1 *
      ClosedLoopHW_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void ClosedLoopHW_initialize(void)
{
  {
    b_dspcodegen_FIRFilter_Closed_T *iobj_0;
    int32_T i;
    static const real_T tmp[86] = { -9.3648823352870375E-5,
      -0.00013202995977890097, -0.0002190115309195932, -0.000337457500570388,
      -0.00049219939901641791, -0.00068720118841426121, -0.00092505352308246754,
      -0.0012064215669484425, -0.0015295106502653092, -0.0018895798478461919,
      -0.0022784468383649642, -0.0026841124436411149, -0.003090461469910993,
      -0.0034773420996495634, -0.0038205375280560214, -0.0040922686862605844,
      -0.0042616192923135149, -0.0042953963894558226, -0.0041591637273872949,
      -0.0038184329045463502, -0.0032400686895812866, -0.0023937289431901886,
      -0.0012533738719836707, 0.00020113657996385746, 0.0019825984191955896,
      0.0040953570015105677, 0.00653413743805201, 0.009283308624156739,
      0.012316475978105944, 0.015596610293449727, 0.019076363274306542,
      0.022698846497343626, 0.026399061753891222, 0.030105571351810356,
      0.033742227274575071, 0.037230604700763628, 0.040492593606369753,
      0.043452399947881026, 0.046039706077112948, 0.048191466249000892,
      0.049854515175384619, 0.050987155259482483, 0.051560760909388367,
      0.051560760909388367, 0.050987155259482483, 0.049854515175384619,
      0.048191466249000892, 0.046039706077112948, 0.043452399947881026,
      0.040492593606369753, 0.037230604700763628, 0.033742227274575071,
      0.030105571351810356, 0.026399061753891222, 0.022698846497343626,
      0.019076363274306542, 0.015596610293449727, 0.012316475978105944,
      0.009283308624156739, 0.00653413743805201, 0.0040953570015105677,
      0.0019825984191955896, 0.00020113657996385746, -0.0012533738719836707,
      -0.0023937289431901886, -0.0032400686895812866, -0.0038184329045463502,
      -0.0041591637273872949, -0.0042953963894558226, -0.0042616192923135149,
      -0.0040922686862605844, -0.0038205375280560214, -0.0034773420996495634,
      -0.003090461469910993, -0.0026841124436411149, -0.0022784468383649642,
      -0.0018895798478461919, -0.0015295106502653092, -0.0012064215669484425,
      -0.00092505352308246754, -0.00068720118841426121, -0.00049219939901641791,
      -0.000337457500570388, -0.0002190115309195932, -0.00013202995977890097,
      -9.3648823352870375E-5 };

    /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

    /* S-Function Block: ClosedLoopHW/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("q4", "0", &ClosedLoopHW_DW.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
        return;
      }

      is_switching = false;
      if ((ClosedLoopHW_P.HILInitialize_CKPStart && !is_switching) ||
          (ClosedLoopHW_P.HILInitialize_CKPEnter && is_switching)) {
        result = hil_set_clock_mode(ClosedLoopHW_DW.HILInitialize_Card, (t_clock
          *) ClosedLoopHW_P.HILInitialize_CKChannels, 2U, (t_clock_mode *)
          ClosedLoopHW_P.HILInitialize_CKModes);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }
      }

      result = hil_watchdog_clear(ClosedLoopHW_DW.HILInitialize_Card);
      if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
        return;
      }

      if ((ClosedLoopHW_P.HILInitialize_AIPStart && !is_switching) ||
          (ClosedLoopHW_P.HILInitialize_AIPEnter && is_switching)) {
        ClosedLoopHW_DW.HILInitialize_AIMinimums[0] =
          (ClosedLoopHW_P.HILInitialize_AILow);
        ClosedLoopHW_DW.HILInitialize_AIMinimums[1] =
          (ClosedLoopHW_P.HILInitialize_AILow);
        ClosedLoopHW_DW.HILInitialize_AIMinimums[2] =
          (ClosedLoopHW_P.HILInitialize_AILow);
        ClosedLoopHW_DW.HILInitialize_AIMinimums[3] =
          (ClosedLoopHW_P.HILInitialize_AILow);
        ClosedLoopHW_DW.HILInitialize_AIMaximums[0] =
          ClosedLoopHW_P.HILInitialize_AIHigh;
        ClosedLoopHW_DW.HILInitialize_AIMaximums[1] =
          ClosedLoopHW_P.HILInitialize_AIHigh;
        ClosedLoopHW_DW.HILInitialize_AIMaximums[2] =
          ClosedLoopHW_P.HILInitialize_AIHigh;
        ClosedLoopHW_DW.HILInitialize_AIMaximums[3] =
          ClosedLoopHW_P.HILInitialize_AIHigh;
        result = hil_set_analog_input_ranges(ClosedLoopHW_DW.HILInitialize_Card,
          ClosedLoopHW_P.HILInitialize_AIChannels, 4U,
          &ClosedLoopHW_DW.HILInitialize_AIMinimums[0],
          &ClosedLoopHW_DW.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }
      }

      if ((ClosedLoopHW_P.HILInitialize_AOPStart && !is_switching) ||
          (ClosedLoopHW_P.HILInitialize_AOPEnter && is_switching)) {
        ClosedLoopHW_DW.HILInitialize_AOMinimums[0] =
          (ClosedLoopHW_P.HILInitialize_AOLow);
        ClosedLoopHW_DW.HILInitialize_AOMinimums[1] =
          (ClosedLoopHW_P.HILInitialize_AOLow);
        ClosedLoopHW_DW.HILInitialize_AOMinimums[2] =
          (ClosedLoopHW_P.HILInitialize_AOLow);
        ClosedLoopHW_DW.HILInitialize_AOMinimums[3] =
          (ClosedLoopHW_P.HILInitialize_AOLow);
        ClosedLoopHW_DW.HILInitialize_AOMaximums[0] =
          ClosedLoopHW_P.HILInitialize_AOHigh;
        ClosedLoopHW_DW.HILInitialize_AOMaximums[1] =
          ClosedLoopHW_P.HILInitialize_AOHigh;
        ClosedLoopHW_DW.HILInitialize_AOMaximums[2] =
          ClosedLoopHW_P.HILInitialize_AOHigh;
        ClosedLoopHW_DW.HILInitialize_AOMaximums[3] =
          ClosedLoopHW_P.HILInitialize_AOHigh;
        result = hil_set_analog_output_ranges(ClosedLoopHW_DW.HILInitialize_Card,
          ClosedLoopHW_P.HILInitialize_AOChannels, 4U,
          &ClosedLoopHW_DW.HILInitialize_AOMinimums[0],
          &ClosedLoopHW_DW.HILInitialize_AOMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }
      }

      if ((ClosedLoopHW_P.HILInitialize_AOStart && !is_switching) ||
          (ClosedLoopHW_P.HILInitialize_AOEnter && is_switching)) {
        ClosedLoopHW_DW.HILInitialize_AOVoltages[0] =
          ClosedLoopHW_P.HILInitialize_AOInitial;
        ClosedLoopHW_DW.HILInitialize_AOVoltages[1] =
          ClosedLoopHW_P.HILInitialize_AOInitial;
        ClosedLoopHW_DW.HILInitialize_AOVoltages[2] =
          ClosedLoopHW_P.HILInitialize_AOInitial;
        ClosedLoopHW_DW.HILInitialize_AOVoltages[3] =
          ClosedLoopHW_P.HILInitialize_AOInitial;
        result = hil_write_analog(ClosedLoopHW_DW.HILInitialize_Card,
          ClosedLoopHW_P.HILInitialize_AOChannels, 4U,
          &ClosedLoopHW_DW.HILInitialize_AOVoltages[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }
      }

      if (ClosedLoopHW_P.HILInitialize_AOReset) {
        ClosedLoopHW_DW.HILInitialize_AOVoltages[0] =
          ClosedLoopHW_P.HILInitialize_AOWatchdog;
        ClosedLoopHW_DW.HILInitialize_AOVoltages[1] =
          ClosedLoopHW_P.HILInitialize_AOWatchdog;
        ClosedLoopHW_DW.HILInitialize_AOVoltages[2] =
          ClosedLoopHW_P.HILInitialize_AOWatchdog;
        ClosedLoopHW_DW.HILInitialize_AOVoltages[3] =
          ClosedLoopHW_P.HILInitialize_AOWatchdog;
        result = hil_watchdog_set_analog_expiration_state
          (ClosedLoopHW_DW.HILInitialize_Card,
           ClosedLoopHW_P.HILInitialize_AOChannels, 4U,
           &ClosedLoopHW_DW.HILInitialize_AOVoltages[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }
      }

      if ((ClosedLoopHW_P.HILInitialize_EIPStart && !is_switching) ||
          (ClosedLoopHW_P.HILInitialize_EIPEnter && is_switching)) {
        ClosedLoopHW_DW.HILInitialize_QuadratureModes[0] =
          ClosedLoopHW_P.HILInitialize_EIQuadrature;
        ClosedLoopHW_DW.HILInitialize_QuadratureModes[1] =
          ClosedLoopHW_P.HILInitialize_EIQuadrature;
        ClosedLoopHW_DW.HILInitialize_QuadratureModes[2] =
          ClosedLoopHW_P.HILInitialize_EIQuadrature;
        ClosedLoopHW_DW.HILInitialize_QuadratureModes[3] =
          ClosedLoopHW_P.HILInitialize_EIQuadrature;
        result = hil_set_encoder_quadrature_mode
          (ClosedLoopHW_DW.HILInitialize_Card,
           ClosedLoopHW_P.HILInitialize_EIChannels, 4U,
           (t_encoder_quadrature_mode *)
           &ClosedLoopHW_DW.HILInitialize_QuadratureModes[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }

        ClosedLoopHW_DW.HILInitialize_FilterFrequency[0] =
          ClosedLoopHW_P.HILInitialize_EIFrequency;
        ClosedLoopHW_DW.HILInitialize_FilterFrequency[1] =
          ClosedLoopHW_P.HILInitialize_EIFrequency;
        ClosedLoopHW_DW.HILInitialize_FilterFrequency[2] =
          ClosedLoopHW_P.HILInitialize_EIFrequency;
        ClosedLoopHW_DW.HILInitialize_FilterFrequency[3] =
          ClosedLoopHW_P.HILInitialize_EIFrequency;
        result = hil_set_encoder_filter_frequency
          (ClosedLoopHW_DW.HILInitialize_Card,
           ClosedLoopHW_P.HILInitialize_EIChannels, 4U,
           &ClosedLoopHW_DW.HILInitialize_FilterFrequency[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }
      }

      if ((ClosedLoopHW_P.HILInitialize_EIStart && !is_switching) ||
          (ClosedLoopHW_P.HILInitialize_EIEnter && is_switching)) {
        ClosedLoopHW_DW.HILInitialize_InitialEICounts[0] =
          ClosedLoopHW_P.HILInitialize_EIInitial;
        ClosedLoopHW_DW.HILInitialize_InitialEICounts[1] =
          ClosedLoopHW_P.HILInitialize_EIInitial;
        ClosedLoopHW_DW.HILInitialize_InitialEICounts[2] =
          ClosedLoopHW_P.HILInitialize_EIInitial;
        ClosedLoopHW_DW.HILInitialize_InitialEICounts[3] =
          ClosedLoopHW_P.HILInitialize_EIInitial;
        result = hil_set_encoder_counts(ClosedLoopHW_DW.HILInitialize_Card,
          ClosedLoopHW_P.HILInitialize_EIChannels, 4U,
          &ClosedLoopHW_DW.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
          return;
        }
      }
    }

    /* Start for MATLABSystem: '<Root>/Lowpass Filter' */
    ClosedLoopHW_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    ClosedLoopHW_DW.obj.NumChannels = -1;
    ClosedLoopHW_DW.obj.matlabCodegenIsDeleted = false;
    ClosedLoopHW_DW.objisempty = true;
    ClosedLoopHW_DW.obj.isInitialized = 1;
    if (ClosedLoopHW_DW.obj.NumChannels == -1) {
      ClosedLoopHW_DW.obj.NumChannels = 1;
    }

    iobj_0 = &ClosedLoopHW_DW.obj._pobj0;
    iobj_0->isInitialized = 0;
    iobj_0->isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 86; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    ClosedLoopHW_DW.obj.FilterObj = iobj_0;
    ClosedLoopHW_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter' */
  }

  {
    b_dspcodegen_FIRFilter_Closed_T *obj;
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    ClosedLoopHW_DW.Delay_DSTATE[0] = ClosedLoopHW_P.x0[0];
    ClosedLoopHW_DW.Delay_DSTATE[1] = ClosedLoopHW_P.x0[1];
    ClosedLoopHW_DW.Delay_DSTATE[2] = ClosedLoopHW_P.x0[2];
    ClosedLoopHW_DW.Delay_DSTATE[3] = ClosedLoopHW_P.x0[3];

    /* InitializeConditions for UnitDelay: '<S1>/UD' */
    ClosedLoopHW_DW.UD_DSTATE[0] = ClosedLoopHW_P.x0[0] / 0.001;
    ClosedLoopHW_DW.UD_DSTATE[1] = ClosedLoopHW_P.x0[1] / 0.001;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    ClosedLoopHW_DW.icLoad = true;

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    ClosedLoopHW_DW.sfEvent = ClosedLoopHW_CALL_EVENT;
    ClosedLoopHW_DW.is_active_c2_ClosedLoopHW = 0U;

    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function' */
    ClosedLoopHW_DW.sfEvent_k = ClosedLoopHW_CALL_EVENT;
    ClosedLoopHW_DW.is_active_c3_ClosedLoopHW = 0U;

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
    obj = ClosedLoopHW_DW.obj.FilterObj;
    if (obj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 85; i++) {
        obj->cSFunObject.W0_states[i] = obj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
  }
}

/* Model terminate function */
void ClosedLoopHW_terminate(void)
{
  b_dspcodegen_FIRFilter_Closed_T *obj;

  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: ClosedLoopHW/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(ClosedLoopHW_DW.HILInitialize_Card);
    hil_monitor_stop_all(ClosedLoopHW_DW.HILInitialize_Card);
    is_switching = false;
    if ((ClosedLoopHW_P.HILInitialize_AOTerminate && !is_switching) ||
        (ClosedLoopHW_P.HILInitialize_AOExit && is_switching)) {
      ClosedLoopHW_DW.HILInitialize_AOVoltages[0] =
        ClosedLoopHW_P.HILInitialize_AOFinal;
      ClosedLoopHW_DW.HILInitialize_AOVoltages[1] =
        ClosedLoopHW_P.HILInitialize_AOFinal;
      ClosedLoopHW_DW.HILInitialize_AOVoltages[2] =
        ClosedLoopHW_P.HILInitialize_AOFinal;
      ClosedLoopHW_DW.HILInitialize_AOVoltages[3] =
        ClosedLoopHW_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 4U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(ClosedLoopHW_DW.HILInitialize_Card,
        ClosedLoopHW_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &ClosedLoopHW_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
      }
    }

    hil_task_delete_all(ClosedLoopHW_DW.HILInitialize_Card);
    hil_monitor_delete_all(ClosedLoopHW_DW.HILInitialize_Card);
    hil_close(ClosedLoopHW_DW.HILInitialize_Card);
    ClosedLoopHW_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  if (!ClosedLoopHW_DW.obj.matlabCodegenIsDeleted) {
    ClosedLoopHW_DW.obj.matlabCodegenIsDeleted = true;
    if ((ClosedLoopHW_DW.obj.isInitialized == 1) &&
        ClosedLoopHW_DW.obj.isSetupComplete) {
      obj = ClosedLoopHW_DW.obj.FilterObj;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      ClosedLoopHW_DW.obj.NumChannels = -1;
    }
  }

  obj = &ClosedLoopHW_DW.obj._pobj0;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ClosedLoopHW_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ClosedLoopHW_update();
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
  ClosedLoopHW_initialize();
}

void MdlTerminate(void)
{
  ClosedLoopHW_terminate();
}

/* Registration function */
RT_MODEL_ClosedLoopHW_T *ClosedLoopHW(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ClosedLoopHW_M, 0,
                sizeof(RT_MODEL_ClosedLoopHW_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ClosedLoopHW_M->solverInfo,
                          &ClosedLoopHW_M->Timing.simTimeStep);
    rtsiSetTPtr(&ClosedLoopHW_M->solverInfo, &rtmGetTPtr(ClosedLoopHW_M));
    rtsiSetStepSizePtr(&ClosedLoopHW_M->solverInfo,
                       &ClosedLoopHW_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ClosedLoopHW_M->solverInfo, (&rtmGetErrorStatus
      (ClosedLoopHW_M)));
    rtsiSetRTModelPtr(&ClosedLoopHW_M->solverInfo, ClosedLoopHW_M);
  }

  rtsiSetSimTimeStep(&ClosedLoopHW_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ClosedLoopHW_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ClosedLoopHW_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "ClosedLoopHW_M points to
       static memory which is guaranteed to be non-NULL" */
    ClosedLoopHW_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ClosedLoopHW_M->Timing.sampleTimes =
      (&ClosedLoopHW_M->Timing.sampleTimesArray[0]);
    ClosedLoopHW_M->Timing.offsetTimes =
      (&ClosedLoopHW_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ClosedLoopHW_M->Timing.sampleTimes[0] = (0.0);
    ClosedLoopHW_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    ClosedLoopHW_M->Timing.offsetTimes[0] = (0.0);
    ClosedLoopHW_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ClosedLoopHW_M, &ClosedLoopHW_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ClosedLoopHW_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ClosedLoopHW_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ClosedLoopHW_M, 30.0);
  ClosedLoopHW_M->Timing.stepSize0 = 0.001;
  ClosedLoopHW_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  ClosedLoopHW_M->Sizes.checksums[0] = (2062547860U);
  ClosedLoopHW_M->Sizes.checksums[1] = (211137538U);
  ClosedLoopHW_M->Sizes.checksums[2] = (3211193813U);
  ClosedLoopHW_M->Sizes.checksums[3] = (140345290U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    ClosedLoopHW_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ClosedLoopHW_M->extModeInfo,
      &ClosedLoopHW_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ClosedLoopHW_M->extModeInfo,
                        ClosedLoopHW_M->Sizes.checksums);
    rteiSetTPtr(ClosedLoopHW_M->extModeInfo, rtmGetTPtr(ClosedLoopHW_M));
  }

  ClosedLoopHW_M->solverInfoPtr = (&ClosedLoopHW_M->solverInfo);
  ClosedLoopHW_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&ClosedLoopHW_M->solverInfo, 0.001);
  rtsiSetSolverMode(&ClosedLoopHW_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ClosedLoopHW_M->blockIO = ((void *) &ClosedLoopHW_B);
  (void) memset(((void *) &ClosedLoopHW_B), 0,
                sizeof(B_ClosedLoopHW_T));

  /* parameters */
  ClosedLoopHW_M->defaultParam = ((real_T *)&ClosedLoopHW_P);

  /* states (dwork) */
  ClosedLoopHW_M->dwork = ((void *) &ClosedLoopHW_DW);
  (void) memset((void *)&ClosedLoopHW_DW, 0,
                sizeof(DW_ClosedLoopHW_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ClosedLoopHW_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ClosedLoopHW_M->Sizes.numContStates = (0);/* Number of continuous states */
  ClosedLoopHW_M->Sizes.numY = (0);    /* Number of model outputs */
  ClosedLoopHW_M->Sizes.numU = (0);    /* Number of model inputs */
  ClosedLoopHW_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ClosedLoopHW_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ClosedLoopHW_M->Sizes.numBlocks = (41);/* Number of blocks */
  ClosedLoopHW_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  ClosedLoopHW_M->Sizes.numBlockPrms = (101);/* Sum of parameter "widths" */
  return ClosedLoopHW_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
