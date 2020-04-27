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
			Point p3();

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
        REQUIRE_THROWS(Point(1.2, 2.4));
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

