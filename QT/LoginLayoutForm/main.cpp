#include "loginlayoutform.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginLayoutForm w;
	w.show();
	return a.exec();
}
