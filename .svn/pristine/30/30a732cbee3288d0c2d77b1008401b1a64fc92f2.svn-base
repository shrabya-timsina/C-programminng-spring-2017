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
