#include "labelmultiline.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LabelMultiLine w;
	w.show();
	return a.exec();
}
