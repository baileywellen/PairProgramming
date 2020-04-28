#pragma once
#include <string>
#include "Point.h"

class Line {
private:
Point A;
Point B;

public:
	Line();
	Line(double x1, double y1, double x2, double y2);

};
