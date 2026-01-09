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
                case 2: handleList(); break;
                case 3: handleSearch(); break;
                case 4: handleUpdate(); break;
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

void Menu::handleList() {
    std::cout << "\n--- STUDENT LIST ---\n";
    repo.getAllStudents(); 
}

void Menu::handleSearch() {
    std::cout << "\n--- SEARCH STUDENT ---\n";
    int id = getIntInput("Enter Student ID: ");
    auto s = repo.findById(id);

    if (s) {
        std::cout << "\n[FOUND]\n";
        std::cout << "ID: " << s->id << "\n";
        std::cout << "Name: " << s->name << " " << s->surname << "\n";
        std::cout << "Dept: " << s->department << "\n";
        std::cout << "Email: " << s->email << "\n";
    } else {
        std::cout << "[!] Student not found.\n";
    }
}

void Menu::handleUpdate() {
    std::cout << "\n--- UPDATE STUDENT ---\n";
    int id = getIntInput("Enter Student ID to update: ");
    
    // 1. FETCH
    auto s = repo.findById(id);
    if (!s) {
        std::cout << "[!] Student not found.\n";
        return;
    }

    std::cout << "Updating Student: " << s->name << " " << s->surname << "\n";
    std::cout << "(Press ENTER to keep current value)\n";

    // 2. MODIFY (Smart Input)
    std::string input;

    // Update Name
    input = getStringInput("Name [" + s->name + "]: ");
    if (!input.empty()) s->name = input;

    // Update Surname
    input = getStringInput("Surname [" + s->surname + "]: ");
    if (!input.empty()) s->surname = input;

    // Update Department
    input = getStringInput("Department [" + s->department + "]: ");
    if (!input.empty()) s->department = input;

    // Update Email
    input = getStringInput("Email [" + s->email + "]: ");
    if (!input.empty()) s->email = input;

    // 3. SAVE
    repo.updateStudent(*s);
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