//
//  controller.c
//  
//
//  Created by Ulises Magaña on 09/22/20
//

#include <stdlib.h>
#include <math.h>


#define controller_IMPORT
#include "controller.h"


/*
 *
 * The function predict_trajectory calculates the person's
 * trajectory using the Euler's method
 *
 * @params
 *      vars (* EQ_VARS):
            EQ_VARS struct
        file (* FILE)
            CSV file to save the data
        
 * @returns
        void
*/

void predict_trajectory(EQ_VARS *vars, FILE *file) {
    int counter = 0, hits = 0, lives = 0, points;
    float x0 = 10, x1 = 10, x2;
    float op1, op2, mass, k, discreet_time, index, time;

    points = vars->points;
    k = vars->jumps_constant;
    mass = vars->mass;
    discreet_time = (vars->ending_time - vars->initial_time) / (vars->points);

    for(index = 1; index <= points; index++){
        time = index/points;
        op1 = -x0 * (1 + (k * pow(discreet_time, 2)) / mass);
        op2 = 2 * x1 + pow(discreet_time, 2) * GRAVITY;
        x2 = op1 + op2;

        if(x0 <= x2) {
            hits++;
        } else {
            lives++;
        }

        fprintf(file, "%.2f, %.2f\n", time, x2);
        
        x0 = x1;
        x1 = x2;
    }

    if(hits > 1) {
        printf("The person got hit\n\n");
    }
    else{
        printf("The person is safe and sound\n\n");
    }

}
