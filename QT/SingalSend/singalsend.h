#ifndef SINGALSEND_H
#define SINGALSEND_H

#include <QtWidgets/QMainWindow>
#include "ui_singalsend.h"

class SingalSend : public QMainWindow
{
	Q_OBJECT

public:
	SingalSend(QWidget *parent = 0);
	~SingalSend();
	void begin();

Q_SIGNALS:
	void teach(int a);

private:
	Ui::SingalSendClass ui;
};

#endif // SINGALSEND_H
