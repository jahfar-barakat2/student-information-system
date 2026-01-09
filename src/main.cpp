#include <iostream>
#include <vector>
#include "StudentRepository.hpp"

int main() {
    StudentRepository repo;

    
    Student s1 = {1000, "student", "name", "fbu","surname@email.com"};
    //repo.save(s1);

    std::vector<Student> vec;

    repo.updateStudent(s1);

    vec = repo.getAllStudents();
    return 0;
}