#include "01-exhaustive-search.h"

void selection_sort(std::vector<int> &vector) {
    const int vector_size = (int) vector.size();
    int min_index, tmp;
    for (int i = 0; i < vector_size - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < vector_size; ++j) {
            if (vector[j] < vector[min_index])
                min_index = j;
        }
        if (min_index != i) {
            tmp = vector[min_index];
            vector[min_index] = vector[i];
            vector[i] = tmp;
        }
    }
}

// Based on SequentialSearch2 algorithm presented in section 3.2 of
// Introduction to the Design and Analysis of Algorithms (3rd Edition) - Anany Levitin
int sequential_search(std::vector<int> vector, int key) {
    int n = (int) vector.size();
    vector.push_back(key);
    int i = 0;
    while (vector[i] != key) {
        ++i;
    }
    if (i < n)
        return i;
    else
        return -1;
}

int get_first_element(const std::stack<int> &stack) {
    return stack.top();
}

int get_first_element(const std::queue<int> &queue) {
    return queue.front();
}

std::map<int, std::set<int>> Graph::get_adjacency_list() {
    return adjacency_list;
}

void Graph::add_node(int node) {
    if (adjacency_list.find(node) == adjacency_list.end()) {
        adjacency_list[node] = {};
    }
}

void Graph::add_edge(int node1, int node2) {
    add_node(node1);
    add_node(node2);
    adjacency_list[node1].insert(node2);
    adjacency_list[node2].insert(node1);
}

std::list<int> Graph::valid_path(int src_node, int dst_node, auto frontier) {
    std::list<int> path;
    std::set<int> nodes_visited;
    std::map<int, int> path_parent;
    path_parent[src_node] = -1;
    frontier.push(src_node);
    int current_node;
    while (!frontier.empty()) {
        current_node = get_first_element(frontier);
        frontier.pop();
        if (current_node == dst_node) {
            path.push_front(current_node); // O(1)
            int parent_node = path_parent[current_node];
            while (parent_node != -1) {
                path.push_front(parent_node); // O(1)
                parent_node = path_parent[parent_node];
            }
            return path;
        }
        if (nodes_visited.find(current_node) == nodes_visited.end()) {
            nodes_visited.insert(current_node);
            for (auto &neighbor: adjacency_list[current_node]) {
                if (neighbor != current_node) {
                    if (path_parent.find(neighbor) == path_parent.end())
                        path_parent[neighbor] = current_node;
                    frontier.push(neighbor);
                }
            }
        }
    }
    return path;
}

std::list<int> Graph::valid_path(int src_node, int dst_node, char const *method) {
    if (strcmp(method, "DFS")) {
        std::stack<int> frontier;
        return valid_path(src_node, dst_node, frontier);
    } else if (strcmp(method, "BFS")) {
        std::queue<int> frontier;
        return valid_path(src_node, dst_node, frontier);
    } else {
        return (std::list<int>) {};
    }
}
