#include <string>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double x_val, double y_val);
    string toString();

};