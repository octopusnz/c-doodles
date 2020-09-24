/* File: eight_utils.h
	 Location: ./src/headers/
*/

/* Global definitions and constants live here */

#define MAX_ITEMS 10

/* Global structs live here */

typedef struct stock
{
    char promo_code[7];
    char name[20];
    float price;
    int stock_level;

} groceries;

typedef struct cart
{

	groceries basket[MAX_ITEMS];
	int store_promo_status;
	float total_price;

} checkout;

/* Function prototypes live here */

size_t findlong_string (groceries items[], size_t items_length);
int get_stock (groceries user_items[], groceries selected_items[]);
void init_stock (groceries items[], size_t items_length);
int string_compare (char string1[], char string2[]);
checkout shopping (groceries items[], size_t *items_length, int *promo_code);
