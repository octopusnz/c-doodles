#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "eight_utils.h"

/* Functions start here */

int main (int argc, char *argv[]) {

    groceries items[MAX_ITEMS] = {{ {0}, {0}, 0, 0 }};
    size_t items_length = 0;
    int promo_status = 0;
    size_t *p_items_length;
    int *p_promo_status;

    p_items_length = &items_length;
    p_promo_status = &promo_status;

    if (argc == 2) {
        if (strcmp(argv[1], "promotion") == 0) {
             promo_status = 1;
        }
    }

    strcpy (items[0].name, "Apple");
    items[0].price = 1.99;
    strcpy (items[0].promo_code, "abc123");
    items[0].stock_level = 4;

    strcpy (items[1].name, "Banana");
    items[1].price = 4.99;
    strcpy (items[1].promo_code, "abc123");
    items[1].stock_level = 5;

    strcpy (items[2].name, "Pear");
    items[2].price = 2.99;
    strcpy (items[2].promo_code, "def456");
    items[2].stock_level = 6;

    strcpy (items[3].name, "Peach");
    items[3].price = 9.99;
    strcpy (items[3].promo_code, "def456");
    items[3].stock_level = 7;

    items_length = 4;

    findlong_string(items, items_length);
    init_stock(items, items_length);
    shopping (items, p_items_length, p_promo_status);

    return 0;
}

void init_stock (groceries items[], size_t items_length) {

    size_t i = 0;
    int promo_success = 0;
    size_t selected_items_length = 0;
    size_t user_items_length = 4;

    groceries user_items[MAX_ITEMS] = { {{0}, {0}, 0, 0} };
    groceries selected_items[MAX_ITEMS] = { {{0}, {0}, 0, 0} };

    /* TO-DO: Calculate the length of longest string and use that for offset */
    printf("***************************************************************\n");
    printf("\n\tWelcome to the Mega Mart!\n");
    printf("\tIt is an exciting time for retail.\n\n");
    printf("***************************************************************\n");
    printf("\n");
    printf("We have the following items in stock:\n");
    printf("\n");
    printf("%-15s %-15s %-15s %s", "Name", "Price($)", "PromoCode", "Quantity");
    printf("\n");

    for(i = 0; i < items_length; i++) {
        printf("%-16s", items[i].name);
        printf("%-16.2f", items[i].price);
        printf("%-16s", items[i].promo_code);
        printf("%d", items[i].stock_level);
        printf("\n");
    }

    promo_success = string_compare(items[0].promo_code, items[1].promo_code);
    printf("\n\n");
    printf("And our promo result was:");
    printf ("%d\n", promo_success);

    selected_items_length = get_stock(user_items, selected_items);

    printf("We back in init now\n");
    printf("Lets try and print the array:\n");

    printf("\nUser Items:\n");

    for(i = 0; i < user_items_length; i++) {
        printf("%-16s", user_items[i].name);
        printf("%-16.2f", user_items[i].price);
        printf("%-16s", user_items[i].promo_code);
        printf("%d", user_items[i].stock_level);
        printf("\n");
    }

    printf("\nSelected Items:\n");

    for(i = 0; i < selected_items_length; i++) {
        printf("%-16s", selected_items[i].name);
        printf("%-16.2f", selected_items[i].price);
        printf("%-16s", selected_items[i].promo_code);
        printf("%d", selected_items[i].stock_level);
        printf("\n");
    }
}

int get_stock (groceries user_items[], groceries selected_items[]) {

    int choice1 = 0;
    int i = 0;
    int user_items_length = 0;
    int selected_items_length = 0;
    int count = 0;
    int selection = 0;
    int valid_input = 0;
    int error_counter = 0;

    strcpy (user_items[0].name, "Chocolate");
    user_items[0].price = 3.99;
    strcpy (user_items[0].promo_code, "zzz244");
    user_items[0].stock_level = 4;

    strcpy (user_items[1].name, "Hot Chocolate");
    user_items[1].price = 4.99;
    strcpy (user_items[1].promo_code, "zzz244");
    user_items[1].stock_level = 5;

    strcpy (user_items[2].name, "Bubbly Water");
    user_items[2].price = 2.99;
    strcpy (user_items[2].promo_code, "def456");
    user_items[2].stock_level = 6;

    strcpy (user_items[3].name, "Ginger Ale");
    user_items[3].price = 9.99;
    strcpy (user_items[3].promo_code, "abc123");
    user_items[3].stock_level = 7;

    user_items_length = 4;

    printf("\n");
    printf("You can request up to 2 more items from our warehouse.\n");
    printf("They'll be added into our store and you can shop for them!\n");

    printf("***************************************************************\n");
    printf("\n\tCheck out our special on Chocolate!\n\n");
    printf("***************************************************************\n");
    printf("Please enter an option between 1-4. 0 will exit the program.\n");
    printf("\n");
    printf("%-15s %-15s %-15s %-15s %s", "Option", "Name", "Price($)",\
           "PromoCode", "Quantity");
    printf("\n");

    for(i = 0, count = 1; i < user_items_length; i++, count++) {

        printf("%-16d", count);
        printf("%-16s", user_items[i].name);
        printf("%-16.2f", user_items[i].price);
        printf("%-16s", user_items[i].promo_code);
        printf("%d", user_items[i].stock_level);
        printf("\n");
    }

    /* TO-DO: Santize user input, maybe with fgets()? */

    do {
        printf("Your choice: ");
        scanf("%d", &choice1);

        if (choice1 == 0) {
            exit(0);
        }
        if (choice1 == 1) {
            printf("We've added %s to our selection!\n", user_items[0].name);
            selected_items[selection] = user_items[0];
            selection++;
            selected_items_length++;
            valid_input++;
            printf("Input Counter is: %d\n", valid_input);
            continue;
        }
        if (choice1 == 2) {
            printf("We've added %s to our selection!\n", user_items[1].name);
            selected_items[selection] = user_items[1];
            selection++;
            selected_items_length++;
            valid_input++;
            continue;
        }
        if (choice1 == 3) {
            printf("We've added %s to our selection!\n", user_items[2].name);
            selected_items[selection] = user_items[2];
            selection++;
            selected_items_length++;
            valid_input++;
            continue;
        }
        if (choice1 == 4) {
            printf("We've added %s to our selection!\n"\
                   , user_items[3].name);
            selected_items[selection] = user_items[3];
            selection++;
            selected_items_length++;
            valid_input++;
            continue;
        }
        else {
            printf("Please enter 1, 2, 3 or 4. 0 will exit.\n");
            error_counter++;
            continue;
        }
    } while(valid_input < 2 && error_counter < 3);

    if (error_counter >= 3) {
        printf("We couldn't understand your input so we'll exit. Bye!\n");
        exit(0);
    }

   for(i = 0; i < selected_items_length; i++) {
       printf("\nThis got updated: %s\n", selected_items[i].name);
   }

   return selected_items_length;
}

checkout shopping (groceries items[], size_t *items_length, int *promo_code) {

    checkout my_cart = { {{ {0}, {0}, 0, 0 }}, 0, 0 };

    float total_price = 0.00;
    size_t i = 0;

    for (i = 0; i < *items_length; i++) {
        total_price += items[i].price;
    }

     for (i = 0; i < *items_length; i++) {
        my_cart.basket[i] = items[i];
    }

    my_cart.total_price = total_price;
    my_cart.store_promo_status = *promo_code;

    printf("Total: %.2f\n", my_cart.total_price);
    printf("Promo Status: %d\n", my_cart.store_promo_status);

    return my_cart;

}
