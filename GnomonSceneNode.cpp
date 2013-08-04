#include "GnomonSceneNode.hpp"

#include <Inventor/nodes/SoSwitch.h>
#include <Inventor/nodes/SoCallback.h>
#include <Inventor/nodes/SoResetTransform.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>

#include <Inventor/actions/SoAction.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/elements/SoViewingMatrixElement.h>
#include <Inventor/elements/SoGLCacheContextElement.h>
#include <Inventor/elements/SoViewportRegionElement.h>

#include <Inventor/sys/SoGL.h>

#include <QFile>
#include <QtDebug>

static const float GNOMON_CAMDIST = 3.5;
static const int   GNOMON_WIDTH   = 100; // pixels
static const int   GNOMON_HEIGHT  = GNOMON_WIDTH;

char* gnomonGeometry = "";

class GnomonSceneNode::GnomonSceneNodePrivate
{
public:

  GnomonSceneNodePrivate( GnomonSceneNode* me ) : m_self( me ) {

  }

  void init() {
    SoSwitch*            pSwitch = new SoSwitch(2);
    SoCallback*          pCallb  = new SoCallback;
    SoPerspectiveCamera* pCam    = new SoPerspectiveCamera;
    SoResetTransform*    pReset  = new SoResetTransform;
    m_self->setName( "Gnomon" );

    // Switch node will allow us turn the gnomon on and off
    pSwitch->setName( "GnomonSwitch" );
    m_self->addChild( pSwitch );

    pCallb->setCallback( gnomonCB, (void*)pCam );
    pSwitch->addChild( pCallb );

    pCam->setName( "GnomonCam" );
    pCam->position = SbVec3f( 0,0,GNOMON_CAMDIST );
    pCam->nearDistance  = 1;
    pCam->farDistance   = 6;
    pCam->focalDistance = GNOMON_CAMDIST;
    pSwitch->addChild( pCam );

    // Read the gnomon geometry from a memory buffer
    QFile hFile( ":/Resource/gadgets/gnomon.iv" );
    if( hFile.open( QFile::ReadOnly ) ) {
      QByteArray contents = hFile.readAll();
      SoInput in;
      in.setBuffer( contents.data(), contents.length() );
      SoNode* node;
      SbBool ok = SoDB::read(&in, node);
      if( ok && node != NULL ) {
        pSwitch->addChild(node);
        pSwitch->whichChild = SO_SWITCH_ALL;
      }

      hFile.close();
    }

    pSwitch->addChild( pReset );
    pReset->whatToReset = SoResetTransform::BBOX;
  }

  static void gnomonCB( void* userData, SoAction* action ) {
    if( action->isOfType( SoGLRenderAction::getClassTypeId() ) ) {
      SoState *state = action->getState();
      SoGLCacheContextElement::shouldAutoCache( state,SoGLCacheContextElement::DONT_AUTO_CACHE );

      SbViewportRegion vport( GNOMON_WIDTH, GNOMON_HEIGHT );
      SoViewportRegionElement::set( state, vport );

      glClear( GL_DEPTH_BUFFER_BIT );

      SbMatrix viewMat = SoViewingMatrixElement::get( state );
      SbVec3f tran, scale;
      SbRotation cameraRotation, orient;
      viewMat.inverse().getTransform( tran, cameraRotation, scale, orient );

      SoCamera* camera = (SoCamera*)userData;

      camera->enableNotify( FALSE );

      camera->orientation = cameraRotation;

      float distance = camera->focalDistance.getValue();

      SbMatrix mx;
      mx = cameraRotation;
      SbVec3f direction( -mx[2][0], -mx[2][1], -mx[2][2] );
      camera->position = SbVec3f(0,0,0) - distance * direction;
    }
  }

  GnomonSceneNode*         m_self;
};

GnomonSceneNode::GnomonSceneNode() : SoSeparator(), _pd( new GnomonSceneNodePrivate( this ) )
{
  _pd->init();
}

GnomonSceneNode::~GnomonSceneNode()
{
}
