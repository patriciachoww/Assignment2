/**
 * @file Vector.h
 * @brief Template Vector class.
 *
 * Dynamic array with resizing and indexed access.
 *
 * @author Patricia
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

// Class interface

template <class T>
class Vector
{
public:
    Vector(int n = 1);                // Constructor with initial capacity
    ~Vector();                        // Destructor

    Vector(const Vector<T>& other);   // Copy constructor
    Vector<T>& operator=(const Vector<T>& other); // Assignment operator

    T& operator[](const int index);             // Access element (read/write)
    const T& operator[](const int index) const; // Access element (read-only)

    int Size() const;      // Number of elements
    int Capacity() const;  // Current capacity

    bool push_back(const T& item);          // Add element to end
    bool Insert(const int index, const T& item); // Insert at position
    bool Delete(const int index);           // Remove element

    void Clear();  // Remove all elements
    void Fill(int n); // Fill with default values

private:
    T* array;      // Pointer to dynamic array
    int capacity;  // Allocated size
    int count;     // Number of elements used

    void Resize(); // Double capacity when full
};

// Implementation of Vector methods

template <class T>
Vector<T>::Vector(int size) : array(nullptr), capacity(0), count(0)
{
    if (size <= 0)
        size = 1;

    capacity = size;
    array = new T[capacity]; // Allocate memory
}

template <class T>
Vector<T>::~Vector()
{
    delete[] array; // Free memory
}

template <class T>
Vector<T>::Vector(const Vector<T>& other)
    : array(nullptr), capacity(other.capacity), count(other.count)
{
    array = new T[capacity];

    for (int i = 0; i < count; i++)
        array[i] = other.array[i]; // Copy elements
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        delete[] array;

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
        Resize(); // Expand if full

    array[count++] = item;
    return true;
}

template <class T>
bool Vector<T>::Insert(const int index, const T& item)
{
    if (index < 0 || index > count)
        throw std::out_of_range("Vector insert index out of range");

    if (count == capacity)
        Resize();

    for (int i = count; i > index; i--)
        array[i] = array[i - 1]; // Shift right

    array[index] = item;
    count++;

    return true;
}

template <class T>
bool Vector<T>::Delete(const int index)
{
    if (index < 0 || index >= count)
        throw std::out_of_range("Vector delete index out of range");

    for (int i = index; i < count - 1; i++)
        array[i] = array[i + 1]; // Shift left

    count--;
    return true;
}

template <class T>
void Vector<T>::Clear()
{
    delete[] array;

    capacity = 1;
    count = 0;

    array = new T[capacity]; // Reset
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

        count = n; // Default values already exist
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
