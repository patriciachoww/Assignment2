#ifndef BST_H
#define BST_H

#include <iostream>

template <class T>
class Bst
{
public:
    Bst();
    Bst(const Bst<T>& other);
    Bst<T>& operator=(const Bst<T>& other);
    ~Bst();

    void Insert(const T& item);       // insert value
    bool Search(const T& item) const; // find value

    void InOrder() const;   // LNR
    void PreOrder() const;  // NLR
    void PostOrder() const; // LRN

    bool CheckBST() const;  // validate BST
    bool IsEmpty() const;   // check empty

private:
    struct Node
    {
        T item;
        Node* left;
        Node* right;

        Node(const T& value); // create node
    };

    Node* m_root;

private:
    void InsertRecursive(Node*& cur, const T& item);
    bool SearchRecursive(const Node* cur, const T& item) const;

    void InOrderRecursive(const Node* cur) const;
    void PreOrderRecursive(const Node* cur) const;
    void PostOrderRecursive(const Node* cur) const;

    void DestroyRecursive(Node*& cur);       // free memory
    Node* CloneRecursive(const Node* cur) const;

    bool CheckBSTRecursive(const Node* cur,
                           const T* low,
                           const T* high) const;
};

// ===== Implementation =====

template <class T>
Bst<T>::Node::Node(const T& value)
    : item(value), left(nullptr), right(nullptr)
{
}

template <class T>
Bst<T>::Bst()
    : m_root(nullptr)
{
}

template <class T>
Bst<T>::Bst(const Bst<T>& other)
    : m_root(nullptr)
{
    m_root = CloneRecursive(other.m_root); // deep copy
}

template <class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other)
{
    if (this != &other)
    {
        DestroyRecursive(m_root);            // clear old
        m_root = CloneRecursive(other.m_root); // copy new
    }
    return *this;
}

template <class T>
Bst<T>::~Bst()
{
    DestroyRecursive(m_root); // cleanup
}

template <class T>
bool Bst<T>::IsEmpty() const
{
    return m_root == nullptr;
}

template <class T>
void Bst<T>::Insert(const T& item)
{
    InsertRecursive(m_root, item);
}

template <class T>
void Bst<T>::InsertRecursive(Node*& cur, const T& item)
{
    if (cur == nullptr)
    {
        cur = new Node(item); // new node
        return;
    }

    if (item < cur->item)
    {
        InsertRecursive(cur->left, item);
    }
    else if (cur->item < item)
    {
        InsertRecursive(cur->right, item);
    }
    // duplicate → ignore
}

template <class T>
bool Bst<T>::Search(const T& item) const
{
    return SearchRecursive(m_root, item);
}

template <class T>
bool Bst<T>::SearchRecursive(const Node* cur, const T& item) const
{
    if (cur == nullptr)
        return false;

    if (item == cur->item)
        return true;

    if (item < cur->item)
        return SearchRecursive(cur->left, item);

    return SearchRecursive(cur->right, item);
}

template <class T>
void Bst<T>::InOrder() const
{
    InOrderRecursive(m_root);
    std::cout << std::endl;
}

template <class T>
void Bst<T>::InOrderRecursive(const Node* cur) const
{
    if (cur == nullptr) return;

    InOrderRecursive(cur->left);
    std::cout << cur->item << " ";
    InOrderRecursive(cur->right);
}

template <class T>
void Bst<T>::PreOrder() const
{
    PreOrderRecursive(m_root);
    std::cout << std::endl;
}

template <class T>
void Bst<T>::PreOrderRecursive(const Node* cur) const
{
    if (cur == nullptr) return;

    std::cout << cur->item << " ";
    PreOrderRecursive(cur->left);
    PreOrderRecursive(cur->right);
}

template <class T>
void Bst<T>::PostOrder() const
{
    PostOrderRecursive(m_root);
    std::cout << std::endl;
}

template <class T>
void Bst<T>::PostOrderRecursive(const Node* cur) const
{
    if (cur == nullptr) return;

    PostOrderRecursive(cur->left);
    PostOrderRecursive(cur->right);
    std::cout << cur->item << " ";
}

template <class T>
void Bst<T>::DestroyRecursive(Node*& cur)
{
    if (cur == nullptr) return;

    DestroyRecursive(cur->left);
    DestroyRecursive(cur->right);
    delete cur;
    cur = nullptr; // avoid dangling
}

template <class T>
typename Bst<T>::Node* Bst<T>::CloneRecursive(const Node* cur) const
{
    if (cur == nullptr)
        return nullptr;

    Node* newNode = new Node(cur->item);

    newNode->left = CloneRecursive(cur->left);
    newNode->right = CloneRecursive(cur->right);

    return newNode;
}

template <class T>
bool Bst<T>::CheckBST() const
{
    return CheckBSTRecursive(m_root, nullptr, nullptr);
}

template <class T>
bool Bst<T>::CheckBSTRecursive(const Node* cur,
                               const T* low,
                               const T* high) const
{
    if (cur == nullptr)
        return true;

    if (low != nullptr && !( *low < cur->item ))
        return false;

    if (high != nullptr && !( cur->item < *high ))
        return false;

    return CheckBSTRecursive(cur->left, low, &cur->item) &&
           CheckBSTRecursive(cur->right, &cur->item, high);
}

#endif
