#include "animation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Animation w;
	w.show();
	return a.exec();
}
