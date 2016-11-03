//***********************
// Name:  Tyra McCoy
// Purpose: Homework 4
// Date: 10/12/16
// Reference:  Chapter 4, 5
//***********************


// The purpose of this program is to calculate the deflection and rotation at incremental points 
//  of the USAF F-16c wing when idealized as a cantilever beam with a uniformly distributed load
// along the length of the cantilever beam. The user can calculate these values in increments 
// of 0.05 meters of the cantilever beam of span (L) by inputting the span of the cantilever beam in meters, 
// the distributed load (w) in N/m, the Young’s Modulus of the material of the beam (E) in Pascals,
// and the base and height of the rectangular section. The formula I = (b*h^3)/12 will be used to
// calculate the area moment of inertia of the rectangular cross-section (I), a necessary variable in
// the calculation of the deflection and slope.



#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main ()
{
	const int MAXCOUNT = 1;
	double i;
	double x, a, w, E, L, b, h, I, del, theta, del2, theta2; // variables declared

cout << "Enter the length of the span of the cantilever beam (L): ";		// in meters
cin >> L;

cout << "Enter the area (a) of the cantilever beam: ";						// in meters
cin >> a;

cout << "Enter the weight of the distributed load (w) on the cantilever beam: ";	// in N/m
cin >> w;

cout << "Enter the Young’s Modulus of the material of the beam: ";			// in Pa
cin >> E;

cout << "Enter the base and height dimensions of the rectangular cross-section (I)" << endl;

cout << "Base: ";	// in meters
cin >> b;

cout << "Height: ";		// in meters
cin >> h;
	
	cout << "Distance (x)   	Deflection     Rotation\n"			// Chart with headers for the distance,
       << "------------   	------------   ------------\n";			// deflection, and rotation angle values

cout << setiosflags(ios::showpoint);       
for (i = 0; i <= MAXCOUNT; i += 0.05)
{

x = i * L;			// Equation for per increment to calculate distance (x)

if (0 <= x <= a)
	{
	I = (b * (h * h * h)) / 12;	
	del = ((w * (x * x)) / (24 * E * I)) * ((6 * (a * a)) - (4 * a * x) + (x * x));	// Equation for deflection if 'x' is less than or equal to 'a' and greater than 0
	theta = ((w * x) / (6 * E * I)) * ((3 * (a * a)) - (3 * a * x) + (x * x));		// Equation for slope (rotation) if 'x' is less than or equal to 'a' and greater than 0
		cout << setprecision(4) << x << "        " 		// 'x' is stated up to 4 digits 
         	 << setprecision(10) << del << "      "		// deflection is stated up to 10 digits
         	 << setprecision(10) << theta << endl;		// slope is stated up to 10 digits 
    
    	if (a < x <= L)
    	{
    		continue;
		}
	}
	
if (a < x <= L)
	{
	I = (b * (h * h * h)) / 12;	
	del2 = ((w * (a * a * a)) / (24 * E * I)) * ((4 * x) - a); 	// Equation for deflection if 'x' is less than or equal to 'L' and greater than a
	theta2 = (w * (a * a * a)) / (6 * E * I);					// Equation for slope if 'x' is less than or equal to 'L' and greater than a
		cout << setprecision(4) << x << "        "				// 'x' is stated up to 4 digits
         	 << setprecision(10) << del2 << "      "			// deflection is stated up to 10 digits
         	 << setprecision(10) << theta2 << endl;				// slope is stated up to 10 digits
    	
	}
	
else
	{
		break;
	}	
}       

return 0;
	   
}
