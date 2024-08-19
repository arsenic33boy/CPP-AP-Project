#pragma once
#include <iostream>
#include <stdexcept>  // For std::out_of_range

template <typename T>
class CustomVector {
private:
    T* data;      // Pointer to the array of elements
    unsigned int size;  // Number of elements

    void ResizeIfNeeded() {
        if (size == 0) {
            Resize(1);
        }
    }

public:
    // Constructor
    CustomVector(unsigned int initial_size = 0, T init = T())
        : size(initial_size) {
        data = new T[size];
        for (unsigned int i = 0; i < size; ++i) {
            data[i] = init;
        }
    }

    // Destructor
    ~CustomVector() {
        delete[] data;
    }

    // Get size
    unsigned int GetSize() const {
        return size;
    }

    // Resize the vector
    void Resize(unsigned int new_size, T init = T()) {
        T* new_data = new T[new_size];
        for (unsigned int i = 0; i < new_size; ++i) {
            if (i < size) {
                new_data[i] = data[i];
            }
            else {
                new_data[i] = init;
            }
        }
        delete[] data;
        data = new_data;
        size = new_size;
    }

    // Add an element at the end
    void Insert(unsigned int index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        Resize(size + 1);
        for (unsigned int i = size - 1; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }

    // Remove an element at a specific position
    void Remove(unsigned int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (unsigned int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        Resize(size - 1);
    }

    // Access element by index
    T& operator[](unsigned int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
};
