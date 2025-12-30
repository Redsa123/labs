#pragma once

typedef struct node
{
    int elem;
    struct node *next;
} node;

typedef node *node_ptr;

typedef struct list_t
{
    node_ptr first;
    node_ptr last;
    int length;
} list_t;

typedef list_t *list;

typedef enum
{
    N = 1,
    E,
    V
} MainCommand;

typedef enum
{
    Exit,
    IsEmpty,
    Pop,
    Push,
    Print,
    Append,
    Get,
    Put,
    Insert,
    Delete,
    Clean,
    WrongCommand,
} NormalCommands;

bool isEmpty(list list);
int pop(list list);
void push(list list, int elem);
void append(list list, int elem);

node_ptr get(list list, int index);
void put(list list, int index, int elem);
void insert(list list, int index, int elem);
void delete (list list, int index);

void print(list list);
int length(list list);
void clean(list list);

void updateLength(list list);