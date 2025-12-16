#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

void normal_control_module();

int main()
{
    // char main_command;
    // printf("New list (N)\nEdit lists (E)\nView lists(V)\n");
    // printf("What do you want to do: ");
    // scanf("%c", &main_command);

    // MainCommand main_command_enumed = (main_command == 'N') ? N : (main_command == 'E') ? E
    //                                                                                     : V;

    // switch (main_command_enumed)
    // {
    // case 1:
    //     normal_control_module();
    //     break;
    // }

    normal_control_module();

    return 0;
}

void normal_control_module()
{

    list list = malloc(sizeof(list_t));
    list->first = list->last = NULL;

    append(list, 10);
    append(list, 20);
    append(list, 30);
    append(list, 40);
    append(list, 50);

    printf("\n--- Created a new list ---\n");
    printf("Available commands: pop, push, print, append, get, put, insert, delete, clean, exit\n\n");

    char command[10];

    while (true)
    {
        printf("Command: ");
        scanf("%s", command);

        NormalCommands command_enumed = (strcmp(command, "isEmpty") == 0) ? IsEmpty : (strcmp(command, "exit") == 0) ? Exit
                                                                                  : (strcmp(command, "pop") == 0)    ? Pop
                                                                                  : (strcmp(command, "push") == 0)   ? Push
                                                                                  : (strcmp(command, "print") == 0)  ? Print
                                                                                  : (strcmp(command, "append") == 0) ? Append
                                                                                  : (strcmp(command, "get") == 0)    ? Get
                                                                                  : (strcmp(command, "put") == 0)    ? Put
                                                                                  : (strcmp(command, "insert") == 0) ? Insert
                                                                                  : (strcmp(command, "delete") == 0) ? Delete
                                                                                  : (strcmp(command, "clean") == 0)  ? Clean
                                                                                                                     : WrongCommand;

        switch (command_enumed)
        {
        case 0:
            if (!isEmpty(list))
                clean(list);
                free(list);
            return;
        case 11:
            printf("This command is unavailable yet.\n");
            break;
        case 1:
            printf("Result: %s\n", isEmpty(list) ? "true" : "false");
            break;
        case 2:
            printf("Result: %d\n", pop(list));
            break;
        case 3:
            int push_elem;
            printf("Value: ");
            scanf("%d", &push_elem);
            push(list, push_elem);
            printf("Result: OK\n");
            break;
        case 4:
            printf("Result: ");
            print(list);
            break;
        case 5:
            int append_elem;
            printf("Value: ");
            scanf("%d", &append_elem);
            append(list, append_elem);
            printf("Result: OK\n");
            break;
        case 6:
            int get_index;
            printf("Index: ");
            scanf("%d", &get_index);
            if (get_index > list->length)
            {
                printf("Wrong index.\n");
            }
            printf("Result: %d\n", get(list, get_index)->elem);
            break;
        case 7:
            int put_index;
            int put_value;
            printf("Index: ");
            scanf("%d", &put_index);
            printf("Value: ");
            scanf("%d", &put_value);
            put(list, put_index, put_value);
            printf("Result: OK\n");
            break;
        case 8:
            int insert_index;
            int insert_value;
            printf("Index: ");
            scanf("%d", &insert_index);
            printf("Value: ");
            scanf("%d", &insert_value);
            insert(list, insert_index, insert_value);
            printf("Result: OK\n");
            break;
        case 9:
            int delete_index;
            printf("Index: ");
            scanf("%d", &delete_index);
            delete(list, delete_index);
            printf("Result: OK\n");
            break;
        case 10:
            clean(list);
            printf("Result: OK\n");
            break;
        }
    }
}
