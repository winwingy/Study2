#include "layoutclass.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LayoutClass w;
	w.show();
	return a.exec();
}
