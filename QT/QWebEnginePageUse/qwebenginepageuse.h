#ifndef QWEBENGINEPAGEUSE_H
#define QWEBENGINEPAGEUSE_H

#include <QtWidgets/QMainWindow>
#include "ui_qwebenginepageuse.h"

class QWebEnginePageUse : public QMainWindow
{
	Q_OBJECT

public:
	QWebEnginePageUse(QWidget *parent = 0);
	~QWebEnginePageUse();

private:
	Ui::QWebEnginePageUseClass ui;
};

#endif // QWEBENGINEPAGEUSE_H
