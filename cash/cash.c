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

int get_cents(void)
{
    int num;
    do
    {
        // Prompt the user
        num = get_int("Changes owed: ");
    } while (num < 0); // Prompt untill valid input
    return num;
}

int calculate_quarters(int cents)
{
    // Check if cents is greater than or equal to 25(a quarter)
    if (cents >= 25)
    {
        // Get remainder
        int remainder = cents % 25;

        // Calculate number of quarters
        int quarters = (cents - remainder) / 25;
        return quarters;
    }
    else
    {
        return 0;
    }
}

int calculate_dimes(int cents)
{
    // Check if cents is greater than or equal to 10(a dime)
    if (cents >= 10)
    {
        // Get remainder
        int remainder = cents % 10;

        // Calculate number of dimes
        int dimes = (cents - remainder) / 10;
        return dimes;
    }
    else
    {
        return 0;
    }
}

int calculate_nickels(int cents)
{
    // Check if cents is greater than or equal to 5(a nickel)
    if (cents >= 5)
    {
        // Get remainder
        int remainder = cents % 5;

        // Calculate number of nickels
        int nickels = (cents - remainder) / 5;
        return nickels;
    }
    else
    {
        return 0;
    }
}

int calculate_pennies(int cents)
{
    // Check if cents is greater than or equal to 1(a penny)
    if (cents >= 1)
    {
        return cents;
    }
    else
    {
        return 0;
    }
}
