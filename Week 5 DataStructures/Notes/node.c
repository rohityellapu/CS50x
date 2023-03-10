#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    (*n).number = 1;
    n->next = NULL;

    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;

    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;

    list->next->next = n;
    // Insert a new node in the middle of the list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 4;
    n->next = list->next;
    list->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("Number is, %i\n", tmp->number);
    }

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}
