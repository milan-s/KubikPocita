//
// Created by milan on 09.08.2021.
//

#include <iostream>
#include "io.h"

int getResultNumber()
{
    int numberInput{};
    std::cout << "Napis vysledek:";
    std::cin >> numberInput;
    return numberInput;
}

void writeAnswer(int resultNumber)
{
    std::cout << "Spravny vysledek je:" << resultNumber << "\n";
}

std::string getConfirmation()
{
    std::string okString;
    std::cout << "Jsi hotov!!! Zavolej rodice \n";
    std::cin >> okString;
    return okString;
}