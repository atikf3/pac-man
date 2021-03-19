//
// Created by AMT on 15/03/2021.
//

#pragma once
#include <string>
#include <iostream>

class Console {
private:
    std::string logns;

public:
    Console(std::string logNamespace);
    void print(std::string line);
};

