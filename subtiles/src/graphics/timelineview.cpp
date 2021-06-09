#include <QBrush>
#include <QStyle>
#include <QPen>

#include "graphics/timelineview.h"
#include "graphics/dialogtile.h"

STTimelineView::STTimelineView(QWidget *parent) :
  QGraphicsView(parent)
{
  setDragMode(DragMode::RubberBandDrag); // Default rubber band drag (select)
  setAlignment(Qt::AlignTop | Qt::AlignLeft);
  setTransformationAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
  setContentsMargins(-2, -2, -2, -2);

  Q_ASSERT(STDialogTileItem::s_view == nullptr);
  STDialogTileItem::s_view = this; // Tell tiles about the view
}

void STTimelineView::Scale(double x, double y)
{
  //resetTransform();
  scale(x, y);
  STDialogTileItem::scaleX *= x;
  STDialogTileItem::scaleY *= y;
}
