#include <stdio.h>


int main(void)
{
    char *s = "Ia!";
    printf("%p, %p\n", &s, s);

    int numbers[] = {4,5 ,5, 4,3,2, 7,};

    printf("%i\n", s[1]);
    printf("%i, %i\n", *numbers, numbers[1]);
}