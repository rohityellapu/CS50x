#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check_key(string key);
string encrypter(string text, int key);

int main(int argc, string argv[])
{
    // printf("%i %s\n", argc, argv[1]);
    if (argc == 2)
    {
        int k = check_key(argv[1]);
        if (k == 10)
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
        string txt = get_string("Plaintext: ");
        string cip = encrypter(txt, k);
        printf("%s\n", cip);
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
            return 10;
        }
    }
    return atoi(key);
}

string encrypter(string text, int key)
{
    string encrypted = NULL;
    int cipher;
    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        if (isalpha(letter))
        {
            cipher = ((int)letter + key) % 123;
            encrypted[i] = (char)cipher;
        }
        else
        {
            encrypted[i] = letter;
        }
    }
    return (char)cipher;
}
