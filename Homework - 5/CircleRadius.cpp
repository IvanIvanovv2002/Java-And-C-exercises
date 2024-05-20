#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

/**
 * Calculates the area of Circle
 * @param radius takes real number as parameter.
 * @return result of Circle's area formula calculation.
 */

double calculateArea(double radius) {
    return PI * (radius * radius);
}

int main() {
    
    double radius, face;

    while (true) {
        std::cout << "Enter radius: ";
        std::cin >> radius;

        if (std::cin.good() && 0 != radius) {
            face = calculateArea(radius);
            std::cout << "Circle's area is: ~ " << face << std::endl;
            return 0;
        } else {
            std::cerr << "You have either not entered numeric value or entered zero instead." << std::endl;
            std::cerr << "Try again!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
    return 0;
}
