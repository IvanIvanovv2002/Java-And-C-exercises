
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//Testing time complexity on fibonacci sequences with iterative and recursive methods.

long recursiveFibonacci(int number) {
    long result = 1;
    if (number > 2) {
        result = recursiveFibonacci(number - 1) + recursiveFibonacci(number - 2);
    }
    return result;
}

long iterativeFibonacci(int number) {
    if (number <= 2) {
        return 1;
    }

    long fib1 = 1, fib2 = 1, result = 0;

    for (int i = 3; i <= number; ++i) {
        result = fib1 + fib2;
        fib1 = fib2;
        fib2 = result;
    }

    return result;
}


int main() {
    const string recursivePath = "C:\\Users\\PC\\Desktop\\Recursive.txt";
    const string iterativePath = "C:\\Users\\PC\\Desktop\\Iterative.txt";


    ofstream recursiveFile(recursivePath);
    ofstream iterativeFile(iterativePath);

    clock_t t1, t2;
    t1 = clock();
    recursiveFile << "Recursive:" << endl;
    for (int i = 3; i <= 18; i ++) {
        for (int j = 1; j <= 10; j ++) {
            recursiveFibonacci(i);
            t2 = clock();
            double timeNeeded = (t2 - t1) / (double)CLOCKS_PER_SEC;
            recursiveFile << timeNeeded << "(" << i << ")" << " ";
            cout << timeNeeded << " ";
        }
    }
  
    t1 = clock();

    iterativeFile << "Iterative:" << endl;
    for (int i = 3; i <= 18; i++) {
        for (int j = 1; j <= 10; j++) {
            iterativeFibonacci(i);
            t2 = clock();
            double timeNeeded = (t2 - t1) / (double)CLOCKS_PER_SEC;
            iterativeFile << timeNeeded << "(" << i << ")" << " ";
            cout << timeNeeded << " ";

        }
    }

}


