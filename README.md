# Student Information System

System Programming course project implemented in **C++**, using **Docker** and **PostgreSQL**.

This project is a **command-line based Student Information System** that allows managing student records with full CRUD functionality.

## 🧰 Technologies

- **C++ (C++17)**
- **PostgreSQL**
- **Docker & Docker Compose**
- **Ubuntu**

## 📌 Project Description

The Student Information System is a **menu-driven CLI application** that enables users to:

- Add new students
- List all students
- Search students by ID
- Update existing student records
- Delete students safely with confirmation

All student data is stored persistently in a **PostgreSQL database**.


## ✨ Features

- Interactive CLI menu
- PostgreSQL database integration
- Full CRUD operations
- Input validation (numeric & string)
- Safe update with partial field modification
- Deletion confirmation
- Table auto-initialization on startup
- Exception-safe database access
- Dockerized development environment


## 📁 Project Structure

├── include/
│ ├── Student.hpp
│ ├── StudentRepository.hpp
│ ├── Database.hpp
│ └── Menu.hpp
│
├── src/
│ ├── main.cpp
│ ├── Menu.cpp
│ ├── StudentRepository.cpp
│ └── Database.cpp
|
|
├── docs/
│ ├── CONTRIBUTING.md
│ ├── MANUAL.md
│ ├── INSTALL.md
│ 
├── Dockerfile
├── docker-compose.yml
├── .gitignore
├── .dockerignore
├── CMakeLists.txt
└── README.md




## 🗄 Database Schema

The application uses a single table:

```sql
students (
    id INTEGER PRIMARY KEY,
    name TEXT,
    surname TEXT,
    department TEXT,
    email TEXT
)

The table is automatically created at runtime if it does not exist.

▶️ Running the Application (Docker – Recommended)

Prerequisites

 - Docker
 - Docker compose

```bash
    docker compose up --build -d

    docker compose exec app ./StudentSystem

This will:

 - Start PostgreSQL

 - Build the C++ application

 - Run the CLI inside the container


 cleanup:
 docker compose down


▶️ Running Locally (Without Docker)


Requirements

 - g++ (C++17)
 - PostgreSQL
 - libpqxx

Build :
    g++ -std=c++17 -I include src/*.cpp -lpqxx -lpq -o StudentSystem

Run :
    ./StudentSystem


🧭 CLI Menu Overview

========================================
   STUDENT INFORMATION SYSTEM (CLI)
========================================
 1. Add New Student
 2. List All Students
 3. Search Student by ID
 4. Update Student Details
 5. Delete Student
 0. Exit
========================================


🏷 Versioning

This project follows semantic versioning.

Current Version

v1.0.0

✔ Stable CRUD
✔ Dockerized
✔ PostgreSQL-backed
✔ CLI-based


📄 License

This project is developed for academic purposes.

Author

Jahfar Barakat

Computer Engineering Student

