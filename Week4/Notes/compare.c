#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int s = get_int("i: ");
    int q = get_int("j: ");

    if (s == q)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}