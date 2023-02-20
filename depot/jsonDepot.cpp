#include "jsonDepot.h"
#include <fstream>
#include <iostream>

unsigned short** JSONDepot::readDepot() {
  cout << "reading jsondepot..." << endl;
  fstream file;
  string line;
  unsigned short** banknotes = new unsigned short*[7];

  file.open("depot.json", ios::in);

  // ignore first line
  getline(file, line);

  for (unsigned short i = 0; i < 7; i++) {
    getline(file, line);

    banknotes[i] = new unsigned short[2];
    banknotes[i][1] = extractValue("banknote\": ", line);
    banknotes[i][0] = extractValue("available\": ", line);

    cout << "banknote: " << banknotes[i][0] << " value: " << banknotes[i][1]
         << endl;
  }

  file.close();
  return banknotes;
}

void JSONDepot::writeDepot(unsigned short** banknotes) {
  cout << "writing jsondepot..." << endl;

  fstream file;
  string line;

  file.open("depot.json", ios::out);

  file << "["
       << "\n";
  for (unsigned short i = 0; i < 7; i++) {
    string end = i < 6 ? ",\n" : "";
    file << "\t{\"banknote\": " << banknotes[i][1]
         << ", \"available\": " << banknotes[i][0] << "}" << end;
  }
  file << "\n]";
  file.close();
}

unsigned short JSONDepot::extractValue(const string& keywordMarker,
                                       const string& line) {
  size_t pos = line.find(keywordMarker) + keywordMarker.length();
  size_t end = line.find(",");
  return stoi(line.substr(pos, end));
}
