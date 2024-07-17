#include "gate.h"
#include <iostream>

#define exampleAND "DEFINE ic1(a,b,c, d): \"a & b & c & d\""
#define exampleOR "DEFINE ic2(a,b,c, d): \"a | b | c | d\""
#define exampleNOT "DEFINE ic3(a): \"~a\""
#define exampleNAND "DEFINE ic4(a,b): \"~(a & b)\""
#define exampleNOR "DEFINE ic5(a,b): \"~(a | b)\""

int main() {

    std::cout << "Permitted functions are DEFINE,RUN AND ALL" << std::endl;
    std::cout << "Syntax for DEFINE: DEFINE name(params): 'expression'" << std::endl;
    std::cout << "Syntax for RUN: RUN name(params)" << std::endl;
    std::cout << "Syntax for ALL: ALL name" << std::endl;
    std::cout << "Abort the program by typing EXIT" << std::endl;

    std::cout << std::endl;

    std::string command;

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command.find("DEFINE") == 0) {
            handleDefine(command, definedSchemes); 
        }
        else if (command.find("RUN") == 0) {
            handleRun(command);
        }
        else if (command.find("ALL") == 0) {
            handleAll(command);
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cerr << "Unknown command." << std::endl;
        }
    }

    freeMemory(definedSchemes);
    return 0;
}
