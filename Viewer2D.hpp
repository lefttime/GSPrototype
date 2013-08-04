#ifndef VIEWER2D_HPP
#define VIEWER2D_HPP

#include <AbstractViewer.hpp>

class Viewer2D : public AbstractViewer
{
  Q_OBJECT;
  
public:

  explicit Viewer2D( QWidget* parent=0, Qt::WindowFlags flags=0 );
  ~Viewer2D();

protected:

  virtual void doDragEnter( QDragEnterEvent* event );
  virtual void doDropEvent( QDropEvent* event );

private:

  class Viewer2DPrivate;
  QScopedPointer<Viewer2DPrivate>         _pd;
};

#endif // VIEWER2D_HPP
