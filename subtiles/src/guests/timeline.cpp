#include <QWheelEvent>
#include <QtMath>
#include "guests/timeline.h"
#include "gui/dialogtile.h"
#include "app/mainframe.h"

STGuestTimeline::STGuestTimeline(SubtilesMainFrame *frame, QWidget *parent) :
  SubtilesAbstractGuest(frame, tr("Timeline"), parent)
{
  m_view = new STTimelineView(this);
  m_scene = new QGraphicsScene(this);
  m_view->setScene(m_scene);

  m_view->viewport()->installEventFilter(this);

  setWidget(m_view);

  m_scene->setBackgroundBrush(QBrush(QColor(32, 32, 32)));

  for(int i = 0; i < 5; i++)
  {
    auto a = std::make_shared<STDialog>();
    a->begin = i * 50000;
    a->duration = 50000;
    a->text = QString("Text%1").arg(i);
    m_scene->addItem(new STDialogTileItem(a));
  }


/*
  auto brushWhite = new QBrush;
  brushWhite->setColor(Qt::white);
  brushWhite->setStyle(Qt::SolidPattern);
  auto penBlack = new QPen;
  penBlack->setColor(Qt::black);

  for(int i = 0; i < 100; i++)
  {
    QGraphicsRectItem *rect = new QGraphicsRectItem;
    rect->setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    rect->setRect(i * 150, -10, 10, 20);
    rect->setBrush(*brushWhite);

#if 1
    QGraphicsTextItem *text = new QGraphicsTextItem(rect);
    text->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    text->setPlainText("Helloworld!");
    text->setDefaultTextColor(Qt::black);
    text->setPos(i * 150, 0);
#endif
    m_scene->addItem(rect);
  }
*/

  m_view->centerOn(0, 0);

  m_view->Scale(10, 5);
}

STGuestTimeline::~STGuestTimeline()
{

}

bool STGuestTimeline::eventFilter(QObject *aWatched, QEvent *aEvent)
{
  switch(aEvent->type())
  {
    case QEvent::Wheel:
    {
      if(aWatched == m_view->viewport())
      {
        QWheelEvent *e = dynamic_cast<QWheelEvent*>(aEvent);
        if(!e) return false;
        m_view->Scale(pow(4, e->angleDelta().y() / 240.0), 1);
        return false;
      }
      return false;
      break;
    }
    default:
      return false;
      break;
  }
}
