# vector
A vector library for C.

```c
    // new int vector with length 4
    Vec* vec = vnew(4, int);
    printf("len = %zu, cap = %zu\n", vlen(vec), vcap(vec));

    // set value with `varr(vector, type)[index] = value`
    for (size_t i = 0; i < vlen(vec); i++) {
        varr(vec, int)[i] = i;
        printf("len = %zu, cap = %zu\n", vlen(vec), vcap(vec));
    }

    // append a value with `vadd(vector, type, value)`
    for (size_t i = vlen(vec); i < 10; i++) {
        vadd(vec, int, i);
        printf("len = %zu, cap = %zu\n", vlen(vec), vcap(vec));
    }

    // access a value with `varr(vector, type)[index]`
    for (size_t i = 0; i < vlen(vec); i++) {
        printf("%d ", varr(vec, int)[i]);
    }
```