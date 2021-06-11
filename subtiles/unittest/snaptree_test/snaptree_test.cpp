#include <QtTest/QtTest>
#include <QVector>
#include "STSnapTree.h"

using std::make_shared;
using std::get;

class snaptree_test : public QObject
{
  Q_OBJECT

  public:
    snaptree_test();
    ~snaptree_test();

  private:
    STSnapTree tree;
    QVector<STDialogPtr> dialogs;

    void checkhead(STSnapTree::SnapResult r, int i);

    void checktail(STSnapTree::SnapResult r, int i);

  private slots:

    void initTestCase();
    void cleanupTestCase();


    void insert_head_occupied();
    void snap_to_tail();
    void snap();
};

snaptree_test::snaptree_test()
{

}
snaptree_test::~snaptree_test()
{
}

void snaptree_test::initTestCase()
{
  STDialogPtr d;

  d = make_shared<STDialog>();
  d->Begin = 0; d->Duration = 2000;
  QVERIFY(tree.InsertTile(d) < STSnapTree::Fail);
  dialogs.push_back(d);

  d = make_shared<STDialog>();
  d->Begin = 8000; d->Duration = 2000;
  QVERIFY(tree.InsertTile(d) < STSnapTree::Fail);
  dialogs.push_back(d);

  d = make_shared<STDialog>();
  d->Begin = 4000; d->Duration = 2000;
  QVERIFY(tree.InsertTile(d) < STSnapTree::Fail);
  dialogs.push_back(d);

  d = make_shared<STDialog>();
  d->Begin = 2000; d->Duration = 2000;
  QVERIFY(tree.InsertTile(d) < STSnapTree::Fail);
  dialogs.push_back(d);

  d = make_shared<STDialog>();
  d->Begin = 6500; d->Duration = 500;
  QVERIFY(tree.InsertTile(d) < STSnapTree::Fail);
  dialogs.push_back(d);
}

void snaptree_test::cleanupTestCase()
{
  foreach(STDialogPtr i, dialogs)
  {
    QCOMPARE(tree.DeleteTile(i->Begin), STSnapTree::Success);
  }
}

void snaptree_test::insert_head_occupied()
{
  STDialogPtr w = make_shared<STDialog>();
  w->Begin = 0;
  w->Duration = 200;
  QCOMPARE(tree.InsertTile(w), STSnapTree::FailOccupied);
}

void snaptree_test::snap_to_tail()
{
  STSnapTree::SnapResult r;
  int count = 0;

  r = tree.SnapTail(0);
  checktail(r, 0); // 1
  r = tree.SnapTail(19);
  checktail(r, 0); // 2
  r = tree.SnapTail(3000); // When distance equals, snap to left side
  checktail(r, 0); // 3
  r = tree.SnapTail(3001);
  checktail(r, 3); // 4
  r = tree.SnapTail(3999);
  checktail(r, 3); // 5
  r = tree.SnapTail(4001);
  checktail(r, 3); // 6
  r = tree.SnapTail(5000);
  checktail(r, 3); // 7
  r = tree.SnapTail(5001);
  checktail(r, 2); // 8
  r = tree.SnapTail(6499);
  checktail(r, 2); // 9
}

void snaptree_test::snap()
{
  STSnapTree::SnapResult r;

  r = tree.Snap(0);
  checkhead(r, 0);
  r = tree.Snap(1000);
  checktail(r, 0);
  r = tree.Snap(1001);
  checktail(r, 0);
  r = tree.Snap(2001);
  checkhead(r, 3);
  r = tree.Snap(3000);
  checktail(r, 3);

}

void snaptree_test::checkhead(STSnapTree::SnapResult r, int i)
{
  QVERIFY(get<0>(r) < STSnapTree::Fail);
  QCOMPARE(get<1>(r), dialogs[i]->Begin);
  //qInfo("%d PASS", count);
}

void snaptree_test::checktail(STSnapTree::SnapResult r, int i)
{
  QVERIFY(get<0>(r) < STSnapTree::Fail);
  QCOMPARE(get<1>(r), dialogs[i]->Begin + dialogs[i]->Duration);
}

QTEST_APPLESS_MAIN(snaptree_test)

#include "snaptree_test.moc"
