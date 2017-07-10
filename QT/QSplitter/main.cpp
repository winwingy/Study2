#include "qsplitter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSplitter w;
	w.show();
	return a.exec();
}
