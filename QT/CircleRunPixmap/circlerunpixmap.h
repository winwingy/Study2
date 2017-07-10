#ifndef CIRCLERUNPIXMAP_H
#define CIRCLERUNPIXMAP_H

#include <QtWidgets/QMainWindow>
#include "ui_circlerunpixmap.h"
#include "circleanimationwidget.h"
#include "qpushbutton.h"
#include "qsignalmapper.h"

class CircleRunPixmap : public QMainWindow
{
	Q_OBJECT

public:
	CircleRunPixmap(QWidget *parent = 0);
	~CircleRunPixmap();

private slots:
	void onMappingBack(int curve);
private:
	virtual void mousePressEvent(QMouseEvent *ev) override;
	
	Ui::CircleRunPixmapClass ui;
	CircleAnimationWidget* m_CircleAnimationWidget;

	QPushButton* m_pBtn1;
	QSignalMapper* m_pSignalMapper;
};

#endif // CIRCLERUNPIXMAP_H
