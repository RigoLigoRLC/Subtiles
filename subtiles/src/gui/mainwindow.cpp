#include <QFile>
#include <QTextStream>
#include <QCloseEvent>

#include "gui/mainwindow.h"


SubtilesMainWindow::SubtilesMainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  m_dockMgr = new ads::CDockManager(this);
}

SubtilesMainWindow::SubtilesMainWindow(uint aMwid, QWidget *parent) :
  SubtilesMainWindow(parent)
{
  m_mwid = aMwid;
}

SubtilesMainWindow::~SubtilesMainWindow()
{
}

void SubtilesMainWindow::closeEvent(QCloseEvent *e)
{
  emit sigWindowClosed(m_mwid);
  e->accept();
}

void SubtilesMainWindow::AddDockWidget(ads::DockWidgetArea aArea, ads::CDockWidget *widget)
{
  m_dockMgr->addDockWidget(aArea, widget);
}
