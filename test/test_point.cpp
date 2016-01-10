#include "test_point.h"
#include "Point.h"
#include <string>
#include<iostream>
#include <cppunit/TestCase.h>
#include "cppunit/TestAssert.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(testpoint, "alltest");

testpoint::testpoint()
{
};

void testpoint::setUp()
{
	std::cout << "test begin" << std::endl;
};

void testpoint::tearDown()
{
	std::cout << "test end" << std::endl;
};

void testpoint::testget()
{
	Point point1(3, 4);
	int resultx = point1.getX();
	int resulty = point1.getY();
	CPPUNIT_ASSERT(resultx == 3);
	CPPUNIT_ASSERT(resulty == 4);
}