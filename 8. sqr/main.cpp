#include "sqr.h"

#include <vector>
#include <utility>
#include <map>
#include <iostream>

int main() {

    const int a = 1;
    int asqr = Sqr(a);
    std::cout << "Squared int:\n" << asqr << std::endl;

    const double b = 1.;
    double bsqr = Sqr(b);
    std::cout << "Squared double:\n" << bsqr << std::endl;

    const std::vector<int> v {1, 2, 3, 4};
    auto vsqr = Sqr(v);
    std::cout << "Squared vector:\n";
    for (auto i : vsqr)
        std::cout << i << '\t';
    std::cout << std::endl;

    const auto p = std::make_pair(1.5, 6.);
    auto psqr = Sqr(p);
    std::cout << "Squared pair:\n" << psqr.first << '\t' << psqr.second << std::endl;

    const std::map<std::string, double> m = {{"a", 1.}, {"b", 2.}, {"c", 3.}};
    auto msqr = Sqr(m);
    std::cout << "Squared map:\n";
    for (auto i : msqr)
        std::cout << i.first << ":" << i.second << '\t';
    std::cout << std::endl;

    return 0;
}