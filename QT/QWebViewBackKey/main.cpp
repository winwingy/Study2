#include "qwebviewbackkey.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWebViewBackKey w;
	w.show();
	return a.exec();
}
