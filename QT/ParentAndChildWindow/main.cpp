#include "parentandchildwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ParentAndChildWindow w;
	w.show();
	return a.exec();
}
