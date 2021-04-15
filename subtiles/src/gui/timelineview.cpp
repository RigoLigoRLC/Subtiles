#include <QBrush>
#include <QStyle>
#include <QPen>

#include "gui/timelineview.h"
#include "gui/dialogtile.h"

STTimelineView::STTimelineView(QWidget *parent) :
  QGraphicsView(parent)
{
  setDragMode(DragMode::RubberBandDrag); // Default rubber band drag (select)
  setAlignment(Qt::AlignTop | Qt::AlignLeft);
  setTransformationAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
  setContentsMargins(-2, -2, -2, -2);
}

void STTimelineView::Scale(double x, double y)
{
  //resetTransform();
  scale(x, y);
  STDialogTileItem::scaleFac = x;
}
