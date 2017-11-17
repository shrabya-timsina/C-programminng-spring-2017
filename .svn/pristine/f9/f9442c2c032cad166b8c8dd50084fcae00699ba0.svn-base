#ifndef _POS_H
#define _POS_H

struct pos {
    unsigned int r, c;
};

typedef struct pos pos;


typedef struct poslist poslist;

struct poslist {
    pos p;
    poslist* next;
};


pos make_pos(unsigned int r, unsigned int c);

poslist* pos_cons(pos p, poslist* ps);

void poslist_free(poslist* ps);

#endif /* _POS_H */