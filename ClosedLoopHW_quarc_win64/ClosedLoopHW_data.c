/*
 * ClosedLoopHW_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ClosedLoopHW".
 *
 * Model version              : 1.48
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Dec  5 15:31:47 2025
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
    { 0.99870289783697985, 0.00097183083224438313, -0.050481078155066049,
      0.026515801118332214, 0.00097030087214362273, 0.99666465175510677,
      0.023451259586486077, -0.095736901147557549, 0.00099935544023447057,
      4.8407639015654509e-7, 0.9999747520578699, 1.3268656430191241e-5,
      4.8356614919550721e-7, 0.00099833931089235613, 1.1736251024946298e-5,
      0.99995210274266644 },

    { 4.1562577519353845e-5, -7.228406677090856e-5, 0.0832061212922221,
      -0.14475217956886224, 0.0012724906082641372, -0.00095813411287155468,
      0.001228560405438174, 0.00092316124795713153, -0.00096118573298054066,
      0.0032903887700508811, -0.0051846879888380014, 0.0057141276550995088 }
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
   *   '<Root>/x_star'
   *   '<S3>/Constant'
   *   '<S3>/Constant1'
   *   '<S5>/MATLAB Function'
   */
  {
    { -1.0471975511965976, -1.0471975511965976, 1.0471975511965976,
      1.0471975511965976 },

    { -0.97079632679489658, -0.6, 0.0, 0.0 },
    0.55515500515189742,

    { -11.760200881355267, -18.071218325641507, 0.86639265765517182,
      -6.4159582829986377 }
  },

  /* Variable: dC
   * Referenced by: '<Root>/Multiply'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: x0
   * Referenced by:
   *   '<Root>/Delay'
   *   '<S1>/Constant1'
   *   '<S2>/UD'
   *   '<S3>/Constant'
   */
  { -1.2707963267948965, 0.0, 0.0, 0.0 },

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

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<Root>/HIL Write Analog'
   */
  0U,

  /* Expression: 2*pi/5000
   * Referenced by: '<Root>/Gain'
   */
  0.0012566370614359172,

  /* Expression: -pi/2
   * Referenced by: '<Root>/Constant'
   */
  -1.5707963267948966,

  /* Expression: -2*pi/10000
   * Referenced by: '<Root>/Gain1'
   */
  -0.00062831853071795862,

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

  /* Expression: -1
   * Referenced by: '<Root>/Constant1'
   */
  -1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

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

  /* Expression: 2/(1.2*0.4006*3.5)
   * Referenced by: '<Root>/Gain2'
   */
  1.1886931507500653,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Saturation'
   */
  -1.0,

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

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<Root>/HIL Write Analog'
   */
  false
};
