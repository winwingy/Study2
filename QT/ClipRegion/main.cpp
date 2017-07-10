#include "clipregion.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ClipRegion w;
	w.show();
	return a.exec();
}
