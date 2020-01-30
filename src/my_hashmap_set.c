/*
** EPITECH PROJECT, 2020
** My library - HashMap
** File description:
** Set and put
*/

#include "my_hashmap.h"

int my_hashmap_set(my_hashmap **map, void const *key, void *data)
{
    my_hashmap *node;

    if (map == NULL)
        return 0;
    node = (*map);
    while (node != NULL) {
        if (node->key == key) {
            node->data = data;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int my_hashmap_remove(my_hashmap **map, void const *key)
{
    my_hashmap *next_node;
    my_hashmap *node;
    my_hashmap *tmp;

    if (map == NULL || key == NULL || my_hashmap_contains((*map), key) != 1)
        return 0;
    node = (*map);
    while (node != NULL) {
        tmp = node->next;
        if (tmp->key == key) {
            next_node = tmp->next;
            node->next = next_node;
            free(tmp);
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int my_hashmap_put(my_hashmap **map, void *key, void *data)
{
    my_hashmap *node;

    if (key == NULL || data == NULL)
        return 0;
    node = malloc(sizeof(my_hashmap));
    node->key = key;
    node->data = data;
    node->next = (*map);
    (*map) = node;
    return 1;
}