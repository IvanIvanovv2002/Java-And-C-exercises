#include <iostream>

using namespace std;

int main() {

    // Allocating dynamic memory for array and then inserting random numbers on his indexes

    srand(time(NULL));

    int* array;

    int arrayCount;
    cin >> arrayCount;
    array = new int[arrayCount];

    for (size_t i = 0; i < arrayCount; i++)
    {
        array[i] = rand();
    }

    for (size_t i = 0; i < arrayCount; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}