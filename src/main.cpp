#include <iostream>
#include <vector>
#include "StudentRepository.hpp"



int main() {
    StudentRepository repo;

    
    //Student s1 = {1000, "student", "name", "fbu","surname@email.com"};
    //repo.save(s1);

    auto student = repo.findById(1000);
    std::cout << "name : " << student->name << std::endl;
    std::cout << "surname : " << student->surname << std::endl;


    std::vector<Student> vec;

    //repo.deleteStudent(1000);

    vec = repo.getAllStudents();
    return 0;
}