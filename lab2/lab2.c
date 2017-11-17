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








    






