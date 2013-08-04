#ifndef VIEWER3DHELPER_HPP
#define VIEWER3DHELPER_HPP

#include <QObject>

class Viewer3D;

class Viewer3DHelper : public QObject
{
  Q_OBJECT

public:

  explicit Viewer3DHelper( Viewer3D* target, QObject* parent=0 );
  ~Viewer3DHelper();

private:

  class Viewer3DHelperPrivate;
  QScopedPointer<Viewer3DHelperPrivate>         _pd;
  
};

#endif // VIEWER3DHELPER_HPP
