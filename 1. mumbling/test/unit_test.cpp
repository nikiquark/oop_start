#include "gtest/gtest.h"
#include "accum.h"

TEST(MUMB, Test1) {
    ASSERT_EQ(accum("a"), "A");
}

TEST(MUMB, Test2) {
    ASSERT_EQ(accum("A"), "A");
}

TEST(MUMB, Test3) {
    ASSERT_EQ(accum("abcd"), "A-Bb-Ccc-Dddd");
}

TEST(MUMB, Test4) {
    ASSERT_EQ(accum("RqaEzty"), "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy");
}

TEST(MUMB, Test5) {
    ASSERT_EQ(accum("cwAt"), "C-Ww-Aaa-Tttt");
}

TEST(MUMB, Test6) {
    ASSERT_EQ(accum("INPinp"), "I-Nn-Ppp-Iiii-Nnnnn-Pppppp");
}

TEST(MUMB, Test7) {
    ASSERT_EQ(accum("finishhim"), "F-Ii-Nnn-Iiii-Sssss-Hhhhhh-Hhhhhhh-Iiiiiiii-Mmmmmmmmm");
}

TEST(MUMB, Test8) {
    ASSERT_EQ(accum(""), "");
}


int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
