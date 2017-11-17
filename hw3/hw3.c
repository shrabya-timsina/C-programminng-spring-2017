/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * HW 3 
 */

#include "hw3.h"
#include <stdlib.h>
#include <stdio.h>

// ===> Problem 1: Array Basics

int all_positive(int a[], unsigned int alen) {
    int i;
    for (i = 0; i < alen; i++) {
        if (a[i] <= 0) {
            return 0;
        }
    }
    return 1;
}

int exists_positive(int a[], unsigned int alen) {
    unsigned int i;
    for (i = 0; i < alen; i++) {
        if (a[i] > 0) {
            return 1;
        }
    }
    return 0; 
}

int first_positive(int a[], unsigned int alen) {
    unsigned int i;
    for (i = 0; i < alen; i++) {
        if (a[i] > 0) {
            return a[i];
        }
    }
    return -1;
}

unsigned int number_positives(int a[], unsigned int alen) {
    unsigned int i,num_pos = 0;
    for (i = 0; i < alen; i++) {
        if (a[i] > 0) {
            num_pos++;
        }
    }
    return num_pos;
}

void negate(int a[], unsigned int alen) {
    unsigned int i;
    for (i = 0; i < alen; i++) {
        a[i] = -a[i];  
    }
}

int* partial_sums(int a[], unsigned int alen) {
    
    unsigned int i = 0;
    int cumulative_sum = 0;
    int* sum_array = (int*) malloc((alen + 1) * sizeof(int)); 

    for (i = 0; i < alen; i++) {
        sum_array[i] = cumulative_sum;
        cumulative_sum += a[i];
        
    } 
    sum_array[alen] = cumulative_sum;    
    return sum_array;
}

void rotate_right(int a[], unsigned int alen) {
    if (alen > 1) {
        unsigned int i;
        int temp = a[alen-1];
        for (i = alen - 1 ; i > 0; i--) {
            a[i] = a[i-1];          
        }
        a[0] = temp;
    }
}

// ===> Problem 2: Prime Factorization

// helper function to exit program if num_of_factors is more than allocated *flen
void check_if_exceeded(unsigned int num_of_factors, unsigned int* flen) {
    if (num_of_factors > *flen) {
        fprintf(stderr, \
          "factorization: number of elements has exceeded allocated space \n");
        exit(1);
    }
}

void factorization(unsigned int n, unsigned int factors[], unsigned int* flen) {
    if (n < 2) {
        //factors[] = {};
    }
    unsigned int i, num_of_factors = 0;

    // finding how many times n can be divided by 2, in order to obtain an odd 
    // number so that we can skip looping through even numbers in the 
    // subsequent for loop
    while (n % 2 == 0) {
        num_of_factors++; 
        check_if_exceeded(num_of_factors, flen);
        factors[num_of_factors - 1] = 2;
        n = n / 2; 
    }
    for (i = 3; i*i <= n; i = i+2) { // finding other factors 2 onwards 
        while (n % i == 0) {
            num_of_factors++;
            check_if_exceeded(num_of_factors, flen);
            factors[num_of_factors - 1] = i;
            n = n / i;
        }
    }    
    if (n > 2) { // if processed value of n is a prime number > 2
        num_of_factors++;
        check_if_exceeded(num_of_factors, flen);
        factors[num_of_factors - 1] = i;
    }
    *flen = num_of_factors;    
}

// ===> Problem 3: CRYP 10100

char* decode(unsigned int a[], unsigned int alen) {
    char* message = (char*) malloc((alen + 1) * sizeof(char));
    unsigned int i; 
    for (i = 0; i < alen; i++) {
        if (a[i] == 0) {
            message[i] = ' ';
        } else {
            message[i] = + a[i] - 1;
        }
    }
    message[alen] = '\0';
    printf("in func %s ", message); 
    return message;
}






































