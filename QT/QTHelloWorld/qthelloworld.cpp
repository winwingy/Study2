#include "qthelloworld.h"
#include <QFileDialog>  
#include <QMessageBox>  
#include "showimageview.h"

QTHelloWorld::QTHelloWorld(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QTHelloWorld::~QTHelloWorld()
{

}

void QTHelloWorld::openImageClicked()
{
	QString fileName;
	fileName = QFileDialog::getOpenFileName(this, QStringLiteral("Ñ¡ÔñÍ¼Ïñ"), "",
		"Images (*.png *.xpm *.jpg)");

	QImage* img = new QImage;
	img->load(fileName);
	ui.label->setPixmap(QPixmap::fromImage(*img));
	delete img;
}

void QTHelloWorld::existClicked()
{
	close();
}

void QTHelloWorld::popupDlg()
{
	ShowImageView* imageView = new ShowImageView;
	imageView->show();
}
