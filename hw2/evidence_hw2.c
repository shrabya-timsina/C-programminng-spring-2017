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
