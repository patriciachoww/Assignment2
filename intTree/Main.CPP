/**
 * @file main.cpp
 * @brief Demo program for Integer Binary Search Tree (BST).
 *
 * Reads integers from file, inserts into BST,
 * and demonstrates operations using traversal callbacks.
 *
 * @author Patricia
 * @date 28/03/2026
 */

#include "../Bst.H"
#include <iostream>
#include <fstream>

/**
 * @brief Print integer value (callback function).
 * @param value Integer to print.
 */
void PrintInt(const int& value)
{
    std::cout << value << " ";
}

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

    inputFile.close();

    // display header
    std::cout << "===== Integer BST Demo =====" << std::endl;

    // check BST validity
    std::cout << "BST valid: "
              << (intTree.CheckBST() ? "Yes" : "No") << std::endl;

    // traversals (UPDATED: pass function pointer)
    std::cout << "InOrder: ";
    intTree.InOrder(PrintInt);
    std::cout << std::endl;

    std::cout << "PreOrder: ";
    intTree.PreOrder(PrintInt);
    std::cout << std::endl;

    std::cout << "PostOrder: ";
    intTree.PostOrder(PrintInt);
    std::cout << std::endl;

    // search tests
    std::cout << "Search 40: "
              << (intTree.Search(40) ? "Found" : "Not found") << std::endl;

    std::cout << "Search 99: "
              << (intTree.Search(99) ? "Found" : "Not found") << std::endl;

    // duplicate test
    std::cout << "Insert duplicate 50" << std::endl;
    intTree.Insert(50);

    std::cout << "InOrder after duplicate insert: ";
    intTree.InOrder(PrintInt);
    std::cout << std::endl;

    return 0;
}
