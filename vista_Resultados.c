#include"bongee_prediction.h"

int vista_Resultados(double tiempo, double muestras, double tiempo_choque, int chocado)
{
  int repetir;
  
  printf("\n\n\t Se ha creado el archivo!\n\n");

  printf("\n\nSe infirio un periodo de: %.0lf segundos.\n",tiempo);
  printf("Se tomaron un total de:%.0lf muestras.\n",muestras);
  printf("¿La persona chocara? ");

  if(chocado == 1)
  {
    printf("Si\n");
    printf("Chocara por primera vez a un tiempo de %.2lf segundos del inicio.\n\n",tiempo_choque);
  }

  else
  {
    printf("No\n\n");
  }

  printf("¿Desea predecir de nuevo con otros datos? 1-SI 0-NO\n\n");
  printf("Opcion: ");
  scanf("%d",&repetir);

  if(repetir == 1)
  {
    return 1;
  }

  else
  {
    return 0;
  }
}
