//
//  equations.h
//
//
//  Created by David Perez on 28/09/2020.
//

#ifndef equations_h
#define equations_h


/*
 * System headers required by the following declarations
 * (the implementation will import its specific dependencies):
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * Application specific headers required by the following declarations
 * (the implementation will import its specific dependencies):
 */

/* Constants declarations. */
#define GRAVEDAD 9.81
#define DT 0.001
/* Set EXTERN macro: */

#ifndef equations_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif

/* Types declarations. */

/* Global variables declarations. */


/* Function prototypes. */


/*
 *
 * La funcion equations_fuezas calcula la fuerza externa
 *
 * @params
 *      masa (double):
 * masa proporcionada por el usuario dado por el usuario 
 *      Dt(double); 
 *   diferencia de tiempo
 *    K (double):
 *  Constante del bongee
.*     xt (double)
 *   posicion 2 segundos atras atras

 * @returns
  int
*/


EXTERN double equations_fuerzas(double masa, double Dt, double K, double xt);
/*
 *
 * La funcion equiations_grav regresa el valor de la graverdad por 
 * el cuadrado de la diferencial del tiempo. 
 *
 * @params
 *      
 *    Dt(double);
 *   diferencial del tiempo

 * @returns
 int.
*/


EXTERN double equations_grav(double Dt);

/*
 *
 * La funcion equ regresa el valor de la posicion que 
 * necesita el usuario
 *
 * @params
 *      K (double);
 *  contante de elasticidad del bongee
 *      masa (double);
 *   masa de la persona que esta cayendo
 *      t (double);
 *   tiempo de donde se quirere sacar la posicion
 *      xt (double)
 *   posicion anterior
 *      xt2 (double)
 *    hace 2 posiciones
 * @returns
 *  double
*/


EXTERN double equ(double K, double masa, double t, double xt, double xt2);

#undef equations_IMPORT
#undef EXTERN
#endif /* equiations_h */
