% ARIS_Euler_MPC_embotech_single_integrator_20201019233222 - a fast solver generated by FORCES PRO v4.0.0
%
%   OUTPUT = ARIS_Euler_MPC_embotech_single_integrator_20201019233222(PARAMS) solves a multistage problem
%   subject to the parameters supplied in the following struct:
%       PARAMS.eq_C - matrix of size [3 x 4]
%       PARAMS.eq_D - matrix of size [3 x 4]
%       PARAMS.eq_c - column vector of length 3
%       PARAMS.cost_H_fin - matrix of size [4 x 4]
%       PARAMS.cost_H - matrix of size [4 x 4]
%       PARAMS.maxit - column vector of length 0
%
%   OUTPUT returns the values of the last iteration of the solver where
%       OUTPUT.u0 - column vector of size 1
%
%   [OUTPUT, EXITFLAG] = ARIS_Euler_MPC_embotech_single_integrator_20201019233222(PARAMS) returns additionally
%   the integer EXITFLAG indicating the state of the solution with 
%       1 - OPTIMAL solution has been found (subject to desired accuracy)
%       0 - Timeout - maximum number of iterations reached
%      -7 - Method could not progress. Problem may be infeasible. Run FORCESdiagnostics on your problem to check for most common errors in the formulation.
%    -100 - License error
%
%   [OUTPUT, EXITFLAG, INFO] = ARIS_Euler_MPC_embotech_single_integrator_20201019233222(PARAMS) returns 
%   additional information about the last iterate:
%       INFO.it        - number of iterations that lead to this result
%       INFO.res_eq    - max. equality constraint residual
%       INFO.res_ineq  - max. inequality constraint residual
%       INFO.pobj      - primal objective
%       INFO.dobj      - dual objective
%       INFO.dgap      - duality gap := pobj - dobj
%       INFO.rdgap     - relative duality gap := |dgap / pobj|
%       INFO.mu        - duality measure
%       INFO.sigma     - centering parameter
%       INFO.lsit_aff  - iterations of affine line search
%       INFO.lsit_cc   - iterations of line search (combined direction)
%       INFO.step_aff  - step size (affine direction)
%       INFO.step_cc   - step size (centering direction)
%       INFO.solvetime - Time needed for solve (wall clock time)
%
% See also COPYING
