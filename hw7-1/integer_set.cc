#include "integer_set.h"
#include <algorithm>

IntegerSet::IntegerSet() {
    // Do Nothing
}

IntegerSet::~IntegerSet() {
    // Do Nothing
}

void IntegerSet::AddNumber(int num) {
    auto find = std::find(m_numbers.begin(), m_numbers.end(), num);
    if (find == m_numbers.end()) {
        m_numbers.emplace_back(num);
        std::sort(m_numbers.begin(), m_numbers.end());
    }
}

void IntegerSet::DeleteNumber(int num) {
    auto find = std::find(m_numbers.begin(), m_numbers.end(), num);
    if (find != m_numbers.end()) {
        m_numbers.erase(find);
    }
}

int IntegerSet::GetItem(int pos) const {
    if (pos < m_numbers.size()) {
        return m_numbers[pos];
    }
    return -1;
}

std::vector<int> IntegerSet::GetAll() const {
    return m_numbers;
}

