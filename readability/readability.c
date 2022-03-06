#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    string txt = get_string("Text: ");

    int letters = count_letters(txt);
    int words = count_words(txt);
    int sentences = count_sentences(txt);
    float L = letters / (float)words * 100;
    float S = sentences / (float)words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    printf("%f L\n", L);
    printf("%f S\n", S);
    printf("%i letters\n", letters);
    printf("%i words\n", words + 1);
    printf("%i sentences\n", sentences);
    printf("%f index\n", index);
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
    return words;
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