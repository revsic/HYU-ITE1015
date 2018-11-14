#include "Animals.h"
#include <iostream>

Animal::Animal(std::string&& name, int age) : 
    m_name(std::move(name)), m_age(age) 
{
    // Do Nothing
}

const std::string& Animal::GetName() const {
    return m_name;
}

int Animal::GetAge() const {
    return m_age;
}

Zebra::Zebra(std::string&& name, int age, int numStripes) :
    Animal(std::move(name), age), m_numStripes(numStripes)
{
    // Do Nothing
}

void Zebra::printInfo() const {
    std::cout << "Zebra, Name: " << GetName() 
              << ", Age: " << GetAge() 
              << ", Number of stripes: " << m_numStripes 
              << std::endl;
}

Cat::Cat(std::string&& name, int age, std::string&& favoriteToy) :
    Animal(std::move(name), age), m_favoriteToy(std::move(favoriteToy))
{
    // Do Nothing
}

void Cat::printInfo() const {
    std::cout << "Cat, Name: " << GetName()
              << ", Age: " << GetAge()
              << ", Favorite toy: " << m_favoriteToy
              << std::endl;
}