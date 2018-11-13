#ifndef PRINT_INFO_H
#define PRINT_INFO_H

#include <string>

class A {
public:
    virtual std::string getTypeInfo() const;
};

class B : public A {
public:
    std::string getTypeInfo() const override;
};

class C : public B {
public:
    std::string getTypeInfo() const override;
};

#endif