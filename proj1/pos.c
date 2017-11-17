#include "pos.h"

pos make_pos(unsigned int r, unsigned int c) {
    pos res;
    res.r = r;
    res.c = c;
    return res;
}

poslist* pos_cons(pos p, poslist* ps) {
    poslist* res = (poslist*) malloc(sizeof(poslist));
    res -> p = p;
    res -> next = ps;
    return res;
}

void poslist_free(poslist* ps) {
    while(ps) {
        temp = ps -> next;
        free(ps);
        ps = temp;
    }
}