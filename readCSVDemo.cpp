#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

class CSVRow {
   public:
//  std::string_view operator[](std::size_t index) const {
    std::string operator[](std::size_t index) const {
//      return std::string_view(&m_line[m_data[index] + 1], m_data[index + 1] - (m_data[index] + 1));
        return std::string(&m_line[m_data[index] + 1], m_data[index + 1] - (m_data[index] + 1));
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

std::istream& operator>>(std::istream& str, CSVRow& data) {
    data.readNextRow(str);
    return str;
}
int main() {
    std::ifstream file("500_Cities.csv");

    std::cout << file.fail() << std::endl;

    CSVRow row;
    while (file >> row) {

        std::cout << "stateid: " << row[0] << std::endl;
        std::cout << "placename: " << row[1] << std::endl;
        std::cout << "fips: " << row[2] << std::endl;
        std::cout << "population: " << row[3] << std::endl;
    }
}