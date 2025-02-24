#include <stdio.h>
#include "cache.h"  // Include the cache header

long (*fibonacci_provider)(int);

long fibonacci(int n) {
    printf(__FILE__ ":%2d   fibonacci(%d) called\n", __LINE__, n);

    if (n < 2)
        return n;

    return (*fibonacci_provider)(n - 1) + (*fibonacci_provider)(n - 2);
}

int main() {
    int test_val;

    // Ask the user for input
    printf("Enter a number to calculate Fibonacci: ");
    if (scanf("%d", &test_val) != 1 || test_val < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // PROGRAM INITIALIZATION
    fibonacci_provider = init_cache(fibonacci);

    // PROGRAM FUNCTIONALITY
    for (int ix = test_val; ix >= 0; ix--) {
        printf(__FILE__ ":%2d   Fibonacci of %d is %ld\n", __LINE__, ix, (*fibonacci_provider)(ix));  // Changed %lld to %ld
    }

    return 0;
}