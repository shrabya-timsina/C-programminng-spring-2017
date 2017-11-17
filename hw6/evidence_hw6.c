#include "hw6.h"
#include "matrix.h"

// evidence functions for problem 1

void evidence_matrix() {
    matrix *matrix_0 = matrix_zero(2,3);
    matrix_show(matrix_0);
    printf("\n adding 1.0 at 1,1 \n");
    matrix_write(matrix_0, 1,1, 1.0);
    matrix_show(matrix_0);
    matrix_free(matrix_0);

}



// evidence functions for problem 2

void print_tree(tree* to_print) {
    if (to_print) {
        if (to_print -> tag == LEAF) {
            printf("%c ", to_print -> u.leaf);
        } else {
            print_tree(to_print -> u.node.left);
            print_tree(to_print -> u.node.right);
        }
    }
}
void free_tree(tree* t) {
    if (t) {
        if (t -> tag == NODE) {
            free_tree(t -> u.node.left);
            free_tree(t -> u.node.right);
        }
        free(t);
    }
}
void evidence_make_tree() {
    printf("\n***** testing Prob 2 : make_tree *******\n\n");
    char sample[8];
    strcpy(sample, "namaste!");
    tree* test_tree = make_tree(sample);
    print_tree(test_tree);
    free_tree(test_tree);

}

// evidence functions for problem 3
void evidence_decode() {
    printf("\n\n***** testing Prob 3 : decode *******\n");

    char* message = "LLLR LLRR RRRR LRRR RRLL RLRL LLRR RRRR RLRR RLLR RRRR\
      LLRL RLRL LRLL RLLL LRLR RRRR RRRL RLLR RRLL RLRL RRRR RLLR RRLR LLLL LRRL\
      RLRR LRLL RLLL LLRR";
    char sample[16];
    strcpy(sample, "ABDEIKLSNORTUVY ");
    tree* test_tree = make_tree(sample);
    print_tree(test_tree);

    char* decrypted = decode(test_tree, message);
    printf("decoded message: %s ", decrypted);
    free(decrypted);
    free_tree(test_tree);


}


/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_matrix();
    evidence_make_tree();
    evidence_decode();
    return 0; 
}