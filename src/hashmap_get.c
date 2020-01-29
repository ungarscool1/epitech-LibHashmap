/*
** EPITECH PROJECT, 2020
** My library - my_hashmap
** File description:
** Get value from key in HashTable
*/

#include "my_hashmap.h"

void *my_hashmap_get(my_hashmap *map, void *key)
{
    my_hashmap *node;

    if (map == NULL)
        return NULL;
    node = map;
    while (node != NULL) {
        if (node->key == key)
            return node->data;
        node = node->next;
    }
    return NULL;
}

void *my_hashmap_get_from_data(my_hashmap *map, void *data)
{
    my_hashmap *node;

    if (map == NULL)
        return NULL;
    node = map;
    while (node != NULL) {
        if (node->data == data)
            return node->key;
        node = node->next;
    }
    return NULL;
}