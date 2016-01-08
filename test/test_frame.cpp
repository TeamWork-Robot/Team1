#include "test_frame.h"
#include "Point.h"
#include "Frame.h"
#include <string>
#include<iostream>
#include <cppunit/TestCase.h>
#include "cppunit/TestAssert.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(testframe, "alltest");

testframe::testframe()
{
};

void testframe::setUp()
{
	std::cout << "test frame begin" << std::endl;
};

void testframe::tearDown()
{
	std::cout << "test frame end" << std::endl;
};

void testframe::testframeget()
{
	Point point1(3, 4);
	double a = 0.0;
	Frame frame1(point1,a);
	int resultx = frame1.getPoint().getX();
	//int resulty = point1.getY();
	//int c = result.getX()
	CPPUNIT_ASSERT(resultx == 3);
	//CPPUNIT_ASSERT(result.getY() == 4);
}