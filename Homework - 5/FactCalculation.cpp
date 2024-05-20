

#include <iostream>
#include <cstdint>

/**
 * Calculates the factorial of a given number.
 * If the number is greater than 20, the function returns 0 to avoid overflow.
 * @param fact The number for which the factorial is to be calculated. Must be a non-negative integer.
 * @return The factorial of the given number as a 64-bit unsigned integer. Returns 0 if the number is greater than 20.
 */

 uint64_t calculateFact(uint32_t fact) {

    if (fact > 20) { return 0; }

    uint64_t initial = 1;
    for (int i = 1; i < fact; i++) {
        initial *= i + 1;
    }
    return initial;
}

int main()
{
    uint32_t value;
    uint64_t fact;

    while (1) {
        std::cout << "Enter value: ";
        std::cin >> value;
        if (0 == value || !std::cin.good()) {
            std::cerr << "You have either entered zero or value which is not numeric !" << std::endl;
            std::cerr << "Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            fact = calculateFact(value);
            std::cout << "Factoriel of " << value << " is " << fact;
            return 0;
        }
    }
}
