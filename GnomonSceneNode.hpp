#ifndef GNOMONSCENENODE_HPP
#define GNOMONSCENENODE_HPP

#include <QScopedPointer>
#include <Inventor/nodes/SoSeparator.h>

class GnomonSceneNode : public SoSeparator
{
public:

  GnomonSceneNode();
  ~GnomonSceneNode();

private:

  class GnomonSceneNodePrivate;
  QScopedPointer<GnomonSceneNodePrivate>         _pd;
};

#endif // GNOMONSCENENODE_HPP
