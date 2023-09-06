#include <iostream>
#include <string>

#include "calculator.h"

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::cout << evaluate(line) << std::endl;
    return 0;
}
