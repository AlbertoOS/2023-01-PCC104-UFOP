#include "01-exhaustive-search.h"

void selection_sort(std::vector<int> &vector) {
    const int vector_size = (int)vector.size();
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
int sequential_search(std::vector<int> vector, int key){
    int n=vector.size();
    vector.push_back(key);
    int i=0;
    while(vector[i] != key){
        ++i;
    }
    if(i<n)
        return i;
    else
        return -1;
}
