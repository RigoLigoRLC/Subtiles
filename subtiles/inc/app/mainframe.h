#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QScopedPointer>
#include "host.h"
#include "abstractguest.h"
#include "gui/mainwindow.h"
#include "STDataOperator.h"

/*
*/
class SubtilesMainWindow;

/**
 * @brief The SubtilesMainFrame is the entire foundation of the application.
 *        It hosts the Host instance (data center), and Guest instances
 *        (different GUI docks), and all the communication between Guests and
 *        Host, basically like a model-view structure. MainWindows are also
 *        managed by MainFrame.
 */
class SubtilesMainFrame final : public QObject
{
    Q_OBJECT

    friend class STDataOperator;

  private:
    SubtilesHost *m_host;
    QList<SubtilesAbstractGuest *> m_guests;
    QMap<uint, SubtilesMainWindow *> m_windows;

  public slots:
    uint CreateMainWindow();

  private slots:
    void evtMainWindowDestroyed(uint aWho);

  private:
    // MainWindowID top value; doesn't go down; each creation of MainWindow
    // will increase it.
    uint m_mwidTop;

  public:
    SubtilesMainFrame();
    ~SubtilesMainFrame();
};

#endif // MAINFRAME_H
