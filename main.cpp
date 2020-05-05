#include <iostream>
#include "Point.h"
#include "Line.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#define CATCH_CONFIG_RUNNER
using namespace std;



TEST_CASE("Point Tests")
{
	//setup code
	cout << "Before the tests" << endl;

	SECTION("Test Constructor")
	{
		try
		{
			Point p(1,7);
			Point p2(1.7, 1.4);
			Point p3;

			SUCCEED();
		}
		catch (...)
		{
			FAIL();
		}
	}

    SECTION("Test Negative Input")
    {
        REQUIRE_THROWS(Point(-2.4, 1.0));
        REQUIRE_THROWS(Point(3.4, -2.1));
        REQUIRE_THROWS(Point(-2.7, -7.8));
    }

    SECTION("Test String Representation")
    {
        Point p(2.3, 3.4);
        REQUIRE("X: 2.300000, Y: 3.400000" == p.toString());

        Point p2;
        REQUIRE("X: 0.000000, Y: 0.000000" == p2.toString());

        Point p3(1,2);
        REQUIRE("X: 1.000000, Y: 2.000000" == p3.toString());
		
	
    }


	SECTION("Test member functions")
	{
		Point p4(4.0, 5.0);
		REQUIRE(p4.getX() == 4.0);
		REQUIRE(p4.getY() == 5.0);
	}



	SECTION("Test Line Class Constructors")
	{
		try {
			Line l1;
			Line l2(1, 2, 3, 4);
	
			SUCCEED();
			
		}
		catch(...)
		{
			FAIL();
		}
	}
	SECTION("Test Negative Line Input")
	{
		Line l1(1,2,3,4);
		REQUIRE_THROWS(Line(-1, 2, 3, 4));
		REQUIRE(l1.LineToString() == "Point 1: [X: 1.000000, Y: 2.000000], Point 2: [X: 3.000000, Y: 4.000000]");
	}
	SECTION("Test line.length()")
	{
		Line l1(1, 1, 2, 2);
		REQUIRE(l1.length() == sqrt(2));

	}
	SECTION("Test line.IsPointOnLine()") {

		Line l1(1, 1, 3, 3);
		REQUIRE(l1.IsPointOnLine(Point(2, 2)) == true);

		REQUIRE(l1.IsPointOnLine(Point(1, 2)) == false);
	}
    SECTION("Test getSlope()")
    {
        Line l1(1,1,2,2);
        REQUIRE(l1.getSlope() == 1);

        Line l2(1,1,1,4);
        REQUIRE(l2.getSlope() == double(INT_MAX));

        Line l3(1,1,3,1);
        REQUIRE(l3.getSlope() == 0);

        Line l4(4,4,8,0);
        REQUIRE(l4.getSlope() == -1);
    }
	SECTION("Test line.IsParallel()") {

		Line l1(1, 1, 3, 3);
		REQUIRE(l1.IsParallel(Line(2, 2, 3, 3)) == true);

		REQUIRE(l1.IsParallel(Line(1, 3, 2, 5)) == false);


	}
	SECTION("Test line.Intersect()") {

		Line l1(1, 1, 10, 10);
		Line l2(1, 10, 10, 1);

		REQUIRE(l1.Intersect(l2) == true);
		REQUIRE(l1.Intersect(l1) == true);
		REQUIRE(l1.Intersect(Line(2, 2, 11, 11)) == false);

	}
    system("pause");

    
}

/*int main(int argc, char* argv[])
{
    Catch::Session session;
    int result = Catch::Session().run( argc, argv );

    system("pause");
    return 0;
}*/

