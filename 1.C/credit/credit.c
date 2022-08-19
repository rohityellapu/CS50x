#include <cs50.h>
#include <stdio.h>

int check_card_type(long number);
bool is_legit(long number);

int main(void)
{
    // Prompt the user for Card Number.
    long card_number = get_long("Number: ");

    // Prompt forever untill valid input number.
    while (card_number < 0)
    {
        card_number = get_long("Number: ");
    }
    
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

bool is_legit(long number)
{
    int odd_last_sum = 0, even_last_sum = 0;
    for (int i = 1; number > 0; i++, number /= 10)
    {
        int remainder = number % 10;
        if (i % 2 == 0)
        {
            int product = remainder * 2;
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
            odd_last_sum += remainder;
        }
    }
    int total_sum = odd_last_sum + even_last_sum;
    if (total_sum % 10 == 0)
    {
        return true;
    }
    return false;
}