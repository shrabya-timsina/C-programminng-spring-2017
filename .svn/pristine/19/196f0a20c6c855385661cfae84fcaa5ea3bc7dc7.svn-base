#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

bucket *bucket_cons(char *s, unsigned long int hash, bucket *b)
{
    bucket* new_bucket = (bucket*) malloc(sizeof(bucket));
    new_bucket -> string = strdup(s);
    new_bucket -> hash = hash;
    new_bucket -> next = b;
    return new_bucket;
}

unsigned int bucket_size(bucket *b)
{
    unsigned int size = 0;
    while (b) {
        size++;
        b = b -> next;
    }
    return size;
}

void bucket_show(bucket *b)
{ 
    while (b) {
        printf(" || hash value: %lu ", b -> hash);
        printf("string: %s ", b -> string); 
        b = b -> next; 
    }
}

void bucket_free(bucket *b)
{
    if (!b) {
        ;
    } else {
        bucket_free(b -> next);
        if (b -> string) {
            free(b -> string);
        }
        free(b);
    }
}

