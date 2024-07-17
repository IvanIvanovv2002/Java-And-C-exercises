#ifndef GATE_H
#define GATE_H

#include <string>
#include <vector>

/*
    Structure which will hold the gate's name and its expression
*/
struct Gate {
    std::string gateName;
    std::string expressionPart;
};

extern std::vector<Gate*> definedSchemes;

Gate* findGate(const std::string& gateName);
std::string extractLetters(const std::string& value);
bool digitsValidation(std::string value);
int evaluateExpression(std::string tokens);
void handleDefine(const std::string& command,std::vector<Gate*>& definedSchemes);
void handleRun(const std::string& command);
void handleAll(const std::string& command);
void freeMemory(std::vector<Gate*>& definedSchemes);

#endif
