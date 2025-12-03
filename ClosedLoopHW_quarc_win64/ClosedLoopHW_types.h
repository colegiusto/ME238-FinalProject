/*
 * ClosedLoopHW_types.h
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

/* Parameters (default storage) */
typedef struct P_ClosedLoopHW_T_ P_ClosedLoopHW_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ClosedLoopHW_T RT_MODEL_ClosedLoopHW_T;

#endif                                 /* RTW_HEADER_ClosedLoopHW_types_h_ */
