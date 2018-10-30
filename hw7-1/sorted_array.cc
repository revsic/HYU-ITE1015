#include "sorted_array.h"
#include <algorithm>
#include <numeric>

SortedArray::SortedArray() {
    // Do Nothing
}

SortedArray::~SortedArray() {
    // Do Nothing
}

void SortedArray::AddNumber(int num) {
    m_numbers.emplace_back(num);
}

std::vector<int> SortedArray::GetSortedAscending() const {
    std::vector<int> copied(m_numbers);
    std::sort(copied.begin(), copied.end());
    return copied;
}

std::vector<int> SortedArray::GetSortedDescending() const {
    std::vector<int> copied(m_numbers);
    std::sort(copied.begin(), copied.end(), [](int a, int b) { return a > b; });
    return copied;
}

int SortedArray::GetMax() const {
    if (m_numbers.size() < 1) {
        return -1;
    }
    return std::accumulate(m_numbers.begin(), 
                           m_numbers.end(), 
                           m_numbers[0], 
                           [](int a, int b) { return a > b ? a : b; });
}

int SortedArray::GetMin() const {
    if (m_numbers.size() < 1) {
        return -1;
    }
    return std::accumulate(m_numbers.begin(), 
                           m_numbers.end(), 
                           m_numbers[0],
                           [](int a, int b) { return a < b ? a : b; });
}

