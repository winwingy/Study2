#ifndef LAYOUTGRID_H
#define LAYOUTGRID_H

#include <QtWidgets/QMainWindow>
#include "ui_layoutgrid.h"

class LayoutGrid : public QMainWindow
{
	Q_OBJECT

public:
	LayoutGrid(QWidget *parent = 0);
	~LayoutGrid();

private:
	Ui::LayoutGridClass ui;
};

#endif // LAYOUTGRID_H
