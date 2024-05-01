#include <iostream>
#include <fstream>
#include <sstream>

void wc(std::string& fileName) {
    std::ifstream file(fileName);
    int lines = 0;
    int words = 0;
    int characters = 0;
    if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        lines++;
        characters += line.length();

        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            words++;
        }
    } 
  } else {
     std::cerr << "Unable to open the file";
     return;
  }
  std::cout << "lines - " << lines << std::endl;
  std::cout << "words - " << words << std::endl;
  std::cout << "characters - " << characters << std::endl;

}

int main(int argc,char** argv) {
    if (argc != 3) {
        std::cerr << "The command is " << argv[0] << " <wc> <filename>";
        return -1;
    }
    std::string fileName = argv[2];
    wc(fileName);
}