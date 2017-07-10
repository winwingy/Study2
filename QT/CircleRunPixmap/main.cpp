#include "circlerunpixmap.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CircleRunPixmap w;
	w.show();
	return a.exec();
}
