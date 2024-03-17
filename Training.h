#ifndef TRAINING_H
#define TRAINING_H

#include <iostream>
#include <sqlite3.h>
using namespace std; 


class Training{ 
    public: 
    string TrainingType; 
    vector<string> inProgressEmployees; 
    int TrainingID; 

    Training(string trainingName, int ID);
    Training(const char* dbPath);
    Training();
    string getTrainingName();
    vector<string>getInProgressEmployees(); 
    void addEmployee();
    void removeEmployeeFromTraining(string,int); 
    string randomizeEmployee();

    private: 
    sqlite3* dataBase;


};



#endif