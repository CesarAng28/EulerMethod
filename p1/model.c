//
//  model.c
//  
//
//  Created by Ulises Magaña on 09/22/20
//

#include <stdlib.h>


#define model_IMPORT
#include "model.h"


/*
 *
 * Instanciates a new file pointer identified via its name and mode.
 * @param
 *  name (char *):
 *      Name of the file
 *  mode (char *):
 *      Mode of file to be opened {r, rb, a, ab, w, wb}
 *
 * @return FILE * opened_file.
*/

FILE * new_file(char *name, char *mode) {
    FILE * my_file = NULL;
    my_file = fopen(name, mode);

    if(my_file == NULL) {
        puts("FILE OPEN ERROR");
        return NULL;
    }
    else
        return my_file;
}


/*
 *
 * The function generate_plot() gives an instruction within GNUPLOT
 * to generate a plot depending on which file is sent to this function. 
 *
 * @params
 *  name (char *):
       Name of the file
     
      
 * @returns
        void   
*/

void generate_plot(char *name) {
    FILE * new_GNUPlot_Window;
    char instruction[MAX];
    sprintf(instruction, "plot \"%s\" w l", name);

    new_GNUPlot_Window = popen("gnuplot -persist", "w");
    fprintf(new_GNUPlot_Window, "%s\n", instruction);
    // pclose(new_GNUPlot_Window);

}
