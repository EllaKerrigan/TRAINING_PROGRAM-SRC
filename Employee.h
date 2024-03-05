#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std; 

class Employee{

    public: 
    string firstName;  
    double idNum; 
    double gradDate; 
    bool inTraining; 

    Employee(string, double, double);
    Employee(); 
    string getName();
    bool getIsInTraining();
    double getId(); 
    double getGraduationDate(); 
    void setName(string); 
    void setID(double); 
    void setGradDate(double); 

};






#endif