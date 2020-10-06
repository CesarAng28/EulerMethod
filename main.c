//
//  main.c
//  
//
//  Created by Juan Carlos Garcia on 28/09/20.
//

#include "main.h"
#include "equations.h"
#include "files.h"



int main(void){
    FILE * arch1, * arch2;
    double tiempo,k,masa,cpu_time,resultado[100000], ant1=0, ant2=0;
    int cont;
    float t;
    clock_t start, stop;
    
    arch1 = fopen("tiempoCPU.csv","w");
    arch2 = fopen("resultados.csv","w");
    
    printf("Calculadora de bongee");
    printf("\nCual es la masa del usuario? (kg)\n");
    scanf("%lf",&masa);
    printf("\nCual es el tiempo de la caida? (s)\n");
    scanf("%lf",&tiempo);
    printf("\nCual es el constante de bongee? (N/m)\n");
    scanf("%lf",&k);
    
    
    for(cont = 0; cont <= tiempo *(1/DT); cont ++){
        t = (float)cont * DT;
        start = clock();
        resultado[cont] = equ(k,masa,t, ant1, ant2);
        stop = clock();
        cpu_time = (stop-start)*1e3 ;
        ant2=ant1;
        ant1 = resultado[cont];
        
        imprimircpu(cont,cpu_time,arch1);
        imprimirres(cont, resultado[cont],arch2);
    }
    fclose(arch1);
    fclose(arch2);
    return 0;
}
