#include <stdio.h>
#include <stdlib.h>

#include "Euler.h"

FILE * file_new(char *name, char *mode){
  FILE *fp;
  fp = fopen (name, mode);
  return fp;
}

void file_write(FILE * fp, conditions *first){
  conditions *node;
  node=first;
  while (node != NULL){
    fprintf(fp, "%f,",node->position);
    fprintf(fp, "%f\n",node->time);
    node = node->sig;
  }
  fclose (fp);
}

void gnuplot () {
  int i;
  char *labels[] = {"set title \"Movimiento\"",
        "set ylabel \"Posicion(x)\"",
        "set xlabel \"Tiempo(t)\"",
        "set grid",
        "set datafile separator','",
        "set terminal png",
        "set output 'Posicion VS Tiempo.png'",
        "plot \"datos.csv\" with lines"};
  FILE *VentanaGnuPlot = popen ("gnuplot -persist", "w");
  for (i=0; i<8; i++)
    fprintf(VentanaGnuPlot, "%s \n", labels[i]);
  pclose (VentanaGnuPlot);
}
