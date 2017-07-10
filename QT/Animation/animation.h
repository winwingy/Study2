#ifndef ANIMATION_H
#define ANIMATION_H

#include <QtWidgets/QMainWindow>
#include "ui_animation.h"

class Animation : public QMainWindow
{
	Q_OBJECT

public:
	Animation(QWidget *parent = 0);
	~Animation();

private:
	virtual void keyPressEvent(QKeyEvent *ev) override;
	void QTimeLineUse();
	void onMyCircleRunAnimation();
	Ui::AnimationClass ui;
};

#endif // ANIMATION_H
