#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t
#include <iostream>

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale >= 1);                      

    uint64_t result = 0;
    for (uint64_t i = 0; i < 64; ++i) {
        uint64_t pos = i*scale;                  
        if (pos >= 64) {
            break;                           
        }
        uint64_t bit = (input >> i) & 1;                 
        result |= bit << pos;               
    }
    return result;  // replace this with your impl!
}

int main() {
    // test here...
    assert(expand(0b1111, 3) == 0b001001001001);
    assert(expand(0b0101, 2) == 0b00010001);
    assert(expand(0b11, 4) == 0b10001);
    assert(expand(0, 5) == 0);
    assert(expand(0b1011, 1) == 0b1011);
    std::cout << "All tests passed\n";
    return 0;
}
