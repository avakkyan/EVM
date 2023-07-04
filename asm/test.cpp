extern "C" {
#include "sort.h"
}
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

bool isEquals(const std::vector<int>& v1, const std::vector<int>& v2)
{
    if (v1.size() != v2.size()) {
        return false;
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

extern "C" void test()
{
    std::vector<int> test_data(1000);
    std::vector<int> max_vals(10);
    size_t iterCount = 1000;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> range(0, 10000);
    for (size_t i = 0; i < iterCount; ++i) {
        for (size_t j = 0; j < test_data.size(); ++j) {
            test_data[j] = range(rng);
        }
        sort(test_data.data(), test_data.size());
        _ASSERT(std::is_sorted(test_data.begin(), test_data.end()));
        findMax10(test_data.data(), test_data.size(), max_vals.data());
        std::reverse(max_vals.begin(), max_vals.end());
        _ASSERT(isEquals(max_vals, std::vector<int>(test_data.end() - 10, test_data.end())));
    }
}
