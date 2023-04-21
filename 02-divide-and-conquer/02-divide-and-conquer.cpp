#include "02-divide-and-conquer.h"

//Binary Search has the restriction that it can only be used in an ascending sorted array
// decrease-by-a-constant-factor algorithm
int binary_search(std::vector<int> vector, int key) {
    int left = 0, right = vector.size() - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2; //floor since it truncates and rounds down on positive integers
        if (key == vector[middle])
            return middle;
        else if (key < vector[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

//Interpolation Search has the restriction that it can only be used in an ascending sorted array
// variable-size-decrease algorithm - partition-based
int interpolation_search(std::vector<int> vector, int key) {
    int left = 0, right = vector.size() - 1;
    // Since vector is sorted, an element present in array must be in range defined by corner elements
    while (left <= right && key >= vector[left] && key <= vector[right]) {
        // If it has compared all the way until left and right indexes met, the value must be here or not in vector at all
        if (left == right) {
            if (vector[left] == key) {
                return left;
            }
            return -1;
        }
        int position = left + ((key - vector[left]) * (right - left) / (vector[right] - vector[left]));
        if (vector[position] == key) {
            return position;
        } else if (vector[position] < key) {
            left = position + 1;
        } else {
            right = position - 1;
        }
    }
    return -1;
}

void BinarySearchTree::insert(const int &element) {
    if (!root) {
        root = std::make_shared<Node>(element);
        return;
    }

    std::shared_ptr<Node> current_node = root;
    std::shared_ptr<Node> next_node = current_node;
    while (next_node != nullptr) {
        current_node = next_node;
        if (element < current_node->value) {
            next_node = current_node->left;
        } else if (element > current_node->value) {
            next_node = current_node->right;
        } else {
            return; // don't duplicate elements
        }
    } // while loop breaks when it has found a leaf node that should receive a new child node
    if (element < current_node->value) {
        current_node->left = std::make_shared<Node>(element);
    } else if (element > current_node->value) {
        current_node->right = std::make_shared<Node>(element);
    }
    return;
}

std::shared_ptr<BinarySearchTree::Node> BinarySearchTree::search(int key) {
    std::shared_ptr<BinarySearchTree::Node> current_node = root;
    while (current_node != nullptr) {
        if (key == current_node->value) {
            return current_node;
        } else if (key < current_node->value) {
            current_node = current_node->left;
        } else if (key > current_node->value) {
            current_node = current_node->right;
        }
    }
    return nullptr;
}

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
    left = nullptr;
    right = nullptr;
}

BinarySearchTree::BinarySearchTree(int value) : value(value) {
    root = std::make_shared<Node>(value);
    left = nullptr;
    right = nullptr;
}
