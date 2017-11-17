#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

bst *bst_singleton(vcard *c)
{
    bst* leaf_node = (bst*) malloc(sizeof(bst));
    leaf_node -> c = c;
    leaf_node -> lsub = NULL;
    leaf_node -> rsub = NULL;
    return leaf_node;
}
// =============================================================

int bst_insert_recursive(bst **t, vcard *c) 
{
    if (*t == NULL) {
        *t = bst_singleton(c);
        return 1;
    } else if (strcmp((*t) -> c -> cnet, c -> cnet) < 0) {
        bst_insert_recursive(&((*t) -> rsub), c); 
    } else if (strcmp((*t) -> c -> cnet, c -> cnet) > 0) {
        bst_insert_recursive(&((*t) -> lsub), c);

    } else {
        //printf("here");
        return 0;
    
    }
}

int bst_insert(bst *t, vcard *c)
{
    if (t==NULL) {
        fprintf(stderr, "bst_insert: you cannot input empty bst");
        exit(1);
    }
    int return_val = bst_insert_recursive(&t, c);
    return return_val;
}
// =============================================================

void bst_num_entries_recursive(bst *t, unsigned int* entry_count) 
{
    if (t==NULL) {
       return;
    } else {
        (*entry_count)++;
        bst_num_entries_recursive(t -> lsub, entry_count);
        bst_num_entries_recursive(t -> rsub, entry_count);
    }
}

unsigned int bst_num_entries(bst *t)
{
    unsigned int num_entries = 0;
    bst_num_entries_recursive(t, &num_entries);
    return num_entries;
}
// =============================================================

unsigned int bst_height(bst *t)
{
    if (t==NULL) {
        return 0;
    } else {
        unsigned int lsub_height = bst_height(t -> lsub);
        unsigned int rsub_height = bst_height(t -> rsub);
        if (lsub_height > rsub_height) {
            return lsub_height + 1;
        } else {
            return rsub_height + 1;
        }
    }
}
// =============================================================

vcard *bst_search_recursive(bst *t, char *cnet, int *n_comparisons)
{
    (*n_comparisons)++;
    if (t == NULL) {
        return NULL;
    }
    if (strcmp(t -> c -> cnet, cnet) == 0) {
        return t -> c;
    } else if (strcmp(t -> c -> cnet, cnet) < 0) {
        return bst_search_recursive(t -> lsub, cnet, n_comparisons); 
    } else {
        return bst_search_recursive(t -> rsub, cnet, n_comparisons);
    }
}

vcard *bst_search(bst *t, char *cnet, int *n_comparisons) {
    *n_comparisons = 0;
    return bst_search_recursive(t, cnet, n_comparisons);
}
// =============================================================

void bst_c_recursive(FILE *f, bst *t, char c, unsigned int* match_count)
{
    if (t == NULL) {
        return;
    }
    if ((t -> c -> cnet[0]) == c) {
        (*match_count)++;
        bst_c_recursive(f, t -> lsub, c, match_count);
        bst_c_recursive(f, t -> rsub, c, match_count);
    } else {
        if ((t -> c -> cnet[0]) < c) {
            bst_c_recursive(f, t -> lsub, c, match_count); 
        } else {
            bst_c_recursive(f, t -> rsub, c, match_count);
        }
        return;
    }
    fprintf(f, "\n%s", t -> c -> cnet);
}

unsigned int bst_c(FILE *f, bst *t, char c) 
{
    unsigned int num_matches = 0;
    bst_c_recursive(f, t, c, &num_matches);
    return num_matches;
}
// =============================================================

void bst_free(bst *t)
{
    if (t) {
        bst_free(t -> lsub);
        bst_free(t -> rsub);
        free(t);
    }
}
