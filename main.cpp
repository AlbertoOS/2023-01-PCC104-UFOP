#include <vector>
#include <random>
#include "utils.h"

void list01_exhaustive_search() {
    std::vector<int> vector = generate_random_vector(10, 1, 100);
    std::cout << "Generated random vector: " << std::endl;
    print_container(vector);
    std::cout << std::endl << "Sorting random vector with Selection Sort algorithm: " << std::endl;
    selection_sort(vector);
    print_container(vector);
    std::cout << std::endl << "---------------------" << std::endl;

    int random_element = vector[generate_random_integer(0, (int) vector.size() - 1)];
    std::cout << std::endl << "Searching for random element in vector: " << random_element << std::endl;
    print_container(vector);
    std::cout << "Sequential search result, element index: " << sequential_search(vector, random_element) << std::endl
              << std::endl << "Searching for element not in vector: " << 0 << std::endl
              << "Sequential search result, should be -1 as it is not found: " << sequential_search(vector, 0)
              << std::endl << "---------------------" << std::endl;

    int num_nodes = 13;
    Graph graph = generate_random_graph(num_nodes, 2 * num_nodes);
    std::cout << std::endl << "Generated random graph: " << std::endl;
    print_graph(graph);

    std::cout << std::endl;
    int src_node = generate_random_integer(1, num_nodes);
    int dst_node = generate_random_integer(1, num_nodes);
    std::cout << "Trying to find a valid path between Node " << src_node << " and Node " << dst_node << std::endl;
    std::cout << "Path found using Depth First Search: ";
    print_container(graph.valid_path(src_node, dst_node, "DFS"), false);
    std::cout << "Path found using Breadth First Search: ";
    print_container(graph.valid_path(src_node, dst_node, "BFS"), false);
    std::cout << std::endl << "---------------------" << std::endl;
}

void list02_decrease_and_conquer() {
    std::vector<int> vector = generate_random_vector(23, 1, 100);
    std::sort(vector.begin(), vector.end()); // O(n*log n) - Introsort (quicksort + heapsort + insertion sort)

    int random_element = vector[generate_random_integer(0, (int) vector.size() - 1)];
    std::cout << std::endl << "Searching for random element in vector: " << random_element << std::endl;
    std::cout << "Using ascending sorted random vector for binary search: " << std::endl;
    print_container(vector);
    std::cout << "Binary search result, element index: " << binary_search(vector, random_element) << std::endl
              << std::endl << "Searching for element not in vector: " << 0 << std::endl
              << "Binary search result, should be -1 as it is not found: " << binary_search(vector, 0)
              << std::endl << "---------------------" << std::endl;

    random_element = vector[generate_random_integer(0, (int) vector.size() - 1)];
    std::cout << std::endl << "Searching for random element in vector: " << random_element << std::endl;
    std::cout << "Using ascending sorted random vector for interpolation search: " << std::endl;
    print_container(vector);
    std::cout << "Interpolation search result, element index: " << interpolation_search(vector, random_element)
              << std::endl
              << std::endl << "Searching for element not in vector: " << 0 << std::endl
              << "Interpolation search result, should be -1 as it is not found: " << interpolation_search(vector, 0)
              << std::endl << "---------------------" << std::endl;

    BinarySearchTree tree;
    random_element = generate_random_integer(1, 100);
    tree.insert(random_element);
    print_binary_search_tree(tree.root);
    for (int i = 0; i < 10; ++i) {
        int insert_element = generate_random_integer(1, 100);
        tree.insert(insert_element);
        if (!generate_random_integer(0, 6)) { //~14%
            random_element = insert_element;
        }
        print_binary_search_tree(tree.root);
    }
    std::shared_ptr<BinarySearchTree::Node> node;
    std::cout << std::endl << "Searching for element not in tree: " << -1 << std::endl;
    node = tree.search(-1);
    if (node == nullptr) {
        std::cout << "Node returned null pointer, as expected" << std::endl;
    }
    std::cout << std::endl << "Searching for random element in tree: " << random_element << std::endl;
    node = tree.search(random_element);
    if (node != nullptr) {
        std::cout << "Node returned, Value: " << node->value << std::endl;
        if (node->left) {
            std::cout << "Left child: " << node->left->value << std::endl;
        }
        if (node->right) {
            std::cout << "Right child: " << node->right->value << std::endl;
        }
    }

}

void list03_divide_and_conquer() {
    std::vector<int> vector = generate_random_vector(23, 1, 100);

    std::cout << std::endl << "Using random vector to find max element: " << std::endl;
    print_container(vector);
    std::cout << "Max element result, element index: " << max_element(vector, 0, vector.size() - 1)
              << ", element value: " << vector[max_element(vector, 0, vector.size() - 1)] << std::endl
              << std::endl << "---------------------" << std::endl;
}

int main() {
    //list01_exhaustive_search();
    //list02_decrease_and_conquer();
    list03_divide_and_conquer();
    return 0;
}
