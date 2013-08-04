#include "ProjectInvSceneNode.hpp"

#include <Inventor/nodes/SoCube.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodekits/SoShapeKit.h>

class ProjectInvSceneNode::ProjectInvSceneNodePrivate
{
public:

  ProjectInvSceneNodePrivate( ProjectInvSceneNode* me ) : m_self( me ) {
  }

  void init() {
    m_shapeNode = new SoShapeKit;
    m_self->addChild( m_shapeNode );

    m_shapeNode->set( "material { diffuseColor .5 .5 .5 }" );
    m_shapeNode->set( "drawStyle { style LINES }" );
    m_shapeNode->set( "pickStyle { style UNPICKABLE }" );
    m_shapeNode->set( "lightModel { model BASE_COLOR }" );

    SbBox3f bbox(-10, -10, -907.266f, 383.714f, 999.328f, 10 );
    SoCube* cubeNode = SO_GET_PART( m_shapeNode, "shape", SoCube );
    cubeNode->width.setValue( bbox.getSize()[0] );
    cubeNode->height.setValue( bbox.getSize()[1] );
    cubeNode->depth.setValue( bbox.getSize()[2] );

    SoTransform* transNode = SO_GET_PART( m_shapeNode, "transform", SoTransform );
    transNode->translation.setValue( bbox.getCenter() );
  }

  ProjectInvSceneNode*         m_self;
  SoShapeKit*                  m_shapeNode;
};

ProjectInvSceneNode::ProjectInvSceneNode(AbstractModel* model) :
  AbstractInvSceneNode( model ), _pd( new ProjectInvSceneNodePrivate( this ) )
{
  _pd->init();
}

ProjectInvSceneNode::~ProjectInvSceneNode()
{
}
