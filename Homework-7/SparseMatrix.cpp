#include <iostream>
#include <cassert>
#include <algorithm>

struct SparseMatrix {
    int* data = nullptr;
    int* offsets = nullptr;
    int sizeData = 0;
    int sizeOffsets = 0;
};

SparseMatrix makeSparse(const int* mat, const int numRows, const int numCols) {
    int* data = new int[numRows * numCols] {0};
    if (data == nullptr) {
        std::cerr << "Can't allocate memory..." << std::endl;
        exit(-1);
    }
    int* offsets = new int[numRows] {0};
    if (offsets == nullptr) {
        delete[] data;
        std::cerr << "Can't allocate memory..." << std::endl;
        exit(-1);
    }

    SparseMatrix sparseMatrix;
    sparseMatrix.data = data;
    sparseMatrix.offsets = offsets;

    int shifting = 0;
    sparseMatrix.sizeOffsets = numRows;

    offsets[0] = 0;

    for (int i = 0; i < numCols; i++) {
        data[i] = mat[i];
    }

    for (int i = 1; i < numRows; ++i) {
        bool isShifted = false;
        do {
            isShifted = false;
            for (int j = 0; j < numCols; ++j) {
                if (mat[i * numCols + j] != 0 && sparseMatrix.data[shifting + j] != 0) {
                    shifting++;
                    isShifted = true;
                    break;
                }
            }
        } while (isShifted);

        offsets[i] = shifting;
        for (int j = 0; j < numCols; ++j) {
            if (mat[i * numCols + j] != 0) {
                data[shifting + j] = mat[i * numCols + j];
                sparseMatrix.sizeData = std::max(sparseMatrix.sizeData, shifting + j + 1);
            }
        }
    }

    return sparseMatrix;
}

int get(const SparseMatrix& sm, const int row, const int col) {
    if (row < sm.sizeOffsets && sm.offsets[row] + col < sm.sizeData) {
        return sm.data[sm.offsets[row] + col];
    } else {
        return -1;
    }
}

void freeSparse(SparseMatrix& sm) {
    delete[] sm.data;
    delete[] sm.offsets;
    sm.data = nullptr;
    sm.offsets = nullptr;
}

int testEasy(const int* mat, const int numRows, const int numCols) {
    SparseMatrix sm = makeSparse(mat, numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            assert(mat[i * numCols + j] == 0 || mat[i * numCols + j] == get(sm, i, j));
        }
    }
    freeSparse(sm);
    return 0;
}


int testHard(const int* mat, const int numRows, const int numCols) {
    SparseMatrix sm = makeSparse(mat, numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (mat[i * numCols + j] != 0 && get(sm, i, j) != 0) {
                assert(mat[i * numCols + j] == get(sm, i, j));
            }
        }
    }
    freeSparse(sm);
    return 0;
}

int main() {
    int matrix1[25] = { 0, 2, 0, 0, 5, 6, 7, 0, 9, 0, 1, 0, 3, 0, 0, 0, 0, 0, 8, 0, 1, 0, 0, 0, 4 };
    int matrix2[25] = { 6, 7, 0, 9, 0, 0, 2, 0, 0, 5, 0, 0, 0, 8, 0, 1, 0, 0, 0, 4, 1, 0, 3, 0, 0, };
    int matrix3[16] = { 4, 0, 0, 5, 0, 1, 0, 0, 0, 0, 0, 3, 0, 2, 0, 0 };
    int matrix4[16] = { 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 3, 4, 0, 0, 5 };

    SparseMatrix sm1 = makeSparse(matrix4, 4, 4);
    SparseMatrix sm2 = makeSparse(matrix3, 4, 4);
    SparseMatrix sm3 = makeSparse(matrix2, 5, 5);
    SparseMatrix sm4 = makeSparse(matrix1, 5, 5);

    for (size_t i = 0; i < sm1.sizeData; i++) {
        std::cout << sm1.data[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < sm2.sizeData; i++) {
        std::cout << sm2.data[i] << " ";
    }
    std::cout << std::endl;


    for (size_t i = 0; i < sm3.sizeData; i++) {
        std::cout << sm3.data[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < sm4.sizeData; i++) {
        std::cout << sm4.data[i] << " ";
    }
    std::cout << std::endl;


    testEasy(matrix1, 5, 5);
    testEasy(matrix2, 5, 5);
    testEasy(matrix3, 4, 4);
    testEasy(matrix4, 4, 4);

    testHard(matrix1, 5, 5);
    testHard(matrix2, 5, 5);
    testHard(matrix3, 4, 4);
    testHard(matrix4, 4, 4);

    return 0;
}
