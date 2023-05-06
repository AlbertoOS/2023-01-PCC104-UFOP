#ifndef DECREASE_AND_CONQUER_H
#define DECREASE_AND_CONQUER_H

#include <vector>
#include <memory>

int binary_search(std::vector<int> vector, int key);

int interpolation_search(std::vector<int> vector, int key);

// Reference https://thesai.org/Downloads/Volume6No3/Paper_9-Implementation_of_Binary_Search_Trees_Via_Smart_Pointers.pdf
// Implementation of Binary Search Trees Via Smart Pointers - Ivaylo Donchev, Emilia Todorova
// (IJACSA) International Journal of Advanced Computer Science and Applications, Vol. 6, No. 3, 2015
class BinarySearchTree {
public:
    struct Node {
        int value;
        std::shared_ptr<Node> left, right;

        Node(int value) : value(value) {};
    };

    std::shared_ptr<Node> root;

    void insert(const int &element);

    std::shared_ptr<Node> search(int key);

    explicit BinarySearchTree();

    explicit BinarySearchTree(int value);
};

#endif //DECREASE_AND_CONQUER_H
