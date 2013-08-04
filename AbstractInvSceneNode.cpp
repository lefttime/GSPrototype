#include "AbstractInvSceneNode.hpp"

class AbstractInvSceneNode::AbstractInvSceneNodePrivate
{
public:

  AbstractInvSceneNodePrivate( AbstractInvSceneNode* me, AbstractModel* model  )
    : m_self( me ), m_model( model ) {

  }

  AbstractInvSceneNode*         m_self;
  AbstractModel*                m_model;
};

AbstractInvSceneNode::AbstractInvSceneNode( AbstractModel* model ) :
  SoSeparator(), _pd( new AbstractInvSceneNodePrivate( this, model ) )
{
}

AbstractInvSceneNode::~AbstractInvSceneNode()
{

}

AbstractModel*AbstractInvSceneNode::model() const
{
  return _pd->m_model;
}
