#ifndef _SQLITE_DEPOT_
#define _SQLITE_DEPOT_

#include "idepot.h"
#include "sqlite3.h"
#include <iostream>

using namespace std;

class SQLiteDepot : public IDepot {
public:
  SQLiteDepot() throw();

protected:
  sqlite3* db;

  void connect();
  void createTable();
  void exec(char* sql);
  static int callback(void* data, int argc, char** argv, char** azColName);

  unsigned short** readDepot();
  void writeDepot(unsigned short** banknotes);
};

#endif
