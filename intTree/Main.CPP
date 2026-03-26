/**
 * @file main.cpp
 * @brief Demo program for Integer Binary Search Tree (BST).
 *
 * Reads integers from file, inserts into BST,
 * and demonstrates basic operations.
 *
 * @author Patricia
 * @date 25/03/2026
 */

#include "../Bst.h"
#include <iostream>
#include <fstream>

int main()
{
    // open input file
    std::ifstream inputFile("data/integers.txt");

    // check file opened
    if (!inputFile)
    {
        std::cerr << "Error: Unable to open data file." << std::endl;
        return 1;
    }

    // create BST
    Bst<int> intTree;

    // read values and insert into BST
    int value;
    while (inputFile >> value)
    {
        intTree.Insert(value);
    }

    // display header
    std::cout << "===== Integer BST Demo =====" << std::endl;

    // check BST validity
    std::cout << "BST valid: "
              << (intTree.CheckBST() ? "Yes" : "No") << std::endl;

    // traversals
    std::cout << "InOrder: ";
    intTree.InOrder();

    std::cout << "PreOrder: ";
    intTree.PreOrder();

    std::cout << "PostOrder: ";
    intTree.PostOrder();

    // search tests
    std::cout << "Search 40: "
              << (intTree.Search(40) ? "Found" : "Not found") << std::endl;

    std::cout << "Search 99: "
              << (intTree.Search(99) ? "Found" : "Not found") << std::endl;

    // duplicate test
    std::cout << "Insert duplicate 50" << std::endl;
    intTree.Insert(50);

    std::cout << "InOrder after duplicate insert: ";
    intTree.InOrder();

    return 0;
}
