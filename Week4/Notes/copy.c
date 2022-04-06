#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    // string t = s; This means t just copied the address of s (changes on t means changes on s)

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }
    strcopy(t, s);

    if (strlen(t) > 1)
    {
        t[0] = toupper(t[0]);
    }


    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}