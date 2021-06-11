#include "guests/uistyleshow.h"

STGuestUiStyleShow::STGuestUiStyleShow(SubtilesMainFrame *frame,
                                       const QString &title, QWidget *parent) :
  SubtilesAbstractGuest(frame, title, parent),
  ui(new Ui::STGuestUiStyleShow)
{
  m_widget = new QWidget;
  ui->setupUi(m_widget);

  this->setWidget(m_widget);

  m_typeId = STGuestTypeID::UiShow;

  connect(ui->pushButton_2, &QPushButton::clicked,
          this, &STGuestUiStyleShow::on_pushButton_2_clicked);

  QFile ObtainStylesheet;
  ObtainStylesheet.setFileName(":/styles/styles/standard/standard.qss");
  ObtainStylesheet.open(QIODevice::ReadOnly);
  auto stylesheet = ObtainStylesheet.readAll();
  ui->textEdit->setPlainText(stylesheet);
  qApp->setStyleSheet(stylesheet);
  ObtainStylesheet.close();
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
