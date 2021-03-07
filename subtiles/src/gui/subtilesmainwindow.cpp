#include <QFile>

#include "gui/subtilesmainwindow.h"
#include "ui_subtilesmainwindow.h"

SubtilesMainWindow::SubtilesMainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::SubtilesMainWindow)
{
  ui->setupUi(this);

}

SubtilesMainWindow::~SubtilesMainWindow()
{
  delete ui;
}

void SubtilesMainWindow::on_pushButton_2_clicked()
{
  qApp->setStyleSheet(ui->textEdit->toPlainText());
}
