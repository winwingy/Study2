#include "QssUse2.h"

QssUse2::QssUse2(QWidget* par /*= nullptr*/)
	: QMainWindow(par)
{
	FILE* fp = nullptr;
	fp = fopen("./resources/qss.css", "r");
	char* buf  =new char[2048];
	fread(buf, 1, 2048, fp);
	fclose(fp);
	setStyleSheet(QString(buf));

	QWidget* pMainWidget =new QWidget;
	setCentralWidget(pMainWidget);
	QHBoxLayout* pMainLayout = new QHBoxLayout(pMainWidget);

	QPushButton* pXueBi = new QPushButton;
	pXueBi->setObjectName("pXueBi");
	pXueBi->setFixedSize(16, 18);
	//pXueBi->setText("pXueBi");
	pMainLayout->addWidget(pXueBi);

	QPushButton* pXueBiVert = new QPushButton;
	pXueBiVert->setObjectName("pXueBiVert");
	pXueBiVert->setFixedSize(5, 6);
	//pXueBi->setText("pXueBi");
	pMainLayout->addWidget(pXueBiVert);

}


QssUse2::~QssUse2(void)
{
}
