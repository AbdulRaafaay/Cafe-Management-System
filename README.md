# Cafe Management System

## 📌 Overview
This is a **Cafe Management System** developed in **C++**, designed to manage cafe operations such as **inventory management, employee records, order processing, notifications, and sales tracking**.

## ⚡ Features
- **Admin functionalities**:
  - Add, remove, and search for items
  - Manage employees and students
  - View complaints and notifications
  - Track best-selling employees
- **Employee functionalities**:
  - Take orders and generate bills
  - Process online/scheduled orders
- **Student functionalities**:
  - Search and order items
  - Schedule online orders
  - View notifications
  - Submit complaints
- **File handling for data persistence**
- **Color-coded console output for better readability**

## 🛠️ Requirements
- C++ Compiler (e.g., **G++ or MSVC**)
- A terminal supporting ANSI escape codes (for colored output)
- Required files:
  - `main.cpp` (Main entry point)
  - `func.cpp` (Function implementations)
  - `header.h` (Header file with function declarations and macros)
  - External text files for data storage (`admin.txt`, `employees.txt`, `students.txt`, `items.txt`, `bill.txt`, etc.)

## 🚀 Installation & Compilation
1. **Clone or Download** the repository.
   ```sh
   git clone <repository-url>
   cd Cafe-Management-System
   ```
2. **Compile the code** using a C++ compiler:
   ```sh
   g++ main.cpp func.cpp -o cafe_management
   ```
3. **Run the executable**:
   ```sh
   ./cafe_management  # Linux/macOS
   cafe_management.exe  # Windows
   ```

## 📌 Usage
1. **Launch the program** and select the user type:
   - `Admin`
   - `Employee`
   - `Student/Staff`
2. Follow on-screen prompts to navigate through the system.
3. Admins can **manage items, employees, and students**.
4. Employees can **process orders and view bills**.
5. Students can **search and order items, view notifications, and submit complaints**.

## 📂 File Structure
```
├── main.cpp        # Main program
├── func.cpp        # Function implementations
├── header.h        # Header file with function declarations
├── admin.txt       # Admin credentials
├── employees.txt   # Employee credentials
├── students.txt    # Student credentials
├── items.txt       # Item inventory
├── bill.txt        # Order receipts
├── complaints.txt  # Customer complaints
├── notifications.txt # System notifications
```

## 📜 License
This project is for **educational purposes only**. Feel free to modify and improve the system.

## 🤝 Contributing
- Fork the repository
- Create a feature branch
- Submit a Pull Request

For any **issues or suggestions**, please open an issue in the repository.

---
**Author:** Abdul Rafay

