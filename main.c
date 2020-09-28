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
#include"funciones.c"

/* Main */
int main(void)
{
  FILE *file;
  DATOS datos;
  datos.tiempo=5;
  datos.masa=60;
  datos.k=500;
  float array[][];//dos dimensiones
  menu(&datos);
  DesarrolloEcuacion(&datos,&array);
  i=CreateFile(&file);
  if(i==0)
    {
      printf("ERROR File couldnt me created\n");
      exit(1);
    }
  FillFile(&file,array);
  if(i==1)
  {
    fclose(file);
  }
}