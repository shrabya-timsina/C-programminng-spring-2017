/* graded hw3 */

/* ====== Makefile ====== */
evidence:
	clang -o ev -Wall -lm hw3.c evidence_hw3.c   

/* ====== hw3.h ====== */
// checks if all entiries in array are positive, returns 1 for true 0 for flase
int all_positive(int a[], unsigned int alen);

int exists_positive(int a[], unsigned int alen);

int first_positive(int a[], unsigned int alen);

unsigned int number_positives(int a[], unsigned int alen);

void negate(int a[], unsigned int alen);

int* partial_sums(int a[], unsigned int alen);

void rotate_right(int a[], unsigned int alen);

void factorization(unsigned int n, unsigned int factors[], unsigned int* flen);

char* decode(unsigned int a[], unsigned int alen);

/* ====== hw3.c ====== */
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
            return a[i]; // GRADER: you want the index, not the value, so return i;
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
    // GRADER: excellent!! You are one of only two people to have considered
    // that a[alen-1] segfaults when alen is 0. Well done!
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
        // GRADER: need to handle invalid entries (value > 26)
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

/* ====== evidence_hw3.c ====== */
#include <stdlib.h>
#include <stdio.h>
#include "hw3.h"

// evidence functions for problem 1

void evidence_all_positive() {
    printf("\n***** testing Prob 1 : all_positive *******\n");

    int a[] = { 5, 16, 34, 345, 1 };
    printf("expecting  True (1) : obtaining %d \n", all_positive(a, 5));

    int b[] = { 5, 16, -3, 4, 34, 345, 1 };
    printf("expecting  False (0) : obtaining %d \n", all_positive(b, 7));

    int c[] = { 15, 1, 45, 234234, 16, 0, 4, 34, 345, 1 };
    printf("expecting  False (0) : obtaining %d \n", all_positive(c, 10));

    int* d = (int*) malloc(0); 
    printf("expecting  True (1) : obtaining %d \n", all_positive(d, 0));
    free(d); 
}

void evidence_exists_positive() {
    printf("\n***** testing Prob 1 : exists_positive *******\n");

    int a[] = { 5, 16, 34, 345, 1 };
    printf("expecting  True (1) : obtaining %d \n", exists_positive(a, 5));

    int b[] = { 5, 16, -3, 4, 34, 345, 1 };
    printf("expecting  True (1) : obtaining %d \n", exists_positive(b, 7));

    int c[] = { -15, -1, -45, -234234, -16, 0, -4, -34, -345, -1 };
    printf("expecting  False (0) : obtaining %d \n", exists_positive(c, 10));

    int* d = (int*) malloc(0); 
    printf("expecting  False (0) : obtaining %d \n", exists_positive(d, 0));
    free(d); 
}

void evidence_first_positive() {
    printf("\n***** testing Prob 1 : first_positive *******\n");

    int a[] = { -5, -16, 34, 345, 1 };
    printf("expecting  34 : obtaining %d \n", first_positive(a, 5));

    int b[] = { -5, -456, 0, -9, -56, -4, 9 };
    printf("expecting  9 : obtaining %d \n", first_positive(b, 7));

    int c[] = { -15, -1, -45, -234234, -16, 0, -4, -34, -345, -7 };
    printf("expecting  None (-1) : obtaining %d \n", first_positive(c, 10));

    int* d = (int*) malloc(0); 
    printf("expecting  None (-1) : obtaining %d \n", first_positive(d, 0));
    free(d); 
}

void evidence_number_positives() {
    printf("\n***** testing Prob 1 : number_positives *******\n");

    int a[] = { 5, -16, -34, 345, 1 };
    printf("expecting  3 : obtaining %d \n", number_positives(a, 5));

    int b[] = { 5, 16, -3, 4, 34, 345, 1 };
    printf("expecting  6 : obtaining %d \n", number_positives(b, 7));

    int c[] = { -15, -1, -45, -234234, -16, 0, -4, -34, -345, -1 };
    printf("expecting  0 : obtaining %d \n", number_positives(c, 10));

    int* d = (int*) malloc(0); 
    printf("expecting  0 : obtaining %d \n", number_positives(d, 0));
    free(d); 
}

