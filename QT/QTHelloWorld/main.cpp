#include "qthelloworld.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTHelloWorld w;
	w.show();
	return a.exec();
}
