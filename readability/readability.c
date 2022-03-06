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
    int ltrs = count_letters(txt);
    int words = count_words(txt);
    int sentences = count_sentences(txt);
    printf("%i letters\n", ltrs);
    printf("%i words\n", words + 1);
    printf("%i sentences\n", sentences);
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
        string j = text[i];
        if (strcmp(j, ".") == 0 || strcmp(j, "!") == 0 || strcmp(j, "?") == 0)
        {
            sentences++;
        }
    }
    return sentences;
}