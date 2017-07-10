#include "acceptclass.h"
#include "qlogging.h"

AcceptClass::AcceptClass(QObject *parent)
	: QObject(parent)
{

}

AcceptClass::~AcceptClass()
{

}

void AcceptClass::teachSlot(int id)
{
	int b = id;
	qDebug("aa");
}
