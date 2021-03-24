#include "gui/mainwindow.h"
#include "app/mainframe.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QSplashScreen splash(QPixmap(":splashes/splash/subtiles-splash.png"));
  splash.show();

  SubtilesMainFrame frame;

  //splash.finish(&w);

  return a.exec();
}
