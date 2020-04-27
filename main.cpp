#include <iostream>
#include "Point.h"
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

    system("pause");

    
}

/*int main(int argc, char* argv[])
{
    Catch::Session session;
    int result = Catch::Session().run( argc, argv );

    system("pause");
    return 0;
}*/

