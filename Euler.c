#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Euler.h"

int euler_menu (float *k, float *m, float *position1, float *position2, float *dt, float *t){

  int opcion;
  do{
    printf("Calculo de salto bungee con método de Euler.\n\n");
    printf ("Bienvenido. Favor de ingresar los datos.\n");
    printf("1. Ingresar la constante del Bongee (k): \n");
    printf("2. Ingresar la masa de la persona (m): \n");
    printf("3. Ingresar la posicion inicial (Xo): \n");  
    printf("4. Ingresar la diferencia de tiempo (dt): \n");    
    printf("5. Ingresar el tiempo a medir (t): \n");
    printf("6. Calcular y salir. (Es necesario ingresar primero todos los datos)\n");
    printf("7. Salir.\n");
    printf("Opcion: ");
    scanf ("%d", &opcion);
  
    switch (opcion){
    case 1:
      printf("k = ");
      scanf("%f",k);
      break;
    case 2:
      printf("m = ");
      scanf("%f",m);	
      break;
    case 3:
      printf("Xo = ");
      scanf("%f",position1);
      *position2 = *position1;
      break;
    case 4:
      printf("dt = ");
      scanf("%f",dt);
      printf("Regresar? [S/*] ");
      break;
    case 5:
      printf("t = ");
      scanf("%f",t);
      break;
    case 7:
      printf("Saliendo...\n");
      exit(1);
      break;
    default:
      if(opcion != 6)
	printf("Opcion invalida.\n");
      break;
    }//switch
    
  }while (opcion != 6);
  return 0;
}

void euler_print (float position, float time)
{
  printf("position: %f\t",position);
  printf("time: %f\n",time);
}

float euler_form (float k, float m, const double g, float position1, float position2, float dt){
  float position;
  float p1 = (-1*position1)*(1+((k*(dt*dt))/m));
  float p2 = 2 * position2;
  float p3 = (dt*dt)*g;
  position=p1+p2+p3;
  return position;
}

int euler_list (float position, conditions **first, float time){
  conditions *node, *aux;
  node= (conditions*) malloc (sizeof (conditions));
  if (node==NULL){
    printf ("No se asigno el espacio en memoria.\n");
    exit (0);
  }
  node->position=position;
  node->time = time;
  node->sig=NULL;

  if (*first==NULL){
    *first=node;
  }
  else{
    aux = *first;
    while (aux->sig != NULL)
      aux = aux->sig;
    aux->sig = node;
  }
  return 0;
}

int euler_free (conditions *first){
  conditions *aux;
  aux=first;
  while (aux != NULL){
    first=first->sig;
    free (aux);
    aux=first;
  }
  return 0;
}
