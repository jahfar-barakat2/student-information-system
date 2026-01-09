
---

# 📘 `MANUAL.md`

```markdown
# User Manual

This document explains how to use the **Student Information System (CLI)**.

---

## 1️⃣ Introduction

The Student Information System is a **menu-driven command-line application** that allows users to manage student records stored in a PostgreSQL database.

The system is designed for **single-user operation** and does not include authentication or user roles.

---

## 2️⃣ Starting the Application

After running the application (via Docker or locally), the main menu appears automatically.

---

## 3️⃣ Main Menu

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


Enter the number corresponding to the desired action.

---

## 4️⃣ Menu Options Explained

---

### ➕ 1. Add New Student

Prompts for:
- Student ID
- Name
- Surname
- Department
- Email

Rules:
- Student ID must be unique
- If the ID already exists, insertion is rejected

---

### 📋 2. List All Students

Displays all students stored in the database.

Each record includes:
- ID
- Name
- Surname
- Department
- Email

---

### 🔍 3. Search Student by ID

- Prompts for student ID
- Displays full student details if found
- Shows an error message if not found

---

### ✏️ 4. Update Student Details

Process:
1. Enter student ID
2. Current values are displayed
3. Press **ENTER** to keep existing values
4. Enter new value to update a field

This allows **partial updates** without re-entering all fields.

---

### 🗑 5. Delete Student

Process:
1. Enter student ID
2. System checks if student exists
3. Confirmation prompt (`y/n`)
4. Student is deleted only after confirmation

---

### 🚪 0. Exit

Safely exits the application.

---

## 5️⃣ Input Validation

- Numeric input is validated (non-numeric values are rejected)
- String input allows empty values only where appropriate
- Invalid choices return the user to the menu

---

## 6️⃣ Error Handling

- Database and runtime errors are caught safely
- Application continues running after recoverable errors
- User-friendly messages are displayed for invalid actions

---

## 7️⃣ Limitations

- No authentication or authorization
- Single-user CLI only
- No reporting or export features
- No concurrency handling

These limitations are intentional due to course scope.

---

## 8️⃣ Exit Behavior

The application exits cleanly without data loss.  
All data is persisted in PostgreSQL.

---