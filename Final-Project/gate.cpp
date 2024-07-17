#include "gate.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cmath>

/*
    Data structure which holds a pointers towards Gate structures.
*/
std::vector<Gate*> definedSchemes;

/*
    Deallocates the previous memory allocated in the function handleDefine.
*/
void freeMemory(std::vector<Gate*>& definedSchemes) {
    for (auto& gate : definedSchemes) {
        delete gate;
        gate = nullptr;
    }
    definedSchemes.clear();
    std::cout << "Memory deallocated" << std::endl;
}

/*
    Iterates over the definedSchemes 
    and returns the desired gate with the searched name
    
    Returns nullptr if the desired gate didn't exist.
*/
Gate* findGate(const std::string& gateName) {
    for (auto& gate : definedSchemes) {
        if (gate->gateName == gateName) {
            return gate;
        }
    }
    return nullptr;
}

/*
    Extracts only the letters from a string variable
    returns string as value, but only with letters.
*/
std::string extractLetters(const std::string& value) {
    std::string val;
    for (char letter : value) {
        if (std::isalpha(letter)) { val += letter; }
    }
    return val;
}

/*
    Evaluates if there is a digit in the string parameter
    returns boolean.
*/
bool digitsValidation(std::string value) {
    for (char letter : value) {
        if (std::isdigit(letter)) { return false; }
    }
    return true;
}

/*
    Gives a certain precedence towards bitwise operator.
    returns an integer.
    returns 0 if the operator is not bitwise, such as '(' and ')'
*/
int precedence(char op) {
    if (op == '~') {
        return 3;
    }
    if (op == '&') {
        return 2;
    }
    if (op == '|') {
        return 1;
    }
    return 0;
}

/*
    takes two integer parameters, as well as an bitwise operator.
    returns and integer calculated by the two integer parameters and 
    the bitwise operator

    throws an exception if the operator isn't (&,|)
*/
int applyOp(int a, int b, char op) {
    switch (op) {
    case '&': return a & b;
    case '|': return a | b;
    default: throw std::invalid_argument("Invalid operator");
    }
}

/*
    takes unary operator and an integer as parameter.
    return an integer with the applied unary operator.

    hrows an exception if the operator isn't (~)
*/
int applyUnaryOp(int a, char op) {
    if (op == '~') {
        return ~a;
    }
    throw std::invalid_argument("Invalid unary operator");
}


/*
    Takes string as parameter
    Iterates over the string's length and evaluates the bitwise expressions
    returns integer.
*/
int evaluateExpression(std::string tokens) {
    size_t i;
    std::stack<int> values;
    std::stack<char> ops;

    for (i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ') continue;

        if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }
        else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                if (op == '~') {
                    int val = values.top(); values.pop();
                    values.push(applyUnaryOp(val, op));
                }
                else {
                    int val2 = values.top(); values.pop();
                    int val1 = values.top(); values.pop();
                    values.push(applyOp(val1, val2, op));
                }
            }
            ops.pop();
        }
        else if (tokens[i] == '~' || tokens[i] == '&' || tokens[i] == '|') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                char op = ops.top();
                ops.pop();
                if (op == '~') {
                    int val = values.top(); values.pop();
                    values.push(applyUnaryOp(val, op));
                }
                else {
                    int val2 = values.top(); values.pop();
                    int val1 = values.top(); values.pop();
                    values.push(applyOp(val1, val2, op));
                }
            }
            ops.push(tokens[i]);
        }
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        if (op == '~') {
            int val = values.top(); values.pop();
            values.push(applyUnaryOp(val, op));
        }
        else {
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();
            values.push(applyOp(val1, val2, op));
        }
    }

    return values.top();
}

/*
    Takes string as parameter and vector of struct Gate pointers
    Create a gate based on a regular expression(regex)
    Allocates memory by creating a struct Gate pointer
    The gate pointer is then pushed in the vector<Gate*> structure

    returns void
*/
void handleDefine(const std::string& command, std::vector<Gate*>& definedSchemes) {
    std::regex defineRegex(R"(DEFINE\s+([a-zA-Z0-9_]+)\s*\((.*?)\):\s*\"(.*)\")");
    std::smatch matches;

    if (std::regex_search(command, matches, defineRegex)) {
        if (matches.size() == 4) {
            std::string gateName = matches[1].str();
            std::string definitionPart = matches[2].str();
            std::string expressionPart = matches[3].str();

            Gate* gateFound = findGate(gateName);

            if (gateFound != nullptr) { 
                std::cerr << "Gate with such name already exists !" << std::endl;
                return;
             }

            if (!digitsValidation(definitionPart) || !digitsValidation(expressionPart)) {
                std::cerr << "You cannot define a gate with digits, it is defined with letter parameters!" << std::endl;
                return;
            }

            else if (extractLetters(definitionPart).size() != extractLetters(expressionPart).size()) {
                std::cerr << "Definition and Expression parameters missmatch !" << std::endl;
                return;
            }

            Gate* newGate = new Gate{ gateName, expressionPart };
            definedSchemes.push_back(newGate);

            std::cout << "Successfully created scheme!" << std::endl;
        }
        else {
            std::cerr << "You do not use the right syntax to create gates!" << std::endl;
        }
    }
}

