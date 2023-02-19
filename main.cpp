#include "atm.h"
#include "csvDepot.h"
#include <iostream>

using namespace std;


int main() {
    IDepot *csvDepot = new CSVDepot();
    ATM atm(csvDepot);
    ATMSlip s;

    cout << "Enter your amount:" << endl;

    unsigned int amount;
    cin >> amount;

    s = atm.widthdraw(amount);

    for (unsigned short i=0; i<7; i++) {
        if (s.widthdraws[i][0] > 0) {
            cout << s.widthdraws[i][0] << "x " << s.widthdraws[i][1] << " EUR" << endl;            
        }
    }
    cout << "total: " << s.total << endl;
    cout << "rest: " << s.rest << endl;

    return 0;
}