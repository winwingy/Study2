#ifndef PARENTANDCHILDWINDOW_H
#define PARENTANDCHILDWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_parentandchildwindow.h"

class ParentAndChildWindow : public QMainWindow
{
	Q_OBJECT

public:
	ParentAndChildWindow(QWidget *parent = 0);
	~ParentAndChildWindow();

public slots:
	void slot1();
private:
	Ui::ParentAndChildWindowClass ui;
};

#endif // PARENTANDCHILDWINDOW_H
