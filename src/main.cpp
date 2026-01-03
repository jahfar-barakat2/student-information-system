#include <iostream>
#include <vector>
#include "StudentRepository.hpp"

int main() {
    StudentRepository repo;

    
    Student s1 = {1000, "name", "surname", "dept","email"};
    repo.save(s1);

    std::vector<Student> vec;



    vec = repo.getAllStudents();
    return 0;
}