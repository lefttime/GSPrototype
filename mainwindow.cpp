#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <AppHelper.hpp>
#include <ProjectManager.hpp>

#include <QLabel>
#include <QtDebug>
#include <QMdiSubWindow>

class MainWindow::MainWindowPrivate
{
public:

  MainWindowPrivate( MainWindow* me ) : m_self( me ) {
    m_ui.setupUi( m_self );
  }

  void init() {
    m_helper = new AppHelper( m_self, m_self );

    updateMenus();
    QObject::connect( m_ui.mdiArea, SIGNAL( subWindowActivated( QMdiSubWindow* ) ),
                      m_self,       SLOT( updateMenus() ) );
  }

  void updateMenus() {
    bool hasMdiChild = (activeMdiChild() != 0);
    m_ui.action_Close->setEnabled( hasMdiChild );
    m_ui.action_Close_All->setEnabled( hasMdiChild );
    m_ui.action_Tile->setEnabled( hasMdiChild );
    m_ui.action_Cascade->setEnabled( hasMdiChild );
    m_ui.action_Next->setEnabled( hasMdiChild );
    m_ui.action_Previous->setEnabled( hasMdiChild );
  }

  QMdiSubWindow* activeMdiChild() {
    return m_ui.mdiArea->activeSubWindow();
  }

  MainWindow*         m_self;
  Ui::MainWindow      m_ui;

  AppHelper*          m_helper;
};

MainWindow::MainWindow( QWidget* parent ) :
  QMainWindow( parent ),
  _pd( new MainWindowPrivate( this ) )
{
  _pd->init();
}

MainWindow::~MainWindow()
{
}

QMdiSubWindow* MainWindow::addSubWindow(QWidget* subWindow )
{
  QMdiSubWindow* mdiSubWindow = _pd->m_ui.mdiArea->addSubWindow( subWindow );
  mdiSubWindow->setAttribute( Qt::WA_DeleteOnClose );
  mdiSubWindow->show();
  mdiSubWindow->setAcceptDrops( true );
  return mdiSubWindow;
}

void MainWindow::updateMenus()
{
  _pd->updateMenus();
}

void MainWindow::on_action_New_Project_triggered()
{
  theProjectManager->createProject();
}

void MainWindow::on_action_Open_Project_triggered()
{
  theProjectManager->openProject();
}

void MainWindow::on_actionNew_2D_window_triggered()
{
  _pd->m_helper->create2DWindow();
}

void MainWindow::on_actionNew_3D_window_triggered()
{
  _pd->m_helper->create3DWindow();
}

void MainWindow::on_action_Modeling_triggered()
{
  QLabel* label = new QLabel;
  label->setScaledContents( true );
  label->setPixmap( QPixmap( ":/Resource/image/Modeling.png" ) );
  addSubWindow( label );
}

void MainWindow::on_action_Curve_Contrast_triggered()
{
  QLabel* label = new QLabel;
  label->setScaledContents( true );
  label->setPixmap( QPixmap( ":/Resource/image/gx.png" ) );
  addSubWindow( label );
}
