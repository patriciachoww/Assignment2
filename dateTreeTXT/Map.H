/**
 * @file Map.h
 * @brief Template Map class.
 *
 * Stores key-value pairs using two parallel vectors.
 *
 * @author Patricia
 */

#ifndef MAP_H
#define MAP_H

#include "Vector.h"

// Class interface

/**
 * @class Map
 * @brief Simple key-value container.
 *
 * Stores keys and values in parallel Vector objects.
 *
 * @tparam K Key type (must support == comparison)
 * @tparam V Value type
 */
template <class K, class V>
class Map
{
public:
    Map();                    // Default constructor
    Map(int capacity);        // Constructor with initial capacity

    void Set(const K& key, const V& value); // Insert or update key-value pair
    V Get(const K& key) const;              // Retrieve value by key

    bool HasKey(const K& key) const; // Check if key exists
    int Size() const;                // Number of key-value pairs

    void Clear(); // Remove all entries

private:
    Vector<K> keys;     // Stores keys
    Vector<V> values;   // Stores corresponding values

    int FindIndex(const K& key) const; // Find index of a key
};

// Implementation of Map methods

template <class K, class V>
Map<K, V>::Map() : keys(10), values(10)
{
    // Initialize with default capacity
}

template <class K, class V>
Map<K, V>::Map(int capacity) : keys(capacity), values(capacity)
{
    // Initialize with given capacity
}

template <class K, class V>
void Map<K, V>::Set(const K& key, const V& value)
{
    int index = FindIndex(key);

    if (index >= 0)
    {
        values[index] = value; // Update existing key
    }
    else
    {
        keys.push_back(key);   // Insert new key
        values.push_back(value);
    }
}

template <class K, class V>
V Map<K, V>::Get(const K& key) const
{
    int index = FindIndex(key);

    if (index < 0)
        throw std::out_of_range("Map key not found");

    return values[index]; // Return value at found index
}

template <class K, class V>
bool Map<K, V>::HasKey(const K& key) const
{
    return FindIndex(key) >= 0; // Key exists if index is valid
}

template <class K, class V>
int Map<K, V>::Size() const
{
    return keys.Size(); // Number of stored keys
}

template <class K, class V>
void Map<K, V>::Clear()
{
    keys.Clear();   // Clear keys
    values.Clear(); // Clear values
}

template <class K, class V>
int Map<K, V>::FindIndex(const K& key) const
{
    for (int i = 0; i < keys.Size(); i++)
    {
        if (keys[i] == key)
            return i; // Return matching index
    }
    return -1; // Key not found
}

#endif
