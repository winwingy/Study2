#include "circlerunpixmap.h"
#include "QSignalMapper"
#include "qpushbutton.h"
#include "qeasingcurve.h"

CircleRunPixmap::CircleRunPixmap(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_CircleAnimationWidget = new CircleAnimationWidget(this);
	m_CircleAnimationWidget->setGeometry(100, 100, 100,100);
	m_CircleAnimationWidget->setCircleInfo(QString("D:\\test\\big.jpg"), 0.3);
	m_CircleAnimationWidget->setPercent(0.5);
	m_CircleAnimationWidget->startAnimation();

	m_pBtn1 = new QPushButton(this);
	m_pBtn1->setGeometry( 10, 10, 50, 30);
	m_pSignalMapper = new QSignalMapper(m_pBtn1);
	connect(m_pBtn1, SIGNAL(clicked()), m_pSignalMapper, SLOT(map()));
	m_pSignalMapper->setMapping(m_pBtn1, QEasingCurve::OutInQuad);
	connect(m_pSignalMapper, SIGNAL(mapped(int)),this, SLOT(onMappingBack(int)));

}

CircleRunPixmap::~CircleRunPixmap()
{

}

void CircleRunPixmap::mousePressEvent(QMouseEvent *ev)
{
	__super::mousePressEvent(ev);
}

void CircleRunPixmap::onMappingBack(int curve)
{

}


