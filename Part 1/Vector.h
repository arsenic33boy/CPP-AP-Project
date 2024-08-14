#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class vector {
public:
    vector() : data(nullptr), N(0), capacity(0) {}
    vector(int _N, T _Val);
    ~vector();
    T& operator[](int index) {
        if (index >= static_cast<int>(N) || index < 0) {
            throw std::out_of_range("Array index out of bounds");
        }
        return *data[index];
    }
    void push_back(const T& value);
    void resize(int new_size);
    void remove(int index);
    void insert(int index, const T& value);
    int size() const {
        return N;
    }

protected:
    T** data;
    int N;
    int capacity;

    void resize_if_needed();
};

template <typename T>
vector<T>::vector(int _N, T _Val) : N(_N), capacity(_N) {
    data = new T * [N];
    for (int i = 0; i < N; i++) {
        data[i] = new T(_Val);
    }
}

template <typename T>
vector<T>::~vector() {
    for (int i = 0; i < N; i++) {
        delete data[i];
        std::cout << i << "\n";
    }
    delete[] data;
}


template <typename T>
void vector<T>::push_back(const T& value) {
    resize_if_needed();
    data[N] = new T(value);
    N++;
}

template <typename T>
void vector<T>::resize(int new_size) {
    if (new_size > capacity) {
        T** new_data = new T * [new_size];
        for (int i = 0; i < N; i++) {
            new_data[i] = data[i];
        }
        for (int i = N; i < new_size; i++) {
            new_data[i] = nullptr;
        }
        delete[] data;
        data = new_data;
        capacity = new_size;
    }
    N = new_size;
}

template <typename T>
void vector<T>::remove(int index) {
    if (index < 0 || index >= N) {
        throw std::out_of_range("Index out of range");
    }
    delete data[index];
    for (int i = index; i < N - 1; i++) {
        data[i] = data[i + 1];
    }
    N--;
}

template <typename T>
void vector<T>::insert(int index, const T& value) {
    if (index < 0 || index > N) {
        throw std::out_of_range("Index out of range");
    }
    resize_if_needed();
    for (int i = N; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = new T(value);
    N++;
}

template <typename T>
void vector<T>::resize_if_needed() {
    if (N >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
}

