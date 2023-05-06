#ifndef DIVIDE_AND_CONQUER_H
#define DIVIDE_AND_CONQUER_H

#include <vector>
#include "../02-decrease-and-conquer/02-decrease-and-conquer.h"

int max_element(std::vector<int> vector, int left, int right);

void merge_sort(std::vector<int> &vector);

int binary_search_tree_size(std::shared_ptr<BinarySearchTree::Node> node);

void bst_preorder_iterative(std::shared_ptr<BinarySearchTree::Node> root);

void bst_preorder_recursive(std::shared_ptr<BinarySearchTree::Node> node);

void bst_postorder_iterative(std::shared_ptr<BinarySearchTree::Node> root);

void bst_postorder_recursive(std::shared_ptr<BinarySearchTree::Node> node);

void bst_inorder_iterative(std::shared_ptr<BinarySearchTree::Node> root);

void bst_inorder_recursive(std::shared_ptr<BinarySearchTree::Node> node);

#endif //DIVIDE_AND_CONQUER_H
