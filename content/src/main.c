#include <errno.h>
#include "raylib.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * An argument parser that holds the typical inputs of the program
 * @param type name: Desc
 * @param int h, The help menu
 * @param int d, The default values of the script
 */
typedef struct cmd{
    int h;
    int d;
    char *output;
} cmd;

/**
 * Parses the command line arguments
 * @param argc: The count of the arguments
 * @param argv: The argument vector
 * @return cmd: A structure with the command flags and values
 * Contains:
 *    h 0, "Prints a usage message"
 *    d 0, "Prints default values for the command line arguments"
 *    output ../figures/, "The output directory"
 */
cmd liner(const int argc, char *argv[])
{
    char *desc = "A population simulator using the Weighted Relative Abundance Criterion.\n";
    // You need to change the size if the arguments change
    char *usage[3][2] = {
        {"-h 0", "Prints a usage message"},
        {"-d 0", "Prints default values for the command line arguments"},
        {"-output ../figures/", "The output directory"},
    };
    struct cmd defaults = {
        .h = 0, // This is false default
        .d = 0,
        .output = strdup("../figures/"),
    };
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "-h") == 0) {
            printf("%s\n", desc);
            printf("Usage:\n");
            // You need to change the loop size if the arguments change
            for (int j = 0; j < 3; j++) {
                printf("    %s %s\n", usage[j][0], usage[j][1]);
            };
            printf("\nExiting\n");
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(argv[i], "-output") == 0) {
            defaults.output = strdup(argv[i + 1]);
        }
    }
    return defaults;
};

/**
 * Frees allocated memory in a cmd instance
 * May or may not be required overall but the archetype is here
 * @param cmd *c, The cmd instance to free memory for
 * @return void
 */
void cmdDestructor(cmd *c) {
    free(c->output);
};

/**
 * Draw a plot of metrics
 * @return void
 */
void plot() {
    InitWindow(800, 600, "test");
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GetColor(0x181818FF));
        EndDrawing();
    }
    CloseWindow();
};

int main(int argc, char *argv[])
{
    cmd status = liner(argc, argv);
    cmdDestructor(&status);
    if (errno != 0) {
        printf("Exist status: %i\n", errno);
        perror("Reason");
    }
    return errno;
};
