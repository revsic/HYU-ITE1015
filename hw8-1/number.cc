#include "number.h"
#include <sstream>

void Number::SetNumber(int num) {
    m_num = num;
}

int Number::GetNumber() const {
    return m_num;
}

std::string Number::GetString() const {
    std::stringstream sstream;
    sstream << "GetNumber(): " << GetNumber() << '\n';
    return sstream.str();
}

int Square::GetSquare() const {
    return m_num * m_num;
}

std::string Square::GetString() const {
    std::stringstream sstream;
    sstream << Number::GetString()
            << "GetSquare(): " << GetSquare() << '\n';
    return sstream.str();
}

int Cube::GetCube() const {
    return m_num * m_num * m_num;
}

std::string Cube::GetString() const {
    std::stringstream sstream;
    sstream << Square::GetString()
            << "GetCube(): " << GetCube() << '\n';
    return sstream.str();
}
