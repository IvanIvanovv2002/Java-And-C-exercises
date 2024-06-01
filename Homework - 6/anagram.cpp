#include <iostream>
#include <cstring>

const int MAX_SIZE = 1023;

void sort(char* str) {
    int length = strlen(str);

    for (size_t i = 0; i < length; i++){
        for (size_t j = i + 1; j < length; j++){
            if (str[i] > str[j]) {
                char temp = str[j];
                str[j] = str[i];
                str[i] = temp;
            }
        }
    }
}

bool areAnagrams(char* str1,char* str2) {
   int l1 = strlen(str1);
   int l2 = strlen(str2);
   if (l1 != l2) { return false; }

    sort(str1);
    sort(str2);

   for (size_t i = 0; i < l2; i++) {
    if (str1[i] != str2[i]) { return false; }
   }
   return true;
}

int main() {
    char word1[MAX_SIZE];
    char word2[MAX_SIZE];

    std::cout << "Enter the first word: ";
    std::cin.getline(word1,MAX_SIZE);
    std::cout << "Enter the second word: ";
    std::cin.getline(word2,MAX_SIZE);

    if (areAnagrams(word1,word2)) { 
        std::cout << "The words are anagrams" << std::endl; 
        std::cout << "Here are the words sorted: " << word1 << " " << word2;
    } else {
        std::cout << "The words aren't anagrams" << std::endl; 
    }

    return 0;
}
