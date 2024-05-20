
#include <iostream>

/**
 * Fuction which checks if a number is prime or not.
 * Keep in mind that if you do not keep up the values in the range of the integer max, it will overflow.
 * @param val integer to be checked if it is prime or not
 * @return boolean. If the parameter is prime,true will be returned, otherwise false.
 */

bool isPrime(int val) {

    if (2 > val) { 
        return false;
    } 

    for (int i = 2; i < val; i ++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int val;

    while (true) {
        std::cout << "Enter value: ";
        std::cin >> val;

        if (!std::cin.good() || 0 == val) {
            std::cerr << "You have either entered zero or value which is not numeric !" << std::endl;
            std::cerr << "Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            bool result = isPrime(val);
            std::cout << "is " << val << " prime ? " << std::boolalpha << result;
        }
           
           
            return 0;
        }
    }
   
    return 0;
}

