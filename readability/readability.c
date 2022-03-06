// Libraries.
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Functions Prototypes.
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// Execution of code.
int main(void)
{
    // Prompt the user for text.
    string txt = get_string("Text: ");

    // Declare float data type variables for clean multiplication and division purposes.
    float letters = count_letters(txt);
    float words = count_words(txt);
    float sentences = count_sentences(txt);

    float L = letters / words * 100;
    float S = sentences / words * 100;

    //  Coleman-Liau index
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

// Function for counting number of letters in the text
int count_letters(string text)
{
    int letters = 0;

    // Looping for every character in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char j = text[i];
        // Check whether the character is an alphabet or not
        if (isalpha(j))
        {
            letters++;
        }
    }
    return letters;
}

// Function for counting number of words in the text.
int count_words(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char j = text[i];
        // Check whether it is a space.
        if (isspace(j))
        {
            words++;
        }
    }
    // Add another 1 as there is no space after the last word.
    return words + 1;
}

// Function for counting number of sentences in the text.
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char j = text[i];

        // Declare characters that ends the sentences.
        char k[] = ".?!";

        // Check whether it is an ending character of a sentence.
        if (j == k[0] || j == k[1] || j == k[2])
        {
            sentences++;
        }
    }
    return sentences;
}
