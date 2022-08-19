#include <cs50.h>
#include <stdio.h>

int check_card_type(long number);
bool is_valid(long number);

int main(void)
{
    long card_number = get_long("Number: ");
    while (card_number < 0)
    {
        card_number = get_long("Number: ");
    }

    int card = check_card_type(card_number);
}

int check_card_type(long number)
{
    int first_digit;
    for (int i = 10; number > 0; number /= 10)
    {
        first_digit = number % i;
    }
    if (first_digit == 3)
    {
        return 1;
    }
    else if (first_digit == 5)
    {
        return 2;
    }
    else if (first_digit == 4)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

bool is_valid(long number)
{
    int odd_last_sum = 0, even_last_sum = 0;
    for (int i = 1, q = 10; number > 0;i++, number /= 10)
    {
        int remainder = number % 10;
        if (i % 2 == 0)
        {
            int product = remainder * 2;
            
        }
    }
}