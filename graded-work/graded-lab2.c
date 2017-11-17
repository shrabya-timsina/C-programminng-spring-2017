/* graded lab2 */

/* ====== Makefile ====== */

lab2 : lab2.h lab2.c evidence_lab2.c
	clang -Wall -o ev lab2.c evidence_lab2.c

/* ====== lab2.h ====== */

void hex_char(unsigned char byte); 
void hex_int(unsigned int n);

void octal_char(unsigned char byte);  
void octal_int(unsigned int n);

void binary_char(unsigned char byte);  
void binary_int(unsigned int n);

/* ====== lab2.c ====== */

/* Shrabya Timsina, shrabya
* CS 152, Spring 2017
 * HW 1 
 */


#include <stdio.h>
void converter(unsigned int input, unsigned char digit_index, \
                                                  unsigned char base) {

    if (digit_index == 0) { /*at the leading (left-most) position*/
        return; 
    } 
    if (digit_index > 0) {
        converter(input / base, digit_index-1, base);
    }

    unsigned char current_digit = input % base;

    if (current_digit > 9) { /* if the base is 16*/
        switch(current_digit) {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F") ;
                break;
        }
    } else {
        printf("%d", current_digit);
    }    
}

void hex_char(unsigned char byte) {

     converter(byte, 2, 16);
}

void hex_int(unsigned int n) {
     converter(n, 8, 16);
}

void octal_char(unsigned char byte) {
     converter(byte, 3, 8);
}

void octal_int(unsigned int n) {
     converter(n, 12, 8);
}

void binary_char(unsigned char byte) {
     converter(byte, 8, 2);
}

void binary_int(unsigned int n) {
     converter(n, 32, 2);
}








    







/* ====== evidence_lab2.c ====== */

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


/* ====== evaluation ======  */

/* === correctness === */

/* binary_char:                         / 8 */
/* octal_char:                          /12 */
/* hex_char:                            /16 */

/* binary_int:                          / 4 */
/* octal_int:                       3    / 4 */// printed one digit more
/* hex_in t:                            / 4 */

/* === style === */

/* code layout                          / 8 */
/* identifiers are well named           / 6 */

/* functions are well designed          / 6 */
/* code is well factored                / 6 */

/* code is written clearly              / 8 */
/* code is efficient                    / 6 */

/* adequate tests                       / 8 */
/* svn used correctly                   / 4 */

/* _total-score_                    99    /100 */

/* graded by Chaojie */
