/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * HW 2 
 */

#include "hw2.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double interest(double principle, double rate, unsigned int periods) {

    if (principle < 0 || rate < 0) {
        fprintf(stderr, \
            "interest: principle and rate cannot be negative\n");
        exit(1);
    }
    unsigned int i;
    for (i = 1; i  <= periods; i++) {
        principle += principle*rate;
        printf("After %u period(s), the value = %lf\n", i, principle);
        }
    return principle;
}

unsigned int sum_odds_upto(unsigned int n) {
   
    if (n%2 == 0) { /* if n is even, we increment only till n-1 */
        n--; 
    }
    unsigned int i, sum_total = 0;
    for (i = 1; i <= n; i += 2) { 
        sum_total += i;
    }  
    return sum_total;
}

double pi_approx(unsigned int n) {
    if (n==0) {
        fprintf(stderr, \
                "pi_approx: number of rectangles must be greater than zero\n");
        exit(1);
    }
    unsigned int i;
    double x, y, delta_x = 1 / (double) n,sum_y = 0;

    for (i = 0; i < n; i++) { /*integrating from 0 to 1*/
        x = delta_x * (double) i; 

        y = sqrt(1 - x*x);

        sum_y += y;
    } 
    double area = sum_y * delta_x * 4;

    return area; /* calculating area of all 4 quadrants of circle*/           
}

void triangles(unsigned int rows, unsigned int cols, unsigned int tri_height) {

    unsigned int current_row, line, current_col, spacing, star, max_spacing;
    for (current_row = 1; current_row <= rows; current_row++) {
       
        for (line = 1; line <= tri_height; line++) {
            printf("\n");
            max_spacing = tri_height - line;

            for (current_col = 1; current_col <= cols; current_col++) {

                for (spacing = 1; spacing <= max_spacing; spacing++){
                    printf(" ");
                }
                for (star = 1; star <= line; star++){
                    printf("*");
                }                                  
            }                                                        
        }                    
    }
}

void int_div(unsigned int n, unsigned int d, unsigned int* q, unsigned int* r) {
    if (d == 0) {
        fprintf(stderr, \
            "int_div: divisor must be greater than zero\n");
        exit(1);
    }
    *q = 0;
    while (n > n - d) {
        n = n - d;
        (*q)++;
    }
    *r = n; 
}





















