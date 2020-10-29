//
//  model.h
//  
//
//  Created by Ulises Magaña on 09/22/20
//

#ifndef model_h
#define model_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/* Constants declarations. */

#define GRAVITY 9.81
#define MAX 200

/* Set EXTERN macro: */

#ifndef model_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Types declarations. */

typedef struct eq_vars{
    float mass;
    float jumps_constant;
    float initial_time;
    float ending_time;
    float points;
} EQ_VARS;

/* Global variables declarations. */


/* Function prototypes. */

/*
 * Instanciates a new file pointer identified via its name and mode.
 * @param
 *  name (char *):
 *      Name of the file
 *  mode (char *):
 *      Mode of file to be opened {r, rb, a, ab, w, wb}
 *
 * @return FILE * opened_file.
*/

EXTERN FILE * new_file(char *name, char *mode);


/*
 *
 * The function generate_plot() gives an instruction within GNUPLOT
 * to generate a plot depending on which file is sent to this function.
 *
 * @params
 *  name (char *):
       Name of the file
     

 * @returns
        void   
*/

EXTERN void generate_plot(char *name);



#undef model_IMPORT
#undef EXTERN

#endif /* model_h */