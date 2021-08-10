//
// Created by milan on 09.08.2021.
//

#include <iostream>
#include <vector>
#include "io.h"
#include "calcs.h"
#include "consoleColor.h"

int main()
{
    int drillCounts = 10;
    int drillCount = drillCounts;
    std::vector<std::string> usedNumbers;
    setConsoleColor(consoleColors::base,consoleColors::black);

    std::cout << "#################### \n";
    std::cout << "Ahoj Kubicku, dneska budes pocitat " << drillCounts << " prikladu pro scitani a odecitani \n";
    std::cout << "Hodne stesti a jdeme na to!!! \n";
    std::cout << "#################### \n";
    std::cout << "Zacneme se scitanim! \n";
    std::cout << "#################### \n";

    while (drillCount > 0)
    {
        drillCount -= calculateIt("+",usedNumbers);
        std::cout << "Zbyva spocitat:" << drillCount << " prikladu.\n";
        std::cout << "#################### \n";
    }

    std::cout << "####################### \n";
    std::cout << "Pokracujeme odecitanim! \n";
    std::cout << "####################### \n";

    drillCount = drillCounts;
    while (drillCount > 0)
    {
        drillCount -= calculateIt("-",usedNumbers);
        std::cout << "Zbyva spocitat:" << drillCount << " prikladu.\n";
        std::cout << "#################### \n";
    }

    if (getConfirmation() == "HOTOVO")
    {
        return EXIT_SUCCESS;
    }

}
