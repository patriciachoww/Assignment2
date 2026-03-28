/**
 * @file Main.CPP
 * @brief Demonstrates Integer Binary Search Tree (BST) operations.
 *
 * Reads integers from file, inserts into BST,
 * and performs traversal and search using callbacks.
 *
 * @author Patricia
 * @date 28/03/2026
 */

#include "../Bst.h"
#include <iostream>
#include <fstream>

/**
 * @brief Prints an integer value during traversal.
 * @param value Integer to print.
 */
void PrintInt(const int& value)
{
    std::cout << value << " ";
}

int main()
{
    // Open input file
    std::ifstream inputFile("data/integers.txt");

    // Check if file opened successfully
    if (!inputFile)
    {
        std::cerr << "Error: Unable to open data file." << std::endl;
        return 1;
    }

    // Create BST object
    Bst<int> intTree;

    // Read integers and insert into BST
    int value;
    while (inputFile >> value)
    {
        intTree.Insert(value);
    }

    inputFile.close();

    // Display header
    std::cout << "===== Integer BST Demo =====" << std::endl;

    // Check BST validity
    std::cout << "BST valid: "
              << (intTree.CheckBST() ? "Yes" : "No") << std::endl;

    // Inorder traversal
    std::cout << "InOrder: ";
    intTree.InOrder(PrintInt);
    std::cout << std::endl;

    // Preorder traversal
    std::cout << "PreOrder: ";
    intTree.PreOrder(PrintInt);
    std::cout << std::endl;

    // Postorder traversal
    std::cout << "PostOrder: ";
    intTree.PostOrder(PrintInt);
    std::cout << std::endl;

    // Search test
    std::cout << "Search 40: "
              << (intTree.Search(40) ? "Found" : "Not found") << std::endl;

    std::cout << "Search 99: "
              << (intTree.Search(99) ? "Found" : "Not found") << std::endl;

    // Duplicate insert test
    std::cout << "Insert duplicate 50" << std::endl;
    intTree.Insert(50);

    std::cout << "InOrder after duplicate insert: ";
    intTree.InOrder(PrintInt);
    std::cout << std::endl;

    return 0;
}
