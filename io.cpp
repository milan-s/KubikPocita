#include <iostream>
#include <string>
#include <math.h>
#include "io.h"
#include "consoleColor.h"
#include <exception>
#include <tuple>

std::string getInput(int inputColor = consoleColors::white) {
    std::string buffer;
    setConsoleColor(inputColor, consoleColors::black);
    std::getline(std::cin, buffer);
    setConsoleColor();
    return buffer;
}

int getResultNumber() {
    int numberInput;
    std::string buffer;
    std::cout << "Napis vysledek:";
    buffer = getInput(consoleColors::aqua);
    try {
        numberInput = std::stoi(buffer);
    } catch (std::exception &e) {
        setConsoleColor(consoleColors::red, consoleColors::black);
        std::cout << "Zapsana hodnota neni cislo\n" << e.what() << std::endl;
        setConsoleColor();
        return -1;
    }
    return numberInput;
}

void writeAnswer(int resultNumber) {
    std::cout << "Spravny vysledek je:" << resultNumber << "\n";
}

std::string getConfirmation(int drillsPassed, int drillsRequired) {
    std::string okString;
    double successRate = ceil(double(drillsRequired) / double(drillsPassed) * 100);
    setConsoleColor(consoleColors::green, consoleColors::black);
    std::cout << "Jsi hotov!!! \nGratuluji!!! \nPocet pozadovanych uloh: " << drillsRequired << "\nPocet pokusu: "
              << drillsPassed << "\nUspesnost: " << successRate << "%\n\nZavolej rodice! \n";
    std::cin >> okString;
    return okString;
}


std::tuple<int, std::string, std::string, std::string, std::string>
changeTestParams(int drillCounts, std::string doAdd, std::string doSub, std::string doMul, std::string doDiv) {

    std::string decisionValue;
    std::string buffer;

    std::cout << "Chces zmenit parametry? (Ano, Ne (default)):";
    decisionValue = getInput(consoleColors::yellow);
    if (!buffer.empty()) { decisionValue = "Ne"; }

    if (decisionValue == "Ano") {
        std::cout << "Zadej nove parametry!!!\n";
        std::cout << "Pocet uloh (default = " << drillCounts << "):" << std::endl;
        buffer = getInput(consoleColors::yellow);
        if (!buffer.empty()) { drillCounts = std::stoi(buffer); }
        std::cout << "Scitani (Ano (default), Ne):" << std::endl;
        buffer = getInput(consoleColors::yellow);
        if (!buffer.empty()) { if (buffer != "Ano") { doAdd = "Ne"; } else { doAdd = buffer; }}
        std::cout << "Odecitani (Ano (default), Ne):" << std::endl;
        buffer = getInput(consoleColors::yellow);
        if (!buffer.empty()) { if (buffer != "Ano") { doSub = "Ne"; } else { doSub = buffer; }}
        std::cout << "Nasobeni (Ano (default), Ne):" << std::endl;
        buffer = getInput(consoleColors::yellow);
        if (!buffer.empty()) { if (buffer != "Ano") { doMul = "Ne"; } else { doMul = buffer; }}
        std::cout << "Deleni (Ano (default), Ne):" << std::endl;
        buffer = getInput(consoleColors::yellow);
        if (!buffer.empty()) { if (buffer != "Ano") { doDiv = "Ne"; } else { doDiv = buffer; }}
        std::cout << "#################### \n";
        std::cout << "Nove parametry uloh jsou:\n";
        std::cout << "Pocet uloh pro kazdy typ vypoctu: " << drillCounts << "\n";
        std::cout << "Vybrane typy uloh [Scitani, Odecitani, Nasobeni, Deleni]: " << "[" << doAdd << "," << doSub << ","
                  << doMul << "," << doDiv << "]" << "\n";
        std::cout << "#################### \n";
    }

    return std::make_tuple(drillCounts, doAdd, doSub, doMul, doDiv);

}