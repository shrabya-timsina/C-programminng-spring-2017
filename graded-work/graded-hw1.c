/* graded hw1 */

/* ====== Makefile ====== */

evidence:
	clang -o ev -Wall -lm hw1.c evidence_hw1.c
	

/* ====== hw1.h ====== */

/* regular_tetrahedron_volume : calculate volume of regular tetrahedron
*                             given the length of edge 'a' */
double regular_tetrahedron_volume(double a);

/* home_equity : calculates the value of part of home owned given
*               the total value of home 'v' and
*               number of days elapsed since loan 'days' */
double home_equity(double v, int days);

/* nc_call_cost : returns cost (in number of cents per minute) for a call
*                 from Chicago to city whose area code is given */
unsigned int nc_call_cost(unsigned int npa);

/* gcd : calculates the greatest common divisor of two 
*        natural numbers 'n' and 'm' */ 
unsigned int gcd(unsigned int n, unsigned int m);

/* ====== hw1.c ====== */

/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * HW 1 
 */

#include "hw1.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double regular_tetrahedron_volume(double a) {
    if (a < 0) {
        fprintf(stderr, \
            "regular_tetrahedron_volume: edge length cannot be negative\n");
        exit(1);
    }
    return (a * a * a)/(6 * sqrt(2));
}

double home_equity(double v, int days) {
    
    if (v < 0) {
       fprintf(stderr, "home_equity: home value cannot be negative\n");
       exit(1);
    }
    if (days >= 10800) { return v; }
    if (days < 0) { return 0; }
    
    int num_complete_months = days / 30;
    double monthly_payment = (0.8 * v) / 360.0;
  
    return (0.2 * v) + (num_complete_months * monthly_payment); 
}

unsigned int nc_call_cost(unsigned int npa) {   
    
    switch(npa) {
        case 212 :
        case 713 :
        case 215 :
        case 214 :
            return 5;
        case 602 :
        case 210 :
            return 10;
        case 213 :
        case 619 :
        case 408 :
            return 15;
        case 312 :
            return 0;
        default :
            fprintf(stderr, \
                "nc_call_cost: area code %u is not served by NationCom\n", npa);
            exit(1);
    }
}

unsigned int gcd(unsigned int n, unsigned int m) {
    
    if (m > n) {
        unsigned int temp = m;       
        m = n;
        n = temp;
    } /* ensuring second argument is equal to or smaller than first arg */
    
    if (m == 0) { return n; }
    else { return gcd(m, n % m); }    
}

/* ====== evidence_hw1.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include "hw1.h"

/* evidence_tetra_volume: test regular_tetrahedron_volume */ 
void evidence_tetra_volume()
{
  printf("*** testing regular_tetrahedron_volume\n");
  printf("- expecting 14.73 : %lf\n", regular_tetrahedron_volume(5));
  printf("- expecting 0 : %lf\n", regular_tetrahedron_volume(0));
  printf("- expecting 0.12 : %lf\n", regular_tetrahedron_volume(1));
  printf("- expecting 117.85 : %lf\n", regular_tetrahedron_volume(10));
  printf("- expecting 14731.39 : %lf\n", regular_tetrahedron_volume(50));
  /* printf("- expecting error\n");
  * regular_tetrahedron_volume(-5); */
}


/* evidence_home_equity : test home_equity */
void evidence_home_equity()
{
  printf("*** testing home_equity\n");
  printf("- expecting 10000 : %lf\n", home_equity(10000, 10800));
  printf("- expecting 10000 : %lf\n", home_equity(10000, 25000)); 
  printf("- expecting 6000 : %lf\n", home_equity(10000, 5400));
  printf("- expecting 2177.78 : %lf\n", home_equity(10000, 250));
  printf("- expecting 210.9 : %lf\n", home_equity(999, 176));
  printf("- expecting 2000 : %lf\n", home_equity(10000, 0));
  printf("- expecting 0 : %lf\n", home_equity(10000, -50));
  printf("- expecting 0 : %lf\n", home_equity(0, 250));
  /* printf("- expecting error\n"); 
  * printf(" %lf\n", home_equity(-800, -8)); */
}


/* evidence_nc_call_cost :  nc_call_cost */
void evidence_nc_call_cost()
{
  printf("*** testing  nc_call_cost\n");
  printf("- expecting 5 : %u\n",  nc_call_cost(212));
  printf("- expecting 5 : %u\n",  nc_call_cost(713));
  printf("- expecting 5 : %u\n",  nc_call_cost(215));
  printf("- expecting 5 : %u\n",  nc_call_cost(214));
  printf("- expecting 15 : %u\n",  nc_call_cost(213));
  printf("- expecting 15 : %u\n",  nc_call_cost(619));
  printf("- expecting 15 : %u\n",  nc_call_cost(408));
  printf("- expecting 0 : %u\n",  nc_call_cost(312));
  printf("- expecting 10 : %u\n",  nc_call_cost(602));
  printf("- expecting 10: %u\n",  nc_call_cost(210));
  /* printf("- expecting error");
  nc_call_cost(6789); */

}
/* evidence_gcd :  gcd */
void evidence_gcd()
{
  printf("*** testing  gcd\n");
  printf("- expecting 6 : %u\n",  gcd(6, 12));
  printf("- expecting 23 : %u\n",  gcd(46, 23));
  printf("- expecting 0 : %u\n",  gcd(6, 0));
  printf("- expecting 100 : %u\n",  gcd(300, 500));
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
  evidence_tetra_volume(); 
  evidence_home_equity();
  evidence_nc_call_cost();
  evidence_gcd();
  return 0; 
}




/* ====== evaluation ====== */

/* === correctness === */

/* problem 1 (tetrahedron)            8/ 8 */
/* problem 2 (home_equity)           12/12 */
/* problem 3 (long distance)         12/12 */
/* problem 4 (gcd)                   16/16 */

/* === style === */

/* code layout                        8/ 8 */
/* identifiers are well named         6/ 6 */

/* functions are well designed        6/ 6 */
/* code is well factored              6/ 6 */

/* code is written clearly            8/ 8 */
/* code is efficient                  6/ 6 */

/* adequate tests                     8/ 8 */
/* svn used correctly                 4/ 4 */

/* _total-score_                    100/100 */

/* graded by Reiny Rolock */

