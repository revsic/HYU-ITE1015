#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>

class Animal {
public:
    Animal(std::string&& name, int age);

    virtual void printInfo() const = 0;

    const std::string& GetName() const;
    int GetAge() const;

private:
    std::string m_name;
    int m_age;
};

class Zebra : public Animal {
public:
    Zebra(std::string&& name, int age, int numStripes);

    void printInfo() const override;

private:
    int m_numStripes;
};

class Cat : public Animal {
public:
    Cat(std::string&& name, int age, std::string&& favoriteToy);

    void printInfo() const override;

private:
    std::string m_favoriteToy;
};

#endif