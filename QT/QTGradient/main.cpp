#include "qtgradient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTGradient w;
	w.show();
	return a.exec();
}
