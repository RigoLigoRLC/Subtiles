#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QGraphicsView>

class STTimelineView : public QGraphicsView
{
    Q_OBJECT
  public:
    STTimelineView(QWidget *parent);
    void Scale(double x, double y);
  private:

};

#endif // TIMELINEVIEW_H
