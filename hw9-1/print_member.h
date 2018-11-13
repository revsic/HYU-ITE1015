#ifndef PRINT_MEMBER_H
#define PRINT_MEMBER_H

#include <string>

class A {
public:
    A(int n);
    virtual ~A();

    virtual void print() const;

private:
    int* memberA;
};

class B : public A {
public:
    B(double n);
    ~B();

    void print() const override;

private:
    double* memberB;
};

class C : public B {
public:
    C(std::string&& str);
    ~C();

    void print() const override;

private:
    std::string* memberC;
};

#endif