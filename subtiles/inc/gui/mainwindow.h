#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "DockManager.h"

namespace Ui {
  class SubtilesMainWindow;
}

class SubtilesMainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit SubtilesMainWindow(QWidget *parent = nullptr);
    explicit SubtilesMainWindow(uint aMwid, QWidget *parent = nullptr);
    ~SubtilesMainWindow() override;

    void AddDockWidget(ads::DockWidgetArea a, ads::CDockWidget *w);

  protected:
    void closeEvent(QCloseEvent *e) override;

  signals:
    void sigWindowClosed(uint who);

  private:
    uint m_mwid;
    Ui::SubtilesMainWindow *ui;
    ads::CDockManager *m_dockMgr;
};

#endif // MAINWINDOW_H
