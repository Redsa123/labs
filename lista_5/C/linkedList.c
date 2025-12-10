#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../linkedList.h"

bool is_empty(list l)
{
    return l->first == NULL;
}

int pop(list l)
{
    node_ptr n = l->first;
    int e = n->elem;

    l->first = l->first->next;

    if (l->first == NULL)
    {
        l->last = NULL;
    }
    free(n);
    return e;
}

void push(list l, int e)
{
    node_ptr n = malloc(sizeof(node));

    n->elem = e;
    n->next = l->first;
    l->first = n;

    if (l->last == NULL)
    {
        l->last = n;
    }
}

void append(list l, int e)
{
    node_ptr n = malloc(sizeof(node));
    n->elem = e;

    if (l->first == NULL)
    {
        l->first = n;
    }
    else
    {
        l->last->next = n;
    }
    l->last = n;
}

void print(list l)
{
    node_ptr n = l->first;

    while (n != NULL)
    {
        printf(" %d", n->elem);
        n = n->next;
    }

    printf(" ( %d )\n", length(l));
}

int length(list l)
{
    int i = 0;
    node_ptr n = l->first;

    while (n != NULL)
    {
        i++;
        n = n->next;
    }

    return i;
}

int main()
{
    char command[20];
    bool cont = true;
    int r;
    list l = malloc(sizeof(list_t));
    l->first = l->last = NULL;
    while (cont)
    {
        printf("Command: ");
        scanf("%s", command);
        if (!strcmp(command, "pop"))
        {
            if (!is_empty(l))
            {
                r = pop(l);
                printf("Result: %d \n", r);
            }
            else
            {
                printf("Error - stack is empty!\n");
            }
        }
        else if (!strcmp(command, "push"))
        {
            printf("Value: ");
            scanf("%d", &r);
            push(l, r);
            printf("Result: OK \n");
        }
        else if (!strcmp(command, "append"))
        {
            printf("Value: ");
            scanf(" %d ", &r);
            append(l, r);
            printf("Result: OK \n");
        }
        else if (!strcmp(command, "print"))
        {
            printf("Result: ");
            print(l);
        }
        else if (!strcmp(command, "length"))
        {
            r = length(l);
            printf("Result: %d \n ", r);
        }
        else if (!strcmp(command, "exit"))
        {
            cont = false;
        }
        else
            printf("Unknown command !\n ");
    }
    while (!is_empty(l))
        pop(l);
    free(l);
    return 0;
}