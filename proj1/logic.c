#include "logic.h"


game* new_game(unsigned int nrows, unsigned int ncols, enum type type) {
    if (nrows < 2 || ncols < 2) {
        // raise error
    }
    game* new = (game*) malloc(sizeof(game));
    new -> b = board_new(nrows, ncols, type);
    new -> next = BLACK_NEXT;
    black_pos_1 = make_pos(nrow / 2, ncol / 2);
    white_pos_1 = make_pos((nrow / 2) + 1), ncol / 2);
    black_pos_2 = make_pos((nrow / 2) + 1), (ncol / 2) + 1);
    white_pos_2 = make_pos(nrow / 2, (ncol / 2) + 1));
    board_set(new -> b, black_pos_1, BLACK);
    board_set(new -> b, white_pos_1, WHITE);
    board_set(new -> b, black_pos_2, BLACK);
    board_set(new -> b, white_pos_2, WHITE);

    return new;
}

unsigned int check_empty_or_same_colour(pos p, board* b, player_col) {
    square pos_status = board_get(b, p);
    if (pos_status == EMPTY) {
        return 0;
    }
    if (pos_status == player_col) {
        *flank = 1;
        break;
        return 1;
    }
    return 2;
}

int outflank_checker(board* b, pos p, unsigned int direction, 
                      int* flank, square player_col) {
    
    // checking immediate next positions
    square pos_status;
    for (delta_row = -1; delta_row <= 1; delta_row++) { 
        for (delta_col = -1; delta_col <= 1; delta_col++) {
            pos_status = board_get(b, make_pos(delta_row, delta_col));
            if (pos_status == EMPTY || pos_status == player_col) { 
                return 0; 
            }
        }
    }
   
        unsigned int i, j;

        for(e = p.c + 2, w = p.c - 2, n = p.r - 2, s = p.r + 2,;  
            e < (b -> ncols) || w >= 0 || n >= 0 || s < (b -> nrows);
            e++, w--, n--, s--) {
            
            // east 
            // add if to all
            unsigned int cell_status = check_empty_or_same_colour(make_pos(p.r, e),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }

            // west
            cell_status = check_empty_or_same_colour(make_pos(p.r, w),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }

            // north
            cell_status = check_empty_or_same_colour(make_pos(n, p.c),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }

            // south
            cell_status = check_empty_or_same_colour(make_pos(s, p.c),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }

            // north-east
            cell_status = check_empty_or_same_colour(make_pos(n, e),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }

            // south-east
            cell_status = check_empty_or_same_colour(make_pos(s, e),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }

            // north-west
            cell_status = check_empty_or_same_colour(make_pos(n, w),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }

            // south-west
            cell_status = check_empty_or_same_colour(make_pos(s, w),
                                                            b, flank);
            if (cell_status == 0) { 
                break;
            } else if (cell_status == 1) {
                return 1;
            } else {
                ;
            }
        }
    return 0;
}
           
          
                
        
    


int outflanks(game* g, pos p) {
    int oflank_status = 0;
    square player_col;
    switch(g -> next) {
        case BLACK_NEXT:
            square player_col = BLACK;
        case WHITE_NEXT:
            square player_col = WHITE; 
    }
    
    // checking horizontally rightward
    outflank_checker(b, p, 0, &oflank_status, player_col);
    // checking horizontally leftward
    outflank_checker(b, p, 1, &oflank_status, player_col);
    // checking vertically upward
    outflank_checker(b, p, 2, &oflank_status, player_col);
    // checking vertically downward
    outflank_checker(b, p, 3, &oflank_status, player_col);
    // checking diaganolly right-up
    outflank_checker(b, p, 4, &oflank_status, player_col);
    // checking diaganolly right-down
    outflank_checker(b, p, 5, &oflank_status, player_col);
    // checking diaganolly left-up
    outflank_checker(b, p, 6, &oflank_status, player_col);
    // checking diaganolly left-down
    outflank_checker(b, p, 7, &oflank_status, player_col);

    return oflank_status;
}

poslist* flips(game* g, pos p) {
    // checking horizontally rightward
    int oflank_status = 0;
    outflank_checker(b, p, 0, &oflank_status, player_col);


}
