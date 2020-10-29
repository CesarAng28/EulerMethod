//
//  view.c
//  
//
//  Created by Ulises Magaña on 09/22/20
//

#include <stdlib.h>


#define view_IMPORT
#include "view.h"


/*
 *
 * The function set_values() requests the user to input different
 * values to use them in the Euler's method.
 *
 * @params
 *      vars (* EQ_VARS):
            EQ_VARS struct
        
 * @returns
        equation's values
*/

EQ_VARS * set_values(EQ_VARS *vars) { 
    float mass, jumps_constant, initial_time, ending_time, points;

    printf("Input the mass' value: ");
    scanf("%f", &mass);
    printf("Input the bungee's jump constant: ");
    scanf("%f", &jumps_constant);
    printf("Input the initial time: ");
    scanf("%f", &initial_time);
    printf("Input the ending time: ");
    scanf("%f", &ending_time);
    printf("Input the number of points you want to plot: ");
    scanf("%f", &points);
    
    vars->mass = mass;
    vars->jumps_constant = jumps_constant;
    vars->initial_time = initial_time;
    vars->ending_time = ending_time;
    vars->points = points;
    
    return vars;
}