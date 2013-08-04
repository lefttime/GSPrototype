#include <time.h>

#include <QApplication>

#include <Inventor/Qt/SoQt.h>

#include <mainwindow.hpp>

int main(int argc, char* argv[])
{
  QApplication app( argc, argv );

  qsrand( (unsigned int)time( 0 ) );
  MainWindow mainWindow;
  mainWindow.show();

  SoQt::init( &mainWindow );

  return app.exec();
}
