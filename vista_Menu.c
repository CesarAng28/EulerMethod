#include"bongee_prediction.h"

int vista_Menu(void)
{
  int masa, k_resorte, repetir;
  double tiempo_a_calcular,muestras;

  system("clear");

  printf("\n\n\tMetodo de Euler para inferencia de salto en bongee\n\n");
  printf("\n\nEl sistema le permitira determinar si es seguro saltar prediciendo la trayectoria de oscilacion del resorte\nmediante el metodo de Euler\n\nSi en algun momento la persona atada golpea el suelo, se avisara en pantalla.");
  printf("\n\nPresiona ENTER para continuar...");
  __fpurge(stdin);
  getchar();

  system("clear");

  printf("\n\nIngrese la masa de la persona (kg):");
  scanf("%d",&masa);

  printf("\n\nIngrese la constante 'k' del resorte (N/m):");
  scanf("%d",&k_resorte);

  printf("\n\nIngrese cuanto tiempo en el futuro desea predecir (seg):");
  scanf("%lf",&tiempo_a_calcular);

  printf("\n\nIngrese la cantidad de muestras que desea tomar en ese intervalo de tiempo:");
  scanf("%lf",&muestras);

  repetir = controlador_Proceso(masa,k_resorte,tiempo_a_calcular,muestras);

  if(repetir == 1)
  {
    return 1;
  }

  else
  {
    return 0;
  }
}
