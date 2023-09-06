#include "gtest/gtest.h"

#include "sortedstrings.h"

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>

using isstrit = std::istream_iterator<std::string>;
const std::string path = "../../test/data/";

std::pair<std::vector<std::string>, std::vector<std::string>>
get_data(int n, int lo, int hi) {
    std::ostringstream oss;
    oss << n << '_' << lo << '_' << hi << ".txt";

    std::ifstream ifile(path + "in_" + oss.str());
    if (!ifile.good()) {
        std::cerr << "File " << path + "in_" + oss.str()
                  << " not found" << std::endl;
        return {{}, {}};
    }
    std::vector<std::string> idata;
    std::copy(isstrit(ifile), isstrit(), std::back_inserter(idata));

    std::ifstream ofile(path + "out_" + oss.str());
    if (!ofile.good()) return {{}, {}};
    std::vector<std::string> odata;
    std::copy(isstrit(ofile), isstrit(), std::back_inserter(odata));

    return {idata, odata};
}

void TestTemplate(const std::vector<std::string>& vec,
                  const std::vector<std::string>& expected_output,
                  double maxsec=2.0) {
    auto start = std::chrono::high_resolution_clock::now();
    SortedString strings;
    std::for_each(vec.begin(), vec.end(),
        [&strings](const std::string& s) {strings.AddString(s);});
    const auto sorted_strings = strings.GetSortedString();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    ASSERT_EQ(sorted_strings, expected_output);
    ASSERT_LE(diff.count(), maxsec);
}

TEST(SortStr, TestABC) {
    const std::vector<std::string> vec {"b", "c", "a"};
    const std::vector<std::string> expected_output {"a", "b", "c"};
    TestTemplate(vec, expected_output);
}

TEST(SortStr, TestAAB) {
    const std::vector<std::string> vec {"b", "a", "a"};
    const std::vector<std::string> expected_output {"a", "a", "b"};
    TestTemplate(vec, expected_output);
}

TEST(SortStr, TestSimple) {
    const std::vector<std::string> vec {"bar", "abac", "aba", "req", "pos"};
    const std::vector<std::string> expected_output {"aba", "abac", "bar", "pos", "req"};
    TestTemplate(vec, expected_output);
}

TEST(SortStr, TestNumbers) {
    const std::vector<std::string> vec {"1", "2", "3", "4", "10", "11", "20"};
    const std::vector<std::string> expected_output {"1", "10", "11", "2", "20", "3", "4"};
    TestTemplate(vec, expected_output);
}

TEST(SortStr, TestSimple2) {
    const std::vector<std::string> vec {"bar", "Bar", "1", "req", "pos"};
    const std::vector<std::string> expected_output {"1", "Bar", "bar", "pos", "req"};
    TestTemplate(vec, expected_output);
}

TEST(SortStr, TestRandom100) {
    auto [idata, odata] = get_data(100, 4, 15);
    TestTemplate(idata, odata);
}

TEST(SortStr, TestRandom1000) {
    auto [idata, odata] = get_data(1000, 4, 15);
    TestTemplate(idata, odata);
}

TEST(SortStr, TestRandom10000) {
    auto [idata, odata] = get_data(10000, 4, 15);
    TestTemplate(idata, odata);
}

TEST(SortStr, TestRandom10000Short) {
    auto [idata, odata] = get_data(10000, 4, 6);
    TestTemplate(idata, odata);
}

TEST(SortStr, TestRandom10000Medium) {
    auto [idata, odata] = get_data(10000, 4, 10);
    TestTemplate(idata, odata);
}

TEST(SortStr, TestRandom100000) {
    auto [idata, odata] = get_data(100000, 4, 6);
    TestTemplate(idata, odata);
}

TEST(SortStr, TestRandom500000) {
    auto [idata, odata] = get_data(500000, 4, 6);
    TestTemplate(idata, odata);
}

int main(int arc, char **argv) {
    ::testing::InitGoogleTest(&arc, argv);
    return RUN_ALL_TESTS();
}
