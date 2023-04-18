#include "02-divide-and-conquer.h"

//Binary Search has the restriction that it can only be used in a sorted array
int binary_search(std::vector<int> vector, int key) {
    int left=0, right=vector.size()-1, middle;
    while(left <= right){
        middle = (left+right)/2; //floor
        if (key == vector[middle])
            return middle;
        else if(key < vector[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}
