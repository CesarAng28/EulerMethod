#include"bongee_prediction.h"

FILE * modelo_Nuevo_Archivo(char * nombre_archivo, char * modo)
{
  FILE * file;

  file = fopen(nombre_archivo,modo);

  return file;
}

void modelo_Imprime_Archivo(FILE * Archivo, size_t columnas, double buffer[] [columnas], size_t filas)
{
  int count_rows,count_columns=0;
  
  for(count_rows = 0;count_rows < filas;count_rows++)
  {
    fprintf(Archivo,"%.0lf ",buffer[count_rows][count_columns]);
    count_columns++;
    fprintf(Archivo,"%.3lf",buffer[count_rows][count_columns]);

    count_columns=0;
    
    fprintf(Archivo,"\n");
  }
}
