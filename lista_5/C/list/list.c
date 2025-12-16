#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

void updateLength(list list_) {
    list_->length = length(list_);
    printf("updated length: %d\n", list_->length);
}

bool isEmpty(list list_)
{
    return list_->first == NULL;
}

int pop(list list_)
{
    if (!isEmpty(list_))
    {
        node_ptr first_node = list_->first;
        int popped = first_node->elem;

        list_->first = first_node->next;
        if (list_->first == NULL)
        {
            list_->last = NULL;
        }

        free(first_node);

        return popped;
    }
    else
    {
        printf("List is already empty\n");
        return -1;
    }
}
void push(list list_, int new_elem)
{
    node_ptr new_node = malloc(sizeof(node));
    new_node->elem = new_elem;
    new_node->next = list_->first;
    list_->first = new_node;

    if (list_->last == NULL)
    {
        list_->last = new_node;
    }
}
void append(list list_, int new_elem)
{
    node_ptr new_node = malloc(sizeof(node));
    new_node->elem = new_elem;
    new_node->next = NULL;
    if (list_->first == NULL)
    {
        list_->first = new_node;
    }
    else
    {
        list_->last->next = new_node;
    }
    list_->last = new_node;
}

node_ptr get(list list_, int index)
{
    if (index > length(list_))
    {
        printf("Wrong index.\n");
        return list_->first;
    }
    node_ptr temp_node = list_->first;
    int temp = 1;

    while (temp < index)
    {
        temp_node = temp_node->next;
        temp++;
    }

    return temp_node;
}
void put(list list_, int index, int new_elem)
{
    node_ptr cur = get(list_, index);
    cur->elem = new_elem;
}
void insert(list list_, int index, int new_elem)
{
    node_ptr cur = get(list_, index);
    node_ptr new_node = malloc(sizeof(node));
    new_node->next = cur;
    new_node->elem = new_elem;

    if (list_->first == cur)
    {
        list_->first = new_node;
        return;
    }

    node_ptr cur_ptr = list_->first;
    while (cur_ptr->next != cur)
    {
        cur_ptr = cur_ptr->next;
    }
    cur_ptr->next = new_node;
}
void delete(list list_, int index)
{
    node_ptr cur = get(list_, index);
    if (list_->first == cur)
    {
        list_->first = cur->next;
        free(cur);
        return;
    }

    node_ptr cur_ptr = list_->first;
    while (cur_ptr->next != cur)
    {
        cur_ptr = cur_ptr->next;
    }
    cur_ptr->next = cur->next;

    free(cur);
}

void print(list list_)
{
    node_ptr temp = list_->first;
    printf("[");
    while (temp != NULL)
    {
        printf(" %d", temp->elem);
        temp = temp->next;
    }
    printf(" ]\t(%d)\n", length(list_));
}

int length(list list_)
{
    int len = 0;
    node_ptr first_node = list_->first;
    while (first_node != NULL)
    {
        len++;
        first_node = first_node->next;
    }

    return len;
}

void clean(list list_)
{
    while (!isEmpty(list_))
    {
        pop(list_);
    }
    free(list_);
}