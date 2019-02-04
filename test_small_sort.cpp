#include <algorithm>
#include <chrono>
#include <random>
#include <tuple>
#include <vector>
#include <iostream>
#include <cstdio>
using std::vector;
using namespace std::chrono;

auto bubble(vector<int> v) {
    auto start = high_resolution_clock::now();
    int len = v.size();
    bool swapped = false;
    do {
        swapped = false;
        for (int i = 1; i < len; ++i) {
            if (v[i - 1] > v[i]) {
                std::swap(v[i - 1], v[i]);
                swapped = true;
            }
        }
    } while (swapped);
    auto end = high_resolution_clock::now();
    auto time_span = duration_cast<microseconds>(end - start);

    return std::make_pair(v, time_span.count());
}

auto insert(vector<int> v) {
    auto start = high_resolution_clock::now();
    int len = v.size();
    for (int i = 1; i < len; ++i) {
        int curr = v[i];
        int j = i - 1;
        for (; j >= 0 && v[j] < curr; --j) {
            v[j + 1] = v[j];
        }
        v[j + 1] = curr;
    }
    auto end = high_resolution_clock::now();
    auto time_span = duration_cast<microseconds>(end - start);

    return std::make_pair(v, time_span.count());
}

int main(void) {
    std::mt19937 mt(4219);
    std::uniform_int_distribution<int> dist(0);
    constexpr int test_num = 1000;
    for (int mul = 1; mul <= 10; mul++) {
        int size = 10 * mul;

        double bubble_time = 0.;
        double insert_time = 0.;
        double default_time = 0.;
        for (int j = 0; j < test_num; j++) {
            vector<int> unsort;
            unsort.reserve(size);
            for (int i = 0; i < size; i++) {
                unsort.push_back(dist(mt));
            }

            auto [b1, bt] = bubble(unsort);
            bubble_time += bt;

            auto [i1, it] = insert(unsort);
            insert_time += it;

            auto start = high_resolution_clock::now();
            std::sort(unsort.begin(), unsort.end());
            auto end = high_resolution_clock::now();
            default_time += (duration_cast<microseconds>(end - start)).count();
        }
        printf("size: %d, bubble: %f us, insert: %f us, default: %f us\n", size, bubble_time, insert_time, default_time);
    }
    return 0;
}
