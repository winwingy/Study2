#ifndef ACCEPTCLASS_H
#define ACCEPTCLASS_H

#include <QObject>

class AcceptClass : public QObject
{
	Q_OBJECT

public:
	AcceptClass(QObject *parent);
	~AcceptClass();

private:
private Q_SLOTS:
	void teachSlot(int id);
};

#endif // ACCEPTCLASS_H
