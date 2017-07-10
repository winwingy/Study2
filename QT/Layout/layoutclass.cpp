#include "layoutclass.h"

LayoutClass::LayoutClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//setWindowFlags(Qt::FramelessWindowHint);  
}

LayoutClass::~LayoutClass()
{

}
