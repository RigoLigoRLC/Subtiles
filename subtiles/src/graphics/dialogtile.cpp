#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include "graphics/dialogtile.h"
#include "utils/color.h"

double STDialogTileItem::scaleX = 1, STDialogTileItem::scaleY = 1;
STTimelineView *STDialogTileItem::s_view = nullptr;

STDialogTileItem::STDialogTileItem(const STDialogCPtr aDialog) :
  m_text()
{
  m_dialog = aDialog;
  m_text.setPlainText(aDialog->Text);
  m_text.setFlag(GraphicsItemFlag::ItemIgnoresTransformations);
  QPen p = pen();
  p.setCosmetic(true); // Cosmetic Pen is always 1px, border shouldn't be zoomed
  setPen(p);
  QBrush b = brush();
  b.setColor(QColor(200, 100, 100, 192)); // TODO: real background color
  b.setStyle(Qt::BrushStyle::SolidPattern);
  setBrush(b);
  setPos(-2, -2);
  RecomputeRect();
}

void STDialogTileItem::RecomputeRect()
{
  // FIXME: determine Y position by parent track position
  setRect(0, 0, m_dialog->Duration / 1000, 10);

  setPos(QPointF(m_dialog->Begin / 1000, 0));
  //m_text.setPos(mapToParent(1,1));
}

void STDialogTileItem::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget)
{
  QGraphicsRectItem::paint(painter, option, widget); // Paint rect first
  if(rect().width() * this->scaleX > TextLodWidthThreshold) // Draw only when tile is wide enough
  {
    painter->save();
    painter->setWorldTransform(deviceTransform(QTransform())); // Clear scaling this way
    QPen p;
    p.setColor(STUtil::BWBackground(Qt::black)); //TODO: Real backgorund color
    painter->setPen(p);
    QRectF r = rect(), c;
    c.setTopLeft(s_view->mapFromScene(pos()) - pos()
                 + QPointF{TextLodWidthThreshold, 0});
    // FIXME:I don't know why I must minus the original x coordinate but it works this way :/
    c.setBottomRight(s_view->mapFromScene(r.bottomRight())
                     + c.topLeft() - QPointF{TextLodWidthThreshold, 0});
    // Minus one pixel out, so it doesn't stick to the edge
    painter->drawText(c, Qt::TextWrapAnywhere, m_dialog->Text);
    painter->restore();
  }
}
