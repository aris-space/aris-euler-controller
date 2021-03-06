//
// Created by Tun Kapgen on 05.10.20.
//

#ifndef PLANT_MANIPULATOR_H
#define PLANT_MANIPULATOR_H

#include "controller_const.h"
#include "plant_manipulator_const.h"
#include "../../aris-euler-state-estimation/Inc/env.h"
#include "../../aris-euler-state-estimation/Inc/flight_phase_detection.h"
#include "../../aris-euler-state-estimation/Inc/Util/math_utils.h"

void linear_model(control_data_t *control_data, flight_phase_detection_t *flight_phase_detection, env_t *env);
void get_C_A_rocket(flight_phase_detection_t *flight_phase_detection, float *C_A_rocket);
void get_C_A_AB(float airbrake_extension, flight_phase_detection_t *flight_phase_detection, float *C_A_AB);

#endif //PLANT_MANIPULATOR_H
