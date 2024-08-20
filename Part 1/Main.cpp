#include <iostream>
#include <vector>
#include <ctime>
#include "CustomVector.h" 
#include "pvector.h"       

// Define a struct with large data
class LargeObject {
public:
    std::vector<char> data;
    LargeObject(int size=1) : data(1024*1024*size) { }
};

int main() {
    // Number of elements for testing
    const size_t num_elements = 100;

    
    CustomVector<LargeObject> cvec(num_elements);

    LargeObject obj(1); 

    // Measure time for insert operations
    std::clock_t start_c_insert = std::clock();
    for (size_t i = 0; i < 10; ++i) {
        cvec.Insert(0, obj);
    }
    std::clock_t end_c_insert = std::clock();
    double c_insert_duration = 1000.0 * (end_c_insert - start_c_insert) / CLOCKS_PER_SEC;
    std::cout << "CustomVector insert operations took: " << c_insert_duration / 10 << " milliseconds on average" << std::endl;

    // Measure time for remove operations
    std::clock_t start_c_remove = std::clock();
    for (size_t i = 0; i < 10; ++i) {
        cvec.Remove(0);
    }
    std::clock_t end_c_remove = std::clock();
    double c_remove_duration = 1000.0 * (end_c_remove - start_c_remove) / CLOCKS_PER_SEC;
    std::cout << "CustomVector remove operations took: " << c_remove_duration / 10 << " milliseconds on average" << std::endl;

    // Measure performance of pvector
    pvector<LargeObject> pvec(num_elements, LargeObject());

    // Measure time for insert operations
    std::clock_t start_p_insert = std::clock();
    for (size_t i = 0; i < 10; ++i) {
        pvec.Insert(0, obj);
    }
    std::clock_t end_p_insert = std::clock();
    double p_insert_duration = 1000.0 * (end_p_insert - start_p_insert) / CLOCKS_PER_SEC;
    std::cout << "pvector insert operations took: " << p_insert_duration / 10 << " milliseconds on average" << std::endl;

    // Measure time for remove operations
    std::clock_t start_p_remove = std::clock();
    for (size_t i = 0; i < 10; ++i) {
        pvec.Remove(0);
    }
    std::clock_t end_p_remove = std::clock();
    double p_remove_duration = 1000.0 * (end_p_remove - start_p_remove) / CLOCKS_PER_SEC;
    std::cout << "pvector remove operations took: " << p_remove_duration / 10 << " milliseconds on average" << std::endl;
    


    return 0;
}
