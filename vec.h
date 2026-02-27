#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct {
    size_t len;
    size_t cap;
    size_t size; // size of an element
} Vec;

#define vnew(len, type) vec_new(len, len, sizeof(type)) 
#define vlen(vector) vec_len(vector)
#define vcap(vector) vec_cap(vector)
#define varr(vector, type) ((type*)(vector+1))
#define vadd(vector, type, value) do { \
    if (vlen(vector) + 1 > vcap(vector)) { \
        vector = vec_grow(vector); \
    } \
    varr(vector, type)[vector->len] = value; \
    vector->len++; \
} while(0);

// #ifdef VECTOR_IMPL

Vec* vec_new(size_t len, size_t cap, size_t size) {
    Vec* vector = (Vec*)malloc(size*cap+sizeof(Vec));
    vector->len = len;
    vector->cap = cap;
    vector->size = size;
    return vector;
}

size_t vec_len(Vec* vector) {
    return vector->len;
}

size_t vec_cap(Vec* vector) {
    return vector->cap;
}

Vec* vec_grow(Vec* vector) {
    size_t new_cap = 8;
    if (vector->cap >= new_cap) {
        new_cap = vector->cap + vector->cap/2;
    }
    Vec* new_vector = vec_new(vector->len, new_cap, vector->size);
    memcpy((void*)(new_vector+1), (void*)(vector+1), vector->len*vector->size);
    free(vector);
    return new_vector;
}

// #endif