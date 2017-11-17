#ifndef _BOARD_H
#define _BOARD_H

#include "pos.h"


enum square {
    EMPTY,
    BLACK,
    WHITE
};

typedef enum square square;


union board_rep {
    enum square** cells;
    unsigned int* bits;
};

typedef union board_rep board_rep;

enum type {
    CELLS, BITS
};


struct board {
    unsigned int nrows, ncols;
    enum type type;
    board_rep u;
};

typedef struct board board;


board* board_new(unsigned int nrows, unsigned int ncols, enum type type);

void board_free(board* b);

void board_show(board* b);

square board_get(board* b, pos p);

void board_set(board* b, pos p, square s);

#endif /* _BOARD_H */