#include <iostream>
#include <sqlite3.h>
#include "Employee.h"
#include "Training.h"

void menu(const char* dbPath);

using namespace std;


int main() {

    sqlite3* dataBase;
    const char* dbPath = "/Users/ellakerrigan/Downloads/SRC_DATABASE.db"; 

    // Open the SQLite database
    int status = sqlite3_open(dbPath, &dataBase);
    if (status != SQLITE_OK) {
        cerr << "Error opening database" << endl;
        return 1;
    }

    // TESTING retrieve employee names
    const char* sqlQuery = "SELECT Name FROM Employees";
    sqlite3_stmt* statement;
    status = sqlite3_prepare_v2(dataBase, sqlQuery, -1, &statement, nullptr);
    if (status != SQLITE_OK) {
        cerr << "Error preparing statement" << endl;
        sqlite3_close(dataBase);
        return 1;
    }

    // get employee names and print
    while (sqlite3_step(statement) == SQLITE_ROW) {
        const unsigned char* name = sqlite3_column_text(statement, 0);
        cout << "Employee Name: " << name << endl;
    }

    //  close database
    sqlite3_finalize(statement);
    sqlite3_close(dataBase);


     const char* dbPath = "/Users/ellakerrigan/Downloads/SRC_DATABASE.db";; 
    
    sqlite3* db;

    int status = sqlite3_open(dbPath, &db);
    if (status != SQLITE_OK) {
        cout << "Error opening database" << endl;
        return 1;
    }
    cout << "Database opened successfully" << std::endl;
    
    sqlite3_close(dataBase);
    menu(dbPath);
    
 
    return 0;
}
    

void menu(const char* dbPath){

    string UserInput; 
    
    cout << "Welcome to the SRC Employee Training Program!: " << endl; 

    while(true){
        cout << "Choose from the Menu below: " << endl;
        cout << "  A - Add an employee to the training database" << endl; 
        cout << "  B - Remove an employee from the training database" << endl; 
        cout << "  C - View this weeks employees in training" << endl; 
        cout << "  D - View history of employees who passed their training" << endl; 
        cout << "  EXIT - to return to home page" << endl;

        cout << "Enter your choice: " << endl; 
        cin >> UserInput;
        if(UserInput == "A"){
            Training employeeToAdd(dbPath);
            employeeToAdd.addEmployee();
        }
        else if(UserInput == "EXIT"){
            break;
        }
        else{
            cout << "Error, try again or EXIT" << endl; 
        }
    }
 };
    
   