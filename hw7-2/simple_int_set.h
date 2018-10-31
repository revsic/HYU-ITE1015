#ifndef SIMPLE_INT_SET
#define SIMPLE_INT_SET

#include <istream>
#include <set>

std::set<int> SetIntersection(const std::set<int>& set0, const std::set<int>& set1);
std::set<int> SetUnion(const std::set<int>& set0, const std::set<int>& set1);
std::set<int> SetDifference(const std::set<int>& set0, const std::set<int>& set1);

bool InputSet(std::istream& input_stream, std::set<int>& s);

#endif
