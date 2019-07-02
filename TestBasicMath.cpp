#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "CBasicMath.hpp"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestBasicMath : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestBasicMath);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testSubtraction);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testDivision);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testAddition(void);
    void testSubtraction(void);
    void testMultiply(void);
    void testDivision(void);

private:

    CBasicMath *mTestObj;
};

//-----------------------------------------------------------------------------

void
TestBasicMath::testAddition(void)
{
    CPPUNIT_ASSERT(8 == mTestObj->Addition(2, 3));
}

/*
void
TestBasicMath::testAddition(void)
{
    CPPUNIT_ASSERT(7 == mTestObj->Addition(2, 3));
}
*/
void
TestBasicMath::testSubtraction(void)
{
    CPPUNIT_ASSERT(5 == mTestObj->Subtraction(10, 5));
}

/*
void
TestBasicMath::testSubtraction(void)
{
    CPPUNIT_ASSERT(7 == mTestObj->Addition(12, 3));
}
*/

void
TestBasicMath::testMultiply(void)
{
    CPPUNIT_ASSERT(6 == mTestObj->Multiply(2, 3));
}

void
TestBasicMath::testDivision(void)
{
    CPPUNIT_ASSERT(6 == mTestObj->Division(36, 6));
}

/*
void
TestBasicMath::testDivision(void)
{
    CPPUNIT_ASSERT(7 == mTestObj->Multiply(36, 6));
}
*/

void TestBasicMath::setUp(void)
{
    mTestObj = new CBasicMath();
}

void TestBasicMath::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppTestBasicMathResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

