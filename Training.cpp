#include "Employee.h"
#include "Training.h"
#include <vector>
#include <iostream>

using namespace std; 

Training::Training(string trainingName, int ID){
    this->TrainingType = trainingName;
    this->TrainingID = ID;
}

Training::Training(const char* dbPath){
    int status = sqlite3_open(dbPath, &dataBase);
    if(status != SQLITE_OK){
        cerr << "Error opening database" << endl; 
    }
}

Training::Training(){
    this->TrainingType = " "; 
    this->TrainingID = 0; 
}

string Training::getTrainingName(){
    return TrainingType;
}

void Training::addEmployee(){
    string name;
    int id;

    cout << "Enter employee name: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << endl; 
    
    cout << "Enter employee ID: ";
    cin >> id;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Insert a new employee into the database
    string sqlInsert = "INSERT INTO Employees (Name, ID) VALUES ('" + name + "', " + to_string(id) + ")";

    int status = sqlite3_exec(dataBase, sqlInsert.c_str(), nullptr, nullptr, nullptr);
    if (status != SQLITE_OK) {
        cout << "Error inserting employee data: " << sqlite3_errmsg(dataBase) << endl;
        return;
    }

    cout << "Employee data inserted successfully" << endl;

}


void Training::deleteEmployee(int &id) {
    //Delete an employee from the database
    string sqlDelete = "DELETE FROM Employees WHERE ID = " + to_string(id);

    // Execute the SQL command
    int status = sqlite3_exec(dataBase, sqlDelete.c_str(), nullptr, nullptr, nullptr);
    if (status != SQLITE_OK) {
        cout << "Error removing employee data: " << sqlite3_errmsg(dataBase) << endl;
        return;
    }

    cout << "Employee data removed successfully" << endl;
}

// Function to select a random employee and add them to the in progress list
void Training::randomizeEmployee() {
    // Retrieve all employees from the database
    string sqlQuery = "SELECT * FROM Employees";

    // Prepare the SQL statement
    sqlite3_stmt* stmt;
    int status = sqlite3_prepare_v2(dataBase, sqlQuery.c_str(), -1, &stmt, nullptr);
    if (status != SQLITE_OK) {
        cout << "Error preparing SQL statement: " << sqlite3_errmsg(dataBase) << endl;
        return;
    }
    while ((status = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int id = sqlite3_column_int(stmt, 1);
        employees.push_back(name);
    }

    // Check if any employees were retrieved
    if (employees.empty()) {
        cout << "No employees found in the database" << std::endl;
        return;
    }
    // Seed the random number generator
    srand(std::time(nullptr));

    // Select a random employee
    int randomIndex = std::rand() % employees.size();
    string randomEmployee = employees[randomIndex];

    // Add the selected employee to the in progress list
    inProgressEmployees.push_back(randomEmployee);
    for(const auto& employee : inProgressEmployees){
        cout << "Testing" << endl; 
        cout << "- " << employee << endl; 
    }
    cout << "Random employee selected and added to in progress list: " << randomEmployee << endl;
}

void Training::printInProgressEmployees(){
    cout << "Employees in progress: " << endl; 
    for(const auto& employee : inProgressEmployees){
        cout << employee << endl;
    }
}
