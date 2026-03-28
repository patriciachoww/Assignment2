#ifndef BST_H
#define BST_H

#include <iostream>

/**
 * @file Bst.h
 * @brief Template Binary Search Tree class.
 *
 * Stores items in Binary Search Tree form.
 * Supports insertion, searching, traversal,
 * deep copy, destruction, and BST validation.
 *
 * Type T must support:
 * - operator<
 * - operator>
 * - operator==
 */
template <class T>
class Bst
{
public:
    /**
     * @brief Callback type for traversal.
     */
    typedef void (*VisitFunc)(const T&);

    /**
     * @brief Construct an empty BST.
     */
    Bst();

    /**
     * @brief Copy constructor.
     * @param other BST to copy.
     */
    Bst(const Bst<T>& other);

    /**
     * @brief Assignment operator.
     * @param other BST to assign from.
     * @return Reference to this BST.
     */
    Bst<T>& operator=(const Bst<T>& other);

    /**
     * @brief Destroy the BST.
     */
    ~Bst();

    /**
     * @brief Insert an item into the BST.
     * @param item Item to insert.
     */
    void Insert(const T& item);

    /**
     * @brief Search for an item in the BST.
     * @param item Item to search for.
     * @return True if found, false otherwise.
     */
    bool Search(const T& item) const;

    /**
     * @brief Traverse the tree in inorder.
     * @param visit Callback function.
     */
    void InOrder(VisitFunc visit) const;

    /**
     * @brief Traverse the tree in preorder.
     * @param visit Callback function.
     */
    void PreOrder(VisitFunc visit) const;

    /**
     * @brief Traverse the tree in postorder.
     * @param visit Callback function.
     */
    void PostOrder(VisitFunc visit) const;

    /**
     * @brief Check whether the BST is valid.
     * @return True if valid, false otherwise.
     */
    bool CheckBST() const;

    /**
     * @brief Check whether the BST is empty.
     * @return True if empty, false otherwise.
     */
    bool IsEmpty() const;

    /**
     * @brief Remove all nodes from the tree.
     */
    void Clear();

private:
    /**
     * @brief Node structure for the BST.
     */
    struct Node
    {
        T item;       ///< Stored item
        Node* left;   ///< Left child
        Node* right;  ///< Right child

        /**
         * @brief Construct a node.
         * @param value Item to store.
         */
        Node(const T& value);
    };

    Node* m_root; ///< Root pointer

private:
    void InsertRecursive(Node*& cur, const T& item);
    bool SearchRecursive(const Node* cur, const T& item) const;

    void InOrderRecursive(const Node* cur, VisitFunc visit) const;
    void PreOrderRecursive(const Node* cur, VisitFunc visit) const;
    void PostOrderRecursive(const Node* cur, VisitFunc visit) const;

    void DestroyRecursive(Node*& cur);
    Node* CloneRecursive(const Node* cur) const;
    bool CheckBSTRecursive(const Node* cur, const T* low, const T* high) const;
};

/**
 * @brief Construct a node with a value.
 * @param value Item to store.
 */
template <class T>
Bst<T>::Node::Node(const T& value)
    : item(value), left(nullptr), right(nullptr)
{
}

/**
 * @brief Construct an empty BST.
 */
template <class T>
Bst<T>::Bst()
    : m_root(nullptr)
{
}

/**
 * @brief Copy constructor.
 * @param other BST to copy.
 */
template <class T>
Bst<T>::Bst(const Bst<T>& other)
    : m_root(nullptr)
{
    m_root = CloneRecursive(other.m_root);
}

/**
 * @brief Assignment operator.
 * @param other BST to assign from.
 * @return Reference to this BST.
 */
template <class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other)
{
    if (this != &other)
    {
        Clear();
        m_root = CloneRecursive(other.m_root);
    }

    return *this;
}

/**
 * @brief Destroy the BST.
 */
template <class T>
Bst<T>::~Bst()
{
    Clear();
}

/**
 * @brief Insert an item into the BST.
 * @param item Item to insert.
 */
template <class T>
void Bst<T>::Insert(const T& item)
{
    InsertRecursive(m_root, item);
}

/**
 * @brief Insert helper function.
 * @param cur Current node pointer.
 * @param item Item to insert.
 */
template <class T>
void Bst<T>::InsertRecursive(Node*& cur, const T& item)
{
    if (cur == nullptr)
    {
        cur = new Node(item);
    }
    else if (item < cur->item)
    {
        InsertRecursive(cur->left, item);
    }
    else if (item > cur->item)
    {
        InsertRecursive(cur->right, item);
    }
}

/**
 * @brief Search for an item in the BST.
 * @param item Item to search for.
 * @return True if found, false otherwise.
 */
