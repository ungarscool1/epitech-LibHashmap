/*
** EPITECH PROJECT, 2020
** My library
** File description:
** HashMap
*/

#include <stdlib.h>

typedef struct my_hashmap{
    void *key;
    void *data;
    struct my_hashmap *next;
} my_hashmap;

#ifndef MY_HASHMAP
#define MY_HASHMAP
/**
* Get data from key in hashmap
* @return void *
**/
void *my_hashmap_get(my_hashmap *map, void *key);

/**
* Get key from data in hashmap
* @return void *
**/
void *my_hashmap_get_from_data(my_hashmap *map, void *data);

/**
* Does hashmap contains key
* @return 1 when true, 0 when false
**/
int my_hashmap_contains(my_hashmap *map, void const *key);

/**
* @return 1 when true, 0 when false
**/
int my_hashmap_contains_from_data(my_hashmap *map, void const *data);

/**
* Put a new row in HashMap
* @return 1 when ok. 0 if an error occured
**/
int my_hashmap_put(my_hashmap **map, void *key, void *data);

/**
* Replace the content of one row
* @return 1 when row is found and modified, 0 when error
**/
int my_hashmap_set(my_hashmap **map, void const *key, void *data);

/**
* Count rows number in HashMap
**/
int my_hashmap_count(my_hashmap *map);

/**
* Transform the hashmap to a string array as format: "KEY=DATA"
*
* A segfault can appear if you put another type instead of char *
* @return char **
**/
char **my_hashmap_to_string_array(my_hashmap *map);

/**
* Transform the hashmap to an all type array as format: DATA
* @return void *
**/
void **my_hashmap_convert(my_hashmap *map);

/**
* Remove a row from key in HashMap
* @return int
**/
int my_hashmap_remove(my_hashmap **map, void const *key);

#endif /* !MY_HASHMAP */
