#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "waves.h"

/* main: runs the draw_waves program with specified side_length 
  and center offsets */
int main(int argc, char *argv[])
{   
    unsigned int i;
    int side_length = 200, x_offset = 0, y_offset = 0;    
    double scale_r = 1.0, scale_g = 1.0, scale_b = 1.0;
    for (i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "-s") == 0) {
            side_length = atoi(argv[i+1]);
        } else if (strcmp(argv[i], "-r") == 0) {
            scale_r = atof(argv[i+1]);
        } else if (strcmp(argv[i], "-g") == 0) {
            scale_g = atof(argv[i+1]);
        } else if (strcmp(argv[i], "-b") == 0) {
            scale_b = atof(argv[i+1]);
        } else if (strcmp(argv[i], "-x") == 0) {
            x_offset = atoi(argv[i+1]);
        } else if (strcmp(argv[i], "-y") == 0) {
            y_offset = atoi(argv[i+1]);
        } else {
            fprintf(stderr, "waves: invalid flag entered\n");
            exit(1);
        }
    }
    draw_waves(side_length, scale_r, scale_g, scale_b, x_offset, y_offset);  
    return 0;
}
