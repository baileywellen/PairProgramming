#include "Line.h"


Line::Line()
{
    A = Point();
    B = Point(); 
}
Line::Line(double x1, double y1, double x2, double y2)
{
	A = Point(x1, y1);
	B = Point(x2, y2);
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

	//Code is still needed here


	return retVal;

}

