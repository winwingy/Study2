#ifndef LAYOUTCLASS_H
#define LAYOUTCLASS_H

#include <QWidget>
#include "ui_layoutclass.h"

class LayoutClass : public QWidget
{
	Q_OBJECT

public:
	LayoutClass(QWidget *parent = 0);
	~LayoutClass();

private:
	Ui::LayoutClass ui;
};

#endif // LAYOUTCLASS_H
