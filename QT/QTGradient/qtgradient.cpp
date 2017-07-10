#include "qtgradient.h"
#include "qpainter.h"

QTGradient::QTGradient(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QTGradient::~QTGradient()
{

}

void QTGradient::paintEvent(QPaintEvent * e)
{
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);
		QLinearGradient linear(0, 0, 0, 1);
		linear.setColorAt(0.0, Qt::green);
		linear.setColorAt(0.2, Qt::white);
		linear.setColorAt(0.4, Qt::blue);
		linear.setColorAt(0.6, Qt::red);
		linear.setColorAt(1.0, Qt::yellow);
		painter.setBrush(QBrush(linear));
		painter.drawEllipse(10, 10, 200, 200);
	}

// 	{
// 		QPainter painter(this);
// 		    //创建了一个QRadialGradient对象实例，参数分别为中心坐标，
// 		//半径长度和焦点坐标,如果需要对称那么中心坐标和焦点坐标要一致  
// 		QRadialGradient gradient(310, 210, 100, 310, 210);
// 
// 		gradient.setColorAt(0, Qt::green);
// 		gradient.setColorAt(0.4, Qt::blue);
// 		gradient.setColorAt(1.0, Qt::yellow);
// 		painter.setBrush(gradient);
// 		painter.drawEllipse(10, 10, 500, 500);
// 
// 	}

// 	{
// 		QPainter painter(this);
// 		QConicalGradient gradient(510, 100, 0);
// 		gradient.setColorAt(0, Qt::green);
// 		gradient.setColorAt(0.2, Qt::white);
// 		gradient.setColorAt(0.4, Qt::blue);
// 		gradient.setColorAt(0.6, Qt::red);
// 		gradient.setColorAt(0.8, Qt::yellow);
// 		gradient.setColorAt(1.0, Qt::black);
// 		painter.setBrush(gradient);
// 		painter.drawRect(410, 10, 200, 200);
// 
// 
// 
// 	}
// 	

}
