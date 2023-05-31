#include "04-dynamic-programming.h"
#include <climits>
#include "../utils.h"

unsigned long long int fibonacci(int n) {
    if (n <= 1) { return n; }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long long int dynamic_var_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    unsigned long long int previous = 0, current = 1;
    for (int i = 2; i <= n; i++) {
        unsigned long long int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

/*
 * Note that we can, in fact, avoid using an extra array to accomplish this task by recording the values
 * of just the last two elements of the Fibonacci sequence (Problem 8 in Exercises 2.5).
 * This phenomenon is not unusual, and we shall encounter it in a few more examples in this chapter.
 * Thus, although a straightforward application of dynamic programming can be interpreted as a special variety of
 * space-for-time trade-off, a dynamic programming algorithm can sometimes be refined to avoid using extra space.
 */
unsigned long long int dynamic_vector_fibonacci(int n) {
    std::vector<unsigned long long int> memory(n + 1, 0);
    memory[0] = 0;
    memory[1] = 1;
    for (int i = 2; i <= n; i++) {
        memory[i] = memory[i - 1] + memory[i - 2];
    }
    return memory[n];
}

void multiply(unsigned long long int F[2][2], unsigned long long int M[2][2]) {
    unsigned long long int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    unsigned long long int b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    unsigned long long int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    unsigned long long int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}

void power(unsigned long long int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    unsigned long long int M[2][2] = {{1, 1},
                                      {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

unsigned long long int fibonacci_matrix(int n) {
    unsigned long long int F[2][2] = {{1, 1},
                                      {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

int change_making(const std::vector<int> &coins, int amount, std::vector<int> &change) {
    std::vector<int> min_coins(amount + 1, 0);
    min_coins[0] = 0;
    std::vector<int> last_coin_used(amount + 1, -1); // for solution backtracking

    for (int i = 1; i <= amount; i++) {
        min_coins[i] = INT_MAX;
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                int min_coin = min_coins[i - coins[j]];
                if (min_coin != INT_MAX && min_coin + 1 < min_coins[i]) {
                    min_coins[i] = min_coin + 1;
                    last_coin_used[i] = j;
                }
            }
        }
        print_container(min_coins, false);
    }

    int remaining_amount = amount;
    while (remaining_amount > 0) {
        int coin_index = last_coin_used[remaining_amount];
        change.push_back(coins[coin_index]);
        remaining_amount -= coins[coin_index];
    }

    return min_coins[amount];
}

std::vector<std::pair<int, int>> coin_collecting_backtrack(const std::vector<std::vector<int>> &max_coins) {
    std::vector<std::pair<int, int>> path;
    // Backtrack to find the solution path
    int i = max_coins.size() - 1, j = max_coins[0].size() - 1;
    while (i > 0 || j > 0) {
        path.push_back({i, j});
        if (i == 0) {
            j--; // if first row, only left movement possible
        } else if (j == 0) {
            i--; // if first column, only up movement possible
        } else {
            if (max_coins[i - 1][j] > max_coins[i][j - 1]) {
                i--; // if up movement is better, move up
            } else {
                j--; // if left movement is better, move left
            }
        }
    }
    path.push_back({0, 0});
    std::reverse(path.begin(), path.end());
    return path;
}

int dynamic_coin_collecting(const std::vector<std::vector<int>> &board, std::vector<std::pair<int, int>> &path) {
    int n = board.size();
    int m = board[0].size();
    std::vector<std::vector<int>> max_coins(n, std::vector<int>(m, 0));
    max_coins[0][0] = board[0][0];

    for (int j = 1; j < m; j++) {
        max_coins[0][j] = board[0][j] + max_coins[0][j - 1];
    }
    for (int i = 1; i < n; i++) {
        max_coins[i][0] = board[i][0] + max_coins[i - 1][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            max_coins[i][j] = board[i][j] + std::max(max_coins[i - 1][j], max_coins[i][j - 1]);
        }
    }
    path = coin_collecting_backtrack(max_coins);
    return max_coins[n - 1][m - 1];
}

int coin_collecting(const std::vector<std::vector<int>> &board, std::vector<std::pair<int, int>> &path) {
    int n = board.size();
    int m = board[0].size();
    std::vector<std::vector<int>> max_coins(n, std::vector<int>(m, 0));
    max_coins[0][0] = board[0][0];
    int result = coin_collecting(board, n - 1, m - 1, max_coins);
    path = coin_collecting_backtrack(max_coins);
    return result;
}

int
coin_collecting(const std::vector<std::vector<int>> &board, int i, int j, std::vector<std::vector<int>> &max_coins) {
    if (i < 0 || j < 0) {
        return 0;
    } else if (i == 0 && j == 0) {
        return board[i][j];
    }

    int max_coin = board[i][j] + std::max(
            coin_collecting(board, i - 1, j, max_coins), coin_collecting(board, i, j - 1, max_coins));
    max_coins[i][j] = max_coin;

    return max_coin;
}

int knapsack(int item_count, int capacity, const std::vector<std::pair<int, int>> &items,
             std::vector<std::vector<int>> &memory) {

    if (memory[item_count][capacity] != -1)
        return memory[item_count][capacity];
    if (item_count == 0 || capacity == 0)
        return 0;

    if (items[item_count - 1].first > capacity) {
        // item's weight is heavier than capacity, cannot fit
        //knapsack_solution[item_count - 1] = false;
        memory[item_count][capacity] = knapsack(item_count - 1, capacity, items, memory);
    } else {
        // item's weight is lighter than capacity, will fit
        int value_included = items[item_count - 1].second +
                             knapsack(item_count - 1, capacity - items[item_count - 1].first, items, memory);
        int value_excluded = knapsack(item_count - 1, capacity, items, memory);

        if (value_included > value_excluded) {
            //knapsack_solution[item_count - 1] = true;
            memory[item_count][capacity] = value_included;
        } else {
            //knapsack_solution[item_count - 1] = false;
            memory[item_count][capacity] = value_excluded;
        }
//        memory[item_count][capacity] = std::max(
//                items[item_count - 1].second +
//                knapsack(item_count - 1, capacity - items[item_count - 1].first, items, memory, knapsack_solution),
//                knapsack(item_count - 1, capacity, items, memory, knapsack_solution));
    }

    return memory[item_count][capacity];
}

std::vector<bool> knapsack_solution(int item_count, int capacity, const std::vector<std::pair<int, int>> &items,
                                    std::vector<std::vector<int>> &memory) {
    std::vector<bool> solution(items.size(), false);
    int result = memory[item_count][capacity];
    int weight = capacity;
    for (int i = item_count; i > 0 && result > 0; i--) {
        if (result == memory[i - 1][weight])
            continue; // this means result is same without item (i-1), so it is not included
        else {
            solution[i - 1] = true;
            result = result - items[i - 1].second;
            weight = weight - items[i - 1].first;
        }
    }
    return solution;
}
