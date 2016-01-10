#include "test_joint.h"
#include "Joint.h"
#include <string>
#include<iostream>
#include <cppunit/TestCase.h>
#include "cppunit/TestAssert.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(testjoint, "alltest");

testjoint::testjoint()
{
};

void testjoint::setUp()
{
	std::cout << "test joint begin" << std::endl;
};

void testjoint::tearDown()
{
	std::cout << "test joint end" << std::endl;
};

void testjoint::testjointget()
{
	Joint joint1(3, 4);
	double a = joint1.getDeg1();
	//int resulty = point1.getY();
	//int c = result.getX()
	CPPUNIT_ASSERT(a == 3.0);
	//CPPUNIT_ASSERT(result.getY() == 4);
}