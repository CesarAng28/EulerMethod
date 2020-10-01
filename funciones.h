//
//  funciones.h
//  
//
//  Created by Castro Bouquet Ildefonso on 27/09/2020.
//  Created by Venegas Ramirez Giovanni Josue on 27/09/2020.
//
#ifndef funciones_h
#define funciones_h

#include <stdio.h>

#ifdef funciones_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* funciones.h -- Function prototypes */

/**
*This function generates a menu for the program, asking if user wants to set values or use the predetermined.
*
*@param
*   datos(DATOS *)
*
*/
EXTERN void menu(DATOS *datos);

/**
*This function creates a file and saves the location on a variable.
*
*@param
*   file(FILE *)
*@returns
*   0 if cant create a file
*   1 if file had been created corretly
*/
EXTERN int CreateFile(FILE **file);

/**
*This function takes the array and print the information from it to the file.
*
*@param
*   files(FILE *)
*   array[][](float *)
*   
*/
EXTERN void FillFile(FILE *file,float array[][2],DATOS *datos);

/**
*This function takes the variables and replace them in the main ecuation, solve it, and save the results in the array.
*
*@param
*   datos(DATOS *)
*   array[][](float *)
*
*/
EXTERN void DesarrolloEcuacion(DATOS *datos,float array[][2]);


#undef funciones_IMPORT
#undef EXTERN

#endif /* funciones_h */
