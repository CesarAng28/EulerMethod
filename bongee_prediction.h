//
//  bongee_prediction.h
//  
//
//  Creado por Rodrigo Garcia el 25 de septiembre del 2020.
//

#ifndef bongee_prediction_h
#define bongee_prediction_h


/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <stdlib.h>

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef bongee_prediction_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Types declarations. */


/* Global variables declarations. */
#define COLUMNS 2


/* Function prototypes. */


/*
 *
 * La funcion vista_Menu proporciona al usuario un menu con la bienvenida y la forma de operar del sistema.
 * Pedira los datos y las mandara a la siguiente funcion del proceso.
 *
 * @params
 *      void
        
 * @returns
        entero que confirma si se repetira el proceso o no
*/


EXTERN int vista_Menu(void);


/*
 *
 * La funcion vista_Resultados proporciona al usuario los resultados de su prediccion.
 * Determinara si el proceso desea repetirse.
 *
 * @params
 *      tiempo (double):
            tiempo en el futuro que se predijo
 *      muestras (double):
            muestras que se tomaron en el proceso de inferencia
 *      tiempo_choque (double):
            tiempo en el cual se genero el primer choque.
 *      chocado (int)
            variable para identificar si hubo un choque.
        
 * @returns
        entero con la confirmacion de si se debe repetir o no
*/


EXTERN int vista_Resultados(double tiempo, double muestras, double tiempo_choque, int chocado);


/*
 *
 * La funcion controlador_Proceso settea las variables y llama a los procesos dependiendo de 
 * lo que se tenga que hacer ahora.
 *
 * @params
 *     masa (int):
            valor de la masa recibida del menu
 *     k_constante (int):
            valor de la constante k del resorte
 *     tiempo (double):
            cantidad de tiempo a predecir en segundos
 *     muestras (double):
            cantidad de muestras que se tomaran entre el tiempo dado

 * @returns
        Estado para repetirse o no
*/


EXTERN int controlador_Proceso(int masa, int k_constante, double tiempo, double muestras);


/*
 *
 * La funcion modelo_Euler_Method predice la posicion de la persona en el bongee dependiendo de los valores dados
 * y la regresa al controlador para ser analizada
 *
 * @params
 *     delta_t (double):
            variable del tiempo entre muestras dentro del periodo de tiempo dado por el usuario
 *     index (int):
            indice que calculara el metodo
 *     masa (int):
            valor de la masa de la persona proporcionado por el usuario
 *     k_resorte (int):
            constante k del resorte proporcionado por el usuario 
            
 * @returns
        posicion obtenida de la prediccion en el index determinado
*/


EXTERN double modelo_Euler_Method(double delta_t,int index, long int gramos, int k_resorte);

/*
 *
 * La funcion modelo_Imprime_Archivo imprime una matriz recibida en una archivo CSV
 *
 * @params
 *     Archivo (FILE *):
            Puntero al archivo donde se imprimira la matriz
 *     columnas (size_t):
            Columnas de la matriz
 *     buffer[][columnas] (double):
            Matriz recibida para imprimir
 *     filas (size_t):
            Filas de la matriz

 * @returns
        void
*/

EXTERN void modelo_Imprime_Archivo(FILE * Archivo, size_t columnas, double buffer[] [columnas], size_t filas);


/*
 * La funcion modelo_Nuevo_Archivo instacia un apuntador a un archivo nuevo
 *
 * @param
 *  nombre_archivo (char *):
        Nombre del archivo
 *  modo (char *):
        Modo en que sera abierto el archivo {r, rb, a, ab, w, wb}

 * @return 
        apuntador al archivo abierto.
*/

EXTERN FILE * modelo_Nuevo_Archivo(char *nombre_archivo, char *modo);


/*
 *
 * The function copy_test copies the data from a array_manager_static_memory structure using array_manager_copy
 *
 * @params
 *      memory_used (size_t):
            Amount of memory that we need allocate.
        
 * @returns
        void
*/

//EXTERN void copy_test (size_t memory_used, array_manager_static_memory * memory);

/*
 *
 * The function array_manager_static_link joins two memory elements for them to be accessed sequentially
 *
 * @params
 *     memory1 (* array_manager_static_memory):
            Amount of memory in bytes of the copied buffer
 *     memory2 (* array_manager_static_memory):
            Memory address of the buffer


 * @returns
        ____ defined by you
*/

//EXTERN ____ array_manager_static_link(array_manager_static_memory * memory1, array_manager_static_memory * memory2);


#undef bongee_preditcion_IMPORT
#undef EXTERN



#endif /* bongee_prediction_h */
