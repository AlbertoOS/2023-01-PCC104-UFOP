#include "02-divide-and-conquer.h"

//Binary Search has the restriction that it can only be used in an ascending sorted array
// decrease-by-a-constant-factor algorithm
int binary_search(std::vector<int> vector, int key) {
    int left = 0, right = vector.size() - 1, middle;
    while (left <= right) {
        middle = (left + right) / 2; //floor since it truncates and rounds down on positive integers
        if (key == vector[middle])
            return middle;
        else if (key < vector[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

//Interpolation Search has the restriction that it can only be used in an ascending sorted array
// variable-size-decrease algorithm - partition-based
// "Unlike binary search, which always compares a search key with the middle value of a given sorted array (and hence reduces the problem’s instance size by half), interpolation search takes into account the value of the search key in order to find the array’s element to be compared with the search key. In a sense, the algorithm mimics the way we search for a name in a telephone book: if we are searching for someone named Brown, we open the book not in the middle but very close to the beginning, unlike our action when searching for someone named, say, Smith" - Introduction to The Design and Analysis of Algorithms, Anany Levitin, p. 161
int interpolation_search(std::vector<int> vector, int key) {
    int left = 0, right = vector.size() - 1;
    // Since vector is sorted, an element present in array must be in range defined by corner elements
    while (left <= right && key >= vector[left] && key <= vector[right]) {
        // If it has compared all the way until left and right indexes met, the value must be here or not in vector at all
        if (left == right) {
            if (vector[left] == key) {
                return left;
            }
            return -1;
        }
        // "More precisely, on the iteration dealing with the array’s portion between the leftmost element A[l] and the rightmost element A[r], the algorithm assumes that the array values increase linearly, i.e., along the straight line through the points (l, A[l]) and (r, A[r])."
        // "(The accuracy of this assumption can influence the algorithm’s efficiency but not its correctness.)" - Introduction to The Design and Analysis of Algorithms, Anany Levitin, p. 162
        int position = left + ((key - vector[left]) * (right - left) / (vector[right] - vector[left]));
        if (vector[position] == key) {
            return position;
        } else if (vector[position] < key) {
            left = position + 1;
        } else {
            right = position - 1;
        }
        /*
         * Example with values, if I'm searching in an array of 10 elements for the number 50 and in first interaction left points to a number 0 and right to a number 100:
         * 0 + ((50 - 0) * (9 - 0) / (100 - 0)) = 0 + (50*9)/100 = 450/100 ~= 4
         * Since the chosen number is halfway between 0 and 100, its position is expected to be halfway across the vector
         * after this, if the search value is not in the expected position, it compares the search value to position value
         * and limits search to left-most or right-most portion/partition of vector.
         */
    }
    return -1;
}
