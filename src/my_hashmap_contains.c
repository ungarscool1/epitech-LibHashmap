/*
** EPITECH PROJECT, 2020
** My library - Hashmap
** File description:
** Equals
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

int my_hashmap_contains(my_hashmap *map, void const *key)
{
    my_hashmap *node;

    if (map == NULL)
        return 0;
    node = map;
    while (node != NULL) {
        if (node->key == key || my_streq(node->key, key))
            return 1;
        node = node->next;
    }
    return 0;
}

int my_hashmap_contains_from_data(my_hashmap *map, void const *data)
{
    my_hashmap *node;

    if (map == NULL)
        return 0;
    node = map;
    while (node != NULL) {
        if (node->data == data || my_streq(node->data, data))
            return 1;
        node = node->next;
    }
    return 0;
}