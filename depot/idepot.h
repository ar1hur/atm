#ifndef _I_DEPOT_
#define _I_DEPOT_

class IDepot {
public:
  virtual unsigned short** readDepot() = 0;
  virtual void writeDepot(unsigned short** banknotes) = 0;
};

#endif
