#ifndef QWEBVIEWBACKKEY_H
#define QWEBVIEWBACKKEY_H

#include <QtWidgets/QMainWindow>
#include "ui_qwebviewbackkey.h"
#include <QtWebKit>
#include "QtWebKitWidgets/qwebview.h"


class QWebViewBackKey : public QMainWindow
{
	Q_OBJECT

public:
	QWebViewBackKey(QWidget *parent = 0);
	~QWebViewBackKey();

private:
	Ui::QWebViewBackKeyClass ui;
};

class WebViewE : public QWebView
{
public:
	WebViewE(QWidget* par = nullptr);
	~WebViewE();

	virtual void mousePressEvent(QMouseEvent*ev) override;

};

#endif // QWEBVIEWBACKKEY_H
