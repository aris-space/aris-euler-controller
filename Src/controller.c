//
// Created by Tun Kapgen on 05.06.20.
//

#include "../Inc/controller.h"

#if CONTROLLER_TYPE == 0
    #include "../Src/test_controller.c" 
#elif CONTROLLER_TYPE == 1
    #include "../Src/lqr_controller.c"
#elif CONTROLLER_TYPE == 2
    #include "../Src/mpc_controller.c"
#endif

void control_data_init(control_data_t *control_data){
    control_data_reset(control_data);

    control_data->sf_velocity = 0;
    control_data->sf_ref_altitude_AGL = 0;
    control_data->tracking_feedback = 0;

    control_data->lowerboundary_aw = 0;
    control_data->upperboundary_aw = 0;

    const double optimal_trajectory_coeff[POLY_DEG+1] = {0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000028201512266827400983745999323449956, -0.000000000000000000000000000000000000000000000000000000000000000000000000000000000169169587081394999722992574816736963843, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000267806258884121013433549049474308717778795, 0.000000000000000000000000000000000000000000000000000000000000000000000000000156310056569105985899288991995874860995901209, -0.000000000000000000000000000000000000000000000000000000000000000000000000420781989593098999410481924748335586374112864584, -0.000000000000000000000000000000000000000000000000000000000000000000000572860174513895973807675225467011036256248527396007, 0.000000000000000000000000000000000000000000000000000000000000000000294721591265893008917159606265125757550845617787456478, 0.000000000000000000000000000000000000000000000000000000000000001462131385430680025992070570814816730592596720193171790698, 0.000000000000000000000000000000000000000000000000000000000001096110591600740018066629549842693785052522113398095235399306, -0.000000000000000000000000000000000000000000000000000000001725731829585179867490660389918973663538734923170165853320743282, -0.000000000000000000000000000000000000000000000000000004483521573247719904542525964273480990676345706714048874017774224721, -0.000000000000000000000000000000000000000000000000001828511307393350097984003197933791219521865641239921753135337682081073, 0.000000000000000000000000000000000000000000000007626773483327769523161411281655730244127601002639531677722015892685518214, 0.000000000000000000000000000000000000000000012890752715884498906150595465213574025309580078273577359118702478738492991177, -0.000000000000000000000000000000000000000003351196781005100066130584894030817234483816568341917229611562328192132993040491, -0.000000000000000000000000000000000000032688157782857599948097673837154255674109177866476450201429364646062551473687276756, -0.000000000000000000000000000000000018742040213220800120872136755681874910336266097597550445659810603981725103805983628575, 0.000000000000000000000000000000065362741029228002330069734823877649438166628309112796605973076331327593535511650537847550, 0.000000000000000000000000000068525746928614100606193437410123075133805238652851087043996671738078293740614038709324518095, -0.000000000000000000000000156682364783303998331950173525814289779487137972400167048695103917373486202002652589726494625211, -0.000000000000000000000107527358253817007694879944590430329595727063973756351966681605453191039600824296940118074417114258, 0.000000000000000000502656163258752008789341001009140755113277120360979919808097626798826240701600909233093261718750000000, -0.000000000000000610156719570548005951499611144859998469357957682351889516780829580966383218765258789062500000000000000000, 0.000000000000414126427426334024000398761411778465681317318303200636364636011421680450439453125000000000000000000000000000, -0.000000000177828483957205990623426351975619290335384192758283461444079875946044921875000000000000000000000000000000000000, 0.000000049665184343479100379224630513672056331131443585036322474479675292968750000000000000000000000000000000000000000000, -0.000008905405334945729625912083649019734821195015683770179748535156250000000000000000000000000000000000000000000000000000, 0.000985068911605107991671936851219015807146206498146057128906250000000000000000000000000000000000000000000000000000000000, -0.064843381998808694022251586375205079093575477600097656250000000000000000000000000000000000000000000000000000000000000000, 3.103069038794299849826074932934716343879699707031250000000000000000000000000000000000000000000000000000000000000000000000, 6.697333443398809649238501151558011770248413085937500000000000000000000000000000000000000000000000000000000000000000000000};
    memcpy(control_data->optimal_trajectory_coeff, optimal_trajectory_coeff, sizeof(optimal_trajectory_coeff));

    #if CONTROLLER_TYPE == 1
        init_gains(control_data);
    #elif CONTROLLER_TYPE == 2
        init_params(control_data);
    #endif
}

void control_data_reset(control_data_t *control_data){
    control_data->control_input = 0;
    control_data->reference_error = 0;
    control_data->integrated_error = 0;
}

void control_step(control_data_t *control_data, state_est_data_t *state_est_data, flight_phase_detection_t *flight_phase_detection) {
    /* Update the control data struct*/
    control_data->sf_velocity = ((float)state_est_data->velocity_rocket[0]) / 1000;
    control_data->sf_ref_altitude_AGL = ((float) state_est_data->position_world[2]) / 1000;
    control_data->tracking_feedback = ((float) state_est_data->airbrake_extension) / 1000000;

    eval_optimal_trajectory_polyfit(control_data);
    compute_control_input(control_data, flight_phase_detection);
}

void eval_optimal_trajectory_polyfit(control_data_t *control_data) {
    /* For Speed */
    double x_placeholder = 0;

    /* Reset ref_velocity_placeholder*/
    double ref_velocity_placeholder = 0;

    control_data->ref_velocity = (float)ref_velocity_placeholder;

    /* For loop */
    for (int i = 0; i < POLY_DEG + 1; ++i) {
        x_placeholder = pow(control_data->sf_ref_altitude_AGL, (double)(POLY_DEG - i));
        ref_velocity_placeholder += (control_data->optimal_trajectory_coeff[i] * x_placeholder);
    }
}

void compute_reference_error(control_data_t *control_data) {
    if (control_data->ref_velocity < 0) {
        control_data->reference_error = control_data->sf_velocity;
    }
    else{
        control_data->reference_error = control_data->sf_velocity - control_data->ref_velocity;
    }
}

void compute_integrated_error(control_data_t *control_data) {
    control_data->upperboundary_aw = fmaxf(M_AW *
            (CONTROL_DEACTIVATION_ALTITUDE_AGL - control_data->sf_ref_altitude_AGL), MIN_BOUNDARAY_AW);
    if (CONTROL_DEACTIVATION_ALTITUDE_AGL < control_data->sf_ref_altitude_AGL) {
        control_data->upperboundary_aw = 0;
    }
    control_data->lowerboundary_aw = - control_data->upperboundary_aw;

    /* Compute the integrated error */
    control_data->integrated_error = fmaxf(control_data->lowerboundary_aw, fminf(control_data->integrated_error
    + DELTA_T * control_data->reference_error, control_data->upperboundary_aw));
}

#if defined(EULER_SIMCON) && CONTROLLER_TYPE == 1
void save_evaluated_polyfits_to_file(control_data_t *control_data){
    int lin_num = 10000;
    FILE *fptr;
    float delta_lin = (float)TARGET_AGOGEE / (float)lin_num;
    fptr = fopen ("plotting/data/coeff_data.csv", "w+");
    for (int j = 0; j < lin_num+1; j++){
        control_data->sf_ref_altitude_AGL = delta_lin * j;
        eval_gains_polyfit(control_data);
        fprintf(fptr, "%f,%f,%f,%f,%f\n", control_data->sf_ref_altitude_AGL,
                control_data->ref_velocity, control_data->gains[0], control_data->gains[1], control_data->gains[2]);
    }
    fprintf(fptr,"\n");
    fclose(fptr);
}
#endif
