#include "gtest/gtest.h"

#include <random>
#include <sstream>

#include "calculator.h"

constexpr double EPS = 1e-6;
constexpr size_t NITER = 1000;
constexpr int SEED = 0xDEADBEEF;
std::minstd_rand RNG(SEED);

std::uniform_int_distribution<int> int_dist() {
    return std::uniform_int_distribution<int>{-10000, 10000};
}

std::uniform_real_distribution<double> dbl_dist() {
    return std::uniform_real_distribution<double>{-10000., 10000.};
}

TEST(Arithmetic, TestSingleInt) {
    EXPECT_NEAR(evaluate("101"), 101., EPS);

    auto dist = int_dist();
    for (size_t i = 0; i < NITER; i++) {
        const int n = dist(RNG);
        std::string s = std::to_string(n);
        EXPECT_NEAR(evaluate(s), n, EPS);
    }
}

TEST(Arithmetic, TestSingleFloat) {
    EXPECT_NEAR(evaluate("101.123"), 101.123, EPS);

    auto dist = dbl_dist();
    for (size_t i = 0; i < NITER; ++i) {
        const double x = dist(RNG);
        std::string s = std::to_string(x);
        EXPECT_NEAR(evaluate(s), x, EPS);
    }
}

TEST(Arithmetic, TestSumInt) {
    EXPECT_NEAR(evaluate("( 100 + 1 )"), ( 100. + 1. ), EPS);
    EXPECT_NEAR(evaluate("( ( 49 + 1 ) + 50 )"), ( ( 49. + 1. ) + 50. ), EPS);
    EXPECT_NEAR(evaluate("( 50 + ( 49 + 1 ) )"), ( 50. + ( 49. + 1. ) ), EPS);
    EXPECT_NEAR(evaluate("( ( 49 + 1 ) + ( 50 + 1 ) )"), ( ( 49. + 1. ) + ( 50. + 1. ) ), EPS);

    auto dist = int_dist();
    std::ostringstream oss;
    for (size_t i = 0; i < NITER; ++i) {
        int n0 = dist(RNG);
        int n1 = dist(RNG);
        oss.str("");
        oss << "( " << n0 << " + " << n1 << " )";
        EXPECT_NEAR(evaluate(oss.str()), n0 + n1, EPS);
    }
}

TEST(Arithmetic, TestSumFloat) {
    EXPECT_NEAR(evaluate("( 100.4 + 1.5 )"), ( 100.4 + 1.5 ), EPS);
    EXPECT_NEAR(evaluate("( ( 100.4 + 1.5 ) + 50.2 )"), ( ( 100.4 + 1.5 ) + 50.2 ), EPS);
    EXPECT_NEAR(evaluate("( 50.3 + ( 49.4 + 1.0 ) )"), ( 50.3 + ( 49.4 + 1.0 ) ), EPS);
    EXPECT_NEAR(evaluate("( ( 49.5 + 1 ) + ( 50.6 + 1.1 ) )"), ( ( 49.5 + 1 ) + ( 50.6 + 1.1 ) ), EPS);

    auto dist = dbl_dist();
    std::ostringstream oss;
    oss.precision(12);
    for (size_t i = 0; i < NITER; ++i) {
        double n0 = dist(RNG);
        double n1 = dist(RNG);
        oss.str("");
        oss << "( " << n0 << " + " << n1 << " )";
        EXPECT_NEAR(evaluate(oss.str()), n0 + n1, EPS);
    }
}

TEST(Arithmetic, TestDif) {
    EXPECT_NEAR(evaluate("( 102 - 1 )"), ( 102. - 1. ), EPS);
    EXPECT_NEAR(evaluate("( 1 - 102 )"), ( 1. - 102. ), EPS);
    EXPECT_NEAR(evaluate("( ( 103 - 1 ) - 1 )"), ( ( 103. - 1. ) - 1. ), EPS);
    EXPECT_NEAR(evaluate("( ( 100 + 5 ) + ( 5 - 110 ) )"), ( ( 100. + 5. ) + ( 5. - 110. ) ), EPS);
    EXPECT_NEAR(evaluate("( ( 1.02 - 0.01 ) + 2 )"), ( ( 1.02 - 0.01 ) + 2 ), EPS);

    auto dist = int_dist();
    std::ostringstream oss;
    for (size_t i = 0; i < NITER; ++i) {
        int n0 = dist(RNG);
        int n1 = dist(RNG);
        oss.str("");
        oss << "( " << n0 << " - " << n1 << " )";
        EXPECT_NEAR(evaluate(oss.str()), n0 - n1, EPS);
    }
}

TEST(Arithmetic, TestProd) {
    EXPECT_NEAR(evaluate("( 1 + ( 5 * 20 ) )"), ( 1. + (5. * 20.) ), EPS);

    auto dist = int_dist();
    std::ostringstream oss;
    for (size_t i = 0; i < NITER; ++i) {
        int n0 = dist(RNG);
        int n1 = dist(RNG);
        oss.str("");
        oss << "( " << n0 << " * " << n1 << " )";
        EXPECT_NEAR(evaluate(oss.str()), n0 * n1, EPS);
    }
}

TEST(Arithmetic, TestDiv) {
    EXPECT_NEAR(evaluate("( 20 / 5 )"), ( 20. / 5. ), EPS);

    auto dist = int_dist();
    std::ostringstream oss;
    for (size_t i = 0; i < NITER; ++i) {
        int n0 = dist(RNG);
        int n1 = dist(RNG);
        oss.str("");
        oss << "( " << n0 * n1 << " / " << n0 << " )";
        EXPECT_NEAR(evaluate(oss.str()), n1, EPS);
    }
}

TEST(Arithmetic, TestSqrt) {
    EXPECT_NEAR(evaluate("sqrt ( 36 )"), std::sqrt ( 36. ), EPS);

    auto dist = int_dist();
    std::ostringstream oss;
    for (size_t i = 0; i < NITER; ++i) {
        int n = std::abs(dist(RNG));
        oss.str("");
        oss << "sqrt ( " << n * n << " )";
        EXPECT_NEAR(evaluate(oss.str()), n, EPS);
    }
}

TEST(Arithmetic, TestHard) {
    EXPECT_NEAR(evaluate("( ( ( sqrt ( 36 ) + 10 ) / 8 ) * 1.1 )"), ( ( ( sqrt ( 36 ) + 10) / 8 ) * 1.1 ), EPS);
}

int main(int arc, char **argv) {
    ::testing::InitGoogleTest(&arc, argv);
    return RUN_ALL_TESTS();
}