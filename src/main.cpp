#include <iostream>
#include <vector>
#include "StudentRepository.hpp"

int main() {
    StudentRepository repo;

    
    Student s1 = {1000, "student", "name", "fbu","surname@email.com"};
    //repo.save(s1);

    std::vector<Student> vec;

    repo.deleteStudent(1000);

    vec = repo.getAllStudents();
    return 0;
}