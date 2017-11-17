#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hw4.h"

void evidence_find_replace() {
    printf("\n*** testing find_replace *****************\n");

    char* dest = (char*) malloc(13*sizeof(char));
    find_replace("hello world", "hello", "hi", dest);
    printf("\nexpecting : 'hi world' ||| obtaining: '%s' \n", dest);

    dest = (char*) malloc(13*sizeof(char));
    find_replace("hello world", "hallo", "hi", dest);
    printf("\nexpecting : 'hello world' ||| obtaining: '%s' \n", dest);

    dest = (char*) malloc(10*sizeof(char));
    find_replace("foofoofoo", "foo", "bar", dest);
    printf("\nexpecting : 'barbarbar' ||| obtaining: '%s' \n", dest);

    dest = (char*) malloc(26*sizeof(char));
    find_replace("the thing is there, then?", "the", "", dest);
    printf("\nexpecting : ' thing is re, n?' ||| obtaining: '%s' \n", dest);
    free(dest);
}

void print_split_array(char** split_array) {
    unsigned int i = 0;
    while (split_array[i] != NULL) {
        printf("'%s' \n", split_array[i]);
        free(split_array[i]);
        i++;
    }
}

void evidence_split_at() {
    printf("\n*** testing split_at *****************\n");
    char split_this[] = "my,name,is,the.greatest,ever", d = ',';
    char** split_array = split_at(split_this, d);    
    printf("\n--- splitting '%s' at '%c' ||| \n obtaining: \n", split_this, d);
    print_split_array(split_array);
    free(split_array);

    char split_this_1[] = ".period. at. first";
    d = '.';
    split_array = split_at(split_this_1, d);    
    printf("\n--- splitting '%s' at '%c' ||| \n obtaining: \n", split_this_1, d);
    print_split_array(split_array);
    free(split_array);

    char split_this_2[] = " space. at. first and last ";
    d = ' ';
    split_array = split_at(split_this_2, d);    
    printf("\n--- splitting '%s' at '%c' ||| \n obtaining: \n", split_this_2, d);
    print_split_array(split_array);
    free(split_array);
}

void evidence_analyze_weather() {
    printf("\n*** testing analyze_weather *****************\n");

    unsigned int num_obvs = 4;
    struct observations* all_obvs_array = (struct observations*) malloc(num_obvs * sizeof(struct observations));
    all_obvs_array[0].temp = 35; all_obvs_array[0].humid = 66; all_obvs_array[0].wind = 20;
    all_obvs_array[1].temp = -2; all_obvs_array[1].humid = 55; all_obvs_array[1].wind = 10;
    all_obvs_array[2].temp = 25; all_obvs_array[2].humid = 70; all_obvs_array[2].wind = 15;
    all_obvs_array[3].temp = 20; all_obvs_array[3].humid = 100; all_obvs_array[3].wind = 50;
    
    struct preferences sample_prefs = {{12,35}, {30, 80}, {5, 20}};
    struct climate sample_climate;
    struct compatibility sample_comp;

    analyze_weather(all_obvs_array, num_obvs, &sample_climate, &sample_prefs, &sample_comp);
    printf("\n expected temp stats: average 19.5, min -2, max 35-- obtained avg %lf min %lf max %lf",
            sample_climate.temps.avg, sample_climate.temps.min, sample_climate.temps.max);
    printf("\n\n expected humid stats: average 72.75, min 55, max 100 -- obtained avg %lf min %lf max %lf",
            sample_climate.humids.avg, sample_climate.humids.min, sample_climate.humids.max);
    printf("\n\n expected wind stats: average 23.75, min 10, max 50 -- obtained avg %lf min %lf max %lf",
            sample_climate.winds.avg, sample_climate.winds.min, sample_climate.winds.max);
   
    printf("\n\n expected num good days: 2 num bad days: 2 -- obtained num good days:  %u num bad days: %u ",
            sample_comp.good_days, sample_comp.bad_days);
    printf("\n\n expected happiness: 0.5 -- obtained happiness:  %lf ",
            sample_comp.happiness);
    
    unsigned int i;
    printf("\n\n-------- good days --------\n");
    for (i = 0; i < sample_comp.good_days; i++) {
        printf("\n obtained temp: %lf humid: %lf wind: %lf ",
               sample_comp.good_data[i]->temp, sample_comp.good_data[i]->humid, sample_comp.good_data[i]->wind);
    }
    printf("\n\n-------- bad days --------\n");
    for (i = 0; i < sample_comp.bad_days; i++) {
        printf("\n obtained temp: %lf humid: %lf wind: %lf ",
               sample_comp.bad_data[i]->temp, sample_comp.bad_data[i]->humid, sample_comp.bad_data[i]->wind);
    }
    free(all_obvs_array);


}

void evidence_mixture_weight() {
    printf("\n\n*** testing mixture_weight *****************\n");

    struct element hydrogen = {"hydrogen", 1};
    struct element oxygen = {"oxygen", 16};
    struct element sulphur = {"sulphur", 32};

    struct element** water_elements = (struct element**) malloc( 2 * sizeof(struct element*));
    water_elements[0] = &hydrogen;
    water_elements[1] = &oxygen;

    unsigned int* atoms = (unsigned int*) malloc( 2 * sizeof(unsigned int));
    atoms[0] = 2;
    atoms[1] = 1;

    struct molecule water = {"water", 2, water_elements, atoms};

    struct element* S = (struct element*) malloc( sizeof(struct element));
    struct molecule* H2O = (struct molecule*) malloc( sizeof(struct molecule));
    S = &sulphur;
    H2O = &water;
    
    union chemical water_chem;
    water_chem.molecule = H2O;

    union chemical sul_chem;
    sul_chem.element = S;

    struct tagged_chemical* mixture_chemicals = (struct tagged_chemical*) malloc( 2 * sizeof(struct tagged_chemical));
    mixture_chemicals[0].tag = MOLECULE;
    mixture_chemicals[0].chemical = water_chem;

    mixture_chemicals[1].tag = ELEMENT;
    mixture_chemicals[1].chemical = sul_chem;

    double* moles = (double*) malloc( 2 * sizeof(double));
    moles[0] = 2;
    moles[1] = 1;

    struct mixture water_sulf_mix = {"sulphur+water", 2, mixture_chemicals, moles};
    double mix_weight = mixture_weight(&water_sulf_mix);
    printf("\n expected mixture weight = 68 ||| obtained = %lf", mix_weight);

}

/* main: run the evidence functions above */

int main(int argc, char *argv[])
{
    evidence_find_replace();
    evidence_split_at();
    evidence_analyze_weather();
    evidence_mixture_weight();
    return 0;
}
