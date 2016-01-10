#include <cppunit/extensions/HelperMacros.h>
#include <Joint.h>

class testjoint :public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(testjoint);
	CPPUNIT_TEST(testjointget);
	//CPPUNIT_TEST(testrotate);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();
	testjoint();
	//~testsolver();
	void testjointget();
	//void testrotate();
};