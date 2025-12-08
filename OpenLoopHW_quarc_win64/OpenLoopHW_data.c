/*
 * OpenLoopHW_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OpenLoopHW".
 *
 * Model version              : 1.16
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Sat Dec  6 17:32:46 2025
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
  /* Variable: t_control
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 0.0, 0.09956125726274366, 0.19912251452548732, 0.298683771788231,
    0.39824502905097464, 0.49780628631371832, 0.597367543576462,
    0.69692880083920561, 0.79649005810194928, 0.89605131536469307,
    0.99561257262743663, 1.0951738298901803, 1.1947350871529241,
    1.2942963444156677, 1.3938576016784112, 1.493418858941155,
    1.5929801162038986, 1.6925413734666424, 1.7921026307293861,
    1.8916638879921297, 1.9912251452548733, 2.090786402517617,
    2.1903476597803606, 2.2899089170431042, 2.3894701743058482,
    2.4890314315685917, 2.5885926888313353, 2.6881539460940793,
    2.7877152033568224, 2.887276460619566, 2.98683771788231, 3.0863989751450536,
    3.1859602324077971, 3.2855214896705411, 3.3850827469332847,
    3.4846440041960287, 3.5842052614587723, 3.6837665187215154,
    3.7833277759842594, 3.882889033247003, 3.9824502905097465, 4.08201154777249,
    4.1815728050352341, 4.2811340622979781, 4.3806953195607212,
    4.4802565768234643, 4.5798178340862084, 4.6793790913489524,
    4.7789403486116964, 4.8785016058744395, 4.9780628631371835,
    5.0776241203999275, 5.1771853776626706, 5.2767466349254137,
    5.3763078921881586, 5.4758691494509018, 5.5754304067136449,
    5.6749916639763889, 5.774552921239132, 5.8741141785018769, 5.97367543576462,
    6.073236693027364, 6.1727979502901071, 6.2723592075528511,
    6.3719204648155943, 6.4714817220783374, 6.5710429793410823,
    6.6706042366038254, 6.7701654938665694, 6.8697267511293125,
    6.9692880083920574, 7.0688492656548005, 7.1684105229175445,
    7.2679717801802877, 7.3675330374430308, 7.4670942947057748,
    7.5666555519685188, 7.6662168092312628, 7.7657780664940059, 7.86533932375675,
    7.9649005810194931, 8.0644618382822362, 8.16402309554498, 8.2635843528077242,
    8.3631456100704682, 8.4627068673332122, 8.5622681245959562,
    8.6618293818586984, 8.7613906391214424, 8.8609518963841865,
    8.9605131536469287, 9.0600744109096745, 9.1596356681724167, 9.25919692543516,
    9.3587581826979047, 9.4583194399606487, 9.5578806972233927,
    9.657441954486135, 9.757003211748879, 9.856564469011623 },

  /* Variable: ut
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { -0.18053004719659854, -0.035359807041115757, 0.15456263961281722,
    -0.14423083408066015, 0.0013535954297769618, 0.0074170885422609346,
    0.019162451018347341, 0.014926375245502799, 0.020524292638764884,
    -0.20037655505568788, 0.060819820940200171, 0.0436180935597293,
    -0.12110034372415943, -0.16374371733303644, 0.0015057175239614647,
    -0.040224039186048291, -0.018781014499752658, -0.0589227976408009,
    -0.07897446846089666, 0.058473232244954765, 0.0043192287101090918,
    0.028473343210918545, -0.053020020314356313, -0.0025391575842752269,
    0.051448812296291585, 0.047582433719928589, 0.14150840360407543,
    -0.025819459719290328, 0.10847607796330352, 0.034995932710983189,
    0.10055639036154798, 0.0008509451337742615, -0.012782008757979267,
    -0.11266680357802586, 0.038323798247745816, 0.10560975770848366,
    0.0418237888241414, -0.035926748581064816, 0.11288688511784148,
    -0.014002246088459711, 0.03177420424995632, 0.16025813450746509,
    -0.0728335859221421, -0.11699665539593138, 0.065288708700881062,
    0.22861214512367883, 0.021821615861970046, 0.00216950263899206,
    0.014486478062024157, 0.031788847465090593, 0.11235519594430253,
    -0.0683482924631587, -0.11908163089015927, -0.16123186388420552,
    -0.0677071987489477, -0.1071114640619024, 0.010672709297040636,
    0.059510585899116834, 0.067901298706773749, -0.035597208696478568,
    0.12492212796087633, -0.031705888239356793, 0.12414962527720333,
    -0.10241152420498696, -0.3567149925085748, 0.165530916068247,
    0.094886199334926, 0.12692404039607047, 0.19146412263709003,
    0.20053247100226482, 0.17972032083213546, 0.0681629042469741,
    0.13345636809705355, -0.10749728375860079, -0.25031684156253553,
    -0.2082779595598965, -0.16200579893242487, 0.015607131382694133,
    0.055322220040791861, 0.056217050896638893, 0.0626620645729165,
    0.31883454189697019, 0.12892977388849411, -0.017181253317091152,
    -0.091401110883230927, -0.44454012347645921, -0.33050887250147476,
    -0.094951516785961421, -0.39552895250973646, -0.28792024726997173,
    -0.052873874715743431, 0.52396710958881942, 0.84463363571731753,
    0.74799769991851006, 0.022597389618200837, -0.40057401774305751,
    -0.54085149729916038, -0.52250680785782433, 0.016163137165922558,
    0.23288592637596661 },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<Root>/HIL Write Analog'
   */
  0U,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  { 0U, 1U },

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

  /* Expression: 1/(1.2*0.4006)
   * Referenced by: '<Root>/Gain2'
   */
  2.0802130138126147,

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
