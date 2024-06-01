#include <iostream>

void rotateArr(int** arr, int rows, int cols) {
    if (arr == nullptr) { return; }

    int** rotatedArr = new int*[cols];
    for (int i = 0; i < cols; i++) {
        rotatedArr[i] = new int[rows];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotatedArr[j][rows - 1 - i] = arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rotatedArr[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        delete[] rotatedArr[i];
    }
    delete[] rotatedArr;
}

void printArr(int** arr, int rows, int cols) {
    if (arr == nullptr) { return; }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows, cols;

    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter cols: ";
    std::cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter value: " << j + 1 << " for row " << i + 1 << ": ";
            std::cin >> arr[i][j];
        }
    }

    std::cout << "Original array:" << std::endl;
    printArr(arr, rows, cols);

    rotateArr(arr, rows, cols);

    std::cout << "Rotated array:" << std::endl;
    printArr(arr, rows, cols);

    for (int i = 0; i < rows; i++) {
        arr[i] = nullptr;
        delete[] arr[i];
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
