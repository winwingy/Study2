#include "parentbottom.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ParentBottom w;
	w.show();
	return a.exec();
}
