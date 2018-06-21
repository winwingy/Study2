#ifndef QTHREADUSE_H
#define QTHREADUSE_H

#include <QtWidgets/QMainWindow>
#include "ui_qthreaduse.h"
#include <QtCore/QThread>
#include <QDebug>

class QThreadMove : public QThread
{
	Q_OBJECT
public:
	QThreadMove(QObject* par = nullptr);
	~QThreadMove();

public slots:
	void slotFun();

signals:
	void signalFun();

protected:
	virtual void run() override;
};



class QThreadUse : public QMainWindow
{
	Q_OBJECT

public:
	QThreadUse(QWidget *parent = 0);
	~QThreadUse();

private:
	Ui::QThreadUseClass ui;
};

#endif // QTHREADUSE_H
