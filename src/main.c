/*******************************************************************************
* main.c
* location: ./src/
* project: c-doodles
* See license.txt in main project folder for copyright and license info
*******************************************************************************/

#include <stdio.h>
#include <string.h>

/* Structures defined */

typedef struct store
{
    int promo_status;
    char name[12];
    char stock[4];
} market;

typedef struct stock
{
    char promo_code;
    char name[10];
    float price;
    int stock_level;
} groceries;

/* Function prototypes */

int setup (char name[], char stock[], int stock_length, int promo_status);

/* Main function */

int main (void)
{
    char name[12] = "New World";
    int promo_status = 1;
    int test_counter = 0;
    char stock[4] = {'a'};
    int stock_length = sizeof stock;

    printf ("Name: %s\n", name);
    printf ("Promo Status: %d\n", promo_status);
    printf ("Test Counter: %d\n", test_counter);
    printf ("%d\n", stock_length);

    promo_status = setup (name, stock, stock_length, promo_status);

    printf ("We in main now\n");
    printf ("%d\n", promo_status);

    return 0;
}

int setup (char name[], char stock[], int stock_length, int promo_status)
{
    market supermarket;
    supermarket.promo_status = promo_status;
    strcpy (supermarket.name, name);

    printf ("Original Name: %s\n", name);
    printf ("Original Promo: %d\n", promo_status);
    printf ("Super Name: %s\n", supermarket.name);
    printf ("Super Promo: %d\n", supermarket.promo_status);

    promo_status++;

    return promo_status;
}
