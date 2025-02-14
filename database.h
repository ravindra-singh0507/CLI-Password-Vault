#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "sqlite3.h"

void createDatabase();
void storePassword(const std::string &service, const std::string &username, const std::string &encryptedPassword);
std::string retrievePassword(const std::string &service);

#endif // DATABASE_H

