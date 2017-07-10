#ifndef QTHELLOWORLD_H
#define QTHELLOWORLD_H

#include <QtWidgets/QMainWindow>
#include "ui_qthelloworld.h"

class QTHelloWorld : public QMainWindow
{
	Q_OBJECT

public:
	QTHelloWorld(QWidget *parent = 0);
	~QTHelloWorld();

private slots:
	void openImageClicked();
	void existClicked();
	void popupDlg();

private:
	Ui::QTHelloWorldClass ui;
};

#endif // QTHELLOWORLD_H
