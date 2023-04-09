#ifndef EXHAUSTIVE_SEARCH_H
#define EXHAUSTIVE_SEARCH_H

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cstring>

void selection_sort(std::vector<int> &vector);

int sequential_search(std::vector<int> vector, int key);

int get_first_element(const std::stack<int> &stack);

int get_first_element(const std::queue<int> &queue);

class Graph {
private:
    std::map<int, std::set<int>> adjacency_list;
public:
    std::map<int, std::set<int>> get_adjacency_list();

    void add_node(int node);

    void add_edge(int node1, int node2);

    std::list<int> valid_path(int src_node, int dst_node, auto frontier);

    std::list<int> valid_path(int src_node, int dst_node, char const *method);
};

#endif //EXHAUSTIVE_SEARCH_H
