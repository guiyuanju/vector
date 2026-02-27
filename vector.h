#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct {
    size_t len;
    size_t cap;
    size_t size; // size of an element
} Vector;

#define vnew(len, type) vector_new(len, len, sizeof(type)) 
#define vlen(vector) vector_len(vector)
#define vcap(vector) vector_cap(vector)
#define varr(vector, type) ((type*)(vector+1))
#define vadd(vector, type, value) do { \
    if (vector->len + 1 > vector->cap) { \
        vector = vector_grow(vector); \
    } \
    varr(vector, type)[vector->len] = value; \
    vector->len++; \
} while(0);

#ifdef VECTOR_IMPL

Vector* vector_new(size_t len, size_t cap, size_t size) {
    Vector* vector = (Vector*)malloc(size*cap+sizeof(Vector));
    vector->len = len;
    vector->cap = cap;
    vector->size = size;
    return vector;
}

size_t vector_len(Vector* vector) {
    return vector->len;
}

size_t vector_cap(Vector* vector) {
    return vector->cap;
}

Vector* vector_grow(Vector* vector) {
    size_t new_cap = 8;
    if (vector->cap >= new_cap) {
        new_cap = vector->cap + vector->cap/2;
    }
    Vector* new_vector = vector_new(vector->len, new_cap, vector->size);
    memcpy((void*)(new_vector+1), (void*)(vector+1), vector->len*vector->size);
    free(vector);
    return new_vector;
}

#endif