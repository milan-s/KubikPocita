#ifndef KUBIKPOCITA_IO_H
#define KUBIKPOCITA_IO_H

int getResultNumber();

void writeAnswer(int resultNumber);

std::string getConfirmation(int drillsPassed, int drillsRequired);

std::string getInput(int inputColor);

std::tuple<int, std::string, std::string, std::string, std::string>
changeTestParams(int drillCounts, std::string doAdd, std::string doSub, std::string doMul, std::string doDiv);

#endif //KUBIKPOCITA_IO_H
