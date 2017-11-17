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
