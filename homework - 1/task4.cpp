#include <iostream>
#include <fstream>
#include <cfloat>

int main() {
    std::ifstream file("C:\\Users\\PC\\numbers.txt"); 
 
    double max = DBL_MIN;

    if (!file.is_open()) { 
        std::cerr << "Failed to open the file." << std::endl;
        return -1; 
    }

    double num;
    while (file >> num) { 
        if (num > max) { max = num; }
    }

    printf("The biggest value is: %.2f", max);
    
    file.close();

    return 0;
}
