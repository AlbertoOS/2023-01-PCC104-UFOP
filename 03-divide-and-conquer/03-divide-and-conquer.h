#ifndef DIVIDE_AND_CONQUER_H
#define DIVIDE_AND_CONQUER_H

#include <vector>
#include "../02-decrease-and-conquer/02-decrease-and-conquer.h"

int max_element(std::vector<int> vector, int left, int right);

void merge_sort(std::vector<int> &vector);

int binary_search_tree_size(std::shared_ptr<BinarySearchTree::Node> node);

#endif //DIVIDE_AND_CONQUER_H
