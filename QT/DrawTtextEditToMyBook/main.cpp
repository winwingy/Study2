#include "drawttextedittomybook.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DrawTtextEditToMyBook w;
	w.show();
	return a.exec();
}
