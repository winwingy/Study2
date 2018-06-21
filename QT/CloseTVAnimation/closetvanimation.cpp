#include "closetvanimation.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QPainter>

CloseTVAnimation::CloseTVAnimation(QWidget *parent)
	: QMainWindow(parent)
	, m_canClose(false)
	, m_paintValue(0)
{
	setWindowFlags(Qt::FramelessWindowHint);

	CreateControl();
	CreateConnection();
}

void CloseTVAnimation::CreateControl()
{
	resize(800, 600);
	m_pMainWidget = new QWidget;
	layout()->addWidget(m_pMainWidget);
	QVBoxLayout* pLayout = new QVBoxLayout(m_pMainWidget);

	QPushButton* pBtn = new QPushButton;
	pBtn->setFixedSize(100, 200);
	pBtn->setText("ÄãºÃ²»");
	pLayout->addWidget(pBtn);

	QPushButton* pBtn2 = new QPushButton;
	pBtn2->setFixedSize(400, 200);
	pBtn2->setText("Hell2");
	pLayout->addWidget(pBtn2);
	QObject::connect(pBtn2, &QPushButton::clicked, [this]()
	{
		closeAnimaiotn();		
	});

	QPushButton* pBtn3 = new QPushButton;
	pBtn3->setFixedSize(400, 200);
	pBtn3->setText("Hell3");
	pLayout->addWidget(pBtn3);
	CloseTVAnimation* pThisOut = this;
	QObject::connect(pBtn3, &QPushButton::clicked, [this, pThisOut]()
	{
		QVariantAnimation* animation = new QVariantAnimation(this);
		animation->setDuration(500);
		QRect rcOut = geometry();
		animation->setStartValue(0);
		animation->setEndValue(rcOut.height()/2);
		animation->start();
		CloseTVAnimation* pThis = pThisOut;
		QObject::connect(animation, &QVariantAnimation::valueChanged, 
			[pThis](const QVariant& var)
		{
			pThis->m_paintValue =  var.toInt();
			pThis->update();
		});
	});

}

void CloseTVAnimation::CreateConnection()
{
	m_closeTimer = new QTimer(this);
	m_closeTimer->setInterval(3000);
	QObject::connect(m_closeTimer, &QTimer::timeout, [this]()
	{
		m_canClose = true;
		close();
	});



}

CloseTVAnimation::~CloseTVAnimation()
{

}

void CloseTVAnimation::closeAnimaiotn()
{
	QVariantAnimation* animation = new QVariantAnimation(this);
	animation->setDuration(500);
	QRect rcOut = geometry();
	animation->setStartValue(0);
	animation->setEndValue(rcOut.height()/2);
	QRect rcMain = m_pMainWidget->geometry();
	
	QObject::connect(animation, &QVariantAnimation::valueChanged,
		[this, rcOut, rcMain](const QVariant& var)
	{
		setUpdatesEnabled(false);
		QRect rc = rcOut;
		
		rc.setTop(rc.top() + var.toInt());
		rc.setBottom(rc.bottom() - var.toInt());


		QRect rcMainMove = rcMain.translated(0, -var.toInt());
		m_pMainWidget->setGeometry(rcMainMove);
		
		setFixedHeight(rc.height());
		setGeometry(rc);
	

		qDebug() << rc << "  var  " << var 
			<< " m_pMainWidget rc "<< rcMain
			<< " m_pMainWidget rcMainMove "<< rcMainMove;
		setUpdatesEnabled(true);
	});
	animation->start();
}


void CloseTVAnimation::closeAnimaiotn2()
{
	setMinimumSize(0,0);
	layout()->setEnabled(false);
	QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
	animation->setDuration(3000);
	QRect rcOut = geometry();
	animation->setStartValue(rcOut);
	animation->setEndValue(QRect(rcOut.left(),
		rcOut.top() + rcOut.height()/2, rcOut.width(), 0));
	QObject::connect(animation, &QPropertyAnimation::valueChanged,
		[this, rcOut](const QVariant& var)
	{
		QRect rc = rcOut;
		rc.setTop(rc.top() + var.toInt());
		rc.setBottom(rc.bottom() - var.toInt());
		qDebug() << rc << "  var  " << var;
		setFixedHeight(rc.height());
		setGeometry(rc);
	});
	animation->start();
}


void CloseTVAnimation::closeEvent(QCloseEvent *ev)
{
	if (!m_canClose)
	{
		if (!m_closeTimer->isActive())
		{
			m_closeTimer->start();
			//layout()->setEnabled(false);
			closeAnimaiotn();
		}		
		ev->ignore();
		return;
	}

	__super::closeEvent(ev);
}

void CloseTVAnimation::paintEvent(QPaintEvent *ev)
{
	QPainter painter(this);
	QRect rc(rect());
	painter.setClipRegion(QRect(m_paintValue, 0, rc.width() - m_paintValue, rc.height()));
	painter.end();
	__super::paintEvent(ev);
}
