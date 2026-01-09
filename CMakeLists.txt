cmake_minimum_required(VERSION 3.10)

# 1. Project Name and Version
project(StudentInformationSystem VERSION 1.0)

# 2. Set C++ Standard (Modern C++ as required)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. Find Required Packages (PostgreSQL and Libpqxx)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

# 4. Include Headers
# Tells CMake to look in the 'include/' folder for .hpp files
include_directories(include)

# 5. Locate Source Files
# Automatically finds all .cpp files in src/
file(GLOB SOURCES "src/*.cpp")

# 6. Define the Executable
# Creates a binary named 'StudentSystem' from the source files
add_executable(StudentSystem ${SOURCES})

# 7. Link Libraries
# Links the database libraries to your executable
target_link_libraries(StudentSystem PRIVATE ${PQXX_LIBRARIES} pq)

# Optional: Add strict compiler warnings
target_compile_options(StudentSystem PRIVATE -Wall -Wextra)