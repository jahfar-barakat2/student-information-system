#include "Menu.hpp"
#include <iostream>
#include <limits> // for numeric_limits

Menu::Menu() {
    repo.initializeTable();
}


void Menu::run() {

        displayOptions();


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