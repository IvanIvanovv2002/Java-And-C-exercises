#include <iostream>
#include <string>
#include <fstream>

void head(const std::string& fileName, int lines) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string currentLine;
        for (int i = 0; i < lines && std::getline(file, currentLine); i++) {
            std::cout << currentLine << std::endl;
        }
        file.close(); 
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}

int main(int argc, char** argv) {

    std::cout << argc << std::endl;

    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " -n <number_of_lines> <filename>" << std::endl;
        return -1;
    }

    int lines = std::stoi(argv[3]);
    std::string filename = argv[4];

    head(filename, lines);

    return 0;
}
