#include "Menu.hpp"
#include <iostream>
#include <limits> // for numeric_limits

Menu::Menu() {
    repo.initializeTable();
}



void Menu::displayOptions() {
    std::cout << "\n========================================\n";
    std::cout << "   STUDENT INFORMATION SYSTEM (CLI)   \n";
    std::cout << "========================================\n";
    std::cout << " 1. Add New Student\n";
    std::cout << " 2. List All Students\n";
    std::cout << " 3. Search Student by ID\n";
    std::cout << " 4. Update Student Details\n";
    std::cout << " 5. Delete Student\n";
    std::cout << " 0. Exit\n";
    std::cout << "========================================\n";
}