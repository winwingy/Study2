#include <QtWidgets/QApplication>
#include <QtWebKitWidgets/QWebView>
#pragma comment(lib,"Qt5Widgetsd.lib")  
#pragma comment(lib,"Qt5WebKitWidgetsd.lib")  
#include "webviewuse.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
//  	WebViewUse w;
//  	w.show();

	QWebView* view = new QWebView();
	view->setStyleSheet("background-color:argb(0,0,0,0)");
	view->setUrl(QUrl("https://www.baidu.com"));
	view->show();


	QWebView* view2 = new QWebView();
	view2->setStyleSheet("background-color:argb(0,0,0,0)");
	view2->setUrl(QUrl("D:\\XSTeachMayi\\xslive\\resources\\template\\fireworks.html"));
	view2->show();

	
	return a.exec();
}
