/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * HW 6
 */

 #include "hw6.h"

// ===> Problem 2: From Leafs to a Tree =======================================

tree* make_tree_recursive(char* leafs, unsigned int leaflen) {
    
    if (leaflen == 1) {
        tree* leaf_node = (tree*) malloc(sizeof(tree));
        leaf_node -> tag = LEAF;
        leaf_node -> u.leaf = leafs[0];
        return leaf_node;       
    } else {
        tree* inner_node = (tree*) malloc(sizeof(tree));
        inner_node -> tag = NODE;
        inner_node -> u.node.left = make_tree_recursive(leafs, leaflen/2);
        inner_node -> u.node.right = make_tree_recursive( (leafs + leaflen/2),
                                                           leaflen/2);
        return inner_node;
    }
}

tree* make_tree(char* leafs) {
    unsigned int leaflen = strlen(leafs);
    unsigned int temp = leaflen;
    while (((temp & 1) == 0) && temp > 1) {
        temp >>= 1;
    }
    if (temp != 1) {
        fprintf(stderr, "\nmake_tree: length of string is not a power of 2\n");
        exit(1);
    }
    return make_tree_recursive(leafs, leaflen);
} 

// ===> Problem 3: CRYP 10200 =======================================

unsigned int tree_height(tree *t) {
    if (t -> tag == LEAF) {
        return 0;
    } else {
        unsigned int height = tree_height(t -> u.node.left);
        return height + 1;
    }       
}

void decode_recursive(tree* key, char* cipher, char* decrypted, 
                      tree* root, unsigned int index) {
    
    if (!*cipher) {
        return;
    } else if (key -> tag == LEAF) {
        decrypted[index] = key -> u.leaf;
        decode_recursive(root, cipher + 1, decrypted, root, index + 1);
    } else {
        
        if (*cipher == 'L') {
            decode_recursive(key -> u.node.left, cipher + 1, decrypted, root, index);
        } else if (*cipher == 'R') {
            decode_recursive(key -> u.node.right, cipher + 1, decrypted, root, index);
        } else {
            decode_recursive(key, cipher + 1, decrypted, root, index);
        }
    }

}

char* decode(tree* key, char* cipher) {

    if (key -> tag == LEAF || key == NULL) {
        fprintf(stderr, "\ndecode: current root is not a node - cannot decode\n");
        exit(1);
    }

    unsigned int len_decrpyted = 0;
    char* temp = cipher;
    while (*temp) {
        if (*temp == 'L' || *temp == 'R') {
            len_decrpyted++;
        }
        temp++;
    }
    len_decrpyted /= tree_height(key);
    char* decrypted = (char*) malloc((len_decrpyted + 1) * sizeof(char));
    decode_recursive(key, cipher, decrypted, key, 0);
    decrypted[len_decrpyted] = '\0';
    return decrypted;
}
