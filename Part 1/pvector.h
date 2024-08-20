#pragma once
#include <iostream>


template <typename T>
class pvector {
private:
    unsigned int N; 
    T** data; 

public:
    
    pvector(unsigned int size = 0, T init = T())
        : N(size)
    {
        data = new T * [N];
        for (size_t i = 0; i < N; ++i) {
            data[i] = new T(init);
        }
    }

 
    
    ~pvector() {
        for (size_t i = 0; i < N; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    
    unsigned int GetSize() const {
        return N;
    }

    
    void Resize(unsigned int newSize, T init = T()) {
        T** temp = new T * [newSize];
        for (size_t i = 0; i < newSize; ++i) {
            if (i < N) {
                temp[i] = data[i];
            }
            else {
                temp[i] = new T(init);
            }
        }
        // Clean up old resources
        for (size_t i = newSize; i < N; ++i) {
            delete data[i];
        }
        delete[] data;
        data = temp;
        N = newSize;
    }

    
    void PushBack(T& value) {
        Resize(N + 1);
        data[N - 1] = new T(value);
    }

    
    void Insert(unsigned int index, const T& value = T()) {
        if (index >= N) {
            std::cout<<"Index out of bounds\n";
        }
        Resize(N + 1);
        delete data[N - 1];
        for (size_t i = N - 1; i > index; --i) {
            data[i] = data[i - 1];
        }

        data[index] = new T(value);
    }

    
    void Remove(unsigned int index) {
        if (index >= N) {
            std::cout << "Index out of bounds\n";
        }
        delete data[index];
        for (size_t i = index; i < N - 1; ++i) {
            data[i] = data[i + 1];
        }
        N--;
    }

    

    
    T& operator[](int index) {
        if (index >= static_cast<int>(N) || index < 0) {
            std::cout << "Index out of bounds\n";
        }
        return *data[index];
    }

    
};