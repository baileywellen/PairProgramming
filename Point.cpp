#include "Point.h"


Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double x_val, double y_val)
{
    if(x_val < 0 || y_val < 0)
    {
        throw "Only values in the first quadrant allowed";
    }
    x = x_val; 
    y = y_val;
}
 
 string Point::toString()
 {
     string ret_val = "X: " + to_string(x) + ", Y: " + to_string(y);
     return ret_val;
 }

 double Point::getX()
 {
	 return x;
 }

 double Point::getY()
 {
	 return y;
 }
