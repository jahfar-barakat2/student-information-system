#include "StudentRepository.hpp"
#include "Database.hpp" // Needs access to DB
#include <iostream>
#include <iomanip>

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

void StudentRepository::save(const Student& s) {
    try {
        auto conn = Database::getInstance().getConnection();
        pqxx::work W(*conn);
        
        // Using exec_params for security
        W.exec_params(
            "INSERT INTO students (id, name, surname, department, email) "
            "VALUES ($1, $2, $3, $4, $5)",
            s.id, s.name, s.surname, s.department, s.email
        );
        
        W.commit();
        std::cout << "[SUCCESS] Saved student: " << s.name << std::endl;
    } catch (const std::exception &e) {
        logError("Save failed: " + std::string(e.what()));
    }
}

std::vector<Student> StudentRepository::getAllStudents(){
    std::vector<Student> students;
    try {
        auto conn = Database::getInstance().getConnection();
        pqxx::work W(*conn);
        
        pqxx::result R = W.exec("SELECT id, name, surname, department, email FROM students ORDER BY id ASC");
        
        std::cout << "\n--------------------------------------------------------------------------------\n";
        std::cout << std::left 
                  << std::setw(10) << "ID" 
                  << std::setw(15) << "Name" 
                  << std::setw(15) << "Surname" 
                  << std::setw(20) << "Department" 
                  << std::setw(20) << "Email";
        std::cout << "\n--------------------------------------------------------------------------------\n";


        for (auto row : R) {
            std::cout << std::left 
                      << std::setw(10) << row[0].as<int>() 
                      << std::setw(15) << row[1].as<std::string>() 
                      << std::setw(15) << row[2].as<std::string>() 
                      << std::setw(20) << row[3].as<std::string>() 
                      << std::setw(20) << row[4].as<std::string>() 
                      << "\n";
        }
        std::cout << "--------------------------------------------------------------------------------\n";


        for (auto row : R) {
            students.push_back({
                row[0].as<int>(),
                row[1].as<std::string>(),
                row[2].as<std::string>(),
                row[3].as<std::string>(),
                row[4].as<std::string>()
            });
        }
        std::cout << "[INFO] Retrieved " << students.size() << " students." << std::endl;
    } catch (const std::exception &e) {
        logError("getAllSttudents failed: " + std::string(e.what()));
    }
    return students;
}

void StudentRepository::updateStudent(const Student& s){
    try {
        auto conn = Database::getInstance().getConnection();
        pqxx::work W(*conn);
        
        auto result = W.exec_params(
            "UPDATE students SET name=$2, surname=$3, department=$4, email=$5 WHERE id=$1",
            s.id, s.name, s.surname, s.department, s.email
        );
        
        W.commit();
        
        if (result.affected_rows() > 0) {
            std::cout << "[SUCCESS] Updated student ID: " << s.id << std::endl;
        } else {
            std::cerr << "[WARN] Student ID " << s.id << " not found for update." << std::endl;
        }
    } catch (const std::exception &e) {
        logError("Update failed: " + std::string(e.what()));
    }
}

void StudentRepository::logError(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}