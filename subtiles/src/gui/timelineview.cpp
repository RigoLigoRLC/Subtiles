#include <QBrush>
#include <QStyle>

#include "gui/timelineview.h"

STTimelineView::STTimelineView(QWidget *parent) :
  QGraphicsView(parent)
{
  setDragMode(DragMode::RubberBandDrag); // Default rubber band drag (select)
}
