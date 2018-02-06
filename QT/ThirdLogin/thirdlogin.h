#ifndef THIRDLOGIN_H
#define THIRDLOGIN_H

#include <QtWidgets/QMainWindow>
#include "ui_thirdlogin.h"

class ThirdLogin : public QMainWindow
{
	Q_OBJECT

public:
	ThirdLogin(QWidget *parent = 0);
	~ThirdLogin();

private:
	Ui::ThirdLoginClass ui;
};

#endif // THIRDLOGIN_H
