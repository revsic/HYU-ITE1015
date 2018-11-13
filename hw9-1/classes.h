#ifndef CLASSES_H
#define CLASSES_H

class A {
public:
    virtual void test() const;
};

class B : public A {
public:
    void test() const override;
};

class C : public B {
public:
    void test() const override;
};

#endif