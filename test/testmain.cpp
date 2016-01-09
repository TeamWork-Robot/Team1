#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TextOutputter.h>

int main()
{
	CppUnit::TestResult r;
	CppUnit::TestResultCollector rc;
	r.addListener(&rc); // ׼���ý���ռ���

	CppUnit::TestRunner runner; // ����ִ��ʵ��
	runner.addTest(CppUnit::TestFactoryRegistry::getRegistry("alltest").makeTest());
	runner.run(r); // ���в���

	CppUnit::TextOutputter o(&rc, std::cout);
	o.write(); // ��������

	system("pause");

	return rc.wasSuccessful() ? 0 : -1;
}