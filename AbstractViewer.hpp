#ifndef ABSTRACTVIEWER_HPP
#define ABSTRACTVIEWER_HPP

#include <QWidget>

#include <QMimeData>
#include <QDropEvent>
#include <QDragEnterEvent>

class QVector3D;

class AbstractViewer : public QWidget
{
  Q_OBJECT;

public:

  explicit AbstractViewer( QWidget* parent=0, Qt::WindowFlags flags=0 );
  virtual ~AbstractViewer();

protected:

  virtual void doDragEnter( QDragEnterEvent* event );
  virtual void doDropEvent( QDropEvent* event );

private:

  virtual void dragEnterEvent( QDragEnterEvent* event );
  virtual void dropEvent( QDropEvent* event );

signals:

  void changeTrackPosition( const QVector3D& );
  
public slots:

  virtual void trackPositionChanged( const QVector3D& );
  
};

#endif // ABSTRACTVIEWER_HPP
