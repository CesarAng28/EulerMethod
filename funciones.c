//
//  funciones.c
//  
//
//  Created by Castro Bouquet Ildefonso on 27/09/2020.
//  Created by Venegas Ramirez Giovanni Josue on 27/09/2020.
//

/* Libraries */
#include<stdio.h>
#include<stdlib.h>

/* funciones.c -- Functions */

/**
*This function generates a menu for the program, asking if user wants to set values or use the predetermined.
*
*@param
*   datos(DATOS *)
*
*/
void menu(DATOS *datos)
{
  do
  {
    printf("=======================================================\n");
    printf("=                         MENU                        =\n");
    printf("=1) Desea introducir valores para las variables?      =\n");
    printf("=2) Calcular grafica                                  =\n");
    printf("=======================================================\n");
    printf("Introduzca una opcion: ",x);
    if((x!=1)&&(x!=2))
    {
      printf("Introduzca una opcion valida.\n");
    }
    if(x==2)
    {
      return;
    }
    if(x == 1)
    {
      do
      {
        printf("Introduzca el valor de la diferencia de tiempo (DeltaT):");
        scanf("%f",datos.tiempo);
      }while(datos.tiempo<=0);
      do
      {
        printf("Introduzca el valor de la Masa (m):");
        scanf("%f",datos.masa);
      }while(datos.tiempo<=0);
      do
      {
        printf("Introduzca el valor de la constante del bongee(k):");
        scanf("%f",datos.k);
      }while(datos.k<=0);
      do
      {
        printf("Introduzca la cantidad de valores a calcular para Delta:");
        scanf("%d",datos.cantDelta);
      }while(datos.cantDelta<=0);//es el valor del for, quiero 15 medidas, osea de x hasta x+15deltas
    }
  }
}

/**
*This function creates a file and saves the location on a variable.
*
*@param
*   file(FILE *)
*@returns
*   0 if cant create a file
*   1 if file had been created corretly
*/
int CreateFile(FILE *file)
{
  file=fopen("grafica.txt","w");
  if(file==Null)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

/**
*This function takes the array and print the information from it to the file.
*
*@param
*   files(FILE *)
*   array[][](float *)
*   
*/
void FillFile(FILE *file,float array[][])
{
  fprintf(file,"",array);
}

/**
*This function takes the variables and replace them in the main ecuation, solve it, and save the results in the array.
*
*@param
*   datos(DATOS *)
*   array[][](float *)
*
*/
void DesarrolloEcuacion(DATOS *datos,float array[][])
{
  float xinicial=10;
  float valorx;
  float x0=xinicial, x1= xinicial;
  float x2; //nos dicen x(t), x(t+delta) y x(t+2delta)
  float t=0; //vamos de cero y se le va sumando delta
  int i;
  for (i=0; i<15; i++)
  {
    x2= Calcular (x0,x1);//metemos x(t) y x(t+delta)
    array[i][0]= t; //valor del tiempo
    array[i][1]= x0; //posicion en ese tiempo
    t= t+datos.tiempo;
    x0=x1;
    x1=x2
  }
}

/**
*This function takes the variables and replace them in the main ecuation, solve it, and save the results in the array.
*
*@param
*   x0(float *)
*   x1(float *)
*@return
*   x2(float *)
*
*/
float Calcular (float x0,float x1)
{
  float x2;
  x2= x0+x1 //aqui va la formulota
  return x2;
}