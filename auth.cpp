#include "auth.h"
#include "BCrypt.hpp"

std::string hashMasterPassword(const std::string& password) {
    return BCrypt::generateHash(password);
}

bool verifyMasterPassword(const std::string& inputPassword, const std::string& storedHash) {
    return BCrypt::validatePassword(inputPassword, storedHash);
}

