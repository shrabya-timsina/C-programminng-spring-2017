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



