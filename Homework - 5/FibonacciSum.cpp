#include <iostream>
#include <cstdint>
#include <vector>
#include <stdexcept> // For std::runtime_error

/**
 * Calculates N-th value of Fibonacci's sequence
 * @param uint32_t value which the function will use for calculating the sequence
 * @param vector<uint64_t> a datastructure which helps with the time complexity (memoization) during recursion
 * @return result of Fibonacci's sequence calculation as uint64_t.
 */

uint64_t fibonacci(uint32_t value, std::vector<uint64_t>& memo) {
    if (94 <= value) {
        throw std::runtime_error("With value equal to or above 94, it will overflow.");
    }

    if (memo[value] != UINT64_MAX) {
        return memo[value];
    }

    if (value <= 1) {
        memo[value] = value;
    }
    else {
        memo[value] = fibonacci(value - 1, memo) + fibonacci(value - 2, memo);
    }
    return memo[value];
}

int main() {
    uint32_t value;
    std::cout << "Enter value: ";
    std::cin >> value;

    std::vector<uint64_t> memo(value + 1, UINT64_MAX);

    try {
        uint64_t result = fibonacci(value, memo);
        std::cout << value << "th value of Fibonacci is " << result << std::endl;
    }
    catch (const std::runtime_error& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
    }

    return 0;
}
