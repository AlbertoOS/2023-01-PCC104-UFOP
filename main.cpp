#include <vector>
#include <random>
#include <chrono>
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

    std::cout << "Generated random vector: " << std::endl;
    print_container(vector);
    std::cout << std::endl << "Sorting random vector with Merge Sort algorithm: " << std::endl;
    merge_sort(vector);
    print_container(vector);
    std::cout << std::endl << "---------------------" << std::endl;

    vector = generate_random_vector(23, 1, 100);
    std::cout << "Generated random vector: " << std::endl;
    print_container(vector);
    std::cout << std::endl << "Sorting random vector with Quick Sort algorithm: " << std::endl;
    quick_sort(vector);
    print_container(vector);
    std::cout << std::endl << "---------------------" << std::endl;


    BinarySearchTree tree;
    int random_element = generate_random_integer(1, 100);
    tree.insert(random_element);
    print_binary_search_tree(tree.root);
    for (int i = 0; i < 10; ++i) {
        tree.insert(generate_random_integer(1, 100));
        print_binary_search_tree(tree.root);
    }
    std::cout << std::endl << "Binary Search Tree size: " << binary_search_tree_size(tree.root) << std::endl;
    std::cout << std::endl << "---------------------" << std::endl;
    std::cout << std::endl << "Binary Search Tree preorder traversal: " << std::endl;
    bst_preorder_recursive(tree.root); // root-left-right order
    std::cout << std::endl;
    bst_preorder_iterative(tree.root);
    std::cout << std::endl;
    std::cout << std::endl << "---------------------" << std::endl;
    std::cout << std::endl << "Binary Search Tree postorder traversal: " << std::endl;
    bst_postorder_recursive(tree.root); //  left-right-root order
    std::cout << std::endl;
    bst_postorder_iterative(tree.root);
    std::cout << std::endl;
    std::cout << std::endl << "---------------------" << std::endl;
    std::cout << std::endl << "Binary Search Tree inorder traversal: " << std::endl;
    bst_inorder_recursive(tree.root); // left-root-right order - ascending values
    std::cout << std::endl;
    bst_inorder_iterative(tree.root);
    std::cout << std::endl;
    std::cout << std::endl << "---------------------" << std::endl;
}

void call_timed_fibonacci(unsigned long long (*fib)(int), int number) {
    auto t1 = std::chrono::high_resolution_clock::now();
    unsigned long long result = fib(number);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << result << " in " << ms_double.count() << "ms" << std::endl;
}

void list04_dynamic_programming() {
    int random_element = generate_random_integer(93, 93);
    //int random_element = generate_random_integer(4, 93);
    // 47th overflows int
    // 93th overflows long long [int]
    // 94th overflows unsigned long long [int]
    std::cout << std::endl << "Calculating " << random_element << "th fibonacci number:" << std::endl;
    //std::cout << std::endl << "recursively:" << std::endl;
    //call_timed_fibonacci(&fibonacci, random_element);

    std::cout << std::endl << "dynamically with two extra variables:" << std::endl;
    call_timed_fibonacci(&dynamic_var_fibonacci, random_element);

    std::cout << std::endl << "dynamically with vector:" << std::endl;
    call_timed_fibonacci(&dynamic_vector_fibonacci, random_element);

    std::cout << std::endl << "with matrix exponentiation:" << std::endl;
    call_timed_fibonacci(&fibonacci_matrix, random_element);

    std::cout << std::endl << std::endl;
    int random_amount = generate_random_integer(1, 50);
    std::vector<int> coins{1, 2, 5, 10, 25, 50};
    std::vector<int> change;
    int coin_count = change_making(coins, random_amount, change);
    std::cout << std::endl << "Calculating change of value " << random_amount << " with coins: ";
    print_container(coins, false);
    std::cout << std::endl << "The minimum amount of coins is " << coin_count << " and the coins are: " << std::endl;
    print_container(change, false);
}

int main() {
    //list01_exhaustive_search();
    //list02_decrease_and_conquer();
    //list03_divide_and_conquer();
    list04_dynamic_programming();
    return 0;
}
