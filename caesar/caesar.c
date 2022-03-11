#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check_key(string key);
int encrypter(char text, int key);

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
        for (int i = 0; i < strlen(txt); i++)
        {
            char l = txt[i];
            if (isalpha(l))
            {
                int cipher = encrypter(l, k);
                printf("%i\n", cipher);

                txt[i] = (char)cipher;
            }
        }
        printf("Ciphertext: %s\n", txt);
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

int encrypter(char letter, int key)
{
    int cipher;
    if (isupper(letter))
    {
        cipher = ((int)letter + key)%91;
        return cipher;
    }
    else
    {
        cipher = ((int)letter + key)%123;
        return cipher;
    }
}
