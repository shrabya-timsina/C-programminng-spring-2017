#include "hw5.h"
#include <stdlib.h>
#include <stdio.h>

// evidence functions for problem 1 =======================
void evidence_intlist_new() {
    intlist* empty_list = intlist_new();
    printf("\n***** testing Prob 1 : intlist_new *******\n");

    printf("\n expecting an empty list \n");
    if (!empty_list) {
        printf("YES, it is an empty list \n");
    } else {
        printf("NO, it is not an empty list \n");
    }
}

void evidence_intlist_nth() {
    printf("\n\n***** testing Prob 1 : intlist_nth (with 0-based indexing) *******\n");

    intlist* newlist = cons(10, cons(11, cons(12, cons(13, NULL))));
    printf("\n getting item 2 - expecting: 12 -- obtaining: %d", intlist_nth(newlist, 2));
    intlist_free(newlist);

    newlist = cons(0, cons(3, cons(3, cons(8, cons(9, NULL)))));
    printf("\n getting item 4 - expecting: 9 -- obtaining: %d", intlist_nth(newlist, 4));
    intlist_free(newlist);

    newlist = cons(1, cons(7, cons(467, cons(456, NULL))));
    //printf("\n getting item 6 - expecting: error -- obtaining: %d", intlist_nth(newlist, 6));
    intlist_free(newlist);

}

void evidence_intlist_set() {
    printf("\n\n***** testing Prob 1 : intlist_set (with 0-based indexing) *******\n");

    intlist* newlist = cons(10, cons(11, cons(12, cons(13, NULL))));
    intlist_set(newlist, 2, 234);
    printf("\n old item 2: 12 -- expected new item 2: 234 -- obtaining: %d", intlist_nth(newlist, 2));
    intlist_free(newlist);

    newlist = cons(0, cons(3, cons(3, cons(8, cons(9, NULL)))));
    intlist_set(newlist, 4, 23);
    printf("\n old item 4: 9 -- expected new item 4: 23 -- obtaining: %d", intlist_nth(newlist, 4));
    intlist_free(newlist);

    newlist = cons(1, cons(7, cons(467, cons(456, NULL))));
    //intlist_set(newlist, 6, 45);
    //printf("\n old item 6 does not exist - expecting: error -- obtaining: %d", intlist_nth(newlist, 6));
    intlist_free(newlist);

}

void evidence_intlist_append() {
    printf("\n\n***** testing Prob 1 : intlist_append (with 0-based indexing) *******\n");

    intlist* newlist = cons(10, cons(11, cons(12, cons(13, NULL))));
    printf("\nold list: 10 11 12 13 --  expecting to append 14 -- obtaining\n");
    newlist = intlist_append(newlist, 14);
    intlist_show(newlist);
    intlist_free(newlist);

    newlist = intlist_new();
    printf("\nold list: empty list --  expecting to append 3545 -- obtaining\n");
    newlist = intlist_append(newlist, 3545);    
    intlist_show(newlist);
    intlist_free(newlist);
}

void evidence_intlist_prepend() {
    printf("\n\n***** testing Prob 1 : intlist_prepend *******\n");

    intlist* newlist = cons(10, cons(11, cons(12, cons(13, NULL))));
    printf("\nold list: 10 11 12 13 --  expecting to prepend 0 -- obtaining\n");
    newlist = intlist_prepend(newlist, 0);
    intlist_show(newlist);
    intlist_free(newlist);


    newlist = intlist_new();
    printf("\nold list: empty list --  expecting to prepend 3545 -- obtaining\n");
    newlist = intlist_prepend(newlist, 3545);
    intlist_show(newlist);
    intlist_free(newlist);
}

void evidence_intlist_show() {
    printf("\n\n***** testing Prob 1 : intlist_show *******\n");

    intlist* newlist = cons(10, cons(11, cons(12, cons(13, NULL))));
    printf("\nexpecting list: 10 11 12 13 --  obtaining\n");
    intlist_show(newlist);
    intlist_free(newlist);


    newlist = intlist_new();
    printf("\n\nexpecting list: empty list --  obtaining\n");
    intlist_show(newlist);
    intlist_free(newlist);

}

// evidence functions for problem 2 =======================
void print_sum_list(intlist* sum_list) {
    if (sum_list == NULL) {
        return;
    } else {
        print_sum_list(sum_list -> next);
    }
    printf("%d ", sum_list -> val);
}

void evidence_add_digits() {
    printf("\n\n***** testing Prob 2 : add_digits *******\n");

    intlist* newlist_1 = intlist_new();
    intlist* newlist_2 = intlist_new();
    intlist* sum_list = add_digits(100, newlist_1, newlist_2);
    printf("\nexpecting empty sum list -- obtaining: ");
    print_sum_list(sum_list);

    newlist_1 = cons(10, cons(11, cons(12, cons(13, NULL))));
    newlist_2 = cons(0, cons(6, cons(4, cons(6, NULL))));
    sum_list = add_digits(16, newlist_1, newlist_2);
    printf("\n\nexpecting sum list: 1 4 1 1 10 -- obtaining: ");
    print_sum_list(sum_list);
    intlist_free(newlist_1);
    intlist_free(newlist_2);
    intlist_free(sum_list);

    
    newlist_1 = cons(4, cons(6, cons(3, cons(5, NULL))));
    newlist_2 = cons(0, cons(6, cons(4, cons(6, NULL))));
    sum_list = add_digits(8, newlist_1, newlist_2);
    printf("\n\nexpecting sum list: 1 4 0 4 4 -- obtaining: ");
    print_sum_list(sum_list);
    printf("\n\n");
    intlist_free(newlist_1);
    intlist_free(newlist_2);
    intlist_free(sum_list);

}

/* main: run the evidence functions above ======================= */ 
int main(int argc, char *argv[]) {
    evidence_intlist_new();
    evidence_intlist_nth();
    evidence_intlist_set();
    evidence_intlist_show();
    evidence_intlist_append();
    evidence_intlist_prepend();
    evidence_add_digits();
}