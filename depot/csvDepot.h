#ifndef _CSV_DEPOT_
#define _CSV_DEPOT_

#include "idepot.h"

class CSVDepot : public IDepot {
protected:
  unsigned short** readDepot();
  void writeDepot(unsigned short** banknotes);
};

#endif
