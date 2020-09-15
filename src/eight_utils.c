#include <stdio.h>
#include <string.h>

#include "eight_utils.h"

int string_compare (char string1[], char string2[]) {

    if (strcmp (string1, string2) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void findlong_string (groceries items[], size_t items_length) {

    size_t longest = strlen(items[0].name);
    size_t i = 0;
    size_t j = 0;
    size_t len = 0;

    printf("We in findlong now\n");

    for(i = 1; i < items_length; i++) {
        len = strlen(items[i].name);

        if(longest < len) {
            longest = len;
            j = i;
        }
    }
    printf("The number of characters is: %lu\n", longest);
    printf("The string is: %s\n", items[j].name);
}

