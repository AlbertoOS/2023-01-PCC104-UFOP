#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "01-exhaustive-search/01-exhaustive-search.h"

void print_array(const std::vector<int> &vector) {
    std::cout << "[ ";
    for (int element: vector) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> generate_random_vector(int vector_size, int random_min, int random_max) {
    std::vector<int> vector(vector_size);

    std::random_device random_device;
    std::mt19937 mersenne_engine{random_device()};
    std::uniform_int_distribution<int> dist{random_min, random_max};

    auto gen = [&dist, &mersenne_engine]() { return dist(mersenne_engine); };
    std::generate(begin(vector), end(vector), gen);

    return vector;
}

int main() {
    std::vector<int> vector = generate_random_vector(10, 1, 100);
    std::cout << "Generated random vector: " << std::endl;
    print_array(vector);
    std::cout << std::endl << "Sorting random vector with Selection Sort algorithm: " << std::endl;
    selection_sort(vector);
    print_array(vector);

    std::cout << std::endl << "Searching for element in vector: " << vector[5] << std::endl;
    print_array(vector);
    std::cout << "Sequential search result, element index: " << sequential_search(vector, vector[5]) << std::endl;
    std::cout << std::endl << "Searching for element not in vector: " << 0 << std::endl;
    std::cout << "Sequential search result, should be -1 as it is not found: " << sequential_search(vector, 0) << std::endl;
    return 0;
}
