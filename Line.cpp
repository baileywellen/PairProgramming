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
