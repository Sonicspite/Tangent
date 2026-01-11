#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tangent_engine.h"


int main () {
    printf("Welcome to Tangent — The powerful, easy to use terminal calculator by Sonicspite.\n");
    printf("Type \"help\" for a brief tutorial.\n");
    printf("Type \"clear\" to clear the terminal and calculator memory. \n");
    printf("Type \"commands\" for a full list of commands.\n");
    printf("Press Ctrl+C or type \"exit\" at any time to exit the calculator.\n");

    while (1) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; 

        if (strcmp(input, "help") == 0) {
            printf("\nTutorial: For basic arithmatic, just simply type the equation. Spaces in between numbers are allowed. Example: 1+1 or 1+2+3. \n");
            printf("Basic operators: \n Addition: + \n Subtraction: - \n Multiplication: * \n Division: / \n");
            printf("\n Type \"menu\" to return to main menu, or just type an equation. \n ");
        }
        else if (strcmp(input, "exit") == 0) {
            break;
        }
        else if (strcmp(input, "menu") == 0) {
            system("clear");
           printf("Welcome to Tangent — The terminal calculator by Sonicspite.\n");
           printf("Type \"help\" for a brief tutorial.\n");
           printf("Type \"clear\" to clear the terminal and calculator memory. \n");
           printf("Type \"commands\" for a full list of commands.\n");
           printf("Press Ctrl+C or type \"exit\" at any time to exit the calculator.\n"); 
        }
        else if (strcmp(input, "commands") == 0) {
            printf("\nList of commands:\n");
            printf("\n\"help\": Gives a brief tutorial on how to use Tangent. \n");
            printf("\"commands\": Gives a full list of commands.\n");
            printf("\"menu\": Takes you back to the main menu.\n");
            printf("\"exit\": Exits Tangent.\n");
            printf("\"clear\": Clears the terminal and the calculatror memory.\n");
            printf("\"preferences\": Allows you to change various settings for Tangent.\n");
            printf("\"update\": Checks the github repo for newer versions and updates Tangent.\n");
        }
        else {
            printf("Not a valid operator or command, use \"help\" for a brief tutorial.\n");
        }
    }

    return 0;
}
