#include "atm.h"
#include "depot/csvDepot.h"
#include "depot/jsonDepot.h"
#include "depot/sqliteDepot.h"
#include <iostream>

int main() {
  IDepot* jsonDepot = new JSONDepot();
  IDepot* csvDepot = new CSVDepot();
  IDepot* sqliteDepot = new SQLiteDepot();

  // you can choose between depots:
  // ATM atm(sqliteDepot);
  // ATM atm(jsonDepot);
  ATM atm(csvDepot);

  unsigned int amount;
  cout << "Enter your amount:" << endl;
  cin >> amount;

  ATMSlip s = atm.withdraw(amount);

  for (unsigned short i = 0; i < 7; i++) {
    if (s.withdraws[i][0] > 0) {
      cout << s.withdraws[i][0] << "x " << s.withdraws[i][1] << " EUR" << endl;
    }
  }
  cout << "total: " << s.total << endl;
  cout << "rest: " << s.rest << endl;

  return 0;
}
