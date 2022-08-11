// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26000;

// Number of words in dictionary
unsigned int words = 0;

// Hash table
node *table[N];

// Single node
node *getNode(const char *key)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf('No enough memory for linked list node.');
        return n;
    }

    strcopy(n->word, key);

    n->next = NULL;

    return n;
}

// Pass pointer to pointer for head node
void insertNode(node **head, const char *key)
{
    node *n = getNOde(key);

    if(*head != NULL)
    {
        n->next = *head;
    }
    *head = n;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char copy[strlen(word) + 1];
    strcpy(copy, word);

    char *p = copy;
    for (; *p;++p)
    {
        *p = tolower(*p);
    }

    unsigned int key = hash(copy);

    node *t = table[key];

    while(*t != NULL)
    {
        if (strcmp(copy, t->word) == 0)
        {
            return true;
        }
        
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic = fopen(dictionary, "r");
    if(dic == NULL)
    {
        return false;
    }

    for (int i = 0; i < N;i++)
     {
         table[i] = NULL;
     }

     char word[LENGTH + 1];
     while (fscanf(dic, '%s', word) != EOF)
     {
         unsigned int key = hash(word);

         node **head = &table[key];

         insertNode(head, word);

         words++;
     }
     return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
