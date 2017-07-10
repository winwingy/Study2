#include "qttreeview.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTTreeView w;
	w.show();
	return a.exec();
}
