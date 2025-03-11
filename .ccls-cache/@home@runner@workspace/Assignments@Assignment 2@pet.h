#ifndef PET_H
#define PET_H

#include <string>

class Pet
{
public:
    Pet(std::string nm, int initialHealth);  // Constructor
    void eat(int amt);  // Method to feed the pet
    void play();  // Method for playing
    std::string name() const;  // Method to get pet's name
    int health() const;  // Method to get pet's health
    bool alive() const;  // Method to check if pet is alive

private:
    std::string m_name;
    int m_health;
};

#endif  // PET_H
