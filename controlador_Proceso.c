#include"bongee_prediction.h"

#define COLUMNAS 2
#define INDEX 0
#define POSICION 1

#define ARCHIVO "BONGEE.CSV"

int controlador_Proceso(double masa, int k_constante,double tiempo, double muestras)
{
  int muestras_entero,index, chocado=0, muestra_choque, repetir;
  double delta_t, posicion_en_index, inicio = 10;
  long int gramos;

  FILE * Archivo = NULL;
  
  
  muestras_entero = (int) muestras;

  double matriz_datos[muestras_entero][COLUMNAS];

  Archivo = modelo_Nuevo_Archivo(ARCHIVO,"w");
 

  delta_t = tiempo/muestras;
  gramos = masa*1000;
  

  system("clear");

  //printf("%d kg\t%d N/m\t%.3lf delta t\n\n",masa, k_constante,delta_t);

  for(index = 0;index < muestras_entero;index++)
  {
    posicion_en_index = modelo_Euler_Method(delta_t,index,masa,k_constante);

    //printf("\n\nPosicion en muestra %d = %.3lf",index,posicion_en_index);

    matriz_datos[index][INDEX] = index;
    matriz_datos[index][POSICION] = posicion_en_index;

    if(posicion_en_index < inicio && index != 0)
    {
      chocado = 1;
      muestra_choque = index;
    }
  }

  modelo_Imprime_Archivo(Archivo,COLUMNAS,matriz_datos,muestras);

  fclose(Archivo);


  //Llamada a la funcion que genera el plot
  modelo_Grafica(ARCHIVO);

  repetir = vista_Resultados(tiempo,muestras,muestra_choque*delta_t,chocado);

  if(repetir == 1)
  {
    return 1;
  }

  else
  {
    return 0;
  }

}
