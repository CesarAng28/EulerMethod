#include"bongee_prediction.h"

#define NUM_COMMANDS 2

void modelo_Grafica (char * nombre_archivo)
{
  char * commandsForGnuplot[] = {"set title \"Prediccion de bongee\"","plot 'BONGEE.CSV' u 1:2 t 'Trayectoria'"};
  FILE * gnuplotPipe = NULL;

  gnuplotPipe = popen("gnuplot -persistent","w");
  
  //Para general el plot
  for(int i = 0;i < NUM_COMMANDS;i++)
  {
    fprintf(gnuplotPipe,"%s \n",commandsForGnuplot[i]);
  }

  pclose(gnuplotPipe);

}
