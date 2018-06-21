#include "closetvanimation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CloseTVAnimation w;
	w.show();
	return a.exec();
}