template <class T>
bool Bst<T>::Search(const T& item) const
{
    return SearchRecursive(m_root, item);
}

/**
 * @brief Search helper function.
 * @param cur Current node pointer.
 * @param item Item to search for.
 * @return True if found, false otherwise.
 */
template <class T>
bool Bst<T>::SearchRecursive(const Node* cur, const T& item) const
{
    if (cur == nullptr)
    {
        return false;
    }

    if (item == cur->item)
    {
        return true;
    }
    else if (item < cur->item)
    {
        return SearchRecursive(cur->left, item);
    }
    else
    {
        return SearchRecursive(cur->right, item);
    }
}

/**
 * @brief Traverse the tree in inorder.
 * @param visit Callback function.
 */
template <class T>
void Bst<T>::InOrder(VisitFunc visit) const
{
    InOrderRecursive(m_root, visit);
}

/**
 * @brief Inorder traversal helper.
 * @param cur Current node pointer.
 * @param visit Callback function.
 */
template <class T>
void Bst<T>::InOrderRecursive(const Node* cur, VisitFunc visit) const
{
    if (cur != nullptr)
    {
        InOrderRecursive(cur->left, visit);
        visit(cur->item);
        InOrderRecursive(cur->right, visit);
    }
}

/**
 * @brief Traverse the tree in preorder.
 * @param visit Callback function.
 */
template <class T>
void Bst<T>::PreOrder(VisitFunc visit) const
{
    PreOrderRecursive(m_root, visit);
}

/**
 * @brief Preorder traversal helper.
 * @param cur Current node pointer.
 * @param visit Callback function.
 */
template <class T>
void Bst<T>::PreOrderRecursive(const Node* cur, VisitFunc visit) const
{
    if (cur != nullptr)
    {
        visit(cur->item);
        PreOrderRecursive(cur->left, visit);
        PreOrderRecursive(cur->right, visit);
    }
}

/**
 * @brief Traverse the tree in postorder.
 * @param visit Callback function.
 */
template <class T>
void Bst<T>::PostOrder(VisitFunc visit) const
{
    PostOrderRecursive(m_root, visit);
}

/**
 * @brief Postorder traversal helper.
 * @param cur Current node pointer.
 * @param visit Callback function.
 */
template <class T>
void Bst<T>::PostOrderRecursive(const Node* cur, VisitFunc visit) const
{
    if (cur != nullptr)
    {
        PostOrderRecursive(cur->left, visit);
        PostOrderRecursive(cur->right, visit);
        visit(cur->item);
    }
}

/**
 * @brief Check whether the BST is valid.
 * @return True if valid, false otherwise.
 */
template <class T>
bool Bst<T>::CheckBST() const
{
    return CheckBSTRecursive(m_root, nullptr, nullptr);
}

/**
 * @brief BST validation helper.
 * @param cur Current node pointer.
 * @param low Lower bound.
 * @param high Upper bound.
 * @return True if valid, false otherwise.
 */
template <class T>
bool Bst<T>::CheckBSTRecursive(const Node* cur, const T* low, const T* high) const
{
    if (cur == nullptr)
    {
        return true;
    }

    if (low != nullptr && !(cur->item > *low))
    {
        return false;
    }

    if (high != nullptr && !(cur->item < *high))
    {
        return false;
    }

    return CheckBSTRecursive(cur->left, low, &cur->item) &&
           CheckBSTRecursive(cur->right, &cur->item, high);
}

/**
 * @brief Check whether the BST is empty.
 * @return True if empty, false otherwise.
 */
template <class T>
bool Bst<T>::IsEmpty() const
{
    return m_root == nullptr;
}

/**
 * @brief Remove all nodes from the BST.
 */
template <class T>
void Bst<T>::Clear()
{
    DestroyRecursive(m_root);
}

/**
 * @brief Destroy helper function.
 * @param cur Current node pointer.
 */
template <class T>
void Bst<T>::DestroyRecursive(Node*& cur)
{
    if (cur != nullptr)
    {
        DestroyRecursive(cur->left);
        DestroyRecursive(cur->right);
        delete cur;
        cur = nullptr;
    }
}

/**
 * @brief Clone helper function.
 * @param cur Current node pointer.
 * @return Pointer to copied subtree.
 */
template <class T>
typename Bst<T>::Node* Bst<T>::CloneRecursive(const Node* cur) const
{
    if (cur == nullptr)
    {
        return nullptr;
    }

    Node* newNode = new Node(cur->item);
    newNode->left = CloneRecursive(cur->left);
    newNode->right = CloneRecursive(cur->right);

    return newNode;
}

#endif
