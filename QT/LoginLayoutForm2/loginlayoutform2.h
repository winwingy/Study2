#ifndef LOGINLAYOUTFORM2_H
#define LOGINLAYOUTFORM2_H

#include <QtWidgets/QMainWindow>
#include "ui_loginlayoutform2.h"

class LoginLayoutForm2 : public QMainWindow
{
	Q_OBJECT

public:
	LoginLayoutForm2(QWidget *parent = 0);
	~LoginLayoutForm2();

private:
	Ui::LoginLayoutForm2Class ui;
};

#endif // LOGINLAYOUTFORM2_H
