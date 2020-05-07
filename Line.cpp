#include "Line.h"
#include <iostream>

using namespace std;


Line::Line()
{
    A = Point();
    B = Point(); 
}
Line::Line(double x1, double y1, double x2, double y2)
{
	if (x1 <= x2)
	{
		A = Point(x1, y1);
		B = Point(x2, y2);
	}
	else
	{
		A = Point(x2, y2);
		B = Point(x1, y1);
	}
}

string Line::LineToString()
{
	string retval = "";
	retval += "Point 1: [";
	retval += A.toString();
	retval += "], Point 2: [";
	retval += B.toString();
	retval += "]";

	return  retval;
}

double Line::length()
{
	double x_minus = A.getX() - B.getX();
	double y_minus = A.getY() - B.getY();

	double distance = sqrt(pow(x_minus, 2) + pow(y_minus, 2));

	
	return distance;
}
bool Line::IsPointOnLine(Point pt) {

	bool retVal = false;

	Line l1(A.getX(), A.getY(), pt.getX(), pt.getY());
	Line l2(B.getX(), B.getY(), pt.getX(), pt.getY());

	if (l1.length() + l2.length() == length()) {

		retVal = true;
	}

	return retVal;

}
double Line::getSlope()
{
    double retVal = double(INT_MAX);
    //if it is not a vertical line, we will find the slope
    if(B.getX() - A.getX() != 0)
    {
        retVal = (B.getY() - A.getY()) / (B.getX() - A.getX());
    }
    return retVal;
}

bool Line::IsParallel(Line ln) {

	bool retVal = false;

	double slope1 = this->getSlope();
	double slope2 = ln.getSlope();
    
    if (slope1 == slope2) {
		retVal = true;
	}

	return retVal;
}

bool Line::Intersect(Line ln) {

	bool retVal = false;

	double x = A.getX();
	double y = A.getY();
	double slope = getSlope();
	
	if(slope == INT_MAX){


		while(y <= B.getY()){

			Point mark(x,y);
			if(ln.IsPointOnLine(mark)){

				cout << "The x is: " << x << "     and y is: " << y << endl;
				cout << "B.getX() is: " << B.getX() << endl;
				cout << "The slope is: " << slope << endl << endl;
				retVal = true;
				break;
			}
			
			y += (1.0/10000);
		}
		
	}
	else{

		while(x <= B.getX()){

			Point mark(x,y);
			if(ln.IsPointOnLine(mark)){

				cout << "The x is: " << x << "     and y is: " << y << endl;
				cout << "B.getX() is: " << B.getX() << endl;
				cout << "The slope is: " << slope << endl << endl;
				retVal = true;
				break;
			}
			
			x += 1.0/10000;
			y += slope * (1.0/10000);
			
		}
	}

	return retVal;

}

