#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List* init_history() {
    List *list = malloc(sizeof(List));
    list->root = 0;
    return list;
}

void add_history(List *list, char *str) {
    Item *new_item = malloc(sizeof(Item));
    Item *cur;

    new_item->str = str;
    new_item->next = 0;

    if (list->root == 0) {
        new_item->id = 1;
        list->root = new_item;
        return;
    }

    cur = list->root;
    while (cur->next != 0) {
        cur = cur->next;
    }
    new_item->id = cur->id + 1;
    cur->next = new_item;
}

char *get_history(List *list, int id) {
    Item *cur = list->root;

    while (cur != 0) {
        if (cur->id == id) {
            return cur->str;
        }
        cur = cur->next;
    }
    return 0;
}

void print_history(List *list) {
    Item *cur = list->root;

    while (cur != 0) {
        printf("%d: %s\n", cur->id, cur->str);
        cur = cur->next;
    }
}

void free_history(List *list) {
    Item *cur = list->root;
    Item *next;

    while (cur != 0) {
        next = cur->next;
        free(cur->str);
        free(cur);
        cur = next;
    }
    free(list);
}
