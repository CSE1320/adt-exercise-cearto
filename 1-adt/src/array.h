#ifndef ARRAY_H
  #define ARRAY_H

// LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// TYPE DEFINITIONS
typedef struct Array
{
    int* data; //?
    unsigned int capacity;
    unsigned int pos;
} Array;

// FUNCTION PROTOTYPES
Array array_init(unsigned int initialSize);
int array_get(Array arr, int index);
void array_set(Array arr, int index, int value);
int array_remove(Array arr, int index);
void array_destroy(Array arr);
int array_print(Array arr);
bool array_isvalid(Array* arr);

// Utility
bool list_isempty(Array arr); 
bool list_isfull(Array arr);
void list_append(Array* arr, int value);

#endif //ARRAY_H