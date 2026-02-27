# vector
A vector library for C.

```c
   // new vector with len
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

    // uninitialized vector
    float* fvec = NULL;
    vadd(fvec, 1.0);
    vadd(fvec, 2.0);
    vadd(fvec, 3.0);
    for (size_t i = 0; i < vlen(fvec); i++) {
        printf("%f ", fvec[i]);
    }
    vfree(fvec);
```