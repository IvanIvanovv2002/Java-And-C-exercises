#include <iostream>
#include <string>

/**
 * Fuction which checks if an integer is palindrome
 * Keep in mind that if you do not keep the value in the integer max range, it will overflow.
 * @param x integer to be checked if it is palindrome
 * @return boolean. True, if the value is palindrome, otherwise false 
 */

bool isPalindrome(int x) {
  
    if (x <= 0) {
        return false;
    } else if (x <= 9) { return true; }

    std::string str = std::to_string(x);
    int n = str.length();

    for (int i = 1; i < n ; ++i) {
        
        if (str[i-1] != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;

    while (1) {
        std::cout << "Enter value: ";
        std::cin >> num;

        if (!std::cin.good()) {
            std::cerr << "You have entered value which is not numeric !" << std::endl;
            std::cerr << "Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (isPalindrome(num)) {
            std::cout << num << " is palindrome." << std::endl;
        } else {
            std::cout << num << " isn't palindrome" << std::endl;
        }
        break;
    }

   

    return 0;
}
