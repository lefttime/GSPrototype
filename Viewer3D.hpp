#ifndef VIEWER3D_HPP
#define VIEWER3D_HPP

#include <AbstractViewer.hpp>

class Viewer3D : public AbstractViewer
{
  Q_OBJECT;
  
public:

  explicit Viewer3D( QWidget* parent=0, Qt::WindowFlags flags=0  );
  ~Viewer3D();

protected:

  virtual void doDragEnter( QDragEnterEvent* event );
  virtual void doDropEvent( QDropEvent* event );
  
private:

  class Viewer3DPrivate;
  QScopedPointer<Viewer3DPrivate>         _pd;
};

#endif // VIEWER3D_HPP
