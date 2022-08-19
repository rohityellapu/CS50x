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
    if(is_valid(card_number))
    {
        printf("Yes\n");
    }
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
    for (int i = 1; number > 0;i++, number /= 10)
    {
        int remainder = number % 10;
        if (i % 2 == 0)
        {
            int product = remainder * 2;
            if (product > 9)
            {
                int sum = 0;
                while(product>0)
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
    printf("%i, %i, %i\n", odd_last_sum, even_last_sum, total_sum);
    if (total_sum % 10 == 0)
    {
        return true;
    }
    return false;
}