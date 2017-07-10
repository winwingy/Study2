#ifndef PARENTBOTTOM_H
#define PARENTBOTTOM_H

#include <QtWidgets/QMainWindow>
#include "ui_parentbottom.h"

class ParentBottom : public QMainWindow
{
	Q_OBJECT

public:
	ParentBottom(QWidget *parent = 0);
	~ParentBottom();

public slots:
	void slot1();
private:
	Ui::ParentBottomClass ui;
};

#endif // PARENTBOTTOM_H
