#include "closetvanimation2.h"
#include <QGuiApplication>
#include <QScreen>
#include <QPixmap>
#include "CoverAnimation.h"
#include <QTimer>

CloseTVAnimation2::CloseTVAnimation2(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.PushButton1, &QPushButton::clicked, [this]()
	{
		// save screen
		QScreen* pScreen = QGuiApplication::primaryScreen();
		QPixmap pix = pScreen->grabWindow(0);
		pix.save("d:\\test\\png\\screen.png", "png");

		QPixmap pixCp = pix.copy(300, 300, 400, 200);
		pixCp.save("d:\\test\\png\\screenCp.png", "png");


	});

	QObject::connect(ui.PushButton2, &QPushButton::clicked, [this]()
	{
		// save screen
		QScreen* pScreen = QGuiApplication::primaryScreen();
		QPixmap pix = pScreen->grabWindow(0);
		pix.save("d:\\test\\png\\screen.png", "png");


		QRect geo = frameGeometry();
		QPixmap pixCp = pix.copy(geo);
		pixCp.save("d:\\test\\png\\thisWin.png", "png");


	});

	QObject::connect(ui.PushButton3, &QPushButton::clicked, [this]()
	{
		QTimer* pTimer =new QTimer(this);
		pTimer->start(100);
		pTimer->setSingleShot(true);
		CloseTVAnimation2* pThis = this;
		QObject::connect(pTimer, &QTimer::timeout, [pThis](){
			CoverAnimation* pAni = new CoverAnimation(pThis, 5000);
			pAni->start();
		});

	});
}

CloseTVAnimation2::~CloseTVAnimation2()
{

}
