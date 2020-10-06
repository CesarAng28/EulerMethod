//
//  files.h
//  
//
//  Created by Juan Carlos Garcia on 28/09/20.
//

#ifndef files_h
#define files_h

#include <stdio.h>


#ifndef files_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/*Imprime los datos a un archivo tipo .csv donde cada dato está en una celula diferente
 * @params
 *  FILE * arch1 & arch2
 *      archivos .csv a donde se van a escribir los datos
 *  int cont
 *      numero contador que indica cuantas veces se ha repetido el programa
 *  double res & cpu_time
 *      resultados de la ecuacion y en cuanto tiempo se calculó
 * @return void
 */

EXTERN void imprimircpu(int cont,double cpu_time, FILE * arch);

EXTERN void imprimirres(int count, double res,FILE * arch);

#endif /* files_h */
