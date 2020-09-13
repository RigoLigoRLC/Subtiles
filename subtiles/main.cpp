#include "subtilesmainwindow.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QSplashScreen splash(QPixmap(":splashes/subtiles-splash.svg"));
  splash.show();

  SubtilesMainWindow w;
  w.show();

  splash.finish(&w);

  return a.exec();
}
