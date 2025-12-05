/*
 * ClosedLoopHW_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ClosedLoopHW".
 *
 * Model version              : 1.36
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Dec  4 17:18:11 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ClosedLoopHW.h"

/* Block parameters (default storage) */
P_ClosedLoopHW_T ClosedLoopHW_P = {
  /* Variable: est_param
   * Referenced by: '<S3>/MATLAB Function'
   */
  {
    { 0.99974436791598642, 0.00020348798945244267, -0.065674150788442687,
      0.065960864569940117, 0.00020548447041177396, 0.99971617646168753,
      0.023640486335375573, -0.10250384450187044, 0.00092483995743419486,
      0.00030697194489008177, 0.98562314451834176, 0.024309745727368135,
      -0.00019792608177175339, 0.00088670525779182652, 0.024311981416540743,
      0.95135809692550566 },

    { 6.1318003148373216e-5, -6.4830892192962888e-5, 0.0904910095391707,
      -0.17150343382627772, 0.00021758086397578597, -0.00018299424530869579,
      5.8431017708283336e-5, 0.00022705696072118959, -0.00018324798993051523,
      0.00024057571860499729, -0.00028568191016043994, 7.0037900255575931e-5,
      7.5038512527247133e-5, -0.00030687353870831319, 0.014343797837512898,
      -0.024276349213349226, 0.00019802515706231782, 0.00011315996827434077,
      -0.024299916026398149, 0.048590169895355632 }
  },

  /* Variable: p
   * Referenced by: '<S1>/MATLAB Function'
   */
  {
    9.8,
    0.014806176,
    0.005095632,
    0.00456684,
    0.100326264,
    0.03028536,
    1.0,
    1.0,
    1.0,
    1.0,
    1.0,
    1.0,
    0.5,
    0.5
  },

  /* Variable: c
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<S3>/Constant'
   *   '<S5>/MATLAB Function'
   */
  {
    { -1.0471975511965976, -1.0471975511965976, 1.0471975511965976,
      1.0471975511965976 },

    { -1.5707963267948966, -0.0, 0.0, 0.0 },
    2.815050406471702e-17,

    { -22.314584401831219, -22.037456376350438, 3.0465850879368395,
      -4.0483652601608195 }
  },

  /* Variable: x0
   * Referenced by:
   *   '<Root>/Delay'
   *   '<S1>/Constant1'
   *   '<S2>/UD'
   *   '<S3>/Constant'
   */
  { -1.4707963267948965, 0.0, 0.0, 0.0 },

  /* Mask Parameter: LowPassFilterDiscreteorContinuo
   * Referenced by: '<S4>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_k
   * Referenced by: '<S8>/Time constant'
   */
  0.1,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S11>/Constant'
   */
  2.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_l
   * Referenced by: '<S8>/Constant'
   */
  2.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_g
   * Referenced by: '<S13>/Constant'
   */
  { 0.0, 0.0 },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<Root>/HIL Write Analog'
   */
  0U,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  { 0U, 1U },

  /* Expression: 0
   * Referenced by: '<S12>/Constant'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.6666666666666668E+7,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  16276.041666666668,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 1/(1.2*0.4006*3.5)
   * Referenced by: '<Root>/Gain2'
   */
  0.59434657537503266,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Saturation'
   */
  -1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.001,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S15>/Integrator'
   */
  0.001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S15>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S15>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S15>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S15>/Saturation'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S2>/TSamp'
   */
  1000.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Step'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1 },

  /* Computed Parameter: HILInitialize_CKModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 0 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  2,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<Root>/HIL Write Analog'
   */
  false,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  true
};