/*
    Takes string as parameter
    Uses regular expression(regex) to evaluate the parameter.
    Extracts the desired Gate pointer and 
    invoke evaluateExpression function over the gate's expression.

    returns void
*/
void handleRun(const std::string& command) {
    std::regex runRegex(R"(RUN\s+([a-zA-Z0-9_]+)\s*\((.*?)\))");
    std::smatch matches;

    if (std::regex_search(command, matches, runRegex)) {
        if (matches.size() == 3) {
            std::string gateName = matches[1].str();
            std::string inputs = matches[2].str();
         
            Gate* gateFound = findGate(gateName);

            if (gateFound == nullptr) {
                std::cerr << "Such gate doesn't exist!" << std::endl;
                return;
            }

            std::string gateValue = gateFound->expressionPart;
            int lettersCount = extractLetters(gateValue).size();

            std::stringstream ss(inputs);
            std::string token;
            std::vector<size_t> inputValues;
            std::regex intRegex(R"(^-?\d+$)");

            while (std::getline(ss, token, ',')) {
                if (std::regex_match(token, intRegex)) {
                    inputValues.push_back(std::stoi(token));
                }
                else {
                    std::cerr << "Invalid input: " << token << " is not a valid integer." << std::endl;
                    return;
                }
            }

            if (inputValues.size() != lettersCount) {
                std::cerr << "The gate exists but it is created with " << lettersCount << " parameters, "
                    << "while you are using " << inputValues.size() << " parameters instead." << std::endl;
                return;
            }

            std::map<char, std::string> letterToValue;
            std::string gateLetters = extractLetters(gateValue);
            for (size_t i = 0; i < gateLetters.size(); ++i) {
                letterToValue[gateLetters[i]] = std::to_string(inputValues[i]);
            }

            std::string result;
            for (char ch : gateValue) {
                if (letterToValue.find(ch) != letterToValue.end()) {
                    result += letterToValue[ch];
                }
                else {
                    result += ch;
                }
            }

            try {
                int evaluatedResult = evaluateExpression(result);
                std::cout << "Evaluated result: " << evaluatedResult << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Error in evaluating expression: " << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "You do not use the right syntax to invoke gates!" << std::endl;
        }
    }
}

/*
    Takes string as parameter.
    Uses regular expression(regex) in order to validate the string parameter.
    Extracts the desired Gate pointer and
    uses evaluateExpression function on the gate's expression
    which prints a matrix on every possible expression scenario

    returns void
*/
void handleAll(const std::string& command) {
    std::regex allRegex(R"(ALL\s+([a-zA-Z0-9_]+))");
    std::smatch matches;

    if (std::regex_search(command, matches, allRegex)) {
        if (matches.size() == 2) {
            std::string gateName = matches[1].str();

           
            Gate* gateFound = findGate(gateName);

            if (gateFound == nullptr) {
                std::cerr << "Such gate doesn't exist!" << std::endl;
                return;
            }

            std::string gateValue = gateFound->expressionPart;
            std::string gateLetters = extractLetters(gateValue);

            int numVariables = gateLetters.size();
            int numCombinations = std::pow(2, numVariables);

            for (char letter : gateLetters) { std::cout << letter << " "; }
            std::cout << " | result" << std::endl;

            for (int i = 0; i < numCombinations; ++i) {
                std::map<char, std::string> letterToValue;
                for (int j = 0; j < numVariables; ++j) {
                    letterToValue[gateLetters[j]] = std::to_string((i >> (numVariables - 1 - j)) & 1);
                    std::cout << ((i >> (numVariables - 1 - j)) & 1);
                    if (j < numVariables - 1) {
                        std::cout << " | ";
                    }
                }

                std::string result;
                for (char ch : gateValue) {
                    if (letterToValue.find(ch) != letterToValue.end()) {
                        result += letterToValue[ch];
                    }
                    else {
                        result += ch;
                    }
                }

                try {
                    int evaluatedResult = evaluateExpression(result);
                    std::cout << " | " << evaluatedResult << std::endl;
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << "Error in evaluating expression: " << e.what() << std::endl;
                }
            }
        }
        else {
            std::cerr << "You do not use the right syntax to list all combinations!" << std::endl;
        }
    }
}