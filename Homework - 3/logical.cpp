#include <iostream>

void synthesisByUnits(int a, int b, int c) {
    if ((!a && !b && !c) || 
    (!a && b && !c) || 
    (!a && b && c) || 
    (a && b && c)) {
        std::cout << "by units: true" << std::endl;
    }
}


void synthesisByZeros(int a, int b, int c) {
    if ((!a && !b && c) || 
    (a && !b && !c) || 
    (a && !b && c) || 
    (a && b && !c)) {
        std::cout << "by zeros: true" << std::endl;
    }
}


int main() {

    int a,b,c;
    std::cin >> a >> b >> c;

    synthesisByUnits(a,b,c);
    synthesisByZeros(a,b,c);

    return 0;
}