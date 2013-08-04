#include "ProjectManager.hpp"
#include "ui_ProjectManager.h"

class ProjectManager::ProjectManagerPrivate
{
public:

  ProjectManagerPrivate( ProjectManager* me ) : m_self( me ) {
    m_ui.setupUi( m_self );
  }

  void init() {
  }

  ProjectManager*         m_self;
  Ui::ProjectManager      m_ui;
};

ProjectManager::ProjectManager( QWidget* parent ) :
  QDialog( parent ), _pd( new ProjectManagerPrivate( this ) )
{
  _pd->init();
}

ProjectManager* ProjectManager::instance()
{
  static ProjectManager* selfObject = 0;
  if( selfObject == 0 ) {
    selfObject = new ProjectManager;
  }

  return selfObject;
}

ProjectManager::~ProjectManager()
{
}

QAbstractItemModel*ProjectManager::openProject()
{
  QAbstractItemModel* result = 0;

  setWindowTitle( tr( "Open project" ) );
  _pd->m_ui.stackedWidget->setCurrentIndex( 0 );
  exec();

  return result;
}

QAbstractItemModel*ProjectManager::createProject()
{
  QAbstractItemModel* result = 0;

  setWindowTitle( tr( "Create project" ) );
  _pd->m_ui.stackedWidget->setCurrentIndex( 1 );
  exec();

  return result;
}
