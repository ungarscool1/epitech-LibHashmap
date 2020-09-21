# My Epitech libs - Hashmap 

![CI](https://github.com/ungarscool1/epitech-LibHashmap/workflows/CI/badge.svg?event=push)

## Introduction

Hashmap is a associative array, it must contain a key and a value

## Sample

```
#include "include/my_hashmap.h"
#include <stdio.h>

int main(int ac, char * const * av)
{
    my_hashmap *map = NULL;

    my_hashmap_put(&map, "Key", "Data");
    my_hashmap_put(&map, 1, NULL);
    printf("Number of row: %d\n", my_hashmap_count(map); // Return 2
    printf("What does contains hashmap with the key 1: %s\n", my_hashmap_get(map, 1)); // return NULL
    printf("What does contains hashmap with the data NULL: %d\n", my_hashmap_get_from_data(map, NULL)); // return 1
}
```
