//
// Created by milan on 09.08.2021.
//

#ifndef CALCS_H
#define CALCS_H

int getRand();
int getResult(int firstNumber, int secondNumber, const std::string& operType);
int evaluateIt(int userResult, int calcResult);
int calculateIt(const std::string& operType, std::vector<std::string>& usedNumbers);

#endif //CALCS_H
