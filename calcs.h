#ifndef KUBIKPOCITA_CALCS_H
#define KUBIKPOCITA_CALCS_H

int getRand(int maxRandNum);

int getResult(int firstNumber, int secondNumber, const std::string &operType);

int evaluateIt(int userResult, int calcResult);

int calculateIt(const std::string &operType, std::vector<std::string> &usedNumbers);

#endif //KUBIKPOCITA_CALCS_H
