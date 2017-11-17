/* graded lab1 */

/* ====== Makefile ====== */

evidence: lab1.h lab1.c evidence_lab1.c
	clang -Wall -o evidence_lab1 lab1.c evidence_lab1.c

/* ====== lab1.h ====== */

/* expt : linear time recursive exponentiation */
long int expt(int a, unsigned int n);

/* ss : exponentiation by successive squaring */
long int ss(int a, unsigned int n);

/* ssm : exponentiation modulo m by successive squaring */
int ssm(int a, unsigned int n, unsigned int m);

/* ====== lab1.c ====== */

/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * Lab 1 
 */

#include "lab1.h"
#include <stdlib.h>
#include <stdio.h>

/*  Linear Time Exponentiation */

long int expt(int a, unsigned int n) {
    if (n==0) {
        return 1;
    } else {
        return a*expt(a, n-1);	
    }  
}

/* Fast Exponentiation by Successive Squaring */

long int ss(int a, unsigned int n) {
    if (n==0) {
        return 1;
    } 
    if (n%2==0) {
        return ss(a, n/2)*ss(a, n/2);
    } else {
        return a*ss(a, n-1);
    }   
}

/*Fast Exponentiation modulo m */

int ssm(int a, unsigned int n, unsigned int m) {
    if (m==1) {
        return 0;
    } 
    if (m==0) {
        fprintf(stderr, "ssm: modulus cannot be zero\n");
        exit(1);   
    } 
    if (n==0) {
        return 1;
    } 
    if (n%2==0) {
        return (ssm(a, n/2, m)*ssm(a, n/2, m))%m;
    } else {
        return (a*ssm(a, n-1, m))%m;
    }
} 


/* ====== evidence_lab1.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include "lab1.h"

/* evidence_expt: test expt */
void evidence_expt()
{
  printf("*** testing expt\n");
  printf("- expecting 1: %ld\n", expt(2,0));
  printf("- expecting 8: %ld\n", expt(2,3));
  printf("- expecting 999: %ld\n", expt(999,1));
  printf("- expecting 11390625: %ld\n", expt(15,6));
  printf("- expecting -285311670611: %ld\n", expt(-11,11));
  printf("- expecting 3111696: %ld\n", ss(42,4));  
/* more tests at your discretion */
}

/* evidence_ss: test ss */
void evidence_ss()
{
  printf("*** testing ss\n");
  printf("- expecting 1: %ld\n", ss(2,0));
  printf("- expecting 8: %ld\n", ss(2,3));
  printf("- expecting 999: %ld\n", ss(999,1));
  printf("- expecting 11390625: %ld\n", ss(15,6));
  printf("- expecting 285311670611: %ld\n", ss(11,11));
  printf("- expecting 3111696: %ld\n", ss(42,4));
  /* tests */
}

void evidence_ssm()
{
  printf("*** testing ssm\n");
  printf("- expecting 24: %d\n", ssm(2,10, 1000));
  printf("- expecting 10: %d\n", ssm(10,7, 45));
  printf("- expecting 0: %d\n", ssm(0,1,1));
  printf("- expecting 0: %d\n", ssm(43576,0,1));    
  /* tests */
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
  evidence_expt();
  evidence_ss();
  evidence_ssm();
  return 0; 
}

/* ====== evaluation ======  */

/* === correctness === */

/* Makefile :                           5/ 5 */
/* lab1.h   :                           5/ 5 */

/* expt     :                           12/12 */
/* ss       :                           13/13 */
/* ssm      :                           13/13 */

/* === style === */

/* code layout                          8/ 8 */
/* identifiers are well named           6/ 6 */

/* functions are well designed          6/ 6 */
/* code is well factored                6/ 6 */

/* code is written clearly              8/ 8 */
/* code is efficient                    6/ 6 */

/* adequate tests                       8/ 8 */
/* svn used correctly                   4/ 4 */

/* _total-score_                        100/100 */

/* graded by chunwei */
