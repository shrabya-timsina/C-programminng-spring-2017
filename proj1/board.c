#include "board.h"
#include <math.h>

board* board_new(unsigned int nrows, unsigned int ncols, enum type type) {

    board* new = (board*) malloc(sizeof(board));
    new -> nrows = nrows;
    new -> ncols = ncols;
    new -> type = type;
    switch(type) {
        case CELLS:
            new -> u.cells = malloc(nrows * sizeof(square*));
            unsigned int i, j;
            for (i = 0; i < nrows; i++) {
                new -> u.cells[i] = malloc(nrows * sizeof(square));
                
                    for (j = 0; j < ncols; j++) {
                        new -> u.cells[i][j] = EMPTY;
                }
            }
        case BITS:
            unsigned int k, num_elements = ciel((nrows * ncols) / 16.0);
            new -> u.bits = malloc(num_elements);
            for (k = 0; k < num_elements; k++) {
                new -> u.bits[k] = 0;
            }
    }
    return new;
}

void board_free(board* b) {
    switch(b -> type) {
        case CELLS:
            unsigned int i;
            for (i = 0; i < b -> nrows; i++) {               
                free(b -> u.cells[i]);
           }
           free(b -> u.cells);
        case BITS:
           free(b -> u.bits);
    }
    free(b);
}

square board_get(board* b, pos p) {
    switch(b -> type) {
        case CELLS:
            return b -> u.cells[p.r][pos.c];
 
        case BITS:
            unsigned int cell_number = (p.r * b -> ncols) + (p.c + 1); 
            unsigned int element_number = cell_number / 16;
            unsigned int element_item_number = \
                                        cell_number - (element_number * 16);
            unsigned int right_shifted = \
                (b -> u.bits[element_number]) >> ((element_item_number - 1) * 2);

            bit_in_square = right_shifted & 3;
            switch(bit_in_square) {
                case 0:
                    return EMPTY;
                case 1:
                    return BLACK;
                case 2:
                    return WHITE;
            }
    }
}

void board_set(board* b, pos p, square s) {
    switch(b -> type) {
        case CELLS:
            b -> u.cells[p.r][pos.c] = s;
            return;
 
        case BITS:
            unsigned int cell_number = (p.r * b -> ncols) + (p.c + 1); 
            unsigned int element_number = cell_number / 16;
            unsigned int element_item_number = \
                                        cell_number - (element_number * 16);
            b -> u.bits[element_number] |= 3 << ((element_item_number - 1) * 2);
    }
}

void print_row_col_headers(unsigned int i) {
    if (j <= 9) {
        printf(" %u ", j);
    } else if (j >= 10 && j <= 35) {
        character_val = 65 + (j - 10);
        printf(" %c ", character_val);
    } else if (j >= 36 && j <= 61) {
        character_val = 97 + (j - 36);
        printf(" %c ", character_val);
    } else {
        printf(" ? ");
    }
}

void board_show(board* b) {
    printf("\n\n ");
    unsigned int i, j;
    char character_val;
    for (j = 0; j < ncols; j++) {
        print_row_col_headers(j);
    }
    for (i = 0; i < nrows; i++) {
        printf("\n");
        print_row_col_headers(i);
        for (j = 0; j < ncols; j++) {
            pos p = make_pos(i, j);
            switch(board_get(b, p)) {
                case EMPTY:
                    printf("O ");
                case BLACK:
                    printf("B ");
                case WHITE:
                    printf("W ");
            }
        }  
    }
    printf("\n\n");
}