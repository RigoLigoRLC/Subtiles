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
    painter->resetTransform(); // Reset painter coordinates so we can draw text untransformed
    QPen p; // Color of text
    p.setColor(STUtil::BWBackground(Qt::black)); //TODO: Real backgorund color, requires Tracks
    painter->setPen(p);
    QSizeF size_ = rect().size();
    size_.rwidth() *= scaleX; // QSize doesn't have a function to scale by factor on axis so...
    size_.rheight() *= scaleY;
    QRectF c(s_view->mapFromScene(pos()), size_); // Area where text is rendered
    c.setLeft(c.left() + TextLodWidthThreshold); // Move right a bit, we'll have some status here
    if(c.left() < 0) c.setLeft(0); // Ensure the text is always visible even TL corner is invisible
    if(c.top() < 0) c.setTop(0);
    painter->drawText(c, Qt::TextWordWrap, m_dialog->Text); // TODO: Text render modes selectable
  }
}
