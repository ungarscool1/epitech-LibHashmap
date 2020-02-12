/*
** EPITECH PROJECT, 2020
** My library - Hashmap
** File description:
** Convert hashmap to array
*/

#include "my_hashmap.h"

static int get_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return len;
}

static char *concat_str(char *dest, char const *src)
{
    int j = get_strlen(dest);
    for (int i = 0; src[i] != '\0'; i++) {
        dest[j] = src[i];
        j++;
    }

    dest[get_strlen(dest)] = '\0';
    return dest;
}

void **my_hashmap_convert(my_hashmap *map)
{
    void **array = malloc(sizeof(void *) * my_hashmap_count(map));
    my_hashmap *node;

    if (array == NULL || map == NULL)
        return NULL;
    node = map;
    for (int i = 0; i < my_hashmap_count(map); i++) {
        array[i] = node->data;
        node = node->next;
    }
    return array;
}

char **my_hashmap_to_string_array(my_hashmap *map)
{
    char **array = malloc(sizeof(char *) * (my_hashmap_count(map) + 1));
    my_hashmap *node;

    if (array == NULL || map == NULL)
        return NULL;
    node = map;
    for (int i = 0; i < my_hashmap_count(map); i++) {
        int total_len = get_strlen(node->key) + get_strlen(node->data) + 1;
        array[i] = malloc(sizeof(char) * total_len);
        if (array[i] == NULL)
            return NULL;
        concat_str(array[i], node->key);
        concat_str(array[i], "=");
        concat_str(array[i], node->data);
        node = node->next;
    }
    array[my_hashmap_count(map)] = NULL;
    return array;
}