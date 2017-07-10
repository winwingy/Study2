#ifndef WEBVIEWUSE_H
#define WEBVIEWUSE_H

#include <QtWidgets/QMainWindow>
#include "ui_webviewuse.h"

class WebViewUse : public QMainWindow
{
	Q_OBJECT

public:
	WebViewUse(QWidget *parent = 0);
	~WebViewUse();

private:
	Ui::WebViewUseClass ui;
};

#endif // WEBVIEWUSE_H
