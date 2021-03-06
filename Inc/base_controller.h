//
// Created by Tun Kapgen on 05.06.20.
//

#ifndef BASE_CONTROLLER_H
#define BASE_CONTROLLER_H

#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../aris-euler-state-estimation/Inc/env.h"
#include "../../aris-euler-state-estimation/Inc/flight_phase_detection.h"
#include "../../aris-euler-state-estimation/Inc/state_est_const.h"
#include "controller_const.h"

/* function declaration */
void control_data_reset(control_data_t *control_data);
void eval_optimal_trajectory_polyfit(control_data_t *control_data);
void compute_reference_error(control_data_t *control_data);
void compute_integrated_error(control_data_t *control_data);

#endif //CONTROLLER_H
