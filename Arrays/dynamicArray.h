#pragma once

#include <stdexcept>

template<typename T>
class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();

    int getSize() const;
    int getCapacity() const;
    T& operator[](int index);
    void push_back(const T& value);
    void pop_back();
    void insertAt(int index, const T& value);
    void deleteAt(int index);

private:
    void resize(int new_capacity);

    int size_;
    int capacity_;
    T* data_;
};

#include "dynamicArray.cpp"
