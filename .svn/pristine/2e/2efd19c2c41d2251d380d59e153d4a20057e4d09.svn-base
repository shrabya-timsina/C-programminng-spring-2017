/* takes in a string 'src', searches for string 'from' within src, replaces 
instances of 'from' with a string 'to' and stores the final result in a 
string 'dest' */
void find_replace(char* src, char* from, char* to, char* dest);

// =================================================================

/*  takes in a string s and a delimiter d and splits the string into "words", 
starting a new word each time the delimiter character occurs. The words are 
returned in an array of strings. */
char** split_at(char* s, char d);

// =================================================================

// struct definitions for prob 3

struct observations {
    double temp;
    double humid;
    double wind;
};
struct range {
    double min, max;
};
struct preferences {
    struct range temps, humids, winds;
};
struct stats {
    double avg, min, max;
};
struct climate {
    struct stats temps, humids, winds;
};
struct compatibility {
    unsigned int good_days, bad_days;
    double happiness;
    struct observations **good_data, **bad_data;
};

/* Given  preferences and an array of daily weather observations, this 
calculate statistics (min, max and avg) for the climate in this location,
 and measure the compatibility for person who entered their preferences */
void analyze_weather(struct observations* observations,
                     unsigned int nobservations,
                     struct climate* climate,
                     struct preferences* preferences,
                     struct compatibility* compatibility);

// =================================================================

// struct definitions for prob 4

struct element {
    char* name;
    unsigned int weight;
};

struct molecule {
    char* name;
    unsigned int nelements;
    struct element** elements;
    unsigned int* atoms;
    /* there are atoms[i] atoms of element elements[i] */
};

union chemical {
    struct element* element;
    struct molecule* molecule;
};

enum chemical_tag {
    ELEMENT, MOLECULE
};

struct tagged_chemical {
    enum chemical_tag tag;
    union chemical chemical;
};

struct mixture {
    char* name;
    unsigned int nchemicals;
    struct tagged_chemical* chemicals;
    double* moles;
    /* there are moles[i] moles of chemical chemicals[i] */
};

/* calculates the weight in grams of the specified mixture 
   that is made up of chemicals*/
double mixture_weight(struct mixture* mixture);










