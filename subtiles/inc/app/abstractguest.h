#ifndef ABSTRACTGUEST_H
#define ABSTRACTGUEST_H

#include <QWidget>
#include "DockWidget.h"

enum class STGuestTypeID : int
{
  Invalid = -1,
  UiShow, Timeline
};

class SubtilesAbstractGuest : public ads::CDockWidget
{
  Q_OBJECT
  public:
    SubtilesAbstractGuest(const QString &title, QWidget *parent) : ads::CDockWidget(title, parent) {};
    virtual STGuestTypeID GetGuestTypeID() = 0;

  protected:
    STGuestTypeID m_typeId;
    QWidget *m_widget; ///< Real widget, convenience for UI designer designed ones
};

#endif // ABSTRACTGUEST_H
