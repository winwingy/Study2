#include "loginlayoutform2.h"
#include <QtWidgets/QApplication>
#include "loginlayoutform.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginLayoutForm w;
	w.show();
	return a.exec();
}
