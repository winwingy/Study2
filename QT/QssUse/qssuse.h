#ifndef QSSUSE_H
#define QSSUSE_H

#include <QtWidgets/QMainWindow>
#include "ui_qssuse.h"
#include "qssUseClass.h"

class QssUse : public QMainWindow
{
	Q_OBJECT

public:
	QssUse(QWidget *parent = 0);
	~QssUse();

private:
	virtual void mousePressEvent(QMouseEvent *ev) override;
	Ui::QssUseClass ui;

	myPushButton* myBtn;
};

#endif // QSSUSE_H
