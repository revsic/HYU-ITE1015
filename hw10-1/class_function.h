#ifndef CLASS_FUNCTION_H
#define CLASS_FUNCTION_H

class A {
public:
    virtual ~A() {}

    virtual void test1() const;
    virtual void test2() const = 0;
};

class B : public A {
public:
    void test2() const override;
};

class C : public B {
public:
    void test1() const override;
    void test2() const override;
};

class BB : public B {
    void test1() const override;
};

#endif