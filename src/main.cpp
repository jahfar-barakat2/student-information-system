#include <iostream>
#include <pqxx/pqxx> // The PostgreSQL C++ library
#include <cstdlib>   // For std::getenv


// Function 1: Save Student Information
void saveStudent(pqxx::connection& C, int id, std::string name, std::string surname, std::string dept, std::string email) {
    try {
        pqxx::work W(C); // Start transaction
        
        // Use 'exec_params' to prevent SQL injection and handle data safely
        // $1, $2... maps to the arguments passed after the query string
        W.exec_params(
            "INSERT INTO students (id, name, surname, department, email) VALUES ($1, $2, $3, $4, $5)",
            id, name, surname, dept, email
        );

        W.commit(); // Commit transaction
        std::cout << "[SUCCESS] Student saved: " << name << " " << surname << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "[ERROR] Could not save student: " << e.what() << std::endl;
    }
}

int main() {
    try {
        // 1. Get connection details from environment variables (set in docker-compose)
        // If they are missing, we provide default values
        const char* db_host = std::getenv("POSTGRES_HOST") ? std::getenv("POSTGRES_HOST") : "db";
        const char* db_name = std::getenv("POSTGRES_DB") ? std::getenv("POSTGRES_DB") : "studentdb";
        const char* db_user = std::getenv("POSTGRES_USER") ? std::getenv("POSTGRES_USER") : "admin";
        const char* db_pass = std::getenv("POSTGRES_PASSWORD") ? std::getenv("POSTGRES_PASSWORD") : "secretpassword";

        // 2. Build the connection string
        std::string conn_str = "host=" + std::string(db_host) + 
                               " port=5432 dbname=" + std::string(db_name) + 
                               " user=" + std::string(db_user) + 
                               " password=" + std::string(db_pass);

        std::cout << "Connection string:  " << conn_str << "..." << std::endl;
        std::cout << "Connecting to database at " << db_host << "..." << std::endl;

        // 3. Establish connection
        pqxx::connection C(conn_str);
        if (C.is_open()) {
            std::cout << "SUCCESS: Connected to " << C.dbname() << std::endl;
        } else {
            std::cerr << "ERROR: Could not open database." << std::endl;
            return 1;
        }

        // 4. Create the table (Basic Function: Week 3 Requirement)
        // pqxx::work W(C);
        // std::string sql = "CREATE TABLE IF NOT EXISTS students ("
        //                   "id INT PRIMARY KEY NOT NULL,"
        //                   "name TEXT NOT NULL,"
        //                   "surname TEXT NOT NULL,"
        //                   "department TEXT,"
        //                   "email TEXT);";
        
        // W.exec(sql);

        
        // W.commit(); // Save changes
        // std::cout << "Table 'students' is ready." << std::endl;

        saveStudent(C,00,"name","surname","dept","name.surname@email.com");        


    } catch (const std::exception &e) {
        std::cerr << "DATABASE ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
