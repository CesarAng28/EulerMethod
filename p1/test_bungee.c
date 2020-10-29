//
//  test_bungee.c
//  
//
//  Created by Ulises Magaña on 09/22/20
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include "model.h"
#include "view.h"
#include "controller.h"
#include "test_bungee.h"


int main(void) {
    
    int flag = 0, file_number;
    char option[MAXCHAR], file_name[MAXCHAR];
    FILE *record = NULL, *file_counter = NULL;
    EQ_VARS *vars = NULL;

    file_counter = new_file("NumberOfFiles.txt", "r");
    fscanf(file_counter, "%d", &file_number);
    fclose(file_counter);
    file_number += 1;

    system("clear");
    puts("\t\t\tWELCOME TO THE BUNGEE JUMPING GAME\n");

    do {
        
        sprintf(file_name, "BUNGEE_FILE_%d.CSV", file_number);

        record = new_file(file_name, "w");
        vars = malloc(sizeof(EQ_VARS));

        set_values(vars);
        predict_trajectory(vars, record);
        generate_plot(file_name);

        free(vars);
        fclose(record);

        puts("Do you want to play again?");
        puts("[y] [n]");
        printf("Select an option--> ");
        scanf(" %[^\n]", option);
        
        if(strcmp(option, "N") == 0 || strcmp(option, "n") == 0) {
            flag = 1;
        }

        file_number++;

    } while(flag == 0);
    
    return 0;
}