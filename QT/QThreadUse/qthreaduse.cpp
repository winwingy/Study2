#include "qthreaduse.h"
#include <QtCore/QThread>


QThreadMove::QThreadMove(QObject* par /*= nullptr*/)
{

}

QThreadMove::~QThreadMove()
{
	qDebug() << "~QThreadMove currentThreadId:" << currentThreadId();
}

void QThreadMove::slotFun()
{
	qDebug() << "QThreadMove::slotFun currentThreadId:" << currentThreadId();
}

void QThreadMove::run()
{
	qDebug() << "QThreadMove::run currentThreadId:" << currentThreadId();
	emit signalFun();
}




QThreadUse::QThreadUse(QWidget *parent)
	: QMainWindow(parent)
{
	qDebug() << "QThreadUse currentThreadId:" << 
		QThread::currentThreadId();
	ui.setupUi(this);

	QObject::connect(ui.pushButton_moveThread, &QPushButton::clicked, this, [this]()
	{
		QThreadMove* pMove = new QThreadMove(this);
		pMove->moveToThread(pMove);
		QThreadUse* pThis = this;
		QObject::connect(pMove, &QThreadMove::signalFun, this, [pThis]()
		{
			qDebug() << "&QThreadMove::signalFun currentThreadId:" << 
				QThread::currentThreadId();
		});
		QObject::connect(pMove, SIGNAL(signalFun()), pMove, SLOT(slotFun()));
		
		QObject::connect(pMove, &QThreadMove::finished, this, [pThis, pMove]()
		{
			qDebug() << "&QThreadMove::finished currentThreadId:" << 
				QThread::currentThreadId();
			pMove->deleteLater();
		});
		pMove->start();
	});
}

QThreadUse::~QThreadUse()
{

}
