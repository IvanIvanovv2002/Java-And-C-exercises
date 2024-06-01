#include <iostream>
void freeMem(int**arr,int rows) {
    for (size_t i = 0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

void multiplyArr(int**arr1,int**arr2,int**arr3,int rows,int cols) {
    for (size_t i = 0; i < rows; i++){
          arr3[i] = new int[cols];
        for (size_t j = 0; j < cols; j++){
            arr3[i][j] = (arr1[i][j]) * (arr2[i][j]);
        }
    }
    
}

void fillArray(int**arr,int rows,int cols) {
    if (arr == nullptr) { return; }
    for (size_t i = 0; i < rows; i++){
        arr[i] = new int[cols];
        for (size_t j = 0; j < cols; j++){
            int val;
            std::cout << "enter value " << j + 1 << " for row " << i + 1 << " ";
            std::cin >> val;
            arr[i][j] = val;
        }
    }
}

void printArr(int**arr,int rows,int cols) {
    if (arr == nullptr) { return; }
    for (size_t i = 0; i < rows; i++){
        for (size_t j = 0; j < cols; j++){
            std::cout << arr[i][j] << " ";
        } 
        std::cout << std::endl;
    }
}

int main() {
    int rows,cols;
    int**arr1 = nullptr;
    int**arr2 = nullptr;
    int**arr3 = nullptr;
    std::cout << "Enter row: ";
    std::cin >> rows;
    std::cout << "Enter cols: ";
    std::cin >> cols;
    arr1 = new int*[rows];
    arr2 = new int*[rows];
    arr3 = new int*[rows];
    std::cout << "We are filling the first array" << std::endl;
    fillArray(arr1,rows,cols);
    std::cout << "We are filling the second array" << std::endl;
    fillArray(arr2,rows,cols);
    std::cout << "Here is the third array, multiplied" << std::endl;
    multiplyArr(arr1,arr2,arr3,rows,cols);
    printArr(arr3,rows,cols);
    
    freeMem(arr1,rows); 
    freeMem(arr2,rows); 
    freeMem(arr3,rows);
    arr1 = nullptr;
    arr2 = nullptr;
    arr3 = nullptr;

    return 0;
}