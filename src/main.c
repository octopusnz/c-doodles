#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defines and constants live here */

#define MAX_ITEMS 10

/* Global structs live here */

typedef struct stock
{
    char promo_code[7];
    char name[20];
    float price;
    int stock_level;

} groceries;

/* Function prototypes live here */

void init_stock (groceries items[MAX_ITEMS], int items_length);
int check_promo (char promo1[], char promo2[]);
void get_stock (void);

/* Functions start here */

int main(void) {
    groceries items[MAX_ITEMS] = {{ {0}, {0}, 0, 0 }};
    int items_length = 0;

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
    init_stock(items, items_length);

    return 0;
}

void init_stock (groceries items[MAX_ITEMS], int items_length) {

    int i=0;
    int promo_success=0;

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

    for(i=0; i < items_length; i++) {
        printf("%-16s", items[i].name);
        printf("%-16.2f", items[i].price);
        printf("%-16s", items[i].promo_code);
        printf("%d", items[i].stock_level);
        printf("\n");
    }

    promo_success = check_promo(items[0].promo_code, items[1].promo_code);
    printf("\n\n");
    printf("And our promo result was:");
    printf ("%d\n", promo_success);

    get_stock();

}

int check_promo (char promo1[], char promo2[]) {

    if (strcmp (promo1, promo2) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void get_stock (void) {

    groceries user_items[MAX_ITEMS] = {{ {0}, {0}, 0, 0 }};
    groceries selected_items[MAX_ITEMS] = {{ {0}, {0}, 0, 0 }};
    int choice=0;
    int i=0;
    int user_items_length=0;
    int selected_items_length=0;
    int count=0;
    int selection=0;

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

    for(i=0, count=1; i < user_items_length; i++, count++) {

        printf("%-16d", count);
        printf("%-16s", user_items[i].name);
        printf("%-16.2f", user_items[i].price);
        printf("%-16s", user_items[i].promo_code);
        printf("%d", user_items[i].stock_level);
        printf("\n");
    }

    scanf("%d", &choice);

    switch(choice) {
    case 0 : exit(0);
    case 1 : printf("We've added %s to our selection!\n", user_items[0].name);
             selection=0;
             break;
    case 2 : printf("We've added %s to our selection!\n", user_items[1].name);
             selection=1;
             break;
    case 3 : printf("We've added %s to our selection!\n", user_items[2].name);
             selection=2;
             break;
    case 4 : printf("We've added %s to our selection!\n", user_items[3].name);
             selection=3;
             break;
    default : printf("Please enter 1, 2, 3 or 4. 0 will exit.\n");
   }

   selected_items_length = MAX_ITEMS

   for(i=0; i < selected_items_length; i++) {
       selected_items[i] = user_items[selection];
   }

   printf("\nThis got updated: %s\n", selected_items[0].name);
}
