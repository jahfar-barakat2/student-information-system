#include "Menu.hpp"
#include <iostream>
#include <limits> // for numeric_limits

Menu::Menu() {
    repo.initializeTable();
}


void Menu::run() {
        bool running = true ;
        displayOptions();
        int choice = getIntInput("Enter your choice: ");

        try {
            switch (choice) {
                case 1: handleAdd(); break;
               
                case 0: 
                    running = false; 
                    std::cout << "Exiting system. Goodbye!\n";
                    break;
                default: 
                    std::cout << "[!] Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "[ERROR] An unexpected error occurred: " << e.what() << "\n";
        }

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


void Menu::handleAdd() {
    std::cout << "\n--- ADD NEW STUDENT ---\n";
    int id = getIntInput("ID: ");
    
    //Check if ID exists first
    if (repo.findById(id)) {
        std::cout << "[!] Error: Student with ID " << id << " already exists.\n";
        return;
    }

    std::string name = getStringInput("Name: ");
    std::string surname = getStringInput("Surname: ");
    std::string dept = getStringInput("Department: ");
    std::string email = getStringInput("Email: ");

    Student s = {id, name, surname, dept, email};
    repo.save(s);
}

// --- HELPERS ---

int Menu::getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            return value;
        } else {
            std::cout << "[!] Invalid input. Please enter a number.\n";
            std::cin.clear(); // Reset error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        }
    }
}

std::string Menu::getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

void Menu::waitForKey() {
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}