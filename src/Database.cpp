#include "Database.hpp"
#include <cstdlib> // for std::getenv
#include <iostream>

Database& Database::getInstance() {
    static Database instance;
    return instance;
}

Database::Database() {
    initConnectionString();
}

void Database::initConnectionString() {
    // Reads from Docker Environment Variables
    const char* host = std::getenv("POSTGRES_HOST") ? std::getenv("POSTGRES_HOST") : "db";
    const char* db   = std::getenv("POSTGRES_DB")   ? std::getenv("POSTGRES_DB")   : "studentdb";
    const char* user = std::getenv("POSTGRES_USER") ? std::getenv("POSTGRES_USER") : "myuser";
    const char* pass = std::getenv("POSTGRES_PASSWORD") ? std::getenv("POSTGRES_PASSWORD") : "mypassword";

    connection_string = "host=" + std::string(host) + 
                        " port=5432 dbname=" + std::string(db) + 
                        " user=" + std::string(user) + 
                        " password=" + std::string(pass);
}

std::unique_ptr<pqxx::connection> Database::getConnection() {
    return std::make_unique<pqxx::connection>(connection_string);
}