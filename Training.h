#ifndef TRAINING_H
#define TRAINING_H

#include <iostream>
using namespace std; 


class Training{ 
    public: 
    string TrainingType; 
    vector<string> inProgressEmployees; 
    int TrainingID; 

    Training(string trainingName, int ID);
    Training();
    string getTrainingName();
    vector<string>getInProgressEmployees(); 
    void addEmployeeToTraining(string,int,double);
    void removeEmployeeFromTraining(string,int); 



};



#endif