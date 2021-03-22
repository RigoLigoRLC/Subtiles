#ifndef STGUESTUISTYLESHOW_H
#define STGUESTUISTYLESHOW_H

#include "app/subtilesabstractguest.h"
#include "ui_guest_uistyleshow.h"

namespace Ui {
  class STGuestUiStyleShow;
}

class STGuestUiStyleShow : public SubtilesAbstractGuest
{
    Q_OBJECT
  public:
    explicit STGuestUiStyleShow(const QString &title, QWidget *parent = nullptr);
    ~STGuestUiStyleShow();

    STGuestTypeID GetGuestTypeID() override { return m_typeId; }

  private slots:
    void on_pushButton_2_clicked();

  private:
    Ui::STGuestUiStyleShow *ui;
};

#endif // STGUESTUISTYLESHOW_H
