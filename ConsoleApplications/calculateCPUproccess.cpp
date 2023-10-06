#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

//algorthitm for calculating time needed for certain operation.
int main()
{
    clock_t t1, t2;
    double* array = new double[5000000]; // Allocate array on the heap

    t1 = clock();
    for (size_t i = 0; i < 5000000; i++)
    {
        array[i] = sqrt(i);
    }
    t2 = clock();

    double timeNeeded = (t2 - t1) / (double)CLOCKS_PER_SEC;
    printf("%.4f\n", timeNeeded);

    // free the allocated memory
  

    return 0;
}
