#include "parentbottom.h"

ParentBottom::ParentBottom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
	//setWindowFlags(Qt::CustomizeWindowHint/* | Qt::WindowMinimizeButtonHint*/);
	// QWidget͸����ʾ������������ʾ���ڵ���߾�ʱ����ֹ��߾���ʾ������
	setAttribute(Qt::WA_TranslucentBackground);
}

ParentBottom::~ParentBottom()
{

}

