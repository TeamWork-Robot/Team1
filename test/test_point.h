#include <cppunit/extensions/HelperMacros.h>
#include <Point.h>

class testpoint :public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(testpoint);
	CPPUNIT_TEST(testget);
	//CPPUNIT_TEST(testrotate);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();
	testpoint();
	//~testsolver();
	void testget();
	//void testrotate();
};