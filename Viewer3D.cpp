#include "Viewer3D.hpp"
#include "ui_Viewer3D.h"

#include <Viewer3DHelper.hpp>
#include <GnomonSceneNode.hpp>
#include <ProjectInvSceneNode.hpp>
#include <WellTrackInvSceneNode.hpp>

#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>

#include <QUrl>
#include <QtDebug>
#include <QGridlayout>

class Viewer3D::Viewer3DPrivate
{
public:

  Viewer3DPrivate( Viewer3D* me ) : m_self( me ) {
    m_ui.setupUi( m_self );
  }

  ~Viewer3DPrivate() {
    delete m_viewer;
  }

  void init() {
    m_viewer = new SoQtExaminerViewer( m_self );
    m_viewer->setDecoration( false );

    m_scene = new SoSeparator;
    m_viewer->setSceneGraph( m_scene );
    GnomonSceneNode* gnomonSceneNode = new GnomonSceneNode;
    m_scene->addChild( gnomonSceneNode );

    QGridLayout* gridLayout = new QGridLayout( m_self );
    gridLayout->setMargin( 0 );
    gridLayout->addWidget( m_viewer->getWidget() );

    m_helper = new Viewer3DHelper( m_self );

    sampleTest();
    m_viewer->viewAll();
  }

  void sampleTest() {
    WellTrackInvSceneNode* wellTrack = new WellTrackInvSceneNode( 0 );
    m_scene->addChild( wellTrack );

    ProjectInvSceneNode* project = new ProjectInvSceneNode( 0 );
    m_scene->addChild( project );
  }

  Viewer3D*           m_self;
  Ui::Viewer3D        m_ui;

  SoQtExaminerViewer* m_viewer;
  SoSeparator*        m_scene;

  Viewer3DHelper*     m_helper;
};

Viewer3D::Viewer3D( QWidget* parent, Qt::WindowFlags flags ) :
  AbstractViewer( parent, flags ),
  _pd( new Viewer3DPrivate( this ) )
{
  _pd->init();
}

Viewer3D::~Viewer3D()
{
}

void Viewer3D::doDragEnter( QDragEnterEvent* event )
{
  if( event->mimeData()->hasUrls() ) {
    event->acceptProposedAction();
  }
}

void Viewer3D::doDropEvent( QDropEvent* event )
{
  if( event->mimeData()->hasUrls() ) {
    foreach( QUrl url, event->mimeData()->urls() ) {
      qDebug() << "Viewer3D::doDropEvent: " << url;
    }
  }
}
