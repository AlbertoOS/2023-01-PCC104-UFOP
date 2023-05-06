#include <stack>
#include <iostream>
#include "03-divide-and-conquer.h"

int max_element(std::vector<int> vector, int left, int right) {
    if (left == right)
        return left;
    int left_max = max_element(vector, left, (left + right) / 2);
    int right_max = max_element(vector, (left + right) / 2 + 1, right);
    if (vector[left_max] >= vector[right_max])
        return left_max;
    else
        return right_max;
}

void merge(std::vector<int> &vector, int left, int mid, int right) {
    int left_size = mid - left + 1, right_size = right - mid;
    std::vector<int> left_vector(left_size), right_vector(right_size);

    for (int i = 0; i < left_size; i++)
        left_vector[i] = vector[left + i];
    for (int j = 0; j < right_size; j++)
        right_vector[j] = vector[mid + 1 + j];

    int left_index = 0;
    int right_index = 0;
    int vector_index = left;

    // Copy elements from aux vectors to main vector, sorting them in the process
    while (left_index < left_size && right_index < right_size) {
        if (left_vector[left_index] <= right_vector[right_index]) {
            vector[vector_index] = left_vector[left_index];
            left_index++;
        } else {
            vector[vector_index] = right_vector[right_index];
            right_index++;
        }
        vector_index++;
    }

    // To reach here, it must exhaust all elements of left or right vector
    // then it copy the remaining elements in the vector not yet exhausted
    while (left_index < left_size) {
        vector[vector_index] = left_vector[left_index];
        left_index++;
        vector_index++;
    }
    while (right_index < right_size) {
        vector[vector_index] = right_vector[right_index];
        right_index++;
        vector_index++;
    }
}

// Iterative with bottom-up
void merge_sort(std::vector<int> &vector) {
    // vector.size() has constant complexity - https://en.cppreference.com/w/cpp/container/vector/size
    // divide the array into blocks of size `sub_size` and merge them, double 'sub_size' on each interaction
    // sub_size = [1, 2, 4, 8, ...]
    for (int sub_size = 1; sub_size <= vector.size() - 1; sub_size *= 2) { // from 1 to n/2
        // for sub_size = 1, left = 0, 2, 4, 6, 8..., right = 1, 3, 5, 7, 9...
        // for sub_size = 2, left = 0, 4, 8..., right = 3, 7, 11...
        // for sub_size = 4, left = 0, 8..., right = 7, 15...
        // ...
        for (int left = 0; left < vector.size() - 1; left += 2 * sub_size) {
            int mid = std::min(left + sub_size - 1, (int) vector.size() - 1);
            int right = std::min(left + 2 * sub_size - 1, (int) vector.size() - 1);
            // Merge "sub-arrays" vector[left...mid] & vector[mid+1...right]
            merge(vector, left, mid, right);
        }
    }
}

int binary_search_tree_size(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node == NULL)
        return 0;
    else
        return 1 + binary_search_tree_size(node->left) + binary_search_tree_size(node->right);
}

void bst_preorder_iterative(std::shared_ptr<BinarySearchTree::Node> root) {
    if (root == nullptr) {
        return;
    }

    std::stack<std::shared_ptr<BinarySearchTree::Node>> preorder_stack;
    preorder_stack.push(root);

    while (!preorder_stack.empty()) {
        std::shared_ptr<BinarySearchTree::Node> node = preorder_stack.top();
        preorder_stack.pop();
        std::cout << node->value << " ";
        if (node->right != nullptr) {
            preorder_stack.push(node->right);
        }
        // Insert left node last on stack to explore it first
        if (node->left != nullptr) {
            preorder_stack.push(node->left);
        }
    }
}

void bst_preorder_recursive(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node != nullptr) {
        std::cout << node->value << " ";
        bst_preorder_recursive(node->left);
        bst_preorder_recursive(node->right);
    }
}

void bst_postorder_iterative(std::shared_ptr<BinarySearchTree::Node> root) {
    std::stack<std::shared_ptr<BinarySearchTree::Node>> traverse_stack, postorder_stack;
    traverse_stack.push(root);

    while (!traverse_stack.empty()) {
        std::shared_ptr<BinarySearchTree::Node> node = traverse_stack.top();
        traverse_stack.pop();
        postorder_stack.push(node);

        if (node->left != nullptr) {
            traverse_stack.push(node->left);
        }
        if (node->right != nullptr) {
            traverse_stack.push(node->right);
        }
    }

    while (!postorder_stack.empty()) {
        std::shared_ptr<BinarySearchTree::Node> node = postorder_stack.top();
        postorder_stack.pop();
        std::cout << node->value << " ";
    }
}


void bst_postorder_recursive(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node != nullptr) {
        bst_postorder_recursive(node->left);
        bst_postorder_recursive(node->right);
        std::cout << node->value << " ";
    }
}

void bst_inorder_iterative(std::shared_ptr<BinarySearchTree::Node> root) {
    std::stack<std::shared_ptr<BinarySearchTree::Node>> inorder_stack;
    std::shared_ptr<BinarySearchTree::Node> node = root;

    while (node != nullptr || !inorder_stack.empty()) {
        // Traverse tree adding left nodes to stack until a leaf is found
        while (node != nullptr) {
            inorder_stack.push(node);
            node = node->left;
        }

        node = inorder_stack.top();
        inorder_stack.pop();
        std::cout << node->value << " ";
        node = node->right;
    }
}

void bst_inorder_recursive(std::shared_ptr<BinarySearchTree::Node> node) {
    if (node != nullptr) {
        bst_inorder_recursive(node->left);
        std::cout << node->value << " ";
        bst_inorder_recursive(node->right);
    }
}
