/* Shrabya Timsina, shrabya
 * CS 152, Spring 2017
 * HW 4 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hw4.h"

// ===> Problem 1: Strings: Find and Replace ====================

void find_replace(char* src, char* from, char* to, char* dest) {
    unsigned int len_src = strlen(src), len_from = strlen(from);
    unsigned int len_to = strlen(to);    
    if (len_to > len_from) {
        fprintf(stderr, \
            "find_replace: lenght of replacement string 'to' cannot exceed that of original 'from' \n");
        exit(1);
    }
    unsigned int dest_idx = 0, src_idx = 0, i, j;
    while (src[src_idx]) {
        if (src_idx <= len_src - len_from) {
            for (i = 0; i < len_from; i++) {
                if (src[src_idx + i] != from[i]) {
                    break;        
                }
            }
        } 
        if (i == len_from) {
            for (j=0; to[j]; j++) {
                dest[dest_idx + j] = to[j]; 
            }
            dest_idx += len_to;
            src_idx += len_from;
        } else { 
            dest[dest_idx] = src[src_idx];
            dest_idx++;
            src_idx++;
        }
        i = 0;
    }
    dest[dest_idx] = '\0'; 
}


// ===> Problem 2: Strings: Splitting ===============================

/* helper function to find the length of required split words array */
unsigned int len_split_words(char* s, char d) {
    // i start at 1 so that we can ignore if first letter is delimiter
    unsigned int i = 1, num_words = 0; 
    while (s[i]) {
        if (s[i] == d) {
            num_words++;
        }
        i++;
    }
    if (s[i-1] == d) { // if last index is delimiter, we can ingore it
        return num_words;
    }
    return num_words + 1; 
}

char** split_at(char* s, char d) {
    unsigned int num_words = len_split_words(s, d);
    char** splits_array = (char**) malloc((num_words + 1) * sizeof(char*));
    unsigned int i = 0, array_idx = 0, word_len, j;
    while (array_idx < num_words) {
        for (word_len = 0; 
            s[i + word_len] && s[i + word_len] != d; word_len++) {
            ;
        }
        if (word_len == 0) { // checking to see if encountered delimiter
            if (s[i+1] == d) { // checking to see if adjacent also delimiter               
                splits_array[array_idx] = (char*) malloc(2 * sizeof(char));
                strcpy(splits_array[array_idx],  "");
                array_idx++;
            }         
            i++;
        } else { // going on to split word
            splits_array[array_idx] = (char*) malloc((word_len + 1) * sizeof(char));
            for (j = 0; j < word_len; j++) {
                splits_array[array_idx][j] = s[i+j];
            }
            splits_array[array_idx][j] = '\0';
            i += word_len;
            array_idx++;
        }
        
    }
    splits_array[array_idx] = NULL;    
    return splits_array;
}


// ===> Problem 3: structs: Weather ======================================


void check_min(double current_value, struct stats* variable) {
    if (current_value < variable -> min) { variable -> min = current_value; }
}
void check_max(double current_value, struct stats* variable) {
    if (current_value > variable -> max) { variable -> max = current_value; }
}

double find_avg(double total, unsigned int nobservations) {
    return total/nobservations;
}

unsigned int check_if_in_range(double current_value, struct range* variable) {
    if ((current_value >= variable -> min) && (current_value <= variable -> max)) {
        return 1;
   }
   return 0;
}

void check_good_bad_day(struct compatibility* compatibility, 
                            struct preferences* preferences,
                            struct observations* observation,
                            unsigned int* good_idx,
                            unsigned int* bad_idx) {

    unsigned int temp_check = check_if_in_range(observation -> temp, &(preferences -> temps));
    unsigned int hum_check = check_if_in_range(observation -> humid, &(preferences -> humids));
    unsigned int wind_check = check_if_in_range(observation -> wind, &(preferences -> winds));
    
    if (temp_check + hum_check + wind_check == 3) {
        compatibility -> good_days += 1;
        compatibility -> good_data[*good_idx] = observation;
        (*good_idx)++;
    } else {
        compatibility -> bad_days += 1;
        compatibility -> bad_data[*bad_idx] = observation;
        (*bad_idx)++;
    }
}

void analyze_weather(struct observations* observations,
                     unsigned int nobservations,
                     struct climate* climate,
                     struct preferences* preferences,
                     struct compatibility* compatibility) {
    
    double total_temp = 0; 
    climate -> temps.min = observations[0].temp;
    climate -> temps.max = observations[0].temp;

    double total_humid = 0; 
    climate -> humids.min = observations[0].humid;
    climate -> humids.max = observations[0].humid;

    double total_wind = 0; 
    climate -> winds.min = observations[0].wind;
    climate -> winds.max = observations[0].wind;

    compatibility -> good_data = (struct observations**) \
                                     malloc(nobservations * sizeof(struct observations*));
    compatibility -> bad_data = (struct observations**) \
                                     malloc(nobservations * sizeof(struct observations*));
    compatibility -> good_days = 0;
    compatibility -> bad_days = 0;

    unsigned int i, good_idx = 0, bad_idx = 0;
    for (i = 0; i < nobservations; i++) {
        total_temp += observations[i].temp;
        check_min(observations[i].temp, &(climate -> temps));
        check_max(observations[i].temp, &(climate -> temps));
      
        total_humid += observations[i].humid;
        check_min(observations[i].humid, &(climate -> humids));
        check_max(observations[i].humid, &(climate -> humids));

        total_wind += observations[i].wind;
        check_min(observations[i].wind, &(climate -> winds));
        check_max(observations[i].wind, &(climate -> winds));

        check_good_bad_day(compatibility, preferences, &(observations[i]), &good_idx, &bad_idx); 
    }
    climate -> temps.avg = find_avg(total_temp, nobservations);
    climate -> humids.avg = find_avg(total_humid, nobservations);
    climate -> winds.avg = find_avg(total_wind, nobservations);
    compatibility -> happiness = (double) (compatibility -> good_days) / nobservations;

}


// ===> Problem 4: Tagged unions: Chemistry ===========================

double mixture_weight(struct mixture* mixture) {

    unsigned int i, j;
    unsigned int num_chemicals = mixture->nchemicals, num_elements, number_atoms;
    double mix_weight = 0, num_moles_of_chem, chemical_weight, element_weight, molecule_weight;
    
    for (i = 0; i < num_chemicals; i++) {       
        num_moles_of_chem = mixture -> moles[i];

        switch(mixture->chemicals[i].tag) {

            case ELEMENT:
                element_weight = mixture->chemicals[i].chemical.element->weight;
                chemical_weight = num_moles_of_chem * element_weight;
                break;

            case MOLECULE:
                num_elements = mixture->chemicals[i].chemical.molecule->nelements;
                molecule_weight = 0;
                for (j = 0; j < num_elements; j++) {
                    
                    element_weight = mixture->chemicals[i].chemical.molecule->elements[j]->weight;
                    number_atoms = mixture->chemicals[i].chemical.molecule->atoms[j];
                    molecule_weight += element_weight * number_atoms;
                }
                chemical_weight = molecule_weight * num_moles_of_chem;
                break;

            default:
                fprintf(stderr, \
                        "mixture_weight: chemical must be ELEMENT or MOLECULE \n");
                exit(1);
        }
        mix_weight += chemical_weight;
    }
    return mix_weight;
}










