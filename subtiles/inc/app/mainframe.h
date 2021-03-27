#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QObject>
#include <QList>
#include <QMap>
#include "host.h"
#include "abstractguest.h"
#include "gui/mainwindow.h"

/*
*/
class SubtilesMainWindow;

class SubtilesMainFrame final : public QObject
{
    Q_OBJECT
  private:
    SubtilesHost *m_host;
    QList<SubtilesAbstractGuest *> m_guests;
    QMap<uint, SubtilesMainWindow *> m_windows;

  public slots:
    uint CreateMainWindow();

  private slots:
    void evtMainWindowDestroyed(uint aWho);

  private:
    uint m_mwidTop; ///< MainWindowID top value; doesn't go down; each creation of MainWindow will increase it.

  public:
    SubtilesMainFrame();
    ~SubtilesMainFrame();
};

#endif // MAINFRAME_H
