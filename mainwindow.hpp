#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class QMdiSubWindow;

class MainWindow : public QMainWindow
{
  Q_OBJECT;

public:

  explicit MainWindow( QWidget* parent=0 );
  ~MainWindow();

  QMdiSubWindow* addSubWindow( QWidget* subWindow );

private slots:

  void updateMenus();

  void on_action_New_Project_triggered();
  void on_action_Open_Project_triggered();

  void on_actionNew_2D_window_triggered();
  void on_actionNew_3D_window_triggered();

  /// test
  void on_action_Modeling_triggered();
  void on_action_Curve_Contrast_triggered();

private:

  class MainWindowPrivate;
  QScopedPointer<MainWindowPrivate>         _pd;
};

#endif // MAINWINDOW_HPP
