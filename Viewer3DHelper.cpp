#include "Viewer3DHelper.hpp"

class Viewer3DHelper::Viewer3DHelperPrivate
{
public:

  Viewer3DHelperPrivate( Viewer3DHelper* me, Viewer3D* target ) :
    m_self( me ), m_target( target ) {

  }

  Viewer3DHelper*         m_self;
  Viewer3D*               m_target;
};

Viewer3DHelper::Viewer3DHelper(Viewer3D* target, QObject* parent ) :
  QObject( parent ), _pd( new Viewer3DHelperPrivate( this, target ) )
{
}

Viewer3DHelper::~Viewer3DHelper()
{
}
