#include <iostream>
#include <vector>
#include <tuple>
#include "io.h"
#include "calcs.h"
#include "consoleColor.h"

int main() {
    int drillCounts_ini = 10;
    std::string doAdd_ini = "Ano";
    std::string doSub_ini = "Ano";
    std::string doMul_ini = "Ano";
    std::string doDiv_ini = "Ano";
    int drillCount;
    int drillsPassed = 0;
    int drillsRequired = 0;
    std::vector<std::string> usedNumbers;
    setConsoleColor(consoleColors::base, consoleColors::black);

    std::cout << "#################### \n";
    std::cout << "Ahoj Kubicku, dame se do pocitani \n";
    std::cout << "Zakladni parametry uloh jsou:\n";
    std::cout << "Pocet uloh pro kazdy typ vypoctu: " << drillCounts_ini << "\n";
    std::cout << "Vybrane typy uloh [Scitani, Odecitani, Nasobeni, Deleni]: " << "[" << doAdd_ini << "," << doSub_ini
              << "," << doMul_ini << "," << doDiv_ini << "]" << "\n";
    auto [drillCounts, doAdd, doSub, doMul, doDiv] = changeTestParams(drillCounts_ini, doAdd_ini, doSub_ini, doMul_ini,
                                                                      doDiv_ini);
    drillCount = drillCounts;
    std::cout << "Hodne stesti a jdeme na to!!! \n";

    if (doAdd == "Ano") {
        drillsRequired = drillsRequired + drillCounts;
        std::cout << "#################### \n";
        std::cout << "Scitame!!! \n";
        std::cout << "#################### \n";

        while (drillCount > 0) {
            drillsPassed++;
            drillCount -= calculateIt("+", usedNumbers);
            std::cout << "Zbyva spocitat:" << drillCount << " prikladu.\n";
            std::cout << "#################### \n";
        }

    }

    if (doSub == "Ano") {
        drillsRequired = drillsRequired + drillCounts;
        std::cout << "####################### \n";
        std::cout << "Odecitame!!! \n";
        std::cout << "####################### \n";

        drillCount = drillCounts;
        while (drillCount > 0) {
            drillsPassed++;
            drillCount -= calculateIt("-", usedNumbers);
            std::cout << "Zbyva spocitat:" << drillCount << " prikladu.\n";
            std::cout << "#################### \n";
        }
    }

    if (doMul == "Ano") {
        drillsRequired = drillsRequired + drillCounts;
        std::cout << "####################### \n";
        std::cout << "Nasobime!!! \n";
        std::cout << "####################### \n";

        drillCount = drillCounts;
        while (drillCount > 0) {
            drillsPassed++;
            drillCount -= calculateIt("*", usedNumbers);
            std::cout << "Zbyva spocitat:" << drillCount << " prikladu.\n";
            std::cout << "#################### \n";
        }

    }

    if (doDiv == "Ano") {
        drillsRequired = drillsRequired + drillCounts;
        std::cout << "####################### \n";
        std::cout << "Delime!!! \n";
        std::cout << "####################### \n";

        drillCount = drillCounts;
        while (drillCount > 0) {
            drillsPassed++;
            drillCount -= calculateIt("/", usedNumbers);
            std::cout << "Zbyva spocitat:" << drillCount << " prikladu.\n";
            std::cout << "#################### \n";
        }

    }


    if (getConfirmation(drillsPassed, drillsRequired) == "HOTOVO") {
        return EXIT_SUCCESS;
    }

}
