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







