void print_array_contents(int a[], unsigned int alen) {
    int i;
    for (i = 0; i < alen; i++) {
        printf("%d, ", a[i]);
    }

}

void evidence_negate() {
    printf("\n***** testing Prob 1 : negate *******");

    int a[] = { 5, -16, -34, 345, 1 };
    printf("\n\nexpecting  array with contents: -5, 16, 34, -345, -1 \nobtaining : ");
    negate(a, 5);
    print_array_contents(a, 5);
    
    int b[] = { 5, -234, -3, 0, 34, -4, 1 };
    printf("\n\nexpecting  array with contents: -5, 234, 3, 0, -34, 4, -1 \nobtaining : ");
    negate(b, 7);
    print_array_contents(b, 7);

    int c[] = { -15, -1, -45, -234234, -16, 0, -4, -34, -345, -1 };
    printf("\n\nexpecting  array with contents: 15, 1, 45, 234234, 16, 0, 4, 34, 345, 1 \nobtaining : ");
    negate(c, 10);
    print_array_contents(c, 10);

    int* d = (int*) malloc(0); 
    printf("\n\nexpecting  array with no contents \nobtaining : ");
    negate(d, 0);
    print_array_contents(d, 0);
    free(d);
    printf("\n");
}


void evidence_partial_sums() {
    printf("\n***** testing Prob 1 : partial_sums *******");

    int a[] = { 5, -16, -34, 345, 1 };
    printf("\n\nexpecting  array with contents: 0, 5, -11, -45, 300, 301 \nobtaining : ");
    int* sum_array_a = partial_sums(a, 5);
    print_array_contents(sum_array_a, 6);
    free(sum_array_a);
    
    int b[] = { 5, -234, -3, 0, 34, -4, 1 };
    printf("\n\nexpecting  array with contents: 0, 5, -229, -232, -232, -198, -202, -201 \nobtaining : ");
    int* sum_array_b = partial_sums(b, 7);
    print_array_contents(sum_array_b, 8);
    free(sum_array_b);

    int c[] = { -15, -1, -45, 234234, -16, 0, -4, -34, -345, -1 };
    printf("\n\nexpecting  array with contents: ");
    printf("0, -15, -16, -61, 234173, 234157, 234157, 234153, 234119, 233774, 233773 \nobtaining : ");
    int* sum_array_c = partial_sums(c, 10);
    print_array_contents(sum_array_c, 11);
    free(sum_array_c);

    int* d = (int*) malloc(0); 
    printf("\n\nexpecting  array with contents: 0 \nobtaining : ");
    int* sum_array_d = partial_sums(d, 0);
    print_array_contents(sum_array_d, 1);
    free(sum_array_d);
    printf("\n");
}

void evidence_rotate_right() {
    printf("\n***** testing Prob 1 : rotate_right *******");

    int a[] = { 5, -16, -34, 345, 1 };
    printf("\n\nexpecting  array with contents: 1, 5, -16, -34, 345  \nobtaining : "
);
    rotate_right(a, 5);
    print_array_contents(a, 5);

    int b[] = { 5, -234, -3, 0, 34, -4, 1 };
    printf("\n\nexpecting  array with contents: 1, 5, -234, -3, 0, 34, -4, \nobtaining : ");
    rotate_right(b, 7);
    print_array_contents(b, 7);

    int c[] = { -15, -1, -45, -234234, -16, 0, -4, -34, -345, -1 };
    printf("\n\nexpecting  array with contents: -1, -15, -1, -45, -234234, -16, 0, -4, -34,-345 \nobtaining : ");
    rotate_right(c, 10);
    print_array_contents(c, 10);

    int* d = (int*) malloc(0);
    printf("\n\nexpecting  array with no contents \nobtaining : ");
    rotate_right(d, 0);
    print_array_contents(d, 0);
    free(d);
    printf("\n");
}

