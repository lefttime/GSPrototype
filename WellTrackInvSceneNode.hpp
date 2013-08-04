#ifndef WELLTRACKINVSCENENODE_HPP
#define WELLTRACKINVSCENENODE_HPP

#include <AbstractInvSceneNode.hpp>

class WellTrackInvSceneNode : public AbstractInvSceneNode
{
public:

  WellTrackInvSceneNode( AbstractModel* model );
  ~WellTrackInvSceneNode();

private:

  class WellTrackInvSceneNodePrivate;
  QScopedPointer<WellTrackInvSceneNodePrivate>         _pd;

};

#endif // WELLTRACKINVSCENENODE_HPP
