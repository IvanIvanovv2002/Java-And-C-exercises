 #include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct TruthTableRow {
    std::vector<int> inputs;
    int output;
};

std::vector<TruthTableRow> readTruthTableFromStdin() {
    std::vector<TruthTableRow> table;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        std::istringstream iss(line);
        TruthTableRow row;
        std::string part;
        while (std::getline(iss, part, ':')) {
            std::istringstream partStream(part);
            int bit;
            while (partStream >> bit) {
                row.inputs.push_back(bit);
                if (partStream.peek() == ',') {
                    partStream.ignore();
                }
            }
        }
        row.output = row.inputs.back();
        row.inputs.pop_back();
        table.push_back(row);
    }
    return table;
}

std::string generateDNF(const std::vector<TruthTableRow>& table) {
    std::string dnf;
    for (const auto& row : table) {
        if (row.output == 1) {
            if (!dnf.empty()) {
                dnf += " | ";
            }
            dnf += "(";
            for (size_t i = 0; i < row.inputs.size(); ++i) {
                if (i > 0) {
                    dnf += " & ";
                }
                if (row.inputs[i] == 0) {
                    dnf += "!";
                }
                dnf += char(i + 97);
            }
            dnf += ")";
        }
    }
    return dnf;
}


int main() {
    std::cout << "The syntax is value,value,value:result;" << std::endl;
    std::cout << "End the program by typing empty line." << std::endl;

    std::vector<TruthTableRow> table = readTruthTableFromStdin();
    std::string dnf = generateDNF(table);
    std::cout << "Result: " << dnf << std::endl;
    return 0;
} 