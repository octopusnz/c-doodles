#include <stdio.h>
#include <string.h>

#include "./headers/eight_utils.h"

int string_compare (char string1[], char string2[]) {

    if (strcmp (string1, string2) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

size_t findlong_string (groceries items[], size_t items_length) {

    size_t longest = strlen(items[0].name);
    size_t i = 0;
    size_t len = 0;

    for (i = 1; i < items_length; i++) {
        len = strlen(items[i].name);

        if (longest < len) {
            longest = len;
        }
    }
    return longest;
}
