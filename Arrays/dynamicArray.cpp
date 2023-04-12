#include "dynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray()
    : size_(0), capacity_(1), data_(new T[capacity_]) {}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data_;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
    return size_;
}

template <typename T>
int DynamicArray<T>::getCapacity() const
{
    return capacity_;
}

template <typename T>
T &DynamicArray<T>::operator[](int index)
{
    if (index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
const T &DynamicArray<T>::operator[](int index) const
{
    if (index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
    if (size_ == capacity_)
    {
        resize(2 * capacity_);
    }
    data_[size_++] = value;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (size_ == 0)
    {
        throw std::length_error("Array is empty");
    }
    size_--;
}

template <typename T>
void DynamicArray<T>::insertAt(int index, const T &value)
{
    if (index < 0 || index > size_)
    {
        throw std::out_of_range("Index out of range");
    }

    if (size_ == capacity_)
    {
        resize(2 * capacity_);
    }

    for (int i = size_; i > index; i--)
    {
        data_[i] = data_[i - 1];
    }

    data_[index] = value;
    size_++;
}

template <typename T>
void DynamicArray<T>::deleteAt(int index)
{
    if (index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }

    for (int i = index; i < size_ - 1; i++)
    {
        data_[i] = data_[i + 1];
    }

    size_--;
}

template <typename T>
void DynamicArray<T>::resize(int new_capacity)
{
    T *new_data = new T[new_capacity];
    for (int i = 0; i < size_; i++)
    {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

// Explicit template instantiation
template class DynamicArray<int>;
template class DynamicArray<std::string>;
