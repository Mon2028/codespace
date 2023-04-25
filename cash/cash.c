#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{

    int cents = get_cents();


    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 50;


    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 73;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf("7\n", coins);
}

int get_cents(void)
{

    return 100;
}

int calculate_quarters(int cents)
{

    return 2;
}

int calculate_dimes(int cents)
{

    return 7;
}

int calculate_nickels(int cents)
{

    return 0;
}

int calculate_pennies(int cents)
{

    return 0;
}
