#include <iostream>
#include <fstream>
#include <vector>

void tail(const std::string& fileName, int lines) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::vector<std::string> vect;
        std::string currLine;
        
        
        while(std::getline(file, currLine)) {
            vect.push_back(currLine);
        }

        for (int i = 0; i < lines && !vect.empty(); i++) {
          std::string lastElement = vect.back();
          vect.pop_back();
          std::cout << lastElement << std::endl;
        }
        
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <tail> <-n> <number_of_lines> <filePath>" << std::endl;
        return -1;
    }

    int lines = std::stoi(argv[3]);
    std::string filename = argv[4];

    tail(filename, lines);

    return 0;
}
