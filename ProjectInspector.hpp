#ifndef PROJECTINSPECTOR_HPP
#define PROJECTINSPECTOR_HPP

#include <AbstractDockWidget.hpp>

class ProjectInspector : public AbstractDockWidget
{
  Q_OBJECT;
  
public:

  explicit ProjectInspector( const QString& workspace, QWidget* parent=0 );
  ~ProjectInspector();

  QDockWidget* widget();

protected:

  virtual bool eventFilter( QObject* obj, QEvent* event );
  
private:

  class ProjectInspectorPrivate;
  QScopedPointer<ProjectInspectorPrivate>         _pd;
};

#endif // PROJECTINSPECTOR_HPP
