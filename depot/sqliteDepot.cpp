#include "sqliteDepot.h"

SQLiteDepot::SQLiteDepot() throw() {
  connect();
  createTable();
}

void SQLiteDepot::connect() {
  int rc = sqlite3_open("depot.db", &db);

  if (rc) {
    cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
    throw "Can't open database";
  }
}

int SQLiteDepot::callback(void* data, int argc, char** argv, char** azColName) {
  return 0;
}

unsigned short** SQLiteDepot::readDepot() {
  cout << "reading SQLiteDepot..." << endl;
  unsigned short** banknotes = new unsigned short*[7];

  const char* sql = "SELECT * from depot";
  sqlite3_stmt* stmt;

  int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    cerr << "error: " << sqlite3_errmsg(db) << endl;
    throw sqlite3_errmsg(db);
  }

  unsigned short i = 0;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    banknotes[i] = new unsigned short[2];
    banknotes[i][1] = sqlite3_column_int(stmt, 0);
    banknotes[i][0] = sqlite3_column_int(stmt, 1);
    cout << "banknote: " << banknotes[i][1] << " value: " << banknotes[i][0]
         << endl;
    i++;
  }

  if (rc != SQLITE_DONE) {
    cerr << "error: " << sqlite3_errmsg(db) << endl;
    throw sqlite3_errmsg(db);
  }
  sqlite3_finalize(stmt);

  return banknotes;
}

void SQLiteDepot::writeDepot(unsigned short** banknotes) {
  cout << "writing SQLiteDepot..." << endl;

  char* sql = (char*)"UPDATE depot SET available = ? WHERE banknote = ?;";
  cout << "loop" << endl;

  for (unsigned short i = 0; i < 7; i++) {
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, banknotes[i][0]);
    sqlite3_bind_int(stmt, 2, banknotes[i][1]);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
  }
}

void SQLiteDepot::createTable() {
  char* sql = (char*)"CREATE TABLE IF NOT EXISTS depot( \
        banknote INT PRIMARY KEY NOT NULL, \
        available  INT NOT NULL \
        );";
  exec(sql);

  sql =
      (char*)"INSERT OR IGNORE INTO depot (banknote,available) VALUES (500, 10); \
        INSERT OR IGNORE INTO depot (banknote,available) VALUES (200, 10); \
        INSERT OR IGNORE INTO depot (banknote,available) VALUES (100, 10); \
        INSERT OR IGNORE INTO depot (banknote,available) VALUES (50, 10); \
        INSERT OR IGNORE INTO depot (banknote,available) VALUES (20, 10); \
        INSERT OR IGNORE INTO depot (banknote,available) VALUES (10, 10); \
        INSERT OR IGNORE INTO depot (banknote,available) VALUES (5, 10);";
  exec(sql);
}

void SQLiteDepot::exec(char* sql) {
  char* zErrMsg = 0;
  char* data;
  int rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n%s", zErrMsg, sql);
    sqlite3_free(zErrMsg);
    throw;
  }
}
