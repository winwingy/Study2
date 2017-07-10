#include "layoutgrid.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LayoutGrid w;
	w.show();
	return a.exec();
}
