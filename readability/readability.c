#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    string txt = get_string("Text: ");

    float letters = count_letters(txt);
    float words = count_words(txt);
    float sentences = count_sentences(txt);
    float L = letters / words * 100;
    float S = sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char j = text[i];
        if (isalpha(j))
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
        if (isspace(j))
        {
            words++;
        }
    }
    return words + 1;
}
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char j = text[i];

        char k[] = ".?!";
        if (j == k[0] || j == k[1] || j == k[2])
        {
            sentences++;
        }
    }
    return sentences;
}
