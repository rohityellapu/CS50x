#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cardNumber = get_long("Number: \n");
    while (cardNumber < 0)
    {
        cardNumber = get_long("Number: \n");
    }

}

