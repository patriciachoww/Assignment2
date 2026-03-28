#ifndef BST_H
#define BST_H

#include <iostream>

/**
 * @file Bst.H
 * @brief Template Binary Search Tree class.
 *
 * This class stores data in binary search tree form.
 * It supports insertion, searching, traversal, deep copying,
 * destruction, and BST validation.
 *
 * Traversal routines use function pointers so client code can
 * decide what action to perform on each visited item.
 */
template <class T>
class Bst
{
public:
    /**
     * @brief Function pointer type for simple traversal callbacks.
     */
    typedef void (*VisitFunc)(const T&);

    /**
     * @brief Function pointer type for traversal callbacks with context.
     */
    typedef void (*VisitFuncCtx)(const T&, void*);

    /**
     * @brief Construct an empty BST.
     */
    Bst();

    /**
     * @brief Copy constructor.
     * @param other Another BST to copy from.
     */
    Bst(const Bst<T>& other);

    /**
     * @brief Assignment operator.
     * @param other Another BST to assign from.
     * @return Reference to this BST.
     */
    Bst<T>& operator=(const Bst<T>& other);

    /**
     * @brief Destructor.
     */
    ~Bst();

    /**
     * @brief Insert an item into the BST.
     * @param item The item to insert.
     */
    void Insert(const T& item);

    /**
     * @brief Search for an item in the BST.
     * @param item The item to search for.
     * @return True if found, otherwise false.
     */
    bool Search(const T& item) const;

    /**
     * @brief Traverse the tree in inorder.
     * @param visit Callback function applied to each item.
     */
    void InOrder(VisitFunc visit) const;

    /**
     * @brief Traverse the tree in preorder.
     * @param visit Callback function applied to each item.
     */
    void PreOrder(VisitFunc visit) const;

    /**
     * @brief Traverse the tree in postorder.
     * @param visit Callback function applied to each item.
     */
    void PostOrder(VisitFunc visit) const;

    /**
     * @brief Traverse the tree in inorder with context data.
     * @param visit Callback function applied to each item.
     * @param context Extra user-defined data.
     */
    void InOrder(VisitFuncCtx visit, void* context) const;

    /**
     * @brief Traverse the tree in preorder with context data.
     * @param visit Callback function applied to each item.
     * @param context Extra user-defined data.
     */
    void PreOrder(VisitFuncCtx visit, void* context) const;

    /**
     * @brief Traverse the tree in postorder with context data.
     * @param visit Callback function applied to each item.
     * @param context Extra user-defined data.
     */
    void PostOrder(VisitFuncCtx visit, void* context) const;

    /**
     * @brief Check whether the tree satisfies BST rules.
     * @return True if valid BST, otherwise false.
     */
    bool CheckBST() const;

    /**
     * @brief Check whether the tree is empty.
     * @return True if empty, otherwise false.
     */
    bool IsEmpty() const;

private:
    /**
     * @brief Tree node structure.
     */
    struct Node
    {
        T item;        ///< Stored data
        Node* left;    ///< Pointer to left child
        Node* right;   ///< Pointer to right child

        /**
         * @brief Construct a node with a value.
         * @param value Data to store.
         */
        Node(const T& value);
    };

    Node* m_root;  ///< Root pointer of the BST

private:
    void InsertRecursive(Node*& cur, const T& item);
    bool SearchRecursive(const Node* cur, const T& item) const;

    void InOrderRecursive(const Node* cur, VisitFunc visit) const;
    void PreOrderRecursive(const Node* cur, VisitFunc visit) const;
    void PostOrderRecursive(const Node* cur, VisitFunc visit) const;

    void InOrderRecursive(const Node* cur, VisitFuncCtx visit, void* context) const;
    void PreOrderRecursive(const Node* cur, VisitFuncCtx visit, void* context) const;
    void PostOrderRecursive(const Node* cur, VisitFuncCtx visit, void* context) const;

    void DestroyRecursive(Node*& cur);
    Node* CloneRecursive(const Node* cur) const;
    bool CheckBSTRecursive(const Node* cur, const T* low, const T* high) const;
};

#endif
