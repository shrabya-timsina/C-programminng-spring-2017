// struct definitions ==================================
typedef struct intlist intlist;
struct intlist {
    int val;
    intlist* next;
};

//problem 1 ============================================

// makes a new, empty list
intlist* intlist_new();

// returns the nth value in the provided list, using zero-based indexing
int intlist_nth(intlist* xs, unsigned int n);

// overwrites the value in the list at the nth index with the specified new value
void intlist_set(intlist* xs, unsigned int n, int val);
 
//  appends the given value to the end of the specified list
intlist* intlist_append(intlist* xs, int val);

//  appends the given value to the beginning  of the specified list
intlist* intlist_prepend(intlist* xs, int val);

// prints the contents of a list to the screen
void intlist_show(intlist* xs);

//  reclaims the memory used by the linked list cells
void intlist_free(intlist* xs);

// problem 1 helper function also used in evidence file

intlist* cons(int fst, intlist*rst);

// problem 2 ============================================

//  takes two backwards-ordered lists of digits in the specified base 
// and adds them together into a single, well-formed digit list in the 
// same base
intlist* add_digits(unsigned char base, intlist* ds1, intlist* ds2);
