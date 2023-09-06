#include "part-of-set.h"

#include <iostream>
#include <set>
#include <vector>

int main() {
    std::set<int> elements;
    for (int i = 0; i < 5; ++i) {
        int N = 0;
        std::cin >> N;
        elements.insert(N);
    }
    const int border(5);
    std::vector<int> result;
    result = FindGreaterElement(elements, border);
    for (auto r : result) {
        std::cout << r << ' ';
    }
    return 0;
}
