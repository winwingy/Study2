#ifndef CLOSETVANIMATION2_H
#define CLOSETVANIMATION2_H

#include <QtWidgets/QMainWindow>
#include "ui_closetvanimation2.h"
#include <QLabel>
#include <QVariantAnimation>

class CloseTVAnimation2 : public QMainWindow
{
	Q_OBJECT

public:
	CloseTVAnimation2(QWidget *parent = 0);
	~CloseTVAnimation2();

private:
	Ui::CloseTVAnimation2Class ui;

	QLabel* m_pCover;
};

#endif // CLOSETVANIMATION2_H
