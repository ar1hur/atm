#include "csvDepot.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

unsigned short** CSVDepot::readDepot() {
  cout << "reading csvdepot..." << endl;
  fstream file;
  string line;
  unsigned short** banknotes = new unsigned short*[7];

  file.open("depot.csv", ios::in);

  for (unsigned short i = 0; i < 7; i++) {
    getline(file, line);

    banknotes[i] = new unsigned short[2];

    size_t pos = line.find(";");
    banknotes[i][1] = stoi(line.substr(0, pos));

    size_t end = line.find("\n");
    banknotes[i][0] = stoi(line.substr(pos + 1, end));

    cout << "banknote: " << banknotes[i][0] << " value: " << banknotes[i][1]
         << endl;
  }

  file.close();
  return banknotes;
}

void CSVDepot::writeDepot(unsigned short** banknotes) {
  cout << "writing csvdepot..." << endl;

  fstream file;
  string line;

  file.open("depot.csv", ios::out);
  for (unsigned short i = 0; i < 7; i++) {
    file << banknotes[i][1] << ";" << banknotes[i][0] << "\n";
  }
  file.close();
}