void print_unsigned_array_contents(unsigned int a[], unsigned int alen) {
    int i;
    for (i = 0; i < alen; i++) {
        printf("%u, ", a[i]);
    }

}

//i evidence functions for problem 2
void evidence_factorization() {
    printf("\n***** testing Prob 2 : factorization *******\n");

    unsigned int len_factors = 15;
    unsigned int* factors_a = (unsigned int*) malloc(len_factors * sizeof(unsigned int));
    factorization(50, factors_a, &len_factors);
    printf("\nthere are %u prime factors of 50 \n expecting: 2,5,5 obtained:" ,len_factors);
    factors_a = (unsigned int*) realloc(factors_a, len_factors * sizeof(unsigned int));
    print_unsigned_array_contents(factors_a, len_factors);

    len_factors = 8;
    unsigned int* factors_b = (unsigned int*) malloc(len_factors * sizeof(unsigned int));
    factorization(0, factors_b, &len_factors);
    printf("\n\nthere are %u prime factors of 0 \n expecting:  obtained:", len_factors);
    factors_b = (unsigned int*) realloc(factors_b, len_factors * sizeof(unsigned int));
    print_unsigned_array_contents(factors_b, len_factors); 

    len_factors = 8;
    unsigned int* factors_c = (unsigned int*) malloc(len_factors * sizeof(unsigned int));
    factorization(1, factors_c, &len_factors);
    printf("\n\nthere are %u prime factors of 1 \n expecting:  obtained:", len_factors);
    factors_c = (unsigned int*) realloc(factors_c, len_factors * sizeof(unsigned int));
    print_unsigned_array_contents(factors_c, len_factors);

    /*len_factors = 2;
    unsigned int* factors_d = (unsigned int*) malloc(len_factors * sizeof(unsigned int));
    factorization(236, factors_d, &len_factors);
    printf("\n\nthere are %u prime factors of 1 \n expecting:  obtained:", len_factors);
    factors_d = (unsigned int*) realloc(factors_d, len_factors * sizeof(unsigned int));
    print_unsigned_array_contents(factors_d, len_factors); */
}

// evidence functions for problem 3



void evidence_decode() {
    printf("\n***** testing Prob 3 : decode *******\n");
    unsigned int a[] = { 1, 4, 5, 3, 1, 0, 3};
    char* message = decode(a, 7);
    printf("/n expecting 'ADECA C' obtained ");
    unsigned int i;
    for (i = 0; i < 8; i++) {
        printf("%s ", message[i]);
    }
    free(message);
}


/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_all_positive();
    evidence_exists_positive();
    evidence_first_positive();
    evidence_number_positives();
    evidence_negate();
    evidence_partial_sums();
    evidence_rotate_right();
    //evidence_factorization();
    evidence_decode();
    return 0; 
}

/* ====== evaluation ====== */

/* ====== evaluation ====== */

/* === correctness === */

/* grader's note: points in each category other than total-score indicate
 * points deducted, not points earned. a blank category indicates full
 * credit. */

/* problem 1 (arrays) */
/* all_positive                        / 4 */
/* exists_positive                     / 4 */
/* first_positive                      1 / 4 */
/* number_positive                     / 4 */
/* negate                              / 4 */
/* partial_sums                        / 5 */
/* rotate_right                        / 6 */

/* problem 2 (factorization)           /11 */

/* problem 3 (decode)                  1 / 6 */

/* === style === */

/* code layout                         / 8 */
/* identifiers are well named          / 6 */

/* functions are well designed         / 6 */
/* code is well factored               / 6 */

/* code is written clearly             / 8 */
/* code is efficient                   / 6 */

/* adequate tests                      / 8 */
/* svn used correctly                  / 4 */

/* _total-score_                       98/100 */

// Outstanding work!

/* graded by yuxiaozou */