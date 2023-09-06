#include "gtest/gtest.h"

#include "part-of-set.h"
#include "custom_class.h"

#include <vector>
#include <string>
#include <iostream>

template<typename T>
void RunTest(const std::set<T>& elements, const T& threshold,
             const std::vector<T>& expected_result) {
    auto actual_result = FindGreaterElement(elements, threshold);
    ASSERT_EQ(actual_result, expected_result);
}

TEST(PoS, Simple) {
    RunTest({1, 2, 3, 4, 5, 6}, 5, {6});
}

TEST(PoS, AllFilteredOut) {
    RunTest({1, 2, 3, 4, 5, 6}, 15, {});
}

TEST(PoS, NoFilteredOut) {
    RunTest({5, 6, 10, 12, 30, 41}, 1, {5, 6, 10, 12, 30, 41});
}

TEST(PoS, AtThreshold) {
    RunTest({5}, 5, {});
}

TEST(PoS, AtThresholdLast) {
    RunTest({-10, -9, -8, -7, -6, -5, 0, 1, 2, 3, 4, 5}, 5, {});
}

TEST(PoS, AtThresholdSmallRandom) {
    RunTest({10, 30, 41, 5, 6, 12, -132}, 10, {12, 30, 41});
}

TEST(PoS, Bools) {
    RunTest({true, false}, false, {true});
}

TEST(PoS, Chars) {
    RunTest({'a', 'A', 'b', 'B', 'f'}, 'Z', {'a', 'b', 'f'});
}

TEST(PoS, Strings) {
    RunTest(
        std::set<std::string>{"i", "like", "this", "test", "mooo"}, 
        std::string("moo"), 
        std::vector<std::string>{"mooo", "test", "this"}
    );
}

TEST(PoS, UsersType) {
    RunTest(
        std::set<Height>{{"Robert", 177}, {"Samuel", 189}, {"James", 170}, {"Leo", 183}, {"Johnny", 178}, {"Leo", 183}}, 
        Height{"Joaquin", 173},
        std::vector<Height>{{"Robert", 177}, {"Johnny", 178}, {"Leo", 183}, {"Samuel", 189}}
    );
}

int main(int arc, char **argv) {
    ::testing::InitGoogleTest(&arc, argv);
    return RUN_ALL_TESTS();
}
