#include "parentandchildwindow.h"
#include <QDialog>

ParentAndChildWindow::ParentAndChildWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

ParentAndChildWindow::~ParentAndChildWindow()
{

}

void ParentAndChildWindow::slot1()
{
	this->hide();
	QDialog* wid = new QDialog();
	wid->setGeometry(-10000, -10000, 1, 1);
	wid->show();
	QDialog* ano = new QDialog(wid);
	wid->hide();
	ano->show();
}