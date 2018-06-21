#include "qssuse.h"
#include <QtWidgets/QApplication>
#include "QssUse2.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QssUse w;
	w.show();
	QssUse2 w2;
	w2.show();
	return a.exec();
}
