#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <pqxx/pqxx>
#include <string>
#include <memory>

class Database {
public:
    // Static method to get the single instance (Singleton Pattern)
    // This ensures we don't open 100 connections by mistake.
    static Database& getInstance();

    // Returns a fresh connection object
    std::unique_ptr<pqxx::connection> getConnection();

private:
    Database(); // Private constructor
    std::string connection_string;
    void initConnectionString();
};

#endif