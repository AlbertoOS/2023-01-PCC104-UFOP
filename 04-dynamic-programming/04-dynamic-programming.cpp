#include <vector>
# include "04-dynamic-programming.h"

unsigned long long int fibonacci(int n) {
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

unsigned long long int dynamic_fibonacci(int n) {
    std::vector<unsigned long long int> memory(n + 1, 0);
    memory[0] = 0;
    memory[1] = 1;
    for (int i = 2; i <= n; i++) {
        memory[i] = memory[i - 1] + memory[i - 2];
    }
    return memory[n];
}
