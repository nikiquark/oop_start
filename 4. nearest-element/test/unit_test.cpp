#include "gtest/gtest.h"
#include "nearest-element.h"

#include <set>

TEST(NearestEl, Simple) {
    const std::set <int> st{2, 5, 6, 7, 10, 12};
    ASSERT_EQ(*FindNearestElement(st, 1), 2);
    ASSERT_EQ(*FindNearestElement(st, 2), 2);
    ASSERT_EQ(*FindNearestElement(st, 3), 2);
    ASSERT_EQ(*FindNearestElement(st, 4), 5);
    ASSERT_EQ(*FindNearestElement(st, 5), 5);
    ASSERT_EQ(*FindNearestElement(st, 11), 10);
    ASSERT_EQ(*FindNearestElement(st, 18), 12);
}

int main(int arc, char **argv) {
    ::testing::InitGoogleTest(&arc, argv);
    return RUN_ALL_TESTS();
}
