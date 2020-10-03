//
//  main.c
//  
//
//  Created by Castro Bouquet Ildefonso on 27/09/2020.
//  Created by Venegas Ramirez Giovanni Josue on 27/09/2020.
//

/* Libraries */
#include<stdio.h>
#include<stdlib.h>

/* Custom Libraries */
#include"tipo.h"
#include"funciones.h"

/* Main */
int main(void)
{
  system("clear");
  int i;
  FILE *file,*gnu_socket;
  DATOS datos;
  /*Predetermined values, set by the problem, can be changed from menu function*/
  datos.delta=0.1;
  datos.masa=60;
  datos.k=500;
  datos.cantDelta=100;
  /**/
  menu(&datos);
  float array[datos.cantDelta][2];
  DesarrolloEcuacion(&datos,array);
  i=CreateFile(&file);
  if(i==0)/*Validate if file cant be created*/
    {
      printf("ERROR File couldnt me created\n");
      exit(1);
    }
  FillFile(file,array,&datos);
  if(i==1)
  {
    fclose(file);
  }
  char *nombre="graphic";
  gnu_socket=popen("gnuplot -persist","w");
  fprintf(gnu_socket,"plot \"%s.dat\" using 1:2 with lines\n",nombre);/*Command for calling gnuplot internally*/
  pclose(gnu_socket);
  /*for(i=0;i<datos.cantDelta;i++)
  {
    printf("%f, %f\n",array[i][0],array[i][1]);
  }*/
}