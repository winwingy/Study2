#include "loginUi.h"
#include "qwidget.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include "qlineedit.h"

loginUi::loginUi()
{

}

loginUi::~loginUi()
{

}

void loginUi::setupUi(QWidget* parent)
{
	if (parent->objectName().isEmpty())
		parent->setObjectName(QStringLiteral("LayoutGridClass"));

	QGridLayout* gridlayout = new QGridLayout(parent);
	gridlayout->setContentsMargins(50, 100, 50, 100);
	gridlayout->setHorizontalSpacing(15);
	gridlayout->setVerticalSpacing(15);

	QLabel* avatar = new QLabel(parent);
	QPixmap pixmap("D:\\XStrainMayi\\xstrain\\resources\\images\\app.ico");
	avatar->setFixedSize(80, 80);
	avatar->setPixmap(pixmap);
	gridlayout->addWidget(avatar, 0, 0, 3, 1);

	QLineEdit* userName = new QLineEdit(parent);
	userName->setPlaceholderText("user name / QQ / email");
	userName->setFixedSize(200, 30);
	gridlayout->addWidget(userName, 0, 0, 2, 1);

	QLineEdit* passWord = new QLineEdit(parent);
	passWord->setPlaceholderText(QStringLiteral("ÃÜÂë"));
	passWord->setFixedSize(200, 30);
	gridlayout->addWidget(passWord, 1, 1, 2, 1);

	QLabel* registerUser = new QLabel(parent);
	registerUser->setText(QStringLiteral("×¢²áÕÊºÅ"));
	gridlayout->addWidget(registerUser, 3, 0, 1, 1);

	QLabel* findPassWord = new QLabel(parent);
	findPassWord->setText(QStringLiteral("ÕÒ»ØÃÜÂë"));
	gridlayout->addWidget(findPassWord, 3, 1, 1, 1);

	QMetaObject::connectSlotsByName(parent);
}
