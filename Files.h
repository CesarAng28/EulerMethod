//
//  Files.h
//
//
//  Created by Team 3.
//

#ifndef Files_h
#define Files_h

#include <stdio.h>
#include <stdlib.h>

#include "Euler.h"

#ifdef Files_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Files.h -- Function prototypes */

/**
 * Instanciates a new file pointer identified via its name and mode.
 * @param
 *  name (char *):
 *      Name of the file
 *  mode (char *):
 *      Mode of file to be opened {r, rb, a, ab, w, wb}
 *
 * @return FILE * opened_file.
*/
EXTERN FILE * file_new(char *name, char *mode);



/**
 * Writes a dynamic list into a file.
 * @param
 *  file (FILE *):
 *      Storage file
 *  first (conditions):
 *      The first node of the dynamic list
 *  aux (conditions):
 *      The auxiliary of the dynamic list
 *  node (conditions):
 *      The actual node of the dynamic list
 *
 * @return void.
*/
EXTERN void file_write(FILE * file, conditions *first);

/**
 * Opens a gnuplot instance to graphicate the data from a file.
 * @param
 *  name (char *):
 *      Name of the file
 *
 * @return void.
*/
EXTERN void gnuplot ();

#undef files_IMPORT
#undef EXTERN



#endif /* Files_h */
