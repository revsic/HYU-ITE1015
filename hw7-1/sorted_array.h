#ifndef SORTED_ARRAY
#define SORTED_ARRAY

#include <vector>

class SortedArray {
public:
    SortedArray();
    ~SortedArray();

    void AddNumber(int num);

    std::vector<int> GetSortedAscending() const;
    std::vector<int> GetSortedDescending() const;

    int GetMax() const;
    int GetMin() const;

private:
    std::vector<int> m_numbers;
};

#endif
