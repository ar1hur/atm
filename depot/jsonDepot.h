#ifndef _JSON_DEPOT_
#define _JSON_DEPOT_

#include "idepot.h"
#include <string>

using namespace std;

class JSONDepot: public IDepot {    
    protected:    
        unsigned short extractValue(const string& keywordMarker, const string& line);
        unsigned short** readDepot();
        void writeDepot(unsigned short** banknotes);        
};

#endif