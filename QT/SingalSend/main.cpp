#include "singalsend.h"
#include <QtWidgets/QApplication>
#include "acceptclass.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SingalSend w;
	w.show();
	AcceptClass ac(nullptr);

	QObject::connect(&w, SIGNAL(teach(int)),  &ac, SLOT(teachSlot(int)));
	emit w.teach(10);
	w.teach(10);
	w.begin();
	char szbuf[1024];
	sprintf_s(szbuf, "%s", "12""34");
	return a.exec();
}
