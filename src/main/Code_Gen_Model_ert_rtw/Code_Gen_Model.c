/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Dec 16 20:41:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Code_Gen_Model.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Code_Gen_Model_private.h"
#include "rtwtypes.h"
#include <float.h>

/* Exported block parameters */
real_T Frequency = 0.25;               /* Variable: Frequency
                                        * Referenced by:
                                        *   '<S2>/Constant1'
                                        *   '<S4>/Constant1'
                                        *   '<S5>/Constant1'
                                        */
real_T Offset = 0.0;                   /* Variable: Offset
                                        * Referenced by:
                                        *   '<S2>/Constant3'
                                        *   '<S3>/Constant3'
                                        *   '<S4>/Constant3'
                                        *   '<S5>/Constant3'
                                        */

/* Block signals (default storage) */
B_Code_Gen_Model_T Code_Gen_Model_B;

/* Block states (default storage) */
DW_Code_Gen_Model_T Code_Gen_Model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Code_Gen_Model_T Code_Gen_Model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Code_Gen_Model_T Code_Gen_Model_Y;

/* Real-time model */
static RT_MODEL_Code_Gen_Model_T Code_Gen_Model_M_;
RT_MODEL_Code_Gen_Model_T *const Code_Gen_Model_M = &Code_Gen_Model_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void Code_Gen_Model_step(void)
{
  real_T rtb_Divide;
  int32_T tmp;
  int8_T rtPrevAction;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/Game_State'
   */
  rtPrevAction = Code_Gen_Model_DW.SwitchCase_ActiveSubsystem;
  Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = -1;
  rtb_Divide = trunc(Code_Gen_Model_U.Game_State);
  if (rtIsNaN(rtb_Divide) || rtIsInf(rtb_Divide)) {
    rtb_Divide = 0.0;
  } else {
    rtb_Divide = fmod(rtb_Divide, 4.294967296E+9);
  }

  if (rtb_Divide < 0.0) {
    tmp = -(int32_T)(uint32_T)-rtb_Divide;
  } else {
    tmp = (int32_T)(uint32_T)rtb_Divide;
  }

  switch (tmp) {
   case 0:
    Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case 1:
    Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   case 2:
    Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = 2;
    break;

   case 3:
    Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = 3;
    break;
  }

  switch (Code_Gen_Model_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S3>/Constant3'
     *  Inport: '<Root>/Smart_Dashboard_input'
     *  Sum: '<S3>/Add'
     */
    Code_Gen_Model_B.Merge = Offset + Code_Gen_Model_U.Smart_Dashboard_input;

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    if (Code_Gen_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S2>/Unit Delay'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_c = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Autonomous' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    Code_Gen_Model_DW.UnitDelay_DSTATE_c += 0.02;

    /* Trigonometry: '<S2>/Sin' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Gain: '<S2>/Gain'
     *  Product: '<S2>/Product'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    Code_Gen_Model_B.sine_wave_raw = sin(6.2831853071795862 * Frequency *
      Code_Gen_Model_DW.UnitDelay_DSTATE_c);

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S2>/Constant3'
     *  Inport: '<Root>/Smart_Dashboard_input'
     *  Product: '<S2>/Product1'
     *  Sum: '<S2>/Add'
     */
    Code_Gen_Model_B.Merge = Code_Gen_Model_U.Smart_Dashboard_input *
      Code_Gen_Model_B.sine_wave_raw + Offset;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    if (Code_Gen_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/TeleOp' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S4>/Unit Delay'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_d = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/TeleOp' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/TeleOp' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Product: '<S4>/Divide' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    rtb_Divide = 1.0 / Frequency;

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    Code_Gen_Model_DW.UnitDelay_DSTATE_d += 0.02;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Inport: '<Root>/Smart_Dashboard_input'
     *  Math: '<S4>/Mod'
     *  Product: '<S4>/Product1'
     *  Sum: '<S4>/Add'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    Code_Gen_Model_B.Merge = Code_Gen_Model_U.Smart_Dashboard_input *
      rt_modd_snf(Code_Gen_Model_DW.UnitDelay_DSTATE_d, rtb_Divide) / rtb_Divide
      + Offset;

    /* End of Outputs for SubSystem: '<S1>/TeleOp' */
    break;

   case 3:
    if (Code_Gen_Model_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Test' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S5>/Unit Delay'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Test' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Sum: '<S5>/Sum' incorporates:
     *  Constant: '<S5>/Constant'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    Code_Gen_Model_DW.UnitDelay_DSTATE += 0.02;

    /* Product: '<S5>/Divide' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    rtb_Divide = 1.0 / Frequency;

    /* Switch: '<S5>/Switch' incorporates:
     *  Gain: '<S5>/Gain'
     *  Inport: '<Root>/Smart_Dashboard_input'
     *  Math: '<S5>/Mod'
     *  RelationalOperator: '<S5>/Relational Operator'
     *  UnaryMinus: '<S5>/Unary Minus'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    if (rt_modd_snf(Code_Gen_Model_DW.UnitDelay_DSTATE, rtb_Divide) >= 0.5 *
        rtb_Divide) {
      rtb_Divide = Code_Gen_Model_U.Smart_Dashboard_input;
    } else {
      rtb_Divide = -Code_Gen_Model_U.Smart_Dashboard_input;
    }

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Sum: '<S5>/Add'
     *  Switch: '<S5>/Switch'
     */
    Code_Gen_Model_B.Merge = Offset + rtb_Divide;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Outport: '<Root>/Smart_Dashboard_output' */
  Code_Gen_Model_Y.Smart_Dashboard_output = Code_Gen_Model_B.Merge;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = -1;
}

/* Model terminate function */
void Code_Gen_Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
