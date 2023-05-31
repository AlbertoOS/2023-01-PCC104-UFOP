#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <vector>

unsigned long long int fibonacci(int n);

unsigned long long int dynamic_var_fibonacci(int n);

unsigned long long int dynamic_vector_fibonacci(int n);

unsigned long long int fibonacci_matrix(int n);

int change_making(const std::vector<int> &coins, int amount, std::vector<int> &change);

#endif //DYNAMIC_PROGRAMMING_H
