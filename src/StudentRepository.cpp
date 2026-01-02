#include "StudentRepository.hpp"
#include "Database.hpp" // Needs access to DB
#include <iostream>

void StudentRepository::initializeTable() {
    try {
        auto conn = Database::getInstance().getConnection();
        pqxx::work W(*conn);
        W.exec(
            "CREATE TABLE IF NOT EXISTS students ("
            "id INT PRIMARY KEY, "
            "name VARCHAR(50) NOT NULL, "
            "surname VARCHAR(50) NOT NULL, "
            "department VARCHAR(50), "
            "email VARCHAR(100) UNIQUE NOT NULL);"
        );
        W.commit();
        std::cout << "[INFO] Table 'students' initialized." << std::endl;
    } catch (const std::exception &e) {
        logError("Table initialization failed: " + std::string(e.what()));
    }
}


void StudentRepository::logError(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}