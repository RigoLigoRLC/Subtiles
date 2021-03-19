#include <QFile>
#include <QTextStream>
#include <QCloseEvent>

#include "gui/subtilesmainwindow.h"
#include "ui_subtilesmainwindow.h"

SubtilesMainWindow::SubtilesMainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::SubtilesMainWindow)
{
  ui->setupUi(this);

  QFile file(":/styles/styles/standard/standard.qss");
  QTextStream stream(&file);
  QString stylesheet = stream.readAll();
  ui->textEdit->setPlainText(stylesheet);
  qApp->setStyleSheet(stylesheet);
}

SubtilesMainWindow::SubtilesMainWindow(uint aMwid, QWidget *parent) :
  SubtilesMainWindow(parent)
{
  m_mwid = aMwid;
}

SubtilesMainWindow::~SubtilesMainWindow()
{
  delete ui;
}

void SubtilesMainWindow::on_pushButton_2_clicked()
{
  qApp->setStyleSheet(ui->textEdit->toPlainText());
}

void SubtilesMainWindow::closeEvent(QCloseEvent *e)
{
  emit sigWindowClosed(m_mwid);
  e->accept();
}
