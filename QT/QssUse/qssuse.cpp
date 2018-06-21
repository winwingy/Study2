#include "qssuse.h"
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include "qssUseClass.h"

QssUse::QssUse(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedHeight(900);
	FILE* fp = nullptr;
	fp = fopen("./resources/qss.css", "r");
	char* buf  =new char[2048];
	fread(buf, 1, 2048, fp);
	fclose(fp);
	setStyleSheet(QString(buf));

	QVBoxLayout* pLayout = new QVBoxLayout(centralWidget());

	QPushButton* btn =new QPushButton(this);
	btn->setFixedSize(100, 100);
	btn->setObjectName("MyBtn");
	btn->setText("HelloBtn");
	//btn->setFlat(true);
	btn->move(100, 10);
	btn->show();
	pLayout->addWidget(btn);

	QLabel* lab = new QLabel(this);
	lab->setFixedSize(100, 100);
	lab->setText("HelloText");
	lab->setObjectName("LabelText");
	pLayout->addWidget(lab);

	QPushButton* btn2 = new QPushButton(this);
	btn2->setObjectName("btn2");
	btn2->setFlat(true);
	btn2->setText("btn2");
	btn2->move(300, 100);
	pLayout->addWidget(btn2);


	QLabel* labImage = new QLabel;
	labImage->setObjectName("labeImage");
	labImage->setProperty("imageProperty", 123);
	pLayout->addWidget(labImage);


	QLabel* labBack = new QLabel;
	labBack->setObjectName("labBack");
	labBack->setProperty("imageProperty", 123);
	pLayout->addWidget(labBack);

	QCheckBox* pBox = new QCheckBox;
	pBox->setText("myCheckBox");
	pBox->setObjectName("myCheckBox");
	pLayout->addWidget(pBox);

	myBtn = new myPushButton;
	myBtn->setText("myPushButton");
	myBtn->setObjectName("myPushButton11");
	pLayout->addWidget(myBtn);

	QPushButton* pBtnLevel = new QPushButton;
	pBtnLevel->setFixedHeight(100);
	pBtnLevel->setText("pBtnLevel");
	pBtnLevel->setObjectName("pBtnLevel");
	pLayout->addWidget(pBtnLevel);
}

QssUse::~QssUse()
{

}

void QssUse::mousePressEvent(QMouseEvent *ev)
{
	QString name = myBtn->teacherName();
	myBtn->setTeacherName("tom");
}
