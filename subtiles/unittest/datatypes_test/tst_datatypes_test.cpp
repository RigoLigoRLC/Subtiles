#include <QtTest>
#include "STTimecode.h"

// add necessary includes here

class datatypes_test : public QObject
{
    Q_OBJECT

  public:
    datatypes_test();
    ~datatypes_test();

  private slots:
    void testTimecodeOutput();
    void testTimecodePlus();

};

datatypes_test::datatypes_test()
{

}

datatypes_test::~datatypes_test()
{

}

void datatypes_test::testTimecodeOutput()
{
  STTimecode tc1(1234, 56, 7, 8901),
      tc2;
  QVERIFY(tc1.GetASSTimecode() == "1234:56:07.8901");
  QVERIFY(tc2.GetASSTimecode() == "00:00:00.0000");
}

void datatypes_test::testTimecodePlus()
{
  STTimecode tc1(0, 59, 59, 9999), tc2(1, 2, 2, 2);
  STTimecode tcr = tc1 + tc2;
  QVERIFY(tcr == STTimecode(2, 2, 2, 1));
}

QTEST_APPLESS_MAIN(datatypes_test)

#include "tst_datatypes_test.moc"
