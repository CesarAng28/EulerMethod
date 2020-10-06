
//  equations.c
//
//
//  Created by David Perez on 29/09/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "equations.h"
#include "main.h"
#include "files.h"

/**
 * Obtiene el resultado de la ecuacion de las fuerzas del sistema.
 * @param
 *  masa (double):
 *      La masa del usuario en Kg. 
 *  Dt (double ):
 *      nuestra constante de cambio
 *  k (double):
 *      la constante de nuestro bungee
 *
 * @return double.
*/
double equations_fuerzas(double masa, double Dt, double K, double xt)
{
  double res, BT = 10;
  res=(-xt * (((K * (Dt * Dt))/masa)+1-((BT*DT)/masa)));
    //-x(t)*(1+((K Dt^2)/masa))
  return res;
}

/**
 * Obtiene el resultado de la gravedad por nuestra constante de cambio.
 * @param
 *  Dt (double ):
 *      nuestra constante de cambio
 * @return double.
*/
double equations_grav(double Dt)
{
  return ((Dt * Dt) * GRAVEDAD);
}

/**
 * Obtiene el resultado nuestro sistema.
 * @param
 *  masa (double):
 *      La masa del usuario en Kg. 
 *  t (double ):
 *      el tiempo del movimiento
 *  k (double):
 *      la constante de nuestro bungee
 *  xt (double):
 *      el movimiento anterior
 *  xt2 (double):
 *      dos movimientos antes. 
 * 
 * @return double.
*/
double equ(double K, double masa, double t, double xt, double xt2)
{
  double res, eq1, eq2, eq3, BT = 10;
  if(t==0 || t<=(DT+0.01))
    return 10;
  else
    {
      eq1=equations_fuerzas(masa,DT, K,xt2);
      eq2=(2-(BT*DT)/masa)*xt;
      eq3=equations_grav(DT);
      res=eq1+eq2+eq3;
      return res;
    }
}

