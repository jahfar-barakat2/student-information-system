# Student Information System

System Programming course project.

## 🧰 Technologies

- C++
- PostgreSQL (planned)
- Docker & Docker Compose
- GitHub Actions (planned)
- Ubuntu

## 📌 Project Description

A CLI-based **Student Information System** written in C++.

The goal of the project is to build a system that will:

- store student information
- support basic CRUD operations (create, read, update, delete)
- interact with a PostgreSQL database

> Functionality is **currently under development**.  
> Database layer and CRUD operations will be added in upcoming iterations.

## 🚀 Development Environment

The repository currently includes:

- initial project structure
- `Dockerfile` for containerizing the C++ application
- `docker-compose.dev.yml` for development setup
- basic README documentation
- environment preparation scripts (planned)

### ▶️ Run using Docker Compose (development)

```bash
docker compose -f docker-compose.dev.yml up --build
