#include "Employee.h"
#include "Training.h"
#include <vector>
#include <iostream>

using namespace std; 


Training::Training(string trainingName, int ID){
    this->TrainingType = trainingName;
    this->TrainingID = ID;
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

void Training::addEmployeeToTraining(string name, int ID, double gradDate){
    //DataBase will be used here 
}
void Training::removeEmployeeFromTraining(string name, int ID){
    //DatabASE will be used here 
}