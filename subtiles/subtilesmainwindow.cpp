#include "subtilesmainwindow.h"
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
