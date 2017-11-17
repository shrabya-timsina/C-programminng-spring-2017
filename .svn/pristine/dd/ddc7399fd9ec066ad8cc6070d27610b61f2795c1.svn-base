/* graded hw2 */

/* ====== Makefile ====== */

evidence:
	clang -o ev -Wall -lm hw2.c evidence_hw2.c     

/* ====== hw2.h ====== */

/* submitted few minutes after deadline */

/* calculates total value accrued over the given periods for given principle at given rate*/
double interest(double principle, double rate, unsigned int periods);

/* calculates total sum of odd integers from 0 to a given number*/
unsigned int sum_odds_upto(unsigned int n);

/* calculates value of pi as an area of unit circle based on rectangle method using given number of rectangles*/
double pi_approx(unsigned int n);

/*prints patterns of triangles of specified height in a speficied number of rows and colums */
void triangles(unsigned int rows, unsigned int cols, unsigned int tri_height);

/* performs division using just subtraction and calcualtes quotient and remainder */
void int_div(unsigned int n, unsigned int d, unsigned int* q, unsigned int* r);


/* ====== hw2.c ====== */

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






















/* ====== evidence_hw2.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include "hw2.h"

void evidence_interest() {
    printf("\n*** testing interest\n");
    printf("\n");
    printf("\n- expecting 10612.080000 : %lf\n", interest(10000, 0.02, 3));
    printf("\n");
    printf("\n- expecting 295652.450000 : %lf\n", interest(243234, 0.05, 4));
    printf("\n");
    printf("\n- expecting 1974851.730000 : %lf\n", interest(326236, 0.35, 6));
    printf("\n");

}

void evidence_sum_odds_upto() {
    printf("\n\n*** testing sum_odds_upto\n");
    printf("- expecting 2500 : %u\n", sum_odds_upto(100));
    printf("\n- expecting 625 : %u\n", sum_odds_upto(49));
    printf("\n- expecting 25 : %u\n", sum_odds_upto(10));
}

void evidence_pi_approx() {
    printf("\n*** testing pi_approx\n");
    printf("- expecting 3.732051 : %lf\n", pi_approx(2));
    printf("- expecting 4.000000 : %lf\n", pi_approx(1));
    printf("- expecting 3.304518 : %lf\n", pi_approx(10));
    printf("- expecting 3.212196 : %lf\n", pi_approx(25));
    
}

void evidence_triangles() {
    printf("\n*** testing triangles\n");
    printf("- expecting 2 rows, 3 columns of triangles of height 4\n");
    printf("\n");
    triangles(2, 3, 4);
    printf("\n");
    printf("- expecting 5 rows, 4 columns of triangles of height 4\n");
    triangles(5, 4, 4);
    printf("\n");
    printf("- expecting 0 rows, 0 columns of triangles of height 0\n");
    triangles(0,1, 4);
    printf("\n");
}

void evidence_int_div() {
    printf("\n\n*** testing pi_approx\n");
    unsigned int quotient, remainder;
    int_div(16, 14, &quotient, &remainder);
    printf("- expecting quotient 1, obtaining %u ||| expecting remainder 2, obtaining  = %u\n", 
            quotient, remainder);
    int_div(45, 105, &quotient, &remainder);
    printf("- expecting quotient 0, obtaining %u ||| expecting remainder 45, obtaining  = %u\n",
           quotient, remainder);
    int_div(345, 6, &quotient, &remainder);
    printf("- expecting quotient 57, obtaining %u ||| expecting remainder 3, obtaining  = %u\n", 
           quotient, remainder);
    int_div(324, 3, &quotient, &remainder);
    printf("- expecting quotient 108, obtaining %u ||| expecting remainder 0, obtaining  = %u\n",
           quotient, remainder);
}/* main: run the evidence fu
nctions above */
int main(int argc, char *argv[])
{
    evidence_interest();
    evidence_sum_odds_upto();
    evidence_pi_approx();
    evidence_triangles();
    evidence_int_div();
    return 0; 
}

/* ====== evaluation ====== */

/* === correctness === */

/* problem 1 (interest)                6/ 6 */
/* problem 2 (sum_odds_upto)           6/ 6 */
/* problem 3 (pi)                      12/12 */
/* problem 4 (triangles)               12/12 */
/* problem 5 (int_div)                 12/12 */

/* === style === */

/* code layout                         8/ 8 */
/* identifiers are well named          6/ 6 */

/* functions are well designed         6/ 6 */
/* code is well factored               6/ 6 */

/* code is written clearly             8/ 8 */
/* code is efficient                   6/ 6 */

/* adequate tests                      8/ 8 */
/* svn used correctly                  4/ 4 */

/* _total-score_                       100/100 */

/* graded by chunwei */

