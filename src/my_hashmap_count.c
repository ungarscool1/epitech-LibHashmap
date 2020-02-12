/*
** EPITECH PROJECT, 2020
** My library - Hashmap
** File description:
** Count number of object
*/

#include "my_hashmap.h"

int my_hashmap_count(my_hashmap *map)
{
    int i = 0;
    my_hashmap *node;

    if (map == NULL)
        return 0;
    node = map;
    while (node != NULL) {
        i++;
        node = node->next;
    }
    return i;
}