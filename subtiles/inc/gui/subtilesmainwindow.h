#ifndef SUBTILESMAINWINDOW_H
#define SUBTILESMAINWINDOW_H

#include <QMainWindow>
#include "app/subtilesmainframe.h"

namespace Ui {
  class SubtilesMainWindow;
}

class SubtilesMainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit SubtilesMainWindow(QWidget *parent = nullptr);
    explicit SubtilesMainWindow(uint aMwid, QWidget *parent = nullptr);
    ~SubtilesMainWindow();

  private slots:
    void on_pushButton_2_clicked();

  protected:
    void closeEvent(QCloseEvent *e) override;

  signals:
    void sigWindowClosed(uint who);

  private:
    uint m_mwid;
    Ui::SubtilesMainWindow *ui;
};

#endif // SUBTILESMAINWINDOW_H
