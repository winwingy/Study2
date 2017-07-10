#include "singalsend.h"

SingalSend::SingalSend(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//connect(this, SIGNAL(teach(10)), )
}

SingalSend::~SingalSend()
{

}

void SingalSend::begin()
{
	emit teach(50);
}

// void SingalSend::teach(int a)
// {
// 	int c = a;
// }
