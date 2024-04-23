#include "array.h"


Array array_init(unsigned int initialSize){
    assert(initialSize > 0);

    Array arr;
    arr.data = (int*) calloc(initialSize, sizeof(int));// heap
    arr.capacity = initialSize;
    arr.pos = 0;

    if(arr.data == NULL){
        fprintf(stderr, "Memory allocation failed.");
    }
    return arr;
}

void array_destroy(Array arr){
    free(arr.data);
    arr.data = NULL;
    arr.capacity = 0;
    arr.pos = 0;
}

bool array_isvalid(Array* arr){
    if(arr->data == NULL){
        fprintf(stderr, "Memory allocation failed.");
        return false;
    }
    if(arr->capacity <= 0){
        fprintf(stderr, "Memory allocation failed.");
        return false;
    }
    if(arr->pos < 0){
        fprintf(stderr, "Invalid pos.");
        return false;
    }
    return true;
}

int array_print(Array arr){
    array_isvalid(&arr);
    // Pre
    int characters = 0;
    characters += printf("Capacity: %d\n", arr.capacity);
    characters += printf("Pos: %d\n", arr.pos);
    characters += printf("Is Full?: %s\n", list_isfull(arr) ? "True" : "False");
    characters += printf("Is Empty: %s\n", list_isempty(arr) ? "True" : "False");
    characters += printf("Data: ");
    for(int i = 0; i < arr.capacity; i++){
        characters += printf("%d,", arr.data[i]);
    }
    characters += printf("\n");
    // Post
    assert(characters > 0);
    return characters;
}

int array_get(Array arr, int index){
    // return *(arr.data + index);
    return arr.data[index];
}
bool list_isempty(Array arr){
   return arr.pos == 0;
}
bool list_isfull(Array arr){
   return arr.pos == arr.capacity;
}

void list_grow(Array* arr){
    // int* newdatablock = realloc(arr->data, arr->capacity * 2);
    int* newdatablock = (int*) malloc(arr->capacity * 2 * sizeof(int));
    memmove(newdatablock, arr->data, arr->capacity * sizeof(int));
    free(arr->data);
    arr->data = newdatablock;
    arr->capacity *= 2;
}
void list_append(Array* arr, int value){
    if(list_isfull(&arr)){
        // grow the list

    }

    arr->data[arr->pos] = value;
    arr->pos++;
}
void array_set(Array arr, int index, int value){
    if(index < 0){
        arr.data[arr.capacity - index] = value;
    }
    arr.data[index] = value;
}

// int array_remove(Array arr, int index){
//     int value = array_get(arr, index);
//     // array_append(arr, 0);
//     return value;
// }

// 0, 1, 2, 3
// REMOVE 1
// 0, 2, 3
int list_remove(Array* arr, int index){
    //
    // arr->data // points to the block of ints
    // arr->capacity // size of the block (members)
    // arr->pos // current open position on the list
    // store temp variable to return at end

    int temp = arr->data[index];
    
    int* mem_endsuphere = arr->data + index;
    int* mem_startblocktocopy = arr->data + index + 1;
    memmove(mem_startblocktocopy, mem_endsuphere, arr->pos - 1 * sizeof(int));

    // for(int i = index; i < arr->pos; i++){
    //     if(i == arr->capacity) break;
    //     arr->data[i] = arr->data[i+1];
    // }
    arr->pos--;
    return temp;
    // loop through arr from index to cap
    // data before == data[at]
    // return temp



    return value;
}