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

