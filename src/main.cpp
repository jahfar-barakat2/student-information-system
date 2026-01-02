#include <iostream>
#include "StudentRepository.hpp"

int main() {
    StudentRepository repo;

    
    Student s1 = {2024010, "name", "surname", "dept", "name@fbu.edu.tr"};
    repo.save(s1);

    return 0;
}