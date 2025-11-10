// ========================================
// hash_fn.cpp — implement your hash functions
// ========================================

#include <string>

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    for (char c : str)
        hash = hash * 31 + static_cast<unsigned char>(c);
    return static_cast<int>(hash % m);
}
