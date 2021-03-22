#include "guests/stguestuistyleshow.h"

STGuestUiStyleShow::STGuestUiStyleShow(const QString &title, QWidget *parent) :
  SubtilesAbstractGuest(title, parent),
  ui(new Ui::STGuestUiStyleShow)
{
  m_widget = new QWidget;
  ui->setupUi(m_widget);

  this->setWidget(m_widget);

  m_typeId = STGuestTypeID::UiShow;
}

void STGuestUiStyleShow::on_pushButton_2_clicked()
{
  qApp->setStyleSheet(ui->textEdit->toPlainText());
}

STGuestUiStyleShow::~STGuestUiStyleShow()
{
  delete ui;
  delete m_widget;
}
