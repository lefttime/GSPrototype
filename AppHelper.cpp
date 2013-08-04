#include "AppHelper.hpp"

#include <mainwindow.hpp>

#include <Viewer2D.hpp>
#include <Viewer3D.hpp>
#include <ProjectInspector.hpp>

class AppHelper::AppHelperPrivate
{
public:

  AppHelperPrivate( AppHelper* me, MainWindow* target ) :
    m_self( me ), m_target( target ), m_proInspector( 0 ) {
  }

  void init() {
    m_workspace = "E:/lefttime/Workspace/Sample";
    m_proInspector.reset( new ProjectInspector( m_workspace ) );
    m_target->addDockWidget( Qt::LeftDockWidgetArea, m_proInspector->widget() );
  }

  void reset() {
  }

  AppHelper*         m_self;
  MainWindow*        m_target;

  QString            m_workspace;

  QScopedPointer<ProjectInspector>  m_proInspector;
};

AppHelper::AppHelper( MainWindow* target, QObject* parent) :
  QObject( parent ),
  _pd( new AppHelperPrivate( this, target ) )
{
  _pd->init();
}

AppHelper::~AppHelper()
{
}

void AppHelper::create2DWindow()
{
  _pd->m_target->addSubWindow( new Viewer2D() );
}

void AppHelper::create3DWindow()
{
  _pd->m_target->addSubWindow( new Viewer3D() );
}
