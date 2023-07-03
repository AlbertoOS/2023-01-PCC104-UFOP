#ifndef PCC104_UFOP_UTILS_H
#define PCC104_UFOP_UTILS_H

#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "01-exhaustive-search/01-exhaustive-search.h"
#include "02-decrease-and-conquer/02-decrease-and-conquer.h"
#include "03-divide-and-conquer/03-divide-and-conquer.h"
#include "04-dynamic-programming/04-dynamic-programming.h"
#include "06-backtracking-algorithms/06-backtracking-algorithms.h"

std::ostream &operator<<(std::ostream &stream, std::pair<int, int> &pair);

const int log10(const std::pair<int, int> &pair);

const int log10(const std::string &ah);

const auto print_container = [](const auto &container, bool print_index = true) {
    std::cout << "[ ";
    for (auto element: container) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;

    if (print_index) {
        std::cout << "i ";
        int i = 0;
        for (auto element: container) {
            std::cout << std::setfill(' ') << std::setw(log10(element) + 1) << i << " ";
            ++i;
        }
        std::cout << std::endl;
    }
};

const auto print_ordered_container = [](auto container) {
    std::cout << "[ ";
    while (!container.empty()) {
        auto element = get_first_element(container);
        std::cout << element << " ";
        container.pop();
    }
    std::cout << "]" << std::endl;
};

std::vector<int> generate_random_vector(int vector_size, int random_min, int random_max);

int generate_random_integer(int random_min, int random_max);

Graph generate_random_graph(int num_nodes, int num_edges);

void print_graph(Graph graph);

void print_binary_search_tree(std::shared_ptr<BinarySearchTree::Node> node, int space);

void print_binary_search_tree(std::shared_ptr<BinarySearchTree::Node> node);

void print_sudoku_board(int sudoku_board[sudoku_size][sudoku_size]);

#endif //PCC104_UFOP_UTILS_H
