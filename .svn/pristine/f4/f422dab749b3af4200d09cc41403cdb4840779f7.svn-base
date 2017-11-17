#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tagged_tree tree;

struct node {
    tree *left, *right;
};

union tree_union {
    struct node node;
    char leaf;
};

enum tree_tag {
    NODE, LEAF
};

struct tagged_tree {
    enum tree_tag tag;
    union tree_union u;
};


tree* make_tree(char* leafs);

char* decode(tree* key, char* cipher);
