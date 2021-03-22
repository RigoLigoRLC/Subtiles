#include "guests/stguestuistyleshow.h"

STGuestUiStyleShow::STGuestUiStyleShow(const QString &title, QWidget *parent) :
  SubtilesAbstractGuest(title, parent),
  ui(new Ui::STGuestUiStyleShow)
{
  ui->setupUi(this);

  m_typeId = STGuestTypeID::UiShow;
}

void STGuestUiStyleShow::on_pushButton_2_clicked()
{
  qApp->setStyleSheet(ui->textEdit->toPlainText());
}

STGuestUiStyleShow::~STGuestUiStyleShow()
{
  delete ui;
}
