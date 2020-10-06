//
//  files.c
//  
//
//  Created by Juan Carlos Garcia on 28/09/20.
//


#include "files.h"
#include "main.h"
#include "equations.h"

/* Function imprimircpu. */
/**
 * Guarda en un archivo la informacion del tiempo que le tomo a nuestro cpu hacer los calculos de cada operacion
 * @param
 *      count (int)  
 *          Index 
 *      cpu_time (double)
 *          tiempo del cpu
 *      arch ( FILE *)
 *          apuntador al archivo que contiene la informacion de nuestro cpu
 * @return void
*/
void imprimircpu(int cont,double cpu_time, FILE * arch)
{
    fprintf(arch, "\n%d, %f", cont, cpu_time);
    
}
/**
 * Writes into a file.
 * @param
 *  arch (FILE *):
 *      Storage file
 *  count (size_t ):
 *      Index
 *  res (double):
 *      Equation result
 *
 * @return void.
*/
void imprimirres(int count, double res,FILE * arch)
{
    fprintf(arch, "\n%d, %f", count, res);
}
