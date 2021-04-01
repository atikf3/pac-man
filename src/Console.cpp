//
// Created by AMT on 15/03/2021.
//

#include "Console.h"

Console::Console(std::string logNamespace) {
    logns = logNamespace;
}

void Console::print(std::string line) {
    std::cout << "[" << logns << "]: " << line << std::endl;
}