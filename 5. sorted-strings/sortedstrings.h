#pragma once

#include <vector>
#include <string>
#include <map>

class SortedString {
 public:
    void AddString(const std::string& s);
    std::vector<std::string> GetSortedString() const;
};
