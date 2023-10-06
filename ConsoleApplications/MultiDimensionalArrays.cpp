

#include <iostream>

int main()
{
    // Calculating a sum of two-dimensional array.

    int rows;
    int cols;

    int count = 1;
    
    std::cin >> rows >> cols;
    int* array = new int[rows * cols];
    for (int i = 0; i < rows; i++)
    {
  
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = count;
            count++;
        }
    }

    for (size_t i = 0; i < rows; i++)
    {

        for (size_t j = 0; i < cols; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
}

