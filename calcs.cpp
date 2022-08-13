#include <iostream>
#include <random>
#include <vector>
#include <string>
#include "io.h"
#include "calcs.h"
#include "consoleColor.h"

int getRand(int maxRandNum) {
    constexpr int min = 1;
    const int max = maxRandNum;
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased
    auto random_integer = uni(rng);
    return random_integer;

}

int getResult(int firstNumber, int secondNumber, const std::string &operType) {
    if (operType == "+") {
        return firstNumber + secondNumber;
    } else if (operType == "-") {
        return firstNumber - secondNumber;
    } else if (operType == "*") {
        return firstNumber * secondNumber;
    } else if (operType == "/") {
        return firstNumber / secondNumber;
    } else return 0;
}

int evaluateIt(int userResult, int calcResult) {
    if (userResult == calcResult) {
        setConsoleColor(consoleColors::green, consoleColors::black);
        std::cout << "Spravne!!!" << "\n";
        setConsoleColor(consoleColors::base, consoleColors::black);
        //writeAnswer(calcResult);
        return 1;
    } else {
        setConsoleColor(consoleColors::red, consoleColors::black);
        std::cout << "Spatne. Zkus to znovu!" << "\n";
        setConsoleColor(consoleColors::base, consoleColors::black);
        writeAnswer(calcResult);
        return 0;
    }
}

void assignRand(const std::string &operType, int &firstNumber, int &secondNumber) {
    constexpr int maxNum{120};
    int maxRandNum;

    if (operType == "+") {
        maxRandNum = 99;
        firstNumber = getRand(maxRandNum);
        secondNumber = getRand(maxRandNum);

        while (firstNumber + secondNumber > maxNum) {
            firstNumber = getRand(maxRandNum);
            secondNumber = getRand(maxRandNum);
        }
    }

    if (operType == "-") {
        maxRandNum = 120;
        firstNumber = getRand(maxRandNum);
        secondNumber = getRand(maxRandNum);

        if (firstNumber < secondNumber) {
            int dumpNumber = firstNumber;
            firstNumber = secondNumber;
            secondNumber = dumpNumber;
        }
    }

    if (operType == "*") {
        maxRandNum = 20;
        firstNumber = getRand(maxRandNum);
        secondNumber = getRand(maxRandNum);

        while (firstNumber * secondNumber > maxNum) {
            firstNumber = getRand(maxRandNum);
            secondNumber = getRand(maxRandNum);
        }
    }

    if (operType == "/") {
        maxRandNum = 100;
        firstNumber = getRand(maxRandNum);
        secondNumber = getRand(maxRandNum);

        while (firstNumber % secondNumber != 0 || firstNumber < secondNumber || secondNumber == 1 ||
               firstNumber / secondNumber == 1 || secondNumber > 10) {
            firstNumber = getRand(maxRandNum);
            secondNumber = getRand(maxRandNum);
        }
    }

}

int calculateIt(const std::string &operType, std::vector<std::string> &usedNumbers) {

    int valuesUsed = 1;
    int firstNumber{};
    int secondNumber{};
    std::vector<std::string>::iterator usedNumbers_it;

    while (valuesUsed == 1) {
        assignRand(operType, firstNumber, secondNumber);
        usedNumbers_it = std::find(usedNumbers.begin(), usedNumbers.end(),
                                   operType + "." + std::to_string(firstNumber) + "." + std::to_string(secondNumber));
        if (usedNumbers_it == usedNumbers.end()) {
            valuesUsed = 0;
        }
    }

    usedNumbers.push_back(operType + "." + std::to_string(firstNumber) + "." + std::to_string(secondNumber));

    std::cout << "Spocitej " << firstNumber << " " << operType << " " << secondNumber << " = ???\n";
    int inputResult{getResultNumber()};
    int resultNumber = getResult(firstNumber, secondNumber, operType);

    return evaluateIt(inputResult, resultNumber);

}