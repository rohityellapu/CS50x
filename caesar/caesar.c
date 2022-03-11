// Libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function Prototypes
int check_key(string key);
int encrypter(char text, int key);

int main(int argc, string argv[])
{
    // Make sure whether there is only one command-line-argument
    if (argc == 2)
    {

        int k = check_key(argv[1]);
        // Checking if the argv[1] is a digit
        if (k == 10)
        {
            // Print the correct usage of the command-line-argument
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
        // Prompt the user for Plaintext
        string txt = get_string("Plaintext: ");
        // Looping through every character in the txt
        for (int i = 0; i < strlen(txt); i++)
        {
            char l = txt[i];
            // Make sure the character is an alphabet.
            if (isalpha(l))
            {
                // Getting the cipher character from given key through function
                int cipher = encrypter(l, k);
                printf("%i\n", cipher);

                // rotate the character with ciphertext
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

//Ensure every character in argv[1] i.e. key is a digit
int check_key(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            // Return 10(any number) if the character is not a number.
            return 10;
        }
    }
    // Returning converted string(into number)
    return atoi(key);
}

// Encrypting plaintext into ciphertext by given key
int encrypter(char letter, int key)
{
    int cipher;
    key %= 26;
    // If the character is UpperCased
    if (isupper(letter))
    {
        //  Caesar's algorithm
        cipher = ((int)letter + key) % 91;
        if (cipher < 26)
        {
            cipher += 65;
        }
        return cipher;
    }
    else
    {
        cipher = ((int)letter + key) % 123;
        if (cipher < 26)
        {
            cipher += 97;
        }
        return cipher;
    }
}
