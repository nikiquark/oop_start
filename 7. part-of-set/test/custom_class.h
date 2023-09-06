#pragma once
#include <string>
#include <iostream>


class Height {
    std::string full_name;
    int height;
 public:
    Height(const std::string& full_name, const int& height) :
        full_name(full_name), height(height) {}

    friend bool operator==(const Height& left, const Height& right) {
        return left.height==right.height;
    }
    friend bool operator!=(const Height& left, const Height& right) {
        return !(left==right);
    }
    friend bool operator> (const Height& left, const Height& right){
        return left.height>right.height;
    }
    friend bool operator<= (const Height& left, const Height& right){
        return left.height<=right.height;
    }
    friend bool operator< (const Height& left, const Height& right){
        return left.height<right.height;
    }
    friend bool operator>= (const Height& left, const Height& right){
        return left.height>=right.height;
    }
    friend std::ostream& operator<< (std::ostream &out, const Height& right){
        out << right.full_name;
        return out;
    }
};
