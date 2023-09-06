#include "gtest/gtest.h"
#include <random>
#include <algorithm>
#include <fstream>
#include <string>

#include "sqr.h"

void get_temp(std::stringstream& ss, int& temp){
    ss >> temp;
}

void get_temp(std::stringstream& ss, std::pair<int, int>& temp){
    ss >> temp.first >> temp.second;
}

void get_temp(std::stringstream& ss, std::vector<int>& temp){
    int numb;
    while(ss >> numb){
        temp.push_back(numb);
    }
}

template <typename T>
std::vector< T > get_data(const std::string& fname){
    std::vector< T > result;
    std::ifstream ifile("../../test/data/" + fname, std::ios::in);
    if (!ifile.good()) {
        std::cerr << "Can't read " << fname << std::endl;
        return result;
    }
    std::string line;
    while(std::getline(ifile, line, '\n')){
        std::stringstream ss(line);
        T temp;
        get_temp(ss, temp);
        result.push_back(temp);
    }
    return result;
}

TEST(Sqr, Int) {
    const std::string label =  "int";
    std::vector< int > iput = get_data<int>(label+".in");
    std::vector< int > oput = get_data<int>(label+".out");
    for( auto it1=iput.begin(), it2=oput.begin(); it1!=iput.end(); ++it1, ++it2)
        ASSERT_EQ(*it2, Sqr(*it1));
}

TEST(Sqr, Pair) {
    const std::string label = "pair";
    std::vector< std::pair<int, int> > iput = get_data<std::pair<int, int>>(label+".in");
    std::vector< std::pair<int, int> > oput = get_data<std::pair<int, int>>(label+".out");
    for( auto it1=iput.begin(), it2=oput.begin(); it1!=iput.end(); ++it1, ++it2)
        ASSERT_EQ(*it2, Sqr(*it1));
}

TEST(Sqr, VectorInt) {
    const std::string label = "vector";
    std::vector< std::vector<int> > iput = get_data<std::vector<int>>(label+".in");
    std::vector< std::vector<int> > oput = get_data<std::vector<int>>(label+".out");
    for( auto it1=iput.begin(), it2=oput.begin(); it1!=iput.end(); ++it1, ++it2)
        ASSERT_EQ(*it2, Sqr(*it1));
}

TEST(Sqr, VectorOfPairs) {
    const std::string label = "vectorOfPairs";
    std::vector< std::pair<int, int> > iput = get_data<std::pair<int, int>>(label+".in");
    std::vector< std::pair<int, int> > oput = get_data<std::pair<int, int>>(label+".out");
    ASSERT_EQ(oput, Sqr(iput));
}

TEST(Sqr, VectorOfVectors) {
    const std::string label = "vectorOfPairs";
    std::vector< std::vector<int> > iput = get_data<std::vector<int>>(label+".in");
    std::vector< std::vector<int> > oput = get_data<std::vector<int>>(label+".out");
    ASSERT_EQ(oput, Sqr(iput));
}

TEST(Sqr, VectorOfMaps) {
    std::vector<std::map<int, int>> a = {
        {{1, 1}, {2, 4}}, {{3, 2}, {4, 8}, {10, 12}}, {{4, 4}, {4, 4}}};
    std::vector<std::map<int, int>> b = {
        {{1, 1}, {2, 16}}, {{3, 4}, {4, 64}, {10, 144}}, {{4, 16}, {4, 16}}};
    ASSERT_EQ(b, Sqr(a));
}

TEST(Sqr, MapIntInt) {
    std::map<int, int> a = { {1, 1}, {2, 2}, {4, 4}, {6, 6}, {9, 9}, {10, 10} };
    std::map<int, int> b = { {1, 1}, {2, 4}, {4, 16}, {6, 36}, {9, 81}, {10, 100} };
    ASSERT_EQ(b, Sqr(a));
}

TEST(Sqr, MapStringInt) {
    std::map<std::string, int> a = { {"err", -1121}, {"fkjf", 2328}, {"wewe", 42}, {"dfb", 1996}, {"etteg", 13}, {"qwrf", 10} };
    std::map<std::string, int> b = { {"err", 1121*1121}, {"fkjf", 2328*2328}, {"wewe", 42*42}, {"dfb", 1996*1996}, {"etteg", 169}, {"qwrf", 100} };
    ASSERT_EQ(b, Sqr(a));
}

TEST(Sqr, MapStringPair) {
    std::map<std::string, std::pair<int, int>> a = { {"err", {1, 4}}, {"fkjf", {12, 2}} };
    std::map<std::string, std::pair<int, int>> b = { {"err", {1, 16}}, {"fkjf", {144, 4}} };
    ASSERT_EQ(b, Sqr(a));
}

TEST(Sqr, MapPairVector) {
    std::map<std::pair<int, int>, std::vector<int>> a = { {{1, 4}, {1, 2, 3, 4}}, {{1, 3}, {4, 10}} };
    std::map<std::pair<int, int>, std::vector<int>> b = { {{1, 4}, {1, 4, 9, 16}}, {{1, 3}, {16, 100}} };
    ASSERT_EQ(b, Sqr(a));
}

int main(int arc, char **argv) {
    ::testing::InitGoogleTest(&arc, argv);
    return RUN_ALL_TESTS();
}
