/* 
   ========================================
   Hash Function Observation (C++ Version)
   ========================================
   
   Description:
   This program tests and displays the output of hash functions for integer
   and string keys using different table sizes. It utilizes the hash functions
   defined in "hash_fn.cpp".

   Development History:
    - 2025/11/11: Initial implementation

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include <iostream>
#include <vector>
#include <string>
#include "hash_fn.hpp"

// Caution: Do not change the content of this file.

int main() {
    // Integer keys
    std::vector<int> intKeys = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
    
    // Table sizes to test
    std::vector<int> sizes = {10, 11, 37};

    std::cout << "=== Hash Function Observation (C++ Version) ===\n\n";

    for (int m : sizes) {
        std::cout << "=== Table Size m = " << m << " ===\n";
        std::cout << "Key\tIndex\n";
        std::cout << "-----------------\n";
        for (int k : intKeys)
            std::cout << k << "\t" << myHashInt(k, m) << "\n";
        std::cout << "\n";
    }

    // String keys (Non-integer keys)
    std::vector<std::string> strKeys = {"cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"};
    for (int m : sizes) {
        std::cout << "=== String Hash (m = " << m << ") ===\n";
        std::cout << "Key\tIndex\n";
        std::cout << "-----------------\n";
        for (const auto& s : strKeys)
            std::cout << s << "\t" << myHashString(s, m) << "\n";
        std::cout << "\n";
    }
}
