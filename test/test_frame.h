#include <cppunit/extensions/HelperMacros.h>
#include <Point.h>
#include <Frame.h>

class testframe :public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(testframe);
	CPPUNIT_TEST(testframeget);
	//CPPUNIT_TEST(testrotate);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp();
	void tearDown();
	testframe();
	//~testsolver();
	void testframeget();
	//void testrotate();
};