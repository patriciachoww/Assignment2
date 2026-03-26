/**
 * @file Map.h
 * @brief Declaration and implementation of a simple template Map class.
 *
 * Stores key-value pairs using two parallel Vector containers.
 *
 * @author Patricia
 */

#ifndef MAP_H
#define MAP_H

#include "Vector.h"
#include <stdexcept>

// --- Class interface ---

/**
 * @class Map
 * @brief Simple key-value container using parallel vectors.
 *
 * Keys and values are stored at matching indices.
 *
 * @tparam K Key type
 * @tparam V Value type
 */
template <class K, class V>
class Map
{
public:
    Map();
    Map(int capacity);

    void Set(const K& key, const V& value);
    V Get(const K& key) const;
    bool HasKey(const K& key) const;
    int Size() const;
    void Clear();

private:
    Vector<K> keys;
    Vector<V> values;

    int FindIndex(const K& key) const;
};

// Implementation of Map methods

template <class K, class V>
Map<K, V>::Map() : keys(10), values(10)
{
}

template <class K, class V>
Map<K, V>::Map(int capacity) : keys(capacity), values(capacity)
{
}

template <class K, class V>
void Map<K, V>::Set(const K& key, const V& value)
{
    int index = FindIndex(key);

    if (index >= 0)
    {
        // Update existing value
        values[index] = value;
    }
    else
    {
        // Insert new key-value pair
        keys.push_back(key);
        values.push_back(value);
    }
}

template <class K, class V>
V Map<K, V>::Get(const K& key) const
{
    int index = FindIndex(key);

    if (index < 0)
        throw std::out_of_range("Key not found");

    return values[index];
}

template <class K, class V>
bool Map<K, V>::HasKey(const K& key) const
{
    return FindIndex(key) >= 0;
}

template <class K, class V>
int Map<K, V>::Size() const
{
    return keys.Size();
}

template <class K, class V>
void Map<K, V>::Clear()
{
    keys.Clear();
    values.Clear();
}

template <class K, class V>
int Map<K, V>::FindIndex(const K& key) const
{
    for (int i = 0; i < keys.Size(); i++)
    {
        if (keys[i] == key)
            return i;
    }
    return -1;
}

#endif
