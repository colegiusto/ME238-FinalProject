/*
 * ClosedLoopHW_data.c
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

/* Block parameters (default storage) */
P_ClosedLoopHW_T ClosedLoopHW_P = {
  /* Variable: c
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<S4>/MATLAB Function'
   */
  {
    { -1.0471975511965976, -1.0471975511965976, 1.0471975511965976,
      1.0471975511965976 },

    { -0.57079632679489656, -1.0, 0.0, 0.0 },
    0.82733207386123653,

    { 43.991852073250193, 8.5935753398370736, 2.9559237365937796,
      -7.18954121173107 }
  },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  { -1570.7963267948965, 0.0 },

  /* Mask Parameter: LowPassFilterDiscreteorContinuo
   * Referenced by: '<S3>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_k
   * Referenced by: '<S59>/Time constant'
   */
  0.05,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S62>/Constant'
   */
  2.0,

  /* Mask Parameter: LowPassFilterDiscreteorContin_l
   * Referenced by: '<S59>/Constant'
   */
  1.0,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  { 0U, 1U },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<Root>/HIL Write Analog'
   */
  0U,

  /* Expression: 0
   * Referenced by: '<S56>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S58>/deltax'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S63>/Constant'
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

  /* Expression: pInitialization.M
   * Referenced by: '<S5>/KalmanGainM'
   */
  { 0.49991761650868671, -1.8232225481716439E-5, -0.0045747553357308448,
    -0.0026630910186563215, -1.8232225481716439E-5, 0.4999961829753003,
    -0.0010093524031734723, -0.00040134615206336447, -0.0045747553357308457,
    -0.0010093524031734723, 0.50016866074298771, 9.5424193069381432E-5,
    -0.0026630910186563202, -0.0004013461520633643, 9.5424193069381378E-5,
    0.50005388755343472 },

  /* Expression: pInitialization.C
   * Referenced by: '<S2>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Expression: -pi/2
   * Referenced by: '<Root>/Constant'
   */
  -1.5707963267948966,

  /* Expression: 2*pi/5000
   * Referenced by: '<Root>/Gain'
   */
  0.0012566370614359172,

  /* Expression: -2*pi/10000
   * Referenced by: '<Root>/Gain1'
   */
  -0.00062831853071795862,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  1000.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S65>/Integrator'
   */
  0.001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S65>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S65>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S65>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S65>/Saturation'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S2>/X0'
   */
  { 0.0, 0.0, 0.0, 0.0 },

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

  /* Expression: pInitialization.A
   * Referenced by: '<S2>/A'
   */
  { 0.99998576540126372, -7.9951000542587477E-6, -0.028469121854977832,
    -0.015990157628601377, -3.0303574190192192E-6, 0.99999829466500856,
    -0.0060606987367549736, -0.0034106609376709021, 0.00099999525512871356,
    -2.6649651291512525E-9, 0.9999857654012636, -7.9949579457923772E-6,
    -1.0101202130926839E-9, 0.00099999943155439975, -3.0303574190192192E-6,
    0.99999829466500856 },

  /* Expression: pInitialization.B
   * Referenced by: '<S2>/B'
   */
  { 3.6734008192959926E-5, -5.45219564271056E-5, 0.073467897161256068,
    -0.10904397975730819 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S5>/CovarianceZ'
   */
  { 0.49991761650868671, -1.8232225481716436E-5, -0.0045747553357308448,
    -0.0026630910186563211, -1.8232225481716432E-5, 0.49999618297530013,
    -0.0010093524031734721, -0.00040134615206336447, -0.004574755335730844,
    -0.0010093524031734723, 0.50016866074298771, 9.5424193069381419E-5,
    -0.0026630910186563215, -0.00040134615206336452, 9.54241930693814E-5,
    0.50005388755343483 },

  /* Expression: pInitialization.L
   * Referenced by: '<S5>/KalmanGainL'
   */
  { 0.49990592570632569, -2.489216306579486E-5, -0.01880678718761666,
    -0.010656749207566823, -2.07564803041127E-5, 0.4999949291168484,
    -0.00403914399831635, -0.0021063633120026459, -0.0040745208698151529,
    -0.0010092200150559744, 0.50029789740157671, 0.00016801882067528156,
    -0.0026629569757763132, 9.87294270910485E-5, 0.00017215579357395916,
    0.50009698613194153 },

  /* Expression: pInitialization.D
   * Referenced by: '<S2>/D'
   */
  { 0.0, 0.0, 0.0, 0.0 },

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

  /* Expression: true()
   * Referenced by: '<S2>/Enable'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<Root>/HIL Write Analog'
   */
  false,

  /* Expression: pInitialization.isSqrtUsed
   * Referenced by: '<S54>/isSqrtUsed'
   */
  false
};
