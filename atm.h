#ifndef _ATM_
#define _ATM_

#include "depot/csvDepot.h"

struct ATMSlip {
    unsigned int total;
    unsigned int amount;
    unsigned short widthdraws[7][2]; // 0=count | 1=value
    unsigned int rest;
};

class ATM: private IDepot {
    unsigned short** readDepot();
    void writeDepot(unsigned short** widthdraws);

    private:
        ATMSlip newSlip(unsigned short** banknotes);
        IDepot *pDepot;
        
    public:
        ATM(IDepot *pDepot);
        ATMSlip widthdraw(unsigned int amount);
};

#endif