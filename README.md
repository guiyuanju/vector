# vector
A vector library for C.

```c
    int* vec = vnew(int, 4);

    printf("len = %zu, cap = %zu\n", vlen(vec), vcap(vec));

    for (size_t i = 0; i < vlen(vec); i++) {
        vec[i] = i;
    }

    for (size_t i = vlen(vec); i < 10; i++) {
        vadd(vec, i);
    }

    for (size_t i = 0; i < vlen(vec); i++) {
        printf("%d ", vec[i]);
    }

    printf("\nlen = %zu, cap = %zu\n", vlen(vec), vcap(vec));

    vfree(vec);
```