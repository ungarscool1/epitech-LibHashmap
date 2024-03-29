/*
** EPITECH PROJECT, 2020
** My library - Hashmap
** File description:
** Unit Test - Simple
*/

#include <criterion/criterion.h>
#include "my_hashmap.h"

Test(hashmap, put_one_element, .timeout = 10)
{
    my_hashmap *map = NULL;

    cr_assert_eq(my_hashmap_put(&map, "hello", "world"), 1);
    cr_assert_eq(my_hashmap_contains(map, "hello"), 1);
    cr_assert_eq(my_hashmap_count(map), 1);
}

Test(hashmap, put_five_element, .timeout = 10)
{
    my_hashmap *map = NULL;

    cr_assert_eq(my_hashmap_put(&map, "hello", "world"), 1);
    cr_assert_eq(my_hashmap_put(&map, "hey", "world"), 1);
    cr_assert_eq(my_hashmap_put(&map, "hallo", "world"), 1);
    cr_assert_eq(my_hashmap_put(&map, "allo", "a l'huile"), 1);
    cr_assert_eq(my_hashmap_put(&map, "bruh", "bruelle"), 1);
    cr_assert_eq(my_hashmap_count(map), 5);
}

Test(hashmap, get_an_elem_from_key, .timeout = 10)
{
    my_hashmap *map = NULL;
    char *test_str = malloc(sizeof(char) * 5);

    test_str[0] = 't';
    test_str[1] = 'e';
    test_str[2] = 's';
    test_str[3] = 't';
    my_hashmap_put(&map, "test", "This is a test");
    cr_assert_str_eq(my_hashmap_get(map, "test"), "This is a test");
    cr_assert_str_eq(my_hashmap_get(map, test_str), "This is a test");
    free(test_str);
}

Test(hashmap, get_an_elem_from_data, .timeout = 10)
{
    my_hashmap *map = NULL;

    my_hashmap_put(&map, "test", "This is a test");
    cr_assert_str_eq(my_hashmap_get_from_data(map, "This is a test"), "test");
}

Test(hashmap, try_to_get_NULL, .timeout = 10)
{
    my_hashmap *map = NULL;

    cr_assert_null(my_hashmap_get_from_data(map, "This is a test"));
    cr_assert_null(my_hashmap_get(map, "test"));
}

Test(hashmap, map_is_NULL, .timeout = 30)
{
    my_hashmap *map = NULL;

    cr_assert_eq(my_hashmap_contains(map, "test"), 0);
    cr_assert_null(my_hashmap_to_string_array(map));
    cr_assert_eq(my_hashmap_put(&map, "test", "data"), 1);
    cr_assert_eq(my_hashmap_remove(&map, "test"), 1);
    cr_assert_eq(my_hashmap_contains_from_data(map, "test"), 0);
    cr_assert_null(my_hashmap_get_from_data(map, "This is a test"));
    cr_assert_null(my_hashmap_get(map, "test"));
    cr_assert_null(my_hashmap_convert(map));
}

Test(hashmap, key_not_found, .timeout = 30)
{
    my_hashmap *map = NULL;
    char *test_str = malloc(sizeof(char) * 5);

    test_str[0] = 'k';
    test_str[1] = 'e';
    test_str[2] = 'y';
    test_str[3] = 's';
    my_hashmap_put(&map, "key", "data");
    my_hashmap_put(&map, "abcde", "letters");
    cr_assert_eq(my_hashmap_contains(map, "test"), 0);
    cr_assert_eq(my_hashmap_contains(map, test_str), 0);
    cr_assert_eq(my_hashmap_contains_from_data(map, "test"), 0);
}

Test(hashmap, convert_to_str_array, .timeout = 10)
{
    my_hashmap *map = NULL;
    char **array;

    my_hashmap_put(&map, "bonjour", "ca va ?");
    my_hashmap_put(&map, "hey", "how are you ?");
    array = my_hashmap_to_string_array(map);
    cr_assert_str_eq(array[0], "bonjour=ca va ?");
    cr_assert_str_eq(array[1], "hey=how are you ?");
}

Test(hashmap, convert_to_array, .timeout = 10)
{
    my_hashmap *map = NULL;
    void **array;

    my_hashmap_put(&map, (int *) 25, (int *) (25 + 2));
    my_hashmap_put(&map, (int *) 33, (int *) (33 + 2));
    array = my_hashmap_convert(map);
    cr_assert_eq(array[0], 27);
    cr_assert_eq(array[1], 35);
}

Test(hashmap, convert_to_keys_array, .timeout = 10)
{
    my_hashmap *map = NULL;
    void **array;

    my_hashmap_put(&map, (int *) 25, (int *) (25 + 2));
    my_hashmap_put(&map, (int *) 33, (int *) (33 + 2));
    array = my_hashmap_convert_keys(map);
    cr_assert_eq(array[0], 25);
    cr_assert_eq(array[1], 33);
}

Test(hahsmap, clear_map, .timeout = 10)
{
    my_hashmap *map = NULL;
    int return_value = -1;

    my_hashmap_put(&map, "key", "data");
    my_hashmap_put(&map, "carte", "de france");
    my_hashmap_put(&map, "terminal", "cmd");
    my_hashmap_put(&map, "table", "chaise");
    my_hashmap_put(&map, "porte", "poigne");
    return_value = my_hashmap_clear(&map);
    cr_assert_eq(return_value, 1);
    cr_assert_null(map);
}