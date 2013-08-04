#include "Viewer2D.hpp"
#include "ui_Viewer2D.h"

#include <qwt_symbol.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>

class Viewer2D::Viewer2DPrivate
{
public:

  Viewer2DPrivate( Viewer2D* me ) : m_self( me ) {
    m_ui.setupUi( m_self );
  }

  void init() {
    QwtPlot* plot = m_ui.qwtPlot;
    plot->setTitle( "2D Plot Demo" );
    plot->setCanvasBackground( Qt::white );

    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->attach( plot );

    generateSampleCurve();
  }

  void generateSampleCurve() {
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setStyle( QwtPlotCurve::Steps );
    curve->setTitle( "Some Points" );
    curve->setPen( Qt::blue, 4 );
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QwtSymbol* symbol = new QwtSymbol( QwtSymbol::Ellipse, QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
    curve->setSymbol( symbol );
    {
      QPolygonF points;
      double y = qrand() % 1000;
      for( double x = 0.0; x <= 1000.0; x += 100.0 ) {
        double off = qrand() % 200 - 100;
        if( y + off > 980.0 || y + off < 20.0 ) {
          off = -off;
        }
        y += off;
        points += QPointF( x, y );
      }
      curve->setSamples( points );
    }

    QwtPlot* plot = m_ui.qwtPlot;
    curve->attach( plot );
  }

  Viewer2D*         m_self;
  Ui::Viewer2D      m_ui;
};

Viewer2D::Viewer2D( QWidget* parent, Qt::WindowFlags flags ) :
  AbstractViewer( parent, flags ),
  _pd( new Viewer2DPrivate( this ) )
{
  _pd->init();
}

Viewer2D::~Viewer2D()
{
}

void Viewer2D::doDragEnter( QDragEnterEvent* event )
{
  event->acceptProposedAction();
}

void Viewer2D::doDropEvent( QDropEvent* event )
{

}
