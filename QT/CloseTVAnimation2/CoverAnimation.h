#pragma once
#include <QPixmap>
#include <QVariantAnimation>
#include <QWidget>
#include <QPaintEvent>
class CoverAnimation : public QWidget
{
public:
	CoverAnimation(QWidget* obj, int intervalMs);
	~CoverAnimation(void);
	void start();

signals:
	void animationEnd();

private:
	virtual void paintEvent(QPaintEvent *ev) override;
	QWidget* m_pObj;
	QPixmap m_pixCp;
	QPixmap m_pixNew;
	int m_aniValue;
	QVariantAnimation* m_ani;

};

