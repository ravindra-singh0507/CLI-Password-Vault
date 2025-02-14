#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <vector>
#include <string>

std::vector<unsigned char> encrypt(const std::string &plaintext, const unsigned char *key, unsigned char *iv);
std::string decrypt(const std::vector<unsigned char> &ciphertext, const unsigned char *key, unsigned char *iv);

#endif // ENCRYPTION_H

