#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct {
    size_t len;
    size_t cap;
    size_t size; // size of an element
} Vec;

#define vnew(type, len) vec_new(len, len, sizeof(type)) 
#define vfree(vector) vec_free(vector)
#define vlen(vector) vec_len(vector)
#define vcap(vector) vec_cap(vector)
#define vadd(vector, type, value) do { \
    if (vlen(vector) + 1 > vcap(vector)) { \
        vector = vec_grow(vector); \
    } \
    vector[vlen(vector)] = value; \
    vec_header(vector)->len++; \
} while(0);

void* vec_new(size_t len, size_t cap, size_t size);
void vec_free(void* vector);
Vec* vec_header(void* vector);
size_t vec_len(void* vector);
size_t vec_cap(void* vector);
void* vec_grow(void* vector);

#ifdef VECTOR_IMPL

void* vec_new(size_t len, size_t cap, size_t size) {
    Vec* vector = (Vec*)malloc(size*cap+sizeof(Vec));
    vector->len = len;
    vector->cap = cap;
    vector->size = size;
    return (void*)(vector+1);
}

Vec* vec_header(void* vector) {
    return (Vec*)vector-1;
}

void vec_free(void* vector) {
    free(vec_header(vector));
}

size_t vec_len(void* vector) {
    return vec_header(vector)->len;
}

size_t vec_cap(void* vector) {
    return vec_header(vector)->cap;
}

void* vec_grow(void* vector) {
    Vec* header = vec_header(vector);
    size_t new_cap = 8;
    if (header->cap >= new_cap) {
        new_cap = header->cap + header->cap/2;
    }
    void* new_vector = vec_new(header->len, new_cap, header->size);
    memcpy(new_vector, vector, header->len*header->size);
    vec_free(vector);
    return new_vector;
}

#endif