#ifndef APPHELPER_HPP
#define APPHELPER_HPP

#include <QObject>

class MainWindow;

class AppHelper : public QObject
{
  Q_OBJECT;

public:

  explicit AppHelper( MainWindow* target, QObject* parent=0 );
  ~AppHelper();

  void create2DWindow();
  void create3DWindow();

private:

  class AppHelperPrivate;
  QScopedPointer<AppHelperPrivate>         _pd;
  
};

#endif // APPHELPER_HPP
