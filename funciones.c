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

#include"tipo.h"

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
  float x;
  do
  {
    printf("====================================================\n");
    printf("=                       MENU                       =\n");
    printf("=1) Set values for Dt, Weight, K or cuantity       =\n");
    printf("=2) Calculate Graphic                              =\n");
    printf("=                                                  =\n");
    printf("====================================================\n");
    printf("Input an option: ");
    scanf("%f",&x);
    if((x!=1)&&(x!=2))
    {
      printf("Thats not a valid value.\n");
    }
    if(x==2)
    {
      return;
    }
    if(x == 1)
    {
      do
      {
        printf("Insert value for Dt (s):");
        scanf("%f",&datos->delta);
        if(datos->delta<=0)
        {
          printf("Value out of range (>0-infinity)\n");
        }
      }while(datos->delta<=0);
      do
      {
        printf("Introduce weight value (kg):");
        scanf("%f",&datos->masa);
        if(datos->masa<=0)
        {
          printf("Value out of range (>0-infinity)\n");
        }
      }while(datos->masa<=0);
      do
      {
        printf("Introduce value for k constant of the bongee(N/m^2):");
        scanf("%f",&datos->k);
        if(datos->k<=0)
        {
          printf("Value out of range (>0-infinity)\n");
        }
      }while(datos->k<=0);
      do
      {
        printf("Introduce how many dots are going to be calculated:");
        scanf("%d",&datos->cantDelta);
        if(datos->cantDelta<=0)
        {
          printf("Value out of range (>0-infinity)\n");
        }
      }while(datos->cantDelta<=0);//es el valor del for, quiero 15 medidas, osea de x hasta x+15deltas
    }
  }while(x!=2);
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
int CreateFile(FILE **file)
{
  *file=fopen("graphic.dat","w");
  if(*file==NULL)
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
void FillFile(FILE *file,float array[][2],DATOS *datos)
{
  int i;
  for(i=0;i<datos->cantDelta;i++)
  {
    fprintf(file,"%f, %f\n",array[i][0],array[i][1]);
  }
}

/**
*This function takes the variables and replace them in the main ecuation, solve it, and save the results in the array.
*
*@param
*   datos(DATOS *)
*   array[][](float *)
*
*/
void DesarrolloEcuacion(DATOS *datos,float array[][2])
{
  float t,n;
  int i;
  t=0;
  for (i=0; i<datos->cantDelta; i++)
  {
    if(i==0)
    {
      array[i][1]=10;
      array[i][0]= t; //time value
      array[i+1][1]=10;
    }
    if(i>=1)
    {
      array[i+1][1]=0-(array[i-1][1])*((1)+(((datos->k)*(datos->delta)*(datos->delta))/datos->masa))+(0.2)*(array[i][1])*(datos->delta)+(datos->delta)*(datos->delta)*9.81;/*agregar 0.2*/
    }
    t=t+datos->delta;
    array[i+1][0]= t; //time value
  }
}