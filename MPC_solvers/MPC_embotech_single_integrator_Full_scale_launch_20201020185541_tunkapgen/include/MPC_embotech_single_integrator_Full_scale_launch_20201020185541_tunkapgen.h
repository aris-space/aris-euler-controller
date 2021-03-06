/*
MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen : A fast customized optimization solver.

Copyright (C) 2013-2020 EMBOTECH AG [info@embotech.com]. All rights reserved.


This software is intended for simulation and testing purposes only. 
Use of this software for any commercial purpose is prohibited.

This program is distributed in the hope that it will be useful.
EMBOTECH makes NO WARRANTIES with respect to the use of the software 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE. 

EMBOTECH shall not have any liability for any damage arising from the use
of the software.

This Agreement shall exclusively be governed by and interpreted in 
accordance with the laws of Switzerland, excluding its principles
of conflict of laws. The Courts of Zurich-City shall have exclusive 
jurisdiction in case of any dispute.

*/

/* Generated by FORCES PRO v4.0.0 on Tuesday, October 20, 2020 at 6:55:44 PM */

#ifndef SOLVER_STDIO_H
#define SOLVER_STDIO_H
#include <stdio.h>
#endif

#ifndef MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_H
#define MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_H

#ifndef SOLVER_STANDARD_TYPES
#define SOLVER_STANDARD_TYPES

typedef signed char solver_int8_signed;
typedef unsigned char solver_int8_unsigned;
typedef char solver_int8_default;
typedef signed short int solver_int16_signed;
typedef unsigned short int solver_int16_unsigned;
typedef short int solver_int16_default;
typedef signed int solver_int32_signed;
typedef unsigned int solver_int32_unsigned;
typedef int solver_int32_default;
typedef signed long long int solver_int64_signed;
typedef unsigned long long int solver_int64_unsigned;
typedef long long int solver_int64_default;

#endif


/* DATA TYPE ------------------------------------------------------------*/
typedef double MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float;


typedef double MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgeninterface_float;

/* SOLVER SETTINGS ------------------------------------------------------*/

/* MISRA-C compliance */
#ifndef MISRA_C_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen
#define MISRA_C_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen (0)
#endif

/* restrict code */
#ifndef RESTRICT_CODE_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen
#define RESTRICT_CODE_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen (0)
#endif

/* print level */
#ifndef SET_PRINTLEVEL_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen
#define SET_PRINTLEVEL_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen    (0)
#endif

/* timing */
#ifndef SET_TIMING_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen
#define SET_TIMING_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen    (1)
#endif

/* Numeric Warnings */
/* #define PRINTNUMERICALWARNINGS */

/* maximum number of iterations  */
#define SET_MAXIT_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen         (15)	

/* scaling factor of line search (affine direction) */
#define SET_LS_SCALE_AFF_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen  (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(0.9)      

/* scaling factor of line search (combined direction) */
#define SET_LS_SCALE_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen      (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(0.95)  

/* minimum required step size in each iteration */
#define SET_LS_MINSTEP_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen    (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(1E-08)

/* maximum step size (combined direction) */
#define SET_LS_MAXSTEP_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen    (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(0.995)

/* desired relative duality gap */
#define SET_ACC_RDGAP_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen     (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(0.0001)

/* desired maximum residual on equality constraints */
#define SET_ACC_RESEQ_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen     (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(1E-06)

/* desired maximum residual on inequality constraints */
#define SET_ACC_RESINEQ_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen   (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(1E-06)

/* desired maximum violation of complementarity */
#define SET_ACC_KKTCOMPL_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen  (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(1E-06)

/* desired maximum violation of stationarity (only checked if value is > 0) */
#define SET_ACC_KKTSTAT_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen  (MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float)(-1)

/* RETURN CODES----------------------------------------------------------*/
/* solver has converged within desired accuracy */
#define OPTIMAL_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen      (1)

/* maximum number of iterations has been reached */
#define MAXITREACHED_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen (0)

/* solver has stopped due to a timeout */
#define TIMEOUT_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen   (2)

/* no progress in line search possible */
#define NOPROGRESS_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen   (-7)

/* fatal internal error - nans occurring */
#define NAN_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen  (-10)

/* invalid values in parameters */
#define PARAM_VALUE_ERROR_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen   (-11)

/* too small timeout given */
#define INVALID_TIMEOUT_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen   (-12)

/* licensing error - solver not valid on this machine */
#define LICENSE_ERROR_MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen  (-100)


/* PARAMETERS -----------------------------------------------------------*/
/* fill this with data before calling the solver! */
typedef struct MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_params
{
    /* matrix of size [3 x 4] (column major format) */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float eq_C[12];

    /* matrix of size [3 x 4] (column major format) */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float eq_D[12];

    /* vector of size 3 */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float eq_c[3];

    /* matrix of size [4 x 4] (column major format) */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float cost_H_fin[16];

    /* matrix of size [4 x 4] (column major format) */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float cost_H[16];

} MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_params;


/* OUTPUTS --------------------------------------------------------------*/
/* the desired variables are put here by the solver */
typedef struct MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_output
{
    /* vector of size 1 */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float u0[1];

} MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_output;


/* SOLVER INFO ----------------------------------------------------------*/
/* diagnostic data from last interior point step */
typedef struct MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_info
{
    /* iteration number */
    solver_int32_default it;

	/* number of iterations needed to optimality (branch-and-bound) */
	solver_int32_default it2opt;
	
    /* inf-norm of equality constraint residuals */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float res_eq;
	
    /* inf-norm of inequality constraint residuals */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float res_ineq;

    /* primal objective */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float pobj;	
	
    /* dual objective */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float dobj;	

    /* duality gap := pobj - dobj */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float dgap;		
	
    /* relative duality gap := |dgap / pobj | */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float rdgap;		

	/* infinity norm of gradient of Lagrangian*/
	MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float gradient_lag_norm;

    /* duality measure */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float mu;

	/* duality measure (after affine step) */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float mu_aff;
	
    /* centering parameter */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float sigma;
	
    /* number of backtracking line search steps (affine direction) */
    solver_int32_default lsit_aff;
    
    /* number of backtracking line search steps (combined direction) */
    solver_int32_default lsit_cc;
    
    /* step size (affine direction) */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float step_aff;
    
    /* step size (combined direction) */
    MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float step_cc;    

	/* solvertime */
	MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_float solvetime;   

} MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_info;









/* SOLVER FUNCTION DEFINITION -------------------------------------------*/
/* Time of Solver Generation: (UTC) Tuesday, October 20, 2020 6:55:44 PM */
/* User License expires on: (UTC) Thursday, March 11, 2021 10:00:00 PM (approx.) (at the time of code generation) */
/* Solver Static License expires on: (UTC) Thursday, March 11, 2021 10:00:00 PM (approx.) */
/* Solver Generation Request Id: 24aae4c7-6530-46e6-a305-68b874deed9e */
/* examine exitflag before using the result! */
#ifdef __cplusplus
extern "C" {
#endif
extern solver_int32_default MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_solve(MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_params *params, MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_output *output, MPC_embotech_single_integrator_Full_scale_launch_20201020185541_tunkapgen_info *info, FILE *fs);

#ifdef __cplusplus
}
#endif

#endif
