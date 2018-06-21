#include "CoverAnimation.h"
#include <QGuiApplication>
#include <QScreen>
#include <windows.h>
#include <QPainter>



CoverAnimation::CoverAnimation(QWidget* obj, int intervalMs)
	: QWidget()
	, m_aniValue(0)
	, m_pObj(obj)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint |
		Qt::WindowMinimizeButtonHint /*| Qt::Tool*/);
	//setWindowFlags(Qt::CustomizeWindowHint/* | Qt::WindowMinimizeButtonHint*/);
	// QWidget透明显示，当设置主显示窗口的外边距时，防止外边距显示出来。
	setAttribute(Qt::WA_TranslucentBackground);


	QScreen* pScreen = QGuiApplication::primaryScreen();
	QPixmap pix = pScreen->grabWindow(0);
	pix.save("d:\\test\\png\\screenCoverAnimation.png", "png");

	QPixmap pixWin = QPixmap::grabWidget(obj);
	pixWin.save("d:\\test\\png\\screenpixWin.png", "png");

	QRect geo = obj->frameGeometry();
	QPixmap pixCp = pix.copy(geo);
	pixCp.save("d:\\test\\png\\thisWinCoverAnimation.png", "png");
	m_pixCp = pixCp;

	
	SetWindowPos((HWND)winId(), (HWND)obj->winId(), 0, 0, 0, 0,
		SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
	setGeometry(geo);

	m_ani = new QVariantAnimation(this);
	m_ani->setDuration(intervalMs);
	m_ani->setStartValue(0);
	m_ani->setEndValue(geo.height()/2);
	QObject::connect(m_ani, &QVariantAnimation::valueChanged, 
		[this, geo](const QVariant& var){
		m_aniValue = var.toInt();
		update();
	});
}


CoverAnimation::~CoverAnimation(void)
{
}

void CoverAnimation::start()
{
	m_ani->start();
	setVisible(true);
	m_pObj->hide();
}

void CoverAnimation::paintEvent(QPaintEvent *ev)
{
	QPainter painter(this);
	painter.setClipRect(0, m_aniValue, width(), height() - m_aniValue*2);
	painter.drawPixmap(rect(), m_pixCp);
}
