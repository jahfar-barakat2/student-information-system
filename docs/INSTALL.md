# Installation Guide

This document explains how to install and run the **Student Information System (CLI)**.

---

## 1️⃣ System Requirements

### Operating System
- Linux (Ubuntu recommended)
- macOS (tested with Docker)
- Windows (via WSL2 or Docker Desktop)

---

## 2️⃣ Required Software

### Mandatory
- **Docker**
- **Docker Compose**

Check installation:
```bash
docker --version
docker compose version


3️⃣ Installation Using Docker (Recommended)

Step 1: Clone the Repository

git clone https://github.com/jahfar-barakat2/student-information-system.git
cd student-information-system

Step 2: Build and Run Containers

docker compose up --build -d

docker compose exec app ./StudentSystem


This will:

 -Start the PostgreSQL container

 -Build the C++ application container

 -Launch the CLI interface

The database data is persisted using Docker volumes.

Step 3: Stop the Application

docker compose down


4️⃣ Local Installation (Without Docker)
    ⚠️ This method is optional and recommended only for development.

Step 1: Install Dependencies

sudo apt update
sudo apt install g++ libpq-dev libpqxx-dev postgresql cmake


Step 2: Compile the Project
g++ -std=c++17 -I include src/*.cpp -lpqxx -lpq -o build/app

Step 3: Run
./app


5️⃣ Database Initialization
 -The students table is created automatically on first run
 -No manual SQL setup is required
 -Connection parameters are managed internally by the application

6️⃣ Common Issues


Docker permission error
 sudo usermod -aG docker $USER
Log out and log back in.



Port already in use
Stop conflicting PostgreSQL services:
    sudo systemctl stop postgresql



7️⃣ Uninstall
To remove containers and volumes:
    docker compose down -v
