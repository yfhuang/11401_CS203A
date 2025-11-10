// ========================================
// Hash Function Observation Test Program
// ========================================

#include <stdio.h>
#include <string.h>
#include "hash_fn.c"

int main(void) {
    int int_keys[] = {21,22,23,24,25,26,27,28,29,30};
    int num_keys = sizeof(int_keys) / sizeof(int_keys[0]);
    int table_sizes[] = {10, 11, 101};
    int num_sizes = sizeof(table_sizes) / sizeof(table_sizes[0]);

    printf("=== Hash Function Observation (C Version) ===\n\n");

    for (int s = 0; s < num_sizes; s++) {
        int m = table_sizes[s];
        printf("=== Table Size m = %d ===\n", m);
        printf("Key\tIndex\n");
        printf("-----------------\n");
        for (int i = 0; i < num_keys; i++) {
            int idx = myHashInt(int_keys[i], m);
            printf("%d\t%d\n", int_keys[i], idx);
        }
        printf("\n");
    }

    const char* str_keys[] = {"cat","dog","bat","cow","ant","owl","bee","hen","pig","fox"};
    num_keys = sizeof(str_keys) / sizeof(str_keys[0]);

    for (int s = 0; s < num_sizes; s++) {
        int m = table_sizes[s];
        printf("=== String Hash (m = %d) ===\n", m);
        printf("Key\tIndex\n");
        printf("-----------------\n");
        for (int i = 0; i < num_keys; i++) {
            int idx = myHashString(str_keys[i], m);
            printf("%s\t%d\n", str_keys[i], idx);
        }
        printf("\n");
    }

    return 0;
}
