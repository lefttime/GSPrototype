#ifndef PROJECTMANAGER_HPP
#define PROJECTMANAGER_HPP

#include <QDialog>

class QAbstractItemModel;

class ProjectManager : public QDialog
{
  Q_OBJECT;
  
public:

  static ProjectManager* instance();
  ~ProjectManager();

  QAbstractItemModel* openProject();
  QAbstractItemModel* createProject();

private:

  explicit ProjectManager( QWidget* parent=0 );
  
private:

  class ProjectManagerPrivate;
  QScopedPointer<ProjectManagerPrivate>         _pd;
};

#define theProjectManager ProjectManager::instance()

#endif // PROJECTMANAGER_HPP
