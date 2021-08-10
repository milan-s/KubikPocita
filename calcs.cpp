//
// Created by milan on 09.08.2021.
//

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include "io.h"
#include "calcs.h"

int getRand()
{
    int min = 1;
    int max = 15;
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased
    auto random_integer = uni(rng);
    return random_integer;

}

int getResult(int firstNumber, int secondNumber, const std::string& operType)
{
    if (operType == "+")
    {
        return firstNumber + secondNumber;
    }
    else if (operType == "-")
    {
        return firstNumber - secondNumber;
    }
    else return 0;
}

int evaluateIt(int userResult, int calcResult)
{
    if (userResult == calcResult)
    {
        std::cout << "Spravne!!!" << "\n";
        writeAnswer(calcResult);
        return 1;
    }
    else
    {
        std::cout << "Spatne. Zkus to znovu!" << "\n";
        writeAnswer(calcResult);
        return 0;
    }
}

void assignRand(const std::string& operType, int& firstNumber, int& secondNumber)
{
    firstNumber = getRand();
    secondNumber = getRand();
    if (operType == "-" && firstNumber < secondNumber)
    {
        int dumpNumber = firstNumber;
        firstNumber = secondNumber;
        secondNumber = dumpNumber;
    }
}

int calculateIt(const std::string& operType, std::vector<std::string>& usedNumbers)
{

    int valuesUsed = 1;
    int firstNumber{};
    int secondNumber{};
    std::vector<std::string>::iterator userNumbers_it;

    while(valuesUsed == 1)
    {
        assignRand(operType,firstNumber, secondNumber);
        userNumbers_it = std::find(usedNumbers.begin(), usedNumbers.end(), operType + "." + std::to_string(firstNumber) + "." + std::to_string(secondNumber));
        if (userNumbers_it == usedNumbers.end())
        {
            valuesUsed = 0;
        }
    }

    usedNumbers.push_back(operType + "." + std::to_string(firstNumber) + "." + std::to_string(secondNumber));

    std::cout << "Spocitej " << firstNumber << " " << operType << " " << secondNumber << " = ???\n";
    int inputResult{ getResultNumber() };
    int resultNumber = getResult(firstNumber, secondNumber, operType);

    return evaluateIt(inputResult, resultNumber);

}