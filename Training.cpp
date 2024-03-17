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

vector<string>Training::getInProgressEmployees(){
    return inProgressEmployees;
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

    // SQL command to insert a new employee into the database
    string sqlInsert = "INSERT INTO Employees (Name, ID) VALUES ('" + name + "', " + to_string(id) + ")";

    int status = sqlite3_exec(dataBase, sqlInsert.c_str(), nullptr, nullptr, nullptr);
    if (status != SQLITE_OK) {
        cout << "Error inserting employee data: " << sqlite3_errmsg(dataBase) << endl;
        return;
    }

    cout << "Employee data inserted successfully" << endl;

}
void Training::removeEmployeeFromTraining(string name, int ID){
    //DatabASE will be used here 
}

string Training::randomizeEmployee(){
    //random employee will be chosen here and added to inprogress employee
    return "";
}