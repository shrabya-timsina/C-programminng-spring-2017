/* graded lab3 */

 /* ====== Compiler warnings/issues ====== */

clang -Wall -lm -o waves waves.c test_lab3.c
 /* ====== Automated dist tests ====== */

expected: 0 answer 0.000000
expected: 0 answer 0.000000
expected: 5 answer 5.000000
expected: ~1.41 answer 1.414214

/* ====== shrabya-cs152-spr-17/lab3/Makefile ====== */

waves: waves.h waves.c main_waves.c
	clang -Wall -lm -o waves waves.c main_waves.c

ev: waves.h waves.c evidence_waves.c
	clang -Wall -lm -o ev waves.c evidence_waves.c

/* ====== shrabya-cs152-spr-17/lab3/waves.h ====== */


/* dist : calculates the distance between two given points with coordinates
*        (x0, y0) and (x1, y1) */
double dist(double x0, double y0, double x1, double y1);

/* draw_waves : calculates the colour value for every pixel coordinate inside
               a square of user-specified length and specified offset values
               to locate its offset center and prints out the contents
               of a ppm file that produces this coloured square */

void draw_waves(int side_length, int x_offset, int y_offset);

/* ====== shrabya-cs152-spr-17/lab3/waves.c ====== */

/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * Lab 3 
 */

#include "waves.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

### GRADER COMMENT
### missing the function descriptions here -2
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

/* ====== shrabya-cs152-spr-17/lab3/evidence_waves.c ====== */

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

/* dist:                                8/ 8 */
/* draw_waves:                          40/40 */

/* === style === */

/* code layout                          6/ 8 */
/* identifiers are well named           6/ 6 */

/* functions are well designed          6/ 6 */
/* code is well factored                6/ 6 */

/* code is written clearly              8/ 8 */
/* code is efficient                    6/ 6 */

/* adequate tests                       8/ 8 */
/* svn used correctly                   4/ 4 */

/* _total-score_                        98/100 */

/* graded by Steven */
