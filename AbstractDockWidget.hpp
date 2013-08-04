#ifndef ABSTRACTDOCKWIDGET_HPP
#define ABSTRACTDOCKWIDGET_HPP

#include <QWidget>

class QDockWidget;

class AbstractDockWidget : public QWidget
{
  Q_OBJECT;

public:

  explicit AbstractDockWidget( QWidget* parent=0 );
  virtual ~AbstractDockWidget();

  virtual QDockWidget* widget()=0;
  
};

#endif // ABSTRACTDOCKWIDGET_HPP
