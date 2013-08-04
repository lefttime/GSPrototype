#include "AbstractViewer.hpp"

AbstractViewer::AbstractViewer( QWidget* parent , Qt::WindowFlags flags ) :
  QWidget( parent, flags )
{
  setAcceptDrops( true );
}

AbstractViewer::~AbstractViewer()
{
}

void AbstractViewer::doDragEnter(QDragEnterEvent* event)
{
  Q_UNUSED( event );
}

void AbstractViewer::doDropEvent( QDropEvent* event )
{
  Q_UNUSED( event );
}

void AbstractViewer::dragEnterEvent( QDragEnterEvent* event )
{
  doDragEnter( event );
}

void AbstractViewer::dropEvent( QDropEvent* event )
{
  doDropEvent( event );
}

void AbstractViewer::trackPositionChanged( const QVector3D& )
{
}
