#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check_key(string key);
int encrypter(string text, int key);

int main(int argc, string argv[])
{
    // printf("%i %s\n", argc, argv[1]);
    if (argc == 2)
    {
        int k = check_key(argv[1]);
        if (k == 1)
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
        string txt = get_string("Plaintext: \n");
        int cipher = encrypter(txt, k);
        printf("%i %i\n", k, cipher);
        return 0;
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}

int check_key(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return 1;
        }
    }
    return atoi(key);
}

int encrypter(string text, int key)
{

    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        if (isalpha(letter))
        {
            int cipher = ((int)letter + key) % 26;
            letter = cipher;
            printf("%c\n", letter);
        }
    }
    return 10;
}
