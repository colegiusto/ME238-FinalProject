/*
 * ClosedLoopHW_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(struct_EyhfgjFUMIaPmLVzByLI3F),
  sizeof(struct_IikMKrhxguvBv6I6XHfpIC),
  sizeof(struct_8dcRBKd2sugfTo5czTP1GD),
  sizeof(t_card),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "struct_EyhfgjFUMIaPmLVzByLI3F",
  "struct_IikMKrhxguvBv6I6XHfpIC",
  "struct_8dcRBKd2sugfTo5czTP1GD",
  "t_card",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&ClosedLoopHW_B.Constant1[0]), 0, 0, 42 },

  { (char_T *)(&ClosedLoopHW_B.LogicalOperator), 8, 0, 1 }
  ,

  { (char_T *)(&ClosedLoopHW_DW.DiscreteTimeIntegrator_DSTATE[0]), 0, 0, 40 },

  { (char_T *)(&ClosedLoopHW_DW.HILInitialize_Card), 18, 0, 1 },

  { (char_T *)(&ClosedLoopHW_DW.Scope_PWORK.LoggedData), 11, 0, 8 },

  { (char_T *)(&ClosedLoopHW_DW.HILInitialize_QuadratureModes[0]), 6, 0, 11 },

  { (char_T *)(&ClosedLoopHW_DW.Integrator_PrevResetState), 2, 0, 1 },

  { (char_T *)(&ClosedLoopHW_DW.Integrator_IC_LOADING), 3, 0, 4 },

  { (char_T *)(&ClosedLoopHW_DW.icLoad), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ClosedLoopHW_P.est_param), 17, 0, 1 },

  { (char_T *)(&ClosedLoopHW_P.p), 15, 0, 1 },

  { (char_T *)(&ClosedLoopHW_P.c), 16, 0, 1 },

  { (char_T *)(&ClosedLoopHW_P.dC[0]), 0, 0, 44 },

  { (char_T *)(&ClosedLoopHW_P.HILInitialize_CKChannels[0]), 6, 0, 7 },

  { (char_T *)(&ClosedLoopHW_P.HILInitialize_AIChannels[0]), 7, 0, 13 },

  { (char_T *)(&ClosedLoopHW_P.HILInitialize_Active), 8, 0, 35 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] ClosedLoopHW_dt.h */
