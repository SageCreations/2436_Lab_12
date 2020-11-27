#ifndef H_cityType
#define H_cityType

#include <iostream>
#include <string>

class cityType {
public:
//mutators
  void setID(std::string str);
  void setCity(std::string str);
  void setFips(std::string str);
  void setPop(int x);
//accessors
  std::string getID();
  std::string getCity();
  std::string getFips();
  int getPop();
//operators
  bool operator!=(const cityType& a) const;
  bool operator==(const cityType& a) const;
  friend std::ostream& operator<<(std::ostream& os, const cityType& a);

private:
  std::string stateID;
  std::string city;
  std::string fips;
  int         population;
};

#endif
