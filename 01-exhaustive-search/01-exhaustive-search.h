#ifndef EXHAUSTIVE_SEARCH_H
#define EXHAUSTIVE_SEARCH_H

#include <vector>
#include <map>
#include <set>

void selection_sort(std::vector<int> &vector);

int sequential_search(std::vector<int> vector, int key);

class Graph {
private:
    std::map<int, std::set<int>> adjacency_list;
public:
    std::map<int, std::set<int>> get_adjacency_list();

    void add_node(int node);

    void add_edge(int node1, int node2);
};

#endif //EXHAUSTIVE_SEARCH_H
