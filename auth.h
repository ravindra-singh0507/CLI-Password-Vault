#ifndef AUTH_H
#define AUTH_H

#include <string>

std::string hashMasterPassword(const std::string& password);
bool verifyMasterPassword(const std::string& inputPassword, const std::string& storedHash);

#endif // AUTH_H

