#include "webviewuse.h"
#include <QtWidgets/QApplication>
#include <QtWebKitWidgets/QWebView>
#pragma comment(lib,"Qt5Widgets.lib")
#pragma comment(lib,"Qt5WebKitWidgets.lib")


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
 	WebViewUse w;
 	w.show();

	QWebView* view = new QWebView(NULL);
	//view->setStyleSheet("background-color:argb(0,0,0,0)");
	view->setUrl(QUrl("http://www.baidu.com"));
	view->show();
	return a.exec();
}
