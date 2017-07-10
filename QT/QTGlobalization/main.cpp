#include "qtglobalization.h"
#include <QtWidgets/QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator qTranslator;
	qTranslator.load("qtglobalization_zh.qm");
	a.installTranslator(&qTranslator);
	QTGlobalization w;
	w.show();
	return a.exec();
}
