#pragma once
#include "StudentRepository.hpp"
#include <memory>

class Menu {
public:
    Menu();
    void run(); // Main loop

private:
    StudentRepository repo;

    // Menu Actions
    void displayOptions();
    void handleAdd();
    void handleList();
    void handleUpdate(); // Implements the Fetch-Modify-Save pattern
    void handleDelete();
    void handleSearch();

    // Input Helpers
    int getIntInput(const std::string& prompt);
    std::string getStringInput(const std::string& prompt);
    void waitForKey();
};
