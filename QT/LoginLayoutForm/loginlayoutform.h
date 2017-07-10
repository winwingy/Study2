#ifndef LOGINLAYOUTFORM_H
#define LOGINLAYOUTFORM_H

#include <QtWidgets/QMainWindow>
class loginUi;
class LoginLayoutForm : public QMainWindow
{
	Q_OBJECT

public:
	LoginLayoutForm(QWidget *parent = 0);
	~LoginLayoutForm();

private:
	loginUi* ui;
};

#endif // LOGINLAYOUTFORM_H
