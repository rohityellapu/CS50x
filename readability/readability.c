#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string txt = get_string("Text: ");
    int ltrs = count_letters(txt);
    printf("%i letters\n", ltrs);
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char j = text[i];
        if (!isspace(j))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char j = text[i];
        printf("%s\n", j)
    }
}