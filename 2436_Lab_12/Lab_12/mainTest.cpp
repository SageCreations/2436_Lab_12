#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "hashT.h"
#include "cityType.h"

class CSVRow {
   public:
//  std::string_view operator[](std::size_t index) const {
    std::string operator[](std::size_t index) const {
//      return std::string_view(&m_line[m_data[index] + 1], m_data[index + 1]
//        - (m_data[index] + 1));
        return std::string(&m_line[m_data[index] + 1], m_data[index + 1]
          - (m_data[index] + 1));
    }
    std::size_t size() const {
        return m_data.size() - 1;
    }
    void readNextRow(std::istream& str) {
        std::getline(str, m_line);

        m_data.clear();
        m_data.emplace_back(-1);
        std::string::size_type pos = 0;
        while ((pos = m_line.find(',', pos)) != std::string::npos) {
            m_data.emplace_back(pos);
            ++pos;
        }
        // This checks for a trailing comma with no data after it.
        pos = m_line.size();
        m_data.emplace_back(pos);
    }

   private:
    std::string m_line;
    std::vector<int> m_data;
};

std::istream& operator>>(std::istream& str, CSVRow& data);
int hashFunc(string name);
void menu();

//***************** Begining of main ************************
int main() {
  std::ifstream file("500Cities.csv");

  std::cout << file.fail() << std::endl;

  CSVRow row;
  hashT<cityType> hashTable(1009);
  cityType places[500];

  int index = 0;
  while (file >> row) {
      places[index].setID(row[0]);
      //std::cout << "stateid: " << places[index].getID() << std::endl;
      places[index].setCity(row[1]);
      //std::cout << "placename: " << places[index].getCity() << std::endl;
      places[index].setFips(row[2]);
      //std::cout << "fips: " << places[index].getFips() << std::endl;
      places[index].setPop(std::stoi(row[3]));
      //std::cout << "population: " << places[index].getPop() << std::endl;
      index++;
  }

  for (int i = 0; i < 500; i++) {
    int key;
    key = hashFunc(places[i].getFips());

    hashTable.insert(key, places[i]);
  }

  int input = 0;
  bool found = false;
  std::string userFips;
  int key = 0;
  do {
    menu();
    std::cin  >> input;
    switch (input) {
      case 1:
        std::cout << "Please enter a vailid fips number: ";
        std::cin  >> userFips;
        key = hashFunc(userFips);
        hashTable.search(*key, *places[500], *found);
        if (found) {
          std::cout << "\nthe city was found\n" << std::endl;
        } else {
          std::cout << "\nthe city was not found\n" << std::endl;
        }
        break;
      case 2:
        hashTable.print();
        break;
      case 3:
        std::cout << "Program is exiting..." << std::endl;
        break;
      default:
        std::cout << "Please choose one of the options above!" << std::endl;
    }
  } while (input != 3);








  return 0;
} // ************* end of main. ***************************



std::istream& operator>>(std::istream& str, CSVRow& data) {
    data.readNextRow(str);
    return str;
}

int hashFunc(string name) {
	int i, sum;
	int len;
	i = 0; sum = 0;

	len = name.length();
	for (int k = 0; k < 15 - len; k++) {
		name = name + ' '; 		//increase the length of the name to 15 characters
  }

	for (int k = 0; k < 5; k++) {
		sum = sum + static_cast<int>(name[i]) * 128 * 128
		+ static_cast<int>(name[i + 1]) * 128
		+ static_cast<int>(name[i + 2]);
        i = i + 3;
	}
    return sum % 1009;
}

void menu () {
  std::cout << "Choose an option below:" << std::endl;
  std::cout << "1.) Search a city from its fips number." << std::endl;
  std::cout << "2.) Print out the entire list of cities." << std::endl;
  std::cout << "3.) exit." << std::endl;
  std::cout << "option: ";
}
