//***********************
// Name:  Tyra McCoy
// Purpose: Homework 3
// Date:  09/28/16
// Reference:  Chapter 3, 4
//***********************


// This program will calculate and display the area of a rectangular or elliptical area 
// given dimensions of the length and width (rectangle) or minor and major axis. Using the area calculated, 
// this program can also calculate the heat transfer rate using a constant convective heat transfer
// coefficient of 2.8 W/m^2*Celsius given the surface temperature and ambient temperature.


#include <iostream>
#include <iomanip>
#include <cmath>               
using namespace std;

int main ()
{
char shape;
double l, w, major, minor, Ts, Ta, t, AIRCONV, q, A;

cout << "Enter a (rectangular area), b (elliptical area), or c (other shapes) for the surface type: ";
cin >> shape;

if (shape == 'a')
{
cout << "Enter the length of the rectangle in meters or feet: ";	// Enter length of rectangle
cin >> l;
cout << "Enter the width of the rectangle in meters or feet: ";		// Enter width of rectangle
cin >> w;
A = l * w;															// Area = length * width
cout << setiosflags(ios:: fixed)
<< setiosflags(ios::showpoint)
<< setprecision(4)
<< "The surface area of the rectangle is: " << A << " m^2 or ft^2" << endl;
}

else if (shape == 'b')
{
cout << "Enter the major axis of the ellipse in meters or feet: ";		// Enter length of major axis of ellipse 
cin >> major;
cout << "Enter the minor axis of the ellipse meters or feet: ";			// Enter length of minor axis of ellipse 
cin >> minor;
A = 3.1416 * major * minor;												// Area = pi*major axis*minor axis
cout << setiosflags(ios:: fixed)
<< setiosflags(ios::showpoint)
<< setprecision(4)
<< "The surface area of the ellipse is: " << A << " m^2 or ft^2" << endl;
}

else if (shape == 'c')
{
cout << "Enter the surface area of the shape: ";		// Enter surface area of non-elliptical/ non-rectangular shape 
cin >> A;
}

if (shape == 'a'||  shape == 'b'||  shape == 'c')
	{
	cout << "Enter surface temperature: ";				// Enter surface temperature of shape	
	cin >> Ts;
	cout << "Enter ambient temperature: ";				// Enter ambient temperature of shape
	cin >> Ta;
	t = Ts - Ta;
	AIRCONV = 2.8;
	q = AIRCONV * A * t;								// q = hA(Ts-Ta)
	cout << "The heat transfer rate of the rectangular area is: " << q << " W or J/s" << endl;
	}

else													// For all values other than a,b, and c
{
cout << "An invalid shape was entered.";
cout << endl;
}


return 0;
}

