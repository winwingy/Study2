#ifndef CLIPREGION_H
#define CLIPREGION_H

#include <QtWidgets/QMainWindow>
#include "ui_clipregion.h"

class ClipRegion : public QMainWindow
{
	Q_OBJECT

public:
	ClipRegion(QWidget *parent = 0);
	~ClipRegion();

private:
	virtual void paintEvent(QPaintEvent *e) override;
	Ui::ClipRegionClass ui;
};

#endif // CLIPREGION_H
