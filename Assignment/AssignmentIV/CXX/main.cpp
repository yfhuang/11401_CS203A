// ========================================
// Hash Function Observation (C++ Version)
// ========================================
#include <iostream>
#include <vector>
#include <string>
#include "hash_fn.cpp"

int main() {
    std::vector<int> intKeys = {21,22,23,24,25,26,27,28,29,30};
    std::vector<int> sizes = {10, 11, 101};

    std::cout << "=== Hash Function Observation (C++ Version) ===\n\n";

    for (int m : sizes) {
        std::cout << "=== Table Size m = " << m << " ===\n";
        std::cout << "Key\tIndex\n";
        std::cout << "-----------------\n";
        for (int k : intKeys)
            std::cout << k << "\t" << myHashInt(k, m) << "\n";
        std::cout << "\n";
    }

    std::vector<std::string> strKeys = {"cat","dog","bat","cow","ant","owl","bee","hen","pig","fox"};
    for (int m : sizes) {
        std::cout << "=== String Hash (m = " << m << ") ===\n";
        std::cout << "Key\tIndex\n";
        std::cout << "-----------------\n";
        for (const auto& s : strKeys)
            std::cout << s << "\t" << myHashString(s, m) << "\n";
        std::cout << "\n";
    }
}
