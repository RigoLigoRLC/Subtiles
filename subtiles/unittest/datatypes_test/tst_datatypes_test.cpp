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

};

datatypes_test::datatypes_test()
{

}

datatypes_test::~datatypes_test()
{

}

QTEST_APPLESS_MAIN(datatypes_test)

#include "tst_datatypes_test.moc"
