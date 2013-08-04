#include "ProjectInspector.hpp"
#include "ui_ProjectInspector.h"

#include <QFileSystemModel>

class ProjectInspector::ProjectInspectorPrivate
{
public:

  ProjectInspectorPrivate( ProjectInspector* me, const QString& workspace ) :
    m_self( me ),
    m_workspace( workspace ) {
    m_ui.setupUi( m_self );
  }

  void init() {
    QTreeView* treeView = m_ui.treeView;
    treeView->installEventFilter( m_self );

    m_fsModel.setRootPath( m_workspace );
    treeView->setModel( &m_fsModel );

    QModelIndex index = m_fsModel.index( m_workspace );
    treeView->setRootIndex( index );
    for( int idx = 1; idx < m_fsModel.columnCount(); ++idx ) {
      treeView->hideColumn( idx );
    }
  }

  ProjectInspector*         m_self;
  Ui::ProjectInspector      m_ui;

  QString                   m_workspace;
  QFileSystemModel          m_fsModel;
};

ProjectInspector::ProjectInspector(const QString& workspace, QWidget* parent) :
  AbstractDockWidget( parent ),
  _pd( new ProjectInspectorPrivate( this, workspace ) )
{
  _pd->init();
}

ProjectInspector::~ProjectInspector()
{
}

QDockWidget*ProjectInspector::widget()
{
  return _pd->m_ui.dockWidget;
}

bool ProjectInspector::eventFilter( QObject* obj, QEvent* event )
{
  Q_UNUSED( obj );
  Q_UNUSED( event );
  return false;
}
