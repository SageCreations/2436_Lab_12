#include <iostream>
#include <string>
#include "cityType.h"

//mutators
void cityType::setID(std::string str) {
  stateID = str;
}

void cityType::setCity(std::string str) {
  city = str;
}

void cityType::setFips(std::string str) {
  fips = str;
}

void cityType::setPop(int x) {
  population = x;
}


//accessors
std::string cityType::getID() {
  return stateID;
}

std::string cityType::getCity() {
  return city;
}

std::string cityType::getFips() {
  return fips;
}

int cityType::getPop() {
  return population;
}

//operators
bool cityType::operator!=(const cityType& a) const {
  return (this->fips != a.fips);
}

bool cityType::operator==(const cityType& a) const {
  return (this->fips == a.fips);
}

std::ostream& operator<<(std::ostream& os, const cityType& a) {
  os << "stateid: " << a.stateID << " // city: " << a.city
     << " // fips: " << a.fips << " // population: " << a.population
     << std::endl;
  return os;
}
