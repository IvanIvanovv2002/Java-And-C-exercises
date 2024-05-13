#include <iostream>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <limits>

bool validNumber(int num) {
    return 0 <= num && 63 >= num;
}

void setBit(uint64_t& attendance,int student) {
    if (!validNumber(student)) {
        std::cerr << "Student number must be between 0 and 63 !";
        return;
    }
     attendance |= (1ULL << student);
}

void clearBit(uint64_t& attendance,int student) {
    if (!validNumber(student)) {
        std::cerr << "Student number must be between 0 and 63 !";
        return;
    }
    attendance &= ~(1ULL << student);
}

void flipBit(uint64_t& attendance,int student) {
    if (!validNumber(student)) {
        std::cerr << "Student number must be between 0 and 63 !";
        return;
    }
    attendance ^= (1ULL << student);
}

bool readBit(uint64_t& attendance,int student) {
    if (!validNumber(student)) {
        std::cerr << "Student number must be between 0 and 63 !";
    }
    return attendance & (1ULL << student);
}

void searchAttendedStudents(uint64_t& attendance) {
    for (int i = 0; i < 64; i ++) {
        if (readBit(attendance,i)) {
            std::cout << "Student " << i + 1 << "is here !" << std::endl;
        }
    }
}

void searchMissingStudents(uint64_t& attendance) {
    for (int i = 0; i < 64; i ++) {
        if (!readBit(attendance,i)) {
            std::cout << "Student " << i + 1 << " isn't there !" << std::endl;
        }
    }
}


int main(void) {
    uint64_t attendance = 0;
    int option;

    std::cout << "1: Set attendance" << std::endl;
    std::cout << "2: Clear attendance" << std::endl;
    std::cout << "3: Attending students" << std::endl;
    std::cout << "4: Absent students" << std::endl;
    std::cout << "5: Change attendance status" << std::endl;
    std::cout << "6: Exit" << std::endl;

    while (1) {
        int studentNumber;
        std::cin >> option;
    
        switch (option) {
        case 1:
            std::cin >> studentNumber;
            if (std::cin.fail()) {
                std::cerr << "You need to enter a number" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }
            setBit(attendance,studentNumber);
            std::cout << std::bitset<8 * sizeof(attendance)>(attendance) << std::endl ;
            break;
        case 2:
            std::cin >> studentNumber;
            if (std::cin.fail()) {
                std::cerr << "You need to enter a number" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }
            clearBit(attendance,studentNumber);
            std::cout << std::bitset<8 * sizeof(attendance)>(attendance) << std::endl; 
            break;
        case 3:
            searchAttendedStudents(attendance);
            break;
        case 4:
            searchMissingStudents(attendance);
            break;
        case 5:
            std::cin >> studentNumber;
            if (std::cin.fail()) {
                std::cerr << "You need to enter a number" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }
            flipBit(attendance,studentNumber);
            std::cout << std::bitset<8 * sizeof(attendance)>(attendance) << std::endl; 
            break;
        case 6:
            std::cout << "End of program." << std::endl;
            return 0;
        default:
            std::cerr << "The options for numbers are 1-6, do it again." << std::endl;
        }
    }
    return 0;
}
