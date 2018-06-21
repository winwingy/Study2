#ifndef CLOSETVANIMATION_H
#define CLOSETVANIMATION_H

#include <QtWidgets/QMainWindow>
#include "ui_closetvanimation.h"
#include <QTimer>
#include <QCloseEvent>
#include <QPropertyAnimation>
#include <QLayout>


class CloseTVAnimation : public QMainWindow
{
	Q_OBJECT

public:
	CloseTVAnimation(QWidget *parent = 0);
	~CloseTVAnimation();
	void CreateConnection();
private:
	virtual void closeEvent(QCloseEvent *ev) override;
	virtual void paintEvent(QPaintEvent *ev) override;
	void closeAnimaiotn();	
	void CreateControl();
	void closeAnimaiotn2();
	QTimer* m_closeTimer;
	bool m_canClose;
	QWidget* m_pMainWidget;
	int m_paintValue;
};

#endif // CLOSETVANIMATION_H
