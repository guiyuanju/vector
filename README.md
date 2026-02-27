# vector
A vector library for C.

```c
    // new int vector with length 4
    int* vec = vnew(int, 4);
    printf("len = %zu, cap = %zu\n", vlen(vec), vcap(vec));

    // set value with array syntax
    for (size_t i = 0; i < vlen(vec); i++) {
        vec[i] = i;
        printf("len = %zu, cap = %zu\n", vlen(vec), vcap(vec));
    }

    // append a value with `vadd(vector, type, value)`
    for (size_t i = vlen(vec); i < 10; i++) {
        vadd(vec, int, i);
        printf("len = %zu, cap = %zu\n", vlen(vec), vcap(vec));
    }

    // access a value array syntax
    for (size_t i = 0; i < vlen(vec); i++) {
        printf("%d ", vec[i]);
    }

    vfree(vec);
```