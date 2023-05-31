#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <vector>

unsigned long long int fibonacci(int n);

unsigned long long int dynamic_var_fibonacci(int n);

unsigned long long int dynamic_vector_fibonacci(int n);

unsigned long long int fibonacci_matrix(int n);

int change_making(const std::vector<int> &coins, int amount, std::vector<int> &change);

int dynamic_coin_collecting(const std::vector<std::vector<int>> &board, std::vector<std::pair<int, int>> &path);

int coin_collecting(const std::vector<std::vector<int>> &board, std::vector<std::pair<int, int>> &path);

int coin_collecting(const std::vector<std::vector<int>> &board, int i, int j, std::vector<std::vector<int>> &max_coins);

int knapsack(int item_count, int capacity, const std::vector<std::pair<int, int>> &items,
             std::vector<std::vector<int>> &memory);

std::vector<bool> knapsack_solution(int item_count, int capacity, const std::vector<std::pair<int, int>> &items,
                                    std::vector<std::vector<int>> &memory);

#endif //DYNAMIC_PROGRAMMING_H
