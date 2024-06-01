#include <iostream>
#include <stdint.h>

void mergeSort(int* arr1, int* arr2, int* &mergeArr, uint32_t size1, uint32_t size2) {
    uint32_t i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergeArr[k++] = arr1[i++];
        } else {
            mergeArr[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        mergeArr[k++] = arr1[i++];
    }

    while (j < size2) {
        mergeArr[k++] = arr2[j++];
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortArray(int* arr, int low, int high) {
    if(arr == nullptr) return;

    if (low < high) {
       
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++; 
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        int pi = i + 1; 

        sortArray(arr, low, pi - 1);
        sortArray(arr, pi + 1, high);
    }
}

void printArr(int* arr, uint32_t length) {
    if (arr == nullptr) return;
    for (size_t i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void fillArray(uint32_t size, int*& arr) {
    for (size_t i = 0; i < size; i++) {
        int val;
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> val;
        arr[i] = val;
    }
}


bool validate(uint32_t size) {
    if (size < 1) { return false; }
    return true;
}

int main() {
    uint32_t length1, length2;
    int* arr1 = nullptr;
    int* arr2 = nullptr;
    int* mergeArr = nullptr;

    std::cout << "Enter length1 for array 1: ";
    std::cin >> length1;

    if (!validate(length1)) {
        std::cerr << "You are trying to create an array with a size of 0." << std::endl;
        return -1;
    }

    arr1 = new int[length1];
    fillArray(length1, arr1);
    

    std::cout << "Enter length2 for array 2: ";
    std::cin >> length2;

    if (!validate(length2)) {
        std::cerr << "You are trying to create an array with a size of 0." << std::endl;
        return -1;
    }

    arr2= new int[length2]; 
    fillArray(length2, arr2);
   
    sortArray(arr1, 0, length1 - 1);

    sortArray(arr2, 0, length2 - 1);

    mergeArr = new int[length1 + length2];
    mergeSort(arr1,arr2,mergeArr,length1,length2);
    std::cout << "Here is the merged array:" << std::endl;
    printArr(mergeArr, length1 + length2);

    delete[] arr1; 
    delete[] arr2;
    delete[] mergeArr;
    arr1 = nullptr;
    arr2 = nullptr;
    mergeArr = nullptr;

    return 0;
}
