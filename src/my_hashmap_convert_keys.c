/*
** EPITECH PROJECT, 2020
** My library - Convert keys
** File description:
** Convert hashmap keys to void * array
*/

#include "my_hashmap.h"

void **my_hashmap_convert_keys(my_hashmap *map)
{
    void **array = malloc(sizeof(void *) * my_hashmap_count(map));
    my_hashmap *node;

    if (array == NULL || map == NULL)
        return NULL;
    node = map;
    for (int i = 0; i < my_hashmap_count(map); i++) {
        array[i] = node->key;
        node = node->next;
    }
    return array;
}