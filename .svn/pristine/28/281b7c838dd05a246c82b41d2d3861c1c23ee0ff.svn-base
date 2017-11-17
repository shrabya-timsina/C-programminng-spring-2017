/* graded lab5 */

 /* ====== Compiler warnings/issues ====== */

clang -Wall -lm -o waves waves.c main_waves.c
 /* ====== Automated test ====== */


/* ====== shrabya-cs152-spr-17/lab5/Makefile ====== */

waves: waves.h waves.c main_waves.c
	clang -Wall -lm -o waves waves.c main_waves.c

ev: waves.h waves.c evidence_waves.c
	clang -Wall -lm -o ev waves.c evidence_waves.c

/* ====== shrabya-cs152-spr-17/lab5/waves.h ====== */


/* dist : calculates the distance between two given points with coordinates
*        (x0, y0) and (x1, y1) */
double dist(double x0, double y0, double x1, double y1);

/* draw_waves : calculates the colour value for every pixel coordinate inside
               a square of user-specified length and specified offset values
               to locate its offset center and prints out the contents
               of a ppm file that produces this coloured square */

void draw_waves(int side_length,
                double scale_r, double scale_g, double scale_b,
                int x_offset, int y_offset);
/* ====== shrabya-cs152-spr-17/lab5/waves.c ====== */

/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * Lab 5
 */

#include "waves.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

### GRADER COMMENT
### These need function descriptions too
### -4
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
          ### GRADER COMMENT
          ### this goes over 80 char
            printf("%d %d %d\n", scaled_value_r, scaled_value_g, scaled_value_b);
        }
    }
}

/* ====== shrabya-cs152-spr-17/lab5/main_waves.c ====== */

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

/* ====== shrabya-cs152-spr-17/lab5/evidence_waves.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include "waves.h"

/* evidence_dist: test dist */
void evidence_dist() {
    printf("\n*** testing dist\n");
    printf("\n- expecting 9.055385 : %lf\n", dist(3, 5, 12, 6));
    printf("\n- expecting 45.310043 : %lf\n", dist(-10, -45, 7, -3));
    printf("\n- expecting 0.000000 : %lf\n", dist(23, 23, 23, 23));
    printf("\n- expecting 229.400585 : %lf\n", dist(10.56, 234.6, 2.53, 5.34));
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_dist();
    return 0;
}

/* ====== evaluation ======  */

/* === correctness === */

/* arg processing:                      24/24 */
/* image generation:                    24/24 */

/* === style === */

/* code layout                          4/ 8 */
/* identifiers are well named           6/ 6 */

/* functions are well designed          6/ 6 */
/* code is well factored                6/ 6 */

/* code is written clearly              8/ 8 */
/* code is efficient                    6/ 6 */

/* adequate tests                       8/ 8 */
/* svn used correctly                   4/ 4 */

/* _total-score_                        96/100 */

/* graded by Steven
*/
