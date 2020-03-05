/*
** EPITECH PROJECT, 2020
** My library - Hashmap
** File description:
** Clear a hashmap
*/

#include "my_hashmap.h"

int my_hashmap_clear(my_hashmap **map)
{
    void **array = my_hashmap_convert_keys((*map));

    for (int i = 0; i <= my_hashmap_count(*map); i++)
        my_hashmap_remove(&(*map), array[i]);
    free((*map));
    (*map) = NULL;
    free(array);
    return 1;
}