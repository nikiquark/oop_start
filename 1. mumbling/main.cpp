#include "accum.h"

#include <iostream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::cout << accum(line) << std::endl;
    return 0;
}
