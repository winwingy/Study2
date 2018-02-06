#include "thirdlogin.h"
#include <QtWidgets/QApplication>
#include <QtWebKitWidgets/QWebView>
#pragma comment(lib,"Qt5Widgetsd.lib")  
#pragma comment(lib,"Qt5WebKitWidgetsd.lib")  

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ThirdLogin w;
	w.show();

	QWebView* view = new QWebView();
	view->setStyleSheet("background-color:argb(0,0,0,0)");
	view->setUrl(QUrl("https://api.weibo.com/oauth2/authorize?response_type=code&client_id=1855711925&redirect_uri=https%3A%2F%2Fwww.xsteach.com%2Fsite%2Fo-auth-login%3Ftype%3Dsina%26goto%3Dhttp%253A%252F%252Fwww.xsteach.com%252F&state=OAuth_59db3730b48f7"));
	view->show();

	return a.exec();
}
