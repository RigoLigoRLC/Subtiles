#ifndef SUBTILESMAINWINDOW_H
#define SUBTILESMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class SubtilesMainWindow;
}

class SubtilesMainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit SubtilesMainWindow(QWidget *parent = nullptr);
    ~SubtilesMainWindow();

  private slots:
    void on_pushButton_2_clicked();

  private:
    Ui::SubtilesMainWindow *ui;
};

#endif // SUBTILESMAINWINDOW_H
