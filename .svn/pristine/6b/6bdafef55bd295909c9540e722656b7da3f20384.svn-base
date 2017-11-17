/* graded lab2 */

/* ====== Makefile ====== */

# Makefile for CS152 2017 Lab 6

.PHONY: clean

adrbook: cmd.h cmd.c shell.h shell.c adrbook.h bst.c vcard.c adrbook.c
	clang -g -o adrbook -Wall vcard.c bst.c shell.c cmd.c adrbook.c -lm

# type 'make clean' to remove the executable and debug information
clean:
	rm -rf a.out adrbook *.dSYM

/* ====== bst.h ====== */

missing file: bst.h

/* ====== bst.c ====== */

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

/* ====== vcard.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"
#include <string.h>

const char *_vcard_todo_format = "TODO [vcard]: %s\nhalting\n";

/* vcard_new : allocate a new vcard, copy all strings, return new object
 * note: this is a "deep copy" as opposed to a "shallow copy"; the string 
 *   arguments are not to be shared by the newly allocated vcard
 */
vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
    vcard* new_card = (vcard*) malloc(sizeof(vcard));
    new_card -> cnet = strdup(cnet);
    new_card -> email = strdup(email);
    new_card -> fname = strdup(fname);
    new_card -> lname = strdup(lname);
    new_card -> tel = strdup(tel);
    return new_card;
}

/* vcard_free : free vcard and the strings it points to
 */
void vcard_free(vcard *c)
{
    if (c) {
        free(c -> cnet); 
        free(c -> email);  
        free(c -> fname);  
        free(c -> lname);  
        free(c -> tel);  
        free(c);
    }
    
}

void vcard_show(FILE *f, vcard *c)
{
    fprintf(f, "cnet %s", c -> cnet);
    fprintf(f, "\nemail %s", c -> email);
    fprintf(f, "\nfname %s", c -> fname);
    fprintf(f, "\nlname %s", c -> lname);
    fprintf(f, "\ntel %s\n", c -> tel);
}

/* ====== evaluation ======  */

/* === correctness === */

/* vcard_new:                           / 4 */
/* vcard_free:                          / 2 */
/* vcard_show:                          / 3 */

/* bst_singleton:                       / 2 */
/* bst_insert:                  2        / 8 */
/* bst_num_entries:                     / 5 */
/* bst_height:                          / 5 */
/* bst_search:                  2        / 8 */
/* bst_c:                      2         / 8 */
/* bst_free:                            / 3 */

/* === style === */

/* code layout                          / 8 */
/* identifiers are well named           / 6 */

/* functions are well designed          / 6 */
/* code is well factored                / 6 */

/* code is written clearly              / 8 */
/* code is efficient                    / 6 */

/* adequate tests                       / 8 */
/* svn used correctly                   / 4 */

/* _total-score_                   82     /100 */

/* graded by GRADER'S_NAME_HERE :chaojie
*/
