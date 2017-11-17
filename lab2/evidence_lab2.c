#include <stdlib.h>
#include <stdio.h>
#include "lab2.h"

void evidence_hex_char() {
    printf("\n*** testing hex_char\n");
    printf("- expecting 0E\n- obtaining ");
    hex_char(14);
    printf("\n\n- expecting 9C\n- obtaining ");
    hex_char(156);
    printf("\n\n- expecting 00\n- obtaining ");
    hex_char(0);
    printf("\n\n- expecting D9\n- obtaining ");
    hex_char(217);
}

void evidence_hex_int() {
    printf("\n\n*** testing hex_int\n");
    printf("- expecting 0002638C\n- obtaining ");
    hex_int(156556);
    printf("\n\n- expecting 00000000\n- obtaining ");
    hex_int(0);
    printf("\n\n- expecting 02983229\n- obtaining ");
    hex_int(43528745);
    printf("\n\n- expecting 0000002D\n- obtaining ");
    hex_int(45);
}

void evidence_octal_char() {
    printf("\n\n*** testing octal_char\n");
    printf("- expecting 000\n- obtaining ");
    octal_char(0);
    printf("\n\n- expecting 204\n- obtaining ");
    octal_char(132);
    printf("\n\n- expecting 015\n- obtaining ");
    octal_char(13);
}

void evidence_octal_int() {
    printf("\n\n***** testing octal_int\n");
    printf("- expecting 000000000000\n- obtaining ");
    octal_int(0);
    printf("\n\n- expecting 000024312051\n- obtaining ");
    octal_int(5346345);
    printf("\n\n- expecting 000000000031\n- obtaining ");
    octal_int(25);
}

void evidence_binary_char() {
    printf("\n\n*** testing binary_char\n");
    printf("- expecting 00001001\n- obtaining ");
    binary_char(17);
    printf("\n\n- expecting 00000000\n- obtaining ");
    binary_char(0);
    printf("\n\n- expecting 10110010\n- obtaining ");
    binary_char(178);
}

void evidence_binary_int() {
    printf("\n\n*** testing binary_int\n");
    printf("- expecting 00000000000000000000000000010001\n- obtaining ");
    binary_int(17);
    printf("\n\n- expecting 00000000000000000000000000000000\n- obtaining ");
    binary_int(0);
    printf("\n\n- expecting 10001011100111010111111101001110\n- obtaining ");
    binary_int(2342354766);
    printf("\n\n");
}

int main(int argc, char *argv[]) {

    evidence_hex_char();
    evidence_hex_int();
    evidence_octal_char();
    evidence_octal_int();
    evidence_binary_char();
    evidence_binary_int();
}

