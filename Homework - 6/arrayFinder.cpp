#include <iostream>

void fillArray(int*arr,int length) {
    if (arr == nullptr) { return; }
    for (size_t i = 0; i < length; i++) {
        int val;
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> val;
        arr[i] = val;
    }
    
}

int main() {
    int bestNum = 0,bestCnt = 0;
    int*arr = nullptr;
    int length;

    std::cout << "Enter length for the array: ";
    std::cin >> length;

    if (length <= 1) {
        std::cerr << "Array should have atleast two values.";
        return -1;
    }

    arr = new int[length];

    fillArray(arr,length);

    for (size_t i = 0; i < length; i++) {
        int currentCnt = 0;
        for (size_t j = 0; j < length; j++){
            if (arr[i] == arr[j]) { currentCnt++; }
        }
        if(currentCnt > bestCnt) { 
            bestCnt = currentCnt; 
            bestNum = arr[i];
        }
    }

    if (bestCnt >= (length / 2) + 1) {
        std::cout << "The value " << bestNum << " contains itself " << 
        bestCnt << " times in the array out of " << length << " elements.";
    } else {
        std::cout << "There are no repeated items found in the array";
    }
    

    delete[] arr;
    return 0;
}