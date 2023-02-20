#include "atm.h"
#include <iostream>

using namespace std;

ATM::ATM(IDepot* pDepot) {
  ATM::pDepot = pDepot;
  pDepot->readDepot();
}

ATMSlip ATM::newSlip(unsigned short** banknotes) {
  ATMSlip slip;
  slip.rest = 0;
  slip.total = 0;

  for (unsigned short i = 0; i < 7; i++) {
    slip.withdraws[i][0] = 0;
    slip.withdraws[i][1] = banknotes[i][1];
  }

  return slip;
}

unsigned short** ATM::readDepot() { return pDepot->readDepot(); }

void ATM::writeDepot(unsigned short** banknotes) {
  pDepot->writeDepot(banknotes);
}

ATMSlip ATM::withdraw(unsigned int amount) {
  unsigned short** banknotes = readDepot();

  ATMSlip slip = newSlip(banknotes);
  slip.amount = amount;

  unsigned short i = 0;
  bool withdrawal = false;

  while (amount != 0 && i < 7) {
    if (banknotes[i][0] == 0 || banknotes[i][1] > amount) {
      i++;
    } else {
      withdrawal = true;
      amount -= banknotes[i][1];
      banknotes[i][0]--;
      slip.withdraws[i][0]++;

      if ((amount > 5 && amount < 10) || (amount > 0 && amount < 5)) {
        slip.rest = amount;
        break;
      }
    }
  }

  for (i = 0; i < 7; i++) {
    if (slip.withdraws[i][0] > 0) {
      slip.total += banknotes[i][1] * slip.withdraws[i][0];
    }
  }

  if (withdrawal) {
    writeDepot(banknotes);
  }

  return slip;
}
