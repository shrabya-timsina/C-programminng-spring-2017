#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

unsigned long int good_hash(char *s)
{
    unsigned int res = 17;
    while(*s) {
        res = (37 * res) + (*s);
        s++;
    }
    return res;
}

unsigned long int bad_hash(char *s)
{
    unsigned int res = 0;
    while(*s) {
        res += (*s);
        s++;
    }
    return res;
}

htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz)
{
    htbl* new_htbl = (htbl*) malloc(sizeof(htbl));
    new_htbl -> buckets = (bucket**) malloc(sizeof(bucket*) * sz);
    new_htbl -> hash = h;
    new_htbl -> n_buckets = sz;
    unsigned int i;
    for (i = 0; i < sz; i++) {
        new_htbl -> buckets[i] = NULL;
    }
    return new_htbl;
}

unsigned int htbl_n_entries(htbl *t)
{
    unsigned int n_entries = 0;
    if (t) {
        unsigned int i, buck_size;
        for (i = 0; i < t -> n_buckets; i++) {
            buck_size = bucket_size(t -> buckets[i]);
            n_entries += buck_size;
        }
    }

    return n_entries;
}

/* htbl_load_factor : htbl* -> float */
/* The load factor is the mean number of elements per bucket. */
double htbl_load_factor(htbl *t)
{
    unsigned int n_entries = htbl_n_entries(t);
    return  n_entries / (double)(t -> n_buckets);
}

unsigned int htbl_max_bucket(htbl *t)
{
    unsigned int max_buck_size = 0;
    if (t) {
        max_buck_size = bucket_size(t -> buckets[0]);
        unsigned int i, buck_size;
        for (i = 1; i < t -> n_buckets; i++) {
            buck_size = bucket_size(t -> buckets[i]);
            if (buck_size > max_buck_size) {
                max_buck_size = buck_size;
            }
        }
    }

    return max_buck_size;   
}

unsigned int htbl_insert(char *s, htbl *t)
{   
    unsigned long int hash_value = t -> hash(s);
    unsigned int hash_index = hash_value % (t -> n_buckets);
    t -> buckets[hash_index] = bucket_cons(s, hash_value,
                                           t -> buckets[hash_index]);
    return bucket_size(t -> buckets[hash_index]);
        
}

int htbl_member(char *s, htbl *t)
{
    unsigned long int hash_value = t -> hash(s);
    unsigned int hash_index = hash_value % (t -> n_buckets);
    bucket* temp = t -> buckets[hash_index];
    while (temp) {
        if (hash_value == temp -> hash) {
            if (strcmp(s, temp -> string) == 0) {
                return 1;
            }
        }
        temp = temp -> next;
    }
    return 0;
}

void htbl_show(htbl *t)
{
    printf("\n");
    if (t) {
        unsigned int i;
        for (i = 0; i < t -> n_buckets; i++) {
            printf("\n");
            printf("--> htbl_index: %u", i);
            bucket_show(t -> buckets[i]);
        }
        printf("\n");
    }

}

void htbl_free(htbl *t)
{ 
    if (t) {
        unsigned int i;
        for (i = 0; i < t -> n_buckets; i++) {
            bucket_free(t -> buckets[i]);
        }
        free(t -> buckets);
        free(t);
    }
    
}
