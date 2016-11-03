//***********************
// Name:  Tyra McCoy
// Purpose: Homework 2
// Date:  09/14/16
// Reference:  Chapter 2, 3
//***********************

//This program will calculate and display the outflow flow velocity through a circular engine pipe
// given values for the velocity entering the pipe, the radius of the entrance of the pipe, and the 
//radius of radius of the exit of the pipe.

#include <iostream>
#include <iomanip>
#include <cmath>               
using namespace std;

int main ()
{
double rin;            //Variable for radius of the entrance of the pipe
double rout;          //Variable for radius of the exit of the pipe

cout << "Enter the radius of the entrance of the pipe (in inches): ";
cin  >> rin;

cout << "Enter radius of the exit of the pipe (in inches): ";
cin  >> rout;

double a = rin/ rout;
double b = a * a;	
double vin;           //Variable for velocity entering the pipe

cout << "Enter the flow's velocity entering the pipe (ft/s): ";
cin  >> vin;

double vout = vin * b;      //Variable for velocity of outflow through circular engine pipe 

cout << setiosflags(ios:: fixed)
<< setiosflags(ios::showpoint)
<< setprecision(4)
<< "The velocity of the outflow through a circular engine pipe is: " << vout << endl;

return 0;
}

