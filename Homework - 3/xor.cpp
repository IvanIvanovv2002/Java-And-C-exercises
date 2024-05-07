#include <iostream>
#include <fstream>

int main(void) {
    std::ifstream file("/home/ivan/Homework - 3/numbers.txt");

    int a,b;

    if (file.is_open()) {
        file >> a >> b;
        if ( (!a && b) || (a && !b) ) {
            std::cout << "1" << std::endl;
        } else {
            std::cout << "0" << std::endl;
        }
    } else {
        std::cerr << "File isn't opened." << std::endl;
    }

    return 0;
}
