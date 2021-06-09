#include <QtTest>
#include "STSnapTree.h"

class snaptree_test : public QObject
{
  Q_OBJECT

  public:
    snaptree_test();
    ~snaptree_test();

  private slots:

};

snaptree_test::snaptree_test()
{

}

snaptree_test::~snaptree_test()
{

}

QTEST_APPLESS_MAIN(snaptree_test)

#include "snaptree_test.moc"
