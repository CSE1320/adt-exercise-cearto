#include "array.h"
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10

int main (void){
    printf("Array ADT!\n");
    Array arr = array_init(INIT_SIZE);
    // int characters = array_print(arr);
    // printf("Printed out %d characters to stdout\n", characters);
    
    list_append(&arr, 100);
    array_print(arr);
    printf("\n");

    // int value = array_get(arr, 0);
    // printf("The value at 0 is %d\n", value);
    // printf("\n");

    // value = array_remove(arr, 0);
    // printf("The value removed at 0 is %d\n", value);
    // array_print(arr);
    // printf("\n");
    // array_destroy(arr);

    return EXIT_SUCCESS;
}
