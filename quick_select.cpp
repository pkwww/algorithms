#include <iostream>
#include <vector>
#include <algorithm>
using std::endl;
using std::cout;
using std::vector;
using std::swap;

namespace quick_select {
    template<typename T>
    int partition(vector<T>& l, int left, int right, int pivot_index) {
        T pivot_value = l.at(pivot_index);
        swap(l.at(right), l.at(pivot_index));
        int num_of_smaller = 0;
        int partition_pos = left;
        for (int i = left; i < right; i++) {
            if (l.at(i) < pivot_value) {
                swap(l.at(i), l.at(partition_pos));
                num_of_smaller++;
                partition_pos++;
            }
        }
        swap(l.at(partition_pos), l.at(right));

        return partition_pos;
    }

    template<typename T>
    T quick_select_help(vector<T>& l, int left, int right, int k) {
        if (left == right) {
            return l.at(left);
        }
        int partition_pos = partition<int>(l, left, right, left);
        if (partition_pos == k) {
            return l.at(k);
        } else if (partition_pos > k) {
            return quick_select_help(l, left, partition_pos, k);
        } else {
            return quick_select_help(l, partition_pos + 1, right, k);
        }
    }

    template<typename T>
    T quick_select(vector<T>& l, int k) {
        return quick_select_help(l, 0, l.size() - 1, k);
    }
}

using namespace quick_select;

int main(void)
{
    vector<int> l = {32, 43, 65, 41, 65, 15, 76, 2};
    auto l_sorted = vector<int>(l);
    std::sort(l_sorted.begin(), l_sorted.end());
    int k = 0;
    int selected_element = quick_select::quick_select(l, k);
    cout << l_sorted[k] << ", " << selected_element << endl;
    return 0;
}
