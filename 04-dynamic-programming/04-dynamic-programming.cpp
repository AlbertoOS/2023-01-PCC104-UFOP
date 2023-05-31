#include <climits>
# include "04-dynamic-programming.h"
# include "../utils.h"

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
