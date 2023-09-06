#include "sortedstrings.h"

#include <vector>
#include <string>
#include <iostream>

int main() {
    SortedString strings;
    const std::vector<std::string> vec {"b", "c", "a"};
    for (const auto& s : vec) strings.AddString(s);
    const auto sorted_strings = strings.GetSortedString();
    for (const auto& s : sorted_strings)
        std::cout << s << ' ';
    std::cout << std::endl;
    return 0;
}
