#ifndef TRAINING_H
#define TRAINING_H

#include <iostream>
#include <sqlite3.h>
using namespace std; 


class Training{ 
    public: 
    string TrainingType; 
    int TrainingID; 

    Training(string trainingName, int ID);
    Training(const char* dbPath);
    Training();
    string getTrainingName(); 
    void addEmployee();
    void removeEmployeeFromTraining(); 
    void randomizeEmployee();
    void deleteEmployee(int &ID);
    void printInProgressEmployees();
    
    private: 
    sqlite3* dataBase;
    vector<string>inProgressEmployees;
    vector<string>employees;


};



#endif