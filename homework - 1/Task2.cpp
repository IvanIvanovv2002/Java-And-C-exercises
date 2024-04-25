#include <iostream>
#include <cmath>

int main() {

    double weight, height, classicBMI, oxfordBMI;

    std::cin >> weight >> height;



    if (std::cin.good() || height <= 0 || weight <= 0) {
        classicBMI = weight / (pow(height, 2));
        oxfordBMI = (1.3 * weight) / pow(height, 2.5);
    }
    else {
        std::cout << "Wrong inputs";
        return -1;
    }

    std::cout << " Classic BMI -  " << classicBMI << std::endl << "Oxford BMI - " << oxfordBMI;

    return 0;
}
