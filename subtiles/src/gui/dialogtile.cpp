#include <QPainter>
#include <QGraphicsScene>
#include "gui/dialogtile.h"

double STDialogTileItem::scaleFac = 1;

STDialogTileItem::STDialogTileItem(std::shared_ptr<STDialog> aDialog) :
  m_text(this)
{
  m_dialog = aDialog;
  m_text.setPlainText(aDialog->text);
  m_text.setFlag(GraphicsItemFlag::ItemIgnoresTransformations);
  QPen p = pen();
  p.setCosmetic(true); // Cosmetic Pen is always 1px, borders shouldn't be zoomed
  setPen(p);
  QBrush b = brush();
  b.setColor(QColor(200, 100, 100, 192));
  b.setStyle(Qt::BrushStyle::SolidPattern);
  setBrush(b);
  setPos(-2, -2);
  RecomputeRect();
}

void STDialogTileItem::RecomputeRect()
{
  // FIXME: determine Y position by parent track position
  setRect(0, 0, m_dialog->duration / 1000, 10);

  setPos(QPointF(m_dialog->begin / 1000, 0));
  //m_text.setPos(mapToParent(1,1));
}

void STDialogTileItem::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget)
{
  QGraphicsRectItem::paint(painter, option, widget); // Paint rect first
  //if() // If it's wide enough, then draw text. LOD measures
  {
    //m_text.paint(painter, option, widget);
  }
}
