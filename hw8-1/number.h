#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number {
public:
    void SetNumber(int num);
    int GetNumber() const;

    virtual std::string GetString() const;

protected:
    int m_num;
};

class Square : public Number
{
public:
    int GetSquare() const;

    std::string GetString() const override;
};

class Cube : public Square
{
public:
    int GetCube() const;

    std::string GetString() const override;
};

#endif
