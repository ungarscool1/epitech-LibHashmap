/*
** EPITECH PROJECT, 2020
** My library - Hashmap
** File description:
** Equals
*/

#include "my_hashmap.h"

int my_hashmap_contains(my_hashmap *map, void const *key)
{
    my_hashmap *node;

    node = map;
    while (node != NULL) {
        if (node->key == key)
            return 1;
        node = node->next;
    }
    return 0;
}

int my_hashmap_contains_from_data(my_hashmap *map, void const *data)
{
    my_hashmap *node;

    node = map;
    while (node != NULL) {
        if (node->data == data)
            return 1;
        node = node->next;
    }
    return 0;
}