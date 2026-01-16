#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tangent_engine.h"

// Global Variables
int is_loop;
int precision = 2;
int use_degrees = 1;
int logging_enabled = 0;

// Defines functions
void welcometxt () {
    printf("-----------------------------------\n");
    printf("Welcome to Tangent — The powerful, easy to use calculator engine.\n");
    printf("Type \"help\" for a brief tutorial.\n");
    printf("Type \"clear\" to clear the terminal and calculator memory. \n");
    printf("Type \"commands\" for a full list of commands.\n");
    printf("Press Ctrl+C or type \"exit\" at any time to exit Tangent.\n");
}

void save_settings() {
    FILE *f = fopen("/usr/local/bin/tgnt_save.txt", "w");
    if (f != NULL) {
        fprintf(f, "%d\n%d\n%d", logging_enabled, precision, use_degrees);
        fclose(f);
    }
}

void load_settings() {
    FILE *f = fopen("/usr/local/bin/tgnt_save.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d\n%d\n%d", &logging_enabled, &precision, &use_degrees);
        fclose(f);
    }
}
// Input/command handler
void handle_input(char *input) {
    if (strcmp(input, "help") == 0) {
        printf("-----------------------------------\n");
        printf("\nTutorial: For basic arithmetic, just simply type the equation. Spaces between numbers are allowed. Example: 1+1 or 1 + 1. When using functions with multiple inputs, spaces or commas are allowed. \n");
        printf("Basic operations: \n Addition: + \n Subtraction: - \n Multiplication: * \n Division: / \n");
        printf("Advanced functions: \n Exponentiation: ^ \n Sqaure Root: sqrt() \n Nth Root: root(n)() \n Logarithm: log() \n");     
        printf(" Natural Log: ln() \n Absolute Value: abs() \n Ceiling: ceil() \n Floor: floor() \n");
        printf(" Least Common Multiple: lcm() \n Greatest Common Factor: gcf() \n Round to Nearest Whole Number: roundw() \n Factiorial: !() \n");
        printf("Trigonometry: \n Sine: sin() \n Cosine: cos() \n Tangent: tan() \n Cosectant: csc() \n Sectangent: sec() \n Cotangent: cot() \n");
        printf("Statistics: \n Mean: mean() \n Median: median() \n Mode: mode() \n Minimum: min() \n Maximum: max() \n");
        printf("Constants: \n e: e \n π: pi \n i: i \n");
        
        if (is_loop == 0) {
            printf("\n Type \"tgnt menu\" to go to the main menu. \n ");
        }
        else {
            printf("\n Type \"menu\" to go to the main menu. \n ");
        }
    } 
    else if (strcmp(input, "version") == 0) {
        printf("Current version installed:\n");
        printf("Tangent v0.0.3 (stable) \n");
    } 
    else if (strcmp(input, "clear") == 0) {
        system("clear");
        printf("Type an equation or command:");
    } 
    else if (strcmp(input, "commands") == 0) {
        printf("-----------------------------------\n");
        printf("List of commands:\n");
        printf("\n\"help\": Gives a brief tutorial on how to use Tangent. \n");
        printf("\"commands\": Gives a full list of commands.\n");
        printf("\"menu\": Takes you back to the main menu.\n");
        printf("\"exit\": Exits Tangent.\n");
        printf("\"clear\": Clears the terminal and the calculatror memory.\n");
        printf("\"settings\": Allows you to change various settings for Tangent.\n");
        printf("\"update\": Checks for new versions of Tangent.\n");
        printf("\"version\": Says what version of Tangent is installed.\n");
        printf("\"uninstall\": Uninstalls Tangent.\n");
    } 
    else if (strcmp(input, "update") == 0) {
        system("sh /usr/local/bin/tgnt_update.sh");
    } 
    else if (strcmp(input, "uninstall") == 0) {
        system("sudo sh /usr/local/bin/tgnt_uninstall.sh");
        return 0;
    } 
    else if (strcmp(input, "exit") == 0) {
        exit(0); 
    } 
    else if (strcmp(input, "menu") == 0) {
        welcometxt();
    } 
    else if (strcmp(input, "settings") == 0) {
        printf("\n--- Tangent Settings ---\n");
        printf("1. Equation logging: [%s]\n", logging_enabled ? "ON" : "OFF");
        printf("2. Math Precision:   [%d decimal places]\n", precision);
        printf("3. Angle Mode:       [%s]\n", use_degrees ? "Degrees" : "Radians");
        printf("4. Clear Logs\n");
        printf("5. Reset settings to Default\n");
        printf("6. Back\n> ");

        char choice[10];
        fgets(choice, sizeof(choice), stdin);
        int opt = atoi(choice);

        if (opt == 1) {
            logging_enabled = !logging_enabled;
            save_settings();
            printf("Logging is now %s.\n", logging_enabled ? "enabled" : "disabled");
        }
        else if (opt == 2) {
            printf("Enter precision (0-10): ");
            fgets(choice, sizeof(choice), stdin);
            precision = atoi(choice);
            save_settings();
            printf("Precision set to %d.\n", precision);
        }
        else if (opt == 3) {
            use_degrees = !use_degrees;
            save_settings();
            printf("Mode changed to %s.\n", use_degrees ? "Degrees" : "Radians");
        }
        else if (opt == 4) {
            FILE *f = fopen("/usr/local/bin/tgnt_logs.txt", "w");
            if (f != NULL) { fclose(f); printf("Logs wiped.\n"); }
        }
        else if (opt == 5) {
            logging_enabled = 0; 
            precision = 2;
            use_degrees = 1;
            save_settings();
            printf("Settings reset.\n");
        }
    }
    else {
        printf("Not a valid operator or command, use \"help\" for a brief tutorial, or use \"commands\" for a list of commands.\n");
    }
}
// Main script
int main(int argc, char *argv[]) {
    load_settings();
    if (argc > 1) {
        is_loop = 0; 
        handle_input(argv[1]);
        return 0;
    }

    is_loop = 1; 
    welcometxt();

    char user_input[100];
    while (1) {
        printf("\ntgnt > ");
        if (!fgets(user_input, sizeof(user_input), stdin)) break;
        user_input[strcspn(user_input, "\n")] = 0;

        handle_input(user_input);
    }
    return 0;
}