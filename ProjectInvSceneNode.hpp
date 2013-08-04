#ifndef PROJECTINVSCENENODE_HPP
#define PROJECTINVSCENENODE_HPP

#include <AbstractInvSceneNode.hpp>

class ProjectInvSceneNode : public AbstractInvSceneNode
{
public:

  ProjectInvSceneNode( AbstractModel* model );
  ~ProjectInvSceneNode();

private:

  class ProjectInvSceneNodePrivate;
  QScopedPointer<ProjectInvSceneNodePrivate>         _pd;
};

#endif // PROJECTINVSCENENODE_HPP
