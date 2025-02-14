#include "database.h"
#include <iostream>

sqlite3 *db;

void createDatabase() {
    int rc = sqlite3_open("passwords.db", &db);
    if (rc) {
        std::cerr << "Database error: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::string sql = "CREATE TABLE IF NOT EXISTS PASSWORDS ("
                          "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "SERVICE TEXT NOT NULL, "
                          "USERNAME TEXT NOT NULL, "
                          "PASSWORD TEXT NOT NULL);";
        sqlite3_exec(db, sql.c_str(), 0, 0, nullptr);
    }
}

void storePassword(const std::string &service, const std::string &username, const std::string &encryptedPassword) {
    std::string sql = "INSERT INTO PASSWORDS (SERVICE, USERNAME, PASSWORD) VALUES ('" +
                      service + "', '" + username + "', '" + encryptedPassword + "');";
    sqlite3_exec(db, sql.c_str(), 0, 0, nullptr);
}

std::string retrievePassword(const std::string &service) {
    std::string query = "SELECT PASSWORD FROM PASSWORDS WHERE SERVICE='" + service + "';";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string encryptedPassword = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
            sqlite3_finalize(stmt);
            return encryptedPassword;  // Decrypt before returning
        }
    }
    sqlite3_finalize(stmt);
    return "No password found!";
}

