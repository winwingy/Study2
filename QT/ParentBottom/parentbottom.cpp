#include "parentbottom.h"

ParentBottom::ParentBottom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
	//setWindowFlags(Qt::CustomizeWindowHint/* | Qt::WindowMinimizeButtonHint*/);
	// QWidget透明显示，当设置主显示窗口的外边距时，防止外边距显示出来。
	setAttribute(Qt::WA_TranslucentBackground);
}

ParentBottom::~ParentBottom()
{

}

