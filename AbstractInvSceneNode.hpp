#ifndef ABSTRACTINVSCENENODE_HPP
#define ABSTRACTINVSCENENODE_HPP

#include <Inventor/nodes/SoSeparator.h>

#include <QScopedPointer>

class AbstractModel;

class AbstractInvSceneNode : public SoSeparator
{
public:

  AbstractInvSceneNode( AbstractModel* model );
  virtual ~AbstractInvSceneNode();

  AbstractModel* model() const;

private:

  class AbstractInvSceneNodePrivate;
  QScopedPointer<AbstractInvSceneNodePrivate>         _pd;
};

#endif // ABSTRACTINVSCENENODE_HPP
