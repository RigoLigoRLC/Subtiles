#ifndef TIMELINE_H
#define TIMELINE_H

#include <QGraphicsScene>

#include "guests/uistyleshow.h"
#include "gui/timelineview.h"

class STGuestTimeline : public SubtilesAbstractGuest
{
    Q_OBJECT
  public:
    STGuestTimeline(SubtilesMainFrame *frame, QWidget *parent);
    ~STGuestTimeline();

    STGuestTypeID GetGuestTypeID() override { return STGuestTypeID::Timeline; }

  private:
    STTimelineView *m_view;
    QGraphicsScene *m_scene;

  private:
    bool eventFilter(QObject*, QEvent*) override;
};

#endif // TIMELINE_H
