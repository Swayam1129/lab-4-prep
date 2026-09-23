#include <cstddef>  // size_t
#include <iostream>
#include <cstdint>
#include <list>
#include <vector>
#include <random>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    std::mt19937_64 rng;
    Timer timer;

    std::list<uint64_t> lisst;
    rng.seed(0);
    timer.restart();
    for (size_t i = 0;i< SIZE; i++){
        lisst.push_back(rng());
    }
    uint64_t listInsert = timer.click<Timer::Micros>();
    
    std::vector<uint64_t> vec;
    rng.seed(0);
    timer.restart();
    for (size_t i = 0; i< SIZE; i++){
        vec.push_back(rng());
    }
    uint64_t VecInsert = timer.click<Timer::Micros>();
    
    std::vector<uint64_t> vecReserved;
    rng.seed(0);
    timer.restart();
    vecReserved.reserve(SIZE);
    for (size_t i = 0; i< SIZE; i++){
        vecReserved.push_back(rng());
    }
    uint64_t VecReservedInsert = timer.click<Timer::Micros>();

    std::cout << "list insert: " << listInsert << " us\n";
    std::cout << "vector insert: " << VecInsert << " us\n";
    std::cout << "VectorReserved insert: " << VecReservedInsert << " us\n";

    uint64_t listSum = 0;                               
    timer.restart();                                    
    for (uint64_t x : lisst) {                          
        listSum += x;                                   
    }
    uint64_t listSumTime = timer.click<Timer::Micros>(); 
    std::cout << "list sum: " << listSum << ", time: " << listSumTime << " us\n"; 

    uint64_t vecSum = 0;                               
    timer.restart();                                    
    for (uint64_t x : vec) {                          
        vecSum += x;                                   
    }
    uint64_t vecSumTime = timer.click<Timer::Micros>(); 
    std::cout << "Vec sum: " << vecSum << ", time: " << vecSumTime << " us\n"; 

    uint64_t vecResSum = 0;                               
    timer.restart();                                    
    for (uint64_t x : vecReserved) {                          
        vecResSum += x;                                   
    }
    uint64_t vecResSumTime = timer.click<Timer::Micros>(); 
    std::cout << "VecRes sum: " << vecResSum << ", time: " << vecResSumTime << " us\n"; 
    return 0;


}
