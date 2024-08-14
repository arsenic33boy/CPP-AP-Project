#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class CustomVector {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize_if_needed() {
        if (size >= capacity) {
            capacity *= 2;
            T* new_data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
    }

public:
    CustomVector() : capacity(10), size(0) {
        data = new T[capacity];
    }

    ~CustomVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        resize_if_needed();
        data[size++] = value;
    }

    void resize(size_t new_size) {
        if (new_size > capacity) {
            T* new_data = new T[new_size];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_size;
        }
        size = new_size;
    }

    size_t get_size() const {
        return size;
    }

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        resize_if_needed();
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    T& operator[](int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

};