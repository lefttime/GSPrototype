#ifndef ABSTRACTMODEL_HPP
#define ABSTRACTMODEL_HPP

#include <QObject>

class AbstractModel : public QObject
{
  Q_OBJECT;

public:

  explicit AbstractModel( QObject* parent=0 );
  
signals:
  
public slots:
  
};

#endif // ABSTRACTMODEL_HPP
