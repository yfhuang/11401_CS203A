/*
   ========================================
   hash_fn.h — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stdio.h>
#include <string.h>

int myHashString(const char* str, int m);
int myHashInt(int key, int m);

#endif
