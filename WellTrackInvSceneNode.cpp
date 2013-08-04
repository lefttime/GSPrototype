#include "WellTrackInvSceneNode.hpp"

#include <Inventor/nodes/SoFont.h>
#include <Inventor/nodes/SoText2.h>
#include <Inventor/nodes/SoLineSet.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoCoordinate3.h>
#include <Inventor/nodekits/SoShapeKit.h>

#include <QFile>
#include <QtDebug>
#include <QTextStream>
#include <QStringList>

class WellTrackInvSceneNode::WellTrackInvSceneNodePrivate
{
public:

  WellTrackInvSceneNodePrivate( WellTrackInvSceneNode* me ) : m_self( me ) {
  }

  void init() {
    m_self->setName( "welltrack" );
    sampleTest();
  }

  void sampleTest() {
    m_shapeNode = new SoShapeKit;
    m_self->addChild( m_shapeNode );

    m_shapeNode->setPart( "shape", new SoLineSet );
    m_shapeNode->set( "material { diffuseColor 1 0 0 } " );

    SoCoordinate3* coordNode = SO_GET_PART( m_shapeNode, "coordinate3", SoCoordinate3 );
    {
      QFile hFile( ":/Resource/datastore/trajectory.txt" );
      if( hFile.open( QFile::ReadOnly ) ) {
        QTextStream in( &hFile );
        while( !in.atEnd() ) {
          QStringList content = in.readLine().split( QRegExp( "\\s+" ) );
          SbVec3f pt(content[0].toFloat(), content[1].toFloat(), content[2].toFloat() );
          coordNode->point.set1Value( coordNode->point.getNum(), pt );
        }
        hFile.close();
      }
    }

    m_textNode = new SoShapeKit;
    m_self->addChild( m_textNode );

    SoText2* text = new SoText2;
    text->justification = SoText2::CENTER;
    text->string.setValue( "Gao-1" );

    m_textNode->setPart( "shape", text );
    SoTransform* transNode = SO_GET_PART( m_textNode, "transform", SoTransform );
    transNode->translation.setValue( coordNode->point[0] );

    SoFont* fontNode = SO_GET_PART( m_textNode, "font", SoFont );
    fontNode->name.setValue( "ARLRDBD" );
    fontNode->size.setValue( 12 );
    fontNode->renderStyle = SoFont::TEXTURE;
  }

  WellTrackInvSceneNode*         m_self;

  SoShapeKit*                    m_textNode;
  SoShapeKit*                    m_shapeNode;
};

WellTrackInvSceneNode::WellTrackInvSceneNode( AbstractModel* model ) :
  AbstractInvSceneNode( model ), _pd( new WellTrackInvSceneNodePrivate( this ) )
{
  _pd->init();
}

WellTrackInvSceneNode::~WellTrackInvSceneNode()
{
}
