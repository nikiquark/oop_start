#include "nearest-element.h"

int main() {
    const std::set <int> st{2, 5, 6, 7, 10, 12};
    std::set<int>::const_iterator a = FindNearestElement(st,1);
    return 0;
}
