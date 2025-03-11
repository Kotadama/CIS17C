#include "pet.h" // Include the class header

Pet::Pet(std::string nm, int initialHealth) {
  m_name = nm;
  m_health = initialHealth;
}

void Pet::eat(int amt) {
  m_health += amt; // Increase health when fed
}

void Pet::play() {
  if (m_health > 0)
    m_health -= 1; // Decrease health when playing (if pet is alive)
}

std::string Pet::name() const {
  return m_name; // Return pet's name
}

int Pet::health() const {
  return m_health; // Return pet's health
}

bool Pet::alive() const {
  return m_health > 0; // Return true if pet is alive (health > 0)
}
