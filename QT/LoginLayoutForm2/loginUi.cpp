#include "loginUi.h"
#include "qwidget.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qmainwindow.h"
#include "qcheckbox.h"
#include "qpushbutton.h"

loginUi::loginUi()
{

}

loginUi::~loginUi()
{

}

void loginUi::setupUi(QMainWindow* parentObj)
{
	if (parentObj->objectName().isEmpty())
		parentObj->setObjectName(QStringLiteral("LayoutGridClass"));

	QWidget* centralWidget = new QWidget(parentObj);
	parentObj->setCentralWidget(centralWidget);

	QGridLayout* gridlayout = new QGridLayout(centralWidget);
	gridlayout->setContentsMargins(50, 100, 50, 100);
	gridlayout->setHorizontalSpacing(15);
	gridlayout->setVerticalSpacing(15);

	QLabel* avatar = new QLabel(parentObj);
	QPixmap pixmap("D:\\XStrainMayi\\xstrain\\resources\\images\\app.ico");
	avatar->setFixedSize(80, 80);
	avatar->setPixmap(pixmap);
	gridlayout->addWidget(avatar, 0, 0, 3, 1, Qt::AlignCenter);

	QLineEdit* userName = new QLineEdit(parentObj);
	userName->setPlaceholderText("user name / QQ / email");
	userName->setFixedSize(200, 30);
	gridlayout->addWidget(userName, 0, 1, 1, 2);

	QLineEdit* passWord = new QLineEdit(parentObj);
	passWord->setPlaceholderText(QStringLiteral("ÃÜÂë"));
	passWord->setFixedSize(200, 30);
	gridlayout->addWidget(passWord, 1, 1,1, 2);

	QLabel* registerUser = new QLabel(parentObj);
	registerUser->setText(QStringLiteral("×¢²áÕÊºÅ"));
	gridlayout->addWidget(registerUser, 0, 3, 1, 1);

	QLabel* findPassWord = new QLabel(parentObj);
	findPassWord->setText(QStringLiteral("ÕÒ»ØÃÜÂë"));
	gridlayout->addWidget(findPassWord, 1, 3, 1, 1);

	QCheckBox* rememberPassword = new QCheckBox(parentObj);
	rememberPassword->setText(QStringLiteral("¼Ç×¡ÃÜÂë"));
	gridlayout->addWidget(rememberPassword, 2, 1, 1, 1);

	QCheckBox* autoLogin = new QCheckBox(parentObj);
	autoLogin->setText(QStringLiteral("×Ô¶¯µÇÂ¼"));
	gridlayout->addWidget(autoLogin, 2, 2, 1, 1);

	QPushButton* loginButton = new QPushButton(parentObj);
	loginButton->setText(QStringLiteral("µÇÂ¼"));
	gridlayout->addWidget(loginButton, 3, 1, 1, 2);

	QMetaObject::connectSlotsByName(parentObj);
}
