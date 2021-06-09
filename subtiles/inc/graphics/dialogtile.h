#ifndef STDIALOGTILEITEM_H
#define STDIALOGTILEITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QScopedPointer>
#include "STDialog.h"

class STDialogTileItem : public QGraphicsRectItem
{
  public:
    STDialogTileItem(const STDialogCPtr);

    void RecomputeRect();

    static double scaleFac;

  private:
    void paint(QPainter *, const QStyleOptionGraphicsItem *,
               QWidget * = 0) override;

  private:
    QGraphicsTextItem m_text;
    STDialogCPtr m_dialog; ///< Associated dialog with this tile being displayed
    QScopedPointer<QPen> m_pen;
};

#endif // STDIALOGTILEITEM_H
