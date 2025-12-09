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
 * C source code generated on : Tue Dec  9 14:50:42 2025
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
#include <math.h>
#include "rt_nonfinite.h"
#include "ClosedLoopHW_private.h"
#include <string.h>
#include "ClosedLoopHW_dt.h"

/* Named constants for MATLAB Function: '<S1>/MATLAB Function' */
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
  __m128d tmp_2;
  real_T Delay_DSTATE_m;
  real_T Delay_DSTATE_m_0;
  real_T Delay_DSTATE_m_1;
  real_T K_idx_0;
  real_T K_idx_1;
  real_T rtb_Max;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  int32_T i;

  /* Constant: '<S1>/Constant1' */
  ClosedLoopHW_B.Constant1[0] = ClosedLoopHW_P.x0[0];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_B.x[0] = ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Constant: '<S1>/Constant1' */
  ClosedLoopHW_B.Constant1[1] = ClosedLoopHW_P.x0[1];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_B.x[1] = ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Constant: '<S1>/Constant1' */
  ClosedLoopHW_B.Constant1[2] = ClosedLoopHW_P.x0[2];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_B.x[2] = ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[2];

  /* Constant: '<S1>/Constant1' */
  ClosedLoopHW_B.Constant1[3] = ClosedLoopHW_P.x0[3];

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_B.x[3] = ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[3];

  /* Reshape: '<Root>/Reshape' */
  ClosedLoopHW_B.Reshape[0] = ClosedLoopHW_B.x[0];
  ClosedLoopHW_B.Reshape[1] = ClosedLoopHW_B.x[1];

  /* MATLAB Function: '<S5>/MATLAB Function' */
  ClosedLoopHW_DW.sfEvent = ClosedLoopHW_CALL_EVENT;

  /* Delay: '<Root>/Delay' */
  ClosedLoopHW_B.Delay[0] = ClosedLoopHW_DW.Delay_DSTATE[0];
  ClosedLoopHW_B.Delay[1] = ClosedLoopHW_DW.Delay_DSTATE[1];
  ClosedLoopHW_B.Delay[2] = ClosedLoopHW_DW.Delay_DSTATE[2];
  ClosedLoopHW_B.Delay[3] = ClosedLoopHW_DW.Delay_DSTATE[3];

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Delay: '<Root>/Delay'
   */
  K_idx_0 = ((((ClosedLoopHW_DW.Delay_DSTATE[0] - ClosedLoopHW_P.c.x_star[0]) *
               -ClosedLoopHW_P.c.K[0] + (ClosedLoopHW_DW.Delay_DSTATE[1] -
    ClosedLoopHW_P.c.x_star[1]) * -ClosedLoopHW_P.c.K[1]) +
              (ClosedLoopHW_DW.Delay_DSTATE[2] - ClosedLoopHW_P.c.x_star[2]) *
              -ClosedLoopHW_P.c.K[2]) + (ClosedLoopHW_DW.Delay_DSTATE[3] -
              ClosedLoopHW_P.c.x_star[3]) * -ClosedLoopHW_P.c.K[3]) +
    ClosedLoopHW_P.c.u_star;

  /* Saturate: '<Root>/Saturation1' */
  if (K_idx_0 > ClosedLoopHW_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    ClosedLoopHW_B.Saturation1 = ClosedLoopHW_P.Saturation1_UpperSat;
  } else if (K_idx_0 < ClosedLoopHW_P.Saturation1_LowerSat) {
    /* Saturate: '<Root>/Saturation1' */
    ClosedLoopHW_B.Saturation1 = ClosedLoopHW_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    ClosedLoopHW_B.Saturation1 = K_idx_0;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Time constant'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  Sum: '<S8>/Sum1'
   */
  ClosedLoopHW_B.LogicalOperator =
    ((ClosedLoopHW_P.LowPassFilterDiscreteorContin_n - ClosedLoopHW_B.Probe[0] <=
      ClosedLoopHW_P.Constant_Value) &&
     (ClosedLoopHW_P.LowPassFilterDiscreteorContin_b <
      ClosedLoopHW_P.CompareToConstant_const));

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  K_idx_1 = ClosedLoopHW_B.Reshape[0] * ClosedLoopHW_P.TSamp_WtEt;
  ClosedLoopHW_B.TSamp[0] = K_idx_1;

  /* Gain: '<S4>/K' incorporates:
   *  Sum: '<S2>/Diff'
   *  UnitDelay: '<S2>/UD'
   */
  K_idx_0 = (K_idx_1 - ClosedLoopHW_DW.UD_DSTATE[0]) *
    ClosedLoopHW_P.LowPassFilterDiscreteorContinuo;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  K_idx_1 = ClosedLoopHW_B.Reshape[1] * ClosedLoopHW_P.TSamp_WtEt;
  ClosedLoopHW_B.TSamp[1] = K_idx_1;

  /* Gain: '<S4>/K' incorporates:
   *  Sum: '<S2>/Diff'
   *  UnitDelay: '<S2>/UD'
   */
  K_idx_1 = (K_idx_1 - ClosedLoopHW_DW.UD_DSTATE[1]) *
    ClosedLoopHW_P.LowPassFilterDiscreteorContinuo;

  /* DiscreteIntegrator: '<S14>/Integrator' */
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

  if (ClosedLoopHW_DW.Integrator_DSTATE[0] >= ClosedLoopHW_P.Integrator_UpperSat)
  {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_UpperSat;
  } else if (ClosedLoopHW_DW.Integrator_DSTATE[0] <=
             ClosedLoopHW_P.Integrator_LowerSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_LowerSat;
  }

  /* Saturate: '<S14>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S14>/Integrator'
   */
  if (ClosedLoopHW_DW.Integrator_DSTATE[0] > ClosedLoopHW_P.Saturation_UpperSat)
  {
    /* Saturate: '<S14>/Saturation' */
    ClosedLoopHW_B.Saturation[0] = ClosedLoopHW_P.Saturation_UpperSat;
  } else if (ClosedLoopHW_DW.Integrator_DSTATE[0] <
             ClosedLoopHW_P.Saturation_LowerSat) {
    /* Saturate: '<S14>/Saturation' */
    ClosedLoopHW_B.Saturation[0] = ClosedLoopHW_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S14>/Saturation' */
    ClosedLoopHW_B.Saturation[0] = ClosedLoopHW_DW.Integrator_DSTATE[0];
  }

  /* DiscreteIntegrator: '<S14>/Integrator' */
  if (ClosedLoopHW_DW.Integrator_DSTATE[1] >= ClosedLoopHW_P.Integrator_UpperSat)
  {
    ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_UpperSat;
  } else if (ClosedLoopHW_DW.Integrator_DSTATE[1] <=
             ClosedLoopHW_P.Integrator_LowerSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[1] = ClosedLoopHW_P.Integrator_LowerSat;
  }

  /* Saturate: '<S14>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S14>/Integrator'
   */
  if (ClosedLoopHW_DW.Integrator_DSTATE[1] > ClosedLoopHW_P.Saturation_UpperSat)
  {
    /* Saturate: '<S14>/Saturation' */
    ClosedLoopHW_B.Saturation[1] = ClosedLoopHW_P.Saturation_UpperSat;
  } else if (ClosedLoopHW_DW.Integrator_DSTATE[1] <
             ClosedLoopHW_P.Saturation_LowerSat) {
    /* Saturate: '<S14>/Saturation' */
    ClosedLoopHW_B.Saturation[1] = ClosedLoopHW_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S14>/Saturation' */
    ClosedLoopHW_B.Saturation[1] = ClosedLoopHW_DW.Integrator_DSTATE[1];
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/x_star'
   */
  tmp = ClosedLoopHW_B.Reshape[0] - ClosedLoopHW_P.c.x_star[0];
  rtb_Max = ClosedLoopHW_B.Saturation[0] - ClosedLoopHW_P.c.x_star[2];
  tmp_0 = ClosedLoopHW_B.Reshape[1] - ClosedLoopHW_P.c.x_star[1];
  tmp_1 = ClosedLoopHW_B.Saturation[1] - ClosedLoopHW_P.c.x_star[3];
  for (i = 0; i <= 0; i += 2) {
    /* Gain: '<Root>/Multiply' */
    _mm_storeu_pd(&ClosedLoopHW_B.Multiply[i], _mm_add_pd(_mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[i + 2]), _mm_set1_pd(tmp_0)),
       _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[i]), _mm_set1_pd(tmp))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[i + 4]), _mm_set1_pd(rtb_Max))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.dC[i + 6]), _mm_set1_pd(tmp_1))));
  }

  /* Delay: '<S3>/Delay' incorporates:
   *  Constant: '<S3>/Constant'
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

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Sum: '<S3>/Subtract'
   */
  ClosedLoopHW_DW.sfEvent_k = ClosedLoopHW_CALL_EVENT;
  tmp = ClosedLoopHW_B.Saturation1 - ClosedLoopHW_P.c.u_star;
  tmp_0 = ClosedLoopHW_B.Multiply[0];
  rtb_Max = ClosedLoopHW_B.Multiply[1];

  /* Delay: '<S3>/Delay' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  tmp_1 = ClosedLoopHW_DW.Delay_DSTATE_m[1];
  Delay_DSTATE_m = ClosedLoopHW_DW.Delay_DSTATE_m[0];
  Delay_DSTATE_m_0 = ClosedLoopHW_DW.Delay_DSTATE_m[2];
  Delay_DSTATE_m_1 = ClosedLoopHW_DW.Delay_DSTATE_m[3];
  for (i = 0; i <= 2; i += 2) {
    /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
     *  Delay: '<S3>/Delay'
     */
    tmp_2 = _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
      &ClosedLoopHW_P.est_param.A[i + 4]), _mm_set1_pd(tmp_1)), _mm_mul_pd
      (_mm_loadu_pd(&ClosedLoopHW_P.est_param.A[i]), _mm_set1_pd(Delay_DSTATE_m))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.est_param.A[i + 8]), _mm_set1_pd
                 (Delay_DSTATE_m_0))), _mm_mul_pd(_mm_loadu_pd
      (&ClosedLoopHW_P.est_param.A[i + 12]), _mm_set1_pd(Delay_DSTATE_m_1))),
                       _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&ClosedLoopHW_P.est_param.B[i + 4]), _mm_set1_pd(tmp_0)), _mm_mul_pd
      (_mm_loadu_pd(&ClosedLoopHW_P.est_param.B[i]), _mm_set1_pd(tmp))),
      _mm_mul_pd(_mm_loadu_pd(&ClosedLoopHW_P.est_param.B[i + 8]), _mm_set1_pd
                 (rtb_Max))));
    _mm_storeu_pd(&ClosedLoopHW_B.x_hat[i], tmp_2);

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/x_star'
     *  MATLAB Function: '<S3>/MATLAB Function'
     */
    _mm_storeu_pd(&ClosedLoopHW_B.Sum[i], _mm_add_pd(tmp_2, _mm_loadu_pd
      (&ClosedLoopHW_P.c.x_star[i])));
  }

  /* Reshape: '<Root>/Reshape1' */
  ClosedLoopHW_B.Reshape1[0] = ClosedLoopHW_B.Sum[0];
  ClosedLoopHW_B.Reshape1[1] = ClosedLoopHW_B.Sum[1];
  ClosedLoopHW_B.Reshape1[2] = ClosedLoopHW_B.Sum[2];
  ClosedLoopHW_B.Reshape1[3] = ClosedLoopHW_B.Sum[3];

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  ClosedLoopHW_DW.sfEvent_c = ClosedLoopHW_CALL_EVENT;
  tmp = cos(ClosedLoopHW_B.x[1]);
  tmp_0 = 2.0 * ClosedLoopHW_P.p.T3;
  rtb_Max = tmp_0 * tmp + (ClosedLoopHW_P.p.T1 + ClosedLoopHW_P.p.T2);
  tmp = ClosedLoopHW_P.p.T3 * tmp + ClosedLoopHW_P.p.T2;
  tmp_1 = sin(ClosedLoopHW_B.x[1]);
  Delay_DSTATE_m = ClosedLoopHW_P.p.T5 * ClosedLoopHW_P.p.g * cos
    (ClosedLoopHW_B.x[0] + ClosedLoopHW_B.x[1]);
  ClosedLoopHW_B.dx[0] = ClosedLoopHW_B.x[2];
  ClosedLoopHW_B.dx[1] = ClosedLoopHW_B.x[3];
  tmp_0 = ((-ClosedLoopHW_P.p.T3 * tmp_1 * (ClosedLoopHW_B.x[3] *
             ClosedLoopHW_B.x[3]) - tmp_0 * tmp_1 * ClosedLoopHW_B.x[3] *
            ClosedLoopHW_B.x[2]) + (ClosedLoopHW_P.p.T4 * ClosedLoopHW_P.p.g *
            cos(ClosedLoopHW_B.x[0]) + Delay_DSTATE_m)) -
    ClosedLoopHW_B.Saturation1;
  tmp_1 = ClosedLoopHW_P.p.T3 * tmp_1 * (ClosedLoopHW_B.x[2] * ClosedLoopHW_B.x
    [2]) + Delay_DSTATE_m;
  Delay_DSTATE_m = rtb_Max * ClosedLoopHW_P.p.T2 - tmp * tmp;
  ClosedLoopHW_B.dx[2] = (tmp_1 * tmp - tmp_0 * ClosedLoopHW_P.p.T2) /
    Delay_DSTATE_m;
  ClosedLoopHW_B.dx[3] = (tmp_0 * tmp - tmp_1 * rtb_Max) / Delay_DSTATE_m;

  /* MinMax: '<S8>/Max' incorporates:
   *  Constant: '<S8>/Time constant'
   */
  if ((ClosedLoopHW_B.Probe[0] >= ClosedLoopHW_P.LowPassFilterDiscreteorContin_n)
      || rtIsNaN(ClosedLoopHW_P.LowPassFilterDiscreteorContin_n)) {
    rtb_Max = ClosedLoopHW_B.Probe[0];
  } else {
    rtb_Max = ClosedLoopHW_P.LowPassFilterDiscreteorContin_n;
  }

  /* End of MinMax: '<S8>/Max' */

  /* Fcn: '<S8>/Avoid Divide by Zero' */
  rtb_Max += (real_T)(rtb_Max == 0.0) * 2.2204460492503131e-16;

  /* Product: '<S4>/1//T' incorporates:
   *  Sum: '<S4>/Sum1'
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

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    ClosedLoopHW_P.DiscreteTimeIntegrator_gainval * ClosedLoopHW_B.dx[0];

  /* Update for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[0] = ClosedLoopHW_B.Sum[0];

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    ClosedLoopHW_P.DiscreteTimeIntegrator_gainval * ClosedLoopHW_B.dx[1];

  /* Update for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[1] = ClosedLoopHW_B.Sum[1];

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[2] +=
    ClosedLoopHW_P.DiscreteTimeIntegrator_gainval * ClosedLoopHW_B.dx[2];

  /* Update for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[2] = ClosedLoopHW_B.Sum[2];

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[3] +=
    ClosedLoopHW_P.DiscreteTimeIntegrator_gainval * ClosedLoopHW_B.dx[3];

  /* Update for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[3] = ClosedLoopHW_B.Sum[3];

  /* Update for DiscreteIntegrator: '<S14>/Integrator' */
  ClosedLoopHW_DW.Integrator_IC_LOADING = 0U;

  /* Update for UnitDelay: '<S2>/UD' */
  ClosedLoopHW_DW.UD_DSTATE[0] = ClosedLoopHW_B.TSamp[0];

  /* Update for DiscreteIntegrator: '<S14>/Integrator' */
  Integrator_DSTATE = ClosedLoopHW_P.Integrator_gainval * ClosedLoopHW_B.uT[0] +
    ClosedLoopHW_DW.Integrator_DSTATE[0];
  ClosedLoopHW_DW.Integrator_DSTATE[0] = Integrator_DSTATE;
  if (Integrator_DSTATE >= ClosedLoopHW_P.Integrator_UpperSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_UpperSat;
  } else if (Integrator_DSTATE <= ClosedLoopHW_P.Integrator_LowerSat) {
    ClosedLoopHW_DW.Integrator_DSTATE[0] = ClosedLoopHW_P.Integrator_LowerSat;
  }

  /* Update for UnitDelay: '<S2>/UD' */
  ClosedLoopHW_DW.UD_DSTATE[1] = ClosedLoopHW_B.TSamp[1];

  /* Update for DiscreteIntegrator: '<S14>/Integrator' */
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

  /* Update for Delay: '<S3>/Delay' */
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

  /* Start for Constant: '<S1>/Constant1' */
  ClosedLoopHW_B.Constant1[0] = ClosedLoopHW_P.x0[0];
  ClosedLoopHW_B.Constant1[1] = ClosedLoopHW_P.x0[1];
  ClosedLoopHW_B.Constant1[2] = ClosedLoopHW_P.x0[2];
  ClosedLoopHW_B.Constant1[3] = ClosedLoopHW_P.x0[3];

  /* Start for Probe: '<S8>/Probe' */
  ClosedLoopHW_B.Probe[0] = 0.001;
  ClosedLoopHW_B.Probe[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[0] = ClosedLoopHW_B.Constant1[0];

  /* InitializeConditions for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[0] = ClosedLoopHW_P.x0[0];

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[1] = ClosedLoopHW_B.Constant1[1];

  /* InitializeConditions for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[1] = ClosedLoopHW_P.x0[1];

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[2] = ClosedLoopHW_B.Constant1[2];

  /* InitializeConditions for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[2] = ClosedLoopHW_P.x0[2];

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[3] = ClosedLoopHW_B.Constant1[3];

  /* InitializeConditions for Delay: '<Root>/Delay' */
  ClosedLoopHW_DW.Delay_DSTATE[3] = ClosedLoopHW_P.x0[3];

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  ClosedLoopHW_DW.UD_DSTATE[0] = ClosedLoopHW_P.x0[0] / 0.001;
  ClosedLoopHW_DW.UD_DSTATE[1] = ClosedLoopHW_P.x0[1] / 0.001;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Integrator' */
  ClosedLoopHW_DW.Integrator_PrevResetState = 0;
  ClosedLoopHW_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  ClosedLoopHW_DW.icLoad = true;

  /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
  ClosedLoopHW_DW.sfEvent = ClosedLoopHW_CALL_EVENT;
  ClosedLoopHW_DW.is_active_c2_ClosedLoopHW = 0U;

  /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
  ClosedLoopHW_DW.sfEvent_k = ClosedLoopHW_CALL_EVENT;
  ClosedLoopHW_DW.is_active_c3_ClosedLoopHW = 0U;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  ClosedLoopHW_DW.sfEvent_c = ClosedLoopHW_CALL_EVENT;
  ClosedLoopHW_DW.is_active_c1_ClosedLoopHW = 0U;
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

  rtmSetTFinal(ClosedLoopHW_M, 10.0);
  ClosedLoopHW_M->Timing.stepSize0 = 0.001;
  ClosedLoopHW_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  ClosedLoopHW_M->Sizes.checksums[0] = (2992429433U);
  ClosedLoopHW_M->Sizes.checksums[1] = (1778215653U);
  ClosedLoopHW_M->Sizes.checksums[2] = (1913437955U);
  ClosedLoopHW_M->Sizes.checksums[3] = (2381205983U);

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
  ClosedLoopHW_M->Sizes.numBlocks = (50);/* Number of blocks */
  ClosedLoopHW_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  ClosedLoopHW_M->Sizes.numBlockPrms = (102);/* Sum of parameter "widths" */
  return ClosedLoopHW_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
