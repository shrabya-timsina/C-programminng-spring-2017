/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * Lab 3 
 */

#include "waves.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double dist(double x0, double y0, double x1, double y1) {

    double x_section = (x1 - x0) * (x1 - x0);
    double y_section = (y1 - y0) * (y1 - y0);
    return sqrt(x_section + y_section);
}

void draw_waves(int side_length, int x_offset, int y_offset) {

    if (side_length < 1) {
        fprintf(stderr, \
                "draw_waves: side length must be greater than 0\n");
        exit(1);
    }
    int max_colour_value = 255;
    printf("P3\n");
    printf("%d %d\n", side_length, side_length);
    printf("%d\n", max_colour_value);

    double x_center = ( (double) side_length / 2) + x_offset;
    double y_center = ( (double) side_length / 2) + y_offset;
    double x, y, dist_from_center, sine_value;
    int scaled_value;
    for (y = 0; y < side_length; y++) {
        for (x = 0; x < side_length; x++) {
            dist_from_center = dist(x, y, x_center, y_center);
            sine_value = sin(dist_from_center);
            scaled_value = (max_colour_value/2.0) * (sine_value + 1);
            printf("0 0 %d\n", scaled_value); 
        }
    }
}
