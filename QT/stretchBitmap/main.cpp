#include "stretchbitmap.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	stretchBitmap w;
	w.show();
	return a.exec();
}
