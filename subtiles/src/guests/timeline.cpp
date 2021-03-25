#include "guests/timeline.h"

STGuestTimeline::STGuestTimeline(QWidget *parent) :
  SubtilesAbstractGuest(tr("Timeline"), parent)
{
  m_view = new STTimelineView(this);
  m_scene = new QGraphicsScene(this);
  m_view->setScene(m_scene);
  setWidget(m_view);

  m_scene->setBackgroundBrush(QBrush(QColor(32, 32, 32)));
}

STGuestTimeline::~STGuestTimeline()
{

}
