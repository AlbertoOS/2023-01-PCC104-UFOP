#include "utils.h"

std::ostream &operator<<(std::ostream &stream, std::pair<int, int> &pair) {
    stream << "(" << pair.first << "," << pair.second << ")";
    return stream;
}

const int log10(const std::pair<int, int> &pair) {
    return (int) std::log10(pair.first) + std::log10(pair.second) + 3;
}

const int log10(const std::string &ah) {
    return 1;
}

static std::random_device random_device;
static std::mt19937 mersenne_engine{random_device()};

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

Graph generate_random_graph(int num_nodes, int num_edges) {
    Graph graph;
    std::uniform_int_distribution<int> dist{1, num_nodes};
    for (int i = 0; i < num_edges; ++i) {
        graph.add_edge(dist(mersenne_engine), dist(mersenne_engine));
    }
    return graph;
}

void print_graph(Graph graph) {
    for (auto const &[node, adjacency_list]: graph.get_adjacency_list()) {
        std::cout << "Node: " << node << ", adjacency_list: ";
        print_container(adjacency_list, false);
    }
}

// Reference - code adapted from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print_binary_search_tree(std::shared_ptr<BinarySearchTree::Node> node, int space) {
    if (node == NULL)
        return;
    int step = 5;
    space += step;

    print_binary_search_tree(node->right, space);
    std::cout << std::endl;
    for (int i = step; i < space; i++)
        std::cout << " ";
    std::cout << node->value << "\n";
    print_binary_search_tree(node->left, space);
}

void print_binary_search_tree(std::shared_ptr<BinarySearchTree::Node> node) {
    std::cout << "~~~Begin Binary Search Tree~~~";
    print_binary_search_tree(node, 0);
    std::cout << "---End Binary Search Tree---" << std::endl;
}
