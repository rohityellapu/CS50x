#include <cs50.h>
#include <stdio.h>

bool is_legit(long number);
int check_card_type(long number);


int main(void)
{
    // Prompt the user for Card Number.
    long card_number = get_long("Number: ");

    // Prompt forever untill valid input number.
    while (card_number < 0)
    {
        card_number = get_long("Number: ");
    }
    // Check whether the number is legit according to Luhn's Algorithm
    if (is_legit(card_number))
    {
        int card = check_card_type(card_number);
        if (card == 0)
        {
            printf("INVALID\n");
        }
        else if (card == 1)
        {
            printf("AMEX\n");
        }
        else if (card == 2)
        {
            printf("MASTERCARD\n");
        }
        else if (card == 3)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// Luhn's Algorithm checks whether card is legit or not.
bool is_legit(long number)
{
    // Sum of odd digit placed number and even digit placed number*2 from last
    int odd_last_sum = 0, even_last_sum = 0;

    // For each digit in the number.
    for (int i = 1; number > 0; i++, number /= 10)
    {
        int remainder = number % 10;
        if (i % 2 == 0)
        {
            // Multiplying the digit with 2
            int product = remainder * 2;

            // Summing the digits of product if it is two digit
            if (product > 9)
            {
                int sum = 0;
                while (product > 0)
                {
                    sum += product % 10;
                    product /= 10;
                }
                product = sum;
            }
            even_last_sum += product;
        }
        else
        {
            // Sum of all other digit numbers which are not multiply by 2.
            odd_last_sum += remainder;
        }
    }
    // Total sum
    int total_sum = odd_last_sum + even_last_sum;

    // If the last digit of sum ends with 0 return true
    if (total_sum % 10 == 0)
    {
        return true;
    }
    return false;
}

// Returns the type of the card if it is
int check_card_type(long number)
{
    int first_digit, second_digit, total_digits = 0;
    while (number > 0)
    {
        first_digit = number % 10;
        if (number > 9 && number < 100)
        {
            second_digit = number % 10;
        }
        total_digits++;
        number /= 10;
    }
    if (total_digits == 15)
    {
        int first_two = first_digit * 10 + second_digit;
        if (first_two == 34 || first_two == 37)
        {
            return 1;
        }
    }
    else if (total_digits == 13 || total_digits == 16)
    {
        if (first_digit == 4)
        {
            return 3;
        }
        if (first_digit == 5)
        {
            if (second_digit < 6 && second_digit > 0)
            {
                return 2;
            }
        }
    }

    return 0;
}
