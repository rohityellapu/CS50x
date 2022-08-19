#include <cs50.h>
#include <stdio.h>

int check_card_type(long number);

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
    if(first_digit == 3)
    {
        return 1;
    }
    else if(first_digit == 5)
    {
        return 2;
    }
    else if(first_digit == 4)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}