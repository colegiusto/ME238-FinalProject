/*
 * ClosedLoopHW_types.h
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

#ifndef RTW_HEADER_ClosedLoopHW_types_h_
#define RTW_HEADER_ClosedLoopHW_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_IikMKrhxguvBv6I6XHfpIC_
#define DEFINED_TYPEDEF_FOR_struct_IikMKrhxguvBv6I6XHfpIC_

typedef struct {
  real_T bounds[4];
  real_T x_star[4];
  real_T u_star;
  real_T K[4];
} struct_IikMKrhxguvBv6I6XHfpIC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_8dcRBKd2sugfTo5czTP1GD_
#define DEFINED_TYPEDEF_FOR_struct_8dcRBKd2sugfTo5czTP1GD_

typedef struct {
  real_T A[16];
  real_T B[12];
} struct_8dcRBKd2sugfTo5czTP1GD;

#endif

#ifndef struct_tag_jB9SLzkz3eVf9leLxH4yWF
#define struct_tag_jB9SLzkz3eVf9leLxH4yWF

struct tag_jB9SLzkz3eVf9leLxH4yWF
{
  int32_T S0_isInitialized;
  real_T W0_states[85];
  real_T P0_InitialStates;
  real_T P1_Coefficients[86];
};

#endif                                 /* struct_tag_jB9SLzkz3eVf9leLxH4yWF */

#ifndef typedef_b_dsp_FIRFilter_0_ClosedLoopH_T
#define typedef_b_dsp_FIRFilter_0_ClosedLoopH_T

typedef struct tag_jB9SLzkz3eVf9leLxH4yWF b_dsp_FIRFilter_0_ClosedLoopH_T;

#endif                             /* typedef_b_dsp_FIRFilter_0_ClosedLoopH_T */

#ifndef struct_tag_Y3g8dL5mymaSXqvMAOPGHG
#define struct_tag_Y3g8dL5mymaSXqvMAOPGHG

struct tag_Y3g8dL5mymaSXqvMAOPGHG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_ClosedLoopH_T cSFunObject;
};

#endif                                 /* struct_tag_Y3g8dL5mymaSXqvMAOPGHG */

#ifndef typedef_b_dspcodegen_FIRFilter_Closed_T
#define typedef_b_dspcodegen_FIRFilter_Closed_T

typedef struct tag_Y3g8dL5mymaSXqvMAOPGHG b_dspcodegen_FIRFilter_Closed_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_Closed_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_ClosedLoopHW_T
#define typedef_cell_wrap_ClosedLoopHW_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_ClosedLoopHW_T;

#endif                                 /* typedef_cell_wrap_ClosedLoopHW_T */

#ifndef struct_tag_p30oaDSryE2FkRWfPbQTH
#define struct_tag_p30oaDSryE2FkRWfPbQTH

struct tag_p30oaDSryE2FkRWfPbQTH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_ClosedLoopHW_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Closed_T *FilterObj;
  b_dspcodegen_FIRFilter_Closed_T _pobj0;
};

#endif                                 /* struct_tag_p30oaDSryE2FkRWfPbQTH */

#ifndef typedef_dsp_simulink_LowpassFilter_Cl_T
#define typedef_dsp_simulink_LowpassFilter_Cl_T

typedef struct tag_p30oaDSryE2FkRWfPbQTH dsp_simulink_LowpassFilter_Cl_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_Cl_T */

/* Parameters (default storage) */
typedef struct P_ClosedLoopHW_T_ P_ClosedLoopHW_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ClosedLoopHW_T RT_MODEL_ClosedLoopHW_T;

#endif                                 /* RTW_HEADER_ClosedLoopHW_types_h_ */
