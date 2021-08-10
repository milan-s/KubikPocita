//
// Created by milan on 09.08.2021.
//

#include <iostream>
#include "io.h"
#include "consoleColor.h"


int getResultNumber()
{
    int numberInput{};
    std::cout << "Napis vysledek:";
    setConsoleColor(consoleColors::aqua,consoleColors::black);
    std::cin >> numberInput;
    setConsoleColor(consoleColors::base,consoleColors::black);
    return numberInput;
}

void writeAnswer(int resultNumber)
{
    std::cout << "Spravny vysledek je:" << resultNumber << "\n";
}

std::string getConfirmation()
{
    std::string okString;
    setConsoleColor(consoleColors::green,consoleColors::black);
    std::cout << "Jsi hotov!!! Zavolej rodice \n";
    std::cin >> okString;
    return okString;
}