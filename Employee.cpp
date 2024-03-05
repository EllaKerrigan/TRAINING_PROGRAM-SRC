#include <iostream>
#include "Employee.h"

using namespace std; 


 Employee::Employee(string firstName, double idNum, double gradDate){
    this->firstName = firstName;  
    this->idNum = idNum; 
    this->gradDate = gradDate;
 }
   Employee::Employee(){
    firstName = " "; 
    idNum = 0; 
    gradDate = 0;
   }

    string Employee::getName(){
        return firstName; 
    }

    double Employee::getId(){
        return idNum; 
    }
    double Employee::getGraduationDate(){
        return gradDate; 
    }
    bool Employee::getIsInTraining(){
        return inTraining;
    }

    void Employee::setName(string name){
        firstName = name;  
    }

    void Employee::setID(double id){
        idNum = id; 
    }

    void Employee::setGradDate(double gradDATE){
        gradDate = gradDATE; 
    }

