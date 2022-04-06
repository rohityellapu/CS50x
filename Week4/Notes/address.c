#include <stdio.h>


int main(void)
{
    char *s = "I!!";
    printf("%p\n", s);

    int numbers[] = {4,5 ,5, 4,3,2, 7,};

    printf("%i\n", numbers[1]);
    printf("%i\n", *numbers);
}