/*
** EPITECH PROJECT, 2020
** My library - my_hashmap
** File description:
** Get value from key in HashTable
*/

#include "my_hashmap.h"

static int get_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return len;
}

static int my_streq(char const *src, char const *str)
{
    if (get_strlen(src) != get_strlen(str))
        return 0;
    for (int i = 0; i < get_strlen(str); i++) {
        if (src[i] != str[i])
            return 0;
    }
    return 1;
}

void *my_hashmap_get(my_hashmap *map, void *key)
{
    my_hashmap *node;

    if (map == NULL)
        return NULL;
    node = map;
    while (node != NULL) {
        if (node->key == key || my_streq(node->key, key))
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