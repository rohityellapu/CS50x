#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int n = 50;
    int m = n;
    int *p = &n;
    int **q = &p;

    printf("%p\n", &n);
    printf("%i\n", n);

    printf("%i\n", m);
    printf("%p\n", &m);

    printf("%i\n", *p);

    printf("%p\n", q);
    printf("%p\n", &q);

    string s = "Hello";
    char *t = "HI";

    printf("%p\n", s);

    int *x;
    int *y;
    x = malloc(sizeof(int));
    *x = 100;
    y = x;
    *y = 300;

    printf("%i\n", *x);
}