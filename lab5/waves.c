/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * Lab 5
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

double scaled_value(double dist_from_center, double scale_coefficient,
                    int max_colour_value) {

    double sine_value;
    int scaled_value;
    sine_value = sin(dist_from_center * scale_coefficient);
    scaled_value = (max_colour_value/2.0) * (sine_value + 1);
    return scaled_value;
}

void draw_waves(int side_length, 
                double scale_r, double scale_g, double scale_b,
                int x_offset, int y_offset) {

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
    double x, y, dist_from_center;
    int scaled_value_r, scaled_value_g, scaled_value_b;
    for (y = 0; y < side_length; y++) {
        for (x = 0; x < side_length; x++) {
            dist_from_center = dist(x, y, x_center, y_center);
            scaled_value_r = scaled_value(dist_from_center, 
                                          scale_r, max_colour_value);
            scaled_value_g = scaled_value(dist_from_center, 
                                          scale_g, max_colour_value);
            scaled_value_b = scaled_value(dist_from_center, 
                                          scale_b, max_colour_value);           
            printf("%d %d %d\n", scaled_value_r, scaled_value_g, scaled_value_b); 
        }
    }
}
