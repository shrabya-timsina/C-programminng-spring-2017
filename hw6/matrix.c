#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

matrix *matrix_zero(unsigned int n_rows, unsigned int n_cols) {
    matrix* matrix_0 = (matrix*) malloc(sizeof(matrix));
    matrix_0 -> n_rows = n_rows;
    matrix_0 -> n_cols = n_cols;
    matrix_0 -> entries = (float**) malloc(n_rows*sizeof(float*));
    unsigned int i,j;
    for (i = 0; i < n_rows; i++) {
        matrix_0 -> entries[i] = (float*) malloc(n_cols*sizeof(float));
        for (j = 0; j < n_cols; j++) {
            matrix_0 -> entries[i][j] = 0.0;
        }
    }
    return matrix_0;
}

float matrix_read(matrix *m, unsigned int i, unsigned int j) {
    if (m) {
        if (m -> n_rows < i || m -> n_cols < j) {
            fprintf(stderr, \
            "\nmatrix_read: i and j must be less than number of rows and columns respectively \n");
            exit(1);
        }
        return m ->entries[i][j];
    } else {
        fprintf(stderr, "\nmatrix_read: input matrix was NULL \n");
        exit(1);
    }
}

void matrix_write(matrix *m, unsigned int i, unsigned int j, float x) {
    if (m) {
        if (m -> n_rows < i || m -> n_cols < j) {
            fprintf(stderr, \
            "\nmatrix_write: i and j must be less than number of rows and columns respectively \n");
            exit(1);
        }
        m -> entries[i][j] = x;
    }
}

matrix *matrix_add(matrix *m, matrix *n) {
    if (m -> n_rows != n -> n_rows || m -> n_cols != n -> n_cols) {
        fprintf(stderr, "\nmatrix_add: both matrices must have save dimensions \n");
        exit(1);
    }
    matrix* matrix_sum = (matrix*) malloc(sizeof(matrix));
    matrix_sum -> n_rows = m -> n_rows;
    matrix_sum -> n_cols = m -> n_cols;
    matrix_sum -> entries = (float**) malloc((m -> n_rows)*sizeof(float*));
    unsigned int i,j;
    for (i = 0; i < (m -> n_rows); i++) {
        matrix_sum -> entries[i] = (float*) malloc((m -> n_cols)*sizeof(float));
        for (j = 0; j < (m -> n_cols); j++) {
            matrix_sum -> entries[i][j] = (m -> entries[i][j]) + (n -> entries[i][j]);
        }
    }
    return matrix_sum;
}

matrix *matrix_mult(matrix *m, matrix *n) {
    if (m -> n_cols != n -> n_rows) {
        fprintf(stderr, "\nmatrix_mult: both matrices must have save dimensions \n");
        exit(1);
    }
    matrix* matrix_mult = (matrix*) malloc(sizeof(matrix));;
    matrix_mult -> n_rows = m -> n_rows;
    matrix_mult -> n_cols = n -> n_cols;
    matrix_mult -> entries = (float**) malloc((m -> n_rows)*sizeof(float*));
    unsigned int i, j, k;
    for (i = 0; i < (m -> n_rows); i++) {
        matrix_mult -> entries[i] = (float*) malloc((m -> n_cols)*sizeof(float));
        for (j = 0; j < (n -> n_cols); j++) {
            matrix_mult -> entries[i][j] = 0.0;
            for (k = 0; k < (m -> n_cols); k++) {
                matrix_mult -> entries[i][j] += (m -> entries[i][k]) * (m -> entries[k][j]);
            }
        }
    }
    return matrix_mult;
}

void matrix_show(matrix *m) {
    if (m) {
        unsigned int i, j;
        printf("\n");
        for (i = 0; i < (m -> n_rows); i++) {
            for (j = 0; j < (m -> n_cols); j++) {
                printf("%f ", m -> entries[i][j]);
            }
            printf("\n");
        }
    }
}

void matrix_free(matrix *m) {
    if (m) {
        unsigned int i;
        for (i = 0; i < (m -> n_rows); i++) {
            free(m -> entries[i]);
        }
        free(m -> entries);
        free(m);
    }
}