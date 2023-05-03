#include "03-divide-and-conquer.h"

int max_element(std::vector<int> vector, int left, int right) {
    if (left == right)
        return left;
    int left_max = max_element(vector, left, (left + right) / 2);
    int right_max = max_element(vector, (left + right) / 2 + 1, right);
    if (vector[left_max] >= vector[right_max])
        return left_max;
    else
        return right_max;
}
