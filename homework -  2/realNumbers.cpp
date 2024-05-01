#include <iostream>
#include <iomanip>
#include <cmath> 

bool normalCompare(double n1, double n2) {
    return n1 == n2;
}

bool fabsCompare(double n1, double n2) {
    const double epsilon = 1e-8;
    return std::fabs(n1 - n2) < epsilon;
}

bool absCompare(double n1, double n2) {
    const double epsilon = 1e-8; 
    return std::abs(n1 - n2) < epsilon;
}

bool isNormal(double n1,double n2) {
    return std::isnormal(n1) && std::isnormal(n2);
}

int main(void) {

    double a = (0.3 * 3) + 0.1;
    double b = 1.0;

    float a2 = (0.3f * 3) + 0.1f;
    float b2 = 1.0f;

     std::cout << std::fixed << std::setprecision(16) << "double datatype: " << a << std::endl;
    std::cout << std::fixed << std::setprecision(16) << "double datatype: " << b<< std::endl;
    
    std::cout << std::fixed << std::setprecision(16) << "float datatype: " << a2<< std::endl;
    std::cout << std::fixed << std::setprecision(16) << "float datatype: " << b2<< std::endl;

    std::cout << std::boolalpha; // Print boolean values as 'true' or 'false', rather than 0 and 1

    std::cout << "double  datatype comparing" << std::endl;

    std::cout << "Result of normalCompare: " << normalCompare(a, b) << std::endl; 
    std::cout << "Result of fabsCompare: " << fabsCompare(a, b) << std::endl;
    std::cout << "Result of absCompare: " << absCompare(a, b) << std::endl;

    std::cout << "float datatype comparing\n******************************" << std::endl;

    std::cout << "Result of normalCompare: " << normalCompare(a2, b2) << std::endl; 
    std::cout << "Result of fabsCompare: " << fabsCompare(a2, b2) << std::endl;
    std::cout << "Result of absCompare: " << absCompare(a2, b2) << std::endl;

    std::cout << "More comparing functions:\n**********************************" << std::endl;

    std::cout << "are values normal ? " << isNormal(0, 0) << std::endl;
    std::cout << "are values normal ? " << isNormal(1.5, 2.5) << std::endl;

    return 0;
}
