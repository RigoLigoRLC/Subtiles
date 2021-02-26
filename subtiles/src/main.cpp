#include "gui/subtilesmainwindow.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QSplashScreen splash(QPixmap(":splashes/splash/subtiles-splash.png"));
  splash.show();

  SubtilesMainWindow w;
  w.show();

  //splash.finish(&w);

  return a.exec();
}
