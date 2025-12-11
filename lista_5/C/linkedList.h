#pragma once

typedef struct node {
    int elem;
    struct node *next;
} node;

typedef node *node_ptr;

typedef struct list_t {
    node_ptr first;
    node_ptr last;
} list_t;

typedef list_t *list;

