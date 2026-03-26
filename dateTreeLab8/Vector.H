/**
 * @file Vector.h
 * @brief Template Vector class definition and implementation.
 *
 * A simple dynamic array class with automatic resizing,
 * indexed access, and basic insert/delete operations.
 *
 * @author Patricia
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

// Class interface

/**
 * @class Vector
 * @brief Template container that manages a dynamic array.
 *
 * This class stores elements in a heap-allocated array and
 * provides basic operations such as insertion, deletion,
 * resizing, and indexed access.
 *
 * @tparam T Type of element stored in the vector.
 */
template <class T>
class Vector
{
public:
    Vector(int n = 1);
    ~Vector();
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);

    T& operator[](const int index);
    const T& operator[](const int index) const;

    int Size() const;
    int Capacity() const;

    bool push_back(const T& item);
    bool Insert(const int index, const T& item);
    bool Delete(const int index);

    void Clear();
    void Fill(int n);

private:
    T* array;
    int capacity;
    int count;

    void Resize();
};

// Implementation of Vector methods

template <class T>
Vector<T>::Vector(int size) : array(nullptr), capacity(0), count(0)
{
    if (size <= 0)
        size = 1;

    capacity = size;
    array = new T[capacity];
}

template <class T>
Vector<T>::~Vector()
{
    if (array != nullptr)
    {
        delete[] array;
        array = nullptr;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T>& other)
    : array(nullptr), capacity(other.capacity), count(other.count)
{
    array = new T[capacity];

    for (int i = 0; i < count; i++)
        array[i] = other.array[i];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        delete[] array;
        array = nullptr;

        capacity = other.capacity;
        count = other.count;

        array = new T[capacity];
        for (int i = 0; i < count; i++)
            array[i] = other.array[i];
    }

    return *this;
}

template <class T>
T& Vector<T>::operator[](const int index)
{
    if (index < 0 || index >= count)
        throw std::out_of_range("Vector index out of range");

    return array[index];
}

template <class T>
const T& Vector<T>::operator[](const int index) const
{
    if (index < 0 || index >= count)
        throw std::out_of_range("Vector index out of range");

    return array[index];
}

template <class T>
int Vector<T>::Size() const
{
    return count;
}

template <class T>
int Vector<T>::Capacity() const
{
    return capacity;
}

template <class T>
bool Vector<T>::push_back(const T& item)
{
    if (count == capacity)
        Resize();

    array[count] = item;
    count++;

    return true;
}

template <class T>
bool Vector<T>::Insert(const int index, const T& item)
{
    if (index < 0 || index > count)
        throw std::out_of_range("Vector insert index out of range");

    if (index == count)
    {
        push_back(item);
    }
    else
    {
        if (count == capacity)
            Resize();

        for (int i = count; i > index; i--)
            array[i] = array[i - 1];

        array[index] = item;
        count++;
    }

    return true;
}

template <class T>
bool Vector<T>::Delete(const int index)
{
    if (index < 0 || index >= count)
        throw std::out_of_range("Vector delete index out of range");

    for (int i = index; i < count - 1; i++)
        array[i] = array[i + 1];

    count--;

    return true;
}

template <class T>
void Vector<T>::Clear()
{
    delete[] array;
    capacity = 1;
    count = 0;
    array = new T[capacity];
}

template <class T>
void Vector<T>::Fill(int n)
{
    if (n <= 0)
    {
        count = 0;
    }
    else
    {
        while (n > capacity)
            Resize();

        count = n;
    }
}

template <class T>
void Vector<T>::Resize()
{
    int newCapacity = capacity * 2;
    T* newArray = new T[newCapacity];

    for (int i = 0; i < count; i++)
        newArray[i] = array[i];

    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

#endif
