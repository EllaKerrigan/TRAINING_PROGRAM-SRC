
#include "Training.h"
#include <vector>
#include <iostream>
#include <sqlite3.h>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std; 

Training::Training(string trainingName, int ID) {
    this->TrainingType = trainingName;
    this->TrainingID = ID;
}

Training::Training(const char* dbPath) {
    int status = sqlite3_open(dbPath, &dataBase);
    if (status != SQLITE_OK) {
        cerr << "Error opening database: " << sqlite3_errmsg(dataBase) << endl;
    }
}

Training::Training() {
    this->TrainingType = " "; 
    this->TrainingID = 0; 
}

Training::~Training() {
    if (dataBase) {
        sqlite3_close(dataBase);
    }
}

string Training::getTrainingName() {
    return TrainingType;
}

void Training::addEmployee() {
    string name;
    int id;

    cout << "Enter employee name: " << endl;
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, name);
    
    cout << "Enter employee ID: ";
    cin >> id;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Insert a new employee into the database
    string sqlInsert = "INSERT INTO Employees (Name, ID) VALUES (?, ?)";

    sqlite3_stmt* stmt;
    int status = sqlite3_prepare_v2(dataBase, sqlInsert.c_str(), -1, &stmt, nullptr);
    if (status != SQLITE_OK) {
        cerr << "Error preparing SQL statement: " << sqlite3_errmsg(dataBase) << endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, id);

    status = sqlite3_step(stmt);
    if (status != SQLITE_DONE) {
        cerr << "Error inserting employee data: " << sqlite3_errmsg(dataBase) << endl;
    } else {
        cout << "Employee data inserted successfully" << endl;
    }

    sqlite3_finalize(stmt);
}

void Training::deleteEmployee(int &id) {
    // Delete an employee from the database
    string sqlDelete = "DELETE FROM Employees WHERE ID = ?";

    sqlite3_stmt* stmt;
    int status = sqlite3_prepare_v2(dataBase, sqlDelete.c_str(), -1, &stmt, nullptr);
    if (status != SQLITE_OK) {
        cerr << "Error preparing SQL statement: " << sqlite3_errmsg(dataBase) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, id);

    status = sqlite3_step(stmt);
    if (status != SQLITE_DONE) {
        cerr << "Error removing employee data: " << sqlite3_errmsg(dataBase) << endl;
    } else {
        cout << "Employee data removed successfully" << endl;
    }

    sqlite3_finalize(stmt);
}

void Training::randomizeEmployee() {
    // Retrieve all employees from the database
    string sqlQuery = "SELECT Name FROM Employees";
    
    sqlite3_stmt* stmt;
    int status = sqlite3_prepare_v2(dataBase, sqlQuery.c_str(), -1, &stmt, nullptr);
    if (status != SQLITE_OK) {
        cerr << "Error preparing SQL statement: " << sqlite3_errmsg(dataBase) << endl;
        return;
    }

    vector<string> employees;
    while ((status = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        employees.push_back(name);
    }

    sqlite3_finalize(stmt);

    // Check if any employees were retrieved
    if (employees.empty()) {
        cout << "No employees found in the database" << endl;
        return;
    }

    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Select a random employee
    int randomIndex = rand() % employees.size();
    string randomEmployee = employees[randomIndex];

    // Add the selected employee to the in progress list
    inProgressEmployees.push_back(randomEmployee);

    cout << "Random employee selected and added to in progress list: " << randomEmployee << endl;
}

void Training::printInProgressEmployees() {
    cout << "Employees in progress: " << endl; 
    for (const auto& employee : inProgressEmployees) {
        cout << "- " << employee << endl;
    }
}
