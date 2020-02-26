/*
** EPITECH PROJECT, 2020
** My library - HashMap
** File description:
** Set and put
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

int my_hashmap_set(my_hashmap **map, void const *key, void *data)
{
    my_hashmap *node;

    if (map == NULL)
        return 0;
    node = (*map);
    while (node != NULL) {
        if (node->key == key || my_streq(node->key, key)) {
            node->data = data;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int my_hashmap_remove(my_hashmap **map, void const *key)
{
    my_hashmap *node;
    my_hashmap *previous;

    if (key == NULL || my_hashmap_contains((*map), key) != 1)
        return 0;
    node = (*map);
    if (node->key == key || my_streq(node->key, key)) {
        (*map) = node->next;
        free(node);
        return 1;
    }
    previous = node;
    node = node->next;
    while (node != NULL) {
        if (node->key == key || my_streq(node->key, key)) {
            previous->next = node->next;
            free(node);
        return 1;
        }
        previous = node;
        node = node->next;
    }
    return 0;
}

int my_hashmap_put(my_hashmap **map, void *key, void *data)
{
    my_hashmap *node;
    my_hashmap *temp;

    if (key == NULL || data == NULL)
        return 0;
    node = malloc(sizeof(my_hashmap));
    node->key = key;
    node->data = data;
    node->next = NULL;
    if ((*map) == NULL) {
        (*map) = node;
        return 1;
    }
    temp = (*map);
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    return 1;
}