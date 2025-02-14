#include <iostream>
#include "auth.h"
#include "database.h"
#include "generator.h"
#include "encryption.h"

int main() {
    createDatabase();
    
    std::string masterPassword, inputPassword;
    std::cout << "Set Master Password: ";
    std::cin >> masterPassword;
    std::string hashedPassword = hashMasterPassword(masterPassword);

    std::cout << "Enter Master Password: ";
    std::cin >> inputPassword;

    if (!verifyMasterPassword(inputPassword, hashedPassword)) {
        std::cout << "Access Denied!\n";
        return 1;
    }

    int choice;
    do {
        std::cout << "\n1. Store Password\n2. Retrieve Password\n3. Generate Password\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string service, username, password;
            std::cout << "Enter Service Name: ";
            std::cin >> service;
            std::cout << "Enter Username: ";
            std::cin >> username;
            std::cout << "Enter Password: ";
            std::cin >> password;
            
            storePassword(service, username, password);
            std::cout << "Password stored successfully!\n";
        } 
        else if (choice == 2) {
            std::string service;
            std::cout << "Enter Service Name: ";
            std::cin >> service;
            std::cout << "Retrieved Password: " << retrievePassword(service) << "\n";
        } 
        else if (choice == 3) {
            int length;
            std::cout << "Enter password length: ";
            std::cin >> length;
            std::cout << "Generated Password: " << generatePassword(length) << "\n";
        }
    } while (choice != 4);

    return 0;
}

