#ifndef STUDENT_REPOSITORY_HPP
#define STUDENT_REPOSITORY_HPP

#include "Student.hpp"
#include <pqxx/pqxx>

class StudentRepository {
public:
    // This method adds new student to the table
    void save(const Student& student);

    std::vector<Student> getAllStudents() ;
    
    // This creates a students table with (id,name,surname,department,email).Should be called for one time
    void initializeTable();

private:
    // Helper to log errors (placeholder for future logging system)
    void logError(const std::string& message);
};

#endif