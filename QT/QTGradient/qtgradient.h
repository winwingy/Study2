#ifndef QTGRADIENT_H
#define QTGRADIENT_H

#include <QtWidgets/QWidget>
#include "ui_qtgradient.h"

class QTGradient : public QWidget
{
	Q_OBJECT

public:
	QTGradient(QWidget *parent = 0);
	~QTGradient();

private:
	void paintEvent(QPaintEvent * e);
	Ui::QTGradientClass ui;
};

#endif // QTGRADIENT_H
