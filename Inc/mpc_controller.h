#ifndef MPC_CONTROLLER_H
#define MPC_CONTROLLER_H

#include "controller_const.h"
#include "controller.h"

void init_params(control_data_t *control_data);
void compute_control_input(control_data_t *control_data, flight_phase_detection_t *current_flight_phase_detection);

#endif