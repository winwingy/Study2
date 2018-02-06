#include "qwebenginepageuse.h"
#include <QtWidgets/QApplication>
#include <QWebEngineView>  

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWebEnginePageUse w;
	w.show();
	return a.exec();
}
