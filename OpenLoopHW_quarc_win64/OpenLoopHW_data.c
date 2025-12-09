/*
 * OpenLoopHW_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OpenLoopHW".
 *
 * Model version              : 1.19
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Tue Dec  9 13:17:52 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OpenLoopHW.h"

/* Block parameters (default storage) */
P_OpenLoopHW_T OpenLoopHW_P = {
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

  /* Variable: t_control
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 0.0, 0.0404040401328055, 0.080808080265611, 0.12121212039841649,
    0.161616160531222, 0.20202020066402746, 0.24242424079683297,
    0.28282828092963846, 0.323232321062444, 0.36363636119524945,
    0.40404040132805491, 0.44444444146086043, 0.48484848159366595,
    0.52525252172647141, 0.56565656185927693, 0.60606060199208245,
    0.646464642124888, 0.68686868225769337, 0.72727272239049889,
    0.76767676252330441, 0.80808080265610982, 0.84848484278891545,
    0.88888888292172086, 0.92929292305452638, 0.9696969631873319,
    1.0101010033201374, 1.0505050434529428, 1.0909090835857485,
    1.1313131237185539, 1.1717171638513595, 1.2121212039841649,
    1.2525252441169705, 1.2929292842497759, 1.3333333243825813,
    1.3737373645153867, 1.4141414046481924, 1.4545454447809978,
    1.4949494849138034, 1.5353535250466088, 1.5757575651794142,
    1.6161616053122196, 1.6565656454450255, 1.6969696855778309,
    1.7373737257106363, 1.7777777658434417, 1.8181818059762473,
    1.8585858461090528, 1.8989898862418582, 1.9393939263746638,
    1.9797979665074692, 2.0202020066402748, 2.0606060467730805,
    2.1010100869058856, 2.1414141270386913, 2.1818181671714969,
    2.2222222073043021, 2.2626262474371077, 2.3030302875699129,
    2.343434327702719, 2.3838383678355242, 2.42424240796833, 2.464646448101135,
    2.5050504882339411, 2.5454545283667462, 2.5858585684995519,
    2.6262626086323575, 2.6666666487651627, 2.7070706888979683,
    2.7474747290307735, 2.7878787691635791, 2.8282828092963848, 2.86868684942919,
    2.9090908895619956, 2.9494949296948012, 2.9898989698276068,
    3.0303030099604125, 3.0707070500932176, 3.1111110902260233,
    3.1515151303588285, 3.1919191704916341, 3.2323232106244393,
    3.2727272507572449, 3.313131290890051, 3.3535353310228562,
    3.3939393711556618, 3.434343411288467, 3.4747474514212726,
    3.5151514915540778, 3.5555555316868834, 3.5959595718196886,
    3.6363636119524947, 3.6767676520853003, 3.7171716922181055,
    3.7575757323509111, 3.7979797724837163, 3.838383812616522,
    3.8787878527493276, 3.9191918928821328, 3.9595959330149384,
    3.999999973147744 },

  /* Variable: ut
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { -0.52497447146502574, -0.48099331196231121, -0.42724895120848738,
    -0.40772677188018497, -0.4085617756269419, -0.39534780709209422,
    -0.35538099942358348, -0.29980743190027448, -0.24892635937199173,
    -0.21905953632912484, -0.20778191364826676, -0.17143971768576705,
    -0.058590368534732873, 0.098157346683258623, 0.23789701837384519,
    0.33186263754021217, 0.37686375109014875, 0.38532638945434389,
    0.37924581532180079, 0.38058740969911159, 0.39023951090406844,
    0.36780863137891, 0.28539630075412165, 0.16122142236156098,
    0.02249959644391613, -0.10821160161060356, -0.21132073617977104,
    -0.26891750339846993, -0.26805742269825061, -0.2114501291864479,
    -0.13592404788103332, -0.13084584398375798, -0.22181927056958348,
    -0.28542127763499775, -0.27900697072078079, -0.21804364105416538,
    -0.12582988678388216, -0.021839341721171756, 0.078674427873770422,
    0.16171924930055706, 0.21158029620907093, 0.21099254599712161,
    0.15019390978531083, 0.051244823601957104, 0.017563772331960856,
    0.14060488781941055, 0.25972469880340243, 0.30226673082981076,
    0.27999914107435514, 0.21992451833130977, 0.14297937608380706,
    0.06084360661630648, -0.019530606252267754, -0.0914056549384675,
    -0.14575039838541659, -0.17025396801790105, -0.15305761807425119,
    -0.0999588891405607, -0.072461369438548653, -0.17165468785294652,
    -0.29604566927312115, -0.34655721078200974, -0.33204173252320235,
    -0.2844111321431127, -0.22371610631968739, -0.15880038053877732,
    -0.095910007496036565, -0.0390409270390991, 0.012179018685615857,
    0.060555293323178744, 0.10510395069029209, 0.1355548377110781,
    0.13827068507732582, 0.11448112254828602, 0.11187292557904314,
    0.21151491236561967, 0.301528472742281, 0.31363597012752409,
    0.27661676761934023, 0.22408699163913909, 0.17038119833344953,
    0.12089664105283374, 0.079973131346658649, 0.049196898154491124,
    0.027042919043251838, 0.010945119943911624, -0.0013771027292362452,
    -0.011615527426728493, -0.020949504268039227, -0.03016992299666732,
    -0.039754399524497552, -0.049869263201041868, -0.060282215332737504,
    -0.070154327802650018, -0.0776532928188096, -0.079290565044389361,
    -0.068833941695550821, -0.035570820604770535, 0.038489686496439336,
    0.087881966222981348 },

  /* Variable: x0
   * Referenced by: '<S1>/Constant1'
   */
  { -1.5707963267948966, 0.0, 0.0, 0.0 },

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

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.001,

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
  true
};
