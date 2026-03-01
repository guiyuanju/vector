#include <assert.h>
#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  size_t len;
  size_t cap;
  size_t size;                      // size of an element
  alignas(max_align_t) char data[]; // flexible array member, properly aligned
} Vec;

#define vnew(type, len) vec_new(len, len, sizeof(type))
#define vnew2(type, len, cap) vec_new(len, cap, sizeof(type))
#define vheader(vector) ((Vec*)((char*)(vector) - offsetof(Vec, data)))
#define vfree(vector) (free(vheader(vector)))
#define vlen(vector) (vheader(vector)->len)
#define vcap(vector) (vheader(vector)->cap)
#define vadd(vector, value)                                                    \
  do {                                                                         \
    if ((vector) == NULL) {                                                    \
      vector = vec_new(0, 4, sizeof(*vector));                                 \
    }                                                                          \
    if (vlen(vector) + 1 > vcap(vector)) {                                     \
      vector = vec_grow(vector);                                               \
    }                                                                          \
    (vector)[vlen(vector)] = (value);                                          \
    vheader(vector)->len++;                                                    \
  } while (0)

void* vec_new(size_t len, size_t cap, size_t size);
void* vec_grow(void* vector);

#ifdef VEC_IMPLEMENTATION

void* vec_new(size_t len, size_t cap, size_t size) {
  Vec* vector = (Vec*)malloc(offsetof(Vec, data) + size * cap);
  vector->len = len;
  vector->cap = cap;
  vector->size = size;
  return (void*)(vector->data);
}

void* vec_grow(void* vector) {
  Vec* header = vheader(vector);
  if (header->cap >= 8) {
    header->cap += header->cap / 2;
  } else {
    header->cap = 8;
  }
  header = realloc(header, offsetof(Vec, data) + header->cap * header->size);
  return (void*)(header->data);
}

#endif
