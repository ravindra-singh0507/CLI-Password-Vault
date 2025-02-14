#include "generator.h"
#include <iostream>
#include <random>

std::string generatePassword(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += characters[distribution(generator)];
    }
    return password;
}

