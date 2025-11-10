// ========================================
// hash_fn.c — implement your hash functions
// ========================================

#include <stdio.h>

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    return key % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
        hash = hash * 31 + str[i];  // polynomial rolling hash
    return (int)(hash % m);
}
