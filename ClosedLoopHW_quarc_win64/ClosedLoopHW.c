/*
 * ClosedLoopHW.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ClosedLoopHW".
 *
 * Model version              : 1.17
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Dec  3 14:00:40 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ClosedLoopHW.h"
#include "rtwtypes.h"
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include "ClosedLoopHW_private.h"
#include <string.h>
#include "ClosedLoopHW_dt.h"

/* Named constants for MATLAB Function: '<S54>/SqrtUsedFcn' */
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
  __m128d tmp;
  real_T rtb_Subtract[4];
  real_T rtb_Subtract_0[4];
  real_T rtb_Integrator[2];
  real_T K_idx_0;
  real_T K_idx_1;
  real_T MemoryX_DSTATE;
  real_T MemoryX_DSTATE_0;
  real_T MemoryX_DSTATE_1;
  real_T rtb_Max;
  int32_T i;

  /* Reset subsysRan breadcrumbs */
  srClearBC(ClosedLoopHW_DW.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ClosedLoopHW_DW.EnabledSubsystem_SubsysRanBC);

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
      rtb_Integrator[0] = ClosedLoopHW_DW.HILReadEncoder_Buffer[0];
      rtb_Integrator[1] = ClosedLoopHW_DW.HILReadEncoder_Buffer[1];
    }
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  ClosedLoopHW_B.Add = ClosedLoopHW_P.Gain_Gain * rtb_Integrator[0] +
    ClosedLoopHW_P.Constant_Value_o;

  /* Gain: '<Root>/Gain1' */
  ClosedLoopHW_B.Gain1 = ClosedLoopHW_P.Gain1_Gain * rtb_Integrator[1];

  /* Logic: '<S59>/Logical Operator' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S59>/Time constant'
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  RelationalOperator: '<S62>/Compare'
   *  RelationalOperator: '<S63>/Compare'
   *  Sum: '<S59>/Sum1'
   */
  ClosedLoopHW_B.LogicalOperator =
    ((ClosedLoopHW_P.LowPassFilterDiscreteorContin_k - ClosedLoopHW_B.Probe[0] <=
      ClosedLoopHW_P.Constant_Value) &&
     (ClosedLoopHW_P.LowPassFilterDiscreteorContin_l <
      ClosedLoopHW_P.CompareToConstant_const));

  /* SignalConversion generated from: '<Root>/To Workspace' */
  ClosedLoopHW_B.y[0] = ClosedLoopHW_B.Add;
  ClosedLoopHW_B.y[1] = ClosedLoopHW_B.Gain1;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  K_idx_1 = ClosedLoopHW_B.y[0] * ClosedLoopHW_P.TSamp_WtEt;
  ClosedLoopHW_B.TSamp[0] = K_idx_1;

  /* Gain: '<S3>/K' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  K_idx_0 = (K_idx_1 - ClosedLoopHW_DW.UD_DSTATE[0]) *
    ClosedLoopHW_P.LowPassFilterDiscreteorContinuo;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  K_idx_1 = ClosedLoopHW_B.y[1] * ClosedLoopHW_P.TSamp_WtEt;
  ClosedLoopHW_B.TSamp[1] = K_idx_1;

  /* Gain: '<S3>/K' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  K_idx_1 = (K_idx_1 - ClosedLoopHW_DW.UD_DSTATE[1]) *
    ClosedLoopHW_P.LowPassFilterDiscreteorContinuo;

  /* DiscreteIntegrator: '<S65>/Integrator' */
  if (ClosedLoopHW_DW.Integrator_IC_LOADING != 0) {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = K_idx_0;
    if (K_idx_0 >= ClosedLoopHW_P.Integrator_UpperSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_UpperSat;
    } else if (K_idx_0 <= ClosedLoopHW_P.Integrator_LowerSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_LowerSat;
    }

    ClosedLoopHW_DW.Integrator_DSTATE[1] = K_idx_1;
    if (K_idx_1 >= ClosedLoopHW_P.Integrator_UpperSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_UpperSat;
    } else if (K_idx_1 <= ClosedLoopHW_P.Integrator_LowerSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_LowerSat;
    }
  }

  if (ClosedLoopHW_B.LogicalOperator ||
      (ClosedLoopHW_DW.Integrator_PrevResetState != 0)) {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = K_idx_0;
    if (K_idx_0 >= ClosedLoopHW_P.Integrator_UpperSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_UpperSat;
    } else if (K_idx_0 <= ClosedLoopHW_P.Integrator_LowerSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_LowerSat;
    }

    ClosedLoopHW_DW.Integrator_DSTATE[1] = K_idx_1;
    if (K_idx_1 >= ClosedLoopHW_P.Integrator_UpperSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_UpperSat;
    } else if (K_idx_1 <= ClosedLoopHW_P.Integrator_LowerSat) {
      ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_LowerSat;
    }
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Subtract[0] = ClosedLoopHW_B.Add - ClosedLoopHW_P.c.x_star[0];
  rtb_Subtract[1] = ClosedLoopHW_B.Gain1 - ClosedLoopHW_P.c.x_star[1];

  /* DiscreteIntegrator: '<S65>/Integrator' */
  rtb_Max = ClosedLoopHW_DW.Integrator_DSTATE[0];
  if (ClosedLoopHW_DW.Integrator_DSTATE[0] >= ClosedLoopHW_P.Integrator_UpperSat)
  {
    rtb_Max = ClosedLoopHW_P.Integrator_UpperSat;
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_UpperSat;
  } else if (ClosedLoopHW_DW.Integrator_DSTATE[0] <=
             ClosedLoopHW_P.Integrator_LowerSat) {
    rtb_Max = ClosedLoopHW_P.Integrator_LowerSat;
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_LowerSat;
  }

  /* Saturate: '<S65>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S65>/Integrator'
   */
  if (rtb_Max > ClosedLoopHW_P.Saturation_UpperSat) {
    /* Saturate: '<S65>/Saturation' */
    ClosedLoopHW_B.Saturation[0] = ClosedLoopHW_P.Saturation_UpperSat;
  } else if (rtb_Max < ClosedLoopHW_P.Saturation_LowerSat) {
    /* Saturate: '<S65>/Saturation' */
    ClosedLoopHW_B.Saturation[0] = ClosedLoopHW_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S65>/Saturation' */
    ClosedLoopHW_B.Saturation[0] = rtb_Max;
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Subtract[2] = ClosedLoopHW_B.Saturation[0] - ClosedLoopHW_P.c.x_star[2];

  /* DiscreteIntegrator: '<S65>/Integrator' */
  rtb_Max = ClosedLoopHW_DW.Integrator_DSTATE[1];
  if (ClosedLoopHW_DW.Integrator_DSTATE[1] >= ClosedLoopHW_P.Integrator_UpperSat)
  {
    rtb_Max = ClosedLoopHW_P.Integrator_UpperSat;
    ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_UpperSat;
  } else if (ClosedLoopHW_DW.Integrator_DSTATE[1] <=
             ClosedLoopHW_P.Integrator_LowerSat) {
    rtb_Max = ClosedLoopHW_P.Integrator_LowerSat;
    ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_LowerSat;
  }

  /* Saturate: '<S65>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S65>/Integrator'
   */
  if (rtb_Max > ClosedLoopHW_P.Saturation_UpperSat) {
    /* Saturate: '<S65>/Saturation' */
    ClosedLoopHW_B.Saturation[1] = ClosedLoopHW_P.Saturation_UpperSat;
  } else if (rtb_Max < ClosedLoopHW_P.Saturation_LowerSat) {
    /* Saturate: '<S65>/Saturation' */
    ClosedLoopHW_B.Saturation[1] = ClosedLoopHW_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S65>/Saturation' */
    ClosedLoopHW_B.Saturation[1] = rtb_Max;
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Subtract[3] = ClosedLoopHW_B.Saturation[1] - ClosedLoopHW_P.c.x_star[3];

  /* Delay: '<S2>/MemoryX' incorporates:
   *  Constant: '<S2>/X0'
   */
  if (ClosedLoopHW_DW.icLoad) {
    ClosedLoopHW_DW.MemoryX_DSTATE[0] = ClosedLoopHW_P.X0_Value[0];
    ClosedLoopHW_DW.MemoryX_DSTATE[1] = ClosedLoopHW_P.X0_Value[1];
    ClosedLoopHW_DW.MemoryX_DSTATE[2] = ClosedLoopHW_P.X0_Value[2];
    ClosedLoopHW_DW.MemoryX_DSTATE[3] = ClosedLoopHW_P.X0_Value[3];
  }

  /* Outputs for Enabled SubSystem: '<S32>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  /* Constant: '<S2>/Enable' */
  if (ClosedLoopHW_P.Enable_Value) {
    ClosedLoopHW_DW.EnabledSubsystem_MODE = true;

    /* Delay: '<S2>/MemoryX' incorporates:
     *  Constant: '<S2>/C'
     *  Product: '<S58>/Product'
     */
    rtb_Max = ClosedLoopHW_DW.MemoryX_DSTATE[1];
    MemoryX_DSTATE = ClosedLoopHW_DW.MemoryX_DSTATE[0];
    MemoryX_DSTATE_0 = ClosedLoopHW_DW.MemoryX_DSTATE[2];
    MemoryX_DSTATE_1 = ClosedLoopHW_DW.MemoryX_DSTATE[3];
    for (i = 0; i <= 2; i += 2) {
      /* Sum: '<S58>/Add1' incorporates:
       *  Constant: '<S2>/C'
       *  Delay: '<S2>/MemoryX'
       *  Product: '<S58>/Product'
       */
      tmp = _mm_loadu_pd(&rtb_Subtract[i]);
      _mm_storeu_pd(&rtb_Subtract_0[i], _mm_sub_pd(tmp, _mm_add_pd(_mm_add_pd
        (_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.C_Value[i + 4]),
        _mm_set1_pd(rtb_Max)), _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.C_Value[i]),
        _mm_set1_pd(MemoryX_DSTATE))), _mm_mul_pd(_mm_loadu_pd
        (&ClosedLoopHW_P.C_Value[i + 8]), _mm_set1_pd(MemoryX_DSTATE_0))),
        _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.C_Value[i + 12]), _mm_set1_pd
                   (MemoryX_DSTATE_1)))));
    }

    /* Product: '<S58>/Product2' incorporates:
     *  Constant: '<S5>/KalmanGainM'
     */
    rtb_Max = rtb_Subtract_0[1];
    MemoryX_DSTATE = rtb_Subtract_0[0];
    MemoryX_DSTATE_0 = rtb_Subtract_0[2];
    MemoryX_DSTATE_1 = rtb_Subtract_0[3];
    for (i = 0; i <= 2; i += 2) {
      /* Product: '<S58>/Product2' incorporates:
       *  Constant: '<S5>/KalmanGainM'
       */
      _mm_storeu_pd(&ClosedLoopHW_B.Product2[i], _mm_add_pd(_mm_add_pd
        (_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.KalmanGainM_Value[i
        + 4]), _mm_set1_pd(rtb_Max)), _mm_mul_pd(_mm_loadu_pd
        (&ClosedLoopHW_P.KalmanGainM_Value[i]), _mm_set1_pd(MemoryX_DSTATE))),
         _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.KalmanGainM_Value[i + 8]),
                    _mm_set1_pd(MemoryX_DSTATE_0))), _mm_mul_pd(_mm_loadu_pd
        (&ClosedLoopHW_P.KalmanGainM_Value[i + 12]), _mm_set1_pd
        (MemoryX_DSTATE_1))));
    }

    srUpdateBC(ClosedLoopHW_DW.EnabledSubsystem_SubsysRanBC);
  } else if (ClosedLoopHW_DW.EnabledSubsystem_MODE) {
    /* Disable for Product: '<S58>/Product2' incorporates:
     *  Outport: '<S58>/deltax'
     */
    ClosedLoopHW_B.Product2[0] = ClosedLoopHW_P.deltax_Y0;
    ClosedLoopHW_B.Product2[1] = ClosedLoopHW_P.deltax_Y0;
    ClosedLoopHW_B.Product2[2] = ClosedLoopHW_P.deltax_Y0;
    ClosedLoopHW_B.Product2[3] = ClosedLoopHW_P.deltax_Y0;
    ClosedLoopHW_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S32>/Enabled Subsystem' */

  /* MATLAB Function: '<S4>/MATLAB Function' */
  ClosedLoopHW_DW.sfEvent = ClosedLoopHW_CALL_EVENT;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<S2>/MemoryX'
   *  Sum: '<S32>/Add'
   */
  rtb_Max = (ClosedLoopHW_B.Product2[0] + ClosedLoopHW_DW.MemoryX_DSTATE[0]) +
    ClosedLoopHW_P.c.x_star[0];
  ClosedLoopHW_B.Sum[0] = rtb_Max;

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum'
   */
  MemoryX_DSTATE = (rtb_Max - ClosedLoopHW_P.c.x_star[0]) * -ClosedLoopHW_P.c.K
    [0];

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<S2>/MemoryX'
   *  Sum: '<S32>/Add'
   */
  rtb_Max = (ClosedLoopHW_B.Product2[1] + ClosedLoopHW_DW.MemoryX_DSTATE[1]) +
    ClosedLoopHW_P.c.x_star[1];
  ClosedLoopHW_B.Sum[1] = rtb_Max;

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum'
   */
  MemoryX_DSTATE += (rtb_Max - ClosedLoopHW_P.c.x_star[1]) *
    -ClosedLoopHW_P.c.K[1];

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<S2>/MemoryX'
   *  Sum: '<S32>/Add'
   */
  rtb_Max = (ClosedLoopHW_B.Product2[2] + ClosedLoopHW_DW.MemoryX_DSTATE[2]) +
    ClosedLoopHW_P.c.x_star[2];
  ClosedLoopHW_B.Sum[2] = rtb_Max;

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum'
   */
  MemoryX_DSTATE += (rtb_Max - ClosedLoopHW_P.c.x_star[2]) *
    -ClosedLoopHW_P.c.K[2];

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Delay: '<S2>/MemoryX'
   *  Sum: '<S32>/Add'
   */
  rtb_Max = (ClosedLoopHW_B.Product2[3] + ClosedLoopHW_DW.MemoryX_DSTATE[3]) +
    ClosedLoopHW_P.c.x_star[3];
  ClosedLoopHW_B.Sum[3] = rtb_Max;

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Sum'
   */
  ClosedLoopHW_B.u = ((rtb_Max - ClosedLoopHW_P.c.x_star[3]) *
                      -ClosedLoopHW_P.c.K[3] + MemoryX_DSTATE) +
    ClosedLoopHW_P.c.u_star;

  /* Gain: '<Root>/Gain2' */
  rtb_Max = ClosedLoopHW_P.Gain2_Gain * ClosedLoopHW_B.u;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Max > ClosedLoopHW_P.Saturation_UpperSat_g) {
    /* Saturate: '<Root>/Saturation' */
    ClosedLoopHW_B.Saturation_p = ClosedLoopHW_P.Saturation_UpperSat_g;
  } else if (rtb_Max < ClosedLoopHW_P.Saturation_LowerSat_o) {
    /* Saturate: '<Root>/Saturation' */
    ClosedLoopHW_B.Saturation_p = ClosedLoopHW_P.Saturation_LowerSat_o;
  } else {
    /* Saturate: '<Root>/Saturation' */
    ClosedLoopHW_B.Saturation_p = rtb_Max;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: ClosedLoopHW/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(ClosedLoopHW_DW.HILInitialize_Card,
      &ClosedLoopHW_P.HILWriteAnalog_channels, 1, &ClosedLoopHW_B.Saturation_p);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
    }
  }

  /* MATLAB Function: '<S54>/SqrtUsedFcn' */
  ClosedLoopHW_DW.sfEvent_e = ClosedLoopHW_CALL_EVENT;

  /* Outputs for Enabled SubSystem: '<S25>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  /* Constant: '<S2>/Enable' */
  if (ClosedLoopHW_P.Enable_Value) {
    ClosedLoopHW_DW.MeasurementUpdate_MODE = true;

    /* Delay: '<S2>/MemoryX' incorporates:
     *  Constant: '<S2>/C'
     *  Product: '<S56>/C[k]*xhat[k|k-1]'
     */
    rtb_Max = ClosedLoopHW_DW.MemoryX_DSTATE[1];
    MemoryX_DSTATE = ClosedLoopHW_DW.MemoryX_DSTATE[0];
    MemoryX_DSTATE_0 = ClosedLoopHW_DW.MemoryX_DSTATE[2];
    MemoryX_DSTATE_1 = ClosedLoopHW_DW.MemoryX_DSTATE[3];
    for (i = 0; i <= 2; i += 2) {
      /* Sum: '<S56>/Sum' incorporates:
       *  Constant: '<S2>/C'
       *  Constant: '<S2>/D'
       *  Delay: '<S2>/MemoryX'
       *  Product: '<S56>/C[k]*xhat[k|k-1]'
       *  Product: '<S56>/D[k]*u[k]'
       */
      tmp = _mm_loadu_pd(&rtb_Subtract[i]);
      _mm_storeu_pd(&rtb_Subtract_0[i], _mm_sub_pd(tmp, _mm_add_pd(_mm_add_pd
        (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.C_Value[i
        + 4]), _mm_set1_pd(rtb_Max)), _mm_mul_pd(_mm_loadu_pd
        (&ClosedLoopHW_P.C_Value[i]), _mm_set1_pd(MemoryX_DSTATE))), _mm_mul_pd
                    (_mm_loadu_pd(&ClosedLoopHW_P.C_Value[i + 8]), _mm_set1_pd
                     (MemoryX_DSTATE_0))), _mm_mul_pd(_mm_loadu_pd
        (&ClosedLoopHW_P.C_Value[i + 12]), _mm_set1_pd(MemoryX_DSTATE_1))),
        _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.D_Value[i]), _mm_set1_pd
                   (ClosedLoopHW_B.u)))));
    }

    /* Product: '<S56>/Product3' incorporates:
     *  Constant: '<S5>/KalmanGainL'
     */
    rtb_Max = rtb_Subtract_0[1];
    MemoryX_DSTATE = rtb_Subtract_0[0];
    MemoryX_DSTATE_0 = rtb_Subtract_0[2];
    MemoryX_DSTATE_1 = rtb_Subtract_0[3];
    for (i = 0; i <= 2; i += 2) {
      /* Product: '<S56>/Product3' incorporates:
       *  Constant: '<S5>/KalmanGainL'
       */
      _mm_storeu_pd(&ClosedLoopHW_B.Product3[i], _mm_add_pd(_mm_add_pd
        (_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.KalmanGainL_Value[i
        + 4]), _mm_set1_pd(rtb_Max)), _mm_mul_pd(_mm_loadu_pd
        (&ClosedLoopHW_P.KalmanGainL_Value[i]), _mm_set1_pd(MemoryX_DSTATE))),
         _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.KalmanGainL_Value[i + 8]),
                    _mm_set1_pd(MemoryX_DSTATE_0))), _mm_mul_pd(_mm_loadu_pd
        (&ClosedLoopHW_P.KalmanGainL_Value[i + 12]), _mm_set1_pd
        (MemoryX_DSTATE_1))));
    }

    srUpdateBC(ClosedLoopHW_DW.MeasurementUpdate_SubsysRanBC);
  } else if (ClosedLoopHW_DW.MeasurementUpdate_MODE) {
    /* Disable for Product: '<S56>/Product3' incorporates:
     *  Outport: '<S56>/L*(y[k]-yhat[k|k-1])'
     */
    ClosedLoopHW_B.Product3[0] = ClosedLoopHW_P.Lykyhatkk1_Y0;
    ClosedLoopHW_B.Product3[1] = ClosedLoopHW_P.Lykyhatkk1_Y0;
    ClosedLoopHW_B.Product3[2] = ClosedLoopHW_P.Lykyhatkk1_Y0;
    ClosedLoopHW_B.Product3[3] = ClosedLoopHW_P.Lykyhatkk1_Y0;
    ClosedLoopHW_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S25>/MeasurementUpdate' */

  /* Delay: '<S2>/MemoryX' incorporates:
   *  Constant: '<S2>/A'
   *  Product: '<S25>/A[k]*xhat[k|k-1]'
   */
  rtb_Max = ClosedLoopHW_DW.MemoryX_DSTATE[1];
  MemoryX_DSTATE = ClosedLoopHW_DW.MemoryX_DSTATE[0];
  MemoryX_DSTATE_0 = ClosedLoopHW_DW.MemoryX_DSTATE[2];
  MemoryX_DSTATE_1 = ClosedLoopHW_DW.MemoryX_DSTATE[3];
  for (i = 0; i <= 2; i += 2) {
    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S2>/B'
     *  Product: '<S25>/B[k]*u[k]'
     *  Product: '<S56>/Product3'
     */
    tmp = _mm_loadu_pd(&ClosedLoopHW_B.Product3[i]);

    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S2>/A'
     *  Constant: '<S2>/B'
     *  Delay: '<S2>/MemoryX'
     *  Product: '<S25>/A[k]*xhat[k|k-1]'
     *  Product: '<S25>/B[k]*u[k]'
     */
    _mm_storeu_pd(&ClosedLoopHW_B.Add_k[i], _mm_add_pd(_mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.A_Value[i +
      4]), _mm_set1_pd(rtb_Max)), _mm_mul_pd(_mm_loadu_pd
      (&ClosedLoopHW_P.A_Value[i]), _mm_set1_pd(MemoryX_DSTATE))), _mm_mul_pd
                  (_mm_loadu_pd(&ClosedLoopHW_P.A_Value[i + 8]), _mm_set1_pd
                   (MemoryX_DSTATE_0))), _mm_mul_pd(_mm_loadu_pd
      (&ClosedLoopHW_P.A_Value[i + 12]), _mm_set1_pd(MemoryX_DSTATE_1))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.B_Value[i]), _mm_set1_pd
                 (ClosedLoopHW_B.u))), tmp));
  }

  /* MinMax: '<S59>/Max' incorporates:
   *  Constant: '<S59>/Time constant'
   */
  if ((ClosedLoopHW_B.Probe[0] >= ClosedLoopHW_P.LowPassFilterDiscreteorContin_k)
      || rtIsNaN(ClosedLoopHW_P.LowPassFilterDiscreteorContin_k)) {
    rtb_Max = ClosedLoopHW_B.Probe[0];
  } else {
    rtb_Max = ClosedLoopHW_P.LowPassFilterDiscreteorContin_k;
  }

  /* End of MinMax: '<S59>/Max' */

  /* Fcn: '<S59>/Avoid Divide by Zero' */
  rtb_Max += (real_T)(rtb_Max == 0.0) * 2.2204460492503131e-16;

  /* Product: '<S3>/1//T' incorporates:
   *  Sum: '<S3>/Sum1'
   */
  ClosedLoopHW_B.uT[0] = 1.0 / rtb_Max * (K_idx_0 - ClosedLoopHW_B.Saturation[0]);
  ClosedLoopHW_B.uT[1] = 1.0 / rtb_Max * (K_idx_1 - ClosedLoopHW_B.Saturation[1]);

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
  real_T Integrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S65>/Integrator' */
  ClosedLoopHW_DW.Integrator_IC_LOADING = 0U;

  /* Update for UnitDelay: '<S1>/UD' */
  ClosedLoopHW_DW.UD_DSTATE[0] = ClosedLoopHW_B.TSamp[0];

  /* Update for DiscreteIntegrator: '<S65>/Integrator' */
  Integrator_DSTATE = ClosedLoopHW_P.Integrator_gainval * ClosedLoopHW_B.uT[0] +
    ClosedLoopHW_DW.Integrator_DSTATE[0];
  ClosedLoopHW_DW.Integrator_DSTATE[0] = Integrator_DSTATE;
  if (Integrator_DSTATE >= ClosedLoopHW_P.Integrator_UpperSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_UpperSat;
  } else if (Integrator_DSTATE <= ClosedLoopHW_P.Integrator_LowerSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_LowerSat;
  }

  /* Update for UnitDelay: '<S1>/UD' */
  ClosedLoopHW_DW.UD_DSTATE[1] = ClosedLoopHW_B.TSamp[1];

  /* Update for DiscreteIntegrator: '<S65>/Integrator' */
  Integrator_DSTATE = ClosedLoopHW_P.Integrator_gainval * ClosedLoopHW_B.uT[1] +
    ClosedLoopHW_DW.Integrator_DSTATE[1];
  ClosedLoopHW_DW.Integrator_DSTATE[1] = Integrator_DSTATE;
  if (Integrator_DSTATE >= ClosedLoopHW_P.Integrator_UpperSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_UpperSat;
  } else if (Integrator_DSTATE <= ClosedLoopHW_P.Integrator_LowerSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_LowerSat;
  }

  ClosedLoopHW_DW.Integrator_PrevResetState = (int8_T)
    ClosedLoopHW_B.LogicalOperator;

  /* Update for Delay: '<S2>/MemoryX' */
  ClosedLoopHW_DW.icLoad = false;
  ClosedLoopHW_DW.MemoryX_DSTATE[0] = ClosedLoopHW_B.Add_k[0];
  ClosedLoopHW_DW.MemoryX_DSTATE[1] = ClosedLoopHW_B.Add_k[1];
  ClosedLoopHW_DW.MemoryX_DSTATE[2] = ClosedLoopHW_B.Add_k[2];
  ClosedLoopHW_DW.MemoryX_DSTATE[3] = ClosedLoopHW_B.Add_k[3];

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
    result = hil_set_card_specific_options(ClosedLoopHW_DW.HILInitialize_Card,
      " ", 2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(ClosedLoopHW_M, _rt_error_message);
      return;
    }

    if ((ClosedLoopHW_P.HILInitialize_CKPStart && !is_switching) ||
        (ClosedLoopHW_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(ClosedLoopHW_DW.HILInitialize_Card, (t_clock *)
        ClosedLoopHW_P.HILInitialize_CKChannels, 2U, (t_clock_mode *)
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
         ClosedLoopHW_P.HILInitialize_EIChannels, 4U, (t_encoder_quadrature_mode
          *) &ClosedLoopHW_DW.HILInitialize_QuadratureModes[0]);
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

  /* Start for Probe: '<S59>/Probe' */
  ClosedLoopHW_B.Probe[0] = 0.001;
  ClosedLoopHW_B.Probe[1] = 0.0;

  /* Start for Enabled SubSystem: '<S32>/Enabled Subsystem' */
  ClosedLoopHW_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S32>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S25>/MeasurementUpdate' */
  ClosedLoopHW_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S25>/MeasurementUpdate' */

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  ClosedLoopHW_DW.UD_DSTATE[0] = ClosedLoopHW_P.DiscreteDerivative_ICPrevScaled
    [0];
  ClosedLoopHW_DW.UD_DSTATE[1] = ClosedLoopHW_P.DiscreteDerivative_ICPrevScaled
    [1];

  /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator' */
  ClosedLoopHW_DW.Integrator_PrevResetState = 0;
  ClosedLoopHW_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for Delay: '<S2>/MemoryX' */
  ClosedLoopHW_DW.icLoad = true;

  /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function' */
  ClosedLoopHW_DW.sfEvent = ClosedLoopHW_CALL_EVENT;
  ClosedLoopHW_DW.is_active_c2_ClosedLoopHW = 0U;

  /* SystemInitialize for MATLAB Function: '<S54>/SqrtUsedFcn' */
  ClosedLoopHW_DW.sfEvent_e = ClosedLoopHW_CALL_EVENT;
  ClosedLoopHW_DW.is_active_c7_ctrlSharedLib = 0U;

  /* SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S58>/Product2' incorporates:
   *  Outport: '<S58>/deltax'
   */
  ClosedLoopHW_B.Product2[0] = ClosedLoopHW_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S25>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S56>/Product3' incorporates:
   *  Outport: '<S56>/L*(y[k]-yhat[k|k-1])'
   */
  ClosedLoopHW_B.Product3[0] = ClosedLoopHW_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S25>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S58>/Product2' incorporates:
   *  Outport: '<S58>/deltax'
   */
  ClosedLoopHW_B.Product2[1] = ClosedLoopHW_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S25>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S56>/Product3' incorporates:
   *  Outport: '<S56>/L*(y[k]-yhat[k|k-1])'
   */
  ClosedLoopHW_B.Product3[1] = ClosedLoopHW_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S25>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S58>/Product2' incorporates:
   *  Outport: '<S58>/deltax'
   */
  ClosedLoopHW_B.Product2[2] = ClosedLoopHW_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S25>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S56>/Product3' incorporates:
   *  Outport: '<S56>/L*(y[k]-yhat[k|k-1])'
   */
  ClosedLoopHW_B.Product3[2] = ClosedLoopHW_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S25>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S58>/Product2' incorporates:
   *  Outport: '<S58>/deltax'
   */
  ClosedLoopHW_B.Product2[3] = ClosedLoopHW_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S25>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S56>/Product3' incorporates:
   *  Outport: '<S56>/L*(y[k]-yhat[k|k-1])'
   */
  ClosedLoopHW_B.Product3[3] = ClosedLoopHW_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S25>/MeasurementUpdate' */
}

/* Model terminate function */
void ClosedLoopHW_terminate(void)
{
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

  /* non-finite (run-time) assignments */
  ClosedLoopHW_P.Integrator_UpperSat = rtInf;
  ClosedLoopHW_P.Integrator_LowerSat = rtMinusInf;
  ClosedLoopHW_P.Saturation_UpperSat = rtInf;
  ClosedLoopHW_P.Saturation_LowerSat = rtMinusInf;

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
  ClosedLoopHW_M->Sizes.checksums[0] = (4082777471U);
  ClosedLoopHW_M->Sizes.checksums[1] = (1301918820U);
  ClosedLoopHW_M->Sizes.checksums[2] = (2612282779U);
  ClosedLoopHW_M->Sizes.checksums[3] = (2531045437U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    ClosedLoopHW_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&ClosedLoopHW_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&ClosedLoopHW_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 21;
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
  ClosedLoopHW_M->Sizes.numBlocks = (70);/* Number of blocks */
  ClosedLoopHW_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  ClosedLoopHW_M->Sizes.numBlockPrms = (194);/* Sum of parameter "widths" */
  return ClosedLoopHW_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
