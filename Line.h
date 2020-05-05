#pragma once
#include <string>
#include "Point.h"

class Line {
protected:
Point A;
Point B;

public:
	Line();
	Line(double x1, double y1, double x2, double y2);
	string LineToString();
	double length();
	bool IsPointOnLine(Point pt);
    double getSlope();
	bool IsParallel(Line ln);
	bool Intersect(Line ln);
};
