#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents()
{
    int cents;
    do
    {
        cents = get_int("How mant cents do you owe?= ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int a = 0;
    while (cents >= 25)
    {
        a++;
        cents = cents - 25;
    }
    return a;
}

int calculate_dimes(int cents)
{
    int b = 0;
    while (cents >= 10)
    {
        b++;
        cents = cents - 10;
    }
    return b;
}

int calculate_nickels(int cents)
{
    int c = 0;
    while (cents >= 5)
    {
        c++;
        cents = cents - 5;
    }
    return c;
}

int calculate_pennies(int cents)
{
    int d = 0;
    while (cents >= 1)
    {
        d++;
        cents = cents - 1;
    }
    return d;
}