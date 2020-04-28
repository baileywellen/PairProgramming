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
	//double x_minus=
	return 0.0;
}

