#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Integers Comparison
    // int s = get_int("i: ");
    // int q = get_int("j: ");

    // if (s == q)
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }
    char *s = get_string("i: ");
    char *q = get_string("j: ");

    // if (strcmp(s, q) == 0) deleted by if(s==q) which doesn't work
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }
    printf("%p\n", s);
    printf("%p\n", q);

}