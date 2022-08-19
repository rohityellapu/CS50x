#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    char *word[26];
    struct node *next;
} node;
int main()
{
    node *list = NULL;
    node *a = malloc(sizeof(node));
    char *A = "alphabet";
    a->word[0] = A;
    a->next = NULL;
    list = a;
    char *B = "ALPHABET";
    node *b = malloc(sizeof(node));
    b->word[0] = B;
    b->next = NULL;
    list->next = b;

    printf("%s\n", *list->word);
    free(a);
    free(b);
}