#ifndef _LOGIC_H
#define _LOGIC_H

#include "board.h"


enum turn {
    BLACK_NEXT,
    WHITE_NEXT
};

typedef enum turn turn;


enum outcome {
    BLACK_WIN,
    WHITE_WIN,
    DRAW
};

typedef enum outcome outcome;


struct game {
    board* b;
    turn next;
};

typedef struct game game;


game* new_game(unsigned int nrows, unsigned int ncols, enum type type);

int outflanks(game* g, pos p);

poslist* flips(game* g, pos p);

void apply_move(game* g, pos p);

int game_over(game* g);

outcome game_outcome(game* g);

#endif /* _LOGIC_H */