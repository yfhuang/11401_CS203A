/* 
   ========================================
   Hash Function Observation (C Version)
   ========================================
   
   Description:
   This program tests and displays the output of hash functions for integer
   and string keys using different table sizes. It utilizes the hash functions
   defined in "hash_fn.c".

   Development History:
    - 2025/11/11: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include <stdio.h>
#include <string.h>
#include "hash_fn.h"

// Caution: Do not change the content of this file.

int main(void) {
    // Integer keys
    int int_keys[] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
    int num_keys = sizeof(int_keys) / sizeof(int_keys[0]);

    // Table sizes to test
    int table_sizes[] = {10, 11, 37};
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

    // String keys (Non-integer keys)
    const char* str_keys[] = {"cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"};
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
