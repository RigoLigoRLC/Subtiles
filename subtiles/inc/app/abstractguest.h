#ifndef ABSTRACTGUEST_H
#define ABSTRACTGUEST_H

#include <QWidget>
#include "DockWidget.h"
#include "DockWidgetTab.h"
#include "app/commander.h"

class SubtilesMainFrame;

enum class STGuestTypeID : int
{
  Invalid = -1,
  UiShow, Timeline
};

class SubtilesAbstractGuest : public ads::CDockWidget
{
  Q_OBJECT
  public:
    SubtilesAbstractGuest(SubtilesMainFrame *frame, const QString &title, QWidget *parent) :
      ads::CDockWidget(title, parent)
    {
      m_frame = frame;
      //tabWidget()->setElideMode(Qt::ElideNone);
    };
    virtual STGuestTypeID GetGuestTypeID() = 0;

  protected:
    STGuestTypeID m_typeId;
    QWidget *m_widget; ///< Real widget, convenience for UI designer designed ones
    SubtilesMainFrame *m_frame;
    SubtilesCommander *m_cmd;
};

#endif // ABSTRACTGUEST_H
