#ifndef STDIALOGTILEITEM_H
#define STDIALOGTILEITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QScopedPointer>
#include "STDialog.h"
#include "graphics/timelineview.h"

class STDialogTileItem : public QGraphicsRectItem
{
  public:
    STDialogTileItem(const STDialogCPtr);

    void RecomputeRect();

    static double scaleX, scaleY;

  private:
    void paint(QPainter *, const QStyleOptionGraphicsItem *,
               QWidget * = 0) override;

  private:
    QGraphicsTextItem m_text;
    STDialogCPtr m_dialog; ///< Associated dialog with this tile being displayed
    QScopedPointer<QPen> m_pen;
    QColor m_bgcolor;

    static STTimelineView *s_view; ///< Set by only view on initialization
    friend class STTimelineView;

  private:
    static constexpr int TextLodWidthThreshold = 12;
};

#endif // STDIALOGTILEITEM_H
