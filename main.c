#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tangent_engine.h"

/* NOTICE: main.c is the C script for CLI interface and only the interface,
the math is done in tangent_engine.h */

int main(int argc, char *argv[])
{
    const char *CURRENT_VERSION = "0.0.2";

    // Checks for arguments
    if (argc > 1) {
        // Checks for arguments
    if (argc > 1) {
        if (strcmp(argv[1], "help") == 0) {
            printf("\nTutorial: For basic arithmatic, just simply type the equation. Spaces between numbers are allowed. Example: 1+1 or 1 + 1. When using functions with multiple inputs, spaces or commas are allowed. \n");
            
            printf("Basic operations: \n Addition: + \n Subtraction: - \n Multiplication: * \n Division: / \n");
            
            printf("Advanced functions: \n Exponentiation: ^ \n Sqaure Root: sqrt() \n Nth Root: root(n)() \n Logarithm: log() \n");     
            printf(" Natural Log: ln() \n Absolute Value: abs() \n Ceiling: ceil() \n Floor: floor() \n");
            printf(" Least Common Multiple: lcm() \n Greatest Common Factor: gcf() \n Round to Nearest Whole Number: roundw() \n Factiorial: !() \n");
            
            printf("Trigonometry: \n Sine: sin() \n Cosine: cos() \n Tangent: tan() \n Cosectant: csc() \n Sectangent: sec() \n Cotangent: cot() \n");

            printf("Statistics: \n Mean: mean() \n Median: median() \n Mode: mode() \n Minimum: min() \n Maximum: max() \n");

            printf("Constants: \n 𝑒: e \n π: pi \n 𝑖: i \n");
            
            printf("\n Type \"tngnt menu\" to go to the main menu. \n ");
            return 0;
        } 
        else if (strcmp(argv[1], "version") == 0) {
            printf("Current version installed:\nTangent v%s\n", CURRENT_VERSION);
            return 0; // Added return so it doesn't move to the menu
        } 
        else if (strcmp(argv[1], "commands") == 0) {
            printf("List of commands:\n");
            printf("\"help\", \"commands\", \"menu\", \"exit\", \"clear\", \"preferences\", \"update\", \"version\"\n");
            return 0;
        } 
        else if (strcmp(argv[1], "update") == 0) {
            // Your update logic calling the .sh script goes here
            return 0;
        } 
        else if (strcmp(argv[1], "preferences") == 0) {
            printf("Preferences command coming soon.\n");
            return 0;
        } 
        else if (strcmp(argv[1], "clear") == 0) {
            system("clear");
            return 0;
        } 
        else if (strcmp(argv[1], "exit") == 0) {
            return 0;
        }
        else if (strcmp(argv[1], "menu") == 0) {
        //Placeholder so it defaults to the full program    
        }
        
        
        else {
            // This runs if they typed an argument, but it wasn't one of the ones above
            printf("Not a valid operator or command, use \"help\" for a brief tutorial, or use \"commands\" for a list of commands.\n");
        
            return 1; 
        }
    }
    // If argc is 1 (no arguments), it lands here and starts the full program...
    }
    
        

    printf("Welcome to Tangent — The powerful, easy to use calculator engine.\n");
    printf("Type \"help\" for a brief tutorial.\n");
    printf("Type \"clear\" to clear the terminal and calculator memory. \n");
    printf("Type \"commands\" for a full list of commands.\n");
    printf("Press Ctrl+C or type \"exit\" at any time to exit Tangent.\n");

    while (1)
    {
        // Input handler
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0)
        {
            printf("\nTutorial: For basic arithmatic, just simply type the equation. Spaces between numbers are allowed. Example: 1+1 or 1 + 1. When using functions with multiple inputs, spaces or commas are allowed. \n");
            
            printf("Basic operations: \n Addition: + \n Subtraction: - \n Multiplication: * \n Division: / \n");
            
            printf("Advanced functions: \n Exponentiation: ^ \n Sqaure Root: sqrt() \n Nth Root: root(n)() \n Logarithm: log() \n");     
            printf(" Natural Log: ln() \n Absolute Value: abs() \n Ceiling: ceil() \n Floor: floor() \n");
            printf(" Least Common Multiple: lcm() \n Greatest Common Factor: gcf() \n Round to Nearest Whole Number: roundw() \n Factiorial: !() \n");
            
            printf("Trigonometry: \n Sine: sin() \n Cosine: cos() \n Tangent: tan() \n Cosectant: csc() \n Sectangent: sec() \n Cotangent: cot() \n");

            printf("Statistics: \n Mean: mean() \n Median: median() \n Mode: mode() \n Minimum: min() \n Maximum: max() \n");

            printf("Constants: \n 𝑒: e \n π: pi \n 𝑖: i \n");
            
            printf("\n Type \"tngnt\" to go to the main menu, or just type an equation. \n ");
        }
        else if (strcmp(input, "exit") == 0)
        {
            break;
        }
        else if (strcmp(input, "menu") == 0)
        {
            printf("\n-----------------------------------\n");
            printf("\nWelcome to Tangent — The powerful, easy to use calculator engine.\n");
            printf("Type \"help\" for a brief tutorial.\n");
            printf("Type \"clear\" to clear the terminal and calculator memory. \n");
            printf("Type \"commands\" for a full list of commands.\n");
            printf("Press Ctrl+C or type \"exit\" at any time to exit Tangent.\n");
        }
        else if (strcmp(input, "commands") == 0)
        {
            printf("\nList of commands:\n");
            printf("\n\"help\": Gives a brief tutorial on how to use Tangent. \n");
            printf("\"commands\": Gives a full list of commands.\n");
            printf("\"menu\": Takes you back to the main menu.\n");
            printf("\"exit\": Exits Tangent.\n");
            printf("\"clear\": Clears the terminal and the calculatror memory.\n");
            printf("\"preferences\": Allows you to change various settings for Tangent.\n");
            printf("\"update\": Checks for new versions of Tangent.\n");
            printf("\"version\": Says what version of Tangent is installed.\n");
        }
        else if (strcmp(input, "version") == 0)
        {
            printf("\nCurrent version installed:\n");
            printf("Tangent v%s\n", CURRENT_VERSION);
        }
        else if (strcmp(input, "clear") == 0)
        {
            system("clear");
            printf("Type an equation or command:");
        }
        else if (strcmp(input, "preferences") == 0)
        {
            // TODO: Make these work
        }
        else if (strcmp(input, "update") == 0)
        {
            // TODO: Make these work
        }
        else
        {
            printf("Not a valid operator or command, use \"help\" for a brief tutorial, or use \"commands\" for a list of commands.\n");
        }
    }
    return 0;
}