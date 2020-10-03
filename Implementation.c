//
//  Implementation.c
//
//
//  Created by Team 3.
//
/**
* Our sample program.
* @copyright 2020 by TDA
* @license as you wish
* @author Team 3.
* @version 2020-09-30
* @file
*/


/* Include standard headers: */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Include modules header we directly invoke here: */
#include "Euler.h"
#include "Files.h"

/*Constants*/
const double g = 9.81;

/*Tentativo*/
//start=clock ();
//<stop = clock ();
//time = ((double)(stop-start))/CLOCKS_PER_SEC;
//printf("time: %f\n",time*1e9);
/*Fin de codigo tentativo*/

int main(int argc, char **argv)
{
    /* Initialize modules: */
    float k,m,position1,position2,position3,dt,time,t;
    
    conditions *first = NULL;
    //clock_t start,stop;
    FILE *fp;

    euler_menu (&k,&m,&position1,&position2,&dt,&t);

    for (float i = 0; i <= t;) {

      position3 = euler_form (k,m,g,position1,position2,dt);

      if (i < (2*dt)) {
        euler_print (position1, i);
        euler_list (position1,&first,i);

        euler_print (position2, i+dt);
        euler_list (position2,&first,i+dt);

        euler_print (position3, i+(2*dt));
        euler_list (position3,&first,i+(2*dt));
        i=i+(2*dt);
      }
      else{
        euler_print (position3,i);
        euler_list (position3,&first,i);
      }
      position1=position2;
      position2=position3;
      i=i+dt;
    }

    fp=file_new ("datos.csv","wt");
    file_write (fp,first);
    gnuplot ();

    euler_free (first);


    return 0;
}
