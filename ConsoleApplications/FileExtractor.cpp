#include <iostream>
#include <cstdio>
#include <fstream>
#include <string.h>

using namespace std;

int main() {

    // Basic program for extracting negative and positive numbers from File.

    fstream file;
    file.open("C:\\Users\\PC\\Desktop\\Data.txt");

    int positives = 0;
    int negatives = 0;
    if (file.is_open()) {
        double number;
        while (file.good()) {
            file >> number;
            if (number < 0) negatives++;
            else positives++;
        }
        cout << "negatives: " << negatives << endl;
        cout << "positives: " << positives << endl;
    }
    else {
        cout << "error.";
    }


    return 0;
}
