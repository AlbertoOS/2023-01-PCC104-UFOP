#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "01-exhaustive-search/01-exhaustive-search.h"

static std::random_device random_device;
static std::mt19937 mersenne_engine{random_device()};

auto print_container = [](const auto &container) {
    std::cout << "[ ";
    for (int element: container) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
};

std::vector<int> generate_random_vector(int vector_size, int random_min, int random_max) {
    std::vector<int> vector(vector_size);
    std::uniform_int_distribution<int> dist{random_min, random_max};

    auto gen = [&dist]() { return dist(mersenne_engine); };
    std::generate(begin(vector), end(vector), gen);

    return vector;
}

int generate_random_integer(int random_min, int random_max) {
    std::uniform_int_distribution<int> dist{random_min, random_max};
    return dist(mersenne_engine);
}

int main() {
    std::vector<int> vector = generate_random_vector(10, 1, 100);
    std::cout << "Generated random vector: " << std::endl;
    print_container(vector);
    std::cout << std::endl << "Sorting random vector with Selection Sort algorithm: " << std::endl;
    selection_sort(vector);
    print_container(vector);

    int random_element = vector[generate_random_integer(0, vector.size() - 1)];
    std::cout << std::endl << "Searching for random element in vector: " << random_element << std::endl;
    print_container(vector);
    std::cout << "Sequential search result, element index: " << sequential_search(vector, random_element) << std::endl;
    std::cout << std::endl << "Searching for element not in vector: " << 0 << std::endl;
    std::cout << "Sequential search result, should be -1 as it is not found: " << sequential_search(vector, 0)
              << std::endl << std::endl;

    return 0;
}
