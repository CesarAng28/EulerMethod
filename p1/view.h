//
//  view.h
//  
//
//  Created by Ulises Magaña on 09/22/20
//

#ifndef view_h
#define view_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>

#include "model.h"

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef view_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Types declarations. */


/* Global variables declarations. */


/* Function prototypes. */

/*
 *
 * The function set_values() requests the user to input different
 * values to use them in the Euler's method.
 *
 * @params
 *      vars (* EQ_VARS):
            
        
 * @returns
        equation's values
*/

EXTERN EQ_VARS * set_values(EQ_VARS *vars);



#undef view_IMPORT
#undef EXTERN

#endif /* view_h */